#include <iostream>

using namespace std;

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int A[], int n) {

    int i,j,flag=0;
    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - i - 1;  j++){

            if(A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                flag = 1;
            }  
        }
        if(flag == 0)
            break;
    }
}

 int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 1, 4, 8, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Bubble Sort:" << endl;
    bubbleSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
 }