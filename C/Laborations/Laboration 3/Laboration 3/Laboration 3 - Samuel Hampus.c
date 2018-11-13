// Laboration 3 - Programmering Grundkurs
//By
//Hampus Tuokkola
//Samuel Östeby


#include <stdio.h>
#include <math.h>

int finished = 0;


double calc(int operation)
{
	double x, y, z;
	
	if (operation == 1)
	{
		printf("Please input two number to add them together.\n");
		scanf("%lf%lf", &x, &y);
		z = x + y;
		printf("Answer: The sum of %lf and %lf is %lf\n", x, y, z);
		system("pause");
	}
	else if (operation == 2)
	{
		printf("Please input two number to subtract them.\n");
		scanf("%lf%lf", &x, &y);
		z = x - y;
		printf("Answer: The difference of %lf and %lf is %lf\n", x, y, z);
		system("pause");
		}
	else if (operation == 3)
	{
		printf("Please input two number to multiply them.\n");
		scanf("%lf%lf", &x, &y);
		z = x * y;
		printf("Answer: The product of %lf and %lf is %lf\n", x, y, z);
		system("pause");
	}
	else if (operation == 4)
	{
		printf("Please input two number to divide them.\n");
		scanf("%lf%lf", &x, &y);
		if (y == 0)
		{
			while (y == 0)
			{
				printf("Can not divide by zero, please choose another number to divide with.\n");
				scanf("%lf", &y);
			}
		}
		z = x / y;
		printf("Answer: The quotient of %lf and %lf is %lf\n", x, y, z);
		system("pause");
	}
	else if (operation == 5)
	{
		printf("Please input one number to get the root.\n");
		scanf("%lf", &x);
		z = sqrt(x);
		printf("Answer: The square root of %lf is %lf\n", x, z);
		system("pause");
	}
	else if (operation == 6)
	{
		printf("Please input two number to raise the first number to the power of the second.\n");
		scanf("%lf%lf", &x, &y);
		z = pow(x,y);
		printf("Answer: %lf to the power of %lf is %lf\n", x, y, z);
		system("pause");
	}
	else if (operation == 7)
	{
		int avg, i;
		double sum, n;
		printf("Choose how many numbers you want to get the average off.\n");
		scanf("%d", &avg);
		if (avg == 0)
		{
			while (avg == 0)
			{
				printf("Cannot take the average of zero numbers, please choose another number.\n");
				scanf("%d", &avg);
			}
		}
		sum = 0;
		for (i = 0; i < avg; i = i + 1)
		{
			printf("Please enter a number: \n");
			scanf("%lf", &n);
			sum = sum + n;
		}
		z = sum / avg;
		printf("Answer: The average of your inputs is %lf\n", z);
		system("pause");
	}
	else if (operation == 8)
	{
		finished = 1;
		printf("Goodbye.\n");
		system("pause");
	}
}


int main()
{
	int userinput;
	userinput = 0;
	printf("Welcome to our calculator!\n");
	printf("Made by Hampus Tuokkola & Samuel \x99steby\n\n");
	while (finished == 0)
	{
		printf("Please enter which operation you wish to perform.\n 1. Summation \n 2. Subtraction \n 3. Multiplication \n 4. Division \n 5. Square root \n 6. Power \n 7. Average \n 8. Exit\n");
		scanf("%d", &userinput);
		calc(userinput);
	}
}