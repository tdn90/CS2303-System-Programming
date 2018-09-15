/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char* mystrdup1(const char* src);
char* mystrdup2(const char* src);
size_t mystrlen1(char *str);
size_t mystrlen2(char *str);

char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

char *strncpy(char *dest, const char *src, size_t n);
char *strndup(const char *s, size_t n);
