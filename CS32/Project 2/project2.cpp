#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int modulo(unsigned int m, unsigned int n);
int occurrences(int number, int d);
string lucky7s(string s);
bool combinations(int array[], int size, int target);

int main()
{


    // test code
    assert(modulo(100, 10) == 0);
    assert(modulo(1, 13) == 1);
    assert(modulo(12, 5) == 2);
    assert(modulo(0, 3) == 0);
    assert(modulo(0, 2) == 0);
    assert(modulo(33, 6) == 3);
    assert(modulo(123123, 1234) == 957);

    assert(occurrences(567, 2) == 0);
    assert(occurrences(128874, 2) == 1);
    assert(occurrences(212121, 2) == 3);
    assert(occurrences(123123123, 3) == 3);
    assert(occurrences(4000000, 0) == 6);
    assert(occurrences(4123145, 5) == 1);

    assert(lucky7s("cs32") == "cs32");
    assert(lucky7s("Apple Baseball") == "Ap77ple Basebal77l");
    assert(lucky7s("abbba") == "ab77b77ba");

    int other[5] = { 10, 8, 2, 6, 4 };
    assert(combinations(other, 5, 10) == true);
    assert(combinations(other, 5, 18) == true);
    assert(combinations(other, 5, 15) == false);

    cout << "all tests passed!" << endl;
    return(0);
}


int modulo(unsigned int m, unsigned int n) {
    if (m == 1 && n > 1) { // mod 1 is always 1
        return 1;
    }
    if (m < n) { // base case: a remainder will never be less than the dividend
        return m;
    }
    else if (m == n || m == 0) { // if m is 0, then mod will always be 0
        return 0;
    }
    return (modulo(m - n, n)); // essentially "divides" by subtracting n over and over again until m < n, meaning we cant divide further
}

int occurrences(int number, int d) {
    if (number == 0) { // base case, cannot divide by 0
        return 0;
    }
    if (number % 10 == d) { // taking mod 10 of a number returns the last digit of it
        return 1 + occurrences(number/10, d); // adding one "occurence" before going down if found, removing last number by dividing by 10
    }
    else {
        return occurrences(number / 10, d); // if no digit found, remove last number again and try again
    }
}

string lucky7s(string s) {
    if (s.length() < 2) { //basecase, no char to compare to if less than 2 characters left
        return s;
    }

    if (s[0] == s[1]) { //checks for matching letters, and if found, appends 77 after it before it runs lucky7s again without the first char
        return s.substr(0, 1) + "77" + lucky7s(s.substr(1, s.length() - 1)); //s[0] returns a char so we use subsstring
    }
    else {
        return s.substr(0, 1) + lucky7s(s.substr(1, s.length() - 1)); //if not matching, remove first character and go down
    }

}

bool combinations(int array[], int size, int target) {
    if (size == 0 && target!=0) { // no sums found
        return false;
    }
    else if (target == 0) { // no more target means that it was evenly added
        return true;
    }
    else {
        return combinations(array, size-1, target) || combinations(array, size - 1, target - array[size-1]); //almost like a nested for loop, branches out like a tree to check every possible combination
    } //size-1 effectively traverses it down the array while array[size-1] actually checks for sums
}