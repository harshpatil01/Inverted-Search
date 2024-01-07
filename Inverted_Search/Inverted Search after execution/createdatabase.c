#include "inverted_index.h"

void createdatabase(hash_table_t *inverted_hashtable, char *pathname, int file_count)
{
	FILE *fd;
	//To open file to read
	fd = fopen(pathname, "r");
        if (fd == NULL)
        {
	    //Prints a descriptive error message to stderr
            perror("fopen");
        }

	//To fetch the words and its occurence in that file 
if (process_word_count(fd, inverted_hashtable, pathname, file_count) == FAILURE )
	{
		//Prints a descriptive error message to stderr
		perror("process_word_count");
	}

	//Close the file
	fclose(fd);
}
