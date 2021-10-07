#include "pipex.h"

void	ft_process1(t_pipe *p, char **envp)
{
	if (dup2(p->fd1, STDIN_FILENO) == -1)
		ft_mistake("Error in dup2 with fd - child1 process\n", p);
	if (dup2(p->end[1], STDOUT_FILENO) == -1)
		ft_mistake("Error in dup2 with end - child1 process\n", p);
	if (close(p->fd2) == -1)
		ft_mistake("Can't close fd2 - child1 process\n", p);
	if (close(p->end[0]) == -1)
		ft_mistake("Can't close end[0] - child1 process\n", p);
	execve(p->cmd1_path, p->cmd1, envp);
}
