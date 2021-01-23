/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:41:39 by namenega          #+#    #+#             */
/*   Updated: 2021/01/23 13:26:49 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_parsing_data(t_list *el, t_data *data)
{
	char	*line;

	line = el->content;
	if (!line)
		return (0);
	else if (line[0] == 0)
		return (1);
	else if (line[0] == 'R' && ft_isspace(line[1]))
		return (ft_resolution(data, &line[1]));
	else if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
		return (ft_north(data, &line[2]));
	else if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
		return (ft_south(data, &line[2]));
	else if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
		return (ft_west(data, &line[2]));
	else if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
		return (ft_east(data, &line[2]));
	else if (line[0] == 'S' && ft_isspace(line[1]))
		return (ft_sprite(data, &line[1]));
	else if ((line[0] == 'F') && ft_isspace(line[1]))
		return (ft_color_ground(data, &line[1]));
	else if ((line[0] == 'C') && ft_isspace(line[1]))
		return (ft_color_sky(data, &line[1]));
	if (data->parsed == 8)
	{
		data->firsttoken = el;
		return (ft_map(data, el));
	}
	else
		ft_error_exit("Error\nA line is wrong in the .cub\nExit Program");
	return (1);
}



int		ft_gnl(int fd, char *line, t_data *data)
{
	int		res;
	t_list	*tmp;
	t_list	*each_line;
	
	data->widthmap = 0;
	data->position = 0;
	res = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			return (0);
		ft_lstadd_back(&data->lst_line, tmp);
		res = 1;
	}
	//data->firsttoken = data->lst_line;
	tmp = ft_lstnew(line);
	if (!tmp)
		return (0);
	ft_lstadd_back(&data->lst_line, tmp);
	each_line = data->lst_line;
	while (each_line)
	{
		ft_parsing_data(each_line, data);
		each_line = each_line->next;
	}
	return (res);
}

int		ft_get_data(t_data *data, char *file)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nTask - Reading File : Fail_1!", 1);
		return (0);
	}
	res = ft_gnl(fd, line, data);
	free(line);
	close(fd);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}

t_data	*ft_data(char *file, int ac)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_bzero(data, sizeof(t_data));
	if (ac == 1)
		if ((data->mlx_ptr = mlx_init()) == NULL)
			return (0);
	if (!(ft_get_data(data, file)))
		ft_free_data(data, "Error\nTask - parsing : Fail_2 !");
	if (ac == 1)
		if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "CUB3D")) == NULL)
			ft_free_data(data, "Error\nTask - parsing : Fail_3 !");
	return (data);
}
