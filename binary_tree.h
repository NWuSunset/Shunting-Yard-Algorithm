#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "stack_and_queue.h"
#include "helper_functions.h"
#include <string>

//Taking an input from postfix notation, push symbols (numbers) to the stack. Once a operator is found, make the top of the stack the right and the next item in the stack the left, and push the math operator to the stack

class BinaryTree {
public:
  BinaryTree(Queue* queue); //takes in the postfix queue
  void printTree(Node* pos);

  Stack* stack = new Stack(); //stack for the binary treew
};

#endif
