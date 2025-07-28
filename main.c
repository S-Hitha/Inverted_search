#include "inverted_Search.h"

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};
    //validate CLA 
    if( argc <= 1 )
    {
        printf("Enter the valid no. of arguments\n");
        printf("./main.exe file1.txt file2.txt .......\n");
        return 1;
    }

    //create file linked list 
    //declare head pointer 
    Flist *f_head = NULL;

    //validation of files 
    file_validation_n_file_list(&f_head ,argv);

    if(f_head == NULL)
    {
        printf("No files added to file linked list\n");
        printf("Hence the process got terminated\n");
        return 2;
    }
    
    char option;
    do{
	    int op;
	    printf("\nChoose your choice amoung the following : \n1. Create Database\n2. Display Database\n3. Update Database\n4. Search database\n5. Save Database\n6. Exit\n Enter the choice:");
	    scanf("%d", &op);

	    switch(op)
	    {
		    case 1:
			    create_database(f_head, head);
			    break;
		    case 2:
			    display_database(head);
			    break;
		    case 3:
			    update_database(head, &f_head);
			    break;
		    case 4:
			    {
				    char word[WORD_SIZE];
				    printf("Enter the word you wnat to search\n");
				    scanf("%s", word);

				    int index = tolower(word[0]) % 97;
				    search(head[index], word);
				    break;
			    }
		    case 5:
			    save_database(head);
			    break;
		    case 6:
			    printf("Exiting\n");
			    return 0;
		    default:
			    printf("Invalid choice!!\nReenter your choice\n");
	    }

	    printf("Do you want to continue?(Press Y/y for Yes or N/n for No): ");
	    scanf(" %c", &option);
    }
    while(option == 'Y' || option == 'y');
    printf("Exiting program...\n");
    
    return 0;
}

