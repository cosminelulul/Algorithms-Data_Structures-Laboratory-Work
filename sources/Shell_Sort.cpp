#include <iostream>

using namespace std;

// shell sort


void shell_sort(int v[], int n){

    for (int h = n/2; h > 0; h/=2){
        for (int i = h; i < n; i++){
            int temp = v[i];
            int j;

            for (j = i; j >= h && v[j-h] > temp; j-=h)
                v[j] = v[j-h];

            v[j] = temp;

        }

    }


}


int main()
{
    int n;
    cin >> n;

    int v[n];

    for (int i = 0; i<n;i++)
        cin >> v[i];

    shell_sort(v, n);

    for (int i = 0; i<n;i++)
        cout << v[i] << " ";

    return 0;
}
