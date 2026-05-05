#include <iostream>

using namespace std;

// Counting Sort

int main()
{
    int n;
    cin >> n;

    int A[n],B[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
        B[i] = 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (A[i] < A[j] )
                B[i]++;
    }

    int C[n];
    for (int i = 0; i < n; i++)
        C[n - 1 - B[i]] = A[i];

    for (int i = 0; i < n; i++)
        cout << C[i] << " ";

    return 0;
}
