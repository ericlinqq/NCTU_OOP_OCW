// utils.cpp
#include <iostream>
using std::cout;
using std::endl;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(int *A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[r], A[i+1]);
    return i+1;
}

// sort elements in A[p]~A[r]
void QuickSort(int *A, int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);   // left
        QuickSort(A, q+1, r);   // right
    }
}

// find the i-th smallest element in A[l]~A[r]
int Select(int *A, int l, int u, int i) {
    if (l < u) {
        int q = Partition(A, l, u);
        int k = q-l+1;
        if (i == k)
            return A[q];
        else if (i < k)
            return Select(A, l, q-1, i);
        else 
            return Select(A, q+1, u, i-k);
    }
    else if (l == u)
        return A[l];
    else {
        cout << "Error! lower bound must be <= upperbound" << endl;
        exit(1);
    }
}

// find an integer k in A[l]~A[u]
int BinSearch(int *A, int l, int u, int k) {
    if (l <= u) {
        int m = (l+u) / 2;
        if (k == A[m])
            return m;
        else if (k < A[m])
            return BinSearch(A, l, m-1, k);
        else
            return BinSearch(A, m+1, u, k);
    }
    return -1;
}
