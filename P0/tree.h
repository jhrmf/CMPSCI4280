#ifndef TREE_H
#define TREE_H

#include <string>

Node* createTree(std::string);
Node* buildTree(Node*, std::string);
std::string printInorder(Node*);
std::string printPreorder(Node*);
std::string printPostorder(Node*);
#endif
