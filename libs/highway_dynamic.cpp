#include "highway_dynamic.h"

#ifndef HWY_TARGET_INCLUDE
#undef HWY_TARGET_INCLUDE
#endif
#define HWY_TARGET_INCLUDE "highway_dynamic.cpp"
#include <hwy/foreach_target.h>
#include <hwy/highway.h>

#include <iostream>
#include <vector>

HWY_BEFORE_NAMESPACE();

namespace mandel
{
namespace HWY_NAMESPACE
{

static std::vector<int> highway_dynamic_impl( float start_re, float start_im, float end_re, float end_im, int num_pixels )
{
    static constexpr int MAX_ITER{65536};

    std::vector<int> output;
    output.resize(num_pixels);
    const float re_scale = (end_re - start_re) / static_cast<float>(num_pixels);
    const float im_scale = (end_im - start_im) / static_cast<float>(num_pixels);

    const HWY_FULL(float) d;
    const HWY_FULL(int32_t) di;
    using VecZ = decltype(Zero(d));
    using VecI = decltype(Zero(di));
    using VecMask = decltype(Zero(d) < Zero(d));
    const VecI one{Set(di, 1)};

    const float cy = start_im + im_scale;
    const VecZ cy_vec = Set(d, cy);
    for (int x = 0; x < num_pixels; x += Lanes(d))
    {
        // Initialize SIMD vectors for the x coordinates
        VecZ cx_vec = MulAdd(Iota(d, x), Set(d, re_scale), Set(d, start_re));
        VecZ zx_vec = cx_vec;
        VecZ zy_vec = cy_vec;
        VecI iter_vec = one;

        for (int i = 0; i < MAX_ITER; ++i)
        {
            const VecZ zx2 = zx_vec * zx_vec;
            const VecZ zy2 = zy_vec * zy_vec;
            const VecZ magnitude2 = zx2 + zy2;

            const VecMask mask = magnitude2 < Set(d, 4.0f);
            if (AllFalse(d, mask))
            {
                break;
            }

            iter_vec += IfThenElseZero(RebindMask(di, mask), one);
            const VecZ new_zy_vec = Set(d, 2.0f) * zx_vec * zy_vec + cy_vec;
            zx_vec = zx2 - zy2 + cx_vec;
            zy_vec = new_zy_vec;
        }

        // Store results
        Store(iter_vec, di, output.data() + x);
    }
    return output;
}

} // namespace HWY_NAMESPACE
} // namespace fractal

HWY_AFTER_NAMESPACE();

#if HWY_ONCE

namespace mandel
{

HWY_EXPORT(highway_dynamic_impl);

std::vector<int> span_highway_dynamic_float(float start_re, float start_im, float end_re, float end_im, int num_pixels)
{
    return HWY_DYNAMIC_DISPATCH(highway_dynamic_impl)(start_re, start_im, end_re, end_im, num_pixels);
}

} // namespace fractal

#endif
