#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
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

int main() {
  cout << isNum("9232") << endl; //returns true (for testing)
  cout << isOperator("^") << endl; //returns true
  cout << isLeftParen("(") << endl; //true = 1
  cout << isRightParen("(") << endl; //returns false

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
    //check if num, operator or paren

    //put into output queue
    if (isNum(token)) {
      
    } else if (token.length() > 1) {
      //Anything besides numbers should only be one character long
      cout << "Error: Non number string contains length greater than two. Did you remember to put spaces between everything?" << endl;
      return;
    } else if (isOperator(token)) {
      
      
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
