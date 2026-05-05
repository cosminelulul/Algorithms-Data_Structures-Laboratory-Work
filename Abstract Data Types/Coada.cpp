#include <iostream>

using namespace std;

struct nod{
    int val;
    nod *ant, *urm;
};

void Adauga(nod *&n, int v){
    nod *nou = new nod;
    nou->val = v;
    nou->urm = NULL;
    nou->ant = NULL;

    if (n == NULL) {
        n = nou;
    } else {
        nod *temp = n;
        while(temp->urm != NULL)
            temp = temp->urm;
        temp->urm = nou;
        nou->ant = temp;
    }

}

void Elimina(nod *&n){

    if (n == NULL)
        return;


    nod *temp = n;

    n = temp->urm;

    if (n != NULL)
        n->ant = NULL;


    delete temp;
}


void Parcurge(nod *n){

    nod *temp = n;
    cout << endl << "Coada (Front->Back): <";
    if (temp == NULL)
         return;

    while(temp != NULL){
        cout << (temp->val) << " ";
        temp = temp->urm;
    }
    cout << ">" << endl;
}




int main()
{

    nod *pr = nullptr;


    int A; bool meniu = true;

    cout << "====Meniul Programului====" << endl;
    cout << "1.Adauga element la inceput" << endl;
    cout << "2.Elimina" << endl;
    cout << "3.Afisare" << endl;
    cout << "4. Iesi din meniu" << endl;

    while (meniu){

    cin >> A;

    switch(A){
    case 1:
        int x1;
        cout << "Introdu valoarea pe care o vrei in nod:" << endl;
        cin >> x1;
        Adauga(pr,x1);
        break;
    case 2:
        Elimina(pr);
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
