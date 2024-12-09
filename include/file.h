#ifndef FILE_H__
#define FILE_H__

#include <stdbool.h>

long int get_file_size(const char *filename);
bool check_file_exists(char *filename);
char *read_file(const char *filename);

#endif
