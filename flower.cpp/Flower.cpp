/*
* Flower.cpp
*
*
*
*
*/
#include "Flower.h" // derived from the parent class 
#include <iomanip> // for io manipulation
using namespace std;

// constructor
Flower::Flower(string plantName, double plantCost, string flowerColor, bool flowerType)
	:Plant(plantName, plantCost), color(flowerColor), isAnnual(flowerType) {
}

//friend function
ostream& operator << (ostream& out, const Flower& f) {
	return f.display(out);
}

//function displays the flower, the color, and whether it is annual or not 
ostream& Flower::display(ostream& out) const {
	out << (Plant)(*this)<< " " << color << " " << (isAnnual ? "annual" : "perennial");
	return out;
}
