
#include <iostream>
using namespace std;

// Ciurul lui Eratostene 

int main(){

    int n;
    cout << "n= "; cin >> n;

    int A[n+1];
    bool A_pr[n+1];

    for (int i = 1; i <= n; i++){
        A[i] = i;
        A_pr[i] = true;
    }


    for (int i = 2; i <= n; i++){
        if (A_pr[i] == true){
            for (int k = i * A[i]; k <= n; k = k + A[i])
              A_pr[k] = false;
        }
    }

    for (int i = 2; i <= n; i++){
        if (A_pr[i] == true)
            cout << A[i] << " ";
    }
    return 0;
}
