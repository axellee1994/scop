#ifndef PARSER_H
# define PARSER_H

# include "math3d.h"

typedef struct s_mesh
{
    Vector3 *vertices;
    int     *indices;
    int     vertexCount;
    int     indexCount;
}   Mesh;

#endif
