/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:30:09 by wweerasi          #+#    #+#             */
/*   Updated: 2024/12/05 00:09:37 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	close_pfds(t_pipex *pipex)
{
	int	i;

	if (!pipex -> pfds)
		return;
	i = 0;
	while (i < pipex -> cmd_count - 1)
	{
		if (pipex -> pfds[2 * i] > 0)
			close(pipex -> pfds[2 * i]);
		else
			break ;
		if (pipex -> pfds[2 * i + 1] > 0)
			close(pipex -> pfds[2 * i + 1]);
		else
			break ;
		i++;
	}
	free(pipex -> pfds);
	pipex -> pfds = NULL;
}

void	free_arr(char ***arr)
{
	char	**tmp;

	tmp = *arr;
	while (*arr && **arr)
	{
		free(**arr);
		**arr = NULL;
		(*arr)++;
	}
	free(tmp);
	tmp = NULL;
}

void	pipex_clean(t_pipex *pipex)
{
	free_arr(&(pipex -> arr_path));
	free_arr(&(pipex -> cmd_arr));
	if (pipex -> path)
		free(pipex -> path);
	close_pfds(pipex);
}

void	pipex_sys_error(char *sys_call, char *param, t_pipex *pipex)
{
	ft_putstr_fd(sys_call, STDERR_FILENO);
	ft_putstr_fd(param , STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	pipex_clean(pipex);
	exit(pipex -> status);
}

void	pipex_error(char *err_note, t_pipex *pipex)
{
	ft_putstr_fd(err_note, STDERR_FILENO);
	ft_putstr_fd(":", STDERR_FILENO);
	pipex_clean(pipex);
	exit(pipex -> status);
}
