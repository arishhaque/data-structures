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

class DoublyLinkedList {

    private:
        Node *head;

    public:

        Node * create(int A[], int size);
        void display();
        int getLength();

        void insert(int pos, int data);
        void deleteNode(int pos);

        void reverse();
};

Node * DoublyLinkedList::create(int A[], int size) {

    head = new Node(A[0]);

    Node *p = head;
    Node *last = NULL;
    for(int i = 1; i < size; i++) {

        Node *t = new Node(A[i]);
        p->next = t;
        t->prev = p;
        last = p;
        p = t;
    }
    p->prev = last;

    return head;
}

void DoublyLinkedList::display() {

    Node *p = head;
    while(p != NULL) {

        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int DoublyLinkedList::getLength() {

    int c = 0;
    Node *p = head;
    while(p != NULL) {

        c += 1;
        p = p->next;
    }
    return c;
}

void DoublyLinkedList::insert(int pos, int data) {

    if (head == NULL || pos < 0 || pos > getLength()) 
        return;

    Node *t = new Node(data);
    if(pos == 0) {

        head->prev = t;
        t->next = head;
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

void DoublyLinkedList::deleteNode(int pos) {

    if (head == NULL || pos < 1 || pos > getLength()) 
        return;

    Node *p = head;
    if(pos == 1){
 
        head = head->next; 
        head->prev = NULL;

        free (p);
    
    } else {

        for(int i = 0; i < pos - 2; i++)
            p = p->next;
        
        p->prev->next = p->next;
        if(p->next != NULL)
            p->next->prev = p->prev;
        
        free(p);

    } 
}

void DoublyLinkedList::reverse() {

    Node *p = head;
    while(p != NULL) {

        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;

        if(p != NULL && p->next == NULL)
            head = p;
    }

}

int main() {

    int A[] = {3, 5, 7, 10, 15};

    DoublyLinkedList dl;

    Node *first = dl.create(A, sizeof(A)/sizeof(A[0]));

    dl.display();

    cout << "Length: " << dl.getLength();

    cout << "\n";
    dl.insert(3,8);
    cout << "Insert after 3: ";
    dl.display();

    cout << "Delete 3rd Node: ";
    dl.deleteNode(3);
    dl.display();

    cout << "Reverse: ";
    dl.reverse();
    dl.display();

    return 0;
}