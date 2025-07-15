# Train-Platform-Allotment

This program allocates platforms to trains based on their arrival and departure times using a priority queue.

### How to Use
1. Compile the code (`train_platform_allocation.cpp`) using a C++ compiler.
2. Run the executable.
3. Enter the number of trains and their arrival/departure times as prompted.

### Logic
- The program sorts trains based on arrival times.
- It uses a priority queue to efficiently manage platform allocations.
- Outputs the platform assigned to each train and the total number of platforms used.

### Example
Enter number of trains: 4
Train 1 (Arrival Departure): 900 950
Train 2 (Arrival Departure): 930 1030
Train 3 (Arrival Departure): 1000 1050
Train 4 (Arrival Departure): 1040 1100

Platform Assignments:
Train 1 -> Platform 1
Train 2 -> Platform 2
Train 3 -> Platform 1
Train 4 -> Platform 2

Total Platforms Used: 2
