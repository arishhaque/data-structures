#include <iostream>
using namespace std;


class Node {

 public:
    int data;
    Node *next;

    Node(int val){

        data = val;
        next = NULL;
    }
};

class CircularLinkedList {

    private:
        Node *head;

    public:

        CircularLinkedList(){ head = NULL;}

        Node * create(int A[], int size);

        void display();
        void recDisplay(Node *p);

        int getLength();

        void insert(int pos, int data);

        void deleteNode(int pos);

};

Node * CircularLinkedList::create(int A[], int size) {

    head = new Node(A[0]);
    Node *last = head;
    for(int i = 1; i < size; i++) {

        Node *temp = new Node(A[i]);
        last->next = temp;
        last = temp;

    }
    last->next = head;

    return head;

}

void CircularLinkedList::insert(int pos, int data) {

    if(pos < 1 || pos > getLength())
        return;

    Node *p = head;
    Node *t = new Node(data);
    if(pos == 1) {

        if(head == NULL) {

            head = t;
            head->next = t;

        } else {

            while(p->next != NULL)
                p = p->next;
            
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    for(int i = 0; i < pos - 1; i++)
        p = p->next;
    
    t->next = p->next;
    p->next = t;
    
    

}

int CircularLinkedList::getLength() {

    Node *p = head;
    int count = 1;
    while(p->next != head) {

        count += 1;
        p = p->next;
    }

    return count;
}

void CircularLinkedList::deleteNode(int pos) {

    if(head == NULL || pos < 1 || pos > getLength())
        return;

    Node *p = head;
    if(pos == 1) {

        while(p->next != head)
            p = p->next;
        
        if(p == head) {

            free(head);
            head = NULL;

        }else {

            p->next = head->next;
            free(head);
            head = head->next;
        }
    }else {

        Node *q = head;
        for(int i = 0; i < pos - 2; i++) 
            q = q->next;
        
        p = q->next;
        q->next = p->next;
        free(p);
    }

    

}

void CircularLinkedList::display() {

    Node *p = head;
    do {

        cout << p->data << " ";
        p = p->next;

    }while(p != head);
    
    cout << "\n";
}

 void CircularLinkedList::recDisplay(Node *p) {

    cout << p->data << " ";
    p = p->next;

    if(p == head)
        return;
    
    recDisplay(p);
 }

int main() {

    int A[] = {3, 5, 7, 10, 15};

    CircularLinkedList cl;

    Node *first = cl.create(A, sizeof(A)/sizeof(A[0]));

    cl.display();

    cl.recDisplay(first);

    cout << "\n";
    cl.insert(4, 12);
    cout << "Insert after 4: ";
    cl.display();

    cout << "Delete Node: 4 \n";
    cl.deleteNode(4);
    cl.display();

    return 0;

}