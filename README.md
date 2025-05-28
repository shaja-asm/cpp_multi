# Multiprocessing Prime Computation in C++

## Overview

This project demonstrates multiprocessing in C++ using `fork()` to fully utilize CPU cores on a Linux (Ubuntu) system. It divides the computational workload—checking prime numbers—across available cores to maximize performance.

## Features

* Efficient multiprocessing utilizing all CPU cores.
* Heavy computational task: prime number checking.
* Clear demonstration of `fork()` and inter-process operations.

## Prerequisites

* Linux (Ubuntu recommended)
* C++ Compiler (e.g., `g++`)

## Compilation

Compile the source code with:

```bash
g++ -o prime_parallel prime_parallel.cpp -pthread
```

## Execution

Run the compiled executable:

```bash
./prime_parallel
```

## Code Explanation

* **`workerTask()`**: Each process computes prime numbers within its assigned numeric range.
* **Workload Distribution**: The numeric range `[1, 50000000000000000]` is evenly divided across all CPU cores.
* **Multiprocessing**: The program uses `fork()` to spawn multiple child processes equal to the number of CPU cores detected.

## Adjusting Computation Load

Modify the range variables in `main()` to adjust computational complexity:

```cpp
unsigned long range_start = 1;
unsigned long range_end = 50000000000000000;
```

Decrease the range for quicker tests or increase it to intensify CPU utilization.

## Notes

* Ensure you have sufficient hardware resources, as very large ranges can significantly impact execution time.
* Termination and synchronization are handled neatly by the parent process waiting for all child processes to complete.

## License

This project is provided under the MIT License.
# Multiprocessing Prime Computation in C++

## Overview

This project demonstrates multiprocessing in C++ using `fork()` to fully utilize CPU cores on a Linux (Ubuntu) system. It divides the computational workload—checking prime numbers—across available cores to maximize performance.

## Features

* Efficient multiprocessing utilizing all CPU cores.
* Heavy computational task: prime number checking.
* Clear demonstration of `fork()` and inter-process operations.

## Prerequisites

* Linux (Ubuntu recommended)
* C++ Compiler (e.g., `g++`)

## Compilation

Compile the source code with:

```bash
g++ -o prime_parallel prime_parallel.cpp -pthread
```

## Execution

Run the compiled executable:

```bash
./prime_parallel
```

## Code Explanation

* **`workerTask()`**: Each process computes prime numbers within its assigned numeric range.
* **Workload Distribution**: The numeric range `[1, 50000000000000000]` is evenly divided across all CPU cores.
* **Multiprocessing**: The program uses `fork()` to spawn multiple child processes equal to the number of CPU cores detected.

## Adjusting Computation Load

Modify the range variables in `main()` to adjust computational complexity:

```cpp
unsigned long range_start = 1;
unsigned long range_end = 50000000000000000;
```

Decrease the range for quicker tests or increase it to intensify CPU utilization.

## Notes

* Ensure you have sufficient hardware resources, as very large ranges can significantly impact execution time.
* Termination and synchronization are handled neatly by the parent process waiting for all child processes to complete.

## License

This project is provided under the MIT License.
