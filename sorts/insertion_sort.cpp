#include <iostream>

using namespace std;


void insertionSort(int A[], int n) {

    int i, j, x = -1;
    for(i = 1; i < n; i++) {

        j = i - 1;
        x = A[i];
        
        while(j >= 0 && A[j] > x) {

            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

 int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 1, 4, 8, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Insertion Sort:" << endl;
    insertionSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
 }