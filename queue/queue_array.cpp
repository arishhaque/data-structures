#include <iostream>

using namespace std;


class Queue {

    private:
        int size;
        int front;  // points at the index of first element
        int rear;   // points at the index of last element
        int *arr;

    public:
        Queue() {

            size = 5;
            front = rear = -1;
            arr = new int[size];
        }

        Queue(int size) {

            this->size = size;
            front = rear = -1;
            arr = new int[this->size];
        }

        void enqueue(int x);
        int dequeue();

        int isEmpty();
        int isFull();

        void display();
};

void Queue::enqueue(int x) {

    if(isFull())
        cout << "Queue is full" << endl;
    
    else {

        if(front == -1)
            front++;

        arr[++rear] = x;
    }

}

int Queue::dequeue() {

    int x = -1;
    if(isEmpty())
        cout << "Queue is Empty" << endl;

    else {
        
        x = arr[front];
        front++;
    } 

    return x;
}

int Queue::isEmpty() {

    if(rear == -1 || front > rear)
        return 1;
    
    return 0;
}

int Queue::isFull() {

    if(rear == size - 1)
        return 1;
    
    return 0;
}

void Queue::display() {

    for(int i = front; i <= rear; i++)
        cout << arr[i] << " "; 

    cout << endl;
}

int main() {

    Queue q;

    cout << "Is Empty: " << q.isEmpty() << endl;
    
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    cout << "Is Full: " << q.isFull() << endl; 

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}