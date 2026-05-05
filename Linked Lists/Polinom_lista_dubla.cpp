#include <iostream>
using namespace std;

struct Pol {
    int coef, pow;
    Pol *urm, *prev;
};


void stergeNod(Pol* &prim, Pol* nod) {
    if (!nod) return;

    if (nod->prev)
        nod->prev->urm = nod->urm;
     else
        prim = nod->urm;


    if (nod->urm)
        nod->urm->prev = nod->prev;


    delete nod;
}

void inserarePol(Pol* &prim, int coef, int powy) {
    if (coef == 0) return;

    Pol* nou = new Pol;
    nou->coef = coef;
    nou->pow = powy;
    nou->urm = NULL;
    nou->prev = NULL;

    if (!prim || powy > prim->pow) {

        nou->urm = prim;
        if (prim)
            prim->prev = nou;

        prim = nou;
        return;
    }

    Pol* p = prim;
    while (p->urm && p->urm->pow > powy)
        p = p->urm;


    if (p->urm && p->urm->pow == powy) {
        p->urm->coef += coef;
        if (p->urm->coef == 0)
            stergeNod(prim, p->urm);
        delete nou;
        return;
    }

    nou->urm = p->urm;
    nou->prev = p;

    if (p->urm)
        p->urm->prev = nou;

    p->urm = nou;
}

void afisare(Pol* L) {
    if (!L) {
        cout << "0" << endl;
        return;
    }

    while (L) {
        cout << L->coef << "x^" << L->pow;
        if (L->urm) cout << " + ";
        L = L->urm;
    }
    cout << endl;
}

Pol* adunare(Pol* L1, Pol* L2) {
    Pol* R = NULL;

    while (L1 && L2) {
        if (L1->pow > L2->pow) {
            inserarePol(R, L1->coef, L1->pow);
            L1 = L1->urm;
        }
        else if (L2->pow > L1->pow) {
            inserarePol(R, L2->coef, L2->pow);
            L2 = L2->urm;
        }
        else {
            inserarePol(R, L1->coef + L2->coef, L1->pow);
            L1 = L1->urm;
            L2 = L2->urm;
        }
    }

    while (L1) {
        inserarePol(R, L1->coef, L1->pow);
        L1 = L1->urm;
    }

    while (L2) {
        inserarePol(R, L2->coef, L2->pow);
        L2 = L2->urm;
    }

    return R;
}

Pol* inmultire(Pol* L1, Pol* L2) {
    Pol* R = NULL;
    Pol* p1 = L1;

    while (p1) {
        Pol* p2 = L2;
        while (p2) {
            int coef_nou = p1->coef * p2->coef;
            int pow_nou = p1->pow + p2->pow;
            inserarePol(R, coef_nou, pow_nou);
            p2 = p2->urm;
        }
        p1 = p1->urm;
    }
    return R;
}

int main() {
    Pol *P1 = NULL, *P2 = NULL;
    int opt, c, p;
    bool menu = true;

    cout << "======= MENIU POLINOAME =======" << endl;
    cout << "1. Adauga termen in P1" << endl;
    cout << "2. Adauga termen in P2" << endl;
    cout << "3. Afiseaza P1" << endl;
    cout << "4. Afiseaza P2" << endl;
    cout << "5. Afiseaza P1 + P2" << endl;
    cout << "6. Afiseaza P1 * P2" << endl;
    cout << "0. Iesire" << endl;


    while (menu){

        cout << "Introduce optiunea:" << endl;
        cin >> opt;

        switch(opt){
            case 1:
                cout << "Coeficient si powere: ";
                cin >> c >> p;
                inserarePol(P1, c, p);
                break;
            case 2:
                cout << "Coeficient si powere: ";
                cin >> c >> p;
                inserarePol(P2, c, p);
                break;
            case 3:
                cout << "P1 = ";
                afisare(P1);
                break;
            case 4:
                cout << "P2 = ";
                afisare(P2);
                break;
            case 5:
                cout << "P1 + P2 = ";
                afisare(adunare(P1, P2));
                break;
            case 6:
                cout << "P1 * P2 = ";
                afisare(inmultire(P1, P2));
                break;
            case 0:
                menu = false;
                break;
            default:
                cout << "Comanda invalida";
                break;
        }
    }

    return 0;
}
