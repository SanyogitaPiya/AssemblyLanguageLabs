/*
	Sanyogita Piya
    1001743446
	Lab 2
	Compile Command: gcc LAB2_1001743446.c 
						a.out 
*/

#include <stdlib.h>
#include <stdio.h>

void InputArray(int* arr, int arr_size);
int isSubsequence(int* X, int x_size, int* A, int a_size, int interleave_factor);
int calculateMaxInterleaveFactor(int* X, int x_size, int* A, int a_size);

int main(int argc, char *argv[])
{
	int *A, *X, a_size, x_size;
	// Input of sizes for the arrays
	scanf("%d", &a_size);
	scanf("%d", &x_size);
	//Two int arrays of given sizes created
	A = (int*)calloc(a_size, sizeof(int));
	X = (int*)calloc(x_size, sizeof(int));
	//Input from user for the arrays
	InputArray(A, a_size);
	InputArray(X, x_size);
	
	int maxInterleaveFactor=calculateMaxInterleaveFactor(X, x_size, A, a_size);
	printf("Maximum repeats is %d\n",maxInterleaveFactor);

	//replacement for getchar() because there are numerous \n in stdin buffer and getchar() would be skipped
	int temp;
	scanf("%d", &temp); 

	return 0;
}


//Input is taken from the user and is filled in the arrays given

void InputArray(int* arr, int arr_size)
{
	int i;
	for (i = 0; i < arr_size; ++i)
	{
		scanf("%d", &arr[i]);
	}
	//This is to ignore -99999999 that separates the array data
	int temp;
	scanf("%d", &temp); 
}


//This function calculates the highest interleaved factor for X such that X is a subsequence of A
	

int calculateMaxInterleaveFactor(int* X, int x_size, int* A, int a_size)
{
	// if size of A is less than X then A cannot be a subsequence for X
	int maximumInterleave = a_size / x_size; 
	int low = 0, high = maximumInterleave;
	int maxSuccessfulInterleaveFactor = 0;

	// binary search to the possible values of the interleave factor
	while (low <= high) 
	{
		int interleave_factor = (low + high) / 2;

		printf("low %d mid %d high %d ", low, interleave_factor, high); 
		//check if the interleaved sequence of X with the factor is a subsequence of A. 
		int subsequence = isSubsequence(X, x_size, A, a_size, interleave_factor);

		if (subsequence)
		{
			printf("passed\n");
			maxSuccessfulInterleaveFactor = interleave_factor;
			low = interleave_factor + 1; 
		}
		else
		{
			printf("failed\n");
			high = interleave_factor - 1; 
		}
	}

	return maxSuccessfulInterleaveFactor;
}

//This function determines whether or not the interleaved sequence that results from applying the given interleave factor to 
	

int isSubsequence(int* X, int x_size, int* A, int a_size, int interleave_factor)
{
	int subsequence = 0;
	int a_index = 0;
	int	x_index = 0;
	int numberOfMatches = 0; 
	// while A is not empty
	while (a_index <= a_size) 
	{
		if (X[x_index] == A[a_index])
		{
			numberOfMatches++;
		}

		//if interleave_factor is n, there need to be n matches in X before moving to the next
		if (numberOfMatches == interleave_factor) 
		{
			x_index++; 
			// move to next element in X array
			numberOfMatches = 0;
		}
		// if X deck is empty
		if (x_index == x_size)  
		{
			subsequence = 1;
			break;
		}
		// move to next card in A deck
		a_index++; 
	}
	return subsequence;
}