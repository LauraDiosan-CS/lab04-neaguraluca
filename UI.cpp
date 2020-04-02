#include "UI.h"
#include <iostream>
using namespace std;

UI::UI()
{
    this->serv;
}

void UI::meniu()
//afiseaza meniul de optiuni
{
    cout << "1.Adaugare cheltuiala" << endl;
    cout << "2.Stergere cheltuiala" << endl;
    cout << "3.Update cheltuiala" << endl;
    cout << "4.Afisare cheltuieli" << endl;
    cout << "5.Afisarea cheltuielilor dintr-o anumita zi" << endl;
    cout << "6.Suma cheltuielilor in functie de tip" << endl;
    cout << "7.Afisarea cheltuielilor cu suma mai mare decat o suma citita" << endl;
    cout << "8.Sortarea cheltuielilor dupa suma" << endl;
    cout << "9.Undo" << endl;
    cout << "10.Inchidere" << endl;
    cout << "------------------------" << endl;
    cout << "Alegeti o operatie: " << endl;
}

void UI::toAdd(Service& serv)
{
    int z, s, d;
    char t[15];
    cout << "Dati id-ul: ";
    cin >> d;
    cout << "Dati ziua:";
    cin >> z;
    cout << "Dati suma:";
    cin >> s;
    cout << "Dati tipul:";
    cin >> t;
    Cheltuiala c(d, z, s, t);
    serv.addElem(c);
}

void UI::toShow(Service& serv)
{
    vector<Cheltuiala> cheltuieli = serv.getAll();
    for (Cheltuiala c : cheltuieli)
        cout << c;
}

void UI::toDelete(Service& serv)
{
    vector<Cheltuiala> elem = serv.getAll();
    int d;
    Cheltuiala c;
    cout << "Dati id-ul de pe care se va sterge elementul: ";
    cin >> d;
    cout << endl;
    serv.delById(c, d);
}

void UI::toUpdate(Service& serv)
{
    vector<Cheltuiala> elem = serv.getAll();
    //int poz = 0;
    int z, suma, d;
    char t[15];
    cout << "Dati id-ul de la care se va face update: ";
    cin >> d;
    cout << "Dati noua zi: ";
    cin >> z;
    cout << "Dati noua suma: ";
    cin >> suma;
    cout << "Dati noul tip: ";
    cin >> t;
    Cheltuiala c = serv.getById(d);
    serv.updateElem(c, z, suma, t);
}

void UI::toPopulate(Service& serv)
{
    serv.populate();
}

void UI::fromADay(Service& serv)
{
    cout << "Dati ziua din care doriti afisarea cheltuielilor: ";
    int z;
    cin >> z;
    vector<Cheltuiala> ok = serv.fromADay(z);
    for (Cheltuiala c : ok)
        cout << c;
        
}

void UI::sumByTip(Service& serv)
{
    char t[20];
    cout << "Dati tipul pentru care se va face suma: ";
    cin >> t;
    int suma = serv.sumByTip(t);
    cout << "Suma pentru " << t << " este " << suma;
}

void UI::greaterSum(Service& serv)
{
    int suma;
    cout << "Dati suma limita: ";
    cin >> suma;
    vector<Cheltuiala> chelt = serv.greaterThan(suma);
    for (Cheltuiala c : chelt)
        cout << c;

}

void UI::sortCheltuieli(Service& s)
{

    vector<Cheltuiala> chelt = s.sortCheltuieli();
    for (Cheltuiala c : chelt)
        cout << c;
}


void UI::showUI(Service& serv)
{
    toPopulate(serv);
    bool sem = true;
    while (sem)
    {
        meniu();
        int op;
        cin >> op;
        if (op == 1)
        {
            toAdd(serv);
            cout << "Adaugare efectuata! "<< endl;
            cout << endl;
            continue;
        }
        if (op == 2)
        {
            toDelete(serv);
            cout << "Stergere efectuata! " << endl;
            cout << endl;
            continue;
        }
        if (op == 3)
        {
            toUpdate(serv);
            cout << "Modificare efectuata! " << endl;
            cout << endl;
            continue;
        }
        if (op == 4)
        {
            toShow(serv);
            cout << endl;
            continue;
        }
        if (op == 5)
        {
            fromADay(serv);
            cout << endl;
            continue;
        }
        if (op == 6)
        {
            sumByTip(serv);
            cout << endl;
            continue;
        }
        if (op == 7)
        {
            greaterSum(serv);
            cout << endl;
            continue;
        }
        if (op == 8)
        {
            sortCheltuieli(serv);
            cout << endl;
            continue;
        }
        if (op == 9)
        {
            serv.undo_operation();
            cout << "Undo efectuat! " << endl;
            continue;
        }
        if (op == 10)
            sem=false; 
    }
}


void tests()
{
    testAdaugare();
    testEntitate();
    testGasire();
    testStergere();
    testSortare();
    testGasireZi();
    testSumaTip();
    testSumaMaiMare();
}



UI::~UI(){}

