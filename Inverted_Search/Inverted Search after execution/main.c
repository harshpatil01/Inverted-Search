#include "inverted_index.h"

int main(int argc, char **argv)
{
	int choice, i;
	char option;
	int status;
	hash_table_t inverted_hashtable;
	int file_count=0;

	char searchword[NAMELENGTH];	

	//Checking for arguments 
	if(argc < 2)
	{
		printf("Invalid arguments.\n");
		printf("Usage: ./a.out <file> <FILES..> \n");
		return -1;
	}

	do
	{
		printf("Enter the option:\n");
		printf("1. Create the database \n");
		printf("2. Search for a word\n");	
		printf("3. Save the database\n");	
		printf("4.Print the database \n ");
		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				//Initialize the database
				databasehashtableinit(&inverted_hashtable);
				file_count = argc - 1;
		i=1;		
		//Create the database for the given files
		while(i<argc)
		{		
		createdatabase(&inverted_hashtable,argv[i],file_count);
		i++;
		}
		printf("Database has been successfully created \n");	
				break;

			case 2:
			//Asking the user to enter the word that needs to be searched
				printf("Enter the word that needs to be searched in the database: ");
				scanf("%s", searchword);

				//Searching in the  inverted hashtable
				if(hashtablesearch(&inverted_hashtable, searchword) == SUCCESS)
				{
					printf("SUCCESS: Element is found\n");
				}
				else
				{
					printf("FAILURE: No Element is found\n");
				}
				printf("\n");
				
				break;

			case 3:
				save_to_database(&inverted_hashtable);
				printf("Saved in file 'backupdatabase.txt'\n");
				break;
			case 4:
				print_hashtable(&inverted_hashtable);
				break;
			default:
				printf("Invalid option\n");
				break;
		}

		//Prompt for continue option
        	printf("Do you want to continue : Y or N ? \n");
		getchar();
        	scanf("%c", &option);
		if(option == 'Y' || option == 'y')
		{
		    continue;
		}
		else
		{
		    break;
		}

    	} while (option);
	return 0;	
}
