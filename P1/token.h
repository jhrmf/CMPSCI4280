#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <ctype.h>

using namespace std;


/*enum idToken{
    idToken = 1000,
    intToken = 1001,
    opDelToken = 1002,
    eofToken = 1003,
    keywordToken = 1004
}; */

struct Token{
    std::string tokenID;
    std::string tokenInstance;
    int lineCount;
};

bool hasWhiteSpace(std::string);
void printToken(struct Token);
int isIdentifier(std::string);
int isKeyword(std::string);
int isNumber(std::string);
int isOperator(std::string);
struct Token getToken(std::string, int);

#endif
