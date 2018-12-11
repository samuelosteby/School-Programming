// Programmering Grundkurs - Laboration 5
// Made by Hampus Tuokkola & Samuel Östeby

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void split_text(char s[]) // Replaces spaces with line breaks in a string
{
	int i;
	char space = ' ';
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '\n';
		}
	}

	printf("\n");
	puts(s);
	return 0;
}

void upper_case_to_lower_case(char s[]) // Converts upper case letters to lower case letters in a string
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
		}
	}

	printf("\n");
	puts(s);
	return 0;
}

void lower_case_to_upper_case(char s[]) // Converts lower case letters to upper case letters in a string
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (isalpha(s[i]))
		{
			s[i] = toupper(s[i]);
		}
	}

	printf("\n");
	puts(s);
	return 0;
}

void remove_character(char s[], char c) // Removes all entities of a character in a string
{
	int i, lengthofstr;
	char newstr[100] = "";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			newstr[strlen(newstr)] = s[i];
		}
	}

	printf("\n");
	puts(newstr);
	return 0;
}

void add_character(char s[], char c) // Add all entities of a character to end of every word
{
	int i, lengthofstr;
	char newstr[100] = "";
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((isspace(s[i])) || (s[i] == '\0'))
		{
			newstr[strlen(newstr)] = c;
			newstr[strlen(newstr)] = s[i];
		}
		else
		{
			newstr[strlen(newstr)] = s[i];
		}
	}

	printf("\n");
	puts(newstr);
	return 0;
}

void replace_character(char s[], char c, char r) // Replace all entities of a character with another character
{
	int i, lengthofstr;
	char newstr[100] = "";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			newstr[strlen(newstr)] = r;
		}
		else
		{
			newstr[strlen(newstr)] = s[i];
		}
	}

	printf("\n");
	puts(newstr);
	return 0;
}

void statistics_string(char s[]) // Count number of words, total number of characters and the number of each character in a string
{
	int i, j, lengthofstr, characters, words, charfrequency;
	words = 1;
	charfrequency = 0;
	char newstr[100] = "", activechar, finishlist[100] = "";
	printf("\n");

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((isspace(s[i])) && (isalnum(s[i+1])))
		{
			words += 1;
		}
		
		newstr[strlen(newstr)] = s[i];
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		activechar = s[i];
		for (j = 0; s[j] != '\0'; j++)
		{
			if (s[j] == activechar)
			{
				charfrequency += 1;
			}
		}

		if ((strchr(finishlist, activechar) == NULL) && (activechar != '\n'))
		{
			printf("The character %c occurs %d times.\n", activechar, charfrequency);
			finishlist[strlen(finishlist)] = activechar;
		}

		charfrequency = 0;
	}

	characters = strlen(newstr) - 1;

	printf("\n");
	printf("The entered text contains %d words and %d characters in total.\n\n", words, characters);
	return 0;
}

int main()
{ 
	int finished;
	finished = 0;
	while (finished == 0) // Loop until finished
	{
		printf("Please select an option.\n 1. Split text \n 2. Upper case to lower case \n 3. Lower case to upper case \n 4. Remove a character \n 5. Add a character \n 6. Replace a character \n 7. Statistics \n 8. Exit\n");
		int maxch = 100; // Maximum amount of characters that will be included in the string
		int option;
		option = 0;
		printf("\n");
		scanf("%d", &option); // Register user input for option
		getchar();
		char inputstr[100]; // The input string from the user to modify
		switch (option) // Determine which option the user has selected
		{
		case 1:
			// Splits text
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			split_text(inputstr);
			break;
		case 2:
			// Upper case to lower case
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			upper_case_to_lower_case(inputstr);
			break;
		case 3:
			// Lower case to upper case
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			lower_case_to_upper_case(inputstr);
			break;
		case 4:
			// Remove a character
			char remove_char;
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			printf("Enter a character to remove:\n");
			scanf("%c", &remove_char);
			getchar();
			remove_character(inputstr, remove_char);
			break;
		case 5:
			// Add a character
			char add_char;
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			printf("Enter a character to add at end of all words:\n");
			scanf("%c", &add_char);
			getchar();
			add_character(inputstr, add_char);
			break;
		case 6:
			// Replace a character
			char replace_char, replacement_char;
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			printf("Enter a character to replace:\n");
			scanf("%c", &replace_char);
			getchar();
			printf("Enter a character to act as the replacement:\n");
			scanf("%c", &replacement_char);
			getchar();
			replace_character(inputstr, replace_char, replacement_char);
			break;
		case 7:
			// Statistics
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			statistics_string(inputstr);
			break;
		case 8:
			// Exit
			printf("Goodbye!\n\n");
			finished = 1;
			break;
		default:
			// Invalid option
			break;
		}
	}
	
	system("pause");
	return 0;
}