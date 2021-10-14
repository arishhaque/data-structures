#include <iostream>
#include <vector>

using namespace std;
 
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Insert(int A[], int n) {

    int i = n - 1;
    int temp = A[n - 1];
    
    while(i > 0 && temp > A[i % 2 == 0 ? (i/2) - 1: i/2]) {

       A[i] = A[i/2];
       i = i/2;
    }
    A[i] = temp;
}
 
int Delete(int A[], int n) {

    int x = A[0];  // Max element
    A[0] = A[n-1];
 
    int i = 0;
    int j = 2 * i + 1;
    
    while(j < n - 1) {

        if(A[j] < A[j+1])
            j++;

        if(A[i] < A[j]) {

            swap(A, i, j);
            i = j;
            j = 2*i + 1;
        }
        else break;
    }
    A[n-1] = x;
    return x;
}

void Heapify(int A[], int n) {

    // Number of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n/2) - 1; i >= 0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
        while(j < n-1) {

            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;

            } else break;
        }
    }
}

int DeleteH(int A[], int n) {

    int x = A[0];  // Max element
    A[0] = A[n-1];
    A[n-1] = x;

    Heapify(A, n - 2);

    return x;
}
 
// STL vector based
void InsertV(vector<int>& vec, int key){
    // Insert key at the end
    int i = vec.size();
    vec.push_back(key);
 
    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}

void create(vector<int>& vec,  int A[], int n) {

    int i;
    for(i = 0; i < n; i++)    
        InsertV(vec, A[i]);
    
}
 
template <class T>
void Print(T& vec, int n) {

    cout << "Max Heap: [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
}
 
 
int main() {
 
    int a[] = {9, 10, 20, 30, 25, 5, 40, 35};
    for(int i = 1; i < sizeof(a)/sizeof(a[0]); i++)
        Insert(a, i);

    Print(a, sizeof(a)/sizeof(a[0]));
    cout << endl;

    int h[] = {9, 10, 20, 30, 25, 5, 40, 35};

    cout << "Heapify" << endl;
    Heapify(h, sizeof(h)/sizeof(h[0]));
    Print(h, sizeof(h)/sizeof(h[0]));

    //cout << "Deleted val: " << Delete(h, 8) << endl;
    //Print(h, sizeof(h)/sizeof(h[0]));
    //cout << endl;
    //cout << "Deleted all elements: " << endl;
    for(int i = 8; i > 0; i--)
        DeleteH(h, i);
    
    cout << "After deleting all elements, Sorted Array: " << endl;
    for(int i = 0; i < sizeof(h)/sizeof(h[0]); i++)
        cout << h[i] << " ";

    cout << endl;


    // STL based
    vector<int> v;
    int b[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++) 
        v.push_back(b[i]); 

    v.reserve(15);  // Reserve space for 15 elements
    InsertV(v, 9);
    Print(v, v.size());
    cout << endl;
 
    vector<int> v1;
    create(v1, b, sizeof(b)/sizeof(b[0]));
    Print(v1, v1.size());
 
    return 0;
}