#include <iostream>

using namespace std;

struct Stiva{
    int val;
    Stiva *ant, *urm;
};

void Push(Stiva *&n, int v){

    Stiva *nou = new Stiva;
    nou->val = v;
    nou->urm = n;
    nou->ant = NULL;

    if (n != NULL) {
        n->ant = nou;
    }

    n = nou;
}


void Pop(Stiva *&n){

    if ( n == NULL)
        return;


    Stiva *temp = n;

    int valoareExtrase = temp->val;

    n = temp->urm;

    if (n != NULL) {
        n->ant = NULL;
    }

    delete temp;
}


void Parcurge(Stiva *n){
    Stiva *temp = n;

    cout << endl << "Stiva(VARF->BAZA): <";
    if (temp == NULL) {
         cout << "Stiva goala>";
         return;
    }
    while(temp != NULL){
        cout << (temp->val) << " ";
        temp = temp->urm;
    }
    cout << ">" << endl;
}


int main()
{

    Stiva *pr = nullptr;


    int A; bool meniu = true;

    cout << "====Meniul Programului====" << endl;
    cout << "1.Adauga element" << endl;
    cout << "2.Elimina un element" << endl;
    cout << "3.Afiseaza" << endl;
    cout << "4. Iesi din meniu" << endl;

    while (meniu){

    cin >> A;

    switch(A){
    case 1:
        int x1;
        cout << "Introdu valoarea pe care o vrei in nod:" << endl;
        cin >> x1;
        Push(pr,x1);
        break;
    case 2:
        Pop(pr);
        break;

    case 3:
        Parcurge(pr);
        break;
    case 4:
        meniu = false;
        break;
    default:
        cout << "Oops" << endl;
        break;
    }

    }


    return 0;
}
