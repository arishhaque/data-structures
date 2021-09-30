#include <iostream>

using namespace std;

class Node {

    public:
        int data;
        Node *next;

        Node(int val) {

            data = val;
            next = NULL;
        }
};

int findMax(int A[], int n) {

    int max = 0;
    for(int i=0; i < n; i++) {

        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void insert(Node **b, int idx) {

    Node *t = new Node(idx);
    if(b[idx] == NULL)
        b[idx] = t;
    
    else {

        Node *p = b[idx];
        while(p->next != NULL)
            p = p->next;

        p->next = t;
    }
}

int remove(Node **b, int idx) {

    Node *p = b[idx]; 
    b[idx] = b[idx]->next;
    int x = p->data;

    delete p;
    
    return x;
}

void bucketSort(int A[], int n) {

    int i,j;
    int max = findMax(A, n);

    Node **bucket = new Node* [max + 1];
    for(i=0; i < n; i++)
        insert(bucket, A[i]);

    i = 0;
    j = 0;
    while (i < max+1) {

        while (bucket[i] != nullptr)
            A[j++] = remove(bucket, i);
        
        i++;
    }
}


int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 3, 4, 8, 6};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Bucket Sort:" << endl;
    bucketSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}