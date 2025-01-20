#include "cities.h"

// Function to read cities from a file and store them in a Cities structure
Cities* readCitiesFromFile(const char* fileName) {
    // Open the file for reading
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    // Create a new Cities structure
    Cities* cities = (Cities*)malloc(sizeof(Cities));
    cities->names = NULL;
    cities->num_cities = 0;
    
    // Read each line from the file and store the city names
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        cities->names = realloc(cities->names, (cities->num_cities + 1) * sizeof(char*));
        cities->names[cities->num_cities] = strdup(line);
        cities->num_cities++;
    }
    
    // Close the file
    fclose(file);
    return cities;
}

// Function to free the memory allocated for the Cities structure
void freeCities(Cities* cities) {
    if (cities == NULL)
        return;

    // Free each city name and the array of city names
    for (int i = 0; i < cities->num_cities; ++i)
        free(cities->names[i]);
    free(cities->names);
    free(cities);
}
