//to find the nummber of primes less than n
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 1e6 + 5;
bool isPrime[MAX_SIZE]; // Prime lookup table
int primeCount[MAX_SIZE]; 

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) count++;
    }
    return count;
}

void sieve(int n) {
    fill(isPrime, isPrime + n, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i < n; i += p)
                isPrime[i] = false;
        }
    }

    primeCount[0] = primeCount[1] = 0;
    for (int i = 2; i < n; i++) {
        primeCount[i] = primeCount[i - 1] + (isPrime[i] ? 1 : 0);
    }
}

int countofprime(int n) {
    return primeCount[n - 1]; 
}

int main() {
    int n = 100;
    sieve(n); 
    countPrimes(n);
    return 0;
}
