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
double fun_sign(const vector<double> numbers,size_t bin_count )
{
    double max, min;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    bin_size = round(bin_size * 100) / 100;
    double val_sign=0;
    val_sign = val_sign + bin_size;
    return val_sign;
}

void show_histogram_svg(const vector<double>& bins,double val_sign)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;

    size_t max_count = 0;
   /* string stroke;
    string fill;
    double sr = mean(bins);
    for (int i=0; i < bins.size(); i++){
        if (bins[i]<=sr)
        {
            stroke="green";
            fill="green";
        }
        if (bins[i]>sr)
        {
            stroke="red";
            fill="red";
        }
    }
    */
    for (double count : bins)
        {
        if (count > max_count)
            max_count = count;
        }

        const bool scaling_needed = max_count > MAX_ASTERISK;

        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;

            for (double bin : bins)
            {
                    auto  height = (double)(bin * scaling_factor);
                    const double bin_width = BLOCK_WIDTH * height;
                    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
                    double sr = mean(bins);
                    for (int i=0; i < bins.size(); i++){
                        if (bins[i]<=sr)
                        {
                            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "green", "#ffeeee");
                        }
                        else if (bins[i]>sr)
                        {
                            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
                        }
                    }
                    top += BIN_HEIGHT;
            }

        }

        else
        {
            for (double bin : bins)
            {
                    const double bin_width = BLOCK_WIDTH * bin;
                    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
                    double sr = mean(bins);
                    for (int i=0; i < bins.size(); i++){
                        if (bins[i]<=sr)
                        {
                            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "green", "#ffeeee");
                        }
                        else if (bins[i]>sr)
                        {
                            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
                        }
                    }
                    top += BIN_HEIGHT;
            }

        }

    svg_end();
}
