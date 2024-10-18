# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Output executable
TARGET = RailwayReservationSystem

# Source files
SRCS = Main.c Train.c Passenger.c Queue.c FileIO.c

# Object files (generated from source files)
OBJS = $(SRCS:.c=.o)

# Rule to build the executable
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files to .o (object files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# A debug target that uses debugging flags
debug: CFLAGS += -g
debug: clean $(TARGET)

# Phony targets: these do not correspond to actual files
.PHONY: all clean debug
