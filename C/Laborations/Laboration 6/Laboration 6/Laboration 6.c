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

	struct node* next;
};

struct Student AddAStudent()
{
	int pnumber, age;
	char name[50] = "", gender[10] = "", sprogram[50] = "", email[50] = "";

	struct Student student;
	printf("Choose a name: \n");
	fgets(name, 50, stdin);
	name[strlen(name) - 1] = '\0';
	printf("Choose an age: \n");
	scanf("%d", &age);
	getchar();
	printf("Choose a gender: \n");
	fgets(gender, 10, stdin);

	return student;
}

void printstudent(struct Student *head)
{
	while (head != NULL) {
		printf("");
		printf("%d\n", head->pnumber);
		puts(head->name);
		printf("");
		puts(head->gender);
		printf("");
		puts(head->sprogram);
		printf("");
		printf("%d\n", head->age);
		printf("");
		puts(head->email);
		printf("");
		head = head->next;
		printf("\n");
	}
	printf("\n");
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
	struct Student *students = NULL, *temp = NULL;
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
	int choice = 0, option = 0, toExit = 1;
	long sizeOfFile = 0;
	scanf("%d", &option);
	getchar();

	int pnumber;
	char name[50] = "";
	char gender[10] = "";
	char sprogram[50] = "";
	int age;
	char email[50] = "";

	while (choice == 0)
	{
		switch (option)
		{
			case 1: // Add
				while (toExit != 0)
				{
					printf("Press 0 to exit. Press anything else to continue.\n");
					scanf("%d", &toExit);;
					if (toExit == 0)
					{
						break;
					}

					getchar();
					//fwrite(&student, sizeof(struct Student), 1, studentdb);
					if (students == NULL)
					{
						students = (struct Student *) malloc(sizeof(struct Student));

						printf("Input a personal number: \n");
						scanf("%d", &pnumber);
						getchar();
						printf("Choose a name: \n");
						fgets(name, 50, stdin);
						name[strlen(name) - 1] = '\0';
						printf("Choose a gender: \n");
						fgets(gender, 10, stdin);
						gender[strlen(gender) - 1] = '\0';
						printf("Choose a program: \n");
						fgets(sprogram, 50, stdin);
						sprogram[strlen(sprogram) - 1] = '\0';
						printf("Choose an age: \n");
						scanf("%d", &age);
						getchar();
						printf("Choose a email: \n");
						fgets(email, 50, stdin);
						email[strlen(email) - 1] = '\0';

						students->pnumber = pnumber;
						strcpy(students->name, name);
						strcpy(students->gender, gender);
						strcpy(students->sprogram, sprogram);
						students->age = age;
						strcpy(students->email, email);

						students->next = NULL;
					}
					else
					{
						temp = students;
						while (temp->next != NULL)
						{
							temp = temp->next;
						}

						temp->next = (struct Student *) malloc(sizeof(struct Student));
						temp = temp->next;

						printf("Input a personal number: \n");
						scanf("%d", &pnumber);
						getchar();
						printf("Choose a name: \n");
						fgets(name, 50, stdin);
						name[strlen(name) - 1] = '\0';
						printf("Choose a gender: \n");
						fgets(gender, 10, stdin);
						gender[strlen(gender) - 1] = '\0';
						printf("Choose a program: \n");
						fgets(sprogram, 50, stdin);
						sprogram[strlen(sprogram) - 1] = '\0';
						printf("Choose an age: \n");
						scanf("%d", &age);
						getchar();
						printf("Choose a email: \n");
						fgets(email, 50, stdin);
						email[strlen(email) - 1] = '\0';

						temp->pnumber = pnumber;
						strcpy(temp->name, name);
						strcpy(temp->gender, gender);
						strcpy(temp->sprogram, sprogram);
						temp->age = age;
						strcpy(temp->email, email);

						temp->next = NULL;
					}
				}
				printf("The list:\n");
				printstudent(students);

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