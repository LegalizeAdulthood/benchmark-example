#pragma once

#include <vector>

namespace mandel
{

std::vector<int> span_std_complex(float start_re, float start_im, float end_re, float end_im, int num_pixels);
std::vector<int> span_std_complex(double start_re, double start_im, double end_re, double end_im, int num_pixels);

} // namespace mandel
