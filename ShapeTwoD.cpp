/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#include "ShapeTwoD.h"

// Default Constructor
ShapeTwoD::ShapeTwoD()
{
}

// Constructor
ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
	this->name = name; 
	this->containsWarpSpace = containsWarpSpace;
}

// Constructor
ShapeTwoD::ShapeTwoD(int shapeID, string name, string specialType)
{
	this->shapeID = shapeID;
	this->name = name; 
	this->specialType = specialType;
}

// Getter
int ShapeTwoD::getShapeID()
{
	return shapeID;
}

// Getter
string ShapeTwoD::getName()
{
	return name;
}

// Getter
bool ShapeTwoD::getContainsWarpSpace()
{
	return containsWarpSpace;
}

// Getter
string ShapeTwoD::getSpecialType()
{
	return specialType;
}

// Getter
double ShapeTwoD::getArea()
{
	return area;
}

// Setter
void ShapeTwoD::setShapeID(int shapeID)
{
	this->shapeID = shapeID;
}

// Setter
void ShapeTwoD::setName(string name)
{
	this->name = name;
}

// Setter
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
}

// Setter
void ShapeTwoD::setSpecialType(string specialType)
{
	this->specialType = specialType;
}

// Setter
void ShapeTwoD::setArea(double area)
{
	this->area = area;
}

// Public virtual member function
string ShapeTwoD::toString()
{
	// values of attribute in shape, exclude vertex data
	// name, special type, area
	string result;
	result = result + "Name : " + getName() + "\n";
	result = result + "Special Type : " + getSpecialType() + "\n";


	if (getName() == "Circle")
	{
		result = result + "Area : " +  to_string(getArea()) + " units";
	}
	else
		result = result + "Area : " + to_string((int)getArea()) + " units square";
	return result;
}

// Public virtual member function
// to be overriden by children classes
double ShapeTwoD::computeArea()
{
	return 0.0;
}

// Public virtual member function
// to be overriden by children classes
bool ShapeTwoD::isPointInShape(int x, int y)
{
	return false;
}

// Public virtual member function
// to be overriden by children classes
bool ShapeTwoD::isPointOnShape(int x, int y)
{
	return false;
}
