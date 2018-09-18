/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char* mystrdup1(const char* src);
char* mystrdup2(const char* src);

size_t mystrlen1(const char *str);
size_t mystrlen2(const char *str);

char *mystrcpy(char *dest, const char *src);

char *mystrcat(char *dest, const char *src);
char *mystrncat(char *dest, const char *src, size_t n);

char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrndup(const char *s, size_t n);
