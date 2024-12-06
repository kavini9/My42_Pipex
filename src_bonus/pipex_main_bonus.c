/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:21:34 by wweerasi          #+#    #+#             */
/*   Updated: 2024/12/04 02:08:39 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac < 5)
	{
		ft_putendl_fd("# Output: Error: Invalid number of arguments."
			"\n# Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(EXIT_FAILURE);
	}
	pipex_init(&pipex, ac, av, envp);
	ft_pipex(&pipex);
	exit(pipex.status);
}