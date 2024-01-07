#include "inverted_index.h"
int update_wordfrequency(struct word_count_table_t s[], const char temporary[], int count);
int insert_at_last(SLink **head, int data, char *pathname);
void print_list(SLink *head);

int process_word_count(FILE *fd, hash_table_t *inverted_hashtable, char *pathname, int file_count)
{
	int read_len;
	char buffer[BUFF_SIZE];
	char temporary[BUFF_SIZE];
	//struct word_count_table_t word_freq_array[BUFF_SIZE + 1]; 
	//array of datatype struct word_count_table_t

	//forward index	
	struct word_count_table_t *word_freq_array; 
	//array of datatype struct word_count_table_t2
	word_freq_array = malloc(sizeof(struct word_count_table_t)*100);

	//Update the file and word count table	
	int index, count = 0;
	int word_freq;
	
	int i, j = 0;

	//Inverted index
	SLink* file_word_table[BUFF_SIZE];
	for(i = 0; i < BUFF_SIZE; i++)
	{
		 file_word_table[i] = NULL;
	}

	//Read the file and store all the words in a buffer
	if ((read_len = fread(buffer, sizeof(char), BUFF_SIZE, fd)) == 0) 
	{
			//Writing the the string to stderr file stream
	        fputs("Error reading file", stderr);
    	} 
	else 
	{
			//Adding the null character at the end of each word
	        buffer[read_len++] = '\0'; 
	}    

	//Fetching each word and save in temp and update the struct
	for (i = 0; i < strlen(buffer); i++)
    	{
			//Fetching only the word
        	while (i < strlen(buffer) && buffer[i] != ' ' && isalnum(buffer[i]))
        	{
        		temporary[j++] = buffer[i++]; 
        	}
			//Update the struct with the word and word frequency
        	if (j != 0)
        	{
        		temporary[j] = '\0';
			
			//Count and save the number of occurences of each word
        		count = update_wordfrequency(word_freq_array,temporary, count);
			j = 0;
        	}	
	}

	//check
	for (i = 0; i < count; i++)
	{
		//To generate the key 
        index = hash_function(word_freq_array[i].each_word);
		//printf(" %s  %d : %d", word_freq_array[i].each_word,word_freq_array[i].frequency, index);
		
		//Update the inverted index
		insert_at_last(&file_word_table[i], word_freq_array[i].frequency, pathname);
		//printf("%s : ", word_freq_array[i].each_word);
		//print_list(file_word_table[i]);
		
		//Inserting the values in the hash table
		hashtableinsert(inverted_hashtable, index, word_freq_array[i].each_word, file_count, count, &file_word_table[i]);
		
      	}
	printf("\n");
}

int update_wordfrequency(struct word_count_table_t s[], const char temporary[], int count)
{
    int i;
 
    for (i = 0; i < count; i++)
    {
		//Comparing the word and updating its frequency if it matches wit the word in temporary
        if (strcmp(s[i].each_word, temporary) == 0)
        {
            s[i].frequency++;
            return count;
        }
    }

    //If control reaches here, it means no match found in struct
	//Hence copy the word in the word_count_table_t s from temp
    strcpy(s[count].each_word, temporary);
    s[count].frequency++;
 
    //Count represents the number of fields updated in the array
    return (count + 1);
}





int insert_at_last(SLink **head, int data, char *pathname)
{
	//Taking a local reference of the head
	SLink *temporary;
	temporary = *head;

	SLink *new = malloc(sizeof(SLink));

	if (new == NULL)
	{
		return FAILURE;
	}

	//Updating the data and link
	strcpy(new -> f_name, pathname);
	new -> data = data;
	new -> link = NULL;
	
	//If the list is empty 
	if ((*head) == NULL)
	{
		
		//Update head and tail
		(*head) = new;
		return SUCCESS;
	} 
	else
	{
		//Iterating till the last node
		while(temporary->link)
		{
			temporary = temporary -> link;
		}
		//Establishing the link between the last and the  new node and update the tail
		(temporary -> link) = new;
	}
	return SUCCESS;
}

void print_list(SLink *head)
{
	//Taking the local reference to traverse through the link
	SLink *temporary = head;
	
	//Iterate and print 
	while(temporary)
	{
		printf("%s: %d ", temporary -> f_name, temporary -> data);
		temporary = temporary-> link;
	}
	printf("\n");
}
