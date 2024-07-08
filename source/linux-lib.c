#include "linux-lib.h"

#include <sys/stat.h>

static long int get_file_size(char *filename)
{
	struct stat st;
	long int size;

	if (stat(filename, &st) == -1)
		return -1;

	return size = st.st_size;
}
