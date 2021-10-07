#include "pipex.h"

void	ft_process2(t_pipe *p, char **envp)
{
	if (dup2(p->fd2, STDOUT_FILENO) == -1)
		ft_mistake("Error in dup2 with fd - child2 process\n", p);
	if (dup2(p->end[0], STDIN_FILENO) == -1)
		ft_mistake("Error in dup2 with end - child2 process\n", p);
	if (close(p->end[1]) == -1)
		ft_mistake("Can't close end[1] - child2 process\n", p);
	if (close(p->fd1) == -1)
		ft_mistake("Can't close fd1 - child2 process\n", p);
	execve(p->cmd2_path, p->cmd2, envp);
}
