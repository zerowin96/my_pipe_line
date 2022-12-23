/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:04:17 by yeham             #+#    #+#             */
/*   Updated: 2022/12/23 15:37:58 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

char	**path_maker(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_split2(envp[i] + 5, ':'));
		i++;
	}
	return (0);
}

char	*check_order(char **path, char *cmd)
{
	int		i;
	char	*find;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (path[i])
	{
		find = ft_strjoin(path[i], cmd);
		if (access(find, X_OK) == 0)
			return (find);
		free(find);
		i++;
	}
	return (0);
}

void	insert_pipe(int flag, t_data *all, char *envp[], int fd[])
{
	if (flag == 1)
	{
		all->order1 = check_order(all->path, all->cmd1[0]);
		close(fd[0]);
		if (dup2(all->infile, 0) == -1)
			just_error("dup error");
		if (dup2(fd[1], 1) == -1)
			just_error("dup error");
		close(fd[1]);
		close(all->infile);
		if (execve(all->order1, all->cmd1, envp) == -1)
			just_error("exec error");
	}
	else
	{
		all->order2 = check_order(all->path, all->cmd2[0]);
		close(fd[1]);
		if (dup2(all->outfile, 1) == -1)
			just_error("dup error");
		if (dup2(fd[0], 0) == -1)
			just_error("dup error");
		close(fd[0]);
		close(all->outfile);
		if (execve(all->order2, all->cmd2, envp) == -1)
			just_error("exec error");
	}
}

void	pipe_maker(t_data *all, char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		just_error("pid error");
	else if (pid1 == 0)
		insert_pipe(1, all, envp, fd);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			just_error("pid error");
		else if (pid2 == 0)
			insert_pipe(0, all, envp, fd);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

void	allfree(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	all;

	if (argc != 5)
		just_error("input count");
	all.infile = open(argv[1], O_RDONLY, 0644);
	if (all.infile == -1)
		perror("file open error");
	all.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (all.outfile == -1)
		just_error("file open error");
	all.cmd1 = ft_split(argv[2], ' ');
	all.cmd2 = ft_split(argv[3], ' ');
	all.path = path_maker(envp);
	pipe_maker(&all, envp);
	allfree(all.path);
	allfree(all.cmd1);
	allfree(all.cmd2);
	return (0);
}
