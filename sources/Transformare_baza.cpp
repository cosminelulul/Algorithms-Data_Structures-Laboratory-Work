#include <iostream>

using namespace std;

int main()
{

    int nr, base;
    cout << "nr, baza="; cin >> nr >> base;

    int nr_converted = 0;
    int mp = 1;
    int nr_copy = nr;

    while (nr_copy > 0){
        nr_converted += nr_copy % base * mp;
        nr_copy /= base;
        mp *= 10;
    }

    cout << nr_converted << endl;

    return 0;
}
