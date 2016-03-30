/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int num(char s[])
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
int date_of_birth(char *d, int *date, int *mon, int *year)
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
	a = num(x);
	b = num(y);
	c = num(z);
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
int isValid(int d, int m, int y)
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
int isGreater(char *dob1, char *dob2) {
	int d1, d2, m1, m2, y1, y2;
	int x, y;
	x = date_of_birth(dob1, &d1, &m1, &y1);
	y = date_of_birth(dob2, &d2, &m2, &y2);
	if ((x == 0) || (y == 0))
		return -1;
	else
	{
		if ((isValid(d1, m1, y1) == 1) && (isValid(d2, m2, y2) == 1))
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
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j, m = 0;
	struct transaction common[10];
	if ((A == NULL) || (B == NULL) || (ALen<1) || (BLen<1))
		return NULL;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (isGreater(A[i].date, B[j].date) == 0)
				common[m++] = A[i];
		}
	}
	if (m == 0)
		return NULL;
	return common;
}