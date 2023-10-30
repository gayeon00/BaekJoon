#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {

    return (long long)w*h - (w+h-gcd(w,h));
}