#include "InputReader.h"
#include "FileWriter.h"
#include "InputReader.h"
#include "GrahamScan.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string fileName1 = "Inputs/1/input.txt";
	string fileName2 = "points.txt";
	string fileName3 = "jarvis_output.txt";
	string fileName4 = "graham_output.txt";
	InputReader inputReader(fileName1);
	vector<pair<float, float> > input = inputReader.GetPoints();
	FileWriter fileWriter(fileName2);
	for(int i=0;i<input.size();i++)
	{
		fileWriter.WritePair(input[i]);
	}
	float t = clock();
	GrahamScan grahamScan(input, fileName4);
	grahamScan.ConvexHull();
	cout << "GrahamScan: " << (clock() - t) / CLOCKS_PER_SEC << " seconds" << endl;

	return 0;
}