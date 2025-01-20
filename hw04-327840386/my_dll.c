// =================== Support Code =================
// Doubly Linked List ( Team DLL ).SP
//
// - Refer to my_dll.h for the structure definitions.
// - Implement each of the functions to create a working DLL that represents a hockey team.
// - Do not change any of the function declarations
//   - (i.e. team_t* create_team() should not have additional arguments)
// - You should not have any 'printf' statements in your functions.
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc. 0x7E7)
// ==================================================

#include <stdlib.h>
#include <string.h>
#include "my_dll.h" // Include the header file

// Creates a Team
// Returns a pointer to a newly created Team.
// The Team should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The Team fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
team_t* create_team() {
    // Modify the body of this function as needed.
    // Allocate memory for the team structure
    team_t* myTeam = (team_t*)malloc(sizeof(team_t));
    if (myTeam == NULL) // Check if memory allocation failed
        return NULL;
    
    // Initialize team fields
    myTeam->activePlayers = 0;
    myTeam->head = NULL;
    myTeam->tail = NULL;
    return myTeam; // Note: This line is a 'filler' so the code compiles.
}

// Team DLL Empty
// Check if the team is empty
// Returns -1 if the team is NULL.
// Returns 1 if true (The team is completely empty)
// Returns 0 if false (the team DLL has at least one player enqueued)
int team_empty(team_t* l) {
    if (l == NULL)
        return -1; // Team is NULL
    
    return (l->head == NULL); // Return 1 if team is empty, 0 otherwise
}

// Function to create a new player
// Returns a pointer to a newly created player.
// The player should be initialized with data on the heap.
player_t* makePlayer(int roster, char* name) {
    player_t* newPlayer = malloc(sizeof(player_t));
    if (newPlayer == NULL)
        return NULL; // Memory allocation failed
    
    // Allocate memory for name and copy it
    newPlayer->name = malloc(strlen(name) + 1); // +1 for null terminator
    if (newPlayer->name == NULL) {
        free(newPlayer); // Free allocated memory before returning
        return NULL;
    }
    strcpy(newPlayer->name, name);
    
    newPlayer->rosterNum = roster;
    newPlayer->next = NULL;
    newPlayer->previous = NULL;
    
    return newPlayer;
}

// push a new player to the front of the DLL ( before the first player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_front(team_t* l, int roster, char* name) {
     if (l == NULL)
        return -1; // Team is NULL
    
    player_t* newPlayer = makePlayer(roster, name);
    if (newPlayer == NULL)
        return 0; // Memory allocation failed
    
    if (l->head == NULL) {
        // List is empty, set head and tail to new player
        l->head = newPlayer;
        l->tail = newPlayer;
    } else {
        // Update pointers
        newPlayer->next = l->head;
        l->head->previous = newPlayer;
        l->head = newPlayer;
    }
    
    l->activePlayers++; // Increment active players count
    return 1; // Success
}

// push a new player to the end of the team DLL (after the last player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_back(team_t* l, int roster, char* name) {
    if (l == NULL)
        return -1; // Team is NULL
    
    player_t* newPlayer = makePlayer(roster, name);
    if (newPlayer == NULL)
        return 0; // Memory allocation failed
    
    if (l->tail == NULL) {
        // List is empty, set head and tail to new player
        l->head = newPlayer;
        l->tail = newPlayer;
    } else {
        // Update pointers
        newPlayer->previous = l->tail;
        l->tail->next = newPlayer;
        l->tail = newPlayer;
    }
    
    l->activePlayers++; // Increment active players count
    return 1; // Success
}

// Returns the first player in the DLL and also removes it from the team.
// Returns NULL if the Team is NULL.
// Returns NULL on failure, i.e. there is no one to pop from the team.
// Assume roster numbers are always greater than zero
player_t* team_pop_front(team_t* t) {
    if (t == NULL || t->activePlayers == 0)
        return NULL; // Team is NULL or empty
    
    player_t* frontPlayer = t->head;
    if (t->head == t->tail) {
        // Only one player in the team
        t->head = NULL;
        t->tail = NULL;
    } else {
        t->head = t->head->next;
        t->head->previous = NULL;
    }
    
    frontPlayer->next = NULL;
    frontPlayer->previous = NULL;
    t->activePlayers--; // Decrement active players count
    
    return frontPlayer;
}

// Returns the last player in the Team, and also removes it from the list.
// Returns NULL if the Team is NULL.
// Returns NULL on failure, i.e. there is no one to pop from the Team.
// Assume roster numbers are always greater than zero
player_t* team_pop_back(team_t* t) {
    if (t == NULL || t->activePlayers == 0)
        return NULL; // Team is NULL or empty
    
    player_t* backPlayer = t->tail;
    if (t->head == t->tail) {
        // Only one player in the team
        t->head = NULL;
        t->tail = NULL;
    } else {
        t->tail = t->tail->previous;
        t->tail->next = NULL;
    }
    
    backPlayer->next = NULL;
    backPlayer->previous = NULL;
    t->activePlayers--; // Decrement active players count
    
    return backPlayer;
}

// Inserts a new player before the player at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new player
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent of calling push_back).
int team_insert(team_t* t, int pos, int roster, char* name) {
    if (t == NULL)
        return -1;
    if (pos < 0 || pos > t->activePlayers)
    {
        return 0;
    }
    
    
    if (pos >= t->activePlayers)
        return team_push_back(t, roster, name); // Insert at the end
    
    player_t* newPlayer = makePlayer(roster, name);
    if (newPlayer == NULL)
        return 0; // Memory allocation failed
    
    player_t* current = t->head;
    int index = 0;
    while (current != NULL && index < pos) {
        current = current->next;
        index++;
    }
    
    // Update pointers
    newPlayer->next = current;
    newPlayer->previous = current->previous;
    if (current->previous != NULL)
        current->previous->next = newPlayer;
    current->previous = newPlayer;
    
    if (current == t->head)
        t->head = newPlayer; // Update head if inserting at the beginning
    
    t->activePlayers++; // Increment active players count
    return 1; // Success
}

// Returns the roster number of the player at position pos starting at 0
// ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume roster numbers are always greater than zero
int team_list_get(team_t* t, int pos) {
    if (t == NULL)
        return -1; // Team is NULL or invalid position
    if (pos < 0 || t->activePlayers == 0)
    {
        return 0;
    }
    
    player_t* current = t->head;
    int index = 0;
    while (current != NULL && index < pos) {
        current = current->next;
        index++;
    }
    
    if (current == NULL)
        return 0; // Failure
    
    return current->rosterNum;
}

// Removes the player at position pos starting at 0 ( 0 being the first item )
// Returns NULL if the list is NULL
// Returns NULL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the roster number of the player removed.
player_t* team_list_remove(team_t* t, int pos) {
    if (t == NULL || pos < 0)
        return NULL; // Team is NULL or invalid position
    
    player_t* current = t->head;
    int index = 0;
    while (current != NULL && index < pos) {
        current = current->next;
        index++;
    }
    
    if (current == NULL)
        return NULL; // Failure
    
    if (current->previous != NULL)
        current->previous->next = current->next;
    if (current->next != NULL)
        current->next->previous = current->previous;
    
    if (current == t->head)
        t->head = current->next;
    if (current == t->tail)
        t->tail = current->previous;
    
    current->next = NULL;
    current->previous = NULL;
    t->activePlayers--; // Decrement active players count
    
    return current;
}

// Team Size
// Returns -1 if the Team is NULL.
// Queries the current size of a team
int team_size(team_t* t) {
    if (t == NULL)
        return -1; // Team is NULL
    
    return t->activePlayers;
}

// BONUS function - not required for HW
// no extra credit is given for this function
// Team DLL Sort
// Returns -1 if the Team is NULL.
// sorts the team by roster number, putting the players in order
// with the smallest roster number at the head of the list,
// in ascending order
// only work on this if you're all done with everything else tested!!
void team_sort(team_t* t) {

    // OPTIONAL
}

// Free Team DLL
// Removes a Team and all of its players (...and their names!!...) from memory.
// This should be called before the program terminates.
void free_team(team_t* t) {
    if (t == NULL)
        return; // Team is NULL
    
    player_t* current = t->head;
    while (current != NULL) {
        player_t* temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
    
    free(t);
}
