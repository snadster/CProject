#ifndef CYCLEDETECTION_H
#define CYCLEDETECTION_H

#include "Graph.h"
#include "LinkedList.h"
#include <errno.h>

// Runs Kahn's algorithm on the graph, and outputs 'CYCLE DETECTED!\n'
// if a DAG cannot be created, or the vertices as a list fx. '4, 0, 1, 3, 2\n'
// representing an ordering in the DAG.
// The output is printed to stdout.
// The input may be altered in the process.
void cycleDetection(Graph *g)
{
    Vertex L[g->numVertices];
    int gVerts = g->numVertices;
    int count;
    //set of vertices of G with no incoming edges
    for(int x = 0; x <= gVerts; x++)
    {
        //i need the specific vertex to interact with
        //bc i need to add the vertices with 0 in neighbors to s.
        if(g->vertices[x].inNeighbours->size == 0)
        {
            count++;
        }
    }
    Vertex S[count]; //a set of vertices? 

    int indexS = 0;
    int indexG = 0;
    while (indexS < (sizeof(S) / sizeof(S[0]))) 
    {
        if (g->vertices[indexG].inNeighbours->size == 0) 
        {
            S[indexS] = g->vertices[indexG];
            indexS++;
            indexG++;
        }
        else {
            indexG++;
        }
    }

    while (S != empty)
    {
        u = //remove a node/vertice from S, first i need S tho.
        append(L, u);
        // need only the vertices with an edge from u to v, how?
        for(v=0; v >= sizeof(g); v++)
        {
            if (v.inNeighbors == [])
            {
                append(S, v);
                //remove edge e from graph G?
            }
        }

    }

    if (g.numEdges != 0)
    {
        printf("Error: %d\n", errno);
    }
    else
    {
        return L;
    }
}


// data: input graph G
// result: vertices of G in topological order, or an error
//         if the graph is NOT DAG. if it is, the list L 
//         will contain the ordering of vertices
// L : empty list of vertices
// S : a set of all vertices of G with NO incoming edges.
// while S != empty, do:
//  u <- node removed from S
//  append u to the tail of L
//
//  for each vertex v in graph with an edge e from u to v, do:
//      if v has no other incoming edges than e, then:
//          insert v in s
//      remove edge e from G
// if G has eny edges left, then:
//      return error    //inpur graph has at least one cycle
// else
//      return L /topological sorted order of vertices

#endif // CYCLEDETECTION_H
