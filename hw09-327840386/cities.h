#ifndef CITIES_H
#define CITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a collection of city names
typedef struct {
    char** names;
    int num_cities;
} Cities;

/**
 * Function to read city names from a file and store them in a Cities structure.
 * 
 * @param fileName The name of the file containing the city names.
 * @return A pointer to a Cities structure containing the read city names, or NULL on failure.
 */
Cities* readCitiesFromFile(const char* fileName);

/**
 * Function to free the memory allocated for a Cities structure.
 * 
 * @param cities A pointer to the Cities structure to be freed.
 */
void freeCities(Cities* cities);

#endif /* CITIES_H */
