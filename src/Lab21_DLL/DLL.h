#pragma once
#ifdef PoultryFarmDLL_EXPORTS  
#define PoultryFarm_API __declspec(dllexport)   
#else  
#define PoultryFarm_API __declspec(dllimport)   
#endif  

class PoultryFarm_API PoultryFarm
{
private:
    char name[50];
    int number;
    char colour[50];
    char kind[50];
    int age;
public:
    static void console_clear();
    void form_file();
    void read_file();
    void work_file();
    void add_PoultryFarm(PoultryFarm t, int pos);
    void delete_from_file(int startAge, int endAge, char* name);
    int clear_file(const char* filename);
    auto create();
    ~PoultryFarm() {}
};