#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"

typedef struct Vertex Vertex;
typedef struct Graph Graph;
struct Vertex {
	int id; // a number in [0; numVertices[
	LinkedList *outNeighbours; // A linked list of vertices.
	LinkedList *inNeighbours; // A linked list of vertices
};

struct Graph {
	int numVertices;
	int numEdges;
	Vertex *vertices; // An array of numVertices vertices
};

// Allocates and constructs a new graph with n vertices.
// Returns a pointer to the new graph, or NULL on error.
// Post: the caller owns the graph.
Graph *Graph_new(int n);
	Graph *g = malloc(sizeof(Graph));
	Vertex *arr[n];
	for (int i = 0; i < n; i++){
		arr[i].outNeighbours = LinkedList_new();
		arr[i].inNeighbours = LinkedList_new(); 
	}
	struct Graph newGraph = {n, 0, arr};
	g = newGraph;
	return g

// Adds an edge from the i'th to the j'th vertex (0-indexed).
void Graph_addEdge(Graph *g, int i, int j);
	struct LinkedListNode newEdgeOut = {NULL, NULL, g.vertices[j]};
	LinkedList_append(g.vertices[i].outNeighbours, newEdgeOut);

	struct LinkedListNode newEdgeIn = {NULL, NULL, g.vertices[i]};
	LinkedList_append(g.vertices[j].inNeighbours, newEdge);

// Reads a graph from the given file and returns a newly
// constructed Graph representing it.
// Returns a pointer to the read graph, or NULL on error.
// Post: the caller owns the graph.
Graph *Graph_read(const char *filename);
	//open the file in read mode
	readFile = fopen("filename", "r");

	//find file size
	fseek(readFile, 0L, SEEK_END);
	end = ftell(readFile);
	start = fseek(readFile, 0L, SEEK_SET);
	
	siz = end - start;

	//store content of file in a string
	char fileData[siz];

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
	//now the data is in fileData
	//make the graph
	Graph karen = Graph_new();

	//time to parse it i guess, if statements abound
	int edges = 0;
	for(int i = 0; i < fileData[0]; i++)
	{
		for(int j = (i * (fileData[0] + 1)) + 2; fileData[j] != "\n"; j++)
		{
			if(fileData[j] == 1)
			{
				edges++;
				Graph_addEdge(karen, i, j-2);
			}
		}
	}
	karen.numEdges = edges;
	
	fclose(readFile);

// Deallocates the given graph and all its associated memory.
void Graph_delete(Graph *g);

// Prints some useful information about the given graph.
void Graph_print(Graph *g);

#endif // GRAPH_H
