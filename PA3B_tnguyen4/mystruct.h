/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
struct Employee* makeRandEmployee();
int randInt(int max);
char *randStr();
char randLowercase();
char randUppercase();
struct Employee **getRandListEmployee(int size);
void printEmployees(struct Employee **list, int count);
void freeArray(struct Employee **list, size_t count);
struct Employee **shallowCopy(struct Employee **list, int size);
struct Employee *deepCopyEmp(struct Employee *e);
struct Employee **deepCopyList(struct Employee **list, size_t size);
