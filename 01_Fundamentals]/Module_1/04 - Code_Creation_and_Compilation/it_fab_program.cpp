#include <iostream>
#include <chrono>

using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n = 35;    
    auto start = chrono::high_resolution_clock::now();
    int result = fibonacci_iterative(n);
    auto end = chrono::high_resolution_clock::now();    
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);    
    cout << "Fibonacci Iterative(" << n << ") = " << result << endl;
    cout << "Execution time: " << duration.count() << " ms" << endl;    
    return 0;
}