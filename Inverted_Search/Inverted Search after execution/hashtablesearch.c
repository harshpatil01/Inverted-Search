#include "inverted_index.h"

int hashtablesearch(hash_table_t *inverted_hashtable, char *value)
{
	
	int key;
	
	//Fetching the key value for the given value
	key = hash_function(value);	
	
	
	//Taking the local reference to link
	node_t *temp;
	temp = inverted_hashtable-> table[key];
	
	//If no elements are present 
	if(inverted_hashtable-> table[key] == NULL)
	{
		return NOELEMENT;
	}
	else
	{
		{
		//If the list has multiple nodes then, iterating till the tail node
         	while (temp)
         	{
			if(strcmp((temp -> word), value) == 0)
			{
				printf("%s :\t", temp -> word);
				//Printing the values of the word that is the file name and the data
				printf("%s ", temp -> filetable -> f_name);
			}
			temp = temp -> link;
		}
		return SUCCESS;
		}
		
		return FAILURE;
		
	}
	
}
