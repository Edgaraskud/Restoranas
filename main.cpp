// Restorano mini apskaitos sistema

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct menuItemType
{
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menu[], int &count)
{
    ifstream fin("menu.txt");

    count = 0;

    while(getline(fin, menu[count].menuItem, ';'))
    {
        fin >> menu[count].menuPrice;
        fin.ignore();
        count++;
    }

    fin.close();
}

void showMenu(menuItemType menu[], int count)
{
    cout << "\n--- MENIU ---\n";

    for(int i = 0; i < count; i++)
    {
        cout << i + 1 << ". "
             << menu[i].menuItem
             << " - "
             << menu[i].menuPrice
             << " EUR" << endl;
    }
}

void printCheck(double suma)
{
    double pvm = suma * 0.21;
    double galutine = suma + pvm;

    cout << fixed << setprecision(2);

    cout << "\nPVM: " << pvm << " EUR" << endl;
    cout << "Galutine suma: " << galutine << " EUR" << endl;

    ofstream fout("receipt.txt");

    fout << fixed << setprecision(2);
    fout << "PVM: " << pvm << " EUR" << endl;
    fout << "Galutine suma: " << galutine << " EUR" << endl;

    fout.close();
}

int main()
{
    menuItemType menu[20];
    int count;

    getData(menu, count);

    showMenu(menu, count);

    double suma = 0;
    int pasirinkimas;
    int kiekis;

    cout << "\n0 - baigti uzsakyma\n";

    while(true)
    {
        cout << "\nPasirinkimas: ";
        cin >> pasirinkimas;

        if(pasirinkimas == 0)
            break;

        cout << "Kiekis: ";
        cin >> kiekis;

        suma += menu[pasirinkimas - 1].menuPrice * kiekis;
    }

    printCheck(suma);

    return 0;
}