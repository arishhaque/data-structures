#include <iostream>

using namespace std;

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}


void selectionSort(int A[], int n) {

    int i,j,k;

    for(i = 0; i < n - 1; i++) {

        k=i;
        for(j=i; j < n; j++) {

            if(A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}


int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 1, 4, 8, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Selection Sort:" << endl;
    selectionSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}