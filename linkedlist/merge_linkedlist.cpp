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

class LinkedList{

    Node *head;

    public:

        LinkedList(){ head = NULL;}

        Node * create(int A[], int size);
        void display(Node *p);

        void concat(Node *p, Node *q);

        Node * mergeSorted(Node *p, Node *q);
};

Node * LinkedList::create(int A[], int size) {

    head = new Node(A[0]);
    Node *prev = head;
    for (int i = 1; i < size; i++) {

        Node *temp = new Node(A[i]);
        prev->next = temp;
        prev = prev->next;
        
    }
    return head;
}

void LinkedList::display(Node *p) {

    while(p != NULL) {

        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void LinkedList::concat(Node *p, Node *q) {

    while(p->next != NULL) {

        p = p->next;
    }
    p->next = q;
}

 Node * LinkedList::mergeSorted(Node *p, Node *q) {

    Node *first = NULL;
    Node *last = NULL;
    
    if(p->data < q->data) {

        first = last = p;
        p = p->next;
        last->next = NULL;
    
    } else {

        first = last = q;
        q = q->next;
        last->next = NULL;
    }

    while(p != NULL && q != NULL) {

        if(p->data < q->data) {

            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
            
        } else {

            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;

        }
    }

    if(p != NULL)
        last->next = p;
    else
        last->next = q;

    return first;
 }

int main() {

    int A[] = {5, 15, 25, 55};

    int B[] = {10, 20, 30, 40};

    LinkedList ll;

    Node *first = ll.create(A, sizeof(A)/sizeof(A[0]));

    Node *second = ll.create(B, sizeof(B)/sizeof(B[0]));

    ll.display(first);

    ll.display(second);

    
    cout << "Merge Sorted Linked List\n";
    Node *merge = ll.mergeSorted(first, second);
    ll.display(merge);
   
   /*
    cout << "Concatenated Linked List\n";
    ll.concat(first, second);
    ll.display(first);
    */


}