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
			char replace_char;
			printf("Enter text:\n");
			fgets(inputstr, maxch - 1, stdin);
			printf("Enter a character to remove:\n");
			scanf("%c", &replace_char);
			getchar();
			remove_character(inputstr, replace_char);
			break;
		case 5:
			// Add a character
			printf("Enter text:\n");
			break;
		case 6:
			// Replace a character
			printf("Enter text:\n");
			break;
		case 7:
			// Statistics
			printf("Enter text:\n");
			break;
		case 8:
			// Exit
			break;
		default:
			// Invalid option
			break;
		}
	}

	return 0;
}