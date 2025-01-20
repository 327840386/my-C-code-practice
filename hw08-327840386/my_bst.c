// VFS23S
// Include our header file for our my_bst.c
//
#include "my_bst.h"

#include <stdio.h>
#include <stdlib.h>

// Complete all the following functions
// Do not change the function signatures or the header file
// You may include helper functions as needed
// make sure to include your tests in bst_tests.c

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
// Helper function to create a new node
treenode_t *create_node(int item) {
    treenode_t *new_node = (treenode_t *)malloc(sizeof(treenode_t));
    if (new_node != NULL) {
        new_node->data = item;
        new_node->leftChild = NULL;
        new_node->rightChild = NULL;
    }
    return new_node;
}

tree_t *bst_create() {
    tree_t *new_tree = (tree_t *)malloc(sizeof(tree_t));
    if (new_tree != NULL) {
        new_tree->size = 0;
        new_tree->source = NULL;
    }
    return new_tree;
}

// Helper function to add a node recursively
int add_node_recursive(treenode_t **node, int item) {
    if (*node == NULL) {
        *node = create_node(item);
        if (*node == NULL)
            return -1; // Memory allocation failed
        return 1; // Node added successfully
    }

    if (item < (*node)->data)
        return add_node_recursive(&((*node)->leftChild), item);
    else if (item > (*node)->data)
        return add_node_recursive(&((*node)->rightChild), item);
    else
        return 0; // Node with this data already exists
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(tree_t *t) {
    if (t == NULL) {
        return -1; // BST is empty
    }
    if (t->size == 0) {
        return 1; // BST is empty
    }
    return 0; // BST is not empty
}


// Adds a new node containing item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive implementation is required.
int bst_add(tree_t *t, int item) {
    if (t == NULL)
        return -1; // Invalid BST

    int result = add_node_recursive(&(t->source), item);
    if (result == 1)
        t->size++; // Increment size if node is added
    return 1;
}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree (i.e., when t == NULL) -- print "(NULL)".
// It should run in O(n) time.
// A recursive implementation is required. 
void print_inorder(treenode_t *node) {
    if (node != NULL) {
        print_inorder(node->leftChild);
        printf("%d ", node->data);
        print_inorder(node->rightChild);
    }
}

void print_reverse_inorder(treenode_t *node) {
    if (node != NULL) {
        print_reverse_inorder(node->rightChild);
        printf("%d ", node->data);
        print_reverse_inorder(node->leftChild);
    }
}

void bst_print(tree_t *t, int order) {
    if (t == NULL) {
        printf("(NULL)");
        return;
    } 
    if (t->source == NULL) {
        return;
    }
    
    if (order == 0) {
        print_inorder(t->source);}
    else {
        print_reverse_inorder(t->source);}
}

// Returns the sum of all the nodes in the bst.
// exits the program for a NULL tree. 
// It should run in O(n) time.
// A recursive implementation is required.
int sum_recursive(treenode_t *node) {
    if (node == NULL)
        return 0;
    return node->data + sum_recursive(node->leftChild) + sum_recursive(node->rightChild);
}

int bst_sum(tree_t *t) {
    if (t == NULL || t->source == NULL) {
        return 0; // Exit program for NULL tree
    } 
    return sum_recursive(t->source);
}



// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int find_recursive(treenode_t *node, int value) {
    if (node == NULL)
        return 0; // Value not found
    if (node->data == value)
        return 1; // Value found
    if (value < node->data)
        return find_recursive(node->leftChild, value);
    else
        return find_recursive(node->rightChild, value);
}

int bst_find(tree_t *t, int value) {
    if (t == NULL || t->source == NULL) {
        return 0; // return 0 program for NULL tree
    }
    return find_recursive(t->source, value);
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(tree_t *t) {
    if (t == NULL || t->source == NULL) {
        return 0; // return 0 program for NULL tree
    }
    return t->size;
}


// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the program terminates.
void free_nodes(treenode_t *node) {
    if (node != NULL) {
        free_nodes(node->leftChild);
        free_nodes(node->rightChild);
        free(node);
    }
}

void bst_free(tree_t *t) {
     if (t != NULL) {
        free_nodes(t->source);
        free(t);
    }
}
