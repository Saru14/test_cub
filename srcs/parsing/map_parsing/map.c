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
	int		height;
	int		**map;
	t_list	*pars;

	data->parsed = 9;
	i = 0;
	j = 0;
	height = 0;
	pars = el;
	//printf("%s", ((char *)el->content));
	//i = ft_strlen(el->content);
	//printf("%d", i);
	pars = pars->next;
	while (el->content && el->next)
	{
		height++;
		i = ft_strlen(el->content);
		//printf("%c\n", ((char *)el->content)[1]);
		if (data->widthmap < i)
			data->widthmap = i;
		el = el->next;
	}
	el = data->firsttoken;
	el = el->next;
	printf("%s\n", ((char *)el->content));
	//printf("%d\n", data->widthmap);
	//printf("%d\n", height);
	i = 0;
	map = malloc(sizeof(int*) * height);
	while (i < height)
	{
		map[i] = malloc(sizeof(int) * data->widthmap);
		i++;
	}
	i = 0;
	printf("lol\n");
	
	while (pars->content)
	{
		while (((char*)pars->content)[j])
		{
			if (((char *)pars->content)[j] == ' ')
				map[i][j] = -1;
			else if (((char *)pars->content)[j] == '0')
				map[i][j] = 7;
			else if (((char *)pars->content)[j] == '1')
				map[i][j] = 1;
			else if (((char *)pars->content)[j] == '2')
				map[i][j] = 2;
			else if (((char *)pars->content)[j] == 'N')
				map[i][j] = 3;
			else if (((char *)pars->content)[j] == 'S')
				map[i][j] = 4;
			else if (((char *)pars->content)[j] == 'E')
				map[i][j] = 5;
			else if (((char *)pars->content)[j] == 'W')
				map[i][j] = 6;
			else
				map[i][j] = 8;
			//printf("%d\n", map[i][j]);
			j++;
		}
		//pars = pars->next;
		i++;
	}
	return (1);
}
