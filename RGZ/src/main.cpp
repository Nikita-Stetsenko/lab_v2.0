#include "bulbarr.h"

int main() {
    BulbArr lightbulbs;
    int answer = 0;
    lightbulbs.readFromFile("doc/bulbs.txt");
    while (answer < 9) {
        cout << "\nActions: " << "\n\t1. Show bulbs;" << "\n\t2. Remove bulb;" << "\n\t3. Show the dead bulb;" << "\n\t4. Find smart bulbs;" << "\n\t5. Find total energy consumprion;" << "\n\t6. Sort bulbs by watts;" << "\n\t7. Merge list;" << "\n\t8. Exit." << endl;
        cin >> answer;
        switch (answer)
        {
        case 1:
            cout << lightbulbs;
            break;
        case 2:
            cout << lightbulbs;
            cout << "Enter the number of bulb: " << endl;
            cin >> answer;
            lightbulbs.removeBulb(answer - 1);
            break;
        case 3:
            cout << "Dead bulb(-s):" << endl;
            lightbulbs.find_deadbulb();
            break;
        case 4:
            cout << "Smart bulb(-s): " << endl;
            lightbulbs.find_smartbulb();
            break;
        case 5:
            cout << "The total energy consumprion in watts is: " << endl;
            lightbulbs.find_fullwatt();
            break;
        case 6:
            cout << "Sort bulbs by watts: " << endl;
            FunctorLessWatt f;
            lightbulbs.Sort(f);
            cout << lightbulbs;
            break;
        case 7:
            lightbulbs.Merger(lightbulbs);
            break;
        case 8:
            lightbulbs.writeToFile("dist/bulb.txt");
            return 0;
        default:
            cout << "ERROR...";
            break;
        }
    }
}
