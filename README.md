# Check-Time-Sort

A comparison of the sort times of the following algorithms:
- [Heapsort](https://en.wikipedia.org/wiki/Heapsort)
- Deterministic [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
- Randomized [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
- [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
- [Introsort](https://en.wikipedia.org/wiki/Introsort)

## Execution modes:
The program generetes instances for sorting and runs them for each algorithm. Follow the types of instances below:
- Random: Fill the array with random elements.
- Worst case: Populate the array in a manner that leads to the worst-case scenario for the quicksort algorithm.
- Ascending order: Generate an instance sorted in ascending order
- Descending order: Generate an instance sorted in descending order

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
    The program can be executed using the following format:
    ./main [instance type] [array size] [number of instances]
    
    Where [instance type] can be A (for random), C (for Ascending order), D (for Descending order) or P(for Worst case)

    Here's an example:
    run `./main A 10000000 5` <br>
    This command will display the sorting results for 5 randomly populated arrays of size 10,000,000.

## Licence information
This project is licensed under the GNU General Public License v3.0.
