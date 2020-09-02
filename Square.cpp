/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#include "Square.h"
#include <cmath>
#include <algorithm>

using namespace std;

// Default Constructor
Square::Square()
{
}

// Constructor
Square::Square (int *xCoordinateArr, int *yCoordinateArr)
{
	this->xCoordinateArr = new int[4];
	this->yCoordinateArr = new int[4];

	for (int i=0; i<4; i++)
	{
		this->xCoordinateArr[i] = xCoordinateArr[i];
		this->yCoordinateArr[i] = yCoordinateArr[i];
	}
}

// Destructor
Square::~Square()
{
	delete [] xCoordinateArr;
	delete [] yCoordinateArr;
}


// Getters
int * Square::getXCoordinateArr()
{
	return xCoordinateArr;
}

// Getters
int * Square::getYCoordinateArr()
{
	return yCoordinateArr;
}


// Setters
void Square::setXCoordinateArr(int *xCoordinateArr)
{
	this->xCoordinateArr = new int[4];
	for (int i=0; i<4; i++)
	{
		this->xCoordinateArr[i] = xCoordinateArr[i];
	}
}

// Setters
void Square::setYCoordinateArr(int *yCoordinateArr)
{
	this->yCoordinateArr = new int[4];
	for (int i=0; i<4; i++)
	{
		this->yCoordinateArr[i] = yCoordinateArr[i];
	}
}


// note: square all sides are equal
double Square::findLength()
{
	return (biggestX() - smallestX());
}

// Loop through all values of X
int Square::biggestX()
{
	int temp = xCoordinateArr[0];
	for (int i=0; i<sizeof(xCoordinateArr)-1; i++)
	{
		// biggest x value
		if (temp < xCoordinateArr[i])
			temp = xCoordinateArr[i];
	}
	return temp;
}

// Loop through all values of Y
int Square::biggestY()
{
	int temp = yCoordinateArr[0];
	for (int i=0; i<sizeof(yCoordinateArr)-1; i++)
	{
		// biggest y value
		if (temp < yCoordinateArr[i])
			temp = yCoordinateArr[i];
	}
	return temp;
}

// Loop through all values of X
int Square::smallestX()
{
	int temp = xCoordinateArr[0];
	for (int i=0; i<sizeof(xCoordinateArr)-1; i++)
	{
		// smallest x value
		if (temp > xCoordinateArr[i])
			temp = xCoordinateArr[i];
	}
	return temp;
}

// Loop through all values of Y
int Square::smallestY()
{
	int temp = yCoordinateArr[0];
	for (int i=0; i<sizeof(yCoordinateArr)-1; i++)
	{
		// smallest y value
		if (temp > yCoordinateArr[i])
			temp = yCoordinateArr[i];
	}
	return temp;
}

// Find points in between two corners
// X values
vector <int> Square::findPerimeterXPoints()
{
	double length = findLength();
	int noOfPointsBetween = length - 1;

	vector<int> xCoordinatePerimeter;

	// smallest coordinate moving in y direction upwards
	for (int i=0; i<noOfPointsBetween; i++)
	{
		xCoordinatePerimeter.push_back(smallestX());
	}
	
	// smallest coordinate moving in x direction right
	int tempX = smallestX();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempX++;
		xCoordinatePerimeter.push_back(tempX);
	}
	
	// biggest coordinate moving in x direction left 
	tempX = biggestX();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempX--;
		xCoordinatePerimeter.push_back(tempX);
	}

	// biggest coordinate moving in y direction downwards 
	for (int i=0; i<noOfPointsBetween; i++)
	{
		xCoordinatePerimeter.push_back(biggestX());
	}

	return xCoordinatePerimeter;
}

// Find points in between two corners
// Y values
vector <int> Square::findPerimeterYPoints()
{
	double length = findLength();
	int noOfPointsBetween = length - 1;

	vector<int> yCoordinatePerimeter;

	// smallest coordinate moving in y direction upwards
	int tempY = smallestY();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempY++;
		yCoordinatePerimeter.push_back(tempY);
	}
	
	// smallest coordinate moving in x direction right
	for (int i=0; i<noOfPointsBetween; i++)
	{
		yCoordinatePerimeter.push_back(smallestY());
	}
	
	// biggest coordinate moving in x direction left 
	for (int i=0; i<noOfPointsBetween; i++)
	{
		yCoordinatePerimeter.push_back(biggestY());
	}

	// biggest coordinate moving in y direction downwards 
	tempY = biggestY();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempY--;
		yCoordinatePerimeter.push_back(tempY);
	}

	return yCoordinatePerimeter;
}

// find X points inside square
vector <int> Square::findXPointsWithinShape()
{
	int length = findLength();

	int x = smallestX();

	// store X points inside square
	vector <int> xPointsInSquare;
	
	//find the smallset corner of Coordinates in Shape
	x++;
	
	xPointsInSquare.push_back(x);

	//incrementing x col by col
	if (length-1 != 0)
	{
		for (int i=1; i<length-1; i++)
		{	
			// find inner square bottom row coordinates
			x++;
			xPointsInSquare.push_back(x);
		}
	}

	//increment y row by row
	if (length-2 != 0)
	{
		for (int i=0; i<length-2; i++){
			for (int i=0; i<length-1; i++)
				//reuse same x value from above
				xPointsInSquare.push_back(x);
		}
	}
	
	return xPointsInSquare;
}

// find y points inside square
vector <int> Square::findYPointsWithinShape()
{
	int length = findLength();

	int y = smallestY();

	// store Y points inside square
	vector <int> yPointsInSquare;
	
	//find the smallset corner of Coordinates in Shape
	y++;
	
	yPointsInSquare.push_back(y);
	

	//incrementing x col by col
	for (int i=1; i<length-1; i++)
	{	
		// find inner square bottom row coordinates
		yPointsInSquare.push_back(y);
	}

	//increment y row by row
	for (int i=0; i<length-2; i++){
		// moving in y direction upwards
		y++;
	
		for (int i=0; i<length-1; i++)
		{	
			//store incremented y
			yPointsInSquare.push_back(y);
		}
	}
	return yPointsInSquare;
}

// Public virtual member function
// Override parent function
string Square::toString()
{
	string result;

	// From ShapeTwoD
	result = result + "Name : " + getName();
	result = result + "\n"; 
	result = result + "Special Type : " + getSpecialType();
	result = result + "\n"; 
	result = result + "Area : " + to_string((int)getArea()) + " units square";
	result = result + "\n"; 

	result = result + "Vertices :";
	result = result + "\n"; 
	// values of vertex data
	for (int i=0; i<4; i++)
	{
		result = result + "Point [" + to_string(i) + "] : (" + to_string(this->xCoordinateArr[i]);
		result = result + ", " + to_string(this->yCoordinateArr[i]) + ")" + "\n";
	}

	result = result + "\n"; 

	result = result + "Points on perimeter : ";

	if (findPerimeterXPoints().size() == 0)
		result =  result + "none!" + "\n";
	else
	{
		for (int i=0; i<findPerimeterXPoints().size(); i++)
		{
			result =  result + "(";
			result =  result + to_string(findPerimeterXPoints()[i]) + ", ";
			result =  result + to_string(findPerimeterYPoints()[i]) + ")";

			if (i != findPerimeterXPoints().size()-1)
				result = result + ", ";
		}
		result = result + "\n";
	}	

	result = result + "\n"; 

	int length = findLength();

	vector<int> xPointsInSquare = findXPointsWithinShape();
	vector<int> yPointsInSquare = findYPointsWithinShape();

	result = result + "Points within shape : ";
	if (length == 1)
	{
		result = result + "none!" + "\n";
	}
	else 
	{
		for (int i=0; i<xPointsInSquare.size(); i++)
		{
			result = result + "(";
			result = result + to_string(xPointsInSquare[i]) + ", ";
			result = result + to_string(yPointsInSquare[i]) + ")";
			if (i != xPointsInSquare.size()-1)
				result = result + ", ";
		}
		result = result + "\n";
	}

	return result;
}

// Public virtual member function
// Override parent function
double Square::computeArea()
{
	return findLength() * findLength();
}

// Public virtual member function
// Override parent function
bool Square::isPointInShape(int x, int y)
{
	if (x > smallestX() && x < biggestX() && y > smallestX() && y < biggestY())
		return true;
	else
		return false;
}

// Public virtual member function
// Override parent functions
// If point is on perimeter, it is on shape
bool Square::isPointOnShape(int x, int y)
{
	vector <int> xCoordinatePerimeter = findPerimeterXPoints();
	vector <int> yCoordinatePerimeter = findPerimeterYPoints();

	for (int i=0; i<xCoordinatePerimeter.size(); i++)
	{
		if (xCoordinatePerimeter[i] == x && yCoordinatePerimeter[i] == y)
			return true;
		else	
			return false;
	}
}
