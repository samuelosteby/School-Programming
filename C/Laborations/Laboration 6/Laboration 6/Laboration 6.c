// Programmering Grundkurs - Laboration 6
// Made by Hampus Tuokkola & Samuel Östeby

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student
{
	//Student info
	double pnumber;
	char name[50];
	char gender[10]; // Has to be "male" or "female"
	char sprogram[50];
	int age;
	char email[50];

	struct Student* next; // Prepare linked list
};

void printstudent(struct Student *head) // Print all students' info
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

void printstudentsearch(struct Student *head) // Use fitting student's info and print it
{
	printf("");
	printf("%12.lf\n", head->pnumber); // Prints 12 characters. Use exactly 12 for best result
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

struct Student *findstudent(struct Student *head, double pnumber) // Find student through matching personal numbers
{
	while (head != NULL)
	{
		if (head->pnumber == pnumber)
		{
			printf("");
			printstudent(head);
			break;
		}

		head = head->next;
	}

	return head;
}

struct Student *findstudentname(struct Student *head, char findstudstr[]) // Find student through matching names
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

struct Student *findstudentsprogram(struct Student *head, char findstudstr[]) // Find student through matching study program
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

struct Student *countstudents(struct Student *head) // Count amount of students in total
{
	int counter = 0;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}

	return counter;
}

struct Student *countstudentsmale(struct Student *head) // Count amount of male students in total
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

struct Student *countstudentsfemale(struct Student *head) // Count amount of female students in total
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

struct Student *countaverageage(struct Student *head) // Calculate average age of all students in total
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

struct Student *studyprogramstatistics(struct Student *head) // Sort through every program and list amount of students, amount of male/female students and average age
{
	// Initialize all variables needed
	int malecounter = 0, femalecounter = 0, agesum = 0, ageresult = 0, totalstudents = 0, i = 0, length = 0, totalstudentsini, isinlist = 0, havecopied = 0, freespace = 0, nonblankprogram = 0;
	char female[10] = "female";
	char male[10] = "male";
	totalstudentsini = countstudents(head); // Used later to go back to the start of the linked list
	struct Student *start = head; // Start of the linked list

	char finishedlist[100][50]; // List to store every finished study program | NOTE! only has a total of 100 spaces. More study programs will cause overflow.

	// Clean array
	for (i = 0; i < 100; i++)
	{
		strcpy(finishedlist[i], "");
	}

	length = sizeof(finishedlist) / sizeof(finishedlist[0]); // Amount of elements in list

	// Go through all students, and place programs in list if not already in list
	// NOTE! strcmp returns 0 if both strings are equal
	while (head != NULL)
	{
		for (i = 0; i < length; ++i)
		{
			if (strcmp(finishedlist[i], head->sprogram) == 0)
			{
				isinlist = 1; // Mark study program as already in the list, to avoid double entries
			}
		}

		if (isinlist == 0) // If study program is not in list...
		{
			for (i = 0; i < length; ++i)
			{
				if (strcmp(finishedlist[i], "") == 0) // Find a free space to avoid overwriting other study programs
				{
					freespace = i;
					break;
				}
			}

			strcpy(finishedlist[freespace], head->sprogram); // Write study program at free spot
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

	head = start; // Reset back to first node

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

				if (strcmp(female, head->gender) == 0) // If female student...
				{
					femalecounter++;
				}
				else if (strcmp(male, head->gender) == 0) // If female student...
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

		// Print all results and reset variables for next iteration
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
	// For when the node to be deleted is first node 
	if (head == remove)
	{
		if (head->next == NULL) // If the first node is the one and only node...
		{
			printf("There is only one node. The list can't be made empty");
			return;
		}

		// Copy the data of the next node to the head
		head->pnumber = head->next->pnumber;
		strcpy(head->name, head->next->name);
		strcpy(head->gender, head->next->gender);
		strcpy(head->sprogram, head->next->sprogram);
		head->age = head->next->age;
		strcpy(head->email, head->next->email);

		// store the address of the next node 
		remove = head->next;

		// Remove the link to the next node 
		head->next = head->next->next;

		// Free the memory of the deleted node
		free(remove);

		return;
	}


	// When not the first node...

	// Find the previous node in the list
	struct Student *prevstud = head;
	while (prevstud->next != NULL && prevstud->next != remove)
		prevstud = prevstud->next;

	// Check if the node really exists
	if (prevstud->next == NULL)
	{
		printf("\n Given node is not present in Linked List");
		return;
	}

	// Remove node from the list
	prevstud->next = prevstud->next->next;

	// Free the memory of the deleted node
	free(remove);

	return;
}

struct Student *writetofile(struct Student *head, FILE *filestream)
{
	while (head != NULL)
	{
		fwrite(&head->pnumber, sizeof(head->pnumber), 1, filestream);
		fwrite(&head->name, sizeof(head->name), 1, filestream);
		fwrite(&head->gender, sizeof(head->gender), 1, filestream);
		fwrite(&head->sprogram, sizeof(head->sprogram), 1, filestream);
		fwrite(&head->age, sizeof(head->age), 1, filestream);
		fwrite(&head->email, sizeof(head->email), 1, filestream);

		head = head->next;
	}
}

int main()
{
	printf("Welcome to your student database.\n");
	struct Student *students = NULL, *temp = NULL, *filestudents = NULL;

	int choice = 0, option = 0, toExit = 1, smenuchoice = 0, searchresult = 0;

	// Initialize student variables
	double pnumber;
	char name[50] = "";
	char gender[10] = "";
	char sprogram[50] = "";
	int age;
	char email[50] = "";

	// Initialize file reading and other variables
	char findstudstr[50] = "", databasefilename[50] = "", acceptedoverwrite = 'c';
	double sizeoffile = 0, inputnumber, amountofdataread = 0;
	int alldataread = 0, timeslooped = 0;

	while (choice == 0)
	{
		printf("Choose an option: \n");
		printf("1. Add new student\n2. Modify existing student\n3. Delete student\n4. Search for student\n5. Save database\n6. Load database\n7. Exit\n");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
			case 1: // Add student
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
					if (students == NULL) // If it's the first student created
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
					else // If it's not the first student created
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
			case 2: // Modify student
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
			case 3: // Delete student
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
			case 4: // Search for student
				printf("Select one of these options: \n");
				printf("1. Personal number\n2. Name\n3. Study program\n4. Statistics\n");
				scanf("%d", &smenuchoice);
				switch (smenuchoice)
				{
					case 1: // search for personal number
					{
						printf("Input a personal number of the student(s) you wish to search for: \n");
						scanf("%lf", &inputnumber);
						searchresult = findstudent(students, inputnumber);
						if (searchresult == 0)
						{
							printf("No students found\n\n");
							system("pause");
						}
						//printstudent(searchresult);
						printf("\n");
						break;
					}
					case 2: // Search for name
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
					case 3: // Search for study program
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
					case 4: // Statistics, both in total and of each study program
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
			case 5: // Save student database
				printf("\n");
				printf("Please enter a filename (no extension) for the file that's going to hold the database: \n");
				fgets(databasefilename, 50, stdin);
				databasefilename[strlen(databasefilename) - 1] = '\0';
				strcat(databasefilename, ".dat");

				FILE *studentdb = fopen(databasefilename, "wb+");

				writetofile(students, studentdb); // Writes the info of every student to file

				if (fwrite != 0) // If the file could be written to successfully...
				{
					printf("contents to file written successfully !\n");
				}

				// Calculate size of the file and move cursor back when done
				fseek(studentdb, 0, SEEK_END);
				sizeoffile = ftell(studentdb);
				rewind(studentdb);

				fclose(studentdb); // End stream
				
				break;
			case 6: // Load
				printf("\n");
				printf("Warning, this will OVERWRITE everything in your current database!\n");
				printf("Are you sure you want to continue?\nPress 'y' to continue. Press anything else to abort\n");

				scanf("%c", &acceptedoverwrite);
				getchar();
				if (acceptedoverwrite != 'y')
				{
					break;
				}

				printf("");
				printf("Please enter a filename (no extension) for the file you want to load: \n");
				fgets(databasefilename, 50, stdin);
				databasefilename[strlen(databasefilename) - 1] = '\0';
				strcat(databasefilename, ".dat");
				FILE *studentfile;

				studentfile = fopen(databasefilename, "rb+");
				if (studentfile == NULL) // If the file couldn't be read
				{
					fprintf(stderr, "\nError opening file\n");
					exit(1);
				}

				fseek(studentfile, 0, SEEK_END);
				sizeoffile = ftell(studentfile);
				rewind(studentfile);

				students = NULL;
				temp = NULL;

				// Mimic way of adding like in the first part of the assignment, except now without user input
				while (alldataread == 0) // While there's still data left to read...
				{
					if (students == NULL) // If writing to the first node...
					{
						students = (struct Student *) malloc(sizeof(struct Student));

						fread(&students->pnumber, sizeof(students->pnumber), 1, studentfile);
						fread(students->name, sizeof(students->name), 1, studentfile);
						fread(students->gender, sizeof(students->gender), 1, studentfile);
						fread(students->sprogram, sizeof(students->sprogram), 1, studentfile);
						fread(&students->age, sizeof(students->age), 1, studentfile);
						fread(students->email, sizeof(students->email), 1, studentfile);
						students->next = NULL;

						puts(students->name);
					}
					else // If not writing to first node...
					{
						temp = students;
						while (temp->next != NULL)
						{
							temp = temp->next;
						}

						temp->next = (struct Student *) malloc(sizeof(struct Student));
						temp = temp->next;

						fread(&temp->pnumber, sizeof(temp->pnumber), 1, studentfile);
						fread(temp->name, sizeof(temp->name), 1, studentfile);
						fread(temp->gender, sizeof(temp->gender), 1, studentfile);
						fread(temp->sprogram, sizeof(temp->sprogram), 1, studentfile);
						fread(&temp->age, sizeof(temp->age), 1, studentfile);
						fread(temp->email, sizeof(temp->email), 1, studentfile);
						temp->next = NULL;

						puts(temp->name);
					}

					// Calculate the amount of times looped, the amount of data read and print it together with the entirety of the filesize
					++timeslooped;
					amountofdataread = (sizeof(students->pnumber) + sizeof(students->name) + sizeof(students->gender) + sizeof(students->sprogram) + sizeof(students->age) + sizeof(students->email)) * timeslooped;
					printf("Amount of data read: %lf / %lf\n\n", amountofdataread, sizeoffile);

					if (amountofdataread == sizeoffile) // If all data was successfully read...
					{
						alldataread = 1;
					}
				}

				fclose(studentfile); // Close stream
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