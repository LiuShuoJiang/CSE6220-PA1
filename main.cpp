#include <mpi/mpi.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {
    int rank, size;
    int n, local_n;
    int count = 0, total_count;
    int i;

    double x, y, PI_calculation, start_time, end_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 2) {
        if (rank == 0) {
            std::cerr << "Invalid input! Usage: " << argv[0] << "<point number>" << std::endl;
        }
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        n = atoi(argv[1]);
        start_time = MPI_Wtime();
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    srand(time(nullptr) + rank);

    local_n = n / size + (rank < n % size);

    for (int i = 0; i < local_n; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) count++;
    }

    MPI_Reduce(&count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        PI_calculation = 4.0 * total_count / n;
        end_time = MPI_Wtime();
        std::cout << std::fixed << std::setprecision(12) << PI_calculation
                  << ", " << end_time - start_time << std::endl;
    }

    MPI_Finalize();
    return 0;
}
