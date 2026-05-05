#include <iostream>

using namespace std;

struct Muchie{
    int x, y;
};

istream& operator>>(istream& is, Muchie& m) {
    is >> m.x >> m.y;
    return is;
}

struct nod{
    int val;
    nod* urm;
};

void Adauga(nod *&n, int v){
    nod *nou = new nod;
    nou->val = v;
    nou->urm = n;
    n = nou;
}

void AfiseazaVecini(nod* Graf[], int n){
    cout << endl << "--- Afisarea Grafului ---" << endl;

    for(int i = 1; i <= n; ++i){

        cout << "Nodul " << i << ": ";
        nod* temp = Graf[i];
        if (temp == nullptr) {
            cout << "NULL";
        }
        while(temp != nullptr){
            cout << temp->val << " , ";
            temp = temp->urm;
        }
        cout << "0" << endl;
    }
    cout << "----------------------------------" << endl;
}

void AfiseazaMatrAdic(int Matr[][101], int n) {
    cout << endl << "--- Afisarea Matricei de Adiacenta ---" << endl;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << Matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

void AfiseazaListaMuchii(Muchie M[], int nrMuchii) {
    cout << endl << "--- Afisarea Listei de Muchii ---" << endl;

    for (int i = 0; i < nrMuchii; ++i) {
        cout << "(" << M[i].x << ", " << M[i].y << ")" << endl;
    }
    cout << "Numar total de muchii: " << nrMuchii << endl;
    cout << "----------------------------------" << endl;
}

void ZeroifyMatrix(int Matrx[][101], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            Matrx[i][j] = 0;
        }
    }
}

void ZeroifyMuchie(Muchie M[], int n) {
    for (int i = 0; i < n; ++i) {
        M[i].x = 0;
        M[i].y = 0;
    }
}

void StergeGraf(nod* Graf[], int& n) {

    for (int i = 1; i <= n; ++i) {

        nod* current = Graf[i];

        while (current != nullptr) {
            nod* next = current->urm;
            delete current;
            current = next;
        }
        Graf[i] = nullptr;
    }
    n = 0;
    cout << "Graful a fost sters cu succes!";

}

int returDinlistaAdiancentaGraf(nod* Graf[], int Matr[][101], Muchie M[], int n) {
    int contorMuchii = 0;

    for (int i = 1; i <= n; i++){
        nod* temp = Graf[i];
        while (temp != nullptr){
            Matr[i][temp->val] = 1;
            if ( i< temp->val ) 
                M[contorMuchii++] = {i, temp->val};
            temp = temp->urm;
        }

    }

    return contorMuchii;
}

int returDinMatriceAdiacentaGraf(int Matr[][101], nod* Graf[], Muchie M[], int n) {
    int contorMuchii = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (Matr[i][j] == 1) {
                Adauga(Graf[i], j);
                Adauga(Graf[j], i);
                if (i < j) {
                    M[contorMuchii++] = {i, j};
                }
            }
        }
    }

    return contorMuchii;
}


int main(){
    nod* Graf[101] = {nullptr};
    int Adiac[101][101] = {};
    Muchie M[1000];
    int n = 0;
    int A; bool meniu = true;

    cout << "====Meniul Programului====" << endl;
    cout << "1.Citeste lista de adiacenta" << endl;
    cout << "2.Citeste lista de muchii" << endl;
    cout << "3.Citeste matricea de adiacenta" << endl;
    cout << "5. Sterge Graf" << endl;
    cout << "0. Iesire"  << endl;

    while (meniu){

    cin >> A;

    switch(A){
        case 1:{
            cout << "Citeste nr de noduri: "; cin >> n;

            cout << "Pentru fiecare nod (1 la n), introduceti toti vecinii, terminati cu 0" << endl;
            for(int i = 1; i <= n; ++i){
                int vecin;
                cout << "Vecinii nodului " << i << ": ";
                while(cin >> vecin && vecin != 0)
                    Adauga(Graf[i], vecin);
            }
            cout << "=============================================" << endl;

            int NrMuchii1  = returDinlistaAdiancentaGraf(Graf, Adiac, M, n);

            AfiseazaListaMuchii(M, NrMuchii1);
            AfiseazaMatrAdic(Adiac, n);

            cout << "=============================================" << endl;
            break;
        }
        case 2:{

            int m;
            cout << "Citeste nr de noduri: "; cin >> n;
            cout << "Citeste nr de muchii: "; cin >> m;

            cout << "Introduceti cele " << m << " muchii (x y):\n";
            for(int i = 0; i < m; ++i){

                Muchie tempMuchie;
                cin >> tempMuchie;

                Adauga(Graf[tempMuchie.x], tempMuchie.y);
                Adauga(Graf[tempMuchie.y], tempMuchie.x);
            }
            cout << "=============================================" << endl;

            for (int i = 0; i < m; i++)
                Adiac[M[i].x][M[i].y] = Adiac[M[i].y][M[i].x] = 1;
            
            AfiseazaMatrAdic(Adiac, n);
            AfiseazaVecini(Graf, n);


            cout << "=============================================" << endl;
            break;
        }
        case 3:{

            cout << "Citeste nr de noduri: "; cin >> n;

            cout << "Introduceti matricea de adiacenta (" << n << "x" << n << ")" << endl;;
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    int adiacent; cin >> adiacent;
                    if(adiacent == 1) Adauga(Graf[i], j);
                    }
                }
            cout << "=============================================" << endl;

            int nrMuchii3 = returDinMatriceAdiacentaGraf(Adiac, Graf, M, n);
            AfiseazaVecini(Graf, n);
            AfiseazaListaMuchii(M, nrMuchii3);

            cout << "=============================================" << endl;
            break;
        }
        case 5:{
            if (n != 0) {
                StergeGraf(Graf, n);
                ZeroifyMatrix(Adiac, n);
                ZeroifyMuchie(M, 1000);
            
            }
            break;
        }
        case 0:{
            meniu = false;
            break;
        }
        default:{
                cout << "Oops" << endl;
                break;
            }
        }

    }

    return 0;
}
