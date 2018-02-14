// ---------
// IncrH.c++
// ---------

// http://en.cppreference.com/w/cpp/language/operator_incdec

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

#define TEST1
#define TEST2
#define TEST3
#define TEST4

int& pre_incr (int& r) {
    return r += 1;}

int post_incr (int& r) {
    int v = r;
    r += 1;
    return v;}

#ifdef TEST1
void test1 () {
    int i = 2;
    int j = pre_incr(i);
    assert(i == 3);
    assert(j == 3);}
#endif

#ifdef TEST2
void test2 () {
    int i = 2;
    int j = pre_incr(pre_incr(i));
    assert(i == 4);
    assert(j == 4);}
#endif

#ifdef TEST3
void test3 () {
    int i = 2;
    int j = post_incr(i);
    assert(i == 3);
    assert(j == 2);}
#endif

#ifdef TEST4
void test4 () {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr'
    assert(i == 2);}
#endif

int main () {
    cout << "Incr.c++" << endl;
    int n;
    cin >> n;
    switch (n) {
        #ifdef TEST1
        case 1:
            test1();
            break;
        #endif

        #ifdef TEST2
        case 2:
            test2();
            break;
        #endif

        #ifdef TEST3
        case 3:
            test3();
            break;
        #endif

        #ifdef TEST4
        case 4:
            test4();
            break;
        #endif

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}
