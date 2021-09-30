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

int countDigit(int number) {

   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

void insert(Node **b, int idx, int val) {

    Node *t = new Node(val);
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

void radixSort(int A[], int n) {

    int i,j;
    int max = findMax(A, n);
    int k = countDigit(max);
    int m = 1;

    Node **bucket = new Node* [n];
    for(j=0; j < k; j++) {
        
        for(i=0; i < n; i++) {
            int idx = (A[i]/m) % 10;
            insert(bucket, idx, A[i]);
        }
        int p=0, q=0;
        while (p < n) {
            while (bucket[p] != nullptr)
                A[q++] = remove(bucket, p);
        
            p++;
        }
        m = m * 10;
    }

    i = 0;
    j = 0;
    while (i < n) {

        while (bucket[i] != nullptr)
            A[j++] = remove(bucket, i);
        
        i++;
    }
}


int main() {

    int A[] = {13, 9, 7, 10, 16, 5, 3, 4, 8, 6};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Radix Sort:" << endl;
    radixSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}