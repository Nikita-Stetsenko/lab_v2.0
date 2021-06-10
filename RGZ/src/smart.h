#ifndef SMART
#define SMART
#include "bulb.h"
using std::string;
using std::endl;

class Smart : public Bulb 
{
private:
	static const string type[2];
protected:
	/// Smart
	string smart;
	/// Wireless
	string wireless;
	/// Microcontroller
	string microcontroller;
	/// Color in HEX
	string hex;


public:
	/// Конструктор за замовчуванням
	Smart();
	/// Копіюючий конструктор
	Smart(const Smart& copy);
	/// Constructor with arguments
	/// @param status The status
	/// @param state The state
	/// @param man The manufacturer
	/// @param death The count to death bulb
	/// @param watt The watt
	/// @param col The temperature of color
	/// @param sh The name of shape
	/// @param pl The plinth type
		/// @param sm Smart
	/// @param wl Wireless
	/// @param mc Microcontroller
	/// @param hx Color in HEX
	Smart(string status, int state, string man, int death, int watt, int col, int sh, int pl, string sm, string wl, int mc, string hx);
	/// Деструктор
	~Smart();

	/// Set the smart
	/// @param sm Smart
	void set_smart(const string sm);
	/// Return smart
	string get_smart() const;
	/// Set the wireless
/// @param wl The wireless
	void set_wireless(const string wl);
	/// Return the status
	string get_wireless() const;
	/// Set the microcontroller
	/// @param mc The microcontroller
	void set_microcontroller(const int mc);
	/// Return the microcontroller
	string get_microcontroller() const;
	/// Set the color in HEX
	/// @param hx The color in HEX
	void set_hex(const string hx);
	/// Return the color in HEX
	string get_hex() const;


	/// Change string to object
	/// @return changed string to obgect
	string toString() const override final;
	/// Change string to object
	/// @param l string, which we should change
	/// @return changed string to object
	void fromString(string l) override final;
	/// Assignment operator
		/// @param other bulb which is being compared
	Smart& operator= (const Smart& other);
	/// Copy function
/// @return the copy of bulb
	Smart& Copy() const override final;
};

#endif 
