#include <iostream>

using namespace std;

// Quick Sort

// Presupunem ca ultimul element este pivot

void quick_sort(int v[], int stanga, int dreapta){
    if (stanga < dreapta){
        int pivot = v[dreapta];
        int i = stanga - 1;
        int temp;

        for (int j = stanga; j < dreapta; j++){
            if ( v[j] <= pivot){
                i++;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }

        temp = v[i+1];
        v[i+1] = v[dreapta];
        v[dreapta] = temp;

        int index = i+1;

        quick_sort(v,stanga, index-1);
        quick_sort(v,index+1,dreapta);

    }





}


int main()
{
    int n;
    cin >> n;
    int v[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    quick_sort(v,0,n-1);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";



    return 0;
}
