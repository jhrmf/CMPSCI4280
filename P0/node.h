#include <string>
struct Node{
    std::string data;
    struct Node *left;
    struct Node *right;
    int depth;
};
