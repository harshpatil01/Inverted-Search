#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3

#define SIZE 26
#define BUFF_SIZE 255
#define NAMELENGTH 20

//Inverted table

typedef struct file_table
{
	char f_name[NAMELENGTH];
	int data;
	struct file_table *link;
}SLink;

typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	SLink *filetable;
	int f_count;
}node_t;

typedef struct database
{
	node_t *table[SIZE];
}hash_table_t;


//Forward table
struct word_count_table_t
{
	char each_word[NAMELENGTH];
	int frequency;
};


void databasehashtableinit(hash_table_t *inverted_hashtable);	
void createdatabase(hash_table_t *inverted_hashtable, char *pathname, int file_count);	
int hash_function(char *value);
int process_word_count(FILE *fd, hash_table_t *inverted_hashtable, char *pathname, int file_count);
int hashtableinsert(hash_table_t *inverted_hashtable, int index, char *word, int file_count, int total_word_count, SLink *file_word_array[]);
int print_hashtable(hash_table_t *inverted_hashtable);
int hashtablesearch(hash_table_t *inverted_hashtable, char *value);
int save_to_database(hash_table_t *inverted_hashtable);
void save_hashtable(FILE *fd, hash_table_t *inverted_hashtable);
int update_wordfrequency(struct word_count_table_t s[], const char temporary[],   int count);
int insert_at_last(SLink **head, int data, char *pathname);
void print_list(SLink *head);
int delete_list(SLink **head);



