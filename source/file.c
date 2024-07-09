#include "file.h"

#include <sys/stat.h>

long int get_file_size(char *filename)
{
	struct stat st;
	long int size;

	if (stat(filename, &st) == -1)
		return -1;

	return size = st.st_size;
}

bool check_file_exists(char *filename)
{
	struct stat st;

	int retval = stat(filename, &st);
	if (retval == -1)
		return false;

	return S_IFREG & st.st_mode;
}
