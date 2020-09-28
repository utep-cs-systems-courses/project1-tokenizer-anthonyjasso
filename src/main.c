#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include"history.h"

int main(int argc, char *argv[])
{
  char input[100]; /*char array for user input */
  List *history = init_history(); /* making list to store history */

  while(1){ /* loop to know when to exit */
    printf("\nPlease enter the appropriate character below.\n");
    printf(" e: exit the program\n r: recover certain previous history\n v: view history\n s: input sentence to history\n");
    printf("$");
    fgets(input, 100, stdin); /* getting user input */

    if(input[0] == 'e'){ /* exits the program if user enters 'e' */
      printf("You have successfully exited, Goodbye!\n");
      free_history(history); /* freeing the list */
      return 0; /* exiting the while loop */
    }
    else if(input[0] == 'r'){ /* recovers certain previous history if user enters 'r' */
      char *recover = get_history(history,atoi(input+1)); /* recovering specific history */
      char **tokens = tokenize(recover); /* tokenizes the recovered history */
      printf("Recovered history:%s\n", recover); /* prints history untokenized */
      printf("Recovered history tokenized:\n"); /* prints history tokenized */
      print_tokens(tokens);
      free_tokens(tokens); /* frees the tokens from memory */
    }
    else if(input[0] == 'v'){ /* views entire history if user enters 'v' */
      print_history(history);
    }
    else if(input[0] == 's'){ /* adds to history if user enters 's' */
      printf("Input sentence below:\n$");
      fgets(input, 100, stdin); /* getting user input */
      char **tokens = tokenize(input); /* tokenizing input */
      print_tokens(tokens); /* printing the tokens */
      add_history(history, input); /* adding to history */
      free_tokens(tokens); /* freeing the tokens from memory */
    }
    else{
      printf("Invalid character entered, please try again.\n$");
    }
  }
}
