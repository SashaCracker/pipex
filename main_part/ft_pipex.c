#include "pipex.h"

void	ft_pipex(t_pipe *p, char **envp)
{
	pid_t	process1;
	pid_t	process2;

	if (pipe(p->end) < 0)
		ft_mistake("Error in pipe - there is no connection.\n", p);
	process1 = fork();
	if (process1 < 0)
		ft_mistake("Error in fork - child1 process\n", p);
	if (process1 == 0)
		ft_process1(p, envp);
	process2 = fork();
	if (process2 < 0)
		ft_mistake("Error in fork - child2 process\n", p);
	if (process2 == 0)
		ft_process2(p, envp);
	close(p->end[1]);
	close(p->end[0]);
	waitpid(process1, NULL, 0);
	waitpid(process2, NULL, 0);
}
