#include <iostream>
#include <forward_list>
#include<climits>
#include <windows.h>
#include <cstring>
#include <iomanip>

using namespace std;

struct PoultryFarm
{
    char number;
    char name[70];
    char colour[70];
    char age;
};

forward_list<PoultryFarm> PoultryFarmList;
PoultryFarm f;

void GetData(forward_list<PoultryFarm>& v)
{

    cout << "\n";
    cout << "Название птицы: ";
    cin >> f.name;
    cout << "Количество: ";
    cin >> f.number;
    cout << "Окрас: ";
    cin >> f.colour;
    cout << "Средний возраст: ";
    cin >> f.age;

    v.push_front(f);

}

void ShowData(const forward_list<PoultryFarm>& v)
{
    cout << "\n";
    cout << "Список птиц\n";
    cout << '\n';

    cout << setw(20) << "Назвавние птицы" << '|';
    cout << setw(16) << "Количество" << '|';
    cout << setw(16) << "Окрас" << '|';
    cout << setw(18) << "Средний возраст" << '|';

    cout << '\n';

    for (const auto& f : v)
    {
        cout << setw(20) << f.name << '|';
        cout << setw(16) << f.number << '|';
        cout << setw(14) << f.colour << '|';
        cout << setw(18) << f.age << '|';
        cout << endl;
    }
    cout << '\n';
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (true) {

        int change;
        cout << "Выберите вариант\n" << endl;
        cout << "1. Добавить элемент в начало списка\n"
            << "2. Удалить элемент из начала списка\n"
            << "3. Вывести элементы списка\n" << endl;
        cout << "Введите свой вариант: ";
        cin >> change;

        switch (change) {
        case 1:
        {
            GetData(PoultryFarmList);
            break;
        }
        case 2:
        {
            PoultryFarmList.pop_front();
            cout << "Элемент удален..." << endl;
            break;
        }

        case 3:
        {
            ShowData(PoultryFarmList);
            break;
        }

        }
    }
    return 0;
}