# Define the compiler
CXX = g++

# UPDATED: Using C++20 for stable std::format support on Windows
CXXFLAGS = -Wall -std=c++20

# Define the target executable name
TARGET = DataLogger

# Define the source files
SRCS = main.cpp Logger.cpp utils.cpp

# The default rule to build the program
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean up the folder
clean:
	rm -f $(TARGET)