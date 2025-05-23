#pragma once

namespace mandel
{

int iterate_std_complex(float real, float imag);
int iterate_std_complex(double real, double imag);
int iterate_complex(float real, float imag);
int iterate_complex(double real, double imag);
int iterate_manual(float real, float imag);
int iterate_manual(double real, double imag);

} // namespace mandel
