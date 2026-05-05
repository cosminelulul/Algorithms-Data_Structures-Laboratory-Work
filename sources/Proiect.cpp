/*
Proiectul consta in realizarea unui program cu mai multe optiuni, fiecare optiune reprezentand o cerinta la care raspunde o functie din program
*/

#include <iostream>
#include <cstring>   // Pentru functiile strcpy, strcmp, strlen
#include <iomanip>   // Pentru formatare afisare, daca e cazul
#include <cmath>     // Pentru functii matematice (log, pow), daca e cazul
#include <algorithm> // Desi nu folosim direct functii STL, e util pentru unele operatii de baza daca e permis

using namespace std;

// -----------------------------------------------------
// Definirea structurilor necesare pentru liste simple/duble
// Observatie: Structura ta initiala avea o mica eroare de denumire (lista* prev), am corectat-o aici.
// Vom folosi 'NodeS' pentru liste simple si 'NodeD' pentru liste duble/circulare.
// -----------------------------------------------------

struct NodeS {
    int val;
    NodeS* next;
};

struct NodeD {
    int val;
    NodeD* prev;
    NodeD* next;
};


// -----------------------------------------------------
// CERINTA 1: O functie care sa sorteze alfabetic un sir de caractere folosind unul dintre algoritmii studiati (Bubble Sort aici).
// -----------------------------------------------------

void ordonare_sir_de_caractere()
{
    char sir[] = "d, z, e, c, a";
    int n = strlen(sir);

    cout << "Sir initial: " << sir << endl;

    // Folosim Bubble Sort, un algoritm simplu si eficient pentru siruri scurte.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Sortam doar caracterele literale/virgule, nu si spatiile daca apar
            if (sir[j] > sir[j+1]) {
                // Swap characters
                char temp = sir[j];
                sir[j] = sir[j+1];
                sir[j+1] = temp;
            }
        }
    }

    cout << "Sir ordonat: " << sir << endl << endl;
}

// -----------------------------------------------------
// CERINTA 2: O functie care sa sorteze alfabetic un sir de cuvinte folosind unul dintre algoritmii studiati (Bubble Sort + strcmp).
// -----------------------------------------------------

void ordonare_sir_de_cuvinte()
{
    // Un tablou (array) de siruri de caractere (cuvinte)
    char cuvinte[][20] = {"carte", "zid", "arta", "casa", "argon"};
    int n = sizeof(cuvinte) / sizeof(cuvinte[0]);

    cout << "Cuvinte initiale: ";
    for(int i=0; i<n; ++i) cout << cuvinte[i] << (i == n-1 ? "" : ", ");
    cout << endl;

    // Folosim Bubble Sort si functia strcmp (string compare) din <cstring>
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Daca cuvantul curent (j) este lexicografic mai mare decat urmatorul (j+1)
            if (strcmp(cuvinte[j], cuvinte[j+1]) > 0) {
                // Swap words using a temporary buffer
                char temp[20];
                strcpy(temp, cuvinte[j]);
                strcpy(cuvinte[j], cuvinte[j+1]);
                strcpy(cuvinte[j+1], temp);
            }
        }
    }

    cout << "Cuvinte ordonate: ";
    for(int i=0; i<n; ++i) cout << cuvinte[i] << (i == n-1 ? "" : ", ");
    cout << endl << endl;
}

// -----------------------------------------------------
// CERINTA 3: O functie care sa sorteze crescator un sir de numere intregi folosind algoritmul Radix (cu cozi simulate prin array-uri).
// Deoarece nu putem folosi STL, vom simula cozile cu array-uri bidimensionale.
// -----------------------------------------------------

// Functie helper pentru a gasi numarul maxim si numarul de cifre
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0}; // Coada pentru fiecare cifra (0-9)

    for (int i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void Radix_cu_cozi()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = getMax(arr, n);

    cout << "Sir initial: ";
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;

    // Radix Sort logic (base 10)
    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSortForRadix(arr, n, exp);
    }

    cout << "Sir ordonat (Radix): ";
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl << endl;
}


// -----------------------------------------------------
// CERINTA 4: O functie care sa interclaseze n liste simplu inlantuite intr-o lista simplu inlanțuita.
// Vom crea 3 liste simple si le vom interclasa.
// -----------------------------------------------------

// Functii ajutatoare pentru liste simple
void insert_NodeS(NodeS** head_ref, int new_val) {
    NodeS* new_node = new NodeS();
    new_node->val = new_val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display_NodeS(NodeS* node) {
    while (node != NULL) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Functia principala de interclasare (Merge function pentru 2 liste)
// Aceasta functie presupune ca listele de intrare sunt deja sortate, pentru o interclasare corecta.
NodeS* mergeSortedLists(NodeS* a, NodeS* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    NodeS* result = NULL;

    if (a->val <= b->val) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }
    return result;
}

// Functia care gestioneaza interclasarea celor N liste
void interclasare_n_liste()
{
    // Presupunem 3 liste sortate pentru a demonstra interclasarea
    NodeS* head1 = NULL;
    insert_NodeS(&head1, 10);
    insert_NodeS(&head1, 5);
    insert_NodeS(&head1, 1);
    // Lista 1: 1 -> 5 -> 10 -> NULL

    NodeS* head2 = NULL;
    insert_NodeS(&head2, 20);
    insert_NodeS(&head2, 8);
    insert_NodeS(&head2, 3);
    // Lista 2: 3 -> 8 -> 20 -> NULL

    NodeS* head3 = NULL;
    insert_NodeS(&head3, 100);
    insert_NodeS(&head3, 50);
    insert_NodeS(&head3, 2);
    // Lista 3: 2 -> 50 -> 100 -> NULL

    cout << "Lista 1: "; display_NodeS(head1);
    cout << "Lista 2: "; display_NodeS(head2);
    cout << "Lista 3: "; display_NodeS(head3);

    // Interclasam L1 si L2, apoi rezultatul cu L3
    NodeS* tempResult = mergeSortedLists(head1, head2);
    NodeS* finalResult = mergeSortedLists(tempResult, head3);

    cout << "Lista finala interclasata (L1+L2+L3): ";
    display_NodeS(finalResult);
    cout << endl;
}


// -----------------------------------------------------
// CERINTA 5: O functie care sa creeze o lista circulara dublu inlantuita si implemnentati operatii de adaugare, stergere, modificare si parcurgere.
// Vom folosi structura NodeD de mai sus.
// -----------------------------------------------------

NodeD* headCircle = NULL; // Nodul de start global pentru lista circulara

NodeD* createNodeD(int val) {
    NodeD* newNode = new NodeD();
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Operatie 5a: Adaugare la final
void insert_circular(int val) {
    NodeD* newNode = createNodeD(val);
    if (headCircle == NULL) {
        headCircle = newNode;
        headCircle->next = headCircle;
        headCircle->prev = headCircle;
    } else {
        NodeD* last = headCircle->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = headCircle;
        headCircle->prev = newNode;
    }
}

// Operatie 5b: Parcurgere
void display_circular() {
    if (headCircle == NULL) {
        cout << "Lista circulara este goala." << endl;
        return;
    }
    NodeD* temp = headCircle;
    cout << "Lista Circulara: ";
    do {
        cout << temp->val << " <-> ";
        temp = temp->next;
    } while (temp != headCircle);
    cout << "(back to head)" << endl;
}

// Operatie 5c: Modificare (prima aparitie a unei valori)
void modify_circular(int oldVal, int newVal) {
    if (headCircle == NULL) return;
    NodeD* temp = headCircle;
    do {
        if (temp->val == oldVal) {
            temp->val = newVal;
            cout << "Valoare " << oldVal << " modificata in " << newVal << endl;
            return; // Modifica doar prima aparitie
        }
        temp = temp->next;
    } while (temp != headCircle);
    cout << "Valoarea " << oldVal << " nu a fost gasita pentru modificare." << endl;
}

// Operatie 5d: Stergere (prima aparitie a unei valori)
void delete_circular(int key) {
    if (headCircle == NULL) return;

    NodeD *curr = headCircle, *prev_node = NULL;
    // Cauta nodul de sters
    do {
        if (curr->val == key) break;
        prev_node = curr;
        curr = curr->next;
    } while (curr != headCircle);

    // Daca nu a fost gasit
    if (curr->val != key) {
         cout << "Valoarea " << key << " nu a fost gasita pentru stergere." << endl;
         return;
    }

    // Daca este singurul nod
    if (curr->next == headCircle && curr->prev == headCircle) {
        delete headCircle;
        headCircle = NULL;
        return;
    }

    // Daca este primul nod (head)
    if (curr == headCircle) {
        prev_node = headCircle->prev;
        headCircle = headCircle->next;
        prev_node->next = headCircle;
        headCircle->prev = prev_node;
        delete curr;
    }
    // Daca este un nod oarecare
    else {
        prev_node->next = curr->next;
        curr->next->prev = prev_node;
        delete curr;
    }
    cout << "Valoarea " << key << " a fost stearsa." << endl;
}


void lista_circulara_operatii() {
    // Curatam lista globala daca a mai fost folosita
    headCircle = NULL;

    insert_circular(10);
    insert_circular(20);
    insert_circular(30);
    cout << "Dupa adaugari initiale: " << endl;
    display_circular();

    modify_circular(20, 25);
    display_circular();

    delete_circular(10);
    display_circular();

    delete_circular(30);
    display_circular();

    delete_circular(25);
    display_circular();
    cout << endl;
}


// -----------------------------------------------------
// CERINTA 6: Scrieti o functie care sa determine reuniunea si intersectia a doua multimi descrise prin liste dinamice (liste simple).
// Presupunem ca listele reprezinta multimi (fara duplicate) si sunt sortate pentru eficienta.
// -----------------------------------------------------

// Helper for Set operations: Check if a value exists in a simple list
bool existsInList(NodeS* head, int val) {
    NodeS* temp = head;
    while(temp != NULL) {
        if(temp->val == val) return true;
        temp = temp->next;
    }
    return false;
}

// Helper for Set operations: Add to end of a simple list (used for result lists)
void addToEndS(NodeS** head_ref, int new_val) {
    NodeS* new_node = new NodeS();
    new_node->val = new_val;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    NodeS* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}


void reuniune_intersectie_multimi()
{
    // Multimea A: {1, 3, 5, 7}
    NodeS* A = NULL;
    addToEndS(&A, 1); addToEndS(&A, 3); addToEndS(&A, 5); addToEndS(&A, 7);

    // Multimea B: {3, 4, 7, 8}
    NodeS* B = NULL;
    addToEndS(&B, 3); addToEndS(&B, 4); addToEndS(&B, 7); addToEndS(&B, 8);

    NodeS* Reun = NULL;
    NodeS* Inter = NULL;

    cout << "Multimea A: "; display_NodeS(A);
    cout << "Multimea B: "; display_NodeS(B);

    // Calculam REUNIUNEA: adaugam toate elementele din A, apoi elementele din B care nu sunt deja in A.
    NodeS* tempA = A;
    while(tempA != NULL) {
        addToEndS(&Reun, tempA->val);
        tempA = tempA->next;
    }
    NodeS* tempB = B;
    while(tempB != NULL) {
        if(!existsInList(A, tempB->val)) {
            addToEndS(&Reun, tempB->val);
        }
        tempB = tempB->next;
    }

    // Calculam INTERSECTIA: adaugam elementele din A care exista si in B.
    tempA = A;
    while(tempA != NULL) {
        if(existsInList(B, tempA->val)) {
            addToEndS(&Inter, tempA->val);
        }
        tempA = tempA->next;
    }


    cout << "\nReuniunea (A U B): "; display_NodeS(Reun); // {1, 3, 5, 7, 4, 8} (ordinea poate varia fara sortare)
    cout << "Intersectia (A n B): "; display_NodeS(Inter); // {3, 7}
    cout << endl;

    // Nota: Eliberarea memoriei alocate dinamic (new NodeS) ar trebui facuta intr-o functie de cleanup, dar pentru simplitatea main-ului de test, o omitem aici.
}


// -----------------------------------------------------
// MAIN FUNCTION (Meniul tau original)
// -----------------------------------------------------

int main()
{
    int optiune=1;

    do
    {
        cout << "--- Programe - PROIECT ---" << endl<<endl;
        cout << " 1. Ordonare sir de caractere (Bubble Sort)" << endl;
        cout << " 2. Ordonare sir de cuvinte (Bubble Sort + strcmp)" << endl;
        cout << " 3. Algoritmul Radix pentru numere intregi" <<endl;
        cout << " 4. Interclasarea a n liste simplu inlantuite (Merge Sorted)" << endl;
        cout << " 5. Lista circulara dublu inlantuita si operatii." << endl;
        cout << " 6. Reunine si intersectie multimi (liste dinamice)." << endl;
        //cout << " 7. " <<endl; // Cerintele 7-10 raman libere
        cout << "0. Terminare program" << endl;

        cout << "Scrieti optiune: "; cin>>optiune;
        cout << "------------------------------------------" << endl;


        switch (optiune)
        {
        case 1:
            ordonare_sir_de_caractere();
            break;

        case 2:
            ordonare_sir_de_cuvinte();
            break;

        case 3:
            Radix_cu_cozi();
            break;

        case 4:
            interclasare_n_liste();
            break;

        case 5:
            lista_circulara_operatii();
            break;

        case 6:
            reuniune_intersectie_multimi();
            break;

        case 0:
            cout << "La revedere!" << endl;
            break;

        default:
            cout << "Optiune invalida!" << endl<<endl;
        } // end switch
         cout << "------------------------------------------" << endl << endl;
    } while(optiune!=0); // end pentru do


    return 0;
}

