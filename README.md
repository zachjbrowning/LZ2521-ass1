# French to English Dictionary
## LZ2521 Assignment 1

The purpose of this assignment is to create a functional dictionary that translates from French to English, using a Binary Search Tree.

The assignment is broken up into three parts, and must be completed in that order. You are provided with a few header files to get you started, but ultimately the implementation is entirely up to you. Importantly however, your solution must perform to an acceptable optimisation level.

## Using the dictionary
The entry point into the dictionary is through the translator.c file. This has been provided and implemented for you, and calls the functions that you will need to implement in this assignment. The dictionary may be run from the CLI as follows: `$_ ./translator <translation file>`, where `<translation file>` refers to the file that holds a list of translations. Once the translator is running, you may use the following commands:
```
    - s <string>
        - Searches the dictionary for a verb starting with <string>. 
    - l 
        - list the most searched for verbs in the dictionary
    - ?
        - list the available commands
    - q
        - quit the translator
```

## Part 1
The first part of the assignment requires you to read a list of translations from a file, and build up a dictionary from that. You may assume that the file to read from is correctly formatted, with one translation per line in the following format:
```
<French verb> <English translation>
<French verb> <English translation>
<French verb> <English translation>
<French verb> <English translation>
```
Each french verb will be one word with no spaces, and the english translation may consist of multilpe words with spaces.

## Part 2
The second part of the assignment is focused on enabling the search capability. 

The output of this function must list all matches to the searched string, in ascending order. Each match should be printed on its own line in the same format as the translation file read in part 1.

## Part 3
The last part of this assignment is focused on enabling the list capability.

The output of this function must list the top five searched for verbs. Each item should be printed on its own line in the following format:
```
<number of searches> <French verb>
```

## Testing
Soon to come (watch this space xx)
Certain test cases should also provide clarity in the behaviour of certain edge cases.

## Extension
It may interest you to add further capabilites to your solution, such as:
- add extra entries to the dictionary dynamically
