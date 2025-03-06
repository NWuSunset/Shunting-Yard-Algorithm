#include "binary_tree.h"

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
void BinaryTree::printExpression(const Node* pos) {
  if (stack->isEmpty()) {
    std::cout << "Binary tree doesn't exit. Stack is empty" << std::endl;
    return;
  }

  if (pos == nullptr) {
    return; //exit when end of tree is hit
  }

  //wow, printing out from an expression tree is so easy!
  /*Prefix
  std::cout << pos->data << " ";
  printExpression(pos->left);
  printExpression(pos->right); */

  //Postfix:
  printExpression(pos->left);
  printExpression(pos->right);
  std::cout << pos->data << " ";

  /*Infix:

  // If the current node is an operator, print an opening parenthesis
  if (isOperator(pos->data)) {
    std::cout << "( ";
  }
    //go through all the tree paths
    printTree(pos->left);
    std::cout << pos->data << " ";
    printTree(pos->right);


   * End parenthesis
  // If the current node is an operator, print a closing parenthesis
  if (isOperator(pos->data)) {
    std::cout << ") ";
  } */

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
