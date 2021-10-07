#include "pipex.h"

void	ft_mistake(char *massage, t_pipe *p)
{
	ft_putstr(massage);
	ft_free(p);
	exit(1);
}
