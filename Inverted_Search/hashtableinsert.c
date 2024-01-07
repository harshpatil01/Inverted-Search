#include "inverted_index.h"
int hashtableinsert(hash_table_t *inverted_hashtable, int index, char *word, int file_count, int total_word_count, SLink *file_word_array[])
{
	
	int i;

	//Create new node and update new node data and link
	node_t *new = malloc(sizeof(node_t));

	//Validation of the new node
	if (new == NULL)
	{
		return FAILURE;
	}
	

	//Create a node using the key and value
	strcpy(new -> word, word);
	new->link = NULL;	
	new->filetable=*file_word_array; 
	new->f_count = file_count;
		
	//Taking a local reference
	node_t *temp = inverted_hashtable-> table[index];
		
	//Update the links and the pointer to the link in the table
	//When no elements are added yet	
	if(inverted_hashtable->table[index] == NULL)
	{
		inverted_hashtable->table[index] = new;
		return SUCCESS;
	}
	else
	{
		//Go till the last node
		while(temp -> link)
		{
			temp = temp -> link;
		}
		//Update the last node with new 
		temp -> link = new;
 		return SUCCESS;	
	}
	return FAILURE;
}