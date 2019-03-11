#include "token.h"

bool hasWhiteSpace(std::string line){
    bool result = false;
    for (int i = 0; i < strlen(line.c_str()); i++) {
        if (isspace(line.c_str()[i]))
            result = true;
    }
    return result;
}

void printToken(struct Token newToken){
    cout << "Token ID: " << newToken.tokenID << endl;
    cout << "Token Instance: " << newToken.tokenInstance << endl;
    cout << "Line Number: " << newToken.lineCount << endl;
    cout << endl;
}

int isIdentifier(std::string word){
    int result = 0;
    char firstLetter = word.c_str()[0];
    if(islower(firstLetter)){
        result = 1000;
    }
    return result;
}

int isKeyword(std::string word){
    int result = 0;

    string keyword[11] = {"iter", "void", "var", "return", "scan", "print", "program", "cond", "then", "let", "int"};

    for(int i = 0; i <= 10; i++){
        if(word.compare(keyword[i]) == 0){
            result = 1004;
        }
    }

    return result;
}

int isOperator(std::string word){
    int result = 0;

    string opDelim[18] = {"=", "<", ">", ":", "+", "-", "*", "/", "%", ".", "(", ")", ",", "{", "}", "[", "]", ";"};

    for(int i = 0; i <= 17; i++){
        if(word.compare(opDelim[i]) == 0){
            result = 1002;
        }
    }

    return result;
}


int isNumber(std::string word) {

    int result;
    int hasLetter = 0, hasNumber = 0;
    std::string period = ".";

    for (int i = 0; i < strlen(word.c_str()); i++) {
        if (isdigit(word.c_str()[i]))
            hasNumber++;
    }
    if(strstr(word.c_str(), period.c_str())){
        hasNumber++;
    }
    if(hasNumber == strlen(word.c_str()))
        result = 1001;
    else
        result = 0;

    return result;
}

struct Token getToken(std::string word, int lineCount){
    struct Token newTk= Token();

    newTk.tokenInstance = word;
    newTk.lineCount = lineCount;

    if(isIdentifier(word) == 1000){
        newTk.tokenID = "idToken";
    }
    if(isNumber(word) == 1001){
        newTk.tokenID = "intToken";
    }
    if(isOperator(word) == 1002){
        newTk.tokenID = "opDelToken";
    }
    if(isKeyword(word) == 1004){
        newTk.tokenID = "keywordToken";
    }

    return newTk;

}