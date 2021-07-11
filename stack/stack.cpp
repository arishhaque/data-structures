#include <iostream>
#include "stack.h"

using namespace std;

stack::stack() {top = NULL;}

//destructor
stack::~stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}

void stack::display() {

    Node *p = top;
    while(p != NULL) {

        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int stack::isEmpty() {

    if(top == NULL)
        return 1;

    return 0;
}

char stack::stackTop() {

    if(top != NULL)
        return top->data;
    
    return -1;
}

void stack::push(char x) {

    Node *t = new Node(x);
    t->data = x;
    if(t == NULL) {
        cout << "stack Overflow" << endl;
        return;
    }

    t->next = top;
    top = t;

    size++;
}

char stack::pop() {

    int x = -1;
    if(isEmpty()) {
        cout << "stack Underflow" << endl;
        return x;
    }

    Node *p = top;
    top = top->next;

    x = p->data;
    free(p);

    size--;
    return x;
}

char stack::peek(int index) {

    if(isEmpty())
        return -1;

    Node* p = top; 
    for (int i=0; p != nullptr && i < index-1; i++)
        p = p->next;
 
    if (p != nullptr){
        return p->data;
    } else {
        return -1;
    }  
}

/*
int main() {

    stack st;

    cout << st.isEmpty() << endl;

    st.push('4');
    st.push('6');
    st.push('2');
    st.pop();
    st.push('7');
    st.push('5');
    st.display();

    cout << "Top Element: " << st.stackTop() << endl;
    cout << "Element at pos 3: " << st.peek(3) << endl;
    
    return 0;
}
*/
