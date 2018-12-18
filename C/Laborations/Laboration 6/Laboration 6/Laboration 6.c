// Programmering Grundkurs - Laboration 6
// Made by Hampus Tuokkola & Samuel Östeby

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // !! EVALUATE IF NECESSARY !!
#include <ctype.h> // !! EVALUATE IF NECESSARY !!

struct Student
{
	int pnumber;
	char name[50];
	char gender[10];
	char sprogram[50];
	int age;
	char email[50];
};

struct Student AddAStudent()
{
	struct Student student;
	printf("Choose a name: \n");
	fgets(student.name, 50, stdin);
	student.name[strlen(student.name) - 1] = '\0';
	printf("Choose an age: \n");
	scanf("%d", &student.age);
	getchar();
	printf("Choose a gender: \n");
	fgets(student.gender, 10, stdin);

	return student;
}

int fileexists(const char * filename) {
	FILE *file;
	if (file = fopen(filename, "r")) {
		fclose(file);
		return 1;
	}
	return 0;
}

int main()
{
	struct Student *students = NULL, student;
	// Check if database exists. Create one if needed.
	FILE *studentdbtest = fopen("studentdb.dat", "r");
	if (studentdbtest == NULL)
	{
		printf("No database exists.\n");
		printf("Creating a student database called 'studentdb.dat'.\n");
	}
	else
	{
		printf("Database located.\n");
		fclose(studentdbtest);
	}
	FILE *studentdb = fopen("studentdb.dat", "wb+");
	printf("Welcome to your student database. What would you like to do?\n");
	printf("1. Add new student\n2. Modify existing student\n3. Delete student\n4. Search for student\n5. Save database\n6. Load database\n7. Exit\n");
	int choice = 0, option = 0, toexit = 0;
	scanf("%d", &option);
	while (choice == 0)
	{
		switch (option)
		{
			case 1: // Add
				int complete = 0;
				while (complete == 0)
				{
					printf("Press 0 to exit. Press anything else to continue.\n");
					scanf("%d", &toexit);
					if (toexit == 0)
					{
						complete = 1;
					}
					getchar();
					getchar();
					student = AddAStudent();
					fwrite(&student, sizeof(struct Student), 1, studentdb);
					puts(student.name);
				}
				choice = 1;
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
	printf("Goodbye!");
	return 0;
}