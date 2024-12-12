#ifndef CYCLEDETECTION_H
#define CYCLEDETECTION_H

#include "Graph.h"

// Runs Kahn's algorithm on the graph, and outputs 'CYCLE DETECTED!\n'
// if a DAG cannot be created, or the vertices as a list fx. '4, 0, 1, 3, 2\n'
// representing an ordering in the DAG.
// The output is printed to stdout.
// The input may be altered in the process.
void cycleDetection(Graph *g)
{
    malloc(sizeof(g))
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
//  for each vertex v in graph G with an edge e from u to v, do:
//      if v has no other incoming edges than e, then:
//          insert v in s
//      remove edge e from G
// if G has eny edges left, then:
//      return error    //inpur graph has at least one cycle
// else
//      return L /topological sorted order of vertices








#endif // CYCLEDETECTION_H
