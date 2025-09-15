#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"
#include <string.h>

double** parseX() {
        size_t numLines = getN(); 
        size_t dimensions = getDimensions(); 
        FILE *file = fopen("./data.csv", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        double **data = malloc(dimensions * numLines * sizeof(double));         
        char line[256]; // 256 char buffer
        size_t r = 0; 
        while (r < numLines && fgets(line, sizeof(line), file) != NULL) {
                char* number = strtok(line, " "); 
                for (size_t c = 0; c < dimensions; c++) {
                        data[r][c] = atoi(number); 
                        number = strtok(line, ","); 
                }
                r++; 
        }

        fclose(file);
        return data; 
}

size_t getN() {
        FILE *file; 
        file = fopen("./data.csv", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        size_t r = 0; 
        char c; 
        while (fscanf(file, " %c", &c)) {
                if (c == '\n') r++; 
        }
        fclose(file);
        return r; 
}

size_t getDimensions() {
        FILE *file = fopen("./data.csv", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        char c; 
        size_t dimensions = 1; 
        while (fscanf(file, " %c, ", &c) && c != '\n') {
                if (c == ',') dimensions++; 
        }
        return dimensions; 
}

