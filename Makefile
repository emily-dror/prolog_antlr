# Compiler Options
CXX = clang++
CXXFLAGS = -Wall -std=c++17
ANTLR_CMD = antlr -Dlanguage=Cpp
LINK_FLAGS = -L $(LIB_DIR) -l $(DYLIB_NAME) -Wl,-rpath,@loader_path/$(LIB_DIR)

# Directory Structure
SRC_DIR = src
LIB_DIR = lib
TEST_DIR = tests
BUILD_DIR = build
GRAMMAR_DIR = grammar
INCLUDE_DIRS = \
    -I include \
    -I include/antlr4-runtime \
	-I $(BUILD_DIR)/include

# Build Directory, Don't Change!!
OBJ_DIR = $(BUILD_DIR)/obj
BUILD_INCLUDE_DIR = $(BUILD_DIR)/include
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Project Paramaters
TARGET = prolog_parser
DYLIB_NAME = antlr4-runtime
GRAMMAR_FILE = $(GRAMMAR_DIR)/prolog.g4

all: $(TARGET)

$(TARGET): BUILD_DIRS ANTLR $(OBJ_FILES)
	@ $(CXX) $(OBJ_DIR)/*.o $(LINK_FLAGS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp BUILD_DIRS ANTLR
	@ $(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

ANTLR: BUILD_DIRS
	@ $(ANTLR_CMD) -o $(BUILD_DIR) $(GRAMMAR_FILE)
	@ cd $(OBJ_DIR); $(CXX) $(CXXFLAGS) -I ../../include/antlr4-runtime -c \
							`find ../$(GRAMMAR_DIR) -maxdepth 1 -type f -name '*.cpp'`
	@ mv $(BUILD_DIR)/$(GRAMMAR_DIR)/*.h $(BUILD_INCLUDE_DIR)

BUILD_DIRS:
	@ echo "\nUsing Development Build Flow\n"
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(BUILD_INCLUDE_DIR)

clean:
	@ rm -rf $(BUILD_DIR)/* $(TARGET)

test:
	@echo "Running tests..."
	# Add your test runner commands here, e.g., GoogleTest

.PHONY: all clean test
