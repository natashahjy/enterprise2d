/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#include "Cross.h"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

// Default Constructor
Cross::Cross()
{}

// Constructor
Cross::Cross (int *xCoordinateArr, int *yCoordinateArr)
{
	this->xCoordinateArr = new int[12];
	this->yCoordinateArr = new int[12];

	for (int i=0; i<12; i++)//loops through 12 vertices
	{
		this->xCoordinateArr[i] = xCoordinateArr[i];
		this->yCoordinateArr[i] = yCoordinateArr[i];
	}
}

// Destructor
Cross::~Cross()
{
	delete [] xCoordinateArr;
	delete [] yCoordinateArr;
}

// Getters
int * Cross::getXCoordinateArr()
{
	return xCoordinateArr;
}

// Getters
int * Cross::getYCoordinateArr()
{
	return yCoordinateArr;
}

// Setters
void Cross::setXCoordinateArr(int *xCoordinateArr)
{
	this->xCoordinateArr = new int[12];
	for (int i=0; i<12; i++)
	{
		this->xCoordinateArr[i] = xCoordinateArr[i];
	}
}

// Setters
void Cross::setYCoordinateArr(int *yCoordinateArr)
{
	this->yCoordinateArr = new int[12];
	for (int i=0; i<12; i++)
	{
		this->yCoordinateArr[i] = yCoordinateArr[i];
	}
}


// Find biggest X value
// Loop through all values of X
int Cross::biggestX()
{
	int temp = xCoordinateArr[0];
	for (int i=0; i<12; i++)
	{
		// biggest x value
		if (temp < xCoordinateArr[i])
			temp = xCoordinateArr[i];
	}

	return temp;//temp
}

// Find biggest Y value
// Loop through all values of Y
int Cross::biggestY()
{
	int temp = yCoordinateArr[0];
	for (int i=0; i<12; i++)
	{
		// biggest x value
		if (temp < yCoordinateArr[i])
			temp = yCoordinateArr[i];
	}
	return temp;
}

// Find smallest X value
// Loop through all values of X
int Cross::smallestX()
{
	int temp = xCoordinateArr[0];
	for (int i=0; i<12; i++)
	{
		// smallest x value
		if (temp > xCoordinateArr[i])
			temp = xCoordinateArr[i];
	}
	return temp;
}

// Find smallest Y value
// Loop through all values of Y
int Cross::smallestY()
{
	int temp = yCoordinateArr[0];
	for (int i=0; i<12; i++)
	{
		// smallest y value
		if (temp > yCoordinateArr[i])
			temp = yCoordinateArr[i];
	}
	return temp;
}

// find the length of each side
vector <int> Cross::findSideLength()
{
	// store length of each side of Cross
	vector <int> sideLength; // each side is made of 2 adjacent points
	// find the length of each side
	for (int i=0; i<12; i++)
	{
		// counter for next value in array
		int nextValue = i+1;
		// figure goes back to first point
		if (i+1 == 12)
			nextValue = 0;
			
		sideLength.push_back(findLength(xCoordinateArr[i], xCoordinateArr[nextValue], yCoordinateArr[i], yCoordinateArr[nextValue]));
	}
	return sideLength;
}

// find if each side has change in x value
vector<int> Cross::findXValueChanges()
{
	// store if x value changes/not 
	vector <int> xValueChanges;

	// find if each side has change in x value
	for (int i=0; i<12; i++)
	{
		// counter for next value in array
		int nextValue = i+1;
		// figure goes back to first point
		if (i+1 == 12)
			nextValue = 0;

		xValueChanges.push_back(findXDirectionChange(xCoordinateArr[i], xCoordinateArr[nextValue]));
	}
	
	return xValueChanges;
}

// find if each side has change in y value
vector<int> Cross::findYValueChanges()
{
	// store if y value changes/not 
	vector <int> yValueChanges;

	// find if each side has change in y value
	for (int i=0; i<12; i++)
	{
		// counter for next value in array
		int nextValue = i+1;
		// figure goes back to first point
		if (i+1 == 12)
			nextValue = 0;

		yValueChanges.push_back(findYDirectionChange(yCoordinateArr[i], yCoordinateArr[nextValue]));
	}
	return yValueChanges;
}

vector <int> Cross::findXPerimeter()
{
	// store length of each side of Cross
	vector <int> sideLength = findSideLength();
	
	// store if x value changes/not 
	vector <int> xValueChanges = findXValueChanges();

	// store perimeter x values
	vector <int> xPerimeterPoints;

	// find perimeter point values
	for (int i=0; i<12; i++)
	{
		// counter for next value in array
		int nextValue = i+1;
		// figure goes back to first point
		if (i+1 == 12)
			nextValue = 0;
		
		// if a side length is greater than 1, there will be points in between
		if (sideLength[i] > 1)
		{
			for (int j=0; j<sideLength[i]-1; j++)
			{
				// xPerimeterPoints
				// the checks determines the first value passed into function
				if (xCoordinateArr[i] < xCoordinateArr[nextValue])
				{
					xPerimeterPoints.push_back(findPointXCoordinate(xCoordinateArr[i] + j, xCoordinateArr[nextValue], xValueChanges[i]));					
				}

				else if (xCoordinateArr[i] == xCoordinateArr[nextValue])
				{
					xPerimeterPoints.push_back(findPointXCoordinate(xCoordinateArr[i], xCoordinateArr[nextValue], xValueChanges[i]));
				}

				else
				{
					xPerimeterPoints.push_back(findPointXCoordinate(xCoordinateArr[i] - j, xCoordinateArr[nextValue], xValueChanges[i]));
				}

			}
		}
	}

	return xPerimeterPoints;
}

vector <int> Cross::findYPerimeter()
{
	// store length of each side of Cross
	vector <int> sideLength = findSideLength();

	// store if y value changes/not 
	vector <int> yValueChanges = findYValueChanges();

	// store perimeter y values
	vector <int> yPerimeterPoints;

	// find perimeter point values
	for (int i=0; i<12; i++)
	{
		// counter for next value in array
		int nextValue = i+1;
		// figure goes back to first point
		if (i+1 == 12)
			nextValue = 0;
		
		// if a side length is greater than 1, there will be points in between
		if (sideLength[i] > 1)
		{
			for (int j=0; j<sideLength[i]-1; j++)
			{
				// yPerimeterPoints
				// the checks determines the first value passed into function
				if (yCoordinateArr[i] < yCoordinateArr[nextValue])
				{
					yPerimeterPoints.push_back(findPointYCoordinate(yCoordinateArr[i] + j, yCoordinateArr[nextValue], yValueChanges[i]));					
				}
				
				else if (yCoordinateArr[i] == yCoordinateArr[nextValue])
				{
					yPerimeterPoints.push_back(findPointYCoordinate(yCoordinateArr[i], yCoordinateArr[nextValue], yValueChanges[i]));
				}

				else 
				{
					yPerimeterPoints.push_back(findPointYCoordinate(yCoordinateArr[i] - j, yCoordinateArr[nextValue], yValueChanges[i]));
				}
			}
		}
	}
	return yPerimeterPoints;
}

// find length of each side
int Cross::findLength(int x1, int x2, int y1, int y2)
{
	if (x2-x1 == 0)
		return (abs(y2-y1));
	else
		return (abs(x2-x1));
}

// determine if each side x changes or not
bool Cross::findXDirectionChange(int x1, int x2)
{
	// if x change its true
	// if x dont change its false 
	if (x2 - x1 == 0)
		return false;
	else
		return true;
}

// determine if each side y changes or not
bool Cross::findYDirectionChange(int y1, int y2)
{
	// if y change its true
	// if y dont change its false 
	if (y2 - y1 == 0)
		return false;
	else
		return true;
}

// if xChange is true
int Cross::findPointXCoordinate(int x1, int x2, int xChange)
{
	if (xChange == 1)
		if (x1 < x2)
			return x1 + 1;
		else 
			return x1 - 1;
	else
		return x1;
}

// if yChange is true
int Cross::findPointYCoordinate(int y1, int y2, int yChange)
{
	if (yChange == 1)
		if (y1 < y2)
			return y1 + 1;
		else 
			return y1 - 1;
	else
		return y1;
}

// Bottom Left
double Cross::findBottomLeftArea()
{
	// Bottom Left
	int x = smallestX(); // 0
	int y = smallestY(); // 0

	// Bottom Left Points
	struct Coord matchCoordX[2]; // store all possible points on line	
	struct Coord matchCoordY[2];
	int counterX = 0;
	int counterY = 0;

	for (int i=0; i<12; i++)
	{
		// Check against Bottom Left's x
		if (x == xCoordinateArr[i]) 
		{
			matchCoordX[counterX].xCoord = xCoordinateArr[i];
			matchCoordX[counterX].yCoord = yCoordinateArr[i];
			counterX++;
		} 
		// Check against Bottom Left's y
		else if(y == yCoordinateArr[i]) 
		{ 
			matchCoordY[counterY].xCoord = xCoordinateArr[i];
			matchCoordY[counterY].yCoord = yCoordinateArr[i];
			counterY++;
		} 
	}
	int nearestHorizontalPoint;
	int nearestVerticalPoint;
	// Looking for point closest to Bottom Left
	// Next nearest value to Bottom Left coordinates in y direction
	if (matchCoordX[0].yCoord < matchCoordX[1].yCoord)
		nearestVerticalPoint = matchCoordX[0].yCoord; 	
	else
		nearestVerticalPoint = matchCoordX[1].yCoord;
	// Check next nearest value to Bottom Left coordinates in x direction
	if (matchCoordY[0].xCoord < matchCoordY[1].xCoord)
		nearestHorizontalPoint = matchCoordY[0].xCoord;
		
	else
		nearestHorizontalPoint = matchCoordY[1].xCoord;
	
	// find Bottom Left Shape Area
	double bottomLeftArea = abs(nearestHorizontalPoint-x) * abs(nearestVerticalPoint-y);
	
	return bottomLeftArea;
}
// Top Left
double Cross::findTopLeftArea()
{
	// Top Left
	int x = smallestX();
	int y = biggestY();

	// Top Left Points
	struct Coord matchCoordX[2]; // store all possible points on line	
	struct Coord matchCoordY[2];
	int counterX = 0;
	int counterY = 0;

	for (int i=0; i<12; i++)
	{
		// Check against Top Left's x
		if (x == xCoordinateArr[i]) // (1, 2) (1, 3)
		{
			matchCoordX[counterX].xCoord = xCoordinateArr[i];
			matchCoordX[counterX].yCoord = yCoordinateArr[i];
			counterX++;
		}
		// Check against Top Left's y
		else if(y == yCoordinateArr[i]) // (3, 5) (4, 5)
		{
			matchCoordY[counterY].xCoord = xCoordinateArr[i];
			matchCoordY[counterY].yCoord = yCoordinateArr[i];
			counterY++;
		}
	}
	int nearestHorizontalPoint=0;
	int nearestVerticalPoint=0;
	// Looking for point closest to Top Left
	// Next nearest value to Top Left coordinates in y direction
	if (matchCoordX[0].yCoord > matchCoordX[1].yCoord) // (1, 2) (1 ,3)
		nearestVerticalPoint = matchCoordX[0].yCoord; 
	else
		nearestVerticalPoint = matchCoordX[1].yCoord; // 3
	// Check next nearest value to Top Left coordinates in x direction
	if (matchCoordY[0].xCoord < matchCoordY[1].xCoord) // (3, 5) (4, 5)
		nearestHorizontalPoint = matchCoordY[0].xCoord; // 3
	else
		nearestHorizontalPoint = matchCoordY[1].xCoord;

	// find Top Left Shape Area
	double topLeftArea = abs(nearestHorizontalPoint-x) * abs(nearestVerticalPoint-y);

	return topLeftArea;
}

// Top Right
double Cross::findTopRightArea()
{
	// Top Right
	int x = biggestX();
	int y = biggestY();

	// Top Right Points
	struct Coord matchCoordX[2]; // store all possible points on line	
	struct Coord matchCoordY[2];
	int counterX = 0;
	int counterY = 0;

	for (int i=0; i<12; i++)
	{
		// Check against Top Right's x
		if (x == xCoordinateArr[i]) // (5,3) (5,2)
		{
			matchCoordX[counterX].xCoord = xCoordinateArr[i];
			matchCoordX[counterX].yCoord = yCoordinateArr[i];
			counterX++;
		}
		// Check against Top Right's y
		else if(y == yCoordinateArr[i]) // (3,5) (4,5)
		{
			matchCoordY[counterY].xCoord = xCoordinateArr[i];
			matchCoordY[counterY].yCoord = yCoordinateArr[i];
			counterY++;
		}
	}
	int nearestHorizontalPoint;
	int nearestVerticalPoint;
	// Looking for point closest to Top Right
	// Check next nearest value to Bottom Left coordinates in x direction
	if (matchCoordX[0].yCoord > matchCoordX[1].yCoord) 
		nearestVerticalPoint = matchCoordX[0].yCoord; 
	else
		nearestVerticalPoint = matchCoordX[1].yCoord;
	// Next nearest value to Top Right coordinates in y direction
	if (matchCoordY[0].xCoord > matchCoordY[1].xCoord) 
		nearestHorizontalPoint = matchCoordY[0].xCoord;
	else
		nearestHorizontalPoint = matchCoordY[1].xCoord; 
	

	// find Top Right Shape Area
	int topRightArea = abs(nearestHorizontalPoint-x) * abs(nearestVerticalPoint-y);
	return topRightArea;
}


// Bottom Right
double Cross::findBottomRightArea()
{
	// Bottom Right
	int x = biggestX();
	int y = smallestY();

	// Bottom Left Points
	struct Coord matchCoordX[2]; // store all possible points on line	
	struct Coord matchCoordY[2];
	int counterX = 0;
	int counterY = 0;

	for (int i=0; i<12; i++)
	{
		// Check against Bottom Right's x 
		if (x == xCoordinateArr[i]) 
		{
			matchCoordX[counterX].xCoord = xCoordinateArr[i];
			matchCoordX[counterX].yCoord = yCoordinateArr[i];
			counterX++;
		}
		// Check against Bottom Right's y
		else if(y == yCoordinateArr[i])
		{
			matchCoordY[counterY].xCoord = xCoordinateArr[i];
			matchCoordY[counterY].yCoord = yCoordinateArr[i];
			counterY++;
		}
	}
	int nearestHorizontalPoint;
	int nearestVerticalPoint;
	// Looking for point closest to Bottom Right
	// Next nearest value to Bottom Right coordinates in y direction
	if (matchCoordX[0].yCoord < matchCoordX[1].yCoord)
		nearestVerticalPoint = matchCoordX[0].yCoord; 
	else 
		nearestVerticalPoint = matchCoordX[1].yCoord;
	// Check next nearest value to Bottom Right coordinates in x direction
	if (matchCoordY[0].xCoord > matchCoordY[1].xCoord)
		nearestHorizontalPoint = matchCoordY[0].xCoord;
	else
		nearestHorizontalPoint = matchCoordY[1].xCoord;

	// find Bottom Right Shape Area
	double bottomRightArea = abs(nearestHorizontalPoint-x) * abs(nearestVerticalPoint-y);

	return bottomRightArea;
}


// filter by y axis (starting from smallestY to biggestY)
// perimeter & vertices makes up boundary
// get x values
vector <int> Cross::findBoundaryXValues(int start)
{
	// store perimeter x values
	vector <int> xPerimeterPoints = findXPerimeter();

	// store perimeter y values
	vector <int> yPerimeterPoints = findYPerimeter();
	
	// boundary x values
	vector <int> boundaryXValues;

	// loop through vertices
	for (int i=0; i<12; i++)
	{
		if (yCoordinateArr[i] == start)
		{
			boundaryXValues.push_back(xCoordinateArr[i]);
		}
	} 

	// loop through perimeter points
	for (int j=0; j<xPerimeterPoints.size(); j++)
	{
		if (yPerimeterPoints[j] == start)
		{
			boundaryXValues.push_back(xPerimeterPoints[j]);
		}
	}

	return boundaryXValues;
}


// filter by y axis (starting from smallestY to biggestY)
// perimeter & vertices makes up boundary
// get y values
vector <int> Cross::findBoundaryYValues(int start)
{
	// perimeterPoints
	// store perimeter y values
	vector <int> yPerimeterPoints = findYPerimeter();
	
	// boundary y values
	vector <int> boundaryYValues;

	// loop through vertices
	for (int i=0; i<12; i++)
	{
		if (yCoordinateArr[i] == start)
		{
			boundaryYValues.push_back(yCoordinateArr[i]);
		}
	} 

	// loop through perimeter points
	for (int j=0; j<yPerimeterPoints.size(); j++)
	{
		if (yPerimeterPoints[j] == start)
		{
			boundaryYValues.push_back(yPerimeterPoints[j]);
		}
	}
		
	return boundaryYValues;
}

// filter by y axis (starting from smallestY to biggestY)
// using vertices and perimeter points
// find X value of point(s) in between
vector <int> Cross::findXPointsInBetweenTwoVertices(vector<int> boundaryXValues)
{
	// find points in between
	int pointsInBetweenCounter = 0;
	vector <int> xPointsInBetween;

	// smallest x on yth row
	// setting to default values
	int smallX = boundaryXValues[0];

	// biggest x on yth row
	int bigX = boundaryXValues[0]; 

	// sorting
	for (int i=smallestX(); i<boundaryXValues.size(); i++)
	{
		if (boundaryXValues[i] < smallX) 
			smallX = boundaryXValues[i];

		if (boundaryXValues[i] > bigX)
			bigX = boundaryXValues[i];
	}

	// eg.
	// smallX = 1
	// pointsInBetweenX (2,3,4,5,6,7)
	// bigX = 8
	for (int i=smallX; i<bigX-1; i++)
	{
		xPointsInBetween.push_back(smallX+pointsInBetweenCounter + 1);
		pointsInBetweenCounter++;
	}

	return xPointsInBetween;
}

// filter by y axis (starting from smallestY to biggestY)
// using vertices and perimeter points
// find Y value of point(s) in between
vector <int> Cross::findYPointsInBetweenTwoVertices(int start, vector<int> boundaryXValues)
{
	// find points in between
	vector <int> yPointsInBetween;

	// smallest x on yth row
	// setting to default values
	int smallX = boundaryXValues[0];
	//int smallY = smallestY();
	int smallY = start;

	// biggest x on yth row
	int bigX = boundaryXValues[0]; 
	//int bigY = smallestY(); 
	int bigY = start;

	// sorting
	for (int i=smallestX(); i<boundaryXValues.size(); i++)
	{
		if (boundaryXValues[i] < smallX) 
			smallX = boundaryXValues[i];

		if (boundaryXValues[i] > bigX)
			bigX = boundaryXValues[i];
	}

	// eg.
	// smallX = 1
	// pointsInBetweenX (2,3,4,5,6,7)
	// bigX = 8
	for (int i=smallX; i<bigX-1; i++)
	{
		yPointsInBetween.push_back(smallY);
	}

	return yPointsInBetween;
}

// find x points in shape
vector <int> Cross::findXPointsInShape()
{
	int start = smallestY(); // starting point of y axis
	int end = biggestY();	// ending point of y axis

	// boundary x values
	vector <int> boundaryXValues;

	// find x points in between
	vector <int> xPointsInBetween;

	// store points in shape coordinates
	vector <int> xPointInShape;

	for (start; start < end+1; start++)
	{
		boundaryXValues = findBoundaryXValues(start);

		xPointsInBetween = findXPointsInBetweenTwoVertices(boundaryXValues);
	
		int pointsInBetweenSize = xPointsInBetween.size();
		// if point is in pointsinbetween but not boundary points
		// point is in shape

		vector<int>::iterator it; 

		for (int i=0; i<pointsInBetweenSize; i++)
		{
			it = find(boundaryXValues.begin(), boundaryXValues.end(), xPointsInBetween[i]);

			if (it != boundaryXValues.end())
			{}
			// store only points that are not in boundary points
			else
			{
				xPointInShape.push_back(xPointsInBetween[i]);
			}
			*it = 0;
		
		}
	}
	return xPointInShape;
}

// find y points in shape
vector <int> Cross::findYPointsInShape()
{
	int start = smallestY(); // starting point of y axis
	int end = biggestY();	// ending point of y axis

	// boundary x values
	vector <int> boundaryXValues;
	// boundary y values
	vector <int> boundaryYValues;

	// find x points in between
	vector <int> xPointsInBetween;
	// find y points in between
	vector <int> yPointsInBetween;

	// store points in shape coordinates
	vector <int> yPointInShape;

	for (start; start < end+1; start++)
	{
		boundaryXValues = findBoundaryXValues(start);
		boundaryYValues = findBoundaryYValues(start);

		xPointsInBetween = findXPointsInBetweenTwoVertices(boundaryXValues);
		yPointsInBetween = findYPointsInBetweenTwoVertices(start,boundaryXValues);
	
		int pointsInBetweenSize = xPointsInBetween.size();
		// if point is in pointsinbetween but not boundary points
		// point is in shape

		vector<int>::iterator it; 

		for (int i=0; i<pointsInBetweenSize; i++)
		{
			it = find(boundaryXValues.begin(), boundaryXValues.end(), xPointsInBetween[i]);

			if (it != boundaryXValues.end())
			{}
			// store only points that are not in boundary points
			else
			{
				yPointInShape.push_back(yPointsInBetween[i]);
			}
			*it = 0;
		
		}
	}
	return yPointInShape;
}

// Public virtual member function
// Override parent function
string Cross::toString()
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
	for (int i=0; i<12; i++)
	{
		result = result + "Point [" + to_string(i) + "] : (" + to_string(this->xCoordinateArr[i]);
		result = result + ", " + to_string(this->yCoordinateArr[i]) + ")" + "\n";
	}

	result = result + "\n"; 

	result = result + "Points on perimeter : ";
	if (findXPerimeter().size() == 0)
		result =  result + "none!" + "\n";
	else
	{
		for (int i=0; i<findXPerimeter().size(); i++)
		{
			result =  result + "(";
			result =  result + to_string(findXPerimeter()[i]) + ", ";
			result =  result + to_string(findYPerimeter()[i]) + ")";

			if (i != findXPerimeter().size()-1)
				result = result + ", ";
		}
		result = result + "\n";
	}

	result = result + "\n"; 

	// store points in shape coordinates
	vector <int> xPointInShape = findXPointsInShape();
	vector <int> yPointInShape = findYPointsInShape();

	result = result + "Points within shape: ";
	if (xPointInShape.size() > 0)
	{
		for (int i=0; i<xPointInShape.size(); i++)
		{
			result = result + "(" + to_string(xPointInShape[i]) + ", ";
			result = result + to_string(yPointInShape[i]) + ")";
			if (i != xPointInShape.size()-1)
				result = result + ", ";
		}
		result = result + "\n";
	}
	else
		result = result + "none!" + "\n";

	return result;
}

// Public virtual member function
// Override parent function
// Cross Area = Surrounding Rectangle - 4 Shapes Area
double Cross::computeArea()
{
	// Surrounding rectangle that contains Cross shape
	int surroundingRectangle = abs(biggestX() - smallestX()) * abs(biggestY()-smallestY());

	// Find Cross Area
	double area = surroundingRectangle - findBottomLeftArea() - findTopLeftArea() - findTopRightArea() - findBottomRightArea();

	return area;
}

// Public virtual member function
// Override parent function
// Find if a point is inside shape
bool Cross::isPointInShape(int x, int y)
{
	// is x,y is in point in shape
	// return true
	vector <int> xPointInShape = findXPointsInShape();
	vector <int> yPointInShape = findYPointsInShape();

	for (int i=0; i<xPointInShape.size(); i++)
	{
		if (xPointInShape[i] == x && yPointInShape[i] == y)
			return true;
		else
			return false;
	}
}

// Public virtual member function
// Override parent functions
// Find if a point is on perimeter or not
bool Cross::isPointOnShape(int x, int y)
{
	vector <int> xPerimeterPoints = findXPerimeter();
	
	vector <int> yPerimeterPoints = findYPerimeter();

	for (int i=0; i<xPerimeterPoints.size(); i++)
	{
		if (xPerimeterPoints[i] == x && yPerimeterPoints[i] == y)
			return true;
		else
			return false;
	}
}
