/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include <stddef.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void sort(int arr[], int first,int last)
{
	int pivot, j, i;
	if (first<last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i<j)
		{
			while ((arr[i] <= arr[pivot]) && (i<last))
				i++;
			while (arr[j]>arr[pivot])
				j--;
			if (i<j)
			{
				swap(&arr[i], &arr[j]);
			}
		}

		swap(&arr[pivot], &arr[j]);
		sort(arr, first, j - 1);
		sort(arr, j + 1, last);

	}
}
int search(int *arr, int low, int high)
{
    if (low == high)
	{
		return arr[low];
	}
	int mid = (low + high) / 2;
	if (mid % 2 == 0)
	{
		if (arr[mid] == arr[mid + 1])
			search(arr, mid + 2, high);
		else
			search(arr, low, mid);
	}
	else
	{
		if (arr[mid] == arr[mid - 1])
			search(arr, mid - 2, high);
		else
			search(arr, low, mid - 1);
	}
}

int findSingleOccurenceNumber(int *A, int len) {
	if ((A == NULL) || (len <= 0))
		return -1;
	sort(A, 0, len - 1);
	return search(A, 0, len - 1);
}