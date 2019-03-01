#include <iostream>
#include <stdio.h>
#include <string>
#include "tree.h"
using namespace std;
int main(int argc, char* argv[]) {

    std::string filename, ifnoname;

    if(argc > 2){
    	cout << "ERROR";
    	return 0;
    }
    if(argc == 2){
		filename = argv[1];
    }
    if(argc < 2){
	ofstream tempfile;
	getline(cin, ifnoname);
	tempfile.open("temp.sp19");
	tempfile << ifnoname;
	tempfile.close();
	filename = "temp.sp19";
    }

	ifstream file((filename + ".sp19").c_str());
	if(!file){
		cout << "ERROR: File does not exist." << endl;
		return 0;
	}
	else if(file.peek() == std::ifstream::traits_type::eof()){
		cout << "ERROR: File is empty." << endl;
		return 0;
	}
	struct Node *root = buildTree(filename);

	printPreorder(root, 0, 0);
	printInorder(root, 0, 0);
	printPostorder(root, 0, 0);



}
