#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (numbers.size() == 0)
        return;

    else
    {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers)
        {
            if (number < min)
            {
                min = number;
            }
            if (number > max)
            {
                max = number;
            }
        }

    }
}

double mean(const vector<double>& bins) {
    if (bins.size()==0) {
        return 0;
        }
    double result;
    double sum=0;
    for (int i = 0; i<bins.size(); i++)
        {
            sum=sum+bins[i];
        }
        result=sum/bins.size();
        return result;
    }
