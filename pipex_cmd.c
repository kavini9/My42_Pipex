/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:32:07 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:38:31 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	**get_arr_path(char **envp)
{
	char	**arr_path;

	arr_path = NULL;
	if (!envp || !*envp)
		return (NULL); //check what kind of error this may cause
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (*envp)
		arr_path = ft_split( *envp + 5, ':');
	if (!arr_path)
		printf("arr_path = ft_split crashed");
	return (arr_path);
}

char	**get_arr_cmd(char **argv, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex -> cmd = malloc((pipex -> cmd_count + 1) * sizeof(*char));
	while(i < pipex -> cmd_count)
		if (strchr(argv[i + 2 + heredoc]), ' ')
			pipex -> cmd[i] = ft_split(argv[i +2 + heredoc], ' ');
		if (!cmd_arr[i])
			printf("cmd_arr crashed at split");
		if (!strchr(cmd_arr[i][0],'/'))
			path = get_cmd_path(pipex);
}

int main(int argc, char **argv, char **envp)
{
	char **path_array;
//	char **cmd_path;
	char **temp;


	(void)argv;
	(void)argc;
	path_array = get_arr_path(envp);
	temp = path_array;
	while (*path_array)
	{
		printf("argv = %s_\n", *path_array);
		path_array++;	
	}
	path_array = temp;
	while (*temp)
	{
		printf("free = %s_\n", *temp);
		free(*temp);
		*temp =NULL;
		temp++;
	}
	free(path_array);
	path_array = NULL;

}