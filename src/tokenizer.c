#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == '\t' || c == ' ' || c == '\n') return 1; /* checks if char is a space or tab and returns one */
  return 0; /* otherwise returns zero */
}

int non_space_char(char c)
{
  if(c == '\t' || c == ' ' || c == '\n') return 0; /* checks if char is a space or tab and returns zero */
  return 1; /* otherwise returns one */
}

char *word_start(char *str)
{
  int i; /* counter variable for loop */

  for(i = 0; str[i] != '\0'; i++){ /* looping through string */
    if(non_space_char(str[i])){ /* checking if char is not a space */
      return str+i; /* returns pointer to char*/
    }
  }
  return str+i;
}

char *word_terminator(char *word)
{
  int i; /* counter variable for loop */

  for(i = 0; word[i] != '\0'; i++){ /* looping through word */
    if(space_char(word[i])){ /* checking if char is a space */
      return word+i; /* returns pointer to char */
    }
  }
  return word+i;
}

int count_words(char *str)
{
  int cnt = 0; /* counter variable */
  char *tmp = word_start(str); /* temp pointer */

  while(*tmp != '\0'){ /* looping through string */
    if(non_space_char(*tmp)){ /* checking if char is not a space */
      cnt++; /* adds one to counter */
    }
    tmp = word_terminator(tmp); /* sets temp to end of word */
    tmp = word_start(tmp); /* sets temp to beginning of next word */
  }
  return cnt; /* returns counter */
}

char *copy_str(char *inStr, short len)
{
  char *strCopy = malloc((len+1) * sizeof(char)); /* allocating memory for inStr*/
  char *tmp = strCopy; /* temporary pointer variable*/
  int i; /* counter for loop */

  for(i = 0; i < len; i++){ /* traversing throught the string */
    *tmp = *inStr; /* copying current char from inStr to temp variable */
    tmp++; /* going to next char in tmp */
    inStr++; ; /* going to next char in inStr */
  }
  *tmp = '\0'; /* adding the zero terminator */

  return strCopy; /* returns copy of string */
}

char **tokenize(char *str)
{
  int cnt = count_words(str); /* word count variable */
  char **tokens = malloc((cnt+1) * sizeof(char*)); /* double pointer that is allocated memory */
  char *tmp = str; /* temp variable that is set to str */

  int i; /* count variable for loop */
  for(i = 0; i < cnt; i++){
    tmp = word_start(tmp); /* sets temp variable to start of word */
    int len = word_length(tmp); /* getting length of current word */
    tokens[i] = copy_str(tmp,len); /* copies token into double pointer variable */
    tmp = word_terminator(tmp); /* going to the next word */
  }
  tokens[i] = 0;
  return tokens; /* returns tokens */
}

void print_tokens(char **tokens)
{
  int i; /* counter for loop */
  
  for(i = 0; tokens[i] != 0; i++){ /* looping through tokens */
    printf("%s\n",tokens[i]); /* printing out each token */
  }
}

void free_tokens(char **tokens)
{
  int i; /* counter for loop */
  for(i = 0; tokens[i] != 0; i++){ /* looping through tokens */
    free(tokens[i]); /* freeing each token from memory */
  }
  free(tokens); /* freeing the entirety */
}

int string_length(char *str)
{
  int i; /* for loop variable */
  for(i = 0; str[i] != '\0'; i++); /* adds one to i if not zero terminator */
  return i; /* returns i */
}

int word_length(char *str)
{
  int cnt = 0;
  int i;
  for(i = 0; str[i] != '\0'; i++){ /* traversing through str */
    if(non_space_char(str[i])){ /* checking if current char is not a space */
      cnt++; /* adding one to the counter */
    }
    else{ /* current char is a space and loop is broken */
      break;
    }
  }
  return cnt; /* returns the word's length */
}
