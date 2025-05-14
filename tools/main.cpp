#include <mandel/span.h>

#include <benchmark/benchmark.h>

int main(int argc, char **argv)
{
    char arg0_default[] = "benchmark";
    char *args_default = arg0_default;
    if (!argv)
    {
        argc = 1;
        argv = &args_default;
    }
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv))
    {
        return 1;
    }
    benchmark::AddCustomContext("static target", mandel::highway_static_target_name());
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::Shutdown();
    return 0;
}
