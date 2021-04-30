#include <iostream>
#include <cstring>
#include "mystring.h"
using namespace std;
int main()
{
    MyString ms1;
    MyString ms2("leonardo dicapeio");
    MyString ms3 = ms2;
    cout << ms2;
    MyString ms4;
    ms4 = ms2;
    cout << ms4;
    cout << "the numbers of objects we have:\n"
         << MyString::howMany() << endl;
    MyString ms5 = "fuck off";
    cout << ms5;
    cout << ms5[5] << endl;
    if (ms1 > ms5)
        cout << "YES!!!" << endl;
    else
        cout << "NO!!!!" << endl;
    return 0;
}