// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include "get_next_line.h"
extern int errno;
int main()
{
	// if file does not have in directory
	// then file foo.txt is created.
	int fd = open("ab.txt", O_RDONLY | O_CREAT);

	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	// if (fd ==-1)
	// {
	// 	// print which type of error have in a code
	// 	printf("Error Number % s\n", errno);

	// 	// print program detail "Success or failure"
	// 	perror("Program");
	// }
	return 0;
}
