#ifndef INPUTREADER_H
#define INPUTREADER_H

#include<bits/stdc++.h>
using namespace std;


//!  InputReader Class 
/*!
  InputReader Class provides functionality to read input points from a file and returns the number of points and the points themselves packed in a vector of pairs, each pair is of float and float
*/
class InputReader
{
private:
	//! A Vector of points each of which is a pair of floats
	vector<pair<float, float> > points;
	//! indicates number of points in the file
	int numOfPoints;
public:
	vector<pair<float, float> > GetPoints();
	int GetNumOfPoints();
	InputReader(string);
	~InputReader();
};

///Reads input into a data structure - points.
/*!
\param fileName file from which input is to be read
*/
InputReader::InputReader(string fileName)
{
	ifstream inputFile;
	inputFile.open(fileName);
	inputFile >> this->numOfPoints;
	float f1, f2;
	pair<float, float> p;
	for(int i=0;i<this->numOfPoints;i++)
	{
		inputFile >> f1 >> f2;
		p = make_pair(f1, f2);
		this->points.push_back(p);
	}
}

///Empties the vector of points before GC of InputReader Object
/*!
*/
InputReader::~InputReader()
{
	points.clear();
}

/*!
\return The vector of points
*/
vector<pair<float, float> > InputReader::GetPoints()
{
	return this->points;
}

/*!
\return The number of points
*/
int InputReader::GetNumOfPoints()
{
	return this->numOfPoints;
}

#endif