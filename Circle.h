/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeTwoD.h"
#include <string>
#include <vector>

class Circle : public ShapeTwoD
{
	private:
		int xCoordinate;
		int yCoordinate;
		int radius;

		struct Coord{
			int xCoord;
			int yCoord;
		};
		vector<Coord> tempCoordInShape;
	public:
		// Default Constructor
		Circle();

		// Constructor
		Circle (int xCoordinate, int yCoordinate, int radius);

		// Getters
		int getXCoordinate();
		int getYCoordinate();
		int getRadius();

		// Setters
		void setXCoordinate(int xCoordinate);
		void setYCoordinate(int yCoordinate);
		void setRadius(int radius);
		
		//Member functions
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
