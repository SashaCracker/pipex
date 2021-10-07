#include "pipex.h"

void	ft_free(t_pipe *p)
{
	if (p->cmd1 != NULL)
		ft_free_char_array(p->cmd1);
	if (p->cmd2 != NULL)
		ft_free_char_array(p->cmd2);
	if (p->path != NULL)
		free(p->path);
	if (p->mypathes != NULL)
		ft_free_char_array(p->mypathes);
	if (p->cmd1_path != NULL)
		free(p->cmd1_path);
	if (p->cmd2_path != NULL)
		free(p->cmd2_path);
}
