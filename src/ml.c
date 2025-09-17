#include<stdio.h>
#include<stdlib.h>

int main() {
        printf("Enter L for Univariate Linear and M for Multivariate Linear: "); 
        char in = '!'; 
        scanf(" %c", &in); 
        while (in != 'L' && in != 'M') {
                printf("Invalid Input.\n");
                printf("Enter L for Univariate Linear and M for Multivariate Linear: "); 
                scanf(" %c", &in); 
        } 
        if (in == 'L') {
                #ifdef _WIN32
                        system("cd Linear && make && make clean && ./linear");
                #elif __APPLE__
                        system("cd Linear && make && make clean && ./linear"); 
                #elif __linux__
                        system("cd Linear && make && make clean && ./linear"); 
                #elif __unix__
                        system("cd Linear && make && make clean && ./linear"); 
                #else
                        printf("UNSUPPORTED OPERATING SYSTEM\n");
                #endif
        } else {
                #ifdef _WIN32
                        system("cd Multivariate && make && make clean && ./mv");
                #elif __APPLE__
                        system("cd Multivariate && make && make clean && ./mv"); 
                #elif __linux__
                        system("cd Multivariate && make && make clean && ./mv"); 
                #elif __unix__
                        system("cd Multivariate && make && make clean && ./mv"); 
                #else
                        printf("UNSUPPORTED OPERATING SYSTEM\n");
                #endif
        }
        return 0; 
}