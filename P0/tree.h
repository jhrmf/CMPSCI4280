#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
static std::string ogname;

struct Node{
    std::string data;
    struct Node *left;
    struct Node *right;
    int depth;
};


struct Node *createTree(std::string value);
struct Node *insert(struct Node *root, std::string value);
void printInorder(struct Node *root, int depth, int check);
void printPreorder(struct Node *root, int depth, int check);
void printPostorder(struct Node *root, int depth, int check);
void combineValues(std::string individuals);
struct Node *buildTree(std::string filename);
#endif
