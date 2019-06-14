#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <bits/stdc++.h>
using namespace std;

//!  FileWriter Class 
/*!
  FileWriter Class provides functionality to read write a points or pair of points from a file and returns the number of points and the points themselves packed in a vector of pairs, each pair is of float and float
*/
class FileWriter
{
private:
	//! An output stream file
	ofstream outputFile;
	//! FileName of the output file
	string fileName;
public:
	void WritePairs(pair<float, float>, pair<float, float>);
	void WritePair(pair<float, float>);
	FileWriter(string);
	~FileWriter();
};

///Directs the output stream into the given file
/*!
\param fileName file to which output is to be written
*/
FileWriter::FileWriter(string fileName)
{
	this->fileName = fileName;
	outputFile.open(this->fileName);
}

///Closes the file before GC of FileWriter Object
/*!
*/
FileWriter::~FileWriter()
{
	this->outputFile.close();
}

///Writes the pair to output stream
/*!
\param p The pair which has to be written
*/
void FileWriter::WritePair(pair<float, float> p)
{
	outputFile << p.first << " " << p.second << endl;
}

///Writes the pairs to output stream
/*!
\param p1 First pair which has to be written
\param p2 Second pair which has to be written
*/
void FileWriter::WritePairs(pair<float, float> p1, pair<float, float> p2)
{
	outputFile << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
}

#endif