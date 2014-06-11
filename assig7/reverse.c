/** Program to demonstrate string reversal
 */

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

/** Print usage message
 */
void usage () {
  printf("usage: reversestring \"string with characters to reverse\"\n");
  printf("   OR: reversewords \"string with words to reverse\"\n");
}

/** Reverses a string up to the given size
 * @param s The string to reverse
 * @param size The number of characters to reverse
*/

void reversestringn(char* s, int size) {
  char tempChar;  //Temporarily hold the character we are moving
  int i; //an iterator variable
  for (i = 0; i < size/2; i++) {
    tempChar = *(s+i);
    *(s+i) = *(s+size-1-i);
    *(s+size-1-i) = tempChar;
  }
}

/** reverses a single word in the string
 * @param s The string containing the word to reverse
 * @param skip The number of words to skip over before coming to the word to reverse
 * @return 0 if at end of string, 1 otherwise
 */
char reverseWord(char* s, int* skip) {
  int length = strlen(s);
  int wordsSkipped = 0;
  char* p = s;
  char* p2;
  int wordLength = 0;

  //advance to the word to reverse
  while (wordsSkipped < *skip) {
    while(*(p++) != ' ') {
      if (!*p) {
       return 0;
      }
    }
    wordsSkipped++;
  }  
  //measure the length of the word
  p2 = p;
  while (*p2 != ' ' && *(p2++)) {
    wordLength++;
  }
  //Reverse the word
  reversestringn(p, wordLength);

  (*skip)++;
  return 1;
}

/** Reverses all the characters in a string, in place.
 * For example, "hello world" becomes "dlrow olleh"
 */
void reversestring(char* s) {
  reversestringn(s,strlen(s));
}

/** Reverses all the words in a string, in place.
 * For example, "hello world" becomes "world hello"
 */
void reversewords(char* s) {
  int atWord = 0;
  reversestring(s);
  while(reverseWord(s,&atWord)) {}
}


/** Must take exactly one argument.
 */
int main(int argc, char* argv[]) {

  char* command; // duplicate of command name
  char* basec;    // basename of command
  char* s;       // String to reverse;

  if (argc != 2) { // Check that it was called with exactly one argument
    usage();
    return 1;
  }

  s = strdup(argv[1]); // Sring to reverse

  // See how the command was invoked

  // First strip down to just the basename, no directory prefix
  command = strdup(argv[0]);
  basec = basename(command);

  if (strcmp(basec, "reversestring") == 0) {
    printf("Original string: %s\n", s);
    reversestring(s);
    printf("Reversed string: %s\n", s);
    return 0;
  } else if (strcmp(basec, "reversewords") == 0) {
    printf("Original string: %s\n", s);
    reversewords(s);
    printf("Reversed string: %s\n", s);
    return 0;
  } else { // Those are the only two valid choices
    usage();
    return 1;
  }
}
