#include "BenchMark.h"
#include "Edge_sketch.h"
int main(int argc, char *argv[]) {
	std::cout << "test00";
        Edge_Sketch<uint64_t, uint64_t> * node = new Edge_Sketch<uint64_t, uint64_t>(500000);
	Edge_Sketch<uint64_t, uint64_t> * edges = new Edge_Sketch<uint64_t, uint64_t>(500000);
	/*
    for(uint32_t i = 1;i < argc;++i) {
        std::cout << argv[i] << std::endl;
        BenchMark dataset(argv[i], "Dataset");
        dataset.HHMultiBench(500000, 0.0001);
    }*/
    return 0;
}
