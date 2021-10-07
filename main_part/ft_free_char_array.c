#include "pipex.h"

void	ft_free_char_array(char **array)
{
	char	*tmp;

	while (*array != NULL)
	{
		tmp = *array;
		array++;
		free(tmp);
	}
}
