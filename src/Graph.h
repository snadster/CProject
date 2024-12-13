#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//style wise, im using: //header//, //subheader

typedef struct Vertex Vertex;
typedef struct Graph Graph;
struct Vertex 
{
	int id; 					// a number in [0; numVertices[
	LinkedList *outNeighbours; // A linked list of vertices.
	LinkedList *inNeighbours; // A linked list of vertices
};

struct Graph 
{
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
	Vertex *arr = malloc(sizeof(Vertex)*n);
	for (int i = 0; i < n; i++) 
	{
		arr[i].id = i;
		arr[i].inNeighbours = LinkedList_new();
		arr[i].outNeighbours = LinkedList_new();
	}
	g->numVertices = n;
	g->numEdges = 0;
	g->vertices = arr;
	return g;
}


// Adds an edge from the i'th to the j'th vertex (0-indexed).
void Graph_addEdge(Graph *g, int i, int j)
{
	void* out = &g -> vertices[j];
	LinkedList_append(g->vertices[i].outNeighbours, out);

	void* in = &g -> vertices[i];
	LinkedList_append(g->vertices[j].inNeighbours, in);

	g->numEdges++;
}


// Reads a graph from the given file and returns a newly
// constructed Graph representing it.
// Returns a pointer to the read graph, or NULL on error.
// Post: the caller owns the graph.
Graph *Graph_read(const char *filename)
{
	//read file//
	//open the file in read mode
	FILE *readFile;
	readFile = fopen(filename, "r");

	//find file size (siz)
	fseek(readFile, 0L, SEEK_END);

	long end = ftell(readFile);
	long start = fseek(readFile, 0L, SEEK_SET);
	
	int siz = end - start;
	
	//store content of file in a char
	char fileData[siz];

	//Read content and store in filedata, if file not empty
	if(readFile != NULL)
	{
		fread(fileData, 1, siz, readFile);
	}
	else
	{
		printf("Not able to open file");
	}

	//now the data is in fileData!//

	int size;
	sscanf(fileData, "%d", &size);

	//make the graph//
	Graph *newGraph = Graph_new(size);
	Graph *p = newGraph;

	//find the first line, excluding the vertex count
	int k = 0;
	for(; fileData[k] != '\n'; k++) {}

	//parsing time//
	int beginning = k + 1;

	//the rows (vertices)
	for(int row = 0; row < size; row++)
	{
		//the columns (edges)
		for(int column = 0; column < size; column++)	//prior math: (i * (fileData[0] + 1)) + 2
		{
			// Specialised for delicius windows newlines (hate them)
			int i = beginning + row*(size+2) + column;
			if(fileData[i] == '1')
			{
				Graph_addEdge(p, row, column);
			}
		}
	}
	
	fclose(readFile);

	return p;
}


// Deallocates the given graph and all its associated memory.
void Graph_delete(Graph *g)
{
	for(int i = 0; i < g->numVertices; i++)
	{
		LinkedList_delete(g->vertices[i].outNeighbours);
		LinkedList_delete(g->vertices[i].inNeighbours);
	}
	free(g->vertices);
	free(g);
}

// Prints some useful information about the given graph.
void Graph_print(Graph *g)
{
	//print amt. of vertices and edges.
	printf("\t\t|DATA|\n ________________________________________________\n");
	printf("| The entered graph contains the following data: |\n");
	printf("  Number of vertices: %d \n", g->numVertices);
	printf("  Number of edges: 	%d \n", g->numEdges);
	printf("|________________________________________________|\n");
	printf(" ________________________________________________\n");
	printf("|The following as an adjecency matrix representation \n of the given graph: \n");
	printf(" ________________________________________________\n");
	printf("|                                                |\n");
	
	//print visual representation of the 
	//accompanying adjecency matrix
	int graphLines = g->numVertices; //nr rows and nr bubbles
	for(int k = 0; k < graphLines; k++)
	{
		for (int j = 0; j < graphLines; j++) 
		{
			void* edge = &g->vertices[j];
			if (LinkedList_find(g->vertices[k].outNeighbours, edge))
			{
				printf("1");
			}
			else 
			{
				printf("0");
			}
		}
		printf("\n");
	}
	printf("|                                                |\n");
	printf(" ________________________________________________\n");
}

#endif // GRAPH_H
