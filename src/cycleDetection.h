#ifndef CYCLEDETECTION_H
#define CYCLEDETECTION_H

#include "Graph.h"
#include "LinkedList.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

// Runs Kahn's algorithm on the graph, and outputs 'CYCLE DETECTED!\n'
// if a DAG cannot be created, or the vertices as a list fx. '4, 0, 1, 3, 2\n'
// representing an ordering in the DAG.
// The output is printed to stdout.
// The input may be altered in the process.
void cycleDetection(Graph *g)
{
    //S contains the id of the vertices with no in-neighbours
    int S[g->numVertices], first = 0, last = 0;
    for (int i = 0; i < g->numVertices; i++) 
    {
        if (g->vertices[i].inNeighbours->size == 0) 
        {
            S[last++] = i; 
        }
    }

    int visited = 0;
    int L[g->numVertices];

    while (first < last) 
    {
        int u = S[first++];
        L[visited++] = u;

        for (int v = 0; v < g->numVertices; v++) 
        {
            void* p = &g -> vertices[v]; 
            if (LinkedList_find(g->vertices[u].outNeighbours, p))
            {
                if (g->vertices[v].inNeighbours->size == 1) 
                {
                    S[last++] = v;
                }
                LinkedList_remove(g->vertices[u].outNeighbours, p);
                void* p_ = &g -> vertices[u];
                LinkedList_remove(g->vertices[v].inNeighbours, p_);
                g->numEdges--;
            }
        }
    }

    if (g->numEdges != 0) 
    {
        printf("Cycle detected!");
    }
    else 
    {
        for (int i = 0; i < g->numVertices; i++) 
        {
            printf("%d\n", L[i]);
        }
    }
}
#endif // CYCLEDETECTION_H
