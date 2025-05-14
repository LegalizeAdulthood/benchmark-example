#include <mandel/mandel.h>

#include <benchmark/benchmark.h>

static void iterate_std_float(benchmark::State &state)
{
    for (auto item : state)
    {
        const int iter = iterate_std_complex(-0.75f, 0.0f);
    }
}

static void iterate_std_double(benchmark::State &state)
{
    for (auto item : state)
    {
        const int iter = iterate_std_complex(-0.75, 0.0);
    }
}

static void iterate_complex_float(benchmark::State &state)
{
    for (auto item: state)
    {
        const int iter = iterate_complex(-0.75f, 0.0f);
    }
}

static void iterate_complex_double(benchmark::State &state)
{
    for (auto item: state)
    {
        const int iter = iterate_complex(-0.75, 0.0);
    }
}

static void iterate_manual_float(benchmark::State &state)
{
    for (auto item: state)
    {
        const int iter = iterate_manual(-0.75f, 0.0f);
    }
}

static void iterate_manual_double(benchmark::State &state)
{
    for (auto item: state)
    {
        const int iter = iterate_manual(-0.75, 0.0);
    }
}

BENCHMARK(iterate_std_float);
BENCHMARK(iterate_std_double);
BENCHMARK(iterate_complex_float);
BENCHMARK(iterate_complex_double);
BENCHMARK(iterate_manual_float);
BENCHMARK(iterate_manual_double);
