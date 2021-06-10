#include "bulb.h"
#include "smart.h"
#include "eternal.h"

const string Bulb::shapes[] = { "Candle", "Tubular", "Globe", "Pear", "Ogive" };
const string Bulb::plinths[] = { "E14", "E27", "E40" };
Bulb::Bulb() : state(0), death(0), watt(0), color(0), shape(shapes[0]), plinth(plinths[0]) {

}

Bulb::Bulb(const Bulb& copy)
	: status(copy.status),
	state(copy.state),
	manufacturer(copy.manufacturer),
	death(copy.death),
	watt(copy.watt),
	color(copy.color),
	shape(copy.shape),
	plinth(copy.plinth) {
}

Bulb::Bulb(string sts, int ste, string man, int dth, int w, int col, int sh, int pl)
	: status(sts),
	state(ste),
	manufacturer(man),
	death(dth),
	watt(w),
	color(col),
	shape(shapes[sh]),
	plinth(plinths[pl]) {
}

Bulb::~Bulb() {

}

void Bulb::set_status(const string sts) {
	status = sts;
}
string Bulb::get_status() const {
	return status;
}

void Bulb::set_state(const int ste) {
	state = ste;
}

int Bulb::get_state() const {
	return state;
}

void Bulb::set_manufacturer(const string man) {
	manufacturer = man;
}
string Bulb::get_manufacturer() const {
	return manufacturer;
}

void Bulb::set_death(const int dth) {
	death = dth;
}

int Bulb::get_death() const {
	return death;
}
void Bulb::set_watt(const int w) {
	watt = w;
}

int Bulb::get_watt() const {
	return watt;
}
void Bulb::set_color(const int col) {
	color = col;
}

int Bulb::get_color() const {
	return color;
}

void Bulb::set_shape(const int sh) {
	shape = shapes[sh];
}
string Bulb::get_shape() const {
	return shape;
}

void Bulb::set_plinth(const int pl) {
	plinth = plinths[pl];
}
string Bulb::get_plinth() const {
	return plinth;
}

string Bulb::toString() const
{
	std::stringstream l;
	l << "\n\tStatus: " << status << ";\n\tState: " << state << ";\n\tManufacturer: " << manufacturer << ";\n\tNumber of starts before burnout: " << death << ";\n\tConsumption in watts: " << watt << ";\n\tLight temperature: " << color << ";\n\tShape: " << shape << ";\n \tType of plinth: " << plinth << "." << endl;
	return l.str();
}

void Bulb::fromString(string l)
{
	int sh, pl;
	std::stringstream str;
	str << l;
	str >> status >> state >> manufacturer >> death >> watt >> color >> sh >> pl;
	set_shape(sh);
	set_plinth(pl);
}

Bulb& Bulb::operator= (const Bulb& other)
{
	if (this == &other)
	{
		return *this;
	}

	status = other.status;
	state = other.state;
	manufacturer = other.manufacturer;
	death = other.death;
	watt = other.watt;
	color = other.color;
	shape = other.shape;
	plinth = other.plinth;
	return *this;
}

bool Bulb::operator< (const Bulb& other) {
	return (this->state < other.state);
}

std::ostream& operator<< (std::ostream& out, const Bulb& bulb) {
	out << bulb.toString();
	return out;
}

std::istream& operator>> (std::istream& in, Bulb& bulb) {
	string l;
	getline(in, l);
	bulb.fromString(l);
	return in;
}

Bulb* Bulb::BulbById(int id) {
	switch (id) {
	case 0:
		return new Eternal();
	case 1:
		return new Smart();
	default:
		return nullptr;
	}
}
