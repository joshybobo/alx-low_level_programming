#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t betty_read_textfile(const char *filename, size_t letters);
int betty_create_file(const char *filename, char *text_content);
int betty_append_text_to_file(const char *filename, char *text_content);

#endif
