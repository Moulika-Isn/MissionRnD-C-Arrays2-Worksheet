/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int toNumber(char s[])
{
	int i = 0, n = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 48) && (s[i] <= 57))
		{
			i++;
		}
		else return 0;
	}
	for (i = 0; s[i] != '\0'; i++)
		n = n * 10 + s[i] - '0';
	return n;
}
int dOB(char *d, int *date, int *mon, int *year)
{
	char x[3], y[3], z[5];
	int a = 0, b = 0, c = 0;
	int n = 0;
	while (*(d + n) != '\0')
		n++;
	if (n == 10)
	{
		if ((*(d + 2) == '-') && (*(d + 5) == '-'))
		{
			x[0] = *d;
			x[1] = *(d + 1);
			x[2] = '\0';
			y[0] = *(d + 3);
			y[1] = *(d + 4);
			y[2] = '\0';
			z[0] = *(d + 6);
			z[1] = *(d + 7);
			z[2] = *(d + 8);
			z[3] = *(d + 9);
			z[4] = '\0';
		}
	}
	else return 0;
	a = toNumber(x);
	b = toNumber(y);
	c = toNumber(z);
	if ((a == 0) || (b == 0) || (c == 0))
		return 0;
	else
	{
		*date = a;
		*mon = b;
		*year = c;
		return 1;
	}
}
int Valid(int d, int m, int y)
{
	if ((m >= 1) && (m <= 12))
	{
		if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
		{
			if ((d >= 1) && (d <= 31))
				return 1;
			else
				return 0;
		}
		else if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
		{
			if ((d >= 1) && (d <= 30))
				return 1;
			else
				return 0;
		}
		else
		{
			if (y % 4 == 0)
			{
				if ((d >= 1) && (d <= 29))
					return 1;
				else
					return 0;
			}
			else
			{
				if ((d >= 1) && (d <= 28))
					return 1;
				else
					return 0;
			}
		}
	}
	else
		return 0;
}
int isElder(char *dob1, char *dob2) {
	int d1, d2, m1, m2, y1, y2;
	int x, y;
	x = dOB(dob1, &d1, &m1, &y1);
	y = dOB(dob2, &d2, &m2, &y2);
	if ((x == 0) || (y == 0))
		return -1;
	else
	{
		if ((Valid(d1, m1, y1) == 1) && (Valid(d2, m2, y2) == 1))
		{
			if (y2 > y1)
				return 1;
			else if (y1 > y2)
				return 2;
			else
			{
				if (m2 > m1)
					return 1;
				else if (m1 > m2)
					return 2;
				else
				{
					if (d2 > d1)
						return 1;
					else if (d1 > d2)
						return 2;
					else
						return 0;
				}
			}

		}
		else
			return -1;
	}
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if((A==NULL)||(B==NULL)||(ALen<=0)||(BLen<=0))
		return NULL;
	struct transaction res[20];
	int i, j = 0, k = 0;
	for (i = 0; i < ALen + BLen;)
	{
		if ((j < ALen) && (k < BLen))
		{
			if ((isElder(A[j].date, B[k].date) == 1) || (isElder(A[j].date, B[k].date) == 0))
			{
				res[i++] = A[j];
				j++;
			}
			else
			{
				res[i++] = B[k];
				k++;
			}
		}
		else if (j == ALen)
		{
			for (; i < ALen + BLen;)
			{
				res[i++] = B[k];
				k++;
			}
		}
		else
		{
			for (; i < ALen + BLen;)
			{
				res[i++] = A[j];
				j++;
			}
		}
	}
	return res;
}