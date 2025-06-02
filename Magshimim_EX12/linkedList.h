#ifndef LINKEDLISTH
#define LINKEDLISTH


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>




#define FALSE 0
#define TRUE !FALSE
#define PATH_LEN 200
#define NAME_LEN 200
#define DEFAULT_DUR 1000
#define FIRST_ID 1
#define MIN_DUR 0

// Frame struct
typedef struct Frame
{
	char* name;
	unsigned int duration;
	char* path;
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;


void printList(FrameNode* head);
FrameNode* initFrame(FrameNode* head);
FrameNode* createFrame(char* name, char* path, int duration);
FrameNode* createFrameNode(Frame* AddFrame);
void add(FrameNode** head);
void myFgets(char str[], int n);
bool isFileExist(char* path);
FrameNode* findFrame(FrameNode* head, char* name);
bool removePerson(FrameNode** head);
void changePlace(FrameNode** head);
int listLength(FrameNode* head);
FrameNode* findPrevious(FrameNode* head, FrameNode* findBefore);
void changeDur(FrameNode* head);
void changeAllDur(FrameNode* head);
void freeListFrames(FrameNode** head);





#endif
