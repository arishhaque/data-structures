#include <iostream>
#include "node.h"

using namespace std;


class Queue {

    private:

        Node *front;
        Node *rear;

    public:
        Queue() {

            front = rear = NULL;
        }


        void enqueue(int x);
        int dequeue();

        int isEmpty();

        void display();

};

int Queue::isEmpty() {

    if(front == NULL)
        return 1;
    
    return 0;
}

void Queue::enqueue(int x) {

    Node *t = new Node(x);
    if(t == NULL)
        cout << "Queue is Full" << endl;
    
    else {

        if(front == NULL) 
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue() {

    int x = -1;
    if(isEmpty())
        cout << "Queue is Empty" << endl;
    
    else {

        x = front->data;
        Node *t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void Queue::display() {

    Node *p = front;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    
    cout << endl;
}


int main() {

    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}