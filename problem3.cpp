#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/** find largest prime factor of number N
  * @param N < 10^12
  */
void problem3(unsigned long long int n) {
    unsigned long long int original_n = n;
    unsigned long long int largest_prime = 2;
    unsigned long long int d = 2;
    while (n > 0 && d * d <= n) {
        while (n % d == 0) {
            largest_prime = d;
            n = n / d;
        }
        ++d;
    }
    if (n != 1)
        largest_prime = n;
    cout << original_n << " with largest prime " << largest_prime << endl;
}

void test_problem3() {
    problem3(10);
    problem3(100);
    problem3(31);
    problem3(1560134955);
    problem3(13195);
    problem3(600851475143);
}

int main() {
    test_problem3();
    return 0;
}