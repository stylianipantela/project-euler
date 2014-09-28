#include <iostream>
using namespace std;

/** print the sum of all multiples of 3 or 5 strictly less than N and greater than 0
 *  @param N int
 *  @pre @param 1 <= N <= 10^9
 */
void problem1(int N) {
    // unsigned long int has size of 8 bytes
    // unsigned int has size of 4 bytes and it overflows
    unsigned long int sum, mul3, mul5, mul15;
    N -= 1;
    mul3 = N / 3;
    mul5 = N / 5;
    mul15 = N / 15;
    sum = ((3 * mul3 * mul3 + 3 * mul3) >> 1) + ((5 * mul5 * mul5 + 5 * mul5) >> 1);
    sum -= (15 * mul15 * mul15 + 15 * mul15) >> 1;
    cout << N + 1 << ": " << sum << endl;
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
