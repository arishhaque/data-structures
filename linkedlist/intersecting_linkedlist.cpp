#include <iostream>
#include <stack>
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

class IntersectingLinkedList {

    Node *head;

    public:

        IntersectingLinkedList(){ head = NULL;}

        Node * create(int A[], int size);
        void display(Node *p);

        Node * findIntersection(Node *p, Node *q);
};

Node * IntersectingLinkedList::create(int A[], int size) {

    head = new Node(A[0]);
    Node *prev = head;
    for (int i = 1; i < size; i++) {

        Node *temp = new Node(A[i]);
        prev->next = temp;
        prev = prev->next;
        
    }
    return head;
}

void IntersectingLinkedList::display(Node *p) {

    while(p != NULL) {

        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

 Node * IntersectingLinkedList::findIntersection(Node *p, Node *q) {

    if(p == NULL || q == NULL)
        return NULL;

    stack<Node*> s1;
    stack<Node*> s2;

    while(p != NULL) {

        s1.push(p);
        p = p->next;
    }
    
    while(q != NULL) {
        
        s2.push(q);
        q = q->next;
    }

    Node *last = NULL;
    while(s1.top() == s2.top()){

        last = s1.top();
        s1.pop();
        s2.pop();
    }

    cout << "Intersecting Node: " <<  last->data;
    return last;
 }

int main() {

    int A[] = {5, 15, 18, 25, 55};

    int B[] = {10, 20};

    IntersectingLinkedList ll;

    Node *first = ll.create(A, sizeof(A)/sizeof(A[0]));

    Node *second = ll.create(B, sizeof(B)/sizeof(B[0]));

    second->next->next = first->next->next->next;

    ll.display(first);

    ll.display(second);

    ll.findIntersection(first, second);

    return 0;
}