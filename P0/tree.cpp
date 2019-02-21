#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
using namespace std;
std::string inOrder, preOrder, postOrder;

Node* createTree(string data){
    Node* temp = new Node();
    temp->data = data;
    temp->right=temp->left = NULL;
    return temp;
}

Node* buildTree(Node* root, string value){

	std::string strsize = value.substr(0, value.find(" "));
	

	if(value != " " && value != "\n"){	
	if(root == NULL){
            root = createTree(value);
        }
        else if(root->data.substr(0, value.find(" ")).size() > strsize.size()){
            root->left = buildTree(root->left, "--" + value);
        }
        else{
            root->right = buildTree(root->right, "--" + value);
        }
	}
    return root;
}

std::string printInorder(Node* root){
    if(root != NULL){
        printInorder(root->left);
        inOrder += root->data + "\n";
        printInorder(root->right);
    }
    return inOrder;
}

std::string printPreorder(Node* root){
    if(root != NULL){
        preOrder += root->data + "\n";
        printPreorder(root->left);
        printPreorder(root->right);
    }
    return preOrder;
}

std::string printPostorder(Node* root){
    if(root != NULL){
        printPostorder(root->left);
        printPostorder(root->right);
        postOrder += root->data + "\n";
    }
    return postOrder;
}
