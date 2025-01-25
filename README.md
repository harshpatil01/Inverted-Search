# Inverted Search Project

This project implements an **Inverted Search** mechanism, a fundamental concept in search engines and text retrieval systems. The program efficiently indexes and retrieves data by mapping terms to their locations in a dataset, enabling fast and relevant search results.

## Features
- **Data Indexing**: Creates an inverted index for words from a given input (e.g., text files).
- **Search Functionality**: Retrieves data based on input queries using the inverted index.
- **File Handling**: Processes multiple input files to build a comprehensive index.
- **Efficient Search**: Provides fast lookup for terms across indexed files.

## How It Works
1. The program reads text from input files.
2. It tokenizes the text into individual words and builds an inverted index.
3. The inverted index maps each word to its occurrences (e.g., file names, line numbers).
4. Users can query the system to find files or lines where specific words appear.

1. **Compilation:**
   - Ensure that you have a suitable compiler installed on your system, like GCC for C projects.
   - Open a terminal and navigate to the directory containing your files.

2. **Makefile:**
   - Check if there is a `makefile` in your project. The `makefile` typically contains instructions on how to compile and build your project.
   - If a `makefile` is present, you can use the `make` command to build the project:

     ```bash
     make
     ```

3. **Compile Individual Files:**
   - If there is no `makefile` or you want to compile individual files, you can use the compiler directly:

     ```bash
     gcc -o final  main.c createdatabase.c databasehashtableinit.c hash_function.c hashtableinsert.c print_hashtable.c hashtablesearch.c process_word_count.c save_to_database.c
     ```


4. **Run the Program:**
   - Once the compilation is successful, you can run the executable:

     ```bash
     ./final
     ```

     Contributors : Harsh
