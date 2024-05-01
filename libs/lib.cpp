#include "lib/lib.h"

#include <complex>
#include <cmath>

constexpr int MAX_ITER{65536};

int iterate_std_complex(float real, float imag)
{
    std::complex c(real, imag);
    std::complex z{c};

    int iter{1};
    for (int i = 0; i < MAX_ITER; ++i)
    {
        if (std::abs(z) > 4.0f)
        {
            break;
        }
        z = z*z + c;
        ++iter;
    }
    return iter;
}
