/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:01:01 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/23 13:28:44 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_map(t_data *data, t_list *el)
{
	int		i;
	int		j;
	int		height;
	int		height2;
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
	height2 = height;
	width = data->widthmap;
	el = data->firsttoken;
	i = 0;
	map = malloc(sizeof(int*) * height);
	while (i < height)
	{
		map[i] = malloc(sizeof(int) * data->widthmap);
		ft_memset(map[i], -1, width * sizeof(int));
		i++;
	}
	i = 0;
	while (el->content && height > 0)
	{
		while (((char*)el->content)[j])
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
			{
				map[i][j] = 3;
				data->position++;
			}
			else if (((char *)el->content)[j] == 'S')
			{
				map[i][j] = 4;
				data->position++;
			}
			else if (((char *)el->content)[j] == 'E')
			{
				map[i][j] = 5;
				data->position++;
			}
			else if (((char *)el->content)[j] == 'W')
			{
				map[i][j] = 6;
				data->position++;
			}
			else
				map[i][j] = 8;
			//printf("%d", map[i][j]);
			j++;
		}
		height--;
		//printf("\n");
		el = el->next;
		j = 0;
		i++;
	}
	if (data->position != 1)
		printf("error position\n");
	ft_verifmap(map, height2, width);
	return (1);
}

int		ft_verifmap(int **map, int height, int width)
{
	ft_verifcharacters(map, height, width);
	ft_verifholes(map, height, width);
	return 1;
}

int		ft_verifholes(int **map, int height, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (map[i][j] <= 7 && map[i][j] >= 2)
			{		
				if (!(j < width - 1) || (j == 0))
				{
					printf("map error 6\n");
					return 1;
				}
				if (!(i < height - 1) || (i == 0))
				{
					printf("map error 6\n");
					return 1;
				}
				if (map[i][j - 1] == -1)
					printf("map error 6\n");
				if (map[i][j + 1] == -1)
					printf("map error 6\n");
				if (map[i + 1][j] == -1)
					printf("map error 6\n");
				if (map[i - 1][j] == -1)
					printf("map error 6\n");
			}
			j++;
		}
		i++;
		j = 0;
	}
	return 1;
}

int		ft_verifcharacters(int **map, int height, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while(j < width)
		{
			if (map[i][j] > 7 || map[i][j] < -1)
				printf("map not valid1\n");
			j++;
		}
		//printf("\n");
		i++;
		j = 0;
	}
	return 1;
}