#include <iostream>
using namespace std;


class Node {

    public:
        int data;
        Node *next;

        Node(int val) {

            data = val;
            next = NULL;
        }
};

class Stack {

    private:
        int size;
        Node *top;

    public:

        Stack() {top = NULL;}
        ~Stack();

        void display();
        int isEmpty();

        void push(int x);
        int pop();

        int stackTop();
        int peek(int index);

};


//destructor
Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::display() {

    Node *p = top;
    while(p != NULL) {

        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::isEmpty() {

    if(top == NULL)
        return 1;

    return 0;
}

int Stack::stackTop() {

    if(top != NULL)
        return top->data;
    
    return -1;
}

void Stack::push(int x) {

    Node *t = new Node(x);
    if(t == NULL) {
        cout << "Stack Overflow" << endl;
        return;
    }

    t->next = top;
    top = t;
}

int Stack::pop() {

    int x = -1;
    if(isEmpty()) {
        cout << "Stack Underflow" << endl;
        return x;
    }

    Node *p = top;
    top = top->next;

    x = p->data;
    free(p);
    return x;
}

int Stack::peek(int index) {

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

int main() {

    Stack st;

    cout << st.isEmpty() << endl;

    st.push(4);
    st.push(6);
    st.push(12);
    st.pop();
    st.push(7);
    st.push(5);
    st.display();

    cout << "Top Element: " << st.stackTop() << endl;
    cout << "Element at pos 3: " << st.peek(3) << endl;
    
    return 0;
}