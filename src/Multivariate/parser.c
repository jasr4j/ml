#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"
#include <string.h>

size_t getN(); 
size_t getDimensions(); 
double** parseX(); 

double** parseX() {
        size_t numLines = getN(); 
        size_t dimensions = getDimensions(); 
        FILE *file = fopen("data.csv", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        double **data = malloc(dimensions * sizeof(double*));   
        for (size_t i = 0; i < dimensions; i++) {
                data[i] = malloc(numLines * sizeof(double));
        }  
        char line[256]; // 256 char buffer
        size_t r = 0; 
        fgets(line, sizeof(line), file); 
        while (r < numLines && fgets(line, sizeof(line), file) != NULL) {
                char* token = strtok(line, ",\n");
                size_t c = 0;
                while (token != NULL && c < dimensions) {
                        data[c][r] = strtod(token, NULL);
                        token = strtok(NULL, ",\n"); 
                        c++;
                }
                r++;
        }

        fclose(file);
        return data; 
}

size_t getN() {
        FILE *file = fopen("data.csv", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        char line[256]; // 256 char buffer
        size_t r = -1; 
        while (fgets(line, sizeof(line), file) != NULL) {
                r++;
        }

        fclose(file);
        return r; 
}

size_t getDimensions() {
        FILE *file = fopen("data.csv", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        char line[256]; 
        size_t d = 1; 
        fgets(line, sizeof(line), file); 
        for (size_t i = 0; i < strlen(line); i++) {
                if (line[i] == ',') d++; 
        }
        return d; 
}


// TEST FUNCTION
/*int main() {
        double **y = parseX(); 
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 10; j++) {
                        printf("%lf\n", (y[i])[j]); 
                }
        }
        for (size_t i = 0; i < getDimensions(); i++) {
                free(y[i]); 
        }
        free(y); 
        return 0; 
}*/