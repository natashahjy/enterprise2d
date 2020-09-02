/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"
#include <string>
#include <vector>

using namespace std;

class Cross : public ShapeTwoD
{
	private:
		int *xCoordinateArr;
		int *yCoordinateArr;
		
		struct Coord{
			int xCoord;
			int yCoord;
		};
		vector<Coord> tempCoordInShape;
		vector<Coord> finalCoordInShape;
	
	public:
		// Default Constructor
		Cross();

		// Constructor
		Cross (int *xCoordinateArr, int *yCoordinateArr);

		// Destructor 
		~Cross();

		// Getters
		int * getXCoordinateArr();
		int * getYCoordinateArr();

		// Setters
		void setXCoordinateArr(int *xCoordinateArr);
		void setYCoordinateArr(int *yCoordinateArr);

		// Member Functions
		int biggestX();
		int biggestY();
		int smallestX();
		int smallestY();

		vector <int> findXPerimeter();
		vector <int> findYPerimeter();

		int findLength(int x1, int x2, int y1, int y2);
		bool findXDirectionChange(int x1, int x2);
		bool findYDirectionChange(int y1, int y2);
		int findPointXCoordinate(int x1, int x2, int xChange);
		int findPointYCoordinate(int y1, int y2, int yChange);

		vector<int> findSideLength(); // stores findLength
		vector<int> findXValueChanges(); // stores XDirectionChange
		vector<int> findYValueChanges(); // stores YDirectionChange

		double findBottomLeftArea();
		double findTopLeftArea();
		double findTopRightArea();
		double findBottomRightArea();

		vector <int> findBoundaryXValues(int start); // store perimeter and vertices x points
		vector <int> findBoundaryYValues(int start); // store perimeter and vertices y points
		vector <int> findXPointsInBetweenTwoVertices(vector<int> boundaryXValues);
		vector <int> findYPointsInBetweenTwoVertices(int start, vector<int> boundaryXValues);
		vector <int> findXPointsInShape();
		vector <int> findYPointsInShape();

		// Inherited functions to override	
		string toString() override;
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;

};
#endif

