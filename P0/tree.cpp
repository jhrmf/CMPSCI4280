#include "tree.h"

std::string printInorder(struct Node *root, int depth);
std::string printPreorder(struct Node *root, int depth);
std::string printPostorder(struct Node *root, int depth);

using namespace std;
std::string inOrder, preOrder, postOrder;


struct Node *createTree(std::string data){
    struct Node *temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

struct Node *insert(struct Node *root, std::string value){

	std::string strsize = value.substr(0, value.find(" "));

	    if(root == NULL){
            return createTree(value);
        }
        if(root->data.substr(0, root->data.find(" ")).size() > strsize.size()){
            root->left = insert(root->left,  value);
        }
        else{
            root->right = insert(root->right,  value);
        }
        return root;



}

void printInorder(struct Node *root, int depth, int check) {

    ofstream userfile((ogname + ".inorder").c_str());

    if(root != NULL){
        printInorder(root->left, depth+1, 1);
        inOrder += string(2*(depth), '-') + root->data + "\n";
        printInorder(root->right, depth+1, 1);
    }
    userfile << inOrder;
    userfile.close();
}

void printPreorder(struct Node *root, int depth, int check){

    ofstream userfile((ogname + ".preorder").c_str());

    if(root != NULL){
        preOrder += string(2*(depth), '-') + root->data + "\n";
        printPreorder(root->left, depth+1, 1);
        printPreorder(root->right, depth+1, 1);
    }
    userfile << preOrder;
    userfile.close();
}

void printPostorder(struct Node *root, int depth, int check){

        ofstream userfile((ogname + ".postorder").c_str());

    if(root != NULL){
        printPostorder(root->left, depth+1, 1);
        printPostorder(root->right, depth+1, 1);
        postOrder += string(2*(depth), '-') + root->data + "\n";
    }
    userfile << postOrder;
    userfile.close();
}

void combineValues(vector<string> &individuals){
    std::string tempstr1, tempstr2;

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

}

struct Node *buildTree(std::string filename){

    std::string values;
    ogname = filename;
    vector<string> individuals;
    struct Node *ogroot = NULL;
    filename += ".sp19";
    ifstream file(filename.c_str());

    while (file >> values) {
        if(values != " " && values!= "" && values != "\n"){
            individuals.push_back(values);
        }
    }
    file.close();

    if(filename == "temp.sp19"){
        remove("temp.sp19");
    }

    combineValues(individuals);

    while (individuals.size() != 0){
        if(individuals.at(0) != " "){
            ogroot = insert(ogroot, individuals.at(0));
            individuals.erase(individuals.begin());
        }
    }



    return ogroot;
/*
    std::ofstream infile((ogname + ".inorder").c_str());
    infile << printInorder(ogroot, 0);
    infile << endl;
    infile.close();
    std::ofstream prefile((ogname + ".preorder").c_str());
    prefile << printPreorder(ogroot, 0);
    prefile << endl;
    prefile.close();
    std::ofstream postfile((ogname + ".postorder").c_str());
    postfile << printPostorder(ogroot, 0);
    postfile << endl;
    postfile.close();
*/

}