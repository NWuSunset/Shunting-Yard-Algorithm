#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "stack_and_queue.h"
using namespace std;

//Takes: Mathamtical expression (in infix notation) that can contain +,-,*,/,^,single digit integers, and parentheses. Each token is separated by a space.
//Changes to postfix notation
//Outputs: infix, prefix, or postfix notation using an expression tree (that was created from the postfix notation)
//Note: Must output expression tree for infix, postfix, and prefix

void shuntingYard(vector<string> tokens, Queue* outQ, Stack* stack);
bool isNum(string token);
bool isOperator(string token);
bool isLeftParen(string token);
bool isRightParen(string token);
opInfo getOpInfo(string op);

enum Associativity {
  LEFT,
  RIGHT
};

//moperator precedence
//^ = 4 RIGHT, * = 3 LEFT, / = 3 LEFt, - = 2 left, + = 2 left. 
struct opInfo {
  int precedence;
  Associativity as;

};

int main() {
  cout << isNum("9232") << endl; //returns true (for testing)
  cout << isOperator("^") << endl; //returns true
  cout << isLeftParen("(") << endl; //true = 1
  cout << isRightParen("(") << endl; //returns false

  //str1.compare(str2) returns 0 if true

  
  Queue* outQ = new Queue(); //output queue for shunting yard
  Stack* stack = new Stack(); // stack for the shunting yard
  
  string input;
  vector<string> tokens;
  string token;
  

  
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
  
  return 0;
}

//Does shunting stuff?
void shuntingYard(vector<string> tokens, Queue* outQ, Stack* stack) {
  //while tokens to be read
  for (auto & token: tokens) {
    //put into output queue
    if (isNum(token)) {
      outQ->enqueue(new Node(token));
    } else if (token.length() > 1) {
      //Anything besides numbers should only be one character long
      cout << "Error: Non number string contains length greater than two.\
               Did you remember to put spaces between everything?" << endl;
      return;
    } else if (isOperator(token)) {
      //Compare to top of stack. If there is an operator will more (or equal)
      //presedence than the one being put in, pop top of stack
      while ((!isLeftParen(token) && getOpInfo(stack->peek()->data).precedence > getOpInfo(token).precedence) || ( getOpInfo(stack->peek()->data).precedence == getOpInfo(token).precedence) && getOpInfo(token).as == Associativity::LEFT) {

      }
      
    } else if (isLeftParen(token)) {
      
    } else if (isRightParen(token)) {
      
    }
  }
}


//Checks if string is a integer
bool isNum(string token) {
  for (char ch : token) {
    int asciiVal = ch; //convert to ascii value
    if (!(ch >= 48 && ch <= 57)) { //check if it's in the range of ascii digits
      return false; //returns false if we find something not in the digit range
    }
  }
  return true;
}

bool isOperator(string token) {
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

bool isLeftParen(string token) {
  for (char ch : token) {
    int asciiVal = ch;
  
  if (asciiVal == 40) { //ascii of ( is 40
    return true; 
  }
  }
  return false;
}

bool isRightParen(string token) {
  for (char ch : token) { 
    int asciiVal = ch;
    
    if (asciiVal == 41) { //ascii val of 41 is )
      return true;
    }
  }
  return false;
}

opInfo getOpInfo(string op) { //returns the precedence of an operator
  const unordered_map<string, opInfo> opMap {
    {"^", {4, Associativity::RIGHT}},
    {"*", {3, Associativity::LEFT}},
    {"/", {3, Associativity::LEFT}},
    {"-", {2, Associativity::LEFT}},
    {"+", {2, Associativity::LEFT}},
  };
  
  //.find() returns end iterator if value not found
  if (opMap.find(op) != opMap.end()) {
    return opMap[op]; //return the operator info struct for the specified operator
  } else {
    return {0, Associativity::LEFT}
  }
}
