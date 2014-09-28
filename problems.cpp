#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/** print the sum of all multiples of 3 or 5 strictly less than N and greater than 0
 *  @param N int
 *  @pre @param 1 <= N <= 10^9
 */
void problem1(int N) {
    // unsigned long int has size of 8 bytes
    // unsigned int has size of 4 bytes and it overflows
    unsigned long int sum3, sum5, sum15, mul3, mul5, mul15;
    N -= 1;
    mul3 = N / 3;
    mul5 = N / 5;
    mul15 = N / 15;
    sum3 = (3 * (mul3 + 1) * mul3) / 2;
    sum5 = (5 * (mul5 + 1) * mul5) / 2;
    sum15 = (15 * (mul15 + 1) * mul15) / 2;
    cout << N + 1 << ": " << sum3 + sum5 - sum15 << endl;
}

void test_problem1() {
    problem1(1);
    problem1(10);
    problem1(100);
    problem1(9);
    problem1(14);
    problem1(1000000000);

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    test_problem1();
    return 0;
}
