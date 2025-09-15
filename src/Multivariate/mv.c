#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parser.h"

double sum(double d[], size_t n) {
        double s = 0;
        for (size_t i = 0; i < n; i++) s+=d[i]; 
        return s; 
}

double mae(double y[], double y_p[], size_t n) {
        double m = 0; 
        for (size_t i = 0; i < n; i++) {
                m += (fabs(y[i] - y_p[i])); 
        }
        m /= n; 
        return m; 
}

double sse(double y[], double y_p[], size_t n) {
        double s = 0; 
        for (size_t i = 0; i < n; i++) {
                s += (y[i] - y_p[i])*(y[i] - y_p[i]); 
        }
        return s; 
}

double loss(double y[], double y_p[], size_t n) {
        double mse = sse(y, y_p, n) / n; 
        return mse; 
}

double* gradient_descent(double *data[], size_t n, double learning_rate, int epochs, size_t dimensions) {
        double t[dimensions]; 
        for (size_t i = 0; i < dimensions; i++) {
                t[i] = 0; 
        }
        double *y_p = malloc(n*sizeof(double)); 
        double errors[n]; 


        for (int epoch = 0; epoch < epochs; epoch++) {
                int xptr = 0; 
                for (size_t i = 0; i < n; i++) {
                        y_p[i] = t[0]; 
                        for (size_t j = 1; j < dimensions; j++) {
                                y_p[i] += t[j] * data[xptr][j];  
                        }
                }
                for (size_t i = 0; i < n; i++) errors[i] = y_p[i] - data[dimensions - 1][i]; 
                double g[dimensions]; 
                g[0] = (2.0/n) * sum(errors, n); 
                int x_ptr = 0; 
                for (size_t i = 1; i < dimensions; i++) {
                        double err_times_x_sum = 0;
                        for (size_t i = 0; i < n; i++) {
                                err_times_x_sum += (errors[i] * data[x_ptr][i]); 
                        }
                        g[i] = g[0] * err_times_x_sum; 
                }
                for (size_t i = 0; i < dimensions; i++) {
                        t[i] -= learning_rate * g[i]; 
                }                

                if (epoch % 100 == 0 || epoch + 1 == epochs) {
                        printf("Epoch=%4d, mse=%.6f, ", epoch, loss(data[dimensions-1], y_p, n)); 
                        for (size_t i = 0; i < dimensions; i++) {
                                printf("theta%zu=%.6f ", i, t[i]); 
                        }
                        printf("\n"); 
                }
                if (epoch + 1 == epochs) {
                        printf("Final Predicted Equation: f(x) = %.3f", t[0]); 
                        for (size_t i = 1; i < dimensions; i++) {
                                printf(" + %.3fx%zu", t[i], i); 
                        }
                        printf("\n"); 
                }
        }
        return y_p; 
}

int main() {
        int epochs; double learning_rate; size_t dimensions = getDimensions(); 
        size_t n = getN(); 
        printf("EPOCHS (Recommended - 100000): "); 
        scanf("%d", &epochs); 
        printf("LEARNING RATE (ALPHA) (Recommended - 0.01): "); 
        scanf("%lf", &learning_rate); 
        double **data = parseX(); 
        double *y_p = gradient_descent(data, n, learning_rate, epochs, dimensions); 
        printf("MAE = %f\n", mae(data[dimensions -1], y_p, n));
        printf("SSE = %f\n", sse(data[dimensions -1], y_p, n));
        free(y_p); 
        free(data); 
        return 0;
}