#include <mandel/span.h>

#include <benchmark/benchmark.h>

#include <numeric>

static void span_std_float(benchmark::State &state)
{
    std::vector<int> iters;
    int total_iters{};
    for (auto item : state)
    {
        iters = mandel::span_std_complex(-0.75f, 0.0f, 1.5f, 0.0f, 256);
        total_iters = std::accumulate(iters.begin(), iters.end(), total_iters);
    }
    state.counters["total_iters"] = total_iters;
}

static void span_std_double(benchmark::State &state)
{
    std::vector<int> iters;
    int total_iters{};
    for (auto item : state)
    {
        iters = mandel::span_std_complex(-0.75, 0.0, 1.5, 0.0, 256);
        total_iters = std::accumulate(iters.begin(), iters.end(), total_iters);
    }
    state.counters["total_iters"] = total_iters;
}

static void span_complex_float(benchmark::State &state)
{
    std::vector<int> iters;
    int total_iters{};
    for (auto item : state)
    {
        iters = mandel::span_complex(-0.75f, 0.0f, 1.5f, 0.0f, 256);
        total_iters = std::accumulate(iters.begin(), iters.end(), total_iters);
    }
    state.counters["total_iters"] = total_iters;
}

static void span_complex_double(benchmark::State &state)
{
    std::vector<int> iters;
    int total_iters{};
    for (auto item : state)
    {
        iters = mandel::span_complex(-0.75, 0.0, 1.5, 0.0, 256);
        total_iters = std::accumulate(iters.begin(), iters.end(), total_iters);
    }
    state.counters["total_iters"] = total_iters;
}

BENCHMARK(span_std_float);
BENCHMARK(span_std_double);
BENCHMARK(span_complex_float);
BENCHMARK(span_complex_double);
