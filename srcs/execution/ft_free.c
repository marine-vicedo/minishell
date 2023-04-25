/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:58:49 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 22:39:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

void	free_exec(t_data *data, t_cmd *cmd)
{
	cmdclear(cmd);
	free_lst(&data->env_lst);
	free_tab((void **)data->env_cpy);
}

int	heredoc_pipe(t_here *here, t_data *data, char *str)
{
	int	i;

	i = -1;
	if (!data->nbr_here)
		return (-1);
	while (++i < data->nbr_here)
	{
		if (!ft_strcmp(data->here[i].delim, str))
			return (here[i].pipe[0]);
	}
	return (-1);
}
