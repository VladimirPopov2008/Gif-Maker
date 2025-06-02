
#ifndef MENUH
#define MENUH

#include <stdio.h>
#include <stdbool.h>


#define PROJ_MODE 0
#define MENU_MODE 1
#define INVALID -1

enum project
{
	CREATE,
	LOAD, 
	END
};

enum menu
{
	EXIT,
	ADD_FRAME,
	REMOVE_FRAME,
	CHANGE_FRAME_ID,
	CHANGE_FRAME_DUR,
	CHANGE_ALL_DUR,
	LIST_FRAMES,
	PLAY,
	SAVE
};


int projectOp();
int printMenu();
void createTextBox();


#endif MENUH
