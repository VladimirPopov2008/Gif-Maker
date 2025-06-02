#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#include "linkedList.h"
#include "Project.h"
#include "view.h"
#include "menu.h"


//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>



#define SUCCESS 0
#define FAILURE 1


int main()
{
	int choiceProject = 0, choiceMenu = 0, id = 0;
	FrameNode* head = NULL;
	FrameNode* newFrame = NULL;
	char name[NAME_LEN] = { 0 };

	do
	{
		choiceProject = projectOp();

		if (choiceProject == LOAD)
		{
			load(&head);
			if (!head)
			{
				choiceProject = INVALID;
			}
		}

		if (choiceProject == CREATE || choiceProject == LOAD)
		{
			do
			{
				

				choiceMenu = printMenu();

				system("cls");

				switch (choiceMenu)
				{
				case ADD_FRAME:

					add(&head);
					break;

				case REMOVE_FRAME:
					removePerson(&head) ? printf("frame removed\n") : printf("frame not found\n");
					break;

				case CHANGE_FRAME_ID:

					changePlace(&head);
					break;

				case CHANGE_FRAME_DUR:
					changeDur(head);
					break;

				case CHANGE_ALL_DUR:
					changeAllDur(head);
					break;

				case PLAY:
					play(head);
					break;

				case LIST_FRAMES:
					printf("\t\t\t\t\tName\t\tDuration\tPath\n");
					printList(head);
					break;
				
				case SAVE:
					save(head);
					break;
				}

					


			} while (choiceMenu != EXIT);

			freeListFrames(&head);

		}

		

		

	} while (choiceProject != END);

	green();
	printf("\t\t\t\t\t\tBye Bye!\n\n");

	//printf("Leaks: %d", _CrtDumpMemoryLeaks());

	return SUCCESS;
}


