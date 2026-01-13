# 1. Variables: Define the compiler and the flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O2

# 2. List of Object Files (the .o files we want to create)
OBJ = main.o basic_math.o advanced_math.o geometry.o statistics.o

# 3. The Target: The final name of the executable
TARGET = math_program

# 4. The "all" rule: This is what runs when you just type 'make'
all: $(TARGET)

# 5. Linking: This rule creates the executable by linking object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# 6. Compiling: These rules create .o files from .cpp files
# Make is smart: it knows that %.o depends on %.cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 7. Clean: This removes the compiled files so you can start fresh
clean:
	rm -f $(OBJ) $(TARGET)