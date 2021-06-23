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
    int size;

 public:

    LinkedList(){ head = NULL; size = 0;}

    Node* getHead();
    Node* create(int A[], int n);
    void insert(int pos, int data);
    void insertAtEnd(int data);
    void sortedInsert(int x);
    void display();
    void deleteNode(int pos);
    void reverse();
    void recReverse(Node *q, Node *p);
    bool isSorted();
    void removeDuplicates();
    int count();
    int recCount(Node *p);
    int sum();
    Node* search(int x);
    bool detectLoop();
    Node* findMidNode();
};


Node* LinkedList::getHead() { return head;}

Node* LinkedList::create(int A[], int n){


    head = new Node(A[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++) {

        Node *temp = new Node(A[i]);
        prev->next = temp;
        prev = prev->next;
        
    }
    size = n;
    return head;
}

void LinkedList::insert(int pos, int data){

    if(pos < 1 || pos > size) {
    
        cout << "postition out of range";
        return;
    }

    Node *temp = new Node(data);
    if(pos == 1) {

        temp->next = head;
        head = temp;
    
    } else {

        Node *p = head;
        for(int i = 0; i < pos - 1; i++)
            p = p->next;
        
        temp->next = p->next;
        p->next = temp;

    }
    size++;
}

void LinkedList::insertAtEnd(int data) {

    if(head == NULL) {

        head = new Node(data);
        return;
    }

    Node *p = head;
    Node *temp = new Node(data);

    while(p->next != NULL)
        p = p->next;

    p->next = temp;
    size++;
}

void LinkedList::sortedInsert(int x) {

    Node *p = head;
    Node *q = NULL;
    Node *temp = new Node(x);
    if(head == NULL) {
        head = temp;
        return;
    }
    
    while(p != NULL && p->data < x) {

        q = p;
        p = p->next;
    }

    if(p == head){
            
        temp->next = head;
        head = temp;
        
    } else {

        temp->next = q->next;
        q->next = temp;
    } 

    size++;
}

void LinkedList::display() {

    Node *p = head;
    while(p != NULL){

        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void LinkedList::deleteNode(int pos) {

    Node *p = head;
    Node *q = NULL;

    if(head == NULL || pos < 1 || pos > size)
        return;

    if(pos == 1){

        Node *t = head;
        head = head->next;
        free(t);
        return;
    }
    for(int i = 0; i < pos - 1; i++) {

        q = p;
        p = p->next;
    }

    q->next = p->next;
    free(p);
    size--;
}

void LinkedList::reverse(){

    if(head == NULL)
        return;

    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while(p != NULL) {

        r=q;
        q=p; 
        p = p->next;
        q->next = r;
        
    }
    head = q;
}

void LinkedList::recReverse(Node *q, Node *p){

    if(p != NULL) {

        recReverse(p, p->next);
        p->next = q;
    }
    else head = q;
}

bool LinkedList::isSorted() {

    if(head == NULL)
        return false;

    int x = -32768;
    Node *p = head;
    while(p != NULL) {

        if(p->data > x)
            return false;
        
        x = p->data;
        p = p->next;
    }
    return true;
}

void LinkedList::removeDuplicates() {

    if(head == NULL)
        return;
    
    Node *q = head;
    Node *p = head->next;

    while(p != NULL) {

        if(q->data != p->data) {

            q = p;
            p = p->next;
        }
        else {
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
}




int LinkedList::recCount(Node *p) {

    if(p != NULL)
        return 1 + recCount(p->next);
    
    return 0;

}

int LinkedList::sum() {

    Node *p = head;
    int sum = 0;
    while(p != NULL) {

        sum += p->data;
        p = p -> next;
    }
    return sum;
}

Node* LinkedList::search(int x) {

    Node *p = head;
    Node *q = NULL;
    while(p != NULL) {

        if(x == p->data) {

            if(q != NULL) { // move searched item to head

                q->next = p->next;
                p->next = head;
                head = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

bool LinkedList::detectLoop() {

    Node *p, *q;
    p = q = head;

    do{

        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    
    } while(p != NULL && q != NULL && p != q);

    if(p == q)
        return true;
    else
        return false;
}

Node* LinkedList::findMidNode() {

    Node *p;
    Node *q;
    p = q = head;
    while(p != NULL) {

        p = p->next;
        if(p != NULL) {
            p = p->next;
            q = q->next;
        }
    }

    return q;
}

int main() {

    int A[] = {3, 5, 7, 8, 10, 15};

    LinkedList ll;

    Node *first = ll.create(A, sizeof(A)/sizeof(A[0]));

    ll.display();

    cout << "Recursive Count:" << ll.recCount(first);

    cout << "\n";
    cout << "Sum:" << ll.sum();

    cout << "\n";
    cout << "Search Result:" << ll.search(10)->data;

    cout << "\n";
    ll.display();

    cout << "Search Result2: " << ll.search(10)->data;

    cout << "\n";
    cout << "Insert at 3: ";
    ll.insert(2, 9);
    ll.display();

    ll.insertAtEnd(15);
    ll.insertAtEnd(15);

    ll.sortedInsert(13);

    ll.display();
    cout << "Delete Node: 3\n";
    ll.deleteNode(10);
    ll.display();

    cout << (ll.isSorted() == 0 ? "Not Sorted" : "Sorted");
    cout << "\n";

    ll.removeDuplicates();
    ll.display();
    
    cout << "Reverse: ";
    ll.reverse();
    ll.display();

    cout << "Recursive Reverse: ";
    ll.recReverse(NULL, ll.getHead());
    ll.display();

    Node *midNode = ll.findMidNode();
    cout << "Middle Node: " << midNode->data << endl; 

    // check for loop in the linked list
    int B[] = {10, 20, 30, 40, 50};

    Node *temp = ll.create(B, sizeof(B)/sizeof(B[0]));

    Node *t1 = temp->next->next;
    Node *t2 = temp->next->next->next->next;

    t2->next = t1;
    cout << "Detect Loop: " << (ll.detectLoop() ? "true" : "false") << endl;

    return 0;

}