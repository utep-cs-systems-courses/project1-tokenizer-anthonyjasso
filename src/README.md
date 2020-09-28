Project 1: Tokenizer
====================
# Objective:

The purpose of this lab was to create a tokenizer that preserves the user's
input. The two main classes are tokenizer.c and history.c. Inside the
tokenizer class all of the necessary functions to tokenize the user's input is
defined in the file. The history class holds the necessary functions to hold
and view the user's input history.

# How to Run Program:

- Step 1. Once inside the src directory, type the word "make" into the
  console. This will create an executable called "tokenizer".

- Step 2. Next, type "./tokenizer" into the console, this will run the
program.

- Step 3. Once out of the program, type "make clean" into the console to
  delete all .o files.

# Program Input Options:

The program prompts the user with four options to choose from, which are:

- e: exits the program if the user enters "e" into the console

- r: recovers a given previous history if the user enters "r" followed by a number into the console

- v: views entire history if the user enters "v" into the console

- s: inputs the user's sentence into history and tokenizes it if the user
  enters "s" into the console
