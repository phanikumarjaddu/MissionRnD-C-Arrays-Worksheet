/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int temp, i, j,p=0;
	for (i = 1; i<len; i++)
	{
		temp = Arr[i];
		j = i - 1;
		while (temp<Arr[j] && j >= 0)
		{
			Arr[j + 1] = Arr[j];
			j = j - 1;
		}
		Arr[j + 1] = temp;
	}
	for (i = 0; num<Arr[i]; i++)
	{
		p++;
	}
	while (len>p)
	{
		Arr[len] = Arr[len - 1];
		len--;
	}
	Arr[len] = num;
	
	Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));

	return  Arr;

	
}