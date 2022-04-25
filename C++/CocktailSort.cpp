// C++ implementation of Cocktail Sort
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>
using namespace std;

// Sorts array a[0..n-1] using Cocktail sort
void CocktailSort(int a[], int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped)
	{
		// reset the swapped flag on entering
		// the loop, because it might be true from
		// a previous iteration.
		swapped = false;

		// loop from left to right same as
		// the bubble sort
		for (int i = start; i < end; ++i)
		{
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		// if nothing moved, then array is sorted.
		if (!swapped)
			break;

		// otherwise, reset the swapped flag so that it
		// can be used in the next stage
		swapped = false;

		// move the end point back by one, because
		// item at the end is in its rightful spot
		--end;

		// from right to left, doing the
		// same comparison as in the previous stage
		for (int i = end - 1; i >= start; --i)
		{
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		// increase the starting point, because
		// the last stage would have moved the next
		// smallest number to its rightful spot.
		++start;
	}
}

/* Prints the array */
void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


// Driver code
int main()
{	
	// array 1
	int arr[100];
 
	srand(time(NULL));
 
	for(int i=0;i<100;i++)
	{
		int num = rand() %1000 ;
		arr[i]=num;
	}

	int n = sizeof(arr) / sizeof(arr[0]);

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	CocktailSort(arr, n);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	printf("Sorted array :\n");
	printArray(arr, n);
	cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


	// array 2

	int arr2[1000];

	for(int i=0;i<1000;i++)
	{
		int num = rand() %1000 ;
		arr2[i]=num;
	}

	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	chrono::steady_clock::time_point begin2 = chrono::steady_clock::now();
	CocktailSort(arr2, n2);
	chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
	printf("Sorted array :\n");
	printArray(arr2, n2);
	cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() << "[µs]" << std::endl;

	// array 3

	int arr3[10000];

	for(int i=0;i<10000;i++)
	{
		int num = rand() %1000 ;
		arr3[i]=num;
	}

	int n3 = sizeof(arr3) / sizeof(arr3[0]);

	chrono::steady_clock::time_point begin3 = chrono::steady_clock::now();
	CocktailSort(arr3, n3);
	chrono::steady_clock::time_point end3 = chrono::steady_clock::now();
	printf("Sorted array :\n");
	printArray(arr3, n3);
	cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end3 - begin3).count() << "[µs]" << std::endl;

	return 0;
}
