#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include "node.h"
#include "tree.h"
using namespace std;
int main(int argc, char* argv[]) {

    std::string filename, ifnoname, values, tempstr1, tempstr2;
    char ch;
    vector<string> individuals;
    Node* ogroot = new Node();

    if(argc > 2){
	cout << "ERROR";
	return 0;
    }
    if(argc == 2){
	filename = argv[1];
	filename += ".sp19";
    }
    if(argc < 2){
	ofstream tempfile;
	getline(cin, ifnoname);
	tempfile.open("temp.sp19");
	tempfile << ifnoname;
	tempfile.close();
	filename = "temp.sp19";
    }

    ifstream file(filename.c_str());
    if(file.peek() == std::ifstream::traits_type::eof()){
	cout << "ERROR: File is empty." << endl;
	return 0;
    }

    while (file >> values) {
	if(values != " " && values!= "" && values != "\n"){
	   individuals.push_back(values);
    	}
    }
    file.close();

    for(int i = 0; i< individuals.size(); i++){
	int n = i+1;
	while(n!=individuals.size()){
		if(individuals.at(i) == individuals.at(n)){
			individuals.erase(individuals.begin() + n);
			n--;
		}	
		n++;
	}
    }

    for(int i = 0; i < individuals.size(); i++){
	tempstr1 = individuals.at(i);
	int valueSize = tempstr1.size();
	int j = i+1;
	    while(j < individuals.size()){
	       tempstr2 = individuals.at(j);
	       if(valueSize == individuals.at(j).size()){
		   tempstr1 = tempstr1 + " " + tempstr2;
	   	   individuals.erase(individuals.begin()+ j);
		   j--;
	       }
	       
	       j++;
	    }
    	individuals.at(i) = tempstr1;
	
    }
    
    while (individuals.size() != 0){
	if(individuals.at(0) != " "){
        buildTree(ogroot, individuals.at(0));
        individuals.erase(individuals.begin());
	}
    }
    std::ofstream infile("out.inorder");
    infile << printInorder(ogroot);
    infile << endl;
    infile.close();
    std::ofstream prefile("out.preorder");
    prefile << printPreorder(ogroot);
    prefile << endl;
    prefile.close();
    std::ofstream postfile("out.postorder");
    postfile << printPostorder(ogroot);
    postfile << endl;
    postfile.close();
    
    if(argc < 2){
	remove("temp.sp19");
    }
    return 0;

}
