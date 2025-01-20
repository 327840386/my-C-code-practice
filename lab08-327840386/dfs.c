// This is a great lab to practice debugging.
// The Makefile already has the -g flag, so you can use gdb to debug.
// See the debugging tutorial on Piazza / Canvas for more information.
#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

// Depth-First Tree Traversal
// Make sure to print out each node you visit, and only print it out once!
// **Hint** Think recursively
void dfs(TreeNode_t* start) {
    // TODO: Hmm, how can I look through both branches of the node?
    // TODO: Hmm, when do I stop?
    //
    // Base case: if the current node is NULL, return
    if (start == NULL) {
        return;
    }

    // Print the data of the current node
    printf("%c ", start->letter);

    // Recursively traverse the left subtree
    dfs(start->lChild);

    // Recursively traverse the right subtree
    dfs(start->rChild);
}

// free function
void freeTree(TreeNode_t* start) {
    // TODO
    // Base case: if the current node is NULL, return
    if (start == NULL) {
        return;
    }

    // Recursively free the memory for the left subtree
    freeTree(start->lChild);

    // Recursively free the memory for the right subtree
    freeTree(start->rChild);

    // Free the memory for the current node
    free(start);
}
