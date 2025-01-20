#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "adjlist.h"

// Structure representing the result of Dijkstra's algorithm
typedef struct {
    int* parents;
    int* distances;
    int numVertices;
    int distance;
} DijkstraResult;

/**
 * Function to perform Dijkstra's algorithm and find the shortest path from a source vertex to a destination vertex.
 * 
 * @param graph The graph in which the shortest path is to be found.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return A structure containing the result of the algorithm, including the shortest path and distance.
 */
DijkstraResult dijkstra(Graph* graph, int src, int dest);

#endif /* DIJKSTRA_H */
