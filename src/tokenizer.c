#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == '\t' || c == ' ') return 1; /* checks if char is a space or tab and returns one */
  return 0; /* otherwise returns zero */
}

int non_space_char(char c)
{
  if(c == '\t' || c == ' ') return 0; /* checks if char is a space or tab and returns zero */
  return 1; /* otherwise returns one */
}

char *word_start(char *str)
{
  char *pstr = NULL; /* pointer variable */
  int i = 0; /* counter variable */

  while(str[i] != '\0'){ /* traverse through str while char is not zero terminator */
    if(non_space_char(str[i])){ /* checking if current char is not a space */
      pstr = &str[i]; /* sets pointer variable to the next char */
      break;
    }
    i++; /* incrementing counter variable */
  }
  return pstr; /* returns pointer variable */
}

char *word_terminator(char *word)
{
  char *pword = NULL; /* pointer variable */
  int i = 0; /* counter variable */

  while(word[i] != '\0'){ /* traverse through word while char is not zero terminator */
    if(space_char(word[i])){ /* checking if current char is a space */
      pword = &word[i]; /* sets pointer variable to next char */
      break;
    }
    i++; /* incrementing counter variable */
  }
  return pword; /* returns pointer variable */
}

int count_words(char *str)
{
  int count = 1; /* counter variable */
  int i; /* for loop variable */

  for(i = 0; str[i] != '\0'; i++) /* for loop to traverse str */
  {
    if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){ /* checks if str has a space,newline, or tab*/
      count++; /* adds one to the counter variable*/
      }
  }
  return count; /* returns counter variable*/
}

char *copy_str(char *inStr, short len)
{
  char *strCopy = malloc((len+1) * sizeof(char)); /* allocating memory for inStr*/
  char *tmp = strCopy; /* temporary pointer variable*/

  while(*inStr != '\0'){ /* traversing throught the string */
    *tmp = *inStr; /* copying current char from inStr to temp variable */
    tmp++; /* going to next location in tmp memory */
    inStr++; ; /* going to next location in inStr memory */
  }
  *tmp = '\0'; /* adding the zero terminator */

  return strCopy; /* returns copy of string */
}

char **tokenize(char *str)
{
  int cnt = count_words(str); /* word count variable */
  char **token = malloc((cnt+1) * sizeof(char*)); /* double pointer that is allocated memory */
  char *tmp = str; /* temp variable that is set to str */

  int i; /* count variable for loop */
  for(i = 0; i < cnt; i++){
    tmp = word_start(tmp); /* sets temp variable to start of word */
    int len = word_length(tmp);
    token[i] = copy_str(tmp,len); /* copies token into double pointer variable */
    tmp = word_terminator(tmp); /* adding the zero terminator */
  }
  token[i] = 0;
  return token; /* returns the tokenized string */
}

void print_tokens(char **str)
{
  while(*str != ""){ /* traverses through str */
    printf("%s\n",*str); /* prints current string */
    str++; /* goes to next string */
  }
}

void free_tokens(char **str)
{
  char **tmp = str; /* temp variable */
  while(*tmp != ""){ /* traverses through temp */
    free(*tmp); /* frees current string from memory */
    tmp++; /* goes to next string */
  }
  free(tmp); /* frees the temp variable itself */
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
  for(i = 0; str[i] != '\0'; i++){
    if(non_space_char(str[i])){
      cnt++;
    }
    else{
      break;
    }
  }
  return cnt;
}
