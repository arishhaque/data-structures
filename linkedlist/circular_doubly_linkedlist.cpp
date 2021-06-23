#include <iostream>
using namespace std;


class Node {

 public:
    
    Node *prev;
    int data;
    Node *next;

    Node(int val){

        prev = NULL;
        data = val;
        next = NULL;
    }
};

class CircularDoublyLinkedList {

    private:
        Node *head;

    public:

        CircularDoublyLinkedList() {

            head = NULL;
        }

        Node * create(int A[], int size);
        void display();
        int getLength();

        void insert(int pos, int data);
        void deleteNode(int pos);
};

Node * CircularDoublyLinkedList::create(int A[], int size) {

    head = new Node(A[0]);
    Node *last = head;
    for(int i = 1; i < size; i++) {

        Node *t = new Node(A[i]);
        last->next = t;
        t->prev = last;
        last = t;
    }

    last->next = head;
    head->prev = last;

    return head;
}

void CircularDoublyLinkedList::display() {

    Node *p = head;
    do {

        cout << p->data << " ";
        p = p->next;
      
    } while(p != head);

    cout << "\n";
}

int CircularDoublyLinkedList::getLength() {

    int c = 0;
    Node *p = head;
    do {

        c += 1;
        p = p->next;
      
    } while(p != head);

    return c;
}

void CircularDoublyLinkedList::insert(int pos, int data) {

    if(head == NULL || pos < 1 || pos > getLength())
        return;

    Node *t = new Node(data);
    if(pos == 1) {

        t->next = head;
        t->prev = head->prev;

        head->prev->next = t;
        head->next->prev = t;

        head = t;
    } else {

        Node *p = head;
        for(int i = 0; i < pos - 1; i++)
            p = p->next;

        t->prev = p;
        t->next = p->next;

        p->next->prev = t;
        p->next = t;
    }
}

 void CircularDoublyLinkedList::deleteNode(int pos) {

     if(head == NULL || pos < 1 || pos > getLength())
        return;

    Node *p = head;
    if(pos == 1) {

        head = head->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        
        free(p);
    } else {

        for(int i = 0; i < pos - 1; i++) 
            p = p->next;

        p->prev->next = p->next;
        p->next->prev = p->prev;

        free(p);
    }  
 }

int main() {

    int A[] = {3, 5, 8, 10, 15};

    CircularDoublyLinkedList cdl;

    Node *first = cdl.create(A, sizeof(A)/sizeof(A[0]));

    cdl.display();

    cout << "Length: " << cdl.getLength();

    cout << "\n";
    cdl.insert(3,6);
    cout << "Insert after 3: ";
    cdl.display();

    cdl.deleteNode(1);
    cout << "Delete Node 3: ";
    cdl.display();

    return 0;
}