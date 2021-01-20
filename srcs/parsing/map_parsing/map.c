/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:01:01 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/20 17:29:30 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_map(t_data *data, t_list *el)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		**map;
	t_list	*pars;

	data->parsed = 8;
	i = 0;
	j = 0;
	width = 0;
	height = 0;
	pars = el;
	while (el->content && el->next)
	{
		height++;
		i = 0;
		while (((char *)el->content)[i])
		{
			printf("%c", ((char *)el->content)[i]);

			i++;
		}
		printf("\n");
		if (width < i)
			width = i;
		el = el->next;
	}
	i = 0;
	map = malloc(sizeof(int*) * height);
	while (i < height)
	{
		map[i] = malloc(sizeof(int) * width);
		i++;
	}
	i = 0;
	while (pars->content)
	{
		while (((char*)pars->content)[i])
		{
			if (((char *)pars->content)[i] == ' ')
				map[i][j] = -1;
			else if (((char *)pars->content)[i] == '0')
				map[i][j] = 7;
			else if (((char *)pars->content)[i] == '1')
				map[i][j] = 1;
			else if (((char *)pars->content)[i] == '2')
				map[i][j] = 2;
			else if (((char *)pars->content)[i] == 'N')
				map[i][j] = 3;
			else if (((char *)pars->content)[i] == 'S')
				map[i][j] = 4;
			else if (((char *)pars->content)[i] == 'E')
				map[i][j] = 5;
			else if (((char *)pars->content)[i] == 'W')
				map[i][j] = 6;
			else
				map[i][j] = 8;
			j++;
		}
		pars = pars->next;
		i++;
	}
	return (1);
}
