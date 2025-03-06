#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "stack_and_queue.h"
#include "helper_functions.h"

//Taking an input from postfix notation, push symbols (numbers) to the stack. Once an operator is found, make the top of the stack the right and the next item in the stack the left, and push the math operator to the stack

class BinaryTree {
public:
  explicit BinaryTree(Queue* &queue); //takes in the postfix queue
  void printExpression(const Node* pos);
  void visualizeTree(const Node* pos, int depth = 0) const;
  // Destructor implementation
  ~BinaryTree();


  Stack* stack = new Stack(); //stack for the binary tree
};

#endif
