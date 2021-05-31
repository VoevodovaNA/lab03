#include "svg.h"
#include "histogram.h"

void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_end()
{
    cout << "</svg>\n";
}


void
svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill  )
{

    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height
         << "' stroke='" << stroke << "' fill='" << fill << "'/>";
}


void show_histogram_svg( const vector<double>& bins,double val_sign)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    double top = 0;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top_sign=0;
    double scaling_factor=0;
    size_t bin_count = bins.size();
    size_t max_count = 0,k;
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

    double bin_size=val_sign;
    string str;
    int i = 0;
    double sr = mean(bins);
    for (size_t bin : bins)
    {
        string str= to_string(val_sign);
        str.erase(4,4);
        const double bin_width = BLOCK_WIDTH * bin * scaling_factor;
        svg_text(2*TEXT_LEFT, top + TEXT_BASELINE+ top_sign, to_string(bin));


        if (bins[i] > sr)
        {
            svg_rect(TEXT_WIDTH, top+ top_sign, bin_width, BIN_HEIGHT, "red", "#ffeeee");
        }
        if (bins[i] <= sr)
        {
            svg_rect(TEXT_WIDTH, top+ top_sign, bin_width, BIN_HEIGHT, "green", "#ffeeee");
        }
        else if (i < bin_count - 1)
        {
            svg_text(0, top + TEXT_BASELINE + top_sign + BIN_HEIGHT, str);
            i++;
        }
        top += BIN_HEIGHT;
        top_sign += BIN_HEIGHT;
        val_sign = val_sign + bin_size;


    }
    svg_end();
}
