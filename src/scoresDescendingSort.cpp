/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (len <= 0)
		return NULL;
	else
	{
		int i, j, temp;
		for (i = 1; i < len; i++)
		{
			temp = students[i].score;
			j = i - 1;
			while (temp < students[j].score && j >= 0)
			{
				students[j + 1].score = students[j].score;
				j = j - 1;
			}
			students[j + 1].score = temp;
		}

		return students;
	}
}