#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {

    private:
        stack<int> stk1;
        stack<int> stk2;

    public:
        QueueUsingStacks(){};
        ~QueueUsingStacks(){};

        void enqueue(int x);
        int dequeue();

        void display(); 

};

void QueueUsingStacks::enqueue(int x) {

        stk1.push(x);
}

int QueueUsingStacks::dequeue() {

    int x = -1;
    if(stk1.empty()) {

        x = stk2.top();
        stk2.pop();
    
    } else {

        while(!stk1.empty()) {

            stk2.push(stk1.top());
            stk1.pop();
        }
        x = stk2.top();
        stk2.pop();
    }

    return x;
}

void QueueUsingStacks::display() {

    while(!stk2.empty()) {
        cout << stk2.top() << " ";
        stk2.pop();
    }

    while(!stk1.empty()) {
        stk2.push(stk1.top());
        stk1.pop();
    }

    while(!stk2.empty()) {
        cout << stk2.top() << " ";
        stk2.pop();
    }
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    QueueUsingStacks qs;
 
    cout << "Enqueue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        qs.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
    cout << endl;
 
    cout << "Dequeue: " << flush;
    cout << qs.dequeue() << endl;

    cout << "Dequeue: " << flush;
    cout << qs.dequeue() << endl;

    qs.enqueue(11);

    cout << "Display: " << endl;
    qs.display();
 
    return 0;
}