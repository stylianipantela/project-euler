#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


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
    test_problem4();
   
    return 0;
}
