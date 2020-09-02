/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.h" // Include header of parent class
#include <string>
#include <vector>

// Square is a subclass of ShapeTwoD
class Square : public ShapeTwoD
{
	private:
		int *xCoordinateArr;
		int *yCoordinateArr;
	
	public:
		// Default Constructor
		Square();

		// Constructor
		Square (int *xCoordinateArr, int *yCoordinateArr);
		// Destructor 
		~Square();

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

		double findLength();
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
