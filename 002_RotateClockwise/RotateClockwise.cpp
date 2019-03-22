#include "stdafx.h"

#include <sstream>
#include <iomanip>
#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <string>
#include <stdlib.h>
#include "dirent.h"
#include <algorithm>
#include <cstdlib>
using namespace std;
#define INT_32BIT 32
#define BASE 2
#define TOTAL_NO_ITEMS 100
#define SIZE 5


vector<int> _RotateClockwise(vector<int> copy, int RotateTimes)
{
	vector<int> ptr = copy;
	vector<int> rotated;
	vector<int>::iterator itrR;

	if (!ptr.empty())
	{
		while (RotateTimes--)
		{
			rotated.push_back(ptr.at(ptr.size()-1));
			for (itrR = ptr.begin(); itrR < ptr.end()-1; itrR++)
				rotated.push_back(*itrR);
			ptr = rotated;
			rotated.clear();
		}
	}
	
	return ptr;
}

int main()
{
	//int Slot[5] = { 5,6,7,8,9 };
	//int temp[5] = { 0,0,0,0,0 };
	//int Slot[100] = { 0 };
	//int temp[100] = { 0 };

	vector<int> Slot = { 1};
	//vector<int> Slot = { 3,8,9,7,6 };
	for (int i = 0; i < 6; i++)
	{
		Slot = _RotateClockwise(Slot, 1);
		vector<int>::iterator itrR;
		for (itrR = Slot.begin(); itrR < Slot.end(); itrR++)
			cout << *itrR << " ";
		cout << endl;
	}
	getchar();
}
