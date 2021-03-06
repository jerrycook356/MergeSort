#include "stdafx.h"
#include <iostream>
#include <array>


void mergeSort(int theArray[], int first, int last);
void merge(int theArray[], int first, int mid, int last);
void printArray(int theArray[]);

	const int MAX_SIZE = 6;
int main()
{
	int anArray[MAX_SIZE] = { 25,30,20,80,40,60 };
	printArray(anArray);

	mergeSort(anArray,0,MAX_SIZE-1);

	printArray(anArray);

	std::cin.get();
	std::cin.get();


	return 0;
}

void mergeSort(int theArray[], int first, int last)
{
	if (first < last)
	{
		//sort each half
		int mid = (first + last) / 2; //midpoint of the array

		//sort the left half of the array
		mergeSort(theArray, first, mid);

		//sort the right half of the array
		mergeSort(theArray, mid + 1, last);
		
		//merge the two halves together
		merge(theArray, first, mid, last);
	}//end if
}//end mergeSort

void merge(int theArray[], int first, int mid, int last)
{
	int tempArray[MAX_SIZE];   //temporary array

	//initiallize the local indices to indicate the subarrays
	int first1 = first;		//beginning of first subarray
	int last1 = mid;		//end of the firt subarray
	int first2 = mid + 1;	//beginning of the second subarray
	int last2 = last;		//end of the second subarray

	//while both subarrays are not empty copy the smaller item to the tempArray

	int index = first1;    //next available location in tempArray
	while ((first1 <= last1) && (first2 <= last2))
	{

		//at this point, tempArray[first....index-1] is in order
		if (theArray[first1] <= theArray[first2])
		{
			tempArray[index] = theArray[first1];
			first1++;
		}
		else
		{
			tempArray[index] = theArray[first2];
			first2++;
		}//end if
		index++;
	}//end while

	//finish off the first subarray if necassary
	while (first1 <= last1)
	{
		//at this point, tempArray[first...index-1] is in order
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}//end while

	//finish off the second subarray if necassary
	while (first2 <= last2)
	{
		//at this point, tempArray[first....index-1] is in order
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}//end while

	//copy the results back to the original array
	for (index = first; index <= last; index++)
	{
		theArray[index] = tempArray[index];
	}//end for
}//end merge

void printArray(int theArray[])
{
	

	std::cout << std::endl << "the contents of the array is : ";
	for (int i = 0;i < MAX_SIZE; i++)
	{
		std::cout << theArray[i] << ", ";
	}
}