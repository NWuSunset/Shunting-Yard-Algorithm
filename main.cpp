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

void shuntingYard(vector<string> tokens);
bool isNum(string token);
bool isOperator(string token);

int main() {
  cout << isNum("9232"); //returns true (for testing)
  cout << isOperator("^"); //returns true

  
  string input;
  vector<string> tokens;
  string token;
  
  cout << "Enter a math expression (in infix notation)" << endl;
  getline(cin, input);

  istringstream iss(input);
  while (getline(iss, token, ' ')) {
    tokens.push_back(token);
  }

  //test print
  for (auto & elem: tokens) {
    cout << elem << endl;
  }

  shuntingYard(tokens);
  
  return 0;
}

//Does shunting stuff?
void shuntingYard(vector<string> tokens) {
  for (auto & token: tokens) { //reading the tokens
    //check if num, operator or parenthhese
    if (isNum(token)) {

    } else if (isOperator(token)) {


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
  if (token.length() > 1) { //operators should only be one character long
    cout << "Error: Non number string contains length greater than two. Did you remember to put spaces between everything?" << endl;
    return false;
  }
  
  string operators("+-*/^");

  for (char ch : operators) {
    if (token[0] == ch) { //since it should be a single char string only compare the 0 slot
      return true;
    }
  }
  return false;
}
