/*
Logan Passi
06/06/2021
MergeIntervals.cpp

Description: Short program to merge an interval into an existing list of intervals
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void printVec(vector<vector<int>>& v);

void mergeVec(vector<vector<int>>& v);

bool myComp(vector<int> a, vector<int> b) { return a[1] > b[1]; };

int main()
{

	//interval to be merged
	vector<vector<int>> mInterval = { {-1000, 1000}, {3, 5}, {5, 15}, {15, 17}, {12, 24} };

	for (unsigned int i = 0; i < mInterval.size(); ++i) {

		//2d vector to hold our intervals
		vector<vector<int>> myIntervals = { {1, 4}, {6, 9}, {11, 12}, {18, 20} };

		cout << "Starting Intervals\n";
		printVec(myIntervals);

		cout << "\nInterval To Be Merged\n";
		cout << mInterval[i][0] << " " << mInterval[i][1] << "\n";

		myIntervals.push_back(mInterval[i]);
		sort(myIntervals.begin(), myIntervals.end(), myComp);


		cout << "\nMerged Intervals\n";
		mergeVec(myIntervals);
		printVec(myIntervals);

		cout << "============================\n";
	}

}

//function to print out values in the 2d vector
void printVec(vector<vector<int>>& v) {
	for (unsigned int i = 0; i < v.size(); ++i) {
		for (unsigned int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}

		cout << "\n";
	}
}

//function to merge the vectors so that none of the intervals are overlapping
void mergeVec(vector<vector<int>>& v) {

	stack<vector<int>> finalStack;

	finalStack.push(v[0]);

	for (unsigned int i = 1; i <= v.size() - 1; ++i) {

		//if current interval is overlapping with previous interval, merge them
		if (v[i][1] >= finalStack.top()[0]) {
			finalStack.top()[1] = max(finalStack.top()[1], v[i][1]);
			finalStack.top()[0] = min(finalStack.top()[0], v[i][0]);
		}
		//otherise, add interval to vector
		else {
			finalStack.push(v[i]);
		}
	}

	v.clear();

	//print out the final sorted and merdged set of intervals
	while (finalStack.empty() == false) {
		cout << finalStack.top()[0] << " " << finalStack.top()[1] << "\n";
		finalStack.pop();
	}
}