#define _CRT_SECURE_NO_WARNINGS


#include "menu.h"
#include "color.h"



/*
The function asks the user if he's interested to create a project
or load an existing one.
input: none.
output: user's choice.
runtime: o(n).
*/
int projectOp()
{
    int choice = 0, check = 0;

    purple();





    do
    {
        printf("\n\n\t\t\t\tWelcome to Vladimir's Movie Maker! What would you like to do?\n\n");

        printf("\t\t\t\t\t\t[0] Create a new project\n");
        printf("\t\t\t\t\t\t[1] Load existing project\n");
        printf("\t\t\t\t\t\t[2] Exit\n\n");

        createTextBox();

        check = scanf("%d", &choice);

        if (!check)
        {
            choice = INVALID;
        }

        while (getchar() != '\n');

        printf("\n\n");


        system("cls");

    } while (choice < CREATE || choice > END);

    return choice;
}




/*
The function prints a menu to the user.
input: none.
output: user's choice of option.
runtime: 
*/
int printMenu()
{
	int choice = 0, check = 0;

    cyan();

	printf("\n\n\n\t\t\t\t\tWhat would you like to do?\n\n");
	printf("\t\t\t\t\t\t[0] Exit\n");
	printf("\t\t\t\t\t\t[1] Add new Frame\n");
	printf("\t\t\t\t\t\t[2] Remove a Frame\n");
	printf("\t\t\t\t\t\t[3] Change frame index\n");
	printf("\t\t\t\t\t\t[4] Change frame duration\n");
	printf("\t\t\t\t\t\t[5] Change duration of all frames\n");
	printf("\t\t\t\t\t\t[6] List frames\n");
	printf("\t\t\t\t\t\t[7] Play movie!\n");
	printf("\t\t\t\t\t\t[8] Save project\n\n");

    createTextBox();

	check = scanf("%d", &choice);


	if (!check)
	{
		choice = INVALID;
	}

	while (getchar() != '\n');

    printf("\n\n");

	return choice;

}


/*
The function creates a box for input text.
input: none.
output: none.
runtime: o(1).
*/
void createTextBox()
{

    printf("\t\t\t\t\t+----------------------------------------------+\n");
    printf("\t\t\t\t\t|                                              |\n");
    printf("\t\t\t\t\t+----------------------------------------------+\n");
    // Move the cursor to the input box
    printf("\033[F"); // Move cursor up one line
    printf("\033[F"); // Move cursor up one line
    printf("\033[42C"); // Move cursor right to the center of the box

}
