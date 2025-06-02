#ifndef PROJECTH
#define PROJECTH


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"


#define PARAMS_NUM 3
#define RQUIERED_ID 2

enum params {
	PATH,
	DURATION,
	NAME 
};

void save(FrameNode* head);
void load(FrameNode** head);




#endif PROJECTH

