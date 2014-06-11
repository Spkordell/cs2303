/** mystring.h
 * @author Mike Ciaraldi
 * @author Steven Kordell
 * My own versions of some of the C-style string functions
*/

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
#ifndef MYSTRING_H
#define  MYSTRING_H

char* mystrdup(const char* src);
size_t mystrlen(const char *s);
char *mystrcpy(char *dest, const char *src);
char *mystrcat(char *dest, const char *src);
char *mystrncat(char *dest, const char *src, size_t n);
char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrndup(const char *s, size_t n);
int genRandInt(int maxValue);
char *genRandString(int n);

#endif
