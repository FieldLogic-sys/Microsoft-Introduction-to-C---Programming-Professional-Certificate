# Define the compiler
CXX = g++

# Define compiler flags (enable warnings and use C++17)
CXXFLAGS = -Wall -std=c++17

# Define the target executable name
TARGET = DataLogger

# Define the source files
SRCS = main.cpp Logger.cpp utils.cpp

# The default rule to build the program
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean up the folder (remove the exe)
clean:
	rm -f $(TARGET)