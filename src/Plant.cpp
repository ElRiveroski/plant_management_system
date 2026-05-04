/*
*
*
*   Plant.cpp
*
*
*/

#include "Plant.h"
#include <iomanip> // formatted output
#include <iostream>
using namespace std;

// constructor
Plant::Plant(string plantName, double plantCost) {  // constructor method that sets up name and cost
	name = plantName;
	cost = plantCost;
}


string Plant::getName() {
	return name;
}


double Plant::getCost() {
	return cost;
}

//overload == operator to compare
bool Plant::operator ==(const string& pName) const {
	return name == pName;
}

//friend
ostream& operator <<(ostream& out, const Plant& p) {
	return p.display(out);
}

//virtual
ostream& Plant::display(ostream& out) const {
    cout << name << " $" << fixed << setprecision(2) << cost;
    
    return out; 
}
