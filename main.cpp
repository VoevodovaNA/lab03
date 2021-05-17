#include "histogram.cpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;
using std::vector;

int main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    //double min, max;
    //find_minmax(numbers, min, max);
    const auto bins = make_histogram(numbers, bin_count);
    auto val_sign = fun_sign(numbers, bin_count);
    show_histogram_svg(bins,val_sign);
    return 1;
}
