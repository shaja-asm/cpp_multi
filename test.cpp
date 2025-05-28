#include <thread>
#include <iostream>

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Available cores: " << cores << std::endl;
    return 0;
}
