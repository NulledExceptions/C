/* File:     search_word.c
 *
 * Purpose:  search input text for the first occurrence of a word.
 *
 * Usage:    ./search_word <word to be searched for>
 * Input:    text
 * Output:   Message if search word not found
 *           Number of first word of input that matched if
 *              found
 * Notes:
 * 1.  Word searched for should contain no white space
 * 2.  Words in input text consist of strings separated by white space
 * 3.  No error check for strings exceeding MAX_STRING_LEN
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_STRING_LEN = 100;

void Usage(char prog_name[]);

int main(int argc, char* argv[]) {
   char search_for[MAX_STRING_LEN];
   char current_word[MAX_STRING_LEN];
   int  scanf_rv;
   int  word_count = 0;  

   if (argc != 2) Usage(argv[0]);
   strcpy(search_for, argv[1]);

   printf("Enter the text to be searched\n");
   scanf_rv = scanf("%s", current_word);
   while ( scanf_rv != EOF )  {
      
      
      
      if (strcmp(current_word, search_for)==0){

      printf("\n%s was word number %d\n",
      search_for, word_count);
	
	}
	


	
	word_count++;
	scanf_rv = scanf("%s", current_word);

	}

  	   if (scanf_rv == EOF){
      printf("\n%s was not found in the %d words of input\n",
         search_for, word_count);
	}

	

   return 0;
}  /* main */

void Usage(char prog_name[]) {
   fprintf(stderr, "usage: %s <string to search for>\n",
      prog_name);
   exit(0);
}  /* Usage */
