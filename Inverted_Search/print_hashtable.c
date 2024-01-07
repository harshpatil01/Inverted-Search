#include "inverted_index.h"

int print_hashtable(hash_table_t *inverted_hashtable)
{
	int i;	
	//Taking the local reference to link
	node_t *element;
	
	//Iterating through each link in each table row
	printf("Index\tWord\tfilename\tNumber of occurence\n");
	for(i = 0; i < SIZE; i++)
	{
		printf("[%d]->",i);
	for(element = inverted_hashtable-> table[i]; element != NULL; element = element -> link)
		{
			//Printing the values
			printf(" {%s} ", element -> word);
			printf(" %s ", element -> filetable -> f_name);
			printf("%d ; ", element -> filetable -> data);		
		}
		printf("\n ");	
	}
	printf("\n");	
}
