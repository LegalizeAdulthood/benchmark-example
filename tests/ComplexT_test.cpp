#include <mandel/ComplexT.h>

#include <gtest/gtest.h>

#include <cmath>
#include <complex>

TEST(TestComplexT, defaultConstruct)
{
    ComplexT<float> z;

    EXPECT_EQ(0.0f, z.real);
    EXPECT_EQ(0.0f, z.imag);
}

TEST(TestComplexT, constructFromReal)
{
    ComplexT<float> z{6.0f};

    EXPECT_EQ(6.0f, z.real);
    EXPECT_EQ(0.0f, z.imag);
}

TEST(TestComplexT, constructFromRealImaginary)
{
    ComplexT<float> z{6.0f, 3.0f};

    EXPECT_EQ(6.0f, z.real);
    EXPECT_EQ(3.0f, z.imag);
}

TEST(TestComplexT, copyConstruct)
{
    const ComplexT<float> c{6.0f, 3.0f};
    ComplexT<float> z{c};

    EXPECT_EQ(6.0f, z.real);
    EXPECT_EQ(3.0f, z.imag);
}

TEST(TestComplexT, copyAssign)
{
    const ComplexT<float> c{6.0f, 3.0f};
    ComplexT<float> z = c;

    EXPECT_EQ(6.0f, z.real);
    EXPECT_EQ(3.0f, z.imag);
}

TEST(TestComplexT, addReal)
{
    const ComplexT<float> c{6.0f, 3.0f};
    ComplexT<float> z = c + 4.0f;

    EXPECT_EQ(10.0f, z.real);
    EXPECT_EQ(3.0f, z.imag);
}

TEST(TestComplexT, addComplex)
{
    const ComplexT<float> c{6.0f, 3.0f};
    ComplexT<float> z = c + c;

    EXPECT_EQ(c.real + c.real, z.real);
    EXPECT_EQ(c.imag + c.imag, z.imag);
}

TEST(TestComplexT, multiplyReal)
{
    const ComplexT<float> c{6.0f, 3.0f};
    ComplexT<float> z = c * 2.0f;

    EXPECT_EQ(c.real * 2.0f, z.real);
    EXPECT_EQ(c.imag * 2.0f, z.imag);
}

TEST(TestComplexT, multiplyComplex)
{
    const ComplexT<float> c{6.0f, 3.0f};
    ComplexT<float> z = c * c;
    std::complex<float> expected{std::complex<float>{c.real, c.imag}};
    expected *= expected;

    EXPECT_EQ(expected.real(), z.real);
    EXPECT_EQ(expected.imag(), z.imag);
}

TEST(TestComplexT, abs)
{
    const ComplexT<float> c{6.0f, 3.0f};

    const float mag{c.abs()};

    EXPECT_EQ(std::sqrt(c.real*c.real + c.imag*c.imag), mag);
}
