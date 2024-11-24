# Makefile for WiFi Simulator Project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -w -std=c++11 -Wall -I./include  # Add -I flag to specify the include directory

# Source files
SRCS = src/main.cpp src/WiFi4AP.cpp src/WiFi5AP.cpp src/WiFi6AP.cpp src/Device.cpp src/Packet.cpp src/AccessPoint.cpp src/Channel.cpp src/FrequencyBand.cpp src/User.cpp

# Output executable
TARGET = project

# Build the project
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Run the simulation
run: $(TARGET)
	./$(TARGET)

# Clean the project
clean:
	rm -f $(TARGET)
