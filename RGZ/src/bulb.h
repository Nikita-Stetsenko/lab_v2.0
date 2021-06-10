#ifndef BULB
#define BULB
#include <string>
#include <sstream>
using std::string;
using std::endl;
/// The class of "Bulb"
class Bulb {
protected:
	/// The status
	string status;
	/// The state
	int state;
	/// The manufacturer
	string manufacturer;
	/// The count to death bulb
	int death;
	/// The watt
	int watt;
	/// The temperature of color
	int color;
	/// The shape
	string shape;
	/// The plinth
	string plinth;
	/// The shape type
	static const string shapes[5];
	/// The plinth type
	static const string plinths[3];
public:
	/// Standart constructor
	Bulb();

	/// Copy constuctor
	Bulb(const Bulb& copy);

	/// Constructor with arguments
/// @param status The status
/// @param state The state
/// @param man The manufacturer
/// @param death The count to death bulb
/// @param watt The watt
/// @param col The temperature of color
/// @param sh The name of shape
/// @param pl The plinth type
	Bulb(string status, int state, string man, int death, int watt, int col, int sh, int pl);

	/// Destructor
	virtual ~Bulb();

	/// Set the status
/// @param status The status
	void set_status(const string status);

	///Return the status
	string get_status() const;

	/// Set the state
	/// @param state The state
	void set_state(const int state);

	///Return the state
	int get_state() const;

	/// Set the manufacturer
	/// @param man The manufacturer
	void set_manufacturer(const string man);

	///Return the manufacturer
	string get_manufacturer() const;

	/// Set the count to death bulb
	/// @param death the count to death bulb
	void set_death(const int death);

	///Return the count to death bulb
	int get_death() const;

	/// Set the watt
	/// @param watt The watt
	void set_watt(const int watt);

	///Return the watt
	int get_watt() const;

	/// Set the temperature of color
	/// @param col The temperature of color
	void set_color(const int col);

	///Return the temperature of color
	int get_color() const;

	/// Set the shape
	/// @param sh The shape
	void set_shape(const int sh);

	///Return the shape
	string get_shape() const;

	/// Set the type of plinth
	/// @param pl The type of plinth
	void set_plinth(const int pl);

	///Return the plinth
	string get_plinth() const;

	// Change string to object
/// @return changed string to obgect
	virtual string toString() const;

	/// Change string to object
/// @param l string, which we should change
/// @return changed string to object
	virtual void fromString(string l);

	/// Copy function
/// @return the copy of bulb
	virtual Bulb& Copy() const = 0;

	/// Assignment operator
	/// @param other bulb which is being compared
	virtual Bulb& operator= (const Bulb& other);

	/// Comparison operator
/// @param other bulb to be compared
	virtual bool operator< (const Bulb& other);

	/// Element output operator
/// @param out output stream
/// @param bulb bulb which is output
	friend std::ostream& operator<< (std::ostream& out, const Bulb& bulb);

	/// Element input operator
/// @param in input stream
/// @param bulb bulb which is input
	friend std::istream& operator>> (std::istream& in, Bulb& bulb);

	/// @param id the id of bulb
/// @return the bulb by id
	static Bulb* BulbById(int id);
};
#endif
#pragma once
