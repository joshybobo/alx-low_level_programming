#include "main.h"
#include <stdlib.h>
#include <unistd.h> // Include the necessary header for open(), read(), write(), and close()

/**
 * read_textfile - Reads a text file and prints it to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read.
 * Return: The actual number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;          // File descriptor
    char *buf;       // Buffer for file content
    ssize_t bytes_read; // Number of bytes read from the file
    ssize_t bytes_written; // Number of bytes written to STDOUT

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    // Allocate memory for the buffer
    buf = malloc(sizeof(char) * letters);
    if (buf == NULL)
    {
        close(fd); // Close the file descriptor on memory allocation failure
        return (0);
    }

    // Read from the file into the buffer
    bytes_read = read(fd, buf, letters);

    // Write the buffer contents to STDOUT
    bytes_written = write(STDOUT_FILENO, buf, bytes_read);

    // Free the allocated memory and close the file
    free(buf);
    close(fd);

    return (bytes_written);
}
