#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

static std::string ogname;  //static global variable to hold name of file passed, available across main.cpp and tree.cpp

struct Node{                                                                                      //struct for the nodes
    std::string data;
    struct Node *left;
    struct Node *right;
};


struct Node *createTree(std::string value);
struct Node *insert(struct Node *root, std::string value);
void printInorder(struct Node *root, int depth);
void printPreorder(struct Node *root, int depth);
void printPostorder(struct Node *root, int depth);
void combineValues(std::string individuals);
struct Node *buildTree(std::string filename);

#endif
