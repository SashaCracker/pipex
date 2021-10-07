#include "pipex.h"

char	*ft_my_substr(char **s, char *start)
{
	char	*str;
	char	*tmp_start;
	int		i;

	i = 0;
	tmp_start = start;
	while ((*s != NULL) && (*tmp_start != '\0'))
	{
		if (*tmp_start == **s)
		{
			tmp_start++;
			(*s)++;
			i++;
		}
		else
		{
			tmp_start = start;
			s++;
			i = 0;
		}
	}
	if (*s == NULL)
		return (NULL);
	str = ft_strdup(*s - i);
	return (str);
}
