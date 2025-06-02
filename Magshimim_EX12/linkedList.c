#define _CRT_SECURE_NO_WARNINGS

#include "linkedList.h"



/*
Prints the linked list (recursively!)
input: head of list
output: none
runtime: o(N)
*/
void printList(FrameNode* head)
{
	if (head)
	{
		printf("\t\t\t\t\t%s\t\t%d ms\t\t%s\n", head->frame->name, head->frame->duration, head->frame->path);
		printList(head->next);
	}
}


/*
Function creates Frame
input: none
output: the new frame
runtime: o(n)
*/
FrameNode* initFrame(FrameNode* head)
{
	char name[NAME_LEN] = { 0 };
	char path[NAME_LEN] = { 0 };
	int duration = 0;
	int isRead = 0;


	printf("\n\n\t\t\t\t\t*** Creating new frame ***\n");

	printf("\t\t\t\t\tPlease insert frame path:\n");

	createTextBox();

	myFgets(path, PATH_LEN);

	printf("\n\n");

	printf("\t\t\t\t\tPlease insert frame duration(in miliseconds):\n");
	createTextBox();
	isRead = scanf("%d", &duration);

	

	if (!isRead || duration <= MIN_DUR)
	{
		red();
		printf("\n\n\t\t\t\t\tWrong input, duration will be set to default(1000 ms)\n\n");
		cyan();
		duration = DEFAULT_DUR;
	}


	while (getchar() != '\n'); //This line is needed insted of a regular getchar in case the user enters letters in duration.

	do
	{
		printf("\n\n\t\t\t\t\tEnter name of frame(There must be no frame with the same name):\n");

		createTextBox();

		myFgets(name, NAME_LEN);

	} while (findFrame(head, name));

	

	printf("\n\n");

	return createFrame(name, path, duration);
}

/*
Creates a frame node in the memory
input: name and age of person
output: the node in the memory
runtime: 0(1)
*/
FrameNode* createFrame(char* frameName, char* framePath, int duration)
{
	Frame* frame = (Frame*)malloc(sizeof(Frame));

	if (!frame)
	{
		printf("Allocation memory failed.\n\n");
		return NULL;
	}

	frame->path = (char*)malloc(PATH_LEN);
	frame->name = (char*)malloc(NAME_LEN);

	if (!(frame->path) || !(frame->name))
	{
		printf("Allocation memory failed.\n\n");
		return NULL;
	}

	strncpy(frame->path, framePath, PATH_LEN);
	strncpy(frame->name, frameName, NAME_LEN);
	frame->duration = duration;

	return createFrameNode(frame);
}

/*
The function creates a frame node.
input: frame to turn into a node.
output: the frame node.
runtime: o(1).
*/
FrameNode* createFrameNode(Frame* AddFrame)
{
	FrameNode* nodeFrame = (FrameNode*)malloc(sizeof(FrameNode));

	if (!nodeFrame)
	{
		printf("Allocation memory failed.\n\n");
		return NULL;
	}

	nodeFrame->frame = AddFrame;
	nodeFrame->next = NULL;

	return nodeFrame;
}



/*
This function adds a frame.
input: first frame in list.
output: none
runtime: o(n)
*/
void add(FrameNode** head)
{
	FrameNode* addFrame = initFrame(*head);
	FrameNode* curr = *head;
	int added = FALSE;
	bool isExist = false;

	/*if (findFrame(*head, addFrame->frame->name))
	{
		red();
		printf("\t\t\t\t\t\tFrame already exists!\n\n");
		cyan();
		return;
	}*/

	isExist = isFileExist(addFrame->frame->path);

	if (isExist)
	{
		if (curr == NULL) // list is empty
		{
			*head = addFrame;
		}


		else
		{
			while (curr && !added)
			{
				if (!curr->next) // last Frame in list
				{
					curr->next = addFrame;
					added = TRUE;
				}
				curr = curr->next;
			}
		}
	}

	else
	{
		red();
		printf("\t\t\t\t\tCan't find file! Frame will not be added\n\n");
		cyan();
	}

}



/*
Function will perform the fgets command and also remove the newline
that might be at the end of the string - a known issue with fgets.
input: the buffer to read into, the number of chars to read
runtime: o(1)
*/
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}


/*
The function checks if a frame exists.
input: path to the frame.
output: true if the file exists else false.
runtime: o(1)
*/
bool isFileExist(char* path)
{
	FILE* check = NULL;

	check = fopen(path, "rb");


	if (!check)
	{
		return false;
	}

	fclose(check);
	return true;
}

/*
The function finds a frame in a list using it's name.
input: first frame in the list. name of frame to find.
output: the frame, or NULL if it doesn't exist.
runtime: o(n)
*/
FrameNode* findFrame(FrameNode* head, char* name)
{
	FrameNode* found = NULL;

	if (head)
	{
		while (head && !found)
		{
			if (strcmp(head->frame->name, name) == 0)
			{
				found = head;
			}
			head = head->next;
		}
	}
	return found;
}

/*
The function temoves a frame from list.
input: first frame in list. name of a frame to remove.
output: true if person is removed else false.
runtime: o(n)
*/
bool removePerson(FrameNode** head)
{
	FrameNode* temp = NULL;
	FrameNode* curr = *head;
	bool removed = false;
	char name[NAME_LEN] = { 0 };

	printf("\t\t\t\t\tEnter name to remove:\n");

	createTextBox();

	myFgets(name, NAME_LEN);

	printf("\n\n");

	printf("\t\t\t\t\t%s ", name);

	if (*head) 
	{
		if (*head && 0 == strcmp((*head)->frame->name, name))
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;

			/*temp1 = (*head)->next;
			temp2 = (*head)->frame;
			free((*head)->frame->name);
			free((*head)->frame->path);
			free((*head)->frame);
			free(*head);
			*head = temp1;*/

			removed = true;
		}
		else
		{
			while (!removed && curr->next && 0 != strcmp((curr->next)->frame->name, name))
			{
				curr = curr->next;
			}

			if (curr->next && 0 == strcmp(curr->next->frame->name, name))
			{
				temp = curr->next;
				curr->next = temp->next;
				free(temp);
				removed = true;
			}
		}
	}

	return removed;


}


/*
The function changes the id of a frame in the list.
input: pointer to pointer of the first frame in the list, name of the frame to move, new index.
output: none.
runtime: O(n).
*/
void changePlace(FrameNode** head)
{
	int i = 0, len = 0, id = 0, check = 0;
	FrameNode* replaceNode = NULL;
	FrameNode* before = NULL;
	FrameNode* curr = *head;
	FrameNode* temp = NULL;
	char name[NAME_LEN] = { 0 };

	printf("\t\t\t\t\tEnter name of frame to move:\n");
	createTextBox();
	myFgets(name, NAME_LEN);

	printf("\n\n\t\t\t\t\tEnter id you want to put %s in (starting from 1):\n", name);
	createTextBox();
	check = scanf("%d", &id);

	if (!check)
	{


		red();
		printf("\n\n\t\t\t\t\tWrong input\n\n");
		cyan();

		while (getchar() != '\n');

		return;
	}


	getchar();


	printf("\n\n");

	len = listLength(*head);

	if (id < 1 || id > len)
	{
		red();
		printf("\t\t\t\t\tThe id is out of range!\n\n");
		cyan();
		return;
	}

	id--; 

	replaceNode = findFrame(*head, name);
	if (!replaceNode)
	{
		red();
		printf("\t\t\t\t\tFrame doesn't exist\n\n");
		cyan();
		return;
	}

	if (replaceNode == *head)
	{
		*head = replaceNode->next;
	}
	else
	{
		before = findPrevious(*head, replaceNode);
		if (before)
		{
			before->next = replaceNode->next;
		}
	}

	if (id == 0)
	{
		replaceNode->next = *head;
		*head = replaceNode;
	}
	else
	{
		curr = *head;
		for (i = 0; i < id - 1; i++)
		{
			curr = curr->next;
		}

		replaceNode->next = curr->next;
		curr->next = replaceNode;
	}
}






/*
The function finds the length of a list.
input: first frame in list.
output: length of list.
runtime: o(n).
*/
int listLength(FrameNode* head)
{
	int size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}

	return size;
}


/*
The function finds the previous frame.
input: first frame in list, the frame to find a one before.
output: the frame before findBefore.
runtime: o(n).
*/
FrameNode* findPrevious(FrameNode* head, FrameNode* findBefore)
{
	FrameNode* curr = head;

	if (!head || head == findBefore)
	{
		return NULL;
	}

	while (curr->next && curr->next != findBefore)
	{
		curr = curr->next;
	}

	return curr->next == findBefore ? curr : NULL;;
}


/*
The function changes the duration of a frame.
input: first frame in list.
output: none.
runtime: o(n).
*/
void changeDur(FrameNode* head)
{
	int newDur = 1000, check = 0;
	FrameNode* change = NULL;
	char name[NAME_LEN] = { 0 };

	printf("\t\t\t\t\tEnter name of frame to change duration:\n");

	createTextBox();

	myFgets(name, NAME_LEN);

	printf("\n\n");

	printf("\t\t\t\t\tEnter new duration:\n");

	createTextBox();

	check = scanf("%d", &newDur);

	printf("\n\n");

	if (!check || newDur <= MIN_DUR)
	{
		red();
		printf("\n\n\t\t\t\t\tWrong input, duration will be set to default(1000 ms)\n\n");
		cyan();
		newDur = DEFAULT_DUR;
	}

	while (getchar() != '\n');

	if (change = findFrame(head, name))
	{
		change->frame->duration = newDur;
	}

	else
	{
		red();
		printf("\t\t\t\t\tFrame not found\n\n");
		cyan();
	}

}


/*
The function changes the duration of all frames in list.
input: first frame in list.
output: none.
runtime: o(n).
*/
void changeAllDur(FrameNode* head)
{
	int newDur = 0, check = 0;
	FrameNode* curr = head;


	printf("\t\t\t\t\tEnter new duration:\n");

	createTextBox();

	check = scanf("%d", &newDur);

	printf("\n\n");


	if (!check || newDur <= MIN_DUR)
	{
		newDur = DEFAULT_DUR;
		red();
		printf("\t\t\t\t\tWrong input, all duration will be set to default(1000 ms)\n\n");
		cyan();
	}

	while (getchar() != '\n');

	while (curr)
	{
		curr->frame->duration = newDur;
		curr = curr->next;
	}
}

/*
The function frees all the frames and their data.
input: pointer to pointer of the first frame in list.
outpput: none.
runtime: o(n).
*/
void freeListFrames(FrameNode** head)
{
	FrameNode* temp1 = head;
	Frame* temp2 = NULL;
	//Frame* frame = head->frame;
	while (*head)
	{
		temp1 = (*head)->next;
		temp2 = (*head)->frame;
		free((*head)->frame->name);
		free((*head)->frame->path);
		free((*head)->frame);
		free(*head);
		*head = temp1;
	}
}



