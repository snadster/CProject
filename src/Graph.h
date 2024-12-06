#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include <stdio.h>

//style wise, im using: //header//, //subheader

typedef struct Vertex Vertex;
typedef struct Graph Graph;
struct Vertex {
	int id; 					// a number in [0; numVertices[
	LinkedList *outNeighbours; // A linked list of vertices.
	LinkedList *inNeighbours; // A linked list of vertices
};

struct Graph {
	int numVertices;
	int numEdges;
	Vertex *vertices; 		   // An array of numVertices vertices
};


// Allocates and constructs a new graph with n vertices.
// Returns a pointer to the new graph, or NULL on error.
// Post: the caller owns the graph.
Graph *Graph_new(int n)
{
	Graph *g = malloc(sizeof(Graph));
	Vertex *arr[n];
	for (int i = 0; i < n; i++){
		arr[i].outNeighbours = LinkedList_new();
		arr[i].inNeighbours = LinkedList_new(); 
	}
	struct Graph newGraph = {n, 0, arr};
	Graph g = newGraph;
	return g;
}


// Adds an edge from the i'th to the j'th vertex (0-indexed).
void Graph_addEdge(Graph *g, int i, int j)
{
	struct LinkedListNode newEdgeOut = {NULL, NULL, g.vertices[j]};
	LinkedList_append(g.vertices[i].outNeighbours, newEdgeOut);

	struct LinkedListNode newEdgeIn = {NULL, NULL, g.vertices[i]};
	LinkedList_append(g.vertices[j].inNeighbours, newEdge);
}


// Reads a graph from the given file and returns a newly
// constructed Graph representing it.
// Returns a pointer to the read graph, or NULL on error.
// Post: the caller owns the graph.
Graph *Graph_read(const char *filename)
{
	//read file//
	//open the file in read mode
	int readFile = fopen("filename", "r");

	//find file size (siz)
	fseek(readFile, 0L, SEEK_END);
	long end = ftell(readFile);
	long start = fseek(readFile, 0L, SEEK_SET);
	
	int siz = end - start;

	//store content of file in a char
	char fileData[siz];

	//read the data into the file, it it is not empty
	if(readFile != NULL)
	{
		while(fgets(fileData, siz, readFile))
		{
			printf("%S", fileData);
		}
	}
	else
	{
		printf("Not able to open file");
	}

	//now the data is in fileData!//

	//make the graph//
	Graph karen = Graph_new();

	//find the first line, excluding the vertex count
	int k = 0;
	for(; fileData[k] != '\n'; k++)
	{
		return k;
	}

	//parsing time//
	int firstLine = k + 1;
	int edges = 0;

	//the rows (vertices)
	for(int i = 0; i < fileData[0]; i++)
	{
		//the columns (edges)
		for(int j = firstLine; fileData[j] != "\n"; j++)	//prior math: (i * (fileData[0] + 1)) + 2
		{
			if(fileData[j] == 1)
			{
				edges++;
				Graph_addEdge(karen, i, j-2);
			}
		}
	}
	//update edges on the graph?
	karen.numEdges = edges;
	
	fclose(readFile);
}


// Deallocates the given graph and all its associated memory.
void Graph_delete(Graph *g);

// Prints some useful information about the given graph.
void Graph_print(Graph *g);

#endif // GRAPH_H
