/*
*
*
*   Plant.h
* Plant.h is the base class
*
* addPlant- add a new Plant or Flower pointer to the vector. Prompt the user for information.
* removePlant -remove a Plant or Flower from the vector
* display - display the contents of the vector
* total cost - display the total cost of all Plants and Flowers in the vector
* sort by plant name
* sort by plants cost
* quit the program
*/

#ifndef PLANT_H
#define PLANT_H

#include <iostream>     // for input/output
#include <string>       //for strings
using namespace std;

class Plant {
private:
	string name;        //private string for strings
	double cost;        // private double for costs

public:
	Plant(string plantName, double plantCost); // function that adds a new plant/flower to the vector
	string getName();   // getter function that returns the name
	double getCost();   // getter function that returns the cost
	bool operator ==(const string& pName) const;    // boolean function to compare string names 
	virtual ostream& display(ostream& out) const;   // polymorphistic function that returns a display
	friend ostream& operator <<(ostream& out, const Plant& p);  // friend function that overloads the "<<" operators


};

#endif /* PLANT_H */