# Data Logger Application

A robust C++17 application designed to process sensor data from CSV files and maintain a persistent, structured audit log.

## Features
- **Persistence**: Uses `std::ios::app` to append logs without data loss.
- **Modularity**: Codebase split into `Logger` and `Utils` modules for scalability.
- **Robustness**: Validates file existence and stream states using the C++17 Filesystem API.
- **Traceability**: Every log entry includes a human-readable timestamp.

## Project Structure
- `main.cpp`: Entry point and directory initialization.
- `Logger.cpp/h`: Logic for CSV parsing and file output.
- `utils.cpp/h`: Utility functions for timestamps and directory management.
- `data.csv`: Source input file (SensorName, Value).
- `logs/`: Directory where persistent log files are stored.

## Building and Running
1. Open Git Bash in the project directory.
2. Compile using the Makefile:
   ```bash
   mingw32-make
   ```
3. Run the executable 
`./DataLogger`

 