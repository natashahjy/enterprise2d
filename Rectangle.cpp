/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#include "Rectangle.h"
#include <cmath>
#include <iostream>

// Default Constructor
Rectangle::Rectangle()
{
}

// Constructor
Rectangle::Rectangle (int *xCoordinateArr, int *yCoordinateArr)
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
Rectangle::~Rectangle()
{
	delete [] xCoordinateArr;
	delete [] yCoordinateArr;
}


// Getters
int * Rectangle::getXCoordinateArr()
{
	return xCoordinateArr;
}

// Getters
int * Rectangle::getYCoordinateArr()
{
	return yCoordinateArr;
}


// Setters
void Rectangle::setXCoordinateArr(int *xCoordinateArr)
{
	this->xCoordinateArr = new int[4];
	for (int i=0; i<4; i++)
	{
		this->xCoordinateArr[i] = xCoordinateArr[i];
	}
}

// Setters
void Rectangle::setYCoordinateArr(int *yCoordinateArr)
{
	this->yCoordinateArr = new int[4];
	for (int i=0; i<4; i++)
	{
		this->yCoordinateArr[i] = yCoordinateArr[i];
	}
}


// note: two lengths are equal
// two breadths are equal
double Rectangle::findXLength()
{
	return (biggestX() - smallestX());
}

double Rectangle::findYLength()
{
	return (biggestY() - smallestY());
}


// Loop through all values of X
int Rectangle::biggestX()
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
int Rectangle::biggestY()
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
int Rectangle::smallestX()
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
int Rectangle::smallestY()
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
vector <int> Rectangle::findPerimeterXPoints()
{
	double xLength = findXLength();
	double yLength = findYLength();

	int noOfPointsBetween = yLength - 1;

	vector<int> xCoordinatePerimeter;

	// using yLength 
	// smallest coordinate moving in y direction upwards
	for (int i=0; i<noOfPointsBetween; i++)
	{
		xCoordinatePerimeter.push_back(smallestX());
	}
	
	// using yLength
	// biggest coordinate moving in y direction downwards
	for (int i=0; i<noOfPointsBetween; i++)
	{
		xCoordinatePerimeter.push_back(biggestX());
	}

	noOfPointsBetween = xLength - 1;

	// using xLength
	// biggest coordinate moving in x direction left
	int tempX = biggestX();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempX--;
		xCoordinatePerimeter.push_back(tempX);
	}

	// using xLength
	// smallest coordinate moving in x direction right
	tempX = smallestX();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempX++;
		xCoordinatePerimeter.push_back(tempX);
	}

	return xCoordinatePerimeter;
}

// Find points in between two corners
// Y values
vector <int> Rectangle::findPerimeterYPoints()
{
	double xLength = findXLength();
	double yLength = findYLength();

	int noOfPointsBetween = yLength - 1;

	vector<int> yCoordinatePerimeter;

	// using yLength 
	// smallest coordinate moving in y direction upwards
	int tempY = smallestY();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempY++;
		yCoordinatePerimeter.push_back(tempY);
	}
	
	// using yLength
	// biggest coordinate moving in y direction downwards
	tempY = biggestY();
	for (int i=0; i<noOfPointsBetween; i++)
	{
		tempY--;
		yCoordinatePerimeter.push_back(tempY);
	}

	noOfPointsBetween = xLength - 1;

	// using xLength
	// biggest coordinate moving in x direction left
	for (int i=0; i<noOfPointsBetween; i++)
	{
		yCoordinatePerimeter.push_back(biggestY());
	}

	// using xLength
	// smallest coordinate moving in x direction right
	for (int i=0; i<noOfPointsBetween; i++)
	{
		yCoordinatePerimeter.push_back(smallestY());
	}

	return yCoordinatePerimeter;
}

// finds x points in rectangle
vector <int> Rectangle::findXPointsWithinShape()
{
	int xLength = findXLength(); 
	int yLength = findYLength(); 

	// store x points in rectangle
	vector <int> xPointsInRectangle;

	int difference;
	// find number of times to loop in y direction
	// based on orientation of rectangle (vertical/horizontal)
	if (xLength > yLength) 
		difference = 0;
	else
		difference = 2;

	int x = smallestX(); 
	
	//find the smallset corner of Coordinates in Shape
	x++;
	
	xPointsInRectangle.push_back(x);

	//incrementing x col by col
	if (xLength-1 != 0)
	{
		for (int i=1; i<xLength-1; i++) 
		{	
			// find inner square bottom row coordinates
			x++;
			xPointsInRectangle.push_back(x); 
		}
	}

	//increment y row by row
	if (yLength-2 !=0)
	{
		for (int i=0; i<yLength-2; i++){
			// moving in y direction upwards
			for (int i=0; i<yLength-difference; i++)
				xPointsInRectangle.push_back(x); 
		}
	}
	/*
	for (int i=0; i<xPointsInRectangle.size(); i++)
		cout << "xpointsinrectangle" << xPointsInRectangle[i] << endl;
	*/
	return xPointsInRectangle;
}


// finds y points in rectangle
vector <int> Rectangle::findYPointsWithinShape()
{
	int xLength = findXLength(); 
	int yLength = findYLength(); 

	// store y points in rectangle
	vector <int> yPointsInRectangle;

	int difference;
	// find number of times to loop in y direction
	// based on orientation of rectangle (vertical/horizontal)
	if (xLength > yLength) 
		difference = 0;
	else
		difference = 2;

	int x = smallestX(); 
	int y = smallestY(); 
	
	//find the smallset corner of Coordinates in Shape
	x++;
	y++;
	
	yPointsInRectangle.push_back(y);
	
	//incrementing x col by col
	if (xLength-1 !=0)
	{
		for (int i=1; i<xLength-1; i++) 
		{	
			// find inner square bottom row coordinates
			yPointsInRectangle.push_back(y);
		}
	}
	//increment y row by row
	if (yLength-2 !=0)
	{
		for (int i=0; i<yLength-2; i++){
			// moving in y direction upwards
			y++;
	
			for (int i=0; i<yLength-difference; i++)	
				//store incremented y
				yPointsInRectangle.push_back(y);
		}
	}
	
	/*
	for (int i=0; i<yPointsInRectangle.size(); i++)
		cout << "ypointsinrectangle" << yPointsInRectangle[i] << endl;
	*/
	return yPointsInRectangle;
}

// Public virtual member function
// Override parent function
string Rectangle::toString()
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

	vector <int> xPointsInRectangle = findXPointsWithinShape();
	vector <int> yPointsInRectangle = findYPointsWithinShape();

	// Printing:
	result = result + "Points within shape : ";
	if (findXLength() == 1 || findYLength() == 1)
	{
		result = result + "none!" + "\n";
		
	} 
	else 
	{
		for (int i=0; i<xPointsInRectangle.size(); i++)
		{
			result = result + "(";
			result = result + to_string(xPointsInRectangle[i]) + ", ";
			result = result + to_string(yPointsInRectangle[i]) + ")";
			if (i != xPointsInRectangle.size()-1)
				result = result + ", ";
		}
	}
	return result;
}

// Public virtual member function
// Override parent function
double Rectangle::computeArea()
{
	return abs(findXLength() * findYLength());
}

// Public virtual member function
// Override parent function
bool Rectangle::isPointInShape(int x, int y)
{
	if (x > smallestX() && x < biggestX() && y > smallestX() && y < biggestY())
		return true;
	else
		return false;
}

// Public virtual member function
// Override parent functions
bool Rectangle::isPointOnShape(int x, int y)
{
	// left hand side test
	int distance;
	distance = (findXLength() * (y - smallestY())) - ((x-smallestX()) * findYLength());
	if (distance == 0)
		return true;
	else
		return false;
}
