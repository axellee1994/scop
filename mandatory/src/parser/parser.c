/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlee <axlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:42:40 by axlee             #+#    #+#             */
/*   Updated: 2026/03/22 19:46:36 by axlee            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "parser.h"

void	count_mesh_data(const char *filepath, Mesh *mesh)
{
	int		fd;
	char	*line;

	mesh->vertexCount = 0;
	mesh->indexCount = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Could not open file %s\n", filepath);
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "v ", 2) == 0)
			mesh->vertexCount++;
		else if (ft_strncmp(line, "f ", 2) == 0)
			mesh->indexCount += 3;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	extract_mesh_data(const char *filepath, Mesh *mesh)
{
	int		fd;
	char	*line;
	int		v_idx;
	int		i_idx;

	v_idx = 0;
	i_idx = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "v ", 2) == 0)
			parse_vertex(line, mesh, &v_idx);
		else if (ft_strncmp(line, "f ", 2) == 0)
			parse_face(line, mesh, &i_idx);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse_obj_file(const char *filepath, Mesh *mesh)
{
	count_mesh_data(filepath, mesh);
	if (mesh->vertexCount == 0 || mesh->indexCount == 0)
	{
		ft_printf("Error: Invalid or empty .obj file\n");
		return ;
	}
	mesh->vertices = (Vector3 *)malloc(sizeof(Vector3) * mesh->vertexCount);
	mesh->indices = (int *)malloc(sizeof(int) * mesh->indexCount);
	if (!mesh->vertices || !mesh->indices)
	{
		ft_printf("Error: Memory allocation failed\n");
		return ;
	}
	extract_mesh_data(filepath, mesh);
}
