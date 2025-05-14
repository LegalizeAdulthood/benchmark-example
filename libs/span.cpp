#include "mandel/span.h"

#include "mandel/iterate.h"

#include <complex>

namespace mandel
{

std::vector<int> span_std_complex(float start_re, float start_im, float end_re, float end_im, int num_pixels)
{
    std::complex<float> c{start_re, start_im};
    const float step{1.0f / static_cast<float>(num_pixels)};
    const std::complex<float> delta{(end_re - start_re) * step, (end_im - start_im) * step};
    std::vector<int> iters;
    iters.reserve(num_pixels);

    for (int i = 0; i < num_pixels; ++i)
    {
        iters.push_back(iterate_std_complex(c.real(), c.imag()));
        c += delta;
    }
    return iters;
}

} // namespace mandel
