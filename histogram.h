#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
double mean(const vector<size_t>& bins);

#endif // HISTOGRAM_H_INCLUDED
