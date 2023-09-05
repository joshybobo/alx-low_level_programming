#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void error_exit(const char *msg);
void print_elf_header(const char *filename);

void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

void print_elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit("Cannot read ELF header");

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
		error_exit("Not an ELF file");

	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");

	printf("  Class:                             %s\n",
	       header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
	       header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid");

	printf("  Data:                              %s\n",
	       header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid");

	printf("  Version:                           %d (current)\n",
	       header.e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
		default: printf("<unknown>\n");
	}

	printf("  ABI Version:                       %d\n",
	       header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE: printf("NONE (Unknown type)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown>\n");
	}

	printf("  Entry point address:               %#lx\n",
	       (unsigned long)header.e_entry);

	close(fd);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	print_elf_header(argv[1]);

	return (0);
}
