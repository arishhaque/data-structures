//#ifndef STACK_H
//#define STACK_H
//#pragma once
#include "node.h"


class stack {

        private:
            int size;
            Node *top;

       public:

            stack();
            ~stack();

            void display();
            int isEmpty();

            void push(char x);
            char pop();

            char stackTop();
            char peek(int index);

};

//#endif



