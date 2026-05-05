#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int nr;
    cout << "nr= "; cin >> nr;
    bool cond = true;

    if ( nr % 2 == 1){
        for (int k = 3; k < nr/2; k=k+2)
            if (nr % k == 0){
                cond = false;
                break;
            }
    }else cond = false;

    if (cond == true)
        cout << "nr este prim" << endl;
    else cout << "nr nu este prim" << endl;


    return 0;
}
