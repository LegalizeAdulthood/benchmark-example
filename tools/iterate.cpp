#include <mandel/iterate.h>

#include <benchmark/benchmark.h>

static void iterate_std_float(benchmark::State &state)
{
    int total_iters{};
    for (auto item : state)
    {
        total_iters += mandel::iterate_std_complex(-0.75f, 0.0f);
    }
    state.counters["total_iters"] = total_iters;
}

static void iterate_std_double(benchmark::State &state)
{
    int total_iters{};
    for (auto item : state)
    {
        total_iters += mandel::iterate_std_complex(-0.75, 0.0);
    }
    state.counters["total_iters"] = total_iters;
}

static void iterate_complex_float(benchmark::State &state)
{
    int total_iters{};
    for (auto item: state)
    {
        total_iters += mandel::iterate_complex(-0.75f, 0.0f);
    }
    state.counters["total_iters"] = total_iters;
}

static void iterate_complex_double(benchmark::State &state)
{
    int total_iters{};
    for (auto item: state)
    {
        total_iters += mandel::iterate_complex(-0.75, 0.0);
    }
    state.counters["total_iters"] = total_iters;
}

static void iterate_manual_float(benchmark::State &state)
{
    int total_iters{};
    for (auto item: state)
    {
        total_iters += mandel::iterate_manual(-0.75f, 0.0f);
    }
    state.counters["total_iters"] = total_iters;
}

static void iterate_manual_double(benchmark::State &state)
{
    int total_iters{};
    for (auto item: state)
    {
        total_iters += mandel::iterate_manual(-0.75, 0.0);
    }
    state.counters["total_iters"] = total_iters;
}

BENCHMARK(iterate_std_float);
BENCHMARK(iterate_std_double);
BENCHMARK(iterate_complex_float);
BENCHMARK(iterate_complex_double);
BENCHMARK(iterate_manual_float);
BENCHMARK(iterate_manual_double);
