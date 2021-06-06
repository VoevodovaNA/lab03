#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;

void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke,
              string fill);
double fun_sign(const vector<double> numbers, size_t bin_count);
void show_histogram_svg(const vector<size_t>& bins, double val_sign);
#endif // SVG_H_INCLUDED
