#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstddef>

#include "histogram.h"
#include "svg.h"

using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<size_t>
make_histogram(const vector<double>& numbers, size_t bin_count) {
    double min, max;
    vector<size_t> bins(bin_count, 0);
    find_minmax(numbers, min, max);
    for (double number : numbers) {
        size_t bin = (size_t)trunc(((number - min) / (max - min))
                                   * (double)bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

void show_histogram_text(const vector<size_t>& bins) {
    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count)
            max_count = count;
    }
    const bool scaling_needed = (max_count > MAX_ASTERISK);
    for (size_t bin : bins) {
        if (bin < 100)
            cout << ' ';
        if (bin < 10)
            cout << ' ';
        cout << bin << "|";
        size_t height = bin;
        if (scaling_needed) {
            const double scaling_factor = MAX_ASTERISK / (double)max_count;
            height = static_cast<size_t>((double)bin * scaling_factor);
        }
        for (size_t i = 0; i < height; i++)
            cout << '*';
        cout << '\n';
    }
}

int main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    /*double min, max;
    find_minmax(numbers, min, max);
     const auto bins = make_histogram(numbers, min, max, bin_count);
    show_histogram_svg(bins,stroke,fill);
    */
    const auto bins = make_histogram(numbers, bin_count);
    auto val_sign = fun_sign(numbers, bin_count);
    show_histogram_svg(bins,val_sign);
    return 1;
}
