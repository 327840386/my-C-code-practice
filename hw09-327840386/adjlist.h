#ifndef ADJLIST_H
#define ADJLIST_H

#include "cities.h"

// Structure representing a node in the adjacency list
typedef struct {
    int dest;
    int weight;
    struct Node* next;
} Node;

// Structure representing an adjacency list
typedef struct {
    Node* head;
} List;

// Structure representing a graph using an array of adjacency lists
typedef struct {
    int num_vertices;
    List* array;
} Graph;

/**
 * Function to create a new graph with the given number of vertices.
 * 
 * @param numVertices The number of vertices in the graph.
 * @return A pointer to the newly created graph.
 */
Graph* createGraph(int numVertices);

/**
 * Function to add a directed edge to the graph.
 * 
 * @param graph The graph to which the edge is added.
 * @param src The source vertex of the edge.
 * @param dest The destination vertex of the edge.
 * @param weight The weight of the edge.
 */
void addEdge(Graph* graph, int src, int dest, int weight);

/**
 * Function to free the memory allocated for the graph.
 * 
 * @param graph The graph to be freed.
 */
void freeGraph(Graph* graph);

#endif /* ADJLIST_H */
