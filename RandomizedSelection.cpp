#include "pch.h"
#include <iostream>
#include <cstdlib>


using namespace std;

int random_partition(int* arr, int start, int end)
{	//random select a position in the array 
	int pivotIdx = start + rand() % (end - start + 1);
	int pivot = arr[pivotIdx]; 
	// move pivot element to the end
	swap(arr[pivotIdx], arr[end]); 
	pivotIdx = end;
	//set the beginning point:the first element 
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{	//if the value<=pivot,swap the value of current point and the front point.
		if (arr[j] <= pivot)
		{	//i records the loc we will settle numbers to
			i = i + 1;
			swap(arr[i], arr[j]);
			
		}
	}
	//put pivot in the part of array after swaps
	swap(arr[i + 1], arr[pivotIdx]);
	//return the location of pivot
	return i + 1;
}

int random_selection(int* arr, int start, int end, int k)
{	//only one element
	if (start == end)
		return arr[start];
	//no elements
	if (k == 0) return -1;

	if (start < end)
	{
		//get the location of the pivot 
		int mid = random_partition(arr, start, end);
		//length
		int i = mid - start + 1;
		//pivot is the value
		if (i == k)
			return arr[mid];
		//pivot > the value
		else if (k < i)
			return random_selection(arr, start, mid - 1, k);
		//pivot < the value
		else
			return random_selection(arr, mid + 1, end, k - i);
	}

}

int main()
{
	int A[] = { 9,5,7,1,10,2,3 };
	//random_selection(int* arr, int start, int end, int k)
	int loc = random_selection(A, 0, 6, 5);
	cout << "the 5th smallest value is  " << loc << endl;
	return 0;
}
