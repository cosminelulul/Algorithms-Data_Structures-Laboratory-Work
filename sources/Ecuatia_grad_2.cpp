#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Ecuatia de grad 2

    float a, b, c;
    float x1,x2;
    cout << "ax^2="; cin >> a;
    cout << "bx="; cin >> b;
    cout << "cx="; cin >> c;

    float delta = b*b - 4*a*c;

    if (delta == 0){
        x2 = -b / (2*a);
        x1 = x2;
        cout << "x1=" << x1 << " x2= " << x2 << endl;
    }
    else if (delta > 0){
        x1 = ((-1)*b + sqrt(delta)) / (2*a);
        x2 = ((-1)*b - sqrt(delta)) / (2*a);
        cout << "x1=" << x1 << " x2= " << x2 << endl;
    }else if ( delta < 0){
        float x1_im,x2_im;
        x2 = x1 = ((-1)*b) / (2*a);
        x1_im = sqrt(((-1)*delta)) / (2*a);
        x2_im = sqrt(((-1)*delta)) / (2*a);

        cout << "x1,2=" << x1  << "+-i*"<<  x1_im << endl;
    }



    return 0;
}
