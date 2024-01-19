
C - Sorting algorithms & Big O

Background Context

This project is designed for groups of two students to collaborate. Each pair of students should engage in pair programming, especially for the mandatory part.

Resources

Read or watch the following resources to enhance your understanding:

Sorting algorithm
Big O notation
Sorting algorithms animations
15 sorting algorithms in 6 minutes (WARNING: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms)
Learning Objectives

Upon completion of this project, you should be able to explain the following concepts without relying on Google:

General

Implementation of at least four different sorting algorithms.
Understanding of the Big O notation and ability to evaluate the time complexity of an algorithm.
Selection of the best sorting algorithm for a given input.
Definition of a stable sorting algorithm.
Requirements

General

Allowed editors: vi, vim, emacs
Compilation of all files on Ubuntu 20.04 LTS using gcc, with the options: -Wall -Werror -Wextra -pedantic -std=gnu89
All files should end with a new line.
A README.md file at the root of the project folder is mandatory.
Code should follow the Betty style, and will be checked using betty-style.pl and betty-doc.pl.
Prohibition of global variables.
Limit of five functions per file.
Unless specified otherwise, standard library functions (e.g., printf, puts) are forbidden.
Example main.c files are provided for testing functions but don’t have to be pushed to the repository.
Prototypes of all functions should be included in a header file named sort.h.
The header files should be include guarded.
A list/array does not need to be sorted if its size is less than 2.
GitHub

Each group should have one project repository.
Cloning/forking a project repository with the same name before the second deadline risks a 0% score.
More Info

Data Structure and Functions

For this project, you have access to the following functions:

print_array

#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

#### `print_list`

#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}


The files `print_array.c` and `print_list.c` (containing the `print_array` and `print_list` functions) will be compiled with your functions during the correction. Ensure to declare the prototypes of these functions in your `sort.h` header file.

### Doubly Linked List Structure

 /**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;



### Big O Notation

-   O(1)
-   O(n)
-   O(n!)
-   O(n^2) (n square)
-   O(log(n))
-   O(n log(n))
-   O(n + k)
-   ...

Please use the "short" notation (avoid using constants). Example: `O(nk)` or `O(wn)` should be written as `O(n)`. If an answer is required within a file, ensure all your answer files have a newline at the end.

## Tests

For testing sorting algorithms with large sets of random integers, you can use [Random.org](https://www.random.org/).

AUTHORS : Benjamin & Célestine `
