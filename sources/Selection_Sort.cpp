#include <iostream>

using namespace std;

// Selection Sort

int main()
{
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0 ; i < n ; i++){

        int min_poz = i;

        for (int j = i+1; j < n; j++){
            if (A[j] < A[min_poz])
                min_poz = j;
        }

        int temp = A[i];
        A[i] = A[min_poz];
        A[min_poz] = temp;

    }

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
