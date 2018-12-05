// Programmering Grundkurs - Laboration 4
// Made by Hampus Tuokkola & Samuel Östeby
#include <stdio.h>

// Throw at rectangle function. Returns -1 if invalid rectangle, 0 if outside border, 3 if on border and 5 if inside rectangle
int throw_at_rectangle(double x, double y, double x1, double y1, double x2, double y2)
{
	// If a rectangle's line ends up as a point (Making the rectangle a straight line or a point)
	if (x1 == x2)
	{
		return -1;
	}
	
	if (y1 == y2)
	{
		return -1;
	}

	// If the rectangle is valid, find the biggest of the x and y values to make a proper rectangle
	double xmin, xmax, ymin, ymax;
	if (x1 < x2)
	{
		xmin = x1;
		xmax = x2;
	}
	else if (x1 > x2)
	{
		xmin = x2;
		xmax = x1;
	}

	if (y1 < y2)
	{
		ymin = y1;
		ymax = y2;
	}
	else
	{
		ymin = y2;
		ymax = y1;
	}

	// Check where the point is and compare it to the triangle
	if ((x > xmin) && (x < xmax) && (y > ymin) && (y < ymax)) // If the point is inside the rectangle...
	{
		return 5;
	}
	else if (((x == xmin) || (x == xmax)) && (y > ymin) && (y < ymax)) // If the point is on the x border but still within the rectangle...
	{
		return 3;
	}
	else if (((y == ymin) || (y == ymax)) && (x > xmin) && (x < xmax)) // If the point is on the y border but still within the rectangle...
	{
		return 3;
	}
	else if (((y == ymin) || (y == ymax)) && ((x > xmin) || (x < xmax))) // If the point is on the y border but still within the rectangle...
	{
		return 3;
	}
	else // If the point is outside the rectangle...
	{
		return 0;
	}
}

int test1() // Test function 1 - (x1 < x2, y1 < y2, point inside rectangle)
{
	int result;
	const int expected = 5;
	result = throw_at_rectangle(2, -1, -2, 2, 5, -3);
	if (result == expected)
	{
		printf("test1 succeeded!\n");
		return 1;
	}
	else
	{
		printf("test1 failed!\n");
		return 0;
	}
}

int test2() // Test function 2 - (x1 > x2, y1 > y2, point inside rectangle)
{
	int result;
	const int expected = 5;
	result = throw_at_rectangle(2, -1, 5, -3, -2, 2);
	if (result == expected)
	{
		printf("test2 succeeded!\n");
		return 1;
	}
	else
	{
		printf("test2 failed!\n");
		return 0;
	}
}

int test3() // Test function 3 - (x1 < x2, y1 < y2, point on x border)
{
	int result;
	const int expected = 3;
	result = throw_at_rectangle(1, 1, 0, 1, 3, -2);
	if (result == expected)
	{
		printf("test3 succeeded!\n");
		return 1;
	}
	else
	{
		printf("test3 failed!\n");
		return 0;
	}
}

int test4() // Test function 4 - (x1 < x2, y1 > y2, point on y border)
{
	int result;
	const int expected = 3;
	result = throw_at_rectangle(5, 1, 2, 3, 5, 0);
	if (result == expected)
	{
		printf("test4 succeeded!\n");
		return 1;
	}
	else
	{
		printf("test4 failed!\n");
		return 0;
	}
}

int test5() // Test function 5 - (x1 < x2, y1 < y2, point on edge)
{
	int result;
	const int expected = 3;
	result = throw_at_rectangle(5, 0, 2, 3, 5, 0);
	if (result == expected)
	{
		printf("test5 succeeded!\n");
		return 1;
	}
	else
	{
		printf("test5 failed!\n");
		return 0;
	}
}

int test6() // Test function 6 - (x1 < x2, y1 < y2, point outside rectangle)
{
	int result;
	const int expected = 0;
	result = throw_at_rectangle(6, -1, 2, 3, 5, 0);
	if (result == expected)
	{
		printf("test6 succeeded!\n");
		return 1;
	}
	else
	{
		printf("test6 failed!\n");
		return 0;
	}
}

int main()
{
	printf("Programmering Grundkurs - Laboration 4\n");
	printf("Made by Hampus Tuokkola & Samuel \x99steby\n\n");

	int testresult = test1() + test2() + test3() + test4() + test5() + test6();

	if (testresult == 6)
	{
		printf("All tests were successful!\n");
	}
	else
	{
		printf("Oh no, a test failed!\n");
	}
}