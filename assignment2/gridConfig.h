/**
 * gridConfig.h
 *
 * @author: Dung (Kevin) Nguyen
 */

#ifndef GRIDCONFIG_H_
#define GRIDCONFIG_H_

#define INITVAL '+'
#define LIVE 'x'
#define RIP ' '

void fillInitGrid(char **array, int nrows, int ncolumns);
int setGridFromFile(char **array, int nrows, int ncolumns, FILE *fp);
void fillUpGrid(char **array, int nrows, int ncolumns);
void centerGrid(char **original, char **centered, int nrows, int ncolumns,
		int maxWidth, int maxHeight);

#endif /* gridConfig_H_ */
