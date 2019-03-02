#include "tree.h"

using namespace std;

int main(int argc, char* argv[]) {

    std::string filename, ifnoname;                                                  // string for the name of the file,
                                                        // and a string to store keyboard entry if no string is provided

    if (argc == 2) {                                   //if the user enters a filename, assign it to the string filename
        filename = argv[1];
    }
    if (argc < 2) {                      //if the user doesn't enter a filename, read from keyboard into string ifnoname
        ofstream tempfile;
        getline(cin, ifnoname);                                                     //reads keyboard input into ifnoname
        tempfile.open("temp.sp19");                       //creates a temporary file for keyboard inputs to be stored in
        tempfile << ifnoname;
        tempfile.close();
        filename = "temp";                                                   // sets filename to the temporary file
    }
    if (filename.find(".sp19") != string::npos){               //checks if file someone entered has .sp19 and removes it
        filename.erase(0, filename.find(".sp19"));
    }

    ifstream file((filename + ".sp19").c_str());

    if(!file){                                                                  //if the file does not exit, throw error
		cout << "ERROR: File does not exist." << endl;
		return 0;
	}
	else if(file.peek() == std::ifstream::traits_type::eof()){                            //throw error if file is empty
		cout << "ERROR: File is empty." << endl;
		return 0;
	}
	file.close();

	struct Node *root = buildTree(filename);                    //call buildTree function (in tree.cpp) passing filename

	printPreorder(root, 0);                               //call printPreorder (in tree.cpp) passing root and depth at 0
	printInorder(root, 0);                                 //call printInorder (in tree.cpp) passing root and depth at 0
	printPostorder(root, 0);                          //call printPostorder (in tree.cpp) passing root and depth at 0

}
