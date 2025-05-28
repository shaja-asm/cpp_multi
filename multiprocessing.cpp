#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <thread>
#include <vector>
#include <cmath>

// Function to check primality
bool is_prime(unsigned long num) {
    if (num < 2) return false;
    for (unsigned long i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void workerTask(int id, unsigned long start, unsigned long end) {
    std::cout << "Process ID: " << getpid() << " | Worker #" << id << " running...\n";

    unsigned int prime_count = 0;
    for (unsigned long num = start; num <= end; ++num) {
        if (is_prime(num)) {
            prime_count++;
        }
    }

    std::cout << "Worker #" << id << " found " << prime_count << " primes in range ["
              << start << ", " << end << "].\n";
}

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    pid_t pid;

    std::cout << "Spawning " << cores << " processes...\n";

    // Define computation range
    unsigned long range_start = 1;
    unsigned long range_end = 50000000000000000;
    unsigned long chunk_size = (range_end - range_start + 1) / cores;

    for (unsigned int i = 0; i < cores; ++i) {
        pid = fork();

        if (pid < 0) {
            std::cerr << "Fork failed\n";
            return 1;
        }

        if (pid == 0) {
            // Child process
            unsigned long chunk_start = range_start + i * chunk_size;
            unsigned long chunk_end = (i == cores - 1) ? range_end : chunk_start + chunk_size - 1;

            workerTask(i, chunk_start, chunk_end);
            return 0; // Return from child
        }
        // Parent continues loop
    }

    // Parent waits for all children
    for (unsigned int i = 0; i < cores; ++i) {
        wait(nullptr);
    }

    std::cout << "All processes finished.\n";
    return 0;
}