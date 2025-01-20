#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cities.h"
#include "dijkstra.h"
#include "adjlist.h"

// Main function to find the shortest path between two cities
int main(int argc, char* argv[]) {
    char* fileNameCities = NULL;
    char* fileNameDistances = NULL;
    char* cityFrom = NULL;
    char* cityTo = NULL;

    // Read command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 < argc) {
                fileNameCities = argv[++i];
            } else {
                printf("Missing argument for -c\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc) {
                fileNameDistances = argv[++i];
            } else {
                printf("Missing argument for -d\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                cityFrom = argv[++i];
            } else {
                printf("Missing argument for -f\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-t") == 0) {
            if (i + 1 < argc) {
                cityTo = argv[++i];
            } else {
                printf("Missing argument for -t\n");
                return 1;
            }
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }
    
    // Check if all required arguments are provided
    if (!fileNameCities || !fileNameDistances || !cityFrom || !cityTo) {
        printf("Usage: %s -c <cities_file> -d <distances_file> -f <city_from> -t <city_to>\n", argv[0]);
        return 1;
    }

    // Read cities and distances from files
    Cities* cities = readCitiesFromFile(fileNameCities);
    Graph* graph = createGraph(cities->num_cities);

    // Read distances from file and populate the graph
    FILE* file = fopen(fileNameDistances, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", fileNameDistances);
        return 1;
    }
    
    // Read distances from file and populate the graph
    char from[256], to[256];
    int distance;
    while (fscanf(file, "%s %s %d", from, to, &distance) != EOF) {
        int src = -1, dest = -1;
        for (int i = 0; i < cities->num_cities; ++i) {
            if (strcmp(cities->names[i], from) == 0)
                src = i;
            if (strcmp(cities->names[i], to) == 0)
                dest = i;
        }
        if (src != -1 && dest != -1)
            addEdge(graph, src, dest, distance);
    }

    fclose(file);

    // Find shortest path
    int src = -1, dest = -1;
    for (int i = 0; i < cities->num_cities; ++i) {
        if (strcmp(cities->names[i], cityFrom) == 0)
            src = i;
        if (strcmp(cities->names[i], cityTo) == 0)
            dest = i;
    }
    
    // Check if the cities are found in the data
    if (src == -1 || dest == -1) {
        printf("City not found in the provided data.\n");
        return 1;
    }
    
    // Perform Dijkstra's algorithm
    DijkstraResult result = dijkstra(graph, src, dest);

    // Print result
    if (result.distance != INT_MAX) {
        printf("Origin: %s\n", cityFrom);
        printf("Destination: %s\n", cityTo);
        printf("Distance: %d\n", result.distance);
        printf("Path cities:\n");
        // Store path cities in an array
        char* pathCities[100]; 
        int pathLength = 0;
        int current = dest;
        while (current != -1) {
            pathCities[pathLength++] = cities->names[current];
            current = result.parents[current];
        }

        // Print path cities
        for (int i = pathLength - 1; i >= 0; i--) {
             printf("%s\n", pathCities[i]);
        }

    } else {
        printf("No path found from %s to %s\n", cityFrom, cityTo);
    }

    // Free allocated memory
    freeCities(cities);
    freeGraph(graph);
    free(result.parents);

    return 0;
}


