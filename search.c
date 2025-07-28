#include"inverted_Search.h"

int search( Wlist *head, char *word)
{
    //check list is empty or not

    if(head == NULL)
    {
        printf("List is empty , search not possible\n");
        return 0;
    }

    if(word != NULL)
    	word[strcspn(word, "\n")] = 0;
    //list is not empty , traverse through the list
    
    while(head)
    {
        //compare search word with each node words 
        if(!strcmp(head->word , word))
        {
            printf("Word %s is present %d files\n" , word , head->file_count);
            
	    Ltable *Thead = head->Tlink;
            while(Thead)
            {
		    if(Thead->file_name != NULL)
			    printf("In file : %s  %d times\n" , Thead->file_name , Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");
            return 0;
        }
        head = head->link;
    }
    
    printf("Search word '%s' not found\n", word);
    return 0;
}
