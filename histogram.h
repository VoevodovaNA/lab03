#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

//#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <string>
//#include<iomanip>


using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
double mean(const vector<double>& bins);


#endif // HISTOGRAM_H_INCLUDED
