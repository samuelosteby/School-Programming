// Programmering Grundkurs - Laboration 6
// Made by Hampus Tuokkola & Samuel Östeby

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student
{
	double pnumber;
	char name[50];
	char gender[10];
	char sprogram[50];
	int age;
	char email[50];

	struct Student* next;
};

struct Student AddAStudent()
{
	double pnumber, age;
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
		printf("%12.lf\n", head->pnumber);
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

void printstudentsearch(struct Student *head)
{
	printf("");
	printf("%12.lf\n", head->pnumber);
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
	printf("\n");
	printf("\n");

}

struct Student *findstudent(struct Student *head, double pnumber)
{
	while (head != NULL)
	{
		if (head->pnumber == pnumber)
		{
			printf("");
			break;
		}

		head = head->next;
	}

	return head;
}

struct Student *findstudentname(struct Student *head, char findstudstr[])
{
	int counter = 0;
	while (head != NULL)
	{
		if (strcmp(head->name, findstudstr) == 0)
		{
			printstudentsearch(head);
			printf("");
			counter += 1;
		}
		head = head->next;
	}

	if (counter != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Student *findstudentsprogram(struct Student *head, char findstudstr[])
{
	int counter = 0;
	while (head != NULL)
	{
		if (strcmp(head->sprogram, findstudstr) == 0)
		{
			printstudentsearch(head);
			printf("");
			counter += 1;
		}
		head = head->next;
	}

	if (counter != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Student *countstudents(struct Student *head)
{
	int counter = 0;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}

	return counter;
}

struct Student *countstudentsmale(struct Student *head)
{
	int malecounter = 0;
	char male[10] = "male";

	while (head != NULL)
	{
		if (strcmp(head->gender, male) == 0)
		{
			malecounter++;
		}	
		head = head->next;
	}

	return malecounter;
}

struct Student *countstudentsfemale(struct Student *head)
{
	int femalecounter = 0;
	char female[10] = "female";

	while (head != NULL)
	{
		if (strcmp(head->gender, female) == 0)
		{
			femalecounter++;
		}
		head = head->next;
	}

	return femalecounter;
}

struct Student *countaverageage(struct Student *head)
{
	int agesum = 0, studentcounter = 0, result = 0;
	while (head != NULL)
	{
		agesum = agesum + head->age;
		studentcounter++;
		head = head->next;
	}

	if (studentcounter != 0)
	{
		result = agesum / studentcounter;
	}
	else
	{
		printf("You can't get an average age of zero students\n");
	}

	return result;
}

struct Student *studyprogramstatistics(struct Student *head)
{
	// Initialize all variables needed
	int malecounter = 0, femalecounter = 0, agesum = 0, ageresult = 0, totalstudents = 0, i = 0, length = 0, totalstudentsini, isinlist = 0, havecopied = 0, freespace = 0, nonblankprogram = 0;
	char female[10] = "female";
	char male[10] = "male";
	totalstudentsini = countstudents(head);
	struct Student *start = head;

	char finishedlist[100][50];

	// Clean array
	for (i = 0; i < 100; i++)
	{
		strcpy(finishedlist[i], "");
	}

	length = sizeof(finishedlist) / sizeof(finishedlist[0]);

	// Go through all students, and place programs in list
	while (head != NULL)
	{
		for (i = 0; i < length; ++i)
		{
			if (strcmp(finishedlist[i], head->sprogram) == 0)
			{
				isinlist = 1;
			}
		}

		if (isinlist == 0)
		{
			for (i = 0; i < length; ++i)
			{
				if (strcmp(finishedlist[i], "") == 0)
				{
					freespace = i;
					break;
				}
			}

			strcpy(finishedlist[freespace], head->sprogram);
		}

		isinlist = 0;
		head = head->next;
	}

	// Print list of programs
	printf("\n");
	printf("List of programs: \n");
	for (i = 0; i < length; ++i)
	{
		if (strcmp(finishedlist[i], "") != 0)
		{
			puts(finishedlist[i]);
			nonblankprogram++;
		}
	}

	// Reset back to first node

	head = start;
	// Check which students belong to which programs and add stats, in order of the programs
	for (i = 0; i < nonblankprogram; i++)
	{
		printf("\n");
		printf("Current program: \n");
		puts(finishedlist[i]);

		while (head != NULL)
		{
			if (strcmp(finishedlist[i], head->sprogram) == 0)
			{
				totalstudents++;

				if (strcmp(female, head->gender) == 0)
				{
					femalecounter++;
				}
				else if (strcmp(male, head->gender) == 0)
				{
					malecounter++;
				}
				else
				{
					printf("Invalid gender, this isn't supposed to happen aaaaaaa");
				}

				agesum += head->age;
			}
			head = head->next;
		}
		ageresult = agesum / totalstudents;

		printf("Number of students in program %d\n", totalstudents);
		printf("Number of female students in program %d\n", femalecounter);
		printf("Number of male students in program %d\n", malecounter);
		printf("Average age of students in program %d\n", ageresult);

		totalstudents = 0;
		femalecounter = 0;
		malecounter = 0;
		agesum = 0;
		ageresult = 0;
		head = start;
		printf("\n");
	}

}

void deletestudent(struct Student *head, struct Student *remove)
{
	// When node to be deleted is head node 
	if (head == remove)
	{
		if (head->next == NULL)
		{
			printf("There is only one node. The list can't be made empty ");
			return;
		}

		/* Copy the data of next node to head */
		head->pnumber = head->next->pnumber;
		strcpy(head->name, head->next->name);
		strcpy(head->gender, head->next->gender);
		strcpy(head->sprogram, head->next->sprogram);
		head->age = head->next->age;
		strcpy(head->email, head->next->email);

		// store address of next node 
		remove = head->next;

		// Remove the link of next node 
		head->next = head->next->next;

		// free memory 
		free(remove);

		return;
	}


	// When not first node, follow the normal deletion process 

	// find the previous node 
	struct Student *prevstud = head;
	while (prevstud->next != NULL && prevstud->next != remove)
		prevstud = prevstud->next;

	// Check if node really exists in Linked List 
	if (prevstud->next == NULL)
	{
		printf("\n Given node is not present in Linked List");
		return;
	}

	// Remove node from Linked List 
	prevstud->next = prevstud->next->next;

	// Free memory 
	free(remove);

	return;
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
	printf("Welcome to your student database.\n");
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
	int choice = 0, option = 0, toExit = 1, smenuchoice = 0, searchresult = 0;
	double sizeOfFile = 0;

	double pnumber;
	char name[50] = "";
	char gender[10] = "";
	char sprogram[50] = "";
	int age;
	char email[50] = "";

	char findstudstr[50] = "";
	char databasefilename[50] = "";
	double numberofelements = 0;
	double inputnumber;

	while (choice == 0)
	{
		printf("Choose an option: \n");
		printf("1. Add new student\n2. Modify existing student\n3. Delete student\n4. Search for student\n5. Save database\n6. Load database\n7. Exit\n");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
			case 1: // Add
				while (toExit != 0)
				{
					printf("Press 0 to exit. Press anything else to continue.\n");
					scanf("%d", &toExit);;
					if (toExit == 0)
					{
						toExit = 1;
						break;
					}

					getchar();
					if (students == NULL)
					{
						students = (struct Student *) malloc(sizeof(struct Student));

						printf("Input a personal number: \n");
						scanf("%lf", &pnumber);
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
						scanf("%lf", &pnumber);
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
				system("pause");

				getchar();
				printf("\n");
				break;
			case 2: // Modify
				printf("Input a personal number of the student you wish to modify: \n");
				scanf("%lf", &inputnumber);
				struct Student *findstud = findstudent(students, inputnumber);
				if (findstud == NULL)
				{
					printf("Could not find student\n");
					system("pause");
				}
				else
				{
					printf("Input a new personal number: \n");
					scanf("%lf", &pnumber);
					getchar();
					printf("Choose a new name: \n");
					fgets(name, 50, stdin);
					name[strlen(name) - 1] = '\0';
					printf("Choose a new gender: \n");
					fgets(gender, 10, stdin);
					gender[strlen(gender) - 1] = '\0';
					printf("Choose a new program: \n");
					fgets(sprogram, 50, stdin);
					sprogram[strlen(sprogram) - 1] = '\0';
					printf("Choose a new age: \n");
					scanf("%d", &age);
					getchar();
					printf("Choose a new email: \n");
					fgets(email, 50, stdin);
					email[strlen(email) - 1] = '\0';

					findstud->pnumber = pnumber;
					strcpy(findstud->name, name);
					strcpy(findstud->gender, gender);
					strcpy(findstud->sprogram, sprogram);
					findstud->age = age;
					strcpy(findstud->email, email);

					printf("Modification complete\n");
					system("pause");

					printstudent(students);
				}
				printf("\n");
				break;
			case 3: // Delete
				printf("Input a personal number of the student you wish to delete: \n");
				scanf("%lf", &inputnumber);
				struct Student *finddeletestud = findstudent(students, inputnumber);
				if (findstud == NULL)
				{
					printf("Could not find student\n");
					system("pause");
				}
				else
				{
					deletestudent(students, finddeletestud);
					printstudent(students);
				}
				printf("\n");
				break;
			case 4: // Search
				printf("Select one of these options: \n");
				printf("1. Personal number\n2. Name\n3. Study program\n4. Statistics\n");
				scanf("%d", &smenuchoice);
				switch (smenuchoice)
				{
					case 1: // Personal number
					{
						printf("Input a personal number of the student(s) you wish to search for: \n");
						scanf("%lf", &inputnumber);
						struct Student *findstudsearchpnum = findstudent(students, inputnumber);
						printstudent(findstudsearchpnum);
						printf("\n");
						break;
					}
					case 2: // Name
					{
						printf("Input a name of the student(s) you wish to search for: \n");
						getchar();
						fgets(findstudstr, 50, stdin);
						findstudstr[strlen(findstudstr) - 1] = '\0';
						searchresult = findstudentname(students, findstudstr);
						if (searchresult == 0)
						{
							printf("No students found\n\n");
							system("pause");
						}
						printf("\n");
						break;
					}
					case 3: // Study program
					{
						printf("Input a study program of the student(s) you wish to search for: \n");
						getchar();
						fgets(findstudstr, 50, stdin);
						findstudstr[strlen(findstudstr) - 1] = '\0';
						searchresult = findstudentsprogram(students, findstudstr);
						if (searchresult == 0)
						{
							printf("No students found\n\n");
							system("pause");
						}
						printf("\n");
						break;
					}
					case 4: // Statistics
					{
						printf("Number of students: %d\n", countstudents(students));
						printf("Number of male students: %d\n", countstudentsmale(students));
						printf("Number of female students: %d\n", countstudentsfemale(students));
						printf("Average age of all students: %d\n", countaverageage(students));
						studyprogramstatistics(students);
						printf("\n");
						system("pause");
						printf("\n");
						printf("\n");
						break;
					}
				}
				break;
			case 5: // Save
				printf("\n");
				printf("Please enter a filename for the file that's going to hold the database: \n");
				fgets(databasefilename, 50, stdin);
				findstudstr[strlen(findstudstr) - 1] = '\0';
				strcat(databasefilename, ".dat");
				break;
			case 6: // Load
				printf("\n");
				break;
			case 7: // Exit
				choice = 1;
				printf("\n");
				break;
		}
	}
	printf("Goodbye!");
	return 0;
}