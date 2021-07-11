//#ifndef NODE_H
//#define NODE_H

#include <iostream>
using namespace std;

class Node {

    public:
        char data;
        Node *next;

        Node(char val) {

            data = val;
            next = NULL;
        }
};
//#endif
