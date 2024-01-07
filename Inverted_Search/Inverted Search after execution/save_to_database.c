#include "inverted_index.h"

int save_to_database(hash_table_t *inverted_hashtable)
{
	FILE *fd;
	
	//Opening a file to read and storing it in fd file pointer
	fd = fopen("backupdatabase.txt", "w+");
        if (fd == NULL)
        {
			//Printing the error message
            perror("fopen");
            return FAILURE;
        }

	save_hashtable(fd, inverted_hashtable);
	//Close the file
	fclose(fd);

	return SUCCESS;	
}

void save_hashtable(FILE *fd, hash_table_t *inverted_hashtable)
{
	int i;	
	
	//Taking the local reference to link
	node_t *element;
	fprintf(fd, " ");
	//Iterating through each link in each table row
	for(i = 0; i < SIZE; i++)
	{
		fprintf(fd, " [%d] ", i);
		for(element = inverted_hashtable-> table[i]; element != NULL; element = element -> link)
		{
			//Printing the values
			fprintf(fd, "{%s} ", element -> word);
			fprintf(fd, "%s ", element -> filetable -> f_name);
			fprintf(fd, "%d ;\t", element -> filetable -> data);	
			
		}
		fprintf(fd,"\n ");	
	}
	fprintf(fd,"\n ");
}
