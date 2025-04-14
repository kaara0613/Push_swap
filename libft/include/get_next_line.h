# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 1

#include <stdlib.h>

char	*get_next_line(int fd);
size_t	free_and_reset(char **buffer);

# endif