// You must submit this test file with your code implementation.
// include all tests that you used to test your binary search tree implementation
// Compile this assignment with: gcc -Wall -g bst_tests.c my_bst.c -o tests
// This is a great assignment to practice debugging.
// Run with: gdb ./tests --tui
// Then type 'start'
// Then type 'next' or 'n' and enter
// See the GDB debugging video for more information

#include <stdio.h>
#include <stdlib.h>

#include "my_bst.h"

// Write more tests here to test your implementation.
// We will use our own test suite (i.e. replacing this file)
// in order to test your implementation from my_bst.

// Testing allocation
int unitTest1()
{
    int result;
    tree_t *testBST = bst_create();
    if (testBST != NULL)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    bst_free(testBST);
    return result;
}

// Add and find a node
int unitTest2()
{
    int result;
    tree_t *testBST = bst_create();
    bst_add(testBST, 78);
    result = bst_find(testBST, 78);
    bst_free(testBST);
    return result;
}

// Sums the nodes in a BST
int unitTest3()
{
    int result;
    tree_t *testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_sum(testBST);
    bst_free(testBST);

    if (result == 5)
    {
        return 1;
    }
    return 0;
}

// Testing the size of the BST
int unitTest4()
{
    int result;
    tree_t *testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_size(testBST);
    bst_free(testBST);

    if (result == 1)
    {
        return 1;
    }
    return 0;
}

// Testing adding multiple nodes and finding them
int unitTest5()
{
    int result = 1;
    tree_t *testBST = bst_create();

    // Add nodes from 1 to 10
    for (int i = 1; i <= 10; i++)
    {
        bst_add(testBST, i);
    }

    // Check if all nodes are found
    for (int i = 1; i <= 10; i++)
    {
        if (bst_find(testBST, i) != 1)
        {
            result = 0; // Test failed if any node is not found
            break;
        }
    }

    bst_free(testBST);
    return result;
}

// Testing adding nodes and checking size
int unitTest6()
{
    tree_t *testBST = bst_create();

    // Add 50 nodes
    for (int i = 1; i <= 50; i++)
    {
        bst_add(testBST, i);
    }

    // Check if size is 50
    int size = bst_size(testBST);
    bst_free(testBST);
    return (size == 50) ? 1 : 0;
}

// Testing printing the tree in ascending order
int unitTest7()
{
    // Assuming the tree has nodes 1 to 10
    tree_t *testBST = bst_create();

    // Add nodes from 1 to 10
    for (int i = 1; i <= 10; i++)
    {
        bst_add(testBST, i);
    }

    // Print in ascending order
    printf("Printing tree in ascending order: ");
    bst_print(testBST, 0); // 0 for ascending order
    printf("\n");

    bst_free(testBST);
    return 1; // Manual check required for correctness of output
}

// Testing printing the tree in descending order
int unitTest8()
{
    // Assuming the tree has nodes 1 to 10
    tree_t *testBST = bst_create();

    // Add nodes from 1 to 10
    for (int i = 1; i <= 10; i++)
    {
        bst_add(testBST, i);
    }

    // Print in descending order
    printf("Printing tree in descending order: ");
    bst_print(testBST, 1); // 1 for descending order
    printf("\n");

    bst_free(testBST);
    return 1; // Manual check required for correctness of output
}

// Testing sum of nodes for a large tree
int unitTest9()
{
    tree_t *testBST = bst_create();

    // Add nodes from 1 to 1000
    for (int i = 1; i <= 1000; i++)
    {
        bst_add(testBST, i);
    }

    // Calculate the expected sum for the sequence 1 to 1000
    int expectedSum = (1000 * (1000 + 1)) / 2; // Sum of natural numbers formula

    // Check if the sum is correct
    int sum = bst_sum(testBST);
    bst_free(testBST);
    return (sum == expectedSum) ? 1 : 0;
}

// Testing adding duplicate nodes
int unitTest10()
{
    tree_t *testBST = bst_create();

    // Add some nodes with duplicate values
    bst_add(testBST, 5);
    bst_add(testBST, 3);
    bst_add(testBST, 8);
    bst_add(testBST, 5); // Duplicate node

    // Check if size remains unaffected by duplicate node
    int size = bst_size(testBST);
    bst_free(testBST);
    return (size == 3) ? 1 : 0;
}

// Testing adding nodes in alternating order and checking if the tree shape is correct
int unitTest11()
{
    tree_t *testBST = bst_create();

    // Add nodes in alternating order to create a "V"-shaped tree
    bst_add(testBST, 5);
    bst_add(testBST, 3);
    bst_add(testBST, 8);
    bst_add(testBST, 2);
    bst_add(testBST, 7);
    bst_add(testBST, 9);

    // Print the tree to manually check its shape
    printf("Printing tree to check shape:\n");
    bst_print(testBST, 0); // Ascending order
    printf("\n");

    bst_free(testBST);
    return 1; // Manual check required for correctness of output
}

// Testing adding nodes to create a highly unbalanced tree (linked list)
int unitTest12()
{
    tree_t *testBST = bst_create();

    // Add nodes in increasing order to create a linked list-like tree
    for (int i = 1; i <= 10; i++)
    {
        bst_add(testBST, i);
    }

    // Print the tree to manually check its shape
    printf("Printing tree to check shape:\n");
    bst_print(testBST, 0); // Ascending order
    printf("\n");

    bst_free(testBST);
    return 1; // Manual check required for correctness of output
}

// Testing an empty tree
int unitTest13()
{
    tree_t *testBST = bst_create();

    // Check if the tree is empty
    int isEmpty = bst_empty(testBST);
    bst_free(testBST);
    return (isEmpty == 1) ? 1 : 0;
}

// Testing finding nodes in an empty tree
int unitTest14()
{
    tree_t *testBST = bst_create();

    // Try to find a node in an empty tree
    int result = bst_find(testBST, 5);
    bst_free(testBST);
    return (result == 0) ? 1 : 0;
}

// Testing sum of nodes in an empty tree
int unitTest15()
{
    tree_t *testBST = bst_create();

    // Check sum of nodes in an empty tree
    int sum = bst_sum(testBST);
    bst_free(testBST);
    return (sum == 0) ? 1 : 0;
}

// Testing size of an empty tree
int unitTest16()
{
    tree_t *testBST = bst_create();

    // Check size of an empty tree
    int size = bst_size(testBST);
    bst_free(testBST);
    return (size == 0) ? 1 : 0;
}

// Testing adding and finding nodes with negative values
int unitTest17()
{
    tree_t *testBST = bst_create();

    // Add nodes with negative values
    bst_add(testBST, -5);
    bst_add(testBST, -3);
    bst_add(testBST, -8);

    // Check if nodes with negative values are found
    int result = 1;
    if (bst_find(testBST, -5) != 1 || bst_find(testBST, -3) != 1 || bst_find(testBST, -8) != 1)
    {
        result = 0; // Test failed if any node is not found
    }

    bst_free(testBST);
    return result;
}

// Testing adding and finding large values
int unitTest18()
{
    tree_t *testBST = bst_create();

    // Add nodes with large values
    bst_add(testBST, 10000);
    bst_add(testBST, 50000);
    bst_add(testBST, 100000);

    // Check if large value nodes are found
    int result = 1;
    if (bst_find(testBST, 10000) != 1 || bst_find(testBST, 50000) != 1 || bst_find(testBST, 100000) != 1)
    {
        result = 0; // Test failed if any node is not found
    }

    bst_free(testBST);
    return result;
}

// Testing adding nodes with duplicate values and checking size
int unitTest19()
{
    tree_t *testBST = bst_create();

    // Add nodes with duplicate values
    bst_add(testBST, 5);
    bst_add(testBST, 3);
    bst_add(testBST, 8);
    bst_add(testBST, 5); // Duplicate node
    bst_add(testBST, 3); // Duplicate node

    // Check if size remains unaffected by duplicate nodes
    int size = bst_size(testBST);
    bst_free(testBST);
    return (size == 3) ? 1 : 0;
}

// Testing adding nodes with duplicate values and finding them
int unitTest20()
{
    tree_t *testBST = bst_create();

    // Add nodes with duplicate values
    bst_add(testBST, 5);
    bst_add(testBST, 3);
    bst_add(testBST, 8);
    bst_add(testBST, 5); // Duplicate node
    bst_add(testBST, 3); // Duplicate node

    // Check if all duplicate nodes are found
    int result = (bst_find(testBST, 5) == 1 && bst_find(testBST, 3) == 1 && bst_find(testBST, 8) == 1) ? 1 : 0;

    bst_free(testBST);
    return result;
}

int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,
    unitTest13,
    unitTest14,
    unitTest15,
    unitTest16,
    unitTest17,
    unitTest18,
    unitTest19,
    unitTest20,
    NULL};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{

    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}
