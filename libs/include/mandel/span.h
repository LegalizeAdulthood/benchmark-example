#pragma once

#include <vector>

namespace mandel
{

std::vector<int> span_std_complex(float start_re, float start_im, float end_re, float end_im, int num_pixels);
std::vector<int> span_std_complex(double start_re, double start_im, double end_re, double end_im, int num_pixels);
std::vector<int> span_complex(float start_re, float start_im, float end_re, float end_im, int num_pixels);
std::vector<int> span_complex(double start_re, double start_im, double end_re, double end_im, int num_pixels);
std::vector<int> span_manual(float start_re, float start_im, float end_re, float end_im, int num_pixels);
std::vector<int> span_manual(double start_re, double start_im, double end_re, double end_im, int num_pixels);
std::vector<int> span_highway_static_float(float start_re, float start_im, float end_re, float end_im, int num_pixels);
std::vector<int> span_highway_dynamic_float(float start_re, float start_im, float end_re, float end_im, int num_pixels);

const char *highway_static_target_name();
const char *highway_dynamic_target_name();

} // namespace mandel
