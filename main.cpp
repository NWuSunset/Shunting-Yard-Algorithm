#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "stack_and_queue.h"
using namespace std;

//Takes: Mathematical expression (in infix notation) that can contain +,-,*,/,^,single digit integers, and parentheses. Each token is separated by a space.
//Changes to postfix notation
//Outputs: infix, prefix, or postfix notation using an expression tree (that was created from the postfix notation)
//Note: Must output expression tree for infix, postfix, and prefix

enum Associativity {
  LEFT,
  RIGHT
};

//operator precedence
//^ = 4 RIGHT, * = 3 LEFT, / = 3 LEFt, - = 2 left, + = 2 left.
struct opInfo {
  int precedence;
  Associativity as;
};


void shuntingYard(vector<string> tokens, Queue* outQ, Stack* stack);
bool isNum(const string& token);
bool isOperator(const string& token);
bool isLeftParen(const string& token);
bool isRightParen(const string& token);
opInfo getOpInfo(const string& op);


int main() {
  cout << isNum("9232") << endl; //returns true (for testing)
  cout << isOperator("^") << endl; //returns true
  cout << isLeftParen("(") << endl; //true = 1
  cout << isRightParen("(") << endl; //returns false

  //str1.compare(str2) returns 0 if true
  cout << getOpInfo("*").precedence << endl;
  

  
  Queue* outQ = new Queue(); //output queue for shunting yard
  Stack* stack = new Stack(); // stack for the shunting yard
  
  string input;
  vector<string> tokens;
  string token;
  
  stack->push(new Node("test"));
  cout << stack->peek()->data << endl;
  stack->pop();
  cout << "Empty or no?: " << stack->isEmpty() << endl; //returns 1 if true


    
  cout << "Enter a math expression (in infix notation). Separate all characters using a space. EX: ( 3 + 2 ) * 2" << endl;
  getline(cin, input);

  istringstream iss(input);
  while (getline(iss, token, ' ')) {
    tokens.push_back(token);
  }

  //test print
  for (auto & elem: tokens) {
    cout << elem << endl;
  }

   
  shuntingYard(tokens, outQ, stack);

  //Print out the output queue
  outQ->printQueue();
  
  return 0;
}

//Does shunting stuff. Supports *,/,+,-,()
void shuntingYard(vector<string> tokens, Queue* outQ, Stack* stack) {
  //while tokens to be read
  for (auto & token: tokens) {
    //put into output queue
    if (isNum(token)) {
      //cout << "is number" << endl;
      outQ->enqueue(new Node(token));
    } else if (token.length() > 1) {
      //Anything besides numbers should only be one character long
      cout << "Error: Non number string contains length greater than two. Did you remember to put spaces between everything?" << endl;
      return;
    } else if (isOperator(token)) {
      
      if (!stack->isEmpty()) {
	//bools for readability.
	//cout << "is Operator" << endl;
	bool isNotLeftParen = !isLeftParen(stack->peek()->data);
	bool hasHigherPrecedence = getOpInfo(stack->peek()->data).precedence > getOpInfo(token).precedence;
	bool hasEqualPrecedence = getOpInfo(stack->peek()->data).precedence == getOpInfo(token).precedence;
	bool isLeftAssociative = getOpInfo(token).as == Associativity::LEFT;
	
	//Compare to top of stack (operator 2, o2). If it's not a left parenthesis and if o2 is more than or equal
	//precedence than the one being put in (operator 1, o1), pop o2.
	while (!stack->isEmpty() && (isNotLeftParen && (hasHigherPrecedence || (hasEqualPrecedence && isLeftAssociative)))) {
	  outQ->enqueue(stack->pop()); //pop operator 2 from stack into output queue
	  if (!stack->isEmpty()) { //once stack is empty, update the while loop conditions
	    isNotLeftParen = !isLeftParen(stack->peek()->data);
	    hasHigherPrecedence = getOpInfo(stack->peek()->data).precedence > getOpInfo(token).precedence;
	    hasEqualPrecedence = getOpInfo(stack->peek()->data).precedence == getOpInfo(token).precedence;
	    isLeftAssociative = getOpInfo(token).as == Associativity::LEFT;
	  }
	}
      }
      //Push operator into stack
      stack->push(new Node(token));
    } else if (isLeftParen(token)) { //push it into the operator stack (as it has the highest prescedence)
      stack->push(new Node(token));
    } else if (isRightParen(token)) {
      bool isNotLeftParen = !isLeftParen(stack->peek()->data);
      while (!stack->isEmpty() && isNotLeftParen) { //pop stack until we find a left paren.
	//cout << "Operator stack is not empty" << endl;
	//If the stack runs out without finding a left paren then there are mismatched parenthesis.
	outQ->enqueue(stack->pop());

	if (!stack->isEmpty()) {
	  isNotLeftParen = !isLeftParen(stack->peek()->data);
	}
      }
      //cout << "There is a left parenthesis at the top of the stack" << endl; //debug

      stack->pop(); //left parenthesis gets discarded once found
    }
  } //end of tokens to be read

  //While there are tokens on the operator stack. (if the top is a parenthesis, then there are mismatched parenthesis)
  while (!stack->isEmpty()) {
    if (!isLeftParen(stack->peek()->data)) {
      //cout << "Operator on topp isn't a left parenthesis" << endl;
    }
    outQ->enqueue(stack->pop());
  }
}


//Checks if string is a integer
bool isNum(const string& token) {
  for (const char ch : token) {
    int asciiVal = ch; //convert to ascii value
    if (!(asciiVal >= 48 && asciiVal <= 57)) { //check if it's in the range of ascii digits
      return false; //returns false if we find something not in the digit range
    }
  }
  return true;
}

bool isOperator(const string& token) {
  /* if (token.length() > 1) { //operators should only be one character long
    cout << "Error: Non number string contains length greater than two. Did you remember to put spaces between everything?" << endl;
    return false;
    } */
  
  string operators("+-*/^");

  for (char ch : operators) {
    if (token[0] == ch) { //since it should be a single char string only compare the 0 slot
      return true;
    }
  }
  return false;
}

bool isLeftParen(const string& token) {
  for (char ch : token) {
    int asciiVal = ch;
    
    if (asciiVal == 40) { //ascii of ( is 40
      return true; 
    }
  }
  return false;
}

bool isRightParen(const string& token) {
  for (char ch : token) { 
    int asciiVal = ch;
    
    if (asciiVal == 41) { //ascii val of 41 is )
      return true;
    }
  }
  return false;
}

opInfo getOpInfo(const string& op) { //returns the precedence of an operator
  const unordered_map<string, opInfo> opMap {
    {"^", {4, Associativity::RIGHT}},
    {"*", {3, Associativity::LEFT}},
    {"/", {3, Associativity::LEFT}},
    {"-", {2, Associativity::LEFT}},
    {"+", {2, Associativity::LEFT}},
  };
  
  //.find() returns end iterator if value not found
  const auto it = opMap.find(op);
  if (it != opMap.end()) {
    //return the operator info struct for the specified operator
    return it->second;
  } else {
    return {0, Associativity::LEFT}; //if isn't found
  }
}
