/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeTwoD.h"
#include <string>
#include <vector>

using namespace std;

class Rectangle : public ShapeTwoD
{
	private:
		int *xCoordinateArr;
		int *yCoordinateArr;
	public:
		// Default Constructor
		Rectangle();

		// Constructor
		Rectangle (int *xCoordinateArr, int *yCoordinateArr);

		// Destructor 
		~Rectangle();

		// Getters
		int * getXCoordinateArr();
		int * getYCoordinateArr();

		// Setters
		void setXCoordinateArr(int *xCoordinate);
		void setYCoordinateArr(int *yCoordinate);
		
		//Member functions
		int biggestX();
		int biggestY();
		int smallestX();
		int smallestY();

		double findXLength();
		double findYLength();
		
		vector <int> findXPointsWithinShape();
		vector <int> findYPointsWithinShape();
		
		vector <int> findPerimeterXPoints();
		vector <int> findPerimeterYPoints();
	
		// Inherited functions to override
		string toString() override;
		double computeArea() override;
		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;

};
#endif
