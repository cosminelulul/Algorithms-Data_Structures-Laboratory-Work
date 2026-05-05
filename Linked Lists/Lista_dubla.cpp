#include <iostream>

using namespace std;

struct nod{
    int val;
    nod *ant, *urm;
};

void AdaugaInceput(nod *&n, int v){
    nod *nou = new nod;
    nou->val = v;
    nou->urm = n;
    nou->ant = NULL;

    if (n != NULL) {
        n->ant = nou;
    }

    n = nou;
}

void AdaugaFinal(nod *&n, int v){
    nod *nou = new nod;
    nou->val = v;
    nou->urm = NULL;
    nou->ant = NULL;


    if (n == NULL)
        n = nou;
    else{

        nod *temp = n;
        while(temp->urm != NULL)
            temp = temp->urm;
        temp->urm = nou;
        nou->ant = temp;
    }
}

void AdaugaDupaVal(nod *&n, int v,int elem){

    nod *temp = n;

    while (temp != NULL && temp->val != elem) {
        temp = temp->urm;
    }

    if (temp != NULL) {

        nod *nou = new nod;
        nou->val = v;
        nou->urm = temp->urm;
        nou->ant = temp;
        temp->urm = nou;


        if (nou->urm != NULL) {
            nou->urm->ant = nou;
        }
    }
    else return;

}


void StergereElement(nod *&n, int v){

    nod *temp = n;

    while (temp != NULL && temp->val != v)
        temp = temp->urm;


    if (temp == NULL)
        return;


    if (temp == n)
        n = temp->urm;


    if (temp->ant != NULL)
        temp->ant->urm = temp->urm;


    if (temp->urm != NULL)
        temp->urm->ant = temp->ant;


    delete temp;
}


void ModificaElement(nod *&n, int v, int newV){

    nod *temp = n;

    while (temp != NULL){
        if (temp->val == v){
            temp->val = newV;
            return;
        }
        temp = temp->urm;

    }

}

void Parcurge(nod *n){
    nod *temp = n;
    cout << endl << "Lista=<";
    cout << (temp->val) << " ";
    while(temp->urm != NULL){
        temp = temp->urm;
        cout << (temp->val) << " ";
    }
    cout << ">" << endl;
}

void ParcurgeRevere(nod *n){

    if (n == nullptr)
        return;


    nod *temp = n;
    cout << endl << "Lista=<";
    while (temp->urm != NULL)
        temp = temp->urm;


    while(temp->ant != NULL){
        cout << (temp->val) << " ";
        temp = temp->ant;
    }
    cout << (temp->val) << " ";
    cout << ">" << endl;
}



int main()
{

    nod *pr = nullptr;


    int A; bool meniu = true;

    cout << "====Meniul Programului====" << endl;
    cout << "1.Adauga element la inceput" << endl;
    cout << "2.Adauga element la sfarsit" << endl;
    cout << "3.Adauga dupa o valoarea" << endl;
    cout << "4. Sterge un element" << endl;
    cout << "5. Modifica o valoarea"  << endl;
    cout << "6. Afiseaza lista" << endl;
    cout << "7. Afiseaza lista invers" << endl;
    cout << "8. Iesi din meniu" << endl;

    while (meniu){

    cin >> A;

    switch(A){
    case 1:
        int x1;
        cout << "Introdu valoarea pe care o vrei in nod:" << endl;
        cin >> x1;
        AdaugaInceput(pr,x1);
        break;
    case 2:
        int x2;
        cout << "Introdu valoarea pe care o vrei in nod:" << endl;
        cin >> x2;
        AdaugaFinal(pr,x2);
        break;
    case 3:
        int x3,dupa;
        cout << "Introdu valoarea pe care o vrei in nod:" << endl;
        cin >> x3;
        cout << "Introdu valoarea din lista:" << endl;
        cin >> dupa;
        AdaugaDupaVal(pr,x3,dupa);
        break;
    case 4:
        int x4;
        cout << "Introdu valoarea pe care vrei o sa elimini" << endl;
        cin >> x4;
        StergereElement(pr,x4);
        break;
    case 5:
        int x5,newV;
        cout << "Introdu valoarea pe care vrei o sa modifici" << endl;
        cin >> x5;
        cout << "Introdu noua valoare" << endl;
        cin >> newV;
        ModificaElement(pr,x5,newV);
        break;
    case 6:
        Parcurge(pr);
        break;
    case 7:
        ParcurgeRevere(pr);
        break;
    case 8:
        meniu = false;
        break;
    default:
        cout << "Oops" << endl;
        break;
    }

    }


    return 0;
}
