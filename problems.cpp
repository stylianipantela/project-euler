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
    cout << "Sum of multiples of 3 or 5 < " << N + 1 << ": " << sum << endl;
}

void test_problem1() {
    problem1(1);
    problem1(10);
    problem1(100);
    problem1(9);
    problem1(14);
    problem1(1000000000);
}

/** print the sum of all even fibonacci numbers less than N
 *  @param N unsigned long long int
 *  @pre @param 10 <= N <= 4 * 10^16
 */
void problem2(unsigned long long int N) {
    unsigned long long int sum, f1, f2, tmp;    
    f1 = 1; f2 = 2; sum = 0;

    // even fibonaccis appear with a period of 3
    while (f2 <= N) {   
        sum += f2;
        f1 += f2;
        f2 += f1;
        f1 += f2;
        tmp = f1;
        f1 = f2;
        f2 = tmp;    
    }   
   
    cout << "Sum of even fibonacci numbers <= " << N << ": " << sum << endl;
}

void test_problem2() {
    problem2(10);
    problem2(4000000000000);
}

int main() {
    test_problem1();
    test_problem2();
   
    return 0;
}
