/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#include "Circle.h"
#include <cmath>
#include <sstream>

// Default Constructor
Circle::Circle()
{
}

// Constructor
Circle::Circle (int xCoordinate, int yCoordinate, int radius)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->radius = radius;
}

// Getters
int Circle::getXCoordinate()
{
	return xCoordinate;
}

// Getters
int Circle::getYCoordinate()
{
	return yCoordinate;
}

// Getters
int Circle::getRadius()
{
	return radius;
}

// Setters
void Circle::setXCoordinate(int xCoordinate)
{
	this->xCoordinate = xCoordinate;
}

// Setters
void Circle::setYCoordinate(int yCoordinate)
{
	this->yCoordinate = yCoordinate;
}

// Setters
void Circle::setRadius(int radius)
{
	this->radius = radius;
}

// find perimeter points of circle
// x coordinates of
// north, south, east, west of mid point
vector <int> Circle::findPerimeterXPoints()
{
	vector <int> xCoordinatePerimeter;

	int northX = xCoordinate;
	xCoordinatePerimeter.push_back(northX);

	int southX = xCoordinate;
	xCoordinatePerimeter.push_back(southX);

	int eastX = xCoordinate + getRadius();
	xCoordinatePerimeter.push_back(eastX);
	
	int westX = xCoordinate - getRadius();
	xCoordinatePerimeter.push_back(westX);

	return xCoordinatePerimeter;
}

// find perimeter points of circle
// y coordinates of
// north, south, east, west of mid point
vector <int> Circle::findPerimeterYPoints()
{
	vector <int> yCoordinatePerimeter;

	int northY = yCoordinate + getRadius();
	yCoordinatePerimeter.push_back(northY);

	int southY = yCoordinate - getRadius();
	yCoordinatePerimeter.push_back(southY);

	int eastY = yCoordinate;
	yCoordinatePerimeter.push_back(eastY);
	
	int westY = yCoordinate;
	yCoordinatePerimeter.push_back(westY);

	return yCoordinatePerimeter;
}

// find x points inside Circle
vector <int> Circle::findXPointsWithinShape()
{
	int length = getRadius()*2;

	int x = xCoordinate - getRadius();

	// find x value of points inside circle
	vector <int> xPointsInShape;
	
	//find the smallset corner of Coordinates in Shape
	x++;

	tempCoordInShape.push_back(Coord());
	tempCoordInShape[0].xCoord=x;

	xPointsInShape.push_back(x);

	//incrementing x col by col
	if (length-1 != 0)
	{
		for (int i=1; i<length-1; i++)
		{	
			// find inner square bottom row coordinates
			x++;
			tempCoordInShape.push_back(Coord());
			tempCoordInShape[i].xCoord=x;
			xPointsInShape.push_back(tempCoordInShape[i].xCoord);
		}
	}

	//increment y row by row
	if (length-2 !=0)
	{
		for (int i=0; i<length-2; i++){
			for (int i=0; i<length-1; i++)
				xPointsInShape.push_back(tempCoordInShape[i].xCoord);	
		}
	}
	/*
	// print to check
	for (int i=0; i<xPointsInShape.size(); i++)
		cout << "point in shape x:" << xPointsInShape[i] << endl;
	*/
	return xPointsInShape;
}

// find y points inside Circle
vector <int> Circle::findYPointsWithinShape()
{
	int length = getRadius()*2;

	int y = yCoordinate - getRadius();
	
	// find y value of points inside circle
	vector <int> yPointsInShape;
	
	//find the smallset corner of Coordinates in Shape
	y++;

	yPointsInShape.push_back(y);

	//incrementing x col by col
	if (length-1 != 0)
	{
		for (int i=1; i<length-1; i++)
		{	
			// find inner square bottom row coordinates
			yPointsInShape.push_back(y);
		}
	}

	//increment y row by row
	if (length-2 !=0)
	{
		for (int i=0; i<length-2; i++){
			// moving in y direction upwards
			y++;
	
			for (int i=0; i<length-1; i++)
				//store incremented y	
				yPointsInShape.push_back(y);
			
		}
	}
	/*
	// print to check
	for (int i=0; i<yPointsInShape.size(); i++)
		cout << "point in shape y:" << yPointsInShape[i] << endl;
	*/
	return yPointsInShape;
}

// Public virtual member function
// Override parent function
string Circle::toString()
{
	string result;

	// From ShapeTwoD
	result = result + "Name : " + getName();
	result = result + "\n"; 
	result = result + "Special Type : " + getSpecialType();
	result = result + "\n"; 

	stringstream ss;
	ss << fixed << setprecision(2) << getArea();
	result = result + "Area : " + ss.str() + " units";
	result = result + "\n"; 
	
	// Circle center coordinates
	result = result + "Point [0] : (" + to_string(xCoordinate);
	result = result + ", " + to_string(yCoordinate) + ")" + "\n";

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
	
	vector <int> xPointsInShape = findXPointsWithinShape();
	vector <int> yPointsInShape = findYPointsWithinShape();

	result = result + "Points within shape : ";
	
	for (int i=0; i<xPointsInShape.size(); i++)
	{
		result = result + "(";
		result = result + to_string(xPointsInShape[i]) + ", ";
		result = result + to_string(yPointsInShape[i]) + ")";
		if (i != xPointsInShape.size()-1)
			result = result + ", ";
	}

	return result;
}

// Public virtual member function
// Override parent function
double Circle::computeArea()
{
	return 3.14 * getRadius() * getRadius();
}

// Public virtual member function
// Override parent function
bool Circle::isPointInShape(int x, int y)
{
	int distance;
	distance = (getRadius() * getRadius()) - (((getXCoordinate()-x)*(getXCoordinate()-x)) + ((getYCoordinate()-y)*(getYCoordinate()-y)));

	// distance between point's x,y and center x,y is less than radius
	// point is inside circle
	if (distance < 0)
		return true;
	// distance is greater than radius
	// point is outside circle
	else 
		return false;
	
}

// Public virtual member function
// Override parent functions
bool Circle::isPointOnShape(int x, int y)
{
	int distance;
	distance = (getRadius() * getRadius()) - (((getXCoordinate()-x)*(getXCoordinate()-x)) + ((getYCoordinate()-y)*(getYCoordinate()-y)));

	// distance between point's x,y and center x,y is equal to radius
	// point is on circumference of circle
	if (distance == 0)
		return true;
	
	else
		return false;
}
