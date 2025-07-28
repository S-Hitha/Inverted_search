#include "inverted_Search.h"

int update_database( Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    printf("Enter the new file name to update the database\n");
    scanf("%s", file_name);

    if(access(file_name, F_OK) == -1)
    {
	    printf("Error: File '%s' not found\n", file_name);
	    return FAILURE;
    }

    Flist *temp = *f_head;
     
    while(temp)
     {
        if(strcmp(file_name , temp->file_name) == 0)
        {
		printf("File '%s' already exists in the database\n", file_name);
		return FAILURE;
	}
	temp = temp->link;
     }

     if(to_create_list_of_files(f_head, file_name) == SUCCESS)
     {
	     printf("Successfull : Inserting the file name %s into the file linked lists\n",file_name);
	     create_database(*f_head , head);
     	     return SUCCESS;
     }
     else
     {
	     printf("Error: Failed to insert file into file list\n");
	     return FAILURE;
     }
    
}
