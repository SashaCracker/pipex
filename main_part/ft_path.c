#include "pipex.h"

char	*ft_path(char *cmd, char **mypathes, t_pipe *p)
{
	char	*path;
	char	**tmp;
	int		i;

	tmp = mypathes;
	path = NULL;
	i = 0;
	while (tmp[i])
	{
		if (cmd[0] == '/')
			path = ft_strjoin(tmp[i], cmd);
		else
			path = ft_strjoin(ft_strjoin(tmp[i], "/"), cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	ft_mistake("Error - there is no such command\n", p);
	exit(1);
}
