#include <iostream>
#include <string.h>


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

int Top(Stiva *n) {
    if (n == NULL)
        return -1;
    return n->val;
}

bool CheckEmpty(Stiva *n) {
    return (n == NULL);
}

bool VerificareExpresia(char str[], int n){

    Stiva *parcurge = nullptr;

    for (int i = 0; i < n; i++){
        char caracter = str[i];
        int valoareVarf;

        switch (caracter) {
            case '(':
                Push(parcurge, 1);
                break;
            case '[':
                Push(parcurge, 2);
                break;
            case '{':
                Push(parcurge, 3);
                break;
            case ')':
                if (CheckEmpty(parcurge))
                    return false;
                valoareVarf = Top(parcurge);
                Pop(parcurge);
                if (valoareVarf != 1)
                    return false;
                break;
            case ']':
                if (CheckEmpty(parcurge))
                    return false;
                valoareVarf = Top(parcurge);
                Pop(parcurge);
                if (valoareVarf != 2)
                    return false;
                break;
            case '}':
                if (CheckEmpty(parcurge))
                    return false;
                valoareVarf = Top(parcurge);
                Pop(parcurge);
                if (valoareVarf != 3)
                    return false;
                break;
        }


    }

    return CheckEmpty(parcurge);
}


int main()
{

    Stiva *pr = nullptr;


    int A; bool meniu = true;
    char expr[256];

    cout << "====Meniul Programului====" << endl;
    cout << "1.Adauga element" << endl;
    cout << "2.Elimina un element" << endl;
    cout << "3.Afiseaza" << endl;
    cout << "4.Verifica expresia matematica" << endl;
    cout << "0. Iesi din meniu" << endl;

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
            cout << "Scrie expresia matematica pentru verificare:" << endl;
            cin >> expr;
            if (VerificareExpresia(expr,strlen(expr)) == true)
                cout << "Expresia a fost scrisa corect" << endl;
            else
                cout << "Expresia nu a fost scrisa corect" << endl;
            break;
        case 0:
            meniu = false;
            break;
        default:
            cout << "Oops" << endl;
            break;
        }

    }


    return 0;
}
