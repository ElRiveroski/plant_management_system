/*
*
*       Flower.h
*
*
*
*/

#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"
using namespace std;

class Flower:public Plant {         // deriving Flower from Plant Class
private:
	string color;       // private string that sets the color 
	bool isAnnual;      // private boolean that returns t/f if annual. A false implies that it is perennial 

public:
	Flower(string plantName, double plantCost, string flowerColor, bool flowerType); // method that would set a flower with a name, 
	                                                                                 // cost, color, and annual or perennial
	virtual ostream& display(ostream& out) const;   // display method
	friend ostream& operator << (ostream& out, const Flower& f);   // overloaded operator for << to print 
};
#endif //FLOWER_H