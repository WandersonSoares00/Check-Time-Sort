# Check-Time-Sort

A comparison of the sort times of the following algorithms:
- [Heapsort](https://en.wikipedia.org/wiki/Heapsort)
- Deterministic [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
- Randomized [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
- [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
- [Introsort](https://en.wikipedia.org/wiki/Introsort)

## Execution modes:
The program generetes instances for sorting and runs them for each algorithm. Follow the types of instances below:
- Random: fill the array with random elements.
- Worst case: fill the array in a way that leads to the worst case of the quicksort algorithm
- Ascending order: generate an instance sorted in ascending order
- Descending order: generate an instance sorted in descending order

## Usage

### Dependencies
- GNU C++ Compiler ( g++ )
- GNU Make installed

### Run
1. Clone the repository:
    `git clone https://github.com/WandersonSoares00/Check-Time-Sort`
2. Change the directory:
    `cd Check-Time-Sort`
3. Compile:
    `make all`
4. Run with options:
    The program can be perform with the following model:
    ./main [instance type] [array size] [number of instances]
    
    Where [instance type] can be A (for random), C (for Ascending order), D (for Descending order) or P(for Worst case)

    Where is an example:
    run `./main A 10000000 5`
    The program will show the results of sorting 5 randomly filled arrays of size 10000000

## Licence information
This project is licensed under the GNU General Public License v3.0.
