#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p;

	if (argc != 5)
		ft_mistake("Wrong number of arguments\n", &p);
	p.fd1 = open(argv[1], O_RDONLY);
	p.fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p.fd1 < 0 || p.fd2 < 0)
		ft_mistake("Can't open or create a file\n", &p);
	p.cmd1 = ft_split(argv[2], ' ');
	if (!(p.cmd1[0]))
		ft_mistake("Error - there is no first command\n", &p);
	p.cmd2 = ft_split(argv[3], ' ');
	if (!(p.cmd2[0]))
		ft_mistake("Error - there is no second command\n", &p);
	p.path = ft_my_substr(envp, "PATH");
	if (p.path == NULL)
		ft_mistake("Error - there is no PATH in envp\n", &p);
	p.mypathes = ft_split(p.path, ':');
	p.cmd1_path = ft_path(p.cmd1[0], p.mypathes, &p);
	p.cmd2_path = ft_path(p.cmd2[0], p.mypathes, &p);
	ft_pipex(&p, envp);
	ft_free(&p);
	exit(0);
}
