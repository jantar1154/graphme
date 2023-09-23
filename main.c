#include <stdio.h>
#include <stdlib.h>

int *largest(int size, int arr[]) {
    int INFINITY = -99999;
    int *largest = &INFINITY;
    for (int i = 1; i < size; i++) {
        if (arr[i] > *largest) largest = &arr[i];
        //printf("i%i. = highest: %i from %i\n", i, *largest, arr[i]);
    }
    return largest;
}

int *smallest(int size, int arr[]) {
    int INFINITY = 99999;
    int *smallest = &INFINITY;
    for (int i = 1; i < size; i++) {
        if (arr[i] < *smallest) smallest = &arr[i];
    }
    return smallest;
}

int map(int x, int in_min, int in_max, int out_min, int out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int main(int argc, char const *argv[]) {

    if (argc < 3) {
        printf("Please provide at least two numbers!\n");
        return 1;
    }

    int argv_int[argc];

    for (int i = 1; i < argc; ++i) argv_int[i] = atoi(argv[i]); // converts char[] to int[]

    // graph width and height
    int g_height = 20;
    int g_width = argc - 1;

    // decide graph lowest value and highest
    int *g_highest_val = largest(argc, argv_int);
    int *g_lowest_val = smallest(argc, argv_int);

    printf("Lowest: %i\n", *g_lowest_val);
    printf("Highest: %i\n", *g_highest_val);

    int g_heightmap[g_width];
    int g_treshold[g_width];

    // applies values to the heightmap
    for (int i = 1; i < g_width+1; i++) {
        g_heightmap[i-1] = map(argv_int[i], *g_lowest_val, *g_highest_val, 1, g_height);
        g_treshold[i-1] = g_height - g_heightmap[i-1];
        printf("%i: %i\n", argv_int[i], g_heightmap[i-1]);
    }

    // creates a graph matrix and applies height map to it
    int g_matrix[g_height][g_width];

    // Finally, print the result!
    for (int i = 0; i < g_height; i++) {
        for (int j = 0; j < g_width; j++) {
            if (i >= g_treshold[j]) {
                g_matrix[i][j] = 1;
            } else {
                g_matrix[i][j] = 0;
            }
            char ch = g_matrix[i][j] == 1 ? 'X' : ' ';
            printf("%c   ", ch);
        }
        printf("\n");
    }

    return 0;
}
