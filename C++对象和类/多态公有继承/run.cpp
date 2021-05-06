#include "bank.h"
#include <string>
#include <iostream>
using namespace std;
const int MAX = 4;
int main()
{
    Brass *p[MAX];
    string temp;
    string tempacc;
    double tempba;
    char kind;

    for (int i = 0; i < MAX; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempacc;
        cout << "Enter opening balance: ";
        cin >> tempba;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        //出错诊断
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        if (kind == '1')
        {
            p[i] = new Brass(temp, tempacc, tempba);
        }
        else
        {
            double tmax, trate;
            cout << "enter the loan limit: ";
            cin >> tmax;
            cout << "enter the rate: ";
            cin >> trate;
            p[i] = new BrassPlus(temp, tempacc, tempba, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }

    cout << endl;
    
    for (int i = 0; i < MAX; i++)
    {
        p[i]->viewAcct();
        cout << endl;
    }
    for (int i = 0; i < MAX; i++)
    {
        delete p[i];
    }
    cout << "Done!!!!\n"
         << endl;
    return 0;
}