#include <iostream>

using namespace std;

int findMax(int A[], int n) {

    int max = 0;
    for(int i=0; i < n; i++) {

        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int A[], int n) {

    int i,j;
    int max = findMax(A, n);
    int *c = new int[max + 1];

    for(i = 0; i < max; i++)
        c[i] = 0;

    for(i=0; i < n; i++)
        c[A[i]]++;

    i = 0;
    j = 0;
    while(i <= max) {

        if(c[i] > 0) {
            A[j++] = i;
            c[i]--;
        } else {
            i++;
        }
    }
}


int main() {

    int A[] = {3, 9, 7, 10, 6, 5, 3, 4, 8, 6};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Count Sort:" << endl;
    countSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}