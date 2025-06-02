#define _CRT_SECURE_NO_WARNINGS



#include "Project.h"



/*
The function saves the project at a location taken from user.
input: first frame in list.
output: none.
runtime: o(n).
*/
void save(FrameNode* head)
{
	FILE* file = NULL;
	char path[NAME_LEN] = { 0 };


	printf("\t\t\t\t\tWhere to save the project? enter a full path and file name\n");

	createTextBox();

	myFgets(path, PATH_LEN);

	file = fopen(path, "wb");

    if (file)
    {

	    while (head)
	    {
		    fprintf(file, "%s,%d,%s\n", head->frame->path, head->frame->duration, head->frame->name);
		    head = head->next;
	    }

        fclose(file);

    }

    else
    {
        printf("\n\n\t\t\t\t\tcouldn't save file\n");
    }

	

}




/*
The function loads an existing progect.
input: pointer to pointer of the first frame in list.
output: none.
runtime: o(n^2)
*/
void load(FrameNode** head)
{
    char params[PARAMS_NUM][NAME_LEN] = { 0 };
    char path[PATH_LEN] = { 0 };
    char line[NAME_LEN] = { 0 }; 
    int i = 0, j = 0, paramIndex = 0, duration = 0;
    FILE* file = NULL;
    FrameNode* temp = *head;

    printf("\t\t\t\t\tEnter path to load from\n");

    createTextBox();

    myFgets(path, PATH_LEN);

    file = fopen(path, "r");

    if (!file) 
    {
        printf("\n\n\t\t\t\t\tFailed to open file\n");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        i = 0;
        j = 0; 
        paramIndex = 0;

        while (line[i] != '\0' && line[i] != '\n') 
        {
            if (line[i] == ',') 
            {
                params[paramIndex][j] = '\0';
                paramIndex++;

                if (paramIndex > RQUIERED_ID)
                {
                    printf("\n\n\t\t\t\t\tThe file format is invalid! lines that are not corrupted might be added\n", line);
                    return;
                }

                j = 0;
            }

            

            else 
            {
                params[paramIndex][j++] = line[i];
            }
            i++;
        }

        params[paramIndex][j] = '\0';
        duration = atoi(params[DURATION]);

        if (paramIndex > RQUIERED_ID || duration <= MIN_DUR || !(isFileExist(params[PATH]))) 
        {
            printf("\n\n\t\t\t\t\tThe file format is invalid! lines that are not corrupted might be added\n", line);
            return; 
        }



        if (!(*head))
        {
            *head = createFrame(params[NAME], params[PATH], atoi(params[DURATION]));
            temp = *head;
        }

        else
        {
            temp->next = createFrame(params[NAME], params[PATH], duration);
            temp = temp->next;
        }
    }

    fclose(file);
}
