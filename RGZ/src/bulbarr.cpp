#include "bulbarr.h"

BulbArr::BulbArr() {

}

BulbArr::~BulbArr() {
    for (vector<Bulb*>::iterator it = bulbs.begin(); it != bulbs.end(); it++)
        delete* it;

    bulbs.clear();
}

Bulb& BulbArr::getBulb(size_t index) const {
    return *bulbs[index];
}

size_t BulbArr::getSize() const {
    return bulbs.size();
}

Bulb& BulbArr::operator[] (const int index) const {
    return *bulbs[index];
}

void BulbArr::showAll() const {
    int i = 1;
    for (Bulb* lightbulb : bulbs)
        cout << "Bulb " << i++ << ": " << endl << lightbulb->toString() << endl;
}

void BulbArr::addBulb(Bulb& bulb)
{
    Bulb* lightbulb = &bulb.Copy();
    bulbs.push_back(lightbulb);
}

void BulbArr::removeBulb(int index) {
    delete bulbs[index];
    bulbs.erase(bulbs.begin() + index);
}

void BulbArr::Merger(BulbArr& lightbulb) {
    size_t size = lightbulb.bulbs.size();

    for (size_t i = 0; i < size; ++i)
        addBulb(**(lightbulb.bulbs.begin() + i));
}



void BulbArr::readFromFile(string fileName) {
    std::ifstream in(fileName);
    if (in.is_open()) {
        cout << "Reading the file ... " << endl << fileName << endl;
        in >> *this;
        in.close();
    }
    else {
        cout << "ERROR... We cannot find the file... " << endl << fileName << endl;
    }
}

void BulbArr::writeToFile(string fileName) {
    std::ofstream out;
    out.open(fileName);
    if (out.is_open()) {
        cout << "Writing to the file ... " << endl << fileName << endl;
        out << *this;
        out.close();
    }
    else {
        cout << "ERROR... We cannot find the file... " << endl << fileName << endl;
    }
}

std::ostream& operator<< (std::ostream& out, const BulbArr& lightbulb) {
    for (size_t i = 0; i < lightbulb.getSize(); i++)
        out << "Bulb " << i + 1 << ": " << endl << lightbulb[i] << endl;
    return out;
}

std::istream& operator>> (std::istream& in, BulbArr& lightbulb) {
    Bulb* bulb;
    string h;
    std::stringstream str;
    int id;
    std::regex smart("\\s[A-Za-z]*\\s[A-Za-z0-9-]*\\s[0-9]*\\s[0-2]\\s[A-Za-z]*\\s[A-Za-z]*\\s[A-Za-z]*\\s[A-Za-z]*");
    std::regex eternal("\\s[A-Za-z]*\\s[A-Za-z0-9-]*\\s[0-9]*\\s[0-2]\\s[A-Za-z]*\\s[A-Za-z]*\\s[0-1]\\s[0-9]*");
    std::smatch m;

    while (in) {
        getline(in, h);
        str.clear();
        str << h;
        str >> id;
        bulb = bulb->BulbById(id);
        getline(str, h);
        switch (id) {
        case 0:
            if (regex_match(h, m, eternal))
            {
                bulb->fromString(h);
                lightbulb.addBulb(*bulb);
            }
            break;
        case 1:
            if (regex_match(h, m, smart))
            {
                bulb->fromString(h);
                lightbulb.addBulb(*bulb);
            }
            break;
        }
        delete bulb;
    }
    return in;
}

void BulbArr::find_deadbulb() const {
    int i = 1;
    for (Bulb* lightbulb : bulbs)
        if (lightbulb->get_state() == 0) {
            cout << "Bulb " << i << endl << *lightbulb;
            i++;
        }
}

void BulbArr::find_smartbulb() const {
    int i = 1;
    for (Bulb* lightbulb : bulbs) {
        Smart* h = dynamic_cast<Smart*>(lightbulb);
        if (h != nullptr) {
            if (h->get_smart() == "Yes") {
                cout << "Bulb " << i << endl << *lightbulb;
                i++;
            }
        }
    }
}

void BulbArr::find_fullwatt() const {
    int allwatt = 0;
    for (Bulb* lightbulb : bulbs) {
        if (lightbulb->get_state() != 0) {
            allwatt = allwatt + lightbulb->get_watt();
        }
    }
    cout << "Total energy consumption is " << allwatt << "watts." << endl;
}
