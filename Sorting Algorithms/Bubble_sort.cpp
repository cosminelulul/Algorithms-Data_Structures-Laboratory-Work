#include <iostream>

using namespace std;

// Bubble Sort

int main()
{
    int n;

    cin >> n;

    bool cond = true;
    int A[n];


    for (int i = 0; i < n; i++)
        cin >> A[i];

    while (cond){
        cond = false;
        for ( int j = 0; j < n-1; j++)
            if ( A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                cond = true;
            }

    }

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";



    return 0;
}
