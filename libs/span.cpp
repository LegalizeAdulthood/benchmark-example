#include "mandel/span.h"

#include "mandel/ComplexT.h"
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

template <typename T>
std::vector<int> span(ComplexT<T> start, ComplexT<T> end, int num_pixels)
{
    ComplexT<T> c{start};
    const ComplexT<T> delta{(end - start) / static_cast<T>(num_pixels)};
    std::vector<int> iters;
    iters.reserve(num_pixels);
    for (int i = 0; i < num_pixels; ++i)
    {
        iters.push_back(iterate_complex(c.real, c.imag));
        c += delta;
    }
    return iters;
}

std::vector<int> span_complex(float start_re, float start_im, float end_re, float end_im, int num_pixels)
{
    return span(ComplexT<float>{start_re, start_im}, ComplexT<float>{end_re, end_im}, num_pixels);
}

std::vector<int> span_complex(double start_re, double start_im, double end_re, double end_im, int num_pixels)
{
    return span(ComplexT<double>{start_re, start_im}, ComplexT<double>{end_re, end_im}, num_pixels);
}

} // namespace mandel
