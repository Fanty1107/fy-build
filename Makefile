# Name of the final executable
TARGET = cbuild

# Compiler and Flags
CXX      = clang++
CXXFLAGS = -Wall -Wextra -std=c++23 -Wpedantic
LDFLAGS  =

# Build configurations
DEBUG_FLAGS   = -g -O0 -fsanitize=address
RELEASE_FLAGS = -O3 -DNDEBUG

# Directories
SRC_DIR   = src
BUILD_DIR = build
BIN_DIR   = .

# Automatically find all .cpp files in SRC_DIR and map them to object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# External Libraries & Include paths
LIBS     =
INCLUDES = -Iinclude

# -----------------------------------------------------------------------------
# Targets
# -----------------------------------------------------------------------------

# Default target: Debug build
all: CXXFLAGS += $(DEBUG_FLAGS)
all: LDFLAGS  += $(DEBUG_FLAGS)
all: $(BIN_DIR)/$(TARGET)

# Release target: Optimized build with debugging info stripped
release: CXXFLAGS += $(RELEASE_FLAGS)
release: LDFLAGS  += $(RELEASE_FLAGS)
release: clean $(BIN_DIR)/$(TARGET)

# Linking the final executable
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)
	@echo "Built target: $(TARGET)"

# Compiling .cpp source files into object files + header dependency files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

# Run the compiled binary
run: all
	@./$(BIN_DIR)/$(TARGET)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)/$(TARGET)
	@echo "Cleaned build artifacts."

# Declare phony targets
.PHONY: all release run clean
