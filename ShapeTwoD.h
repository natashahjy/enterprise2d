/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 2
*/

#ifndef SHAPE_TWO_D
#define SHAPE_TWO_D

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class ShapeTwoD
{
	protected:
		string name;
		bool containsWarpSpace;
		string specialType;
		double area;
		int shapeID;
	public: 
		// Constructors
		ShapeTwoD();
		ShapeTwoD(string name, bool containsWarpSpace);
		ShapeTwoD(int shapeID, string name, string specialType);
	
		// Getters
		int getShapeID();
		string getName();
		bool getContainsWarpSpace();
		string getSpecialType();
		double getArea();
		
		// Setters
		void setShapeID(int shapeID);
		void setName(string name);
		void setContainsWarpSpace(bool containsWarpSpace);
		void setSpecialType(string specialType);
		void setArea(double area);

		// Member functions
		virtual string toString();
		virtual double computeArea();
		virtual bool isPointInShape(int x, int y);
		virtual bool isPointOnShape(int x, int y);
		
};

#endif
