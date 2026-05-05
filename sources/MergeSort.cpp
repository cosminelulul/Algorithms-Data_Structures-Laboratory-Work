#include <iostream>

using namespace std;

// Merge Sort

void mergesort(int s, int d, int v[]){
    if (s < d){
        int m = (s+d) / 2;
        mergesort(s, m ,v);
        mergesort(m+1,d,v);

    int i = s;
    int j = m+1; int k =0;
    int w[d-s+1];

    while ( i <= m && j<= d)
        if ( v[i] < v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];

    while (i <= m)
        w[k++] = v[i++];
    while ( j <= d)
        w[k++] = v[j++];
    for ( i = s; i<=d; i++)
        v[i] = w[i-s];
    }
}

int main()
{
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    mergesort(0,n-1,A);

    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    return 0;
}
