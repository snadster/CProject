#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

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
	// allocate space 
	Graph *g = malloc(sizeof(Graph));
	Vertex *arr = malloc(sizeof(Vertex)*n);
	for (int i = 0; i < n; i++) 
	{
		arr[i].id = i;
		arr[i].inNeighbours = LinkedList_new();
		arr[i].outNeighbours = LinkedList_new();
	}
	// assign values
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
	// read file //
	// open the file in read mode
	FILE *readFile;
	readFile = fopen(filename, "r");

	// find file size (siz)
	fseek(readFile, 0L, SEEK_END);

	long end = ftell(readFile);
	long start = fseek(readFile, 0L, SEEK_SET);
	
	int siz = end - start;
	
	// store content of file in a char
	char fileData[siz];

	// Read content and store in filedata, if file not empty
	if(readFile != NULL)
	{
		fread(fileData, 1, siz, readFile);
	}
	else
	{
		printf("Not able to open file");
	}

	// now the data is in fileData!//

	int num;
	sscanf(fileData, "%d", &num);

	// make the graph //
	Graph *newGraph = Graph_new(num);

	// find the first line, excluding the vertex count
	int k = 0;
	for(; fileData[k] != '\n'; k++) {}

	// parsing time //
	int beginning = k + 1;

	// the rows (vertices)
	for(int row = 0; row < num; row++)
	{
		// the columns (edges)
		for(int column = 0; column < num; column++)
		{
			// specialised for windows newlines (hate them)
			int i = beginning + row*(num+2) + column;
			if(fileData[i] == '1')
			{
				Graph_addEdge(newGraph, row, column);
			}
		}
	}
	
	fclose(readFile);

	return newGraph;
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
// (and prints some stylish ascii)
void Graph_print(Graph *g)
{
	//define nr. of rows and columns.
	int graphLines = g->numVertices;

	// aesthetics and ascii art //
	// we highly reccomend printing this function
	// in order to see its full potential.
	// !! the wrap-around breaks it by graphmatrix-5.txt !!
	printf("            ____    _  _____  _     \n");
	printf("           |  _ \\  / \\|_   _|/ \\    \n");
	printf("           | | | |/ _ \\ | | / _ \\   \n");
	printf("           | |_| / ___ \\| |/ ___ \\  \n");
	printf("           |____/_/   \\_\\_/_/   \\_\\ \n");
	printf("\n");
	printf(" ________________________________________________\n");
	printf("| The entered graph contains the following data: |\n");
	printf("  Number of vertices: %d \n", g->numVertices);
	printf("  Number of edges:    %d \n", g->numEdges);
	printf("|________________________________________________|\n");
	printf(" ________________________________________________\n");
	printf("|  The following is an adjecency matrix          | \n  representation of the given graph: \n");
	printf(" ");

	// printing the matrix correctly (and in style) //
	// style
	for(int s = 0; s < (graphLines+1); s++)
	{
		printf("__");
	}
	printf("_");
	printf("\n");
	printf("|");
	for(int s = 0; s < (graphLines+1); s++)
	{
		printf("  ");
	} 
	printf(" ");
	printf("|\n");
	
	//visual representation of the adjecency matrix
	for(int k = 0; k < graphLines; k++)
	{
		printf("  ");
		for (int j = 0; j < graphLines; j++) 
		{
			void* edge = &g->vertices[j];
			if (LinkedList_find(g->vertices[k].outNeighbours, edge))
			{
				printf(" 1");
			}
			else 
			{
				printf(" 0");
			}
		}
		printf("\n");
	}

	// more style
	printf("|");
	for(int s = 0; s < (graphLines+1); s++)
	{
		printf("__");
	}
	printf("_");
	printf("|\n");
	printf("\n\n\n");
}


// spreads some christmas cheer
void MerryChristmas()
{
	printf("         |\n");
	printf("        -+-\n");
	printf("         A\n");
	printf("        /=\\               /\\  /\\    ___  _ __  _ __ __    __ \n");
	printf("      i/ O \\i            /  \\/  \\  / _ \\| '__|| '__|\\ \\  / / \n");
	printf("      /=====\\           / /\\  /\\ \\|  __/| |   | |    \\ \\/ / \n");
	printf("      /  i  \\           \\ \\ \\/ / / \\___/|_|   |_|     \\  / \n");
	printf("    i/ O * O \\i                                       / /\n");
	printf("    /=========\\        __  __                        /_/    _\n");
	printf("    /  *   *  \\        \\ \\/ /        /\\  /\\    __ _  ____  | |\n");
	printf("  i/ O   i   O \\i       \\  /   __   /  \\/  \\  / _` |/ ___\\ |_|\n");
	printf("  /=============\\       /  \\  |__| / /\\  /\\ \\| (_| |\\___ \\  _\n");
	printf("  /  O   i   O  \\      /_/\\_\\      \\ \\ \\/ / / \\__,_|\\____/ |_|\n");
	printf("i/ *   O   O   * \\i\n");
	printf("/=================\\\n");
	printf("       |___|\n\n");
	printf("(and a happy new year :)\n\n");

}

#endif // GRAPH_H
