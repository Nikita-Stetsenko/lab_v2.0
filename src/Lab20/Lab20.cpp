#define FILENAME "file.dat"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <regex>
using namespace std;

struct PoultryFarm
{
    char name[50];
    int number;
    char colour[50];
    char kind[50];
    int age;
};

void console_clear();
void form_file();
void read_file();
void work_file();
void delete_from_file(int startAge, int endAge, char* name);
int clear_file(const char* filename);
PoultryFarm create();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int oper;
    clock_t start = clock();
    do
    {
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        cout << "\n������� ����� � ����: " << asctime(timeinfo) << endl << endl;
        cout << "\n������� main\n";

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
    clock_t end = clock();
    cout << ("\n����� ������ ���������: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
}

PoultryFarm create()
{
    cout << "\n������� create";

    cout << "��������: ";
    char name[50];
    cin >> name;

    cout << "����������: ";
    int number;
    cin >> number;

    cout << "�����: ";
    char colour[50];
    cin >> colour;

    cout << "�������: ";
    int age;
    cin >> age;

    cout << "���������: ";
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

void form_file()
{
    cout << "\n������� form_file\n";
    cout << "���������� ���������: ";
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

void read_file()
{
    FILE* file = fopen("file.dat", "rb");
    PoultryFarm p;
    cout << "\n������� read_file\n";
    cout << "��������" << setw(15) << "���������" << setw(30) << "�������" << setw(20) << "����������" << setw(20) << "�����" << endl << endl;

    while (fread(&p, sizeof(PoultryFarm), 1, file))
    {
        cout << p.name << setw(17) << p.kind << setw(27) << p.age << setw(19) << p.number << setw(24) << p.colour << endl;
    }

    fclose(file);
}

int clear_file(const char* filename)
{
    FILE* f = NULL;

    if (fopen_s(&f, filename, "wb") != 0)
        return -1;

    fclose(f);
    return 0;
}

void delete_from_file(int startAge, int endAge, char* name)
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

void add_PoultryFarm(PoultryFarm t, int pos)
{
    cout << "\n������� add_Zoo\n";
    if (pos < 1)
        cout << "\n\t������������ �����" << endl;
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
            cout << "\n\t������������ �����" << endl;
    }
}

void work_file()
{
    int oper;
    cout << "\n������� work_file\n";
    do
    {
        cout << "1. �������� �����" << endl;
        cout << "2. �������� �� �����" << endl;
        cout << "3. ���������� � ����" << endl;
        cout << "4. �������� ����" << endl;
        cout << "0. �����" << endl << endl;
        cout << "�������� �������: ";

        cin >> oper;
        console_clear();
        switch (oper)
        {
        case 1:
            read_file();
            break;
        case 2:
        {
            cout << "��������: ";
            char str[30];
            cin >> str;

            int start;
            cout << "�������: ";
            cin >> start;
            int end = start;

            delete_from_file(start, end, str);
            console_clear();
            break;
        }
        case 3:
        {
            int pos;
            cout << "����� ������ �������� ��������? -> ";
            cin >> pos;

            PoultryFarm p = create();
            add_PoultryFarm(p, pos);
            break;
        }
        case 4:
        {
            cout << "�� ����� ������ �������� ������? (+ / ANYKEY)\t";
            if (_getch() == '+')
                cout << "���� ������\n", clear_file(FILENAME) == 0 ? "" : "��";
            else
                cout << "\n������";

            cout << "\nANYKEY TO CONTINUE ";
            _getch();
            console_clear();
            break;
        }
        }
    } while (oper != 0);
}

void console_clear()
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