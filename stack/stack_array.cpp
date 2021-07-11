#include <iostream>
using namespace std;

// array implementation of stack
class Stack {

    public:
        int size;
        int top;
        int *arr;

        Stack(int n) {

            size = n;
            top = -1;
            arr = new int[size];
        }

        void display();

        bool isEmpty();
        bool isFull();

        void push(int x);
        int pop();

        int peek(int pos);
};

void Stack::display() {

    for(int i = top; i >= 0; i--) {

        cout << arr[i] << " ";
    }
}

bool Stack::isEmpty() {

    if(top == -1)
        return true;

    return false;
}

bool Stack::isFull() {

    if(top == size - 1)
        return true;

    return false;
}

void Stack::push(int x) {

    if(isFull()) {
        
        cout << "Stack Overflow" << endl;
        return;
    }

    top++;
    arr[top] = x;
}

int Stack::pop() {

    int x = -1;
    if(!isEmpty())
        x = arr[top--];
    else
        cout << "Stack Underflow" << endl;
    return x;    
}

int Stack::peek(int pos) {

    int x = -1;
    if(top - pos + 1 < 0)
        cout << "Invalid index" << endl;
    
    x = arr[top - pos +1];
    return x;

}

int main() {

    Stack *st = new Stack(5);

    cout << ((st->isEmpty() > 0) ? "True" : "False") << endl;
    cout << ((st->isFull() > 0) ? "True" : "False") << endl;

    st->push(7);
    st->push(11);
    st->push(5);
    st->pop();
    st->push(4);
    st->push(16);
    st->push(8);
    
    cout << "Element at pos 3: " << st->peek(3) << endl;
    st->display();

    return 0;
}

