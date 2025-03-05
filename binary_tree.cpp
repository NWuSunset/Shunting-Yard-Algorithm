#include "binary_tree.h"

//Constructor creates a binary tree
BinaryTree::BinaryTree(Queue* queue) {
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
};

//recursivley go through tree
void BinaryTree::printTree(Node* pos) {
  if (stack->isEmpty()) {
    std::cout << "Binary tree doesn't exit. Stack is empty" << std::endl;
    return;
  } else {
    //go through all the tree paths
    printTree(pos->left);
    std::cout << pos->data << " ";
    printTree(pos->right);
  }
}
