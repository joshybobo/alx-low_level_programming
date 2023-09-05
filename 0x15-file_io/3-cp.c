#include "main.h"

#define BUFSIZE 1024

void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFSIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", file_to);

	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_exit(99, "Error: Can't write to %s\n", file_to);
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_to);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	copy_file(argv[1], argv[2]);

	return (0);
}
