#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <conio.h>
#include "histogram.h"


using namespace std;
using std::vector;

vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

void
find_minmax(const vector<double>& numbers, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
}

vector<size_t>
make_histogram(const vector<double> numbers, size_t bin_count) {
    double min, max;
    vector<size_t> bins(bin_count);
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
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
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

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}


void svg_rect(double x, double y, double width, double height, string stroke, string fill  )
{

    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height
         << "' stroke='" << stroke << "' fill='" << fill << "'/>";
}

double fun_sign(const vector<double>& numbers,size_t bin_count)
{

    double max,min;
    char str[4]="";
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    double step=bin_size;
    double sign = round(step*100)  / 100;
    step = step + bin_size;

    return sign ;
}

void
show_histogram_svg(const vector<size_t>& bins,char str) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    double top = 0;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double scaling_factor,k;
    size_t bin_count = bins.size();
    size_t max_count = 0;
    const auto MAX_WIDTH = IMAGE_WIDTH - TEXT_WIDTH;
    for (size_t i = 0; i < bin_count; i++)
    {
        k = bins[i] * BLOCK_WIDTH;
        if (k > MAX_WIDTH)
        {
            max_count = k;
        }
    }
    for (size_t i = 0; i < bin_count; i++)
    {
        if (max_count > MAX_WIDTH)
        {
            scaling_factor = (static_cast<double>(MAX_WIDTH) / max_count);
        }
        else
        {
            scaling_factor = 1;
        }
    }

    for (size_t bin : bins) {
        const double bin_width = BLOCK_WIDTH * bin * scaling_factor;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, std::to_string((long long)bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#ffeeee");
        top += BIN_HEIGHT;
    }


    //svg_begin(400, 300);
    //svg_text(20, 20, to_string(bins[0]));
    //svg_rect(0, 0, 100, 200, "blue", "#aaffaa");
    svg_end();
}

int main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    double min, max;
    find_minmax(numbers, min, max);
    const auto bins = make_histogram(numbers, bin_count);
    auto val_sign = fun_sign(numbers, bin_count);
    show_histogram_svg(bins,val_sign);
    return 1;
}
