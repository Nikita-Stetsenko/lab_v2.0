#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "file.dat"
#include "pch.h"
#include"DLL.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;

auto PoultryFarm::create()
{
    cout << "Название: ";
    char name[50];
    cin >> name;

    cout << "Количество: ";
    int number;
    cin >> number;

    cout << "Окрас: ";
    char colour[50];
    cin >> colour;

    cout << "Возраст: ";
    int age;
    cin >> age;

    cout << "Семейство: ";
    char kind[50];
    cin >> kind;

    console_clear();

    PoultryFarm p;
    strcpy(p.kind, kind);
    strcpy(p.colour, colour);
    strcpy(p.name, name);
    p.number = number;
    p.age = age;

    return p;
}

void PoultryFarm::add_PoultryFarm(PoultryFarm t, int pos)
{
    if (pos < 1)
        cout << "\nНЕКОРРЕКТНЫЙ НОМЕР" << endl;
    else
    {
        FILE* file = fopen("file.dat", "rb");
        FILE* tempfile = fopen("temp.dat", "wb");
        PoultryFarm p;
        int index = 0;

        while (fread(&p, sizeof(PoultryFarm), 1, file))
        {
            fwrite(&p, sizeof(PoultryFarm), 1, tempfile);
            index++;

            if (index == pos)
                fwrite(&t, sizeof(PoultryFarm), 1, tempfile);
        }

        fclose(file);
        fclose(tempfile);

        remove("file.dat");
        rename("temp.dat", "file.dat");

        if (index < pos)
            cout << "\nНЕКОРРЕКТНЫЙ НОМЕР" << endl;
    }
}

void PoultryFarm::form_file()
{
    cout << "Количество элементов: ";
    int count;
    cin >> count;

    FILE* file = fopen("file.dat", "wb");
    if (file == NULL)
        exit(1);

    for (int i = 0; i < count; i++)
    {
        PoultryFarm p = create();

        fwrite(&p, sizeof(PoultryFarm), 1, file);

        if (ferror(file))
            exit(2);
    }

    fclose(file);
}

void PoultryFarm::read_file()
{
    FILE* file = fopen("file.dat", "rb");
    PoultryFarm p;
    cout << "Название" << setw(15) << "Семейство" << setw(30) << "Возраст" << setw(20) << "Количество" << setw(20) << "Окрас" << endl << endl;

    while (fread(&p, sizeof(PoultryFarm), 1, file))
    {
        cout << p.name << setw(17) << p.kind << setw(27) << p.age << setw(19) << p.number << setw(24) << p.colour << endl;
    }

    fclose(file);
}

int PoultryFarm::clear_file(const char* filename)
{
    FILE* f = NULL;

    if (fopen_s(&f, filename, "wb") != 0)
        return -1;

    fclose(f);
    return 0;
}

void PoultryFarm::delete_from_file(int startAge, int endAge, char* name)
{
    FILE* file = fopen("file.dat", "rb");
    FILE* tempfile = fopen("temp.dat", "wb");
    PoultryFarm p;

    bool value = false;

    while (fread(&p, sizeof(PoultryFarm), 1, file))
    {
        if (!((p.age >= startAge && p.age <= endAge) && (strcmp(p.name, name) == 0)))
        {
            fwrite(&p, sizeof(PoultryFarm), 1, tempfile);
            value = true;
        }
    }

    fclose(file);
    fclose(tempfile);

    if (value)
    {
        remove("file.dat");
        rename("temp.dat", "file.dat");
    }
}

void PoultryFarm::work_file()
{
    int oper;
    int oper;
    do
    {
        cout << "1. Просмотр файла" << endl;
        cout << "2. Удаление из файла" << endl;
        cout << "3. Добавление в файл" << endl;
        cout << "4. Очистить файл" << endl;
        cout << "0. Назад" << endl << endl;
        cout << "Выберите вариант: ";

        cin >> oper;
        console_clear();
        switch (oper)
        {
        case 1:
            read_file();
            break;
        case 2:
        {
            cout << "Название: ";
            char str[30];
            cin >> str;

            int start;
            cout << "Возраст: ";
            cin >> start;
            int end = start;

            delete_from_file(start, end, str);
            console_clear();
            break;
        }
        case 3:
        {
            int pos;
            cout << "После какого элемента добавить? -> ";
            cin >> pos;

            PoultryFarm p = create();
            add_PoultryFarm(p, pos);
            break;
        }
        case 4:
        {
            cout << "Вы точно хотите очистить список? (+ / ANYKEY)\t";
            if (_getch() == '+')
                cout << "Файл очищен\n", clear_file(FILENAME) == 0 ? "" : "НЕ";
            else
                cout << "\nОтмена";

            cout << "\nANYKEY TO CONTINUE ";
            _getch();
            console_clear();
            break;
        }
        }
    } while (oper != 0);
}

void PoultryFarm::console_clear()
{
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ',
        dwConSize, coordScreen, &cCharsWritten))
        return;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;

    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
        dwConSize, coordScreen, &cCharsWritten))
        return;

    SetConsoleCursorPosition(hConsole, coordScreen);
}