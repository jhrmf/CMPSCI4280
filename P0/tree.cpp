#include "tree.h"

std::string inOrder, preOrder, postOrder;     //strings for storing the values to be entered into their designated files

using namespace std;

struct Node *createTree(std::string data){                             //function for creating the tree and nodes within
    struct Node *temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;                                                                           //return the new node created
}

struct Node *insert(struct Node *root, std::string value){                       //function for inserting nodes into bst

	std::string strsize = value.substr(0, value.find(" "));                  //gets substring of string up until a space

	    if(root == NULL){                                                               //if node is null, add it to bst
            return createTree(value);
        }
        if(root->data.substr(0, root->data.find(" ")).size() > strsize.size()){            //if length of data in bst is
            root->left = insert(root->left,  value);                   // greater than length of the new string, go left
        }
        else{
            root->right = insert(root->right,  value);                        //if other conditions aren't met, go right
        }
        return root;                                                                                       //return node

}

void printInorder(struct Node *root, int depth) {                //function for printing the tree in inOrder to new file

    ofstream userfile((ogname + ".inorder").c_str());                            //open file with the extension .inorder

    if(root != NULL){           //traverse tree in inOrder
        printInorder(root->left, depth+1);
        inOrder += string(2*(depth), '-') + root->data + "\n";      //store value with depth and new line for next value
        printInorder(root->right, depth+1);
    }
    userfile << inOrder;                                                 //store string value into the file that is open
    userfile.close();                                                                                       //close file
}

void printPreorder(struct Node *root, int depth){               //function for printing the tree in preOrder to new file

    ofstream userfile((ogname + ".preorder").c_str());                              //open file with extension .preorder

    if(root != NULL){                                                                       //traverse tree in postOrder
        preOrder += string(2*(depth), '-') + root->data + "\n";     //store value with depth and new line for next value
        printPreorder(root->left, depth+1);
        printPreorder(root->right, depth+1);
    }
    userfile << preOrder;                                                //store string value into the file that is open
    userfile.close();                                                                                       //close file
}

void printPostorder(struct Node *root, int depth){             //function for printing the tree in postOrder to new file

    ofstream userfile((ogname + ".postorder").c_str());                            //open file with extension .postorder

    if(root != NULL){       //traverse tree in postOrder
        printPostorder(root->left, depth+1);
        printPostorder(root->right, depth+1);
        postOrder += string(2*(depth), '-') + root->data + "\n";    //store value with depth and new line for next value
    }

    userfile << postOrder;                                              //store string value into the file that was open
    userfile.close();                                                                                       //close file
}

void combineValues(vector<string> &individuals){  //function for removing duplicates and appending values of same length
    std::string tempstr1, tempstr2;                                //temporary strings for manipulation fo vector passed

    for(int i = 0; i< individuals.size(); i++){                                     //loop that removes duplicate values
        int n = i+1;
        while(n!=individuals.size()){
            if(individuals.at(i) == individuals.at(n)){          //if one value has a duplicate amongst the other values
                individuals.erase(individuals.begin() + n);                                 //remove the duplicate value
                n--;
            }
            n++;
        }
    }

    for(int i = 0; i < individuals.size(); i++){                              //loop that appends strings of same length
        tempstr1 = individuals.at(i);
        int valueSize = tempstr1.size();
        int j = i+1;
        while(j < individuals.size()){
            tempstr2 = individuals.at(j);
            if(valueSize == individuals.at(j).size()){                   //if the two values compared have the same size
                tempstr1 = tempstr1 + " " + tempstr2;                                           //ready them as appended
                individuals.erase(individuals.begin()+ j);                          //remove the value that was appended
                j--;
            }

            j++;
        }
        individuals.at(i) = tempstr1;              //set the original value that was compared as the new appended string
    }

}

struct Node *buildTree(std::string filename){  //function for reading the values from file and passing for tree building

    std::string values;         //string to hold values rea
    ogname = filename;          //set the global static std::string ogname to the name of the file (in tree.h)
    vector<string> individuals;         //vector to hold the individual values read from the file
    struct Node *ogroot = NULL;         //node to create the tree
    filename += ".sp19";            //append the file extension to the filename
    ifstream file(filename.c_str());    //open the file provided for reading

    while (file >> values) {            //loop to read all values in the file into vector, until EOF
        if(values != " " && values!= "" && values != "\n"){         //verifies that values are not spaces or new lines
            individuals.push_back(values);          //pushes each value from file into the vector
        }
    }
    file.close();           //close the file after reading

    if(filename == "temp.sp19"){            //removes the temp file that was created if no file name was provided
        remove("temp.sp19");
    }

    combineValues(individuals);             //calls function combineValues (above) passing the vector

    while (individuals.size() != 0){        //loop to traverse values inside the vector, calling function to insert
        if(individuals.at(0) != " "){           //verifies that no values are spaces
            ogroot = insert(ogroot, individuals.at(0));       //calls function insert (above) passing the node and value
            individuals.erase(individuals.begin());         //removes the value from vector after it is passed
        }
    }



    return ogroot;          //returns the node to main

}
