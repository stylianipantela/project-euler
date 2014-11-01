#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


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
    test_problem2();
    return 0;
}