#include "mandel/span.h"

#include "mandel/iterate.h"

#include <complex>

namespace mandel
{

template <typename T>
std::vector<int> span(std::complex<T> start, std::complex<T> end, int num_pixels)
{
    std::complex<T> c{start};
    const std::complex<T> delta{(end - start) / static_cast<T>(num_pixels)};
    std::vector<int> iters;
    iters.reserve(num_pixels);
    for (int i = 0; i < num_pixels; ++i)
    {
        iters.push_back(iterate_std_complex(c.real(), c.imag()));
        c += delta;
    }
    return iters;
}

std::vector<int> span_std_complex(float start_re, float start_im, float end_re, float end_im, int num_pixels)
{
    return span(std::complex{start_re, start_im}, std::complex{end_re, end_im}, num_pixels);
}

std::vector<int> span_std_complex(double start_re, double start_im, double end_re, double end_im, int num_pixels)
{
    return span(std::complex{start_re, start_im}, std::complex{end_re, end_im}, num_pixels);
}

} // namespace mandel
