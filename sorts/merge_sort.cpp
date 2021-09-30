#include <iostream>

using namespace std;

void merge(int A[], int low, int mid, int high) {

    int i=low, j=mid+1, k=low;
    int B[high+1];

    while(i <= mid && j <= high) {

        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while(i <= mid)
        B[k++] = A[i++];

    while(j <= high)
        B[k++] = A[j++];

    for(i=low; i <= high; i++)
        A[i] = B[i];

}

void mergeSort(int A[], int n) {

    int i;
    for (i=2; i<=n; i=i*2) {

        for (int j=0; j+i-1<n; j=j+i) {

            int low = j;
            int high = j+i-1;
            int mid = (low+high)/2;

            merge(A, low, mid, high);
        }
    }
    if (i/2 < n){
        merge(A, 0, i/2-1, n-1);
    }
}


void mergeSortRec(int A[], int low, int high) {

    if(low < high) {

        int mid = (low + high)/2;
        mergeSortRec(A, low, mid);
        mergeSortRec(A, mid+1, high);
        merge(A, low, mid, high);
    }

}

int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 1, 4, 8, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Merge Sort:" << endl;
    mergeSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    int B[] = {12, 17, 16, 15, 14, 13, 11, 0, 0, 1};
    int m = sizeof(B)/sizeof(B[0]);

    cout<< "Recursive Merge Sort:" << endl;
    mergeSortRec(B, 0, m-1);

    for(int i = 0; i < m; i++)
        cout << B[i] << " ";
    
    cout << endl;
     
    return 0;
}