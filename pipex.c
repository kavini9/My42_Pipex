/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:51:32 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/10 19:02:53 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5){
		ft_putendl_fd("Error: Invalid format detected. Please use the 
				correct format:\n./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex();
}


