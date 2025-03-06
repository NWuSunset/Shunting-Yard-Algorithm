#include <string>

using namespace std;

//Checks if string is an integer
bool isNum(const string& token) {
  for (const char ch : token) {
    const int asciiVal = ch; //convert to ascii value
    if (!(asciiVal >= 48 && asciiVal <= 57)) { //check if it's in the range of ascii digits
      return false; //returns false if we find something not in the digit range
    }
  }
  return true;
}

bool isOperator(const string& token) {
  string operators("+-*/^");

  for (const char ch : operators) {
    if (token[0] == ch) { //since it should be a single char string only compare the 0 slot
      return true;
    }
  }
  return false;
}

bool isLeftParen(const string& token) {
  for (const char ch : token) {
    const int asciiVal = ch;

    if (asciiVal == 40) { //ascii of ( is 40
      return true;
    }
  }
  return false;
}

bool isRightParen(const string& token) {
  for (const char ch : token) {
    const int asciiVal = ch;

    if (asciiVal == 41) { //ascii val of 41 is )
      return true;
    }
  }
  return false;
}