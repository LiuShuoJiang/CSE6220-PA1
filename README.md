# CSE 6220 PA1

## Overview

This program estimates the value of $\pi$ using the Monte Carlo method by generating random points
within a unit square and determining the fraction that fall within a unit circle centered at the origin.
The estimation uses parallel computing with MPI to distribute the computation across multiple processors,
demonstrating the effectiveness and scalability of parallel processing for numerical simulations.

## Technical Details

- It takes the total number of random points (`n`) as a command line argument.
- The master processor (rank `0`) broadcasts the total number of points to all processors.
- Each processor generates its subset of random points and counts how many fall inside the unit circle.
- Using `MPI_Reduce`, all local counts are summed up to the master processor to compute the final estimation of $\pi$.
- The program measures and outputs the run-time of the computation, along with the estimated value of $\pi$.
- Output format: The program outputs the estimated value of $\pi$, followed by the computation time, formatted as `"estimated_pi, time_in_seconds"`.

## Local Machine Used for Results

Windows Subsystem for Linux (WSL) running Ubuntu 22.04

## Compilation and Running

1. Compile the program using MPICH's `mpicxx` compiler wrapper:

``` 
mpicxx -o pi_calc mpi_pi_estimation.cpp -std=c++11
```

2. Run the program with a specific number of processors (`p`) and points (`n`):

```
mpirun -n [p] ./pi_calc [n]
```

Example for `4` processors and `10^6` points:

```
mpirun -n 4 ./pi_calc 1000000
```
