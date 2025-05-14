#include "lib/lib.h"

#include <complex>
#include <cmath>

constexpr int MAX_ITER{65536};

template <typename T>
static int iterate(std::complex<T> c)
{
    std::complex z{c};

    int iter{1};
    for (int i = 0; i < MAX_ITER; ++i)
    {
        if (std::abs(z) > static_cast<T>(4))
        {
            break;
        }
        z = z*z + c;
        ++iter;
    }
    return iter;
}

int iterate_std_complex(float real, float imag)
{
    return iterate(std::complex{real, imag});
}

int iterate_std_complex(double real, double imag)
{
    return iterate(std::complex{real, imag});
}
