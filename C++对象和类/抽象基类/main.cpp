#include "bank2.h"
#include <string>
#include <iostream> 
using namespace std;
const int MAX = 4;
int main()
{
    //从抽象基类定义出来的指针
    AcctABC *p[MAX];
    string temp_name;
    string temp_ID;
    double temp_balance;
    char kind;
    int i;
    for (i = 0; i < MAX; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp_name);
        cout << "Enter client's ID: ";
        cin >> temp_ID;
        cout << "Enter client's balance: ";
        cin >> temp_balance;
        cin >> kind;
        cout << "Enter the kind you want to create." << endl;
        cout << "1 for Brass and 2 for BrassPlus:";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter 1 or 2!!!" << endl;
        if (kind == '1')
            p[i] = new Brass(temp_name, temp_ID, temp_balance);
        else
        {
            double temp_max, temp_rate;
            cout << "Enter the maxloan:";
            cin >> temp_max;
            cout << "Enter the rate:";
            cin >> temp_rate;
            p[i] = new BrassPlus(temp_name, temp_ID, temp_balance, temp_max, temp_rate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (i = 0; i < MAX; i++)
    {
        p[i]->showIofo();
        cout << endl;
    }

    for (i = 0; i < MAX; i++)
    {
        delete p[i];
    }
    cout << "----------DONE!----------" << endl;
    return 0;
}