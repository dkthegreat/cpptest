#include "stdafx.h"
#include "TestQuickSort.h"
#include "QuickSort.h"

int gQuickSortTestData[10] = { 8, 6, 9, 3, 7, 1, 0, 2, 5, 4 };

void TestQuickSort()
{
	for (int i = 0; i < sizeof(gQuickSortTestData) / sizeof(gQuickSortTestData[0]); i++)
	{
		printf("%d ", gQuickSortTestData[i]);
	}
	printf("\n");

	QuickSortInt(&gQuickSortTestData[0], &gQuickSortTestData[9]);

	for (int i = 0; i < sizeof(gQuickSortTestData) / sizeof(gQuickSortTestData[0]); i++)
	{
		printf("%d ", gQuickSortTestData[i]);
	}
	printf("\n");
	getchar();
}
