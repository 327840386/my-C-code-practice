#include "adjlist.h"

// Function to create a new adjacency list node
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = numVertices;
    graph->array = (List*)malloc(numVertices * sizeof(List));
    for (int i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* graph) {
    if (graph == NULL)
        return;
    
    // Free each node in the adjacency list
    for (int i = 0; i < graph->num_vertices; ++i) {
        Node* current = graph->array[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}
