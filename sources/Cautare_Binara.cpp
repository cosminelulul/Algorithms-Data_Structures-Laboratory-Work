#include <iostream>

using namespace std;

// Cautarea binara

int cautare_binara(int s, int d, int v[], int y){
    if ( s > d)
        return 0;
    else {
        int m = ( s + d) / 2;
        if ( y == v[m]){
            return 1;
        } else if ( y != v[m]){
            if (y < v[m])
                cautare_binara(s,m-1,v,y);
            else
                cautare_binara(m+1,d,v,y);
        }

    }

}


int main()
{
    int n; cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int y;
    cin >> y;

    if (cautare_binara(0,n,v,y) == 1)
        cout << y << " se afla in sirul v";
    else
        cout << y << " nu se afla in sirul v";


    return 0;
}
