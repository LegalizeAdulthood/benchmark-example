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

BENCHMARK(span_std_float);
