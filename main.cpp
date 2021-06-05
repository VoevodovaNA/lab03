#include "histogram.h"
#include "svg.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;
using std::vector;

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<double>
make_histogram(const vector<double>& numbers, size_t bin_count) {
    double min, max;
    vector<double> bins(bin_count);
    find_minmax(numbers, min, max);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
 return bins;
}

void
show_histogram_text(const vector<size_t> bins)
{
    int bin_count = bins.size();
    int max_count = 0;
    for (size_t i = 0; i < bin_count; i++)
    {
        size_t count = bins[i];

        if (count > max_count)
        {
            max_count = count;
        }
    }
    double height;
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
    if (max_count > MAX_ASTERISK)
    {
        height = (static_cast<double>(MAX_ASTERISK) / max_count);;
    }
    else
    {
        height = 1;
    }
    for (size_t i = 0; i < bin_count; i++)
    {
        size_t k = bins[i];
        cout << "   ";
        if (k < 100)
        {
            cout << " ";
        }
        if (k < 10)
        {
            cout << " ";
        }
        cout << k << "|";
        for (size_t j = 0; j < k * height; j++)
        {
            cout << "*";
        }
        cout << "\n";


    }
    return;
}



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
