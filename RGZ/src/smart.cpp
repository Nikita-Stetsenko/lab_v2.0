#include "smart.h"

const string Smart::type[] = { "ESP8266", "STM32F103" };

Smart::Smart()
	: Bulb(),
	microcontroller(type[0]) {
}

Smart::Smart(const Smart& copy)
	: Bulb(copy),
	smart(copy.smart),
	wireless(copy.wireless),
	microcontroller(copy.microcontroller),
	hex(copy.hex) {
}

Smart::Smart(string status, int state, string man, int death, int watt, int col, int sh, int pl, string sm, string wl, int mc, string hx)
	: Bulb(status, state, man, death, watt, col, sh, pl),
	smart(sm),
	wireless(wl),
	microcontroller(type[mc]),
	hex(hx) {
}

Smart::~Smart() {

}

void Smart::set_smart(const string sm) {
	smart = sm;
}
string Smart::get_smart() const {
	return smart;
}
void Smart::set_wireless(const string wl) {
	wireless = wl;
}
string Smart::get_wireless() const {
	return wireless;
}

void Smart::set_microcontroller(const int mc) {
	microcontroller = type[mc];
}
string Smart::get_microcontroller() const {
	return microcontroller;
}

void Smart::set_hex(const string hx) {
	hex = hx;
}
string Smart::get_hex() const {
	return hex;
}

Smart& Smart::operator= (const Smart& other)
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
	smart = other.smart;
	wireless = other.wireless;
	microcontroller = other.microcontroller;
	hex = other.hex;
	return *this;
}

string Smart::toString() const {
	std::stringstream l;
	l << "\n\tStatus: " << status << ";\n\tState: " << state << ";\n\tManufacturer: " << manufacturer << ";\n\tNumber of starts before burnout: " << death << ";\n\tConsumption in watts: " << watt << ";\n\tLight temperature: " << color << ";\n\tShape: " << shape << ";\n\tType of plinth: " << plinth << ";\n\tSmart: " << smart << ";\n\tWireless:" << wireless << ";\n\tMicrocontroller:" << microcontroller << ";\n\tThe color in HEX:" << hex << "." << endl;
	return l.str();
}

void Smart::fromString(string l)
{
	int sh, pl, mc;
	std::stringstream str;

	str << l;
	str >> status >> state >> manufacturer >> death >> watt >> color >> sh >> pl >> smart >> wireless >> mc >> hex;
	set_shape(sh);
	set_plinth(pl);
	set_microcontroller(mc);

}

Smart& Smart::Copy() const {
	Smart* bulb = new Smart();
	*bulb = *this;
	return *bulb;
}
