#include "histogram.h"
#include "svg.h"

#include <cassert>
#include <vector>

void
test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
    return;
}
void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
    return;
}
void test_equal()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
    return;
}
void test_one_number()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
    return;
}
void test_empty()
{
    double min=0;
    double max=0;
    cerr << "test" << endl;
    find_minmax({},min,max);
}

void test1()
{
    vector<size_t> fortest1 = {3,4,5};
    size_t expected=4;
    double e=10e-5;
    size_t val = mean(fortest1);
    assert(val - expected < e);
}

void test2()
{
    vector<size_t> fortest2;
    size_t expected=0;
    size_t val = mean(fortest2);
    assert(val == expected);
}

int
main()
{
    test_positive();
    test_negative();
    test_equal();
    test_one_number();
    test_empty();
    test1();
    test2();
    return 0;
}
