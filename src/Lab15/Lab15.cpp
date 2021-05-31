#include<iostream>
using namespace std;
//Игры
struct Games
{
    char game[50];
    char developer[50];
    char genre[50];
    float rating;
    float price;
};

//Надписи
void inscription(Games net)
{
    cout << "\Title\t: " << net.game;
    cout << "\nDevelop\t: " << net.developer;
    cout << "\nGenre\t: " << net.genre;
    cout << "\nRating\t: " << net.rating;
    cout << "\nPrice\t: " << net.price << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "\t\tGameRay" << endl;
    const int length = 8;

    Games GameRay[length]
    {
        { "1) Grand Theft Auto V", "Rockstar North", "Action", 9.6, 520 },
        { "2) FIFA 21", "EA Canada","Sport", 7.3, 750 },
        { "3) Death Stranding", "Kojima Productions", "Action", 8.6, 550 },
        { "4) Days Gone", "Bend Studio", "Shooter, adventure", 7.1, 972 },
        { "5) Resident Evil Village", "Capcom", "Action", 7.5, 688 },
        { "6) SnowRunner", "Saber Interactive", "Adventure, simulation", 7.6, 379 },
        { "7) Maneater", "Tripwire Interactive", "Action, Adventure, RPG", 5.8, 366 },
        { "8) Elite Dangerous: Odyssey", "Frontier Developments", "Action, Adventure, RPG, Simulation", 8.0, 270 },
    };

    for (int i = 0; i < length; i++)
        inscription(GameRay[i]);

}