#ifndef BULBARR
#define BULBARR
#include "bulb.h"
#include "smart.h"
#include "eternal.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;

/// The collection of bulbs
class BulbArr
{
private:
	vector<Bulb*> bulbs;
public:
	/// Standart constructor
	BulbArr();
	/// Destructor
	~BulbArr();

	/// Finding bulbs for the index
	/// @param index The index
	Bulb& getBulb(size_t index) const;
	/// Returns the size of collection
	size_t getSize() const;
	/// Print all of the bulbs
	void showAll() const;
	/// Adding the bulb
	/// @param bulb the bulb which we add
	void addBulb(Bulb& bulb);
	/// Delete the bulb for index
	/// @param index The index
	void removeBulb(int index);
	/// Combining two classes
		/// @param lightbulb class which we add
	void Merger(BulbArr& lightbulb);


	/// Read info from file
/// @param fileName file
	void readFromFile(string fileName);
	/// Write info to file
	/// @param fileName file
	void writeToFile(string fileName);


	/// Finding the dead bulb
	void find_deadbulb() const;
	/// Finding smart bulbs
	void find_smartbulb() const;
	/// Finding total energy consumption
	void find_fullwatt() const;



	/// Index operator
	/// @param index index
	Bulb& operator[] (const int index) const;
	/// Element output operator
	/// @param out output stream
	/// @param bulb bulb which is output
	friend std::ostream& operator<< (std::ostream& out, const BulbArr& bulb);
	/// Element input operator
	/// @param in input stream
	/// @param bulb bulb which is input
	friend std::istream& operator>> (std::istream& in, BulbArr& bulbs);
	/// Sorting the list from 
	template <typename Functor> void Sort(Functor f) {
		std::sort(bulbs.begin(), bulbs.end(), f);
	}
};

/// Functor "Less watts"
class FunctorLessWatt {
public:
	/// @param bulb1 the firt bulb
	/// @param bulb2 the second bulb
	/// @param true if the number of watts of the first bulb is less than the second, @param false if vice versa
	bool operator()(const Bulb* bulb1, const Bulb* bulb2) {
		return bulb1->get_watt() < bulb2->get_watt();
	}
};
#endif
