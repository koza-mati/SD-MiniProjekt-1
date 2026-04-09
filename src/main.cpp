#include "menu.hpp"
#include <string>

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--benchmarks") {
        runBenchmarks();
        return 0;
    }
    menuGlowne();
    return 0;
}
