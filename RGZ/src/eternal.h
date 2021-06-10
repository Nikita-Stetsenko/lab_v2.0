#ifndef ETERNAL
#define ETERNAL
#include "bulb.h"
using std::string;
using std::endl;

/// The class of eternal bulb
class Eternal : public Bulb {
protected:
	string eternal;
public:
	/// Конструктор за замовчуванням
	Eternal();
	/// Копіюючий конструктор
	Eternal(const Eternal& copy);
	/// Constructor with arguments
	/// @param status The status
	/// @param state The state
	/// @param man The manufacturer
	/// @param death The count to death bulb
	/// @param watt The watt
	/// @param col The temperature of color
	/// @param sh The name of shape
	/// @param pl The plinth type
		/// @param et Eternal bulb
	Eternal(string status, int state, string man, int death, int watt, int col, int sh, int pl, string et);

	/// Деструктор
	~Eternal();

	/// Set the eternal
	/// @param et eternal
	void set_eternal(const string et);
	/// Return eternal
	string get_eternal() const;

	/// Assignment operator
	/// @param other bulb which is being compared
	Eternal& operator= (const Eternal& other);
	/// Copy function
/// @return the copy of bulb
	Eternal& Copy() const override final;

	/// Change string to object
	/// @param l string, which we should change
	/// @return changed string to object
	void fromString(string l) override final;
	// Change string to object
	/// @return changed string to obgect
	string toString() const override final;
};

#endif
