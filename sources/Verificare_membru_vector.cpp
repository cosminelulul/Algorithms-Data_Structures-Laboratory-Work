#include <iostream>

using namespace std;

// Cautarea secventiala


int main()
{
    int n; cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int y;
    cin >> y;
    int c = 0;

    for (int i = 0; i < n; i++){

        if ( v[i] == y)
            c++;

    }

    if ( c == 0)
        cout << y << " nu se afla in sirul v";
    else
        cout << y << " se afla in sirul v";

    return 0;
}
