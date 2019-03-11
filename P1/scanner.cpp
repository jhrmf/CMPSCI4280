#include "scanner.h"
#include "token.h"

void scanner(std::string filename){
    std::string word;
    char character;
    int count = 0, lineCount = 1;
    ifstream read;

    read.open((filename).c_str());

    while(!read.eof()){

        count++;
        read.get(character);
        if(character == '&'){
            while(character != '\n'){
                read.get(character);
            }
        }
        if(!isspace(character) && !read.eof()) {
            word += character;
        }
        if(isspace(character) && !read.eof()){

            if(word.length() < 9){
                struct Token newToken = getToken(word, lineCount);
                printToken(newToken);
            }
            word = "";
        }
        if(character == '\n'){
            lineCount++;
        }

    }

    read.close();
}
