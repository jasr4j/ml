#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"

double* parseX(bool x, size_t maxpt) {
        FILE *file; 
        if (x) {
                file = fopen("./data/x.txt", "r"); 
        } else {
                file = fopen("./data/y.txt", "r"); 
        }
        
        double tmp[maxpt]; 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        size_t r = 0; 
        double v;
        while (r < maxpt && fscanf(file, " %lf", &v) == 1) {
                tmp[r] = v; 
                r++; 
        }
        fclose(file);
        double *D = malloc(sizeof(double) * r); 
        if (D == NULL) {
                perror("Not enough memory"); 
                exit(1); 
        }
        for (size_t i = 0; i < r; i++) {
                printf("%lf ", tmp[i]); 
        }
        for (size_t i = 0; i < r; i++) D[i] = tmp[i]; 
        printf("\n"); 
        return D; 
}

size_t getN() {
        FILE *file; 
        file = fopen("./data/x.txt", "r"); 
        if (file == NULL) {
                perror("Error opening file"); 
                exit(1); 
        }
        size_t r = 0; 
        double v; 
        while (fscanf(file, " %lf", &v) == 1) {
                r++; 
        }
        fclose(file);
        return r; 
}
