#include <mandel/mandel.h>

#include <benchmark/benchmark.h>

static void bench_std_float(benchmark::State &state)
{
    for (auto item : state)
    {
        const int iter = iterate_std_complex(-0.75f, 0.0f);
    }
}

static void bench_std_double(benchmark::State &state)
{
    for (auto item : state)
    {
        const int iter = iterate_std_complex(-0.75, 0.0);
    }
}

BENCHMARK(bench_std_float);
BENCHMARK(bench_std_double);

BENCHMARK_MAIN();
