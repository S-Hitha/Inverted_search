#include "inverted_Search.h"

void display_database(Wlist *head[])
{
    printf("\n%-5s %-12s %-18s %-12s %-8s\n", "[INDEX]", "[WORD]", "[FILE_COUNT]", "[FILE_NAME]", "[WORD_COUNT]");
    printf("==================================================================\n");

    for (int i = 0; i < 27; i++) 
    {
        if (head[i] != NULL) 
	{
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head) 
{
    while (head != NULL) 
    {
        printf("%-4d  %-14s  %-9d file/s ", tolower(head->word[0]) % 97, head->word, head->file_count); 

        Ltable *Thead = head->Tlink;

        while (Thead) 
	{
            printf("File: %-11s   %-7d ", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        printf("\n");
        head = head->link;
    }

}


