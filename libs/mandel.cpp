#include "mandel/mandel.h"
#include "mandel/ComplexT.h"

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

template <typename T>
static int iterate(ComplexT<T> c)
{
    ComplexT z{c};

    int iter{1};
    for (int i = 0; i < MAX_ITER; ++i)
    {
        if (z.abs() > static_cast<T>(4))
        {
            break;
        }
        z = z*z + c;
        ++iter;
    }
    return iter;
}

int iterate_complex(float real, float imag)
{
    return iterate(ComplexT<float>{real, imag});
}

int iterate_complex(double real, double imag)
{
    return iterate(ComplexT<double>{real, imag});
}
