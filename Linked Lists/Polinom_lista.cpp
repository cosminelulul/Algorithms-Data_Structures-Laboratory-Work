#include <iostream>
using namespace std;

struct Pol {
    int coef, pow;
    Pol* urm;
};

void inserarePol(Pol* &prim, int coef, int powy) {
    if (coef == 0) return;

    Pol* nou = new Pol;
    nou->coef = coef;
    nou->pow = powy;
    nou->urm = NULL;

    if (!prim || powy > prim->pow) {
        nou->urm = prim;
        prim = nou;
        return;
    }

    Pol* p = prim;

    while (p->urm && p->urm->pow > powy)
        p = p->urm;

    if (p->urm && p->urm->pow == powy) {
        p->urm->coef += coef;
        if (p->urm->coef == 0) {
            Pol* t = p->urm;
            p->urm = t->urm;
            delete t;
        }
        delete nou;
        return;
    }

    if (prim->pow == powy) {
        prim->coef += coef;
        if (prim->coef == 0) {
            Pol* t = prim;
            prim = prim->urm;
            delete t;
        }
        delete nou;
        return;
    }

    nou->urm = p->urm;
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

Pol* adunare(Pol* P1, Pol* P2) {
    Pol* R = NULL;

    while (P1 && P2) {
        if (P1->pow > P2->pow) {
            inserarePol(R, P1->coef, P1->pow);
            P1 = P1->urm;
        }
        else if (P2->pow > P1->pow) {
            inserarePol(R, P2->coef, P2->pow);
            P2 = P2->urm;
        }
        else {
            inserarePol(R, P1->coef + P2->coef, P1->pow);
            P1 = P1->urm;
            P2 = P2->urm;
        }
    }

    while (P1) {
        inserarePol(R, P1->coef, P1->pow);
        P1 = P1->urm;
    }

    while (P2) {
        inserarePol(R, P2->coef, P2->pow);
        P2 = P2->urm;
    }

    return R;
}

Pol* inmultire(Pol* P1, Pol* P2){
    Pol *R = NULL;
    Pol* temp1 = P1;

    while (temp1){

        Pol* temp2 = P2;
        while (temp2){
            int coef_nou = temp1->coef * temp2->coef;
            int pow_nou = temp1->pow + temp2->pow;

            inserarePol(R,coef_nou,pow_nou);
            temp2 = temp2->urm;
        }
        temp1 = temp1->urm;
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
                afisare(adunare(P1, P2));
                break;
            case 6:
                afisare(inmultire(P1,P2));
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
