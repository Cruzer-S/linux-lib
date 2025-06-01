#ifndef FILE_H__
#define FILE_H__

#include <stdbool.h>

#define TIMESTAMP_FORMAT_WIKIPEDIA "%d %B %Y, at %H:%M (UTC)"

enum file_time_type {
	FILE_TIME_TYPE_CREATE,
	FILE_TIME_TYPE_MODIFIED,
	FILE_TIME_TYPE_ACCESSED
};

long int get_file_size(const char *filename);
bool check_file_exists(char *filename);
char *read_file(const char *filename);
char *get_file_time(const char *filename, enum file_time_type, char *format);

#endif
