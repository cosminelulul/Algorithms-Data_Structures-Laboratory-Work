#include <iostream>

using namespace std;

// radix sort

int getMax(int v[],int n){

    int maxi = v[0];

    for (int i = 1 ; i < n; i++)
        if ( v[i] > maxi)
            maxi = v[i];

    return maxi;

}

void sorting(int v[], int n, int exp){
    int o_v[n];
    int i, vcount[10] = {0};

    for (i = 0; i < n; i++)
        vcount[(v[i] / exp) % 10]++;

    for (i = 1; i< 10; i++)
        vcount[i] += vcount[i-1];

    for (i = n-1; i >= 0; i--){
        o_v[vcount[(v[i] / exp) % 10] - 1] = v[i];
        vcount[(v[i] / exp) % 10]--;
    }

}

void radix_sort(int v[],int n){

    int maxi = getMax(v,n);

    for (int exp = 1; maxi / exp > 0; exp *= 10)
        sorting(v, n, exp);


}



int main()
{
    int n;
    cin >> n;

    int v[n];

    for (int i = 0; i<n;i++)
        cin >> v[i];

    radix_sort(v, n);

    for (int i = 0; i<n;i++)
        cout << v[i] << " ";
    return 0;
}
