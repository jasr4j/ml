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

double* gradient_descent(double x[], double y[], size_t n, double learning_rate, int epochs) {
        double t0 = 0, t1 = 0; // theta 0 and theta 1
        double *y_p = malloc(n*sizeof(double)); 
        double errors[n]; 
        for (int epoch = 0; epoch < epochs; epoch++) {
                
                for (size_t i = 0; i < n; i++) y_p[i] = t0 + (t1*x[i]); 
                for (size_t i = 0; i < n; i++) errors[i] = y_p[i] - y[i]; 
                double g0 = (2.0/n)*sum(errors, n); // gradient 0
                double err_times_x_sum = 0;
                for (size_t i = 0; i < n; i++) {
                        err_times_x_sum += (errors[i] * x[i]); 
                }
                double g1 = (2.0/n)*err_times_x_sum; // gradient 1
                t0 -= learning_rate * g0; 
                t1 -= learning_rate * g1; 
                
                if (epoch % 100 == 0 || epoch + 1 == epochs) {
                        printf("Epoch=%4d, mse=%.6f, theta0=%.6f, theta1=%.6f\n", epoch, loss(y, y_p, n), t0, t1); 
                }
                if (epoch + 1 == epochs) {
                        printf("Final Predicted Equation: f(x) = %.3f + %.3fx\n", t0, t1); 
                }
        }
        return y_p; 
}

int main() {
        printf("\033c");
        int epochs; double learning_rate; 
        size_t n = getN(); 
        printf("EPOCHS (Recommended - 100000): "); 
        scanf("%d", &epochs); 
        printf("LEARNING RATE (ALPHA) (Recommended - 0.01): "); 
        scanf("%lf", &learning_rate); 
        double *x = parseX(1, n); 
        double *y = parseX(0, n); 
        for (size_t i = 0; i < n; i++) {
                printf("(x, y)%zu: (%lf, %lf)\n", i, x[i], y[i]); 
        }
        double *y_p = gradient_descent(x, y, n, learning_rate, epochs); 
        printf("MAE = %f\n", mae(y, y_p, n));
        printf("SSE = %f\n", sse(y, y_p, n));
        free(y_p); 
        free(x); free(y); 
        return 0;
}