#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd, n;
	char buf[1024];
	fd = open("test.c", O_RDONLY);
	if(fd < 0)
	{
		perror("open file");
		exit(-1);
	}
	while((n = read(fd, buf, sizeof(buf))) > 0)
	{
		write(STDOUT_FILENO, buf, n);
	}
	return 0;
}
