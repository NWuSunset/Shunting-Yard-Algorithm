#include <iostream>
#include <sstream>
#include <vector> 
#include "stack_and_queue.h"
using namespace std;

//Takes: Mathamtical expression (in infix notation) that can contain +,-,*,/,^,single digit integers, and parentheses. Each token is separated by a space.
//Changes to postfix notation
//Outputs: infix, prefix, or postfix notation using an expression tree (that was created from the postfix notation)
//Note: Must output expression tree for infix, postfix, and prefix

void shuntingYard(vector<string> tokens);

int main() {

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
  }
}
