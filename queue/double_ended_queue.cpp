#include <iostream>

using namespace std;


class DEQueue {

     private:
        int size;
        int front;  
        int rear;
        int *arr;

    public:

        DEQueue(int size);
        ~DEQueue();

        bool isFull();
        bool isEmpty();

        void enqueueFront(int x);
        void enqueueRear(int x);

        int dequeueRear();
        int dequeueFront();

        void display();

};

DEQueue::DEQueue(int size) {

    this->size = size;
    front = rear = -1;
    arr = new int[size];
}

DEQueue::~DEQueue() {

    delete []arr;
}

bool DEQueue::isEmpty() {

    if(front > rear || rear == -1)
        return true;
    
    return false;
}

bool DEQueue::isFull() {

    if (front == 0 && rear == size - 1)
        return true;
    
    return false;
    
}

void DEQueue::enqueueRear(int x) {

    if(isFull()) {

        cout << "EnQueue Rear: Overflow" << endl;
        return;
    
    } else {

        arr[++rear] = x;
        if(front == -1)
            front++;
    }
}

int DEQueue::dequeueFront() {

    int x = -1;
    if(isEmpty()) {
        cout << "DeQueue Front: Underflow" << endl;
    }else {
        
        x = arr[front];
        front++;
    }
    return x;
}

void DEQueue::enqueueFront(int x) {

    if(isFull()) {

        cout << "EnQueue Front: Overflow" << endl;
        return;
    
    } else {

        if(front == -1) {

            arr[++front] = x;
            rear++;
        } else {
            arr[--front] = x;
        }
    }
}

int DEQueue::dequeueRear() {

    int x = -1;
    if(isEmpty()) {
        cout << "DeQueue Rear: Underflow" << endl;
    }else {

        x = arr[rear];
        rear--;
    }
    return x;
}

void DEQueue::display() {

    
    for (int i=front; i<=rear; i++) {
        cout << arr[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main() {

    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
 
    DEQueue deq(sizeof(A)/sizeof(A[0]));
    
    cout << "Enqueue Rear and Dequeue Front:" << endl;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }

    deq.dequeueFront();
    cout << endl;

    cout << "Enqueue Front and Dequeue Rear:" << endl;
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.dequeueRear();

}