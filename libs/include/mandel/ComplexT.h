#pragma once

#include <cmath>

template <typename T>
struct ComplexT
{
    T real{};
    T imag{};

    ComplexT operator+(T value) const
    {
        return {real + value, imag};
    }

    ComplexT operator+(ComplexT value) const
    {
        return {real + value.real, imag + value.imag};
    }

    ComplexT operator*(T value) const
    {
        return {real * value, imag * value};
    }
    // (a + bi) * (c + di) = a(c + di) + bi(c + di)
    //                     = ac + adi + bci + bdi^2
    //                     = ac + adi + bci - bd
    //                     = (ac - bd) + (ad + bc)i
    ComplexT operator*(ComplexT value) const
    {
        return {real * value.real - imag * value.imag, real * value.imag + imag * value.real};
    }

    T abs() const
    {
        return std::sqrt(real * real + imag * imag);
    }
};
