#include <iostream>

using namespace std;

int main()
{
    int m,n,p;
    cout << "m,n,p="; cin >> m >> n >> p;

    float A[m][n],B[n][p];

    cout << "Elemente A:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Elemente B:"<< endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    cout << "Elemente A:"<< endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
    cout << endl;
    }

    cout << "Elemente B:"<< endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++)
            cout << B[i][j] << " ";
       cout << endl;
    }

    float C[m][p];

    for (int i = 0; i < m; i++)
        for ( int j = 0; j < p; j++){
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    cout << "Elemente C:"<< endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
    cout << endl;
    }









    return 0;
}
