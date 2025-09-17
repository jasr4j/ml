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

double* gradient_descent(double **data, size_t n, double learning_rate, int epochs, size_t dimensions) {
        double t[dimensions]; // theta
        for (size_t i = 0; i < dimensions; i++) {
                t[i] = 0; 
        }
        double *y_p = malloc(n*sizeof(double)); // predicted y
        double errors[n]; // errors
        for (int epoch = 0; epoch < epochs; epoch++) {
                for (size_t i = 0; i < n; i++) {
                        y_p[i] = t[0]; 
                        for (size_t j = 1; j < dimensions; j++) {

                                y_p[i] += (t[j] * data[j - 1][i]);
                        }
                        errors[i] = y_p[i] - data[dimensions-1][i]; 
                }
                double g[dimensions]; 
                g[0] = (2.0/n) * sum(errors, n); 
                int x_ptr = 0; 
                for (size_t i = 1; i < dimensions; i++) {
                        double err_times_x_sum = 0;
                        for (size_t j = 0; j < n; j++) {
                                err_times_x_sum += (errors[j] * data[x_ptr][j]); 
                        }
                        g[i] = (2.0/n) * err_times_x_sum; 
                        x_ptr++; 
                }
                for (size_t i = 0; i < dimensions; i++) {
                        t[i] -= learning_rate * g[i]; 
                        if (t[i] == -0.00) t[i] = 0.0;
                }

                if ((epoch + 1) % 1000 == 0 || epoch + 1 == epochs || epoch == 0) {
                        printf("Epoch=%6d, mse=%.3f, ", epoch + 1, loss(data[dimensions-1], y_p, n)); 
                        for (size_t i = 0; i < dimensions; i++) {
                                printf("theta%zu=%.3f ", i, t[i]); 
                        }
                        for (size_t i = 0; i < dimensions; i++) {
                                printf("g%zu=%.3lf ", i, g[i]); 
                        }
                        if (epoch != 0 && epoch + 1 != epochs) { 
                                printf("\r"); 
                        } else {
                                printf("\n"); 
                        }
                }
                if (epoch + 1 == epochs) {
                        printf("Final Predicted Equation: y_p = %.3f", t[0]); 
                        for (size_t i = 1; i < dimensions; i++) {
                                printf(" + %.3fx%zu", t[i], i-1); 
                        }
                        printf("\n"); 
                }
        }
        return y_p; 
}

int main() {
        int epochs; double learning_rate; 
        size_t dimensions = getDimensions(); 
        size_t n = getN(); 
        printf("EPOCHS (Recommended - 1000000000): "); 
        scanf("%d", &epochs); 
        printf("LEARNING RATE (ALPHA) (Recommended - 0.0000001): "); 
        scanf("%lf", &learning_rate); 
        double **data = parseX(); 
        double *y_p = gradient_descent(data, n, learning_rate, epochs, dimensions); 
        printf("MAE = %.3lf\n", mae(data[dimensions -1], y_p, n));
        printf("SSE = %.3lf\n", sse(data[dimensions -1], y_p, n));
        free(y_p); 
        for (size_t i = 0; i < dimensions; i++) free(data[i]); 
        free(data); 
        return 0;
}