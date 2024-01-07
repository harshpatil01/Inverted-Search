#include "inverted_index.h"

void databasehashtableinit(hash_table_t *inverted_hashtable)
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		//Initialise all the tables to NULL
		inverted_hashtable-> table[i] = NULL;
	}	
}
