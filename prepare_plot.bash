#!/bin/bash

# The number of points
N=1000000

# Array of processor counts to test
processors=(1 2 3 4 5 6 7 8 9)

# Loop over each processor count
for p in "${processors[@]}"
do
    echo "Running with ${p} processors..."
    mpirun -n "$p" ./pi_calc $N >> results1.csv
done