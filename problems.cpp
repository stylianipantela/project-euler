#include <iostream>
#include <math.h>
#include <vector>
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

/** Get the palindrome from the 3 digit number we pass in
  * @param n int 3 digit number to be turned into a palindrome
  * @pre 100 <= @a n < 1000
  * 
  * @return retusn n concatenated with reverse(n), example 103 will return 103301
  */
int get_palindrome(int n) {
    string n_str = to_string(n);
    string n_rev = to_string(n);
    reverse(n_rev.begin(), n_rev.end());
    n_str.append(n_rev);
    return stoi(n_str);
}

/** find largest prime factor of number N
  * @param 101101< N <1000000
  */
void problem4(int N) {
    int max = 0;

    for (int i = 999; i >= 100; --i) {
        max = get_palindrome(i);
        if (max > N)
            continue;
        for (int j = 100; j < 1000; ++j) {
            if (max % j == 0 && (max / j) / 1000 == 0) {
                cout << max << endl;
                return;
            }
        }
    }
}

void test_problem4() {
    problem4(101110);
    problem4(800009);
}


int main() {
    // test_problem1();
    // test_problem2();
    // test_problem3();
    test_problem4();
   
    return 0;
}
