#include "get_next_line.h"

#include <stdio.h>
int     main(void)
{
char    *line;
int     fd;
int	res;

fd = open("text.txt", O_RDONLY);
while ((res = get_next_line(fd, &line)))
{
	printf("res = %d, line is: %s\n", res, line);
	free(line);
}

printf("res = %d, line is:%s\n ",res, line);

return(0);
}
