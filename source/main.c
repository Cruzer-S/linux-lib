#include <stdio.h>
#include <stdlib.h>

#include "file.h"

#define FILE_PATH "output"

int main(void)
{
	char *timestamp;

	timestamp = get_file_time(
		FILE_PATH, FILE_TIME_TYPE_MODIFIED, TIMESTAMP_FORMAT_WIKIPEDIA
	);

	if (timestamp == NULL)
		exit(EXIT_FAILURE);

	printf("%s: last modified: %s\n", FILE_PATH, timestamp);

	return 0;
}
