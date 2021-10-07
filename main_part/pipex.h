#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_pipe
{
	char		**cmd1;
	char		**cmd2;
	int			fd1;
	int			fd2;
	int			end[2];
	char		*path;
	char		**mypathes;
	char		*cmd1_path;
	char		*cmd2_path;
}				t_pipe;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_putstr(char *str);
char	*ft_my_substr(char **s, char *start);
void	ft_free_char_array(char **array);
char	*ft_path(char *cmd, char **mypathes, t_pipe *p);
void	ft_free(t_pipe *p);
void	ft_pipex(t_pipe *p, char **envp);
void	ft_mistake(char *massage, t_pipe *p);
void	ft_process1(t_pipe *p, char **envp);
void	ft_process2(t_pipe *p, char **envp);

#endif
