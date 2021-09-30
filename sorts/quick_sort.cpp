#include <iostream>

using namespace std;

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int low, int high) {

    int pivot = A[low];
    int i = low, j = high;

    do {

        do{i++;}while(A[i] <= pivot);

        do{j--;}while(A[j] > pivot);

        if(i < j)
            swap(A[i], A[j]);
    }while(i < j);

    if(i > j)
        swap(A[low], A[j]);

    return j;
}

void quickSort(int A[], int low, int high) {

    int j;
    if(low < high) {

        j = partition(A, low, high);
        quickSort(A, low, j);
        quickSort(A, j+1, high);
    }
}

int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 1, 4, 8, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Quick Sort:" << endl;
    quickSort(A, 0, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}