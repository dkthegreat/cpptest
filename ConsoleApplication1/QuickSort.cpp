#include "stdafx.h"
#include "QuickSort.h"

void QuickSortInt(int * start, int * end)
{
	if (start <= end)
	{
		int * left = start;
		int * right = end;
		int nPivot = start[0];

		while (left != right)
		{
			while (right > left && *right >= nPivot)
			{
				right--;
			}
			*left = *right;

			while (left < right && *left <= nPivot)
			{
				left++;
			}
			*right = *left;
		}
		*right = nPivot;
		QuickSortInt(start, left - 1);
		QuickSortInt(right + 1, end);
	}
}