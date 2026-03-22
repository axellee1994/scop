#ifndef PARSER_H
# define PARSER_H

# include "math3d.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_mesh
{
    Vector3 *vertices;
    int     *indices;
    int     vertexCount;
    int     indexCount;
}   Mesh;

// Parser functions
void	count_mesh_data(const char *filepath, Mesh *mesh);
void	extract_mesh_data(const char *filepath, Mesh *mesh)
void	parse_obj_file(const char *filepath, Mesh *mesh)

// Extraction vertex and face functions
void    parse_vertex(char *line, Mesh *mesh, int *v_idx);
void    parse_face(char *line, Mesh *mesh, int *i_idx);

#endif
