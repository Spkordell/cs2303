/** mystring.c
 * @author Mike Ciaraldi
 * @author Steven Kordell
 * My own versions of some of the C-style string functions
*/
#include <string.h>
#include <stdlib.h>
// stdlib.h is needed to use malloc()
#include "mystring.h"

/** Allocates memory for a string and copies the src string into it
@paran src Source String
@return pointer to a new string
*/
char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Calculates the length of a string not including the \0 character.
 *@param *s input string 
 *@return Length of the input string, not including the termination character, \0
 *@author Steven Kordell
*/
size_t mystrlen(const char *s) {
   const char* p = s;    //Make a pointer that we can play with
   while (*(p++)){}      //Advance the pointer to the end of the string
   return p-s-1;         //Return the length of the string without the terminator
}

/** Copies the src string into the dest string (including the '\0' termination characto). The destination string must be large enough for the source string
 *@paran dest The string to copy the string too
 *@paran src The string to copy
 *@return A pointer to the desitnation string
 * @author Steven Kordell
*/
char *mystrcpy(char *dest, const char *src) {
  const char* p = src;           //Make a pointer we can play with
  while (*(dest++) = *(p++)) {}  //Set the destination value to the src value, increment the pointer, and repeat till the terminator is reached
  return dest;                   //return the pointer to the new string
}

/** Appends string src to the dest sting overwriting the \o character at the end of dest, and then add a termination \0 character. Destination string must have enough space for result
 *@paran *dest String to append to
 *@paran *src String to append onto dest (will not be modified)
 *@return Poointer to the destination string
 *@author Steven Kordell
*/
char *mystrcat(char *dest, const char *src){
  char* d = dest;             //Create a pointer to play with
  const char* s = src;        //Create a pointer to play with
  while (*(++d));             //Advance destination pointer to terminator
  while (*(d++) = *(s++));    //Copy until we reach the src terminator
  return dest;                //return a pointer to the destination string
}

/** Appends n characters from string src to the dest sting overwriting the \o character at the end of dest, and then add a termination \0 character. Destination string must have enough space for result. At most, n+1 characters will be written, accounting for the terminator.
 *@paran *dest String to append to
 *@paran *src String to append onto dest (will not be modified)
 *@paran n number of bytes to copy
 *@return Poointer to the destination string
 *@author Steven Kordell
*/
char *mystrncat(char *dest, const char *src, size_t n) {
  char* d = dest;             //Create a pointer to play with
  const char* s = src;        //Create a pointer to play with
  while (*(++d));             //Advance destination pointer to terminator
  while(*s && s-src < n) {    //Copy the values until termination character hit
    *(d++) = *(s++);          //Or n is reached
  }
  *d='\0';
  return dest-n;                //return a pointer to the destination string  
}

/** Copies at most n bytes of the src string into the dest string. Will not null terminate the string if there is no \0 within the first n bytes.  The destination string must be large enough for the source string. If the length of src is less then n, the remainder of dest will be padded with null bytes.
 *@paran dest The string to copy the string too
 *@paran src The string to copy
 *@n Number of bytes to copy.
 *@return A pointer to the desitnation string
 * @author Steven Kordell
*/
char *mystrncpy(char *dest, const char *src, size_t n) {
  const char* s = src;           //Make a pointer we can play with
  while(s-src <n) {
    if (*s) *dest=*s;
    else *dest='\0';
    s++;
    dest++;
  }
  return dest-n;                //return the pointer to the new string
}

/**
Allocates memory for a string and copies n bytes of the src string into it.
If s is longer than n, only n characters are copied and a terminating null byter(\0) is added.
 *@param *s Sting to duplicate
 *@param n Number of bytes to copy
 *@return A pointer to the new string
 *@author Steven Kordell
*/
char *mystrndup(const char *s, size_t n){
  const char* p = s;  //A pointer to play with
  char* newstr; // Pointer to memory which will hold new string
  newstr = (char*) malloc(n+1);// Allocate memory for the duplicate

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  return mystrncpy(newstr,s,n);
}

/** Generates a random in between 0 and maxValue, inclusive
 *  @param maxValue The maximum value output
 *  @return A random integer between 0 and maxValue, inclusive
 *  @author Steven Kordell
*/
int genRandInt(int maxValue){
  return rand()%(maxValue+1);
}

/** Fills a string of specified size with random alphabetic characters
 *  @param n The size to make the string, actul size will be n+1, accounting for the terminator
 *  @return Pointer to the new string or zero if no memory available
 *  @author Steven Kordell
 */
char *genRandString(int n) {
  char *s = (char*) malloc(sizeof(char)*(n+1)); //Make space for the string
  if (s == 0) return (char *) 0; //Return if no memory available
  char* p = s;                   //Duplicate the pointer
  while (p - s < n) {            //Go through the array
    *p = (char)genRandInt(57)+65;//Generate a random character
    if (*p >= 91 && *p <= 96);   //Ensure the character is in the proper range
    else p++;                    //increment the pointer
  }
  *p = '\0';                     //Set last charater to terminator
  return s;                      //return the pointer to the new string
}
