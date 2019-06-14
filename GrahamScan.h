#ifndef GRAHAMSCAN_H
#define GRAHAMSCAN_H

#include <bits/stdc++.h>
#include "FileWriter.h"
#include "Utilities.h"
using namespace std;

pair<float, float> p0;
string file;

///COmparator ssed by qsort to sort objects
/*!
/param p1 The address of the first object of type void
/param p2 The address of the second object of type void
*/
int compare( const void *p1, const void *p2 )
{
	pair<float, float> *p = (pair<float, float> *)p1; 
  pair<float, float> *q = (pair<float, float> *)p2; 
	Utilities utilities(file); 
	int o = utilities.Orientation(p0, *p, *q); 
	if (o == 0) 
		return (utilities.DistSquare(p0, *q) >= utilities.DistSquare(p0, *p))? -1 : 1; 
  else if(o==1) return 1;
  else return -1;
}

//!  GrahamScan Class 
/*!
  GrahamScan Class provides the functionality to calculate the convex hull of a set of points
*/
class GrahamScan
{
private:
  //! A Vector of points each of which is a pair of floats
	vector<pair<float, float> > points;
  //! indicates number of points in the file
	int numOfPoints;
  //! Name of the output file
	string fileName;
public:
	void ConvexHull();
	GrahamScan(vector<pair<float, float> >, string);
	~GrahamScan();
};

///Constructor
/*!
\param points The vector of pair of float and float
\param fileName The name of the output file
*/
GrahamScan::GrahamScan(vector<pair<float, float> > points, string fileName)
{
	this->points = points;
	this->numOfPoints = points.size();
	this->fileName = fileName;
	file = fileName;
}


///Clears the vector of pairs each of which is a pair of float and float
/*!
*/
GrahamScan::~GrahamScan()
{
	points.clear();
}

///Constructs the convex hull and writes the intermediate points into the output file
/*!
*/
void GrahamScan::ConvexHull()
{
	FileWriter fileWriter(this->fileName);
	pair<float, float> p1;
	pair<float, float> p2;
	Utilities utilities(this->fileName);
  
  int min_y = points[0].second, min_index = 0; 
  for (int i = 1; i < this->numOfPoints; i++) 
  { 
    int y = points[i].second; 
    if ((y < min_y) || (min_y == y && 
        points[i].first < points[min_index].first)) 
        min_y = points[i].second, min_index = i; 
  } 
  
  utilities.Swap(points[0], points[min_index]); 
  p0 = points[0]; 
  qsort(&points[1], this->numOfPoints-1, sizeof(pair<float, float>), compare); 
  
  int m = 1;
  for (int i=1; i<this->numOfPoints; i++) 
  { 
    while (i < this->numOfPoints-1 && utilities.Orientation(p0, points[i], points[i+1]) == 0) 
    {
      i++;
    } 
    points[m] = points[i]; 
    m++;
  } 
   
  if (m < 3) return; 
  
  stack<pair<float, float>> hull_stack; 
  hull_stack.push(points[0]); 
  hull_stack.push(points[1]); 
  hull_stack.push(points[2]); 
  
  for (int i = 3; i < m; i++) 
  { 
    while (utilities.Orientation(utilities.NextToTop(hull_stack), hull_stack.top(), points[i]) != 2) 
		{	
			hull_stack.push(points[i]);
			utilities.printStack(hull_stack, this->fileName, 1);
		  hull_stack.pop();
		  hull_stack.pop();
			utilities.printStack(hull_stack, this->fileName, 0);		    
		} 

    hull_stack.push(points[i]); 
    utilities.printStack(hull_stack, this->fileName, 0);
   } 
}

#endif