/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "ShapeTwoD.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cross.h"

using namespace std;

// function prototypes //
void printMenu();

int promptChoice();

int main() {

	// variables
	int choice;
	string name;
	string specialType;

	// to store 4, 12 points of Square/Rectangle, Cross
	// set to nullptr to prevent segmentation fault
	// deallocating memory when no memory was allocated
	int * xCoordinateArr = nullptr;
	int * yCoordinateArr = nullptr;

	// to store Circle's center coordinates/temp storage for array
	int xCoordinate;
	int yCoordinate;

	int radius;

	// tracks number of records enter into ShapeTwoD
	int noOfRecords = 0;
	int vertices;
	bool containsWarpSpace;

	// define vector to store ShapeTwoD object
	vector <ShapeTwoD*> shapeVector;

	// define vector to store Square object
	Square * squareArray = new Square[100];

	// define and initialise 100 Rectangle object
	Rectangle * rectangleArray = new Rectangle[100];

	// define and initialise 100 Circle object
	Circle * circleArray = new Circle[100];

	// define and initialise 100 Cross object
	Cross * crossArray = new Cross[100];
	
	// display menu
	printMenu();

	// prompt choice
	PROMPTCHOICE:choice = promptChoice();
	
	if (choice == 1)
	{
		// submenu
		cout << "[ Input sensor data ]" << endl;
		cout << "Please enter name of shape : ";
		cin >> name;

		cout << "Please enter special type : ";
		cin >> specialType;
		cout << endl;
	
		// check shape name
		if (name == "Square")
		{
			vertices = 4;
			xCoordinateArr = new int[vertices];
			yCoordinateArr = new int[vertices];
		}
		else if (name == "Rectangle")
		{
			vertices = 4;
			xCoordinateArr = new int[vertices];
			yCoordinateArr = new int[vertices];
		}
		else if (name == "Cross")
		{
			vertices = 12;
			xCoordinateArr = new int[vertices];
			yCoordinateArr = new int[vertices];
		}
		else if (name == "Circle")
		{
			vertices = 1;
		}
		
		// check specialType
		if (specialType == "WS")
		{
			containsWarpSpace = true;
		} 
		else	
		{
			containsWarpSpace = false;
		}	

		// initialise ShapeTwoD vector object
		shapeVector.push_back(new ShapeTwoD(noOfRecords, name, specialType));
				

		if (vertices != 1)
		{
			for (int i = 0; i<vertices; i++)
			{
				cout << "Please enter x-ordinate of pt. " << i+1 << " : ";
				cin >> xCoordinate;
				xCoordinateArr[i] = xCoordinate;
				cout << "Please enter y-ordinate of pt. " << i+1 << " : ";
				cin >> yCoordinate;
				yCoordinateArr[i] = yCoordinate;
				cout << endl;
			}
		}
		else 
		{
			cout << "Please enter x-ordinate of center : ";
			cin >> xCoordinate;
			
			cout << "Please enter y-ordinate of center : ";
			cin >> yCoordinate;
			
			cout << "Please enter radius (units) : ";
			cin >> radius;

			cout << endl;
		}
		
		// pass vertices values into shape
		if (name == "Square")
		{
			squareArray[noOfRecords].setXCoordinateArr(xCoordinateArr);
			squareArray[noOfRecords].setYCoordinateArr(yCoordinateArr);
		}
		else if (name == "Rectangle")
		{
			rectangleArray[noOfRecords].setXCoordinateArr(xCoordinateArr);
			rectangleArray[noOfRecords].setYCoordinateArr(yCoordinateArr);
		}
		else if (name == "Cross")
		{
			crossArray[noOfRecords].setXCoordinateArr(xCoordinateArr);
			crossArray[noOfRecords].setYCoordinateArr(yCoordinateArr);
		}
		else if (name == "Circle")
		{
			circleArray[noOfRecords].setXCoordinate(xCoordinate);
			circleArray[noOfRecords].setYCoordinate(yCoordinate);
			circleArray[noOfRecords].setRadius(radius);
		}
		
		cout << "Record successfully stored. Going back to main menu ..." << endl;
		cout << endl;

		noOfRecords++;
		printMenu();
		goto PROMPTCHOICE;		
	} 
	else if (choice == 2)
	{
		// Compute Area
		for (int i=0; i<noOfRecords; i++)
		{
			if (shapeVector[i]->getName() == "Square")
				shapeVector[i]->setArea(squareArray[i].computeArea());

			else if (shapeVector[i]->getName() == "Rectangle")
				shapeVector[i]->setArea(rectangleArray[i].computeArea());

			else if (shapeVector[i]->getName() == "Circle")
				shapeVector[i]->setArea(circleArray[i].computeArea());

			else if (shapeVector[i]->getName() == "Cross")	
				shapeVector[i]->setArea(crossArray[i].computeArea());
		}

		cout << "Computation completed! ( " << noOfRecords << " records were updated )" << endl;
		cout << endl;

		printMenu();
		goto PROMPTCHOICE;			
	}
	else if (choice == 3)
	{
		cout << "Total no. of records available = " << noOfRecords << endl;
		cout << endl;

		// Displays Shape Records
		for (int i=0; i<noOfRecords; i++)
		{
			cout << "Shape [" << shapeVector[i]->getShapeID() << "]" << endl;

			if (shapeVector[i]->getName() == "Square")
			{	
				squareArray[i].setName(shapeVector[i]->getName());
				squareArray[i].setSpecialType(shapeVector[i]->getSpecialType());
				squareArray[i].setArea(shapeVector[i]->getArea());
				cout << squareArray[i].toString() << endl;
			}
			else if (shapeVector[i]->getName() == "Rectangle")
			{
				rectangleArray[i].setName(shapeVector[i]->getName());
				rectangleArray[i].setSpecialType(shapeVector[i]->getSpecialType());
				rectangleArray[i].setArea(shapeVector[i]->getArea());
				cout << rectangleArray[i].toString() << endl;
			}	
			else if (shapeVector[i]->getName() == "Circle")
			{
				circleArray[i].setName(shapeVector[i]->getName());
				circleArray[i].setSpecialType(shapeVector[i]->getSpecialType());
				circleArray[i].setArea(shapeVector[i]->getArea());
				cout << circleArray[i].toString() << endl;
			}
			else if (shapeVector[i]->getName() == "Cross")	
			{
				crossArray[i].setName(shapeVector[i]->getName());
				crossArray[i].setSpecialType(shapeVector[i]->getSpecialType());
				crossArray[i].setArea(shapeVector[i]->getArea());
				cout << crossArray[i].toString() << endl;
			}
			
			cout << endl;
		}
		
		printMenu();
		goto PROMPTCHOICE;
	}
	else if (choice == 4)
	{
		// Sorts Shape Records based on user choice
		cout << "Sorting" << endl;
		char option;
	
		// sub menu
		// Sort options
		cout << setw(6) << "a)" << setw(5) << " " << "Sort by area (ascending)" << endl;
		cout << setw(6) << "b)" << setw(5) << " " << "Sort by area (descending)" << endl;
		cout << setw(6) << "c)" << setw(5) << " " << "Sort by special type and area" << endl;
		cout << endl;

		cout << "Please select sort option ('q' to go to main menu) : ";
		cin >> option;

		cout << endl;

		if (option == 'q')
		{
			printMenu();
			goto PROMPTCHOICE;
		}
		else if (option == 'a')
		{
			// using sort with lambda
			// sort area in ascending order
			sort(shapeVector.begin(), shapeVector.end(), 
				[] (ShapeTwoD* lhs, ShapeTwoD* rhs)
			{	
				return lhs->getArea() < rhs->getArea();
			});

			cout << "Sort by area (smallest to largest) ..." <<endl;
			cout << endl;
			
			// Displays Shape Records after sorting
			for (int i=0; i<noOfRecords; i++)
			{
				cout << "Shape [" << shapeVector[i]->getShapeID() << "]" << endl;

				if (shapeVector[i]->getName() == "Square")
				{	
					cout << squareArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				else if (shapeVector[i]->getName() == "Rectangle")
				{
					cout << rectangleArray[shapeVector[i]->getShapeID()].toString() << endl;
				}	
				else if (shapeVector[i]->getName() == "Circle")
				{
					cout << circleArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				else if (shapeVector[i]->getName() == "Cross")	
				{
					cout << crossArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				cout << endl;
			}
			cout << endl;
			printMenu();
			goto PROMPTCHOICE;
		}
		else if (option == 'b')
		{
			// using sort with lambda
			// sort area in descending order
			sort(shapeVector.begin(), shapeVector.end(), 
				[] (ShapeTwoD* lhs, ShapeTwoD* rhs)
			{	
				return lhs->getArea() > rhs->getArea();
			});

			cout << "Sort by area (largest to smallest) ..." <<endl;
			cout << endl;

			// Displays Shape Records after sorting
			for (int i=0; i<noOfRecords; i++)
			{
				cout << "Shape [" << shapeVector[i]->getShapeID() << "]" << endl;

				if (shapeVector[i]->getName() == "Square")
				{	
					cout << squareArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				else if (shapeVector[i]->getName() == "Rectangle")
				{
					cout << rectangleArray[shapeVector[i]->getShapeID()].toString() << endl;
				}	
				else if (shapeVector[i]->getName() == "Circle")
				{
					cout << circleArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				else if (shapeVector[i]->getName() == "Cross")	
				{
					cout << crossArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				cout << endl;
			}
			cout << endl;
			printMenu();
			goto PROMPTCHOICE;
		}
		else if (option == 'c')
		{
			// Sort by special type, (WS, NS)
			// Followed by area in descending order 
			struct compareShape {
				inline bool
				operator()(ShapeTwoD* lhs, ShapeTwoD* rhs) const
				{
					return 
						// Compare Special Type, if same then compare Area
						(lhs->getSpecialType() > rhs->getSpecialType() ||
						lhs->getSpecialType() == rhs->getSpecialType() && 
						(lhs->getArea() > rhs->getArea()));
			
				}
			};
			stable_sort(shapeVector.begin(), shapeVector.end(), compareShape{});

			cout << "Sort by special type and area (largest to smallest) ..." <<endl;
			cout << endl;

			// Displays Shape Records after sorting
			for (int i=0; i<noOfRecords; i++)
			{
				cout << "Shape [" << shapeVector[i]->getShapeID() << "]" << endl;
 
				if (shapeVector[i]->getName() == "Square")
				{	
					cout << squareArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				else if (shapeVector[i]->getName() == "Rectangle")
				{
					cout << rectangleArray[shapeVector[i]->getShapeID()].toString() << endl;
				}	
				else if (shapeVector[i]->getName() == "Circle")
				{
					cout << circleArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				else if (shapeVector[i]->getName() == "Cross")	
				{
					cout << crossArray[shapeVector[i]->getShapeID()].toString() << endl;
				}
				cout << endl;
			}
			cout << endl;
			printMenu();
			goto PROMPTCHOICE;
		}
	}
	else if (choice == 5)
	{
		// deallocate memory
		delete [] xCoordinateArr;
		delete [] yCoordinateArr;
	
		delete [] squareArray;
		delete [] rectangleArray;
		delete [] circleArray;
		delete [] crossArray;
		
		exit(0);
	}
	
	return 0;
}

// display menu
void printMenu()
{
	// displays menu	
	cout << "Student ID	: 6959684" << endl;
	cout << "Student Name	: Natasha Jeng Yee Heng" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Welcome to Assn2 program!" << endl;
	cout << endl;
	cout << "1)	Input sensor data" << endl;
	cout << "2)	Compute area (for all records)" << endl;
	cout << "3)	Print shapes report" << endl;
	cout << "4)	Sort shape data" << endl;
	cout << "5)	Quit" << endl;
	cout << endl;
}

// prompt choice
int promptChoice()
{
	int choice;	
	cout << "Please enter your choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}
