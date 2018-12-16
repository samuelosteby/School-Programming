// Programmering Grundkurs - Laboration 6
// Made by Hampus Tuokkola & Samuel Östeby

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Student
{
	int pnumber;
	char name[30];
	char gender[5];
	char sprogram[30];
	int age;
	char email[50];

	int *Student
};

int main()
{
	FILE *database;
	int choice = 0, option = 0;
	while (choice == 0)
	{
		switch (option)
		{
			case 1: // Add
				break;
			case 2: // Modify
				break;
			case 3: // Delete
				break;
			case 4: // Search
				break;
			case 5: // Save
				break;
			case 6: // Load
				break;
			case 7: // Exit
				choice = 1;
				break;
		}
	}
	return 0;
}