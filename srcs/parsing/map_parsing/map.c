/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:01:01 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/21 15:01:23 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_map(t_data *data, t_list *el)
{
	int		i;
	int		j;
	int		height;
	int		**map;
	int		width;

	data->parsed = 9;
	i = 0;
	j = 0;
	height = 0;
	while (el->content && el->next)
	{
		height++;
		i = ft_strlen(el->content);
		if (data->widthmap < i)
			data->widthmap = i;
		el = el->next;
	}
	width = data->widthmap;
	el = data->firsttoken;
	i = 0;
	map = malloc(sizeof(int*) * height);
	while (i < height)
	{
		map[i] = malloc(sizeof(int) * data->widthmap);
		i++;
	}
	i = 0;
	while (el->content && height > 0)
	{
		while (((char*)el->content)[j] && j <= width)
		{
			if (((char *)el->content)[j] == ' ')
				map[i][j] = -1;
			else if (((char *)el->content)[j] == '0')
				map[i][j] = 7;
			else if (((char *)el->content)[j] == '1')
				map[i][j] = 1;
			else if (((char *)el->content)[j] == '2')
				map[i][j] = 2;
			else if (((char *)el->content)[j] == 'N')
				map[i][j] = 3;
			else if (((char *)el->content)[j] == 'S')
				map[i][j] = 4;
			else if (((char *)el->content)[j] == 'E')
				map[i][j] = 5;
			else if (((char *)el->content)[j] == 'W')
				map[i][j] = 6;
			else
				map[i][j] = 8;
			printf("%d", map[i][j]);
			j++;
		}
		height--;
		printf("\n");
		el = el->next;
		j = 0;
		i++;
	}
	return (1);
}
