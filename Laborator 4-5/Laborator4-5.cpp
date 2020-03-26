#include "Cheltuiala.h"
#include "Repository.h"
#include "Service.h"
#include "Test.h"
#include <iostream>
#include <string>
#include <string.h>

void meniu()
//afiseaza meniul de optiuni
{
    cout << "1.Adaugare cheltuiala" << endl;
    cout << "2.Stergere cheltuiala" << endl;
    cout << "3.Update cheltuiala" << endl;
    cout << "4.Afisare cheltuieli" << endl;
    cout << "5.Inchidere" << endl;
    cout << "------------------------" << endl;
    cout << "Alegeti o operatie: " << endl;
}

/*void tests()
{
    test_adaugare();
    test_entitate();
    test_gasire();
    test_stergere();
}*/

void to_add(Service& serv)
{
    int z, s;
    char t[15];
    cout << "Dati ziua:";
    cin >> z;
    cout << "Dati suma:";
    cin >>s;
    cout << "Dati tipul:";
    cin >> t;
    Cheltuiala c(z, s, t);
    serv.addElem(c);
}

void to_show(Service& s)
{
    vector<Cheltuiala> cheltuieli = s.getAll();
    for (Cheltuiala c : cheltuieli)
        cout << c;
}

void to_delete(Service& s)
{
    vector<Cheltuiala> elem = s.getAll();
    int poz = 0; 
    cout << "Dati pozitia de pe care se va sterge elementul: ";
    cin >> poz;
    cout << endl;
    s.deleteElem(elem[poz - 1]);
}

void to_update(Service& s)
{
    vector<Cheltuiala> elem = s.getAll();
    int poz = 0;
    cout << "Dati pozitia de pe care se va face update: ";
    cin >> poz;
    s.updateElem(elem[poz - 1]);

}

int main()
{
    Service serv;
    int op;
    bool sem = true;
    while (sem)
    {
        meniu();
        cin >> op;
        if (op == 1)
        {
            to_add(serv);
            continue;
        }
        if (op == 2)
        {
            to_delete(serv);
            to_show(serv);
            continue;
        }
        if (op == 3)
        {
            to_update(serv);
            to_show(serv);
            continue;
        }
        if (op == 4)
        {
            to_show(serv);
        }
        if (op == 5)
        {
            sem = false;
        }
    }  
    return 0;
}