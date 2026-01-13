#include "statistics.h"

// Calculate the mean (average)
double average(double values[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum / count;
}

// Find the smallest value in the set
double minimum(double values[], int count) {
    double min = values[0]; // Assume the first number is the smallest
    for (int i = 1; i < count; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

// Find the largest value in the set
double maximum(double values[], int count) {
    double max = values[0]; // Assume the first number is the largest
    for (int i = 1; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}