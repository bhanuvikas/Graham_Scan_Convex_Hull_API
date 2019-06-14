#ifndef UTILITIES_H
#define UTILITIES_H


#include <bits/stdc++.h>
using namespace std;
#include "FileWriter.h"


//!  Utilities Class 
/*!
  Utilities Class provides functionalities like calculating the orientation of points, distance between points, swap two points, printing a stack and finding the point below the top of a stack
*/
class Utilities
{
private:
	//! An output stream file
	ofstream outputFile;
public:
	int Orientation(pair<float, float>, pair<float, float>, pair<float, float>);
	float DistSquare(pair<float, float>, pair<float, float>);
	void Swap(pair<float, float> &, pair<float, float> &);
	pair<float, float> NextToTop(stack<pair<float, float> >&);
	void printStack(stack<pair<float, float> > s, string fileName, int flag);
	Utilities();
	Utilities(string fileName);
	~Utilities();
};

///An empty argument constructor
/*!
*/
Utilities::Utilities()
{
	
}

///Directs the output stream into the given file
/*!
\param fileName file to which output is to be written
*/
Utilities::Utilities(string fileName)
{
	outputFile.open(fileName);
}
///Closes the file before GC of FileWriter Object
/*!
*/
Utilities::~Utilities()
{
	outputFile.close();
}

///Prints the stack to output file
/*!
\param s The stack which has to be printed to the output file
\param flag This has to be 1 if the stack is being printed after push, 0 if the stack is being printed after pop 
*/
void Utilities::printStack(stack<pair<float, float> > s, string fileName, int flag)
{
	pair<float, float> p;
	while(!s.empty())
	{
		p = s.top();
		outputFile << p.first << " " << p.second << endl;
		s.pop();
	}
	if(flag==0)
		outputFile << "$" << endl;
	else
		outputFile << "$$" << endl;
}

///Computes the orientation of 3 points whether they are collinear, clock-wise or counter clock-wise
/*!
\param p The first point which is a pair of float and float
\param q The second point which is a pair of float and float
\param r The third point which is a pair of float and float
\return integer representing the orientation 0 if collinear, 1 if counter clock-wise, 2 if clock-wise
*/
int Utilities::Orientation(pair<float, float> p, pair<float, float> q, pair<float, float> r)
{
	float val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
	if(val == 0)	return 0;
	else if(val > 0)	return 1;
	else	return 2;
}

///Computes the distance between two points
/*!
\param p The first point which is a pair of float and float
\param q The second point which is a pair of float and float
\return distance The distance between two points which is a floating point value
*/
float Utilities::DistSquare(pair<float, float> p, pair<float, float> q) 
{ 
    return (p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second); 
} 

///Swaps two points
/*!
\param p The address of the first point which is a pair of float and float
\param q The address of the second point which is a pair of float and float
*/
void Utilities::Swap(pair<float, float> &p, pair<float, float> &q) 
{ 
    pair<float, float> temp = p; 
    p = q; 
    q = temp; 
} 

///Gets the point just below the top of the stack
/*!
\param s The address of the stack
\return res The point just below the top of the stack 
*/
pair<float, float> Utilities::NextToTop(stack<pair<float, float> > &S) 
{ 
    pair<float, float> p = S.top(); 
    S.pop(); 
    pair<float, float> res = S.top(); 
    S.push(p); 
    return res; 
} 

#endif