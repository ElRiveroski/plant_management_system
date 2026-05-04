/******************************************************************************

main.cpp

Rolando Rivera
Lab 6 - C++ Plants and Flowers 

* addPlant- add a new Plant or Flower pointer to the vector. Prompt the user for information.
* removePlant -remove a Plant or Flower from the vector
* display - display the contents of the vector
* total cost - display the total cost of all Plants and Flowers in the vector
* sort by plant name
* sort by plants cost
* quit the program

*******************************************************************************/
#include <iostream>
#include "Plant.h"  // includes the plant files
#include "Flower.h" // includes the flower files
#include <vector>       //STL
#include <algorithm> // needed for the sorting algorithm
#include <iterator>  
#include <iomanip>
using namespace std;


//prototypes
void addPlant(vector<Plant*>& garden);      //adds a plant or flower to the vector 
void removePlant(vector<Plant*>& garden);   //removes a plant or flower from the vector 
void displayGarden(const vector<Plant*>& garden); //displays our vector 
void totalCost(const vector<Plant*>& garden); // provides a total cost (value) of our vector 
bool screenByName(Plant* a, Plant* b);      //helper function for sort by name
bool screenByCost(Plant* a, Plant* b);        //helper function for sort by cost
void sortByName(vector<Plant*>& garden); // sorts our vector by name 
void sortByCost(vector<Plant*>& garden); // sorts out vector by cost 

int main()
{

	vector<Plant*> garden;      // creates a vector pointer named garden 
	int choice;                 // choice input is read for the menu 
	
	
	
    /*The following lines of code (from 44 to about 118) is the menu that takes the 
    input from the user and proceeds based on said input.*/
	do {
		cout << "\n***MY GARDEN MENU***" << endl;
		cout << "Please enter your selection numerically only" << endl;
		cout << "1. Add a new plant" << endl;
		cout << "2. Remove a plant" << endl;
		cout << "3. Display your plants" << endl;
		cout << "4. Total Cost" << endl;
		cout << "5. Sort by plant name" << endl;
		cout << "6. Sort by plant cost" << endl;
		cout << "7. Quit" << endl;
		cout << "Please enter your selection number: " << endl;
		cin >> choice;

		switch(choice) {
		case 1:
			addPlant(garden);
			break;
		case 2:
			removePlant(garden);
			break;
		case 3:
			displayGarden(garden);
			break;
		case 4:
			totalCost(garden);
			break;
		case 5:
			sortByName(garden);
			break;
		case 6:
			sortByCost(garden);
			break;
		case 7:
			cout << "Program complete" << endl;
			break;
		}

	} while (choice != 7);

	return 0;
}

// this method takes in a character to know whether to create a flower or a plant 
// depending on the selection, it will proceed to prompt the user for further details
// and will add them to our vector 
void addPlant(vector<Plant*>& garden) {
	char type;
	cout << "Enter plant type ('P' for Plant, 'F' for flower): ";
	cin >> type;

	if(type == 'P' || type == 'p') {
		string addPlantName;
		double addPlantCost;

		cout << "Enter plant name: ";
		cin >> addPlantName;
		cout << "Enter plant cost: ";
		cin >> addPlantCost;
		garden.push_back(new Plant(addPlantName,addPlantCost));
	}
	else if(type == 'F' || type == 'f') {
		string addFlowerName;
		string addFlowerColor;
		double addFlowerCost;
		char flowerType;

		cout << "Enter flower name: ";
		cin >> addFlowerName;
		cout << "Enter flower cost: ";
		cin >> addFlowerCost;
		cout << "Enter flower color: ";
		cin >> addFlowerColor;
		cout<< "Is the flower annual? (Y/N): ";
		cin >> flowerType;
		garden.push_back(new Flower(addFlowerName, addFlowerCost, addFlowerColor, (flowerType == 'Y' || flowerType == 'y')));
	} else {
		cout << "There is an error in the input- please revise your input" << endl;
	}
}

// removePlant takes the inputted string name, cross referrences through our 
// vector and then deletes it. If the string name is not located, an error 
// is returned and the string name as 'not in the garden' 
void removePlant(vector<Plant*>& garden) {
	string removePlant_name;
	cout << "Enter plant name to remove: ";
	cin >> removePlant_name;

	vector<Plant*>::iterator it = find_if(garden.begin(), garden.end(), [&removePlant_name](Plant* p) {
		return *p == removePlant_name;
	});

	if(it != garden.end()) {
		delete *it;
		garden.erase(it);
		cout << "Plant removed succesfully." << endl;
	}
	else {
		cout << "Error - " << removePlant_name << " is not in the garden." << endl;
	}
}

// displays the vector by running a loop within our garden until it reaches the size 
void displayGarden(const vector<Plant*>& garden) {
	if(garden.empty()) {
		cout << "The garden is empty." << endl;
		return;
	} else {
		for(size_t i = 0; i < garden.size(); i++) {
			cout << "Plant " << i + 1 << ": ";
			garden[i]->display(cout);
			cout << endl;
		}
	}
}

// this function sets the cost of all plants/ flowers in our vector 
void totalCost(const vector<Plant*>& garden) {
	double cost = 0.0;
	/*for(const vector<Plant*>::iterator it = garden.begin(); it != garden.end(); it++){
	    (*it)->display();
	}*/
	for(const auto& plant : garden) { //auto function reads the type of 'plant', loops over the garden vector and modifies our 
	                                  // localized variable (cost) which ultimately provides our sum total  
		cost += plant->getCost();
	}
	cout << "The total cost of all the plants is: $" << fixed << setprecision(2) << cost << endl;

}

// boolean helper function to read string names 
bool screenByName(Plant* a, Plant* b) {
	return a->getName() < b->getName();
}

// boolean helper function to read double costs 
bool screenByCost(Plant* a, Plant* b) {
	return a->getCost() < b->getCost();
}

// sort function that runs through our vector, and takes the 
// sort function from the <algorithm> library to reorder our 
// vector by name 
void sortByName(vector<Plant*>& garden) {
	sort(garden.begin(), garden.end(), screenByName);
	cout << "Garden sorted by name." << endl;
	if(garden.empty()) {
		cout << "The garden is empty." << endl;
		return;
	} else {
		for(size_t i = 0; i < garden.size(); i++) {
			cout << "Plant " << i + 1 << ": ";
			garden[i]->display(cout);
			cout << endl;
		}
	}
}

// sort function that runs through our vector, and takes the 
// sort function from the <algorithm> library to reorder our 
// vector based on costs 
void sortByCost(vector<Plant*>& garden) {
	sort(garden.begin(), garden.end(), screenByCost);
	cout << "Garden sort by cost." << endl;
	if(garden.empty()) {
		cout << "The garden is empty." << endl;
		return;
	} else {
		for(size_t i = 0; i < garden.size(); i++) {
			cout << "Plant " << i + 1 << ": ";
			garden[i]->display(cout);
			cout << endl;
		}
	}
}










