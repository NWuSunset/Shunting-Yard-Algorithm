#include "binary_tree.h"
#include <iostream>
#include <cstring>
#include <limits>

//Constructor creates a binary tree
BinaryTree::BinaryTree(Queue* &queue) {
  //while tokens to be read
  //if is symbol (number)
  //if is operator
  while (!queue->isEmpty()) {
    Node* token = queue->dequeue();
    
    if (isNum(token->data)) {
      //Push to stack
      stack->push(token);
    } else if (isOperator(token->data)) {
      //Set top of stack to right, next in stack to right, push to stack
      token->right = stack->pop();
      token->left = stack->pop();
      stack->push(token);
    }  
  }
  delete queue; //free up memory after taking things from the queue
};

//recursively go through tree
void BinaryTree::printExpression(const Node* pos, int type) {
  if (stack->isEmpty()) {
    std::cout << "Binary tree doesn't exit. Stack is empty" << std::endl;
    return;
  }
  
  if (pos == nullptr) {
    return; //exit when end of tree is hit
  }
  
  if (type == 1) {
    //prefix
    std::cout << pos->data << " ";
    printExpression(pos->left, 1);
    printExpression(pos->right, 1); 
    
  } else if (type == 2) {
    //Postfix:
    printExpression(pos->left, 2);
    printExpression(pos->right, 2);
    std::cout << pos->data << " ";
    
  } else if (type == 3) {
    //Infix:
    
    // If the current node is an operator, print an opening parenthesis
    if (isOperator(pos->data)) {
      std::cout << "( ";
    }
    //go through all the tree paths
    printExpression(pos->left, 3);
    std::cout << pos->data << " ";
    printExpression(pos->right, 3);
    
    
    // End parenthesis
    // If the current node is an operator, print a closing parenthesis
    if (isOperator(pos->data)) {
      std::cout << ") ";
    }   
  }
}

//Prints out the binary tree
void BinaryTree::visualizeTree(const Node* pos, const int depth) const {
  if (pos == nullptr) {
    return;
  }

  visualizeTree(pos->right, depth + 1); //print the right of the tree

  for (int i = 0; i < depth; ++i) {
    std::cout << "    "; //more depth -> more space.
  }
  std::cout << pos->data << std::endl; //print tree data

  visualizeTree(pos->left, depth + 1); //print left of tree
}

// Destructor
BinaryTree::~BinaryTree() {
  delete stack;
}
