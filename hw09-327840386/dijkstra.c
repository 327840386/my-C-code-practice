#include "dijkstra.h"
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int* distances, int* visited, int numVertices) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && distances[v] < min) {
            min = distances[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to perform Dijkstra's algorithm and find the shortest paths from a source vertex to all other vertices
DijkstraResult dijkstra(Graph* graph, int src, int dest) {
    DijkstraResult result;
    int numVertices = graph->num_vertices;
    int* distances = (int*)malloc(numVertices * sizeof(int));
    int* visited = (int*)malloc(numVertices * sizeof(int));
    int* parents = (int*)malloc(numVertices * sizeof(int));

    // Initialize distances, visited, and parents arrays
    for (int i = 0; i < numVertices; ++i) {
        distances[i] = INT_MAX;
        visited[i] = 0;
        parents[i] = -1;
    }

    // Distance from source to itself is 0
    distances[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numVertices - 1; ++count) {
        int u = minDistance(distances, visited, numVertices);
        if (u == -1 || u == dest) {
            break; // All reachable vertices have been processed or destination reached
        }

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update distance value of the adjacent vertices of the selected vertex
        Node* current = graph->array[u].head;
        while (current != NULL) {
            int v = current->dest;
            int weight = current->weight;
            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parents[v] = u;
            }
            current = current->next;
        }
    }

    // Store the result
    result.distance = distances[dest];
    result.parents = parents;
    result.numVertices = numVertices;
    
    // Free memory
    free(visited);
    free(distances);

    return result;
}
