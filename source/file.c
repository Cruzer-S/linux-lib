#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <unistd.h>
#include <fcntl.h>

#include <sys/stat.h>

long int get_file_size(const char *filename)
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

char *read_file(const char *filename)
{
	char *content;
	long int filesize;
	long int readlen;
	int fd;

	filesize = get_file_size(filename);

	content = malloc(filesize + 1);
	if (content == NULL)
		goto RETURN_NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		goto FREE_CONTENT;

	readlen = 0;
	while (true) {
		ssize_t len = read(fd, content + readlen, filesize - readlen);

		if (len == 0)
			break;

		if (len == -1)
			goto CLOSE_FD;

		readlen += len;
	}

	if (readlen != filesize)
		goto CLOSE_FD;

	content[filesize] = '\0';

	close(fd);

	return content;

CLOSE_FD:	close(fd);
FREE_CONTENT:	free(content);
RETURN_NULL:	return NULL;
}
