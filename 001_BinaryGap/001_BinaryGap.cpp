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

#define INT_32BIT 32
#define BASE 2

void Dec2Bin(int* ptr, int value)
{
	for (int i = INT_32BIT; value > 0; i--)
	{
		*(ptr + i - 1) = value % BASE;
		value /= BASE;
	}
}

int _BinaryGap(int* ptr)
{
	int count = 0;
	int max = 0;
	//int size = sizeof(ptr);
	for (int iter = 0; iter < INT_32BIT; iter++)
	{
		count = 0;
		if (ptr[iter] == 1)
		{
			iter++;

			while (ptr[iter] == 0)
			{
				count += 1;
				if (iter >= INT_32BIT-1)
				{
					count = 0;
					break;
				}
				iter++;
			}

			iter--;
			if (count > max)
				max = count;
		}
	}
	return max;
}

int decimal[32] = { 0 };
int *ptr = decimal;
