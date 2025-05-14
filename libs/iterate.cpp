#include "mandel/iterate.h"
#include "mandel/ComplexT.h"

#include <cmath>
#include <complex>

static constexpr int MAX_ITER{65536};

template <typename T>
static int iterate(std::complex<T> c)
{
    std::complex z{c};

    int iter{1};
    for (int i = 0; i < MAX_ITER; ++i)
    {
        if (std::abs(z) > static_cast<T>(2))
        {
            break;
        }
        z = z * z + c;
        ++iter;
    }
    return iter;
}

namespace mandel
{

int iterate_std_complex(float real, float imag)
{
    return iterate(std::complex{real, imag});
}

int iterate_std_complex(double real, double imag)
{
    return iterate(std::complex{real, imag});
}

} // namespace mandel

template <typename T>
static int iterate(ComplexT<T> c)
{
    ComplexT z{c};

    int iter{1};
    for (int i = 0; i < MAX_ITER; ++i)
    {
        if (z.abs() > static_cast<T>(2))
        {
            break;
        }
        z = z * z + c;
        ++iter;
    }
    return iter;
}

namespace mandel
{

int iterate_complex(float real, float imag)
{
    return iterate(ComplexT<float>{real, imag});
}

int iterate_complex(double real, double imag)
{
    return iterate(ComplexT<double>{real, imag});
}

} // namespace mandel

template <typename T>
static int iterate(T cr, T ci)
{
    T zr{cr};
    T zi{ci};

    int iter{1};
    for (int i = 0; i < MAX_ITER; ++i)
    {
        if (std::abs(zr * zr + zi * zi) > static_cast<T>(4))
        {
            break;
        }
        // (a + bi)*(a + bi) = a(a + bi) + bi(a + bi)
        //                   = a^2 + abi + abi + b^2i^2
        //                   = a^2 - b^2 + 2abi
        const T t{zr * zr - zi * zi};
        zi *= static_cast<T>(2) * zr;
        zi += ci;
        zr = t + cr;
        ++iter;
    }
    return iter;
}

namespace mandel
{

int iterate_manual(float real, float imag)
{
    return iterate(real, imag);
}

int iterate_manual(double real, double imag)
{
    return iterate(real, imag);
}

} // namespace mandel
