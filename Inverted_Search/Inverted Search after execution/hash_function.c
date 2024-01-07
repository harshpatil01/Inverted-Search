#include "inverted_index.h"

int hash_function(char *value)
{
	int key;
	int i;	
	//Takes the mod of 26 for the first character of the value
	//To ignore case-senstitivity
	if (*value >= 'A' && *value <= 'Z') 
	{
		key = *value - 'A';
	}
	else if (*value >= 'a' && *value <= 'z') 
	{
		key = *value - 'a';
	}

	//Key value to map to the hashtable
	key = key % SIZE;	
    return key;
}