#include "eternal.h"

Eternal::Eternal()
	: Bulb() {
}

Eternal::Eternal(const Eternal& copy)
	: Bulb(copy),
	eternal(copy.eternal) {
}

Eternal::Eternal(string status, int state, string man, int death, int watt, int col, int sh, int pl, string et)
	: Bulb(status, state, man, death, watt, col, sh, pl),
	eternal(et) {
}

Eternal::~Eternal() {

}

void Eternal::set_eternal(const string et) {
	eternal = et;
}
string Eternal::get_eternal() const {
	return eternal;
}

Eternal& Eternal::operator= (const Eternal& other)
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
	eternal = other.eternal;
	return *this;
}

string Eternal::toString() const {
	std::stringstream l;
	l << "\n\tStatus: " << status << ";\n\tEternal: " << eternal << ";\n\tState: " << state << ";\n\tManufacturer: " << manufacturer << ";\n\tNumber of starts before burnout: " << death << ";\n\tConsumption in watts: " << watt << ";\n\tLight temperature: " << color << ";\n\tShape: " << shape << ";\n\tType of plinth: " << plinth << "." << endl;
	return l.str();
}

void Eternal::fromString(string l)
{
	int sh, pl;
	std::stringstream str;
	str << l;
	str >> status >> state >> manufacturer >> death >> watt >> color >> sh >> pl >> eternal;
	set_shape(sh);
	set_plinth(pl);
}

Eternal& Eternal::Copy() const {
	Eternal* bulb = new Eternal();
	*bulb = *this;
	return *bulb;
}
