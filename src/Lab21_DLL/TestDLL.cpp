#include <iostream>
#include "DLL.h"
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char oper;

    do
    {
        cout << "1. ������������ ����" << endl;
        cout << "2. ������ � ������" << endl;
        cout << "3. �����" << endl << endl;
        cout << "�������� �������: ";

        cin >> oper;
        console_clear();
        switch (oper)
        {
        case 1:
            form_file();
            break;
        case 2:
            work_file();
            break;
        default:
            break;
        }

    } while (oper != 3);
}