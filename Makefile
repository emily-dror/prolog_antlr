# Compiler Options
CXX = clang++
CXXFLAGS = -Wall -std=c++17
ANTLR_CMD = antlr -Dlanguage=Cpp
LINK_FLAGS = -L $(LIB_DIR) -l $(DYLIB_NAME) -Wl,-rpath,@loader_path/$(LIB_DIR)
brief = @echo "[$(patsubst $(OBJ_DIR)/%,%,$(@))]";

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

# Lexer and Parser, Don't Change!!
LEXER_PATH = $(BUILD_DIR)/$(patsubst %.g4,%Lexer.cpp,$(GRAMMAR_DIR)/prolog.g4)
PARSER_PATH = $(BUILD_DIR)/$(patsubst %.g4,%Parser.cpp,$(GRAMMAR_DIR)/prolog.g4)
LEXER_OBJ = $(OBJ_DIR)/$(subst .cpp,.o,$(notdir $(LEXER_PATH)))
PARSER_OBJ = $(OBJ_DIR)/$(subst .cpp,.o,$(notdir $(PARSER_PATH)))

# Project Paramaters
TARGET = prolog_parser
DYLIB_NAME = antlr4-runtime
GRAMMAR_FILE = $(GRAMMAR_DIR)/prolog.g4

all: $(TARGET)

$(TARGET): BUILD_DIRS $(OBJ_FILES) $(LEXER_OBJ) $(PARSER_OBJ)
	$(brief) $(CXX) $(OBJ_DIR)/*.o $(LINK_FLAGS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp ANTLR_HEADERS
	$(brief) $(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

$(LEXER_OBJ): ANTLR_HEADERS
	$(brief) $(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $(LEXER_PATH) -o $@

$(PARSER_OBJ): ANTLR_HEADERS
	$(brief) $(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $(PARSER_PATH) -o $@

ANTLR_HEADERS: BUILD_DIRS
	# Generate ANTLR4 lexer and parser
	$(brief) $(ANTLR_CMD) -o $(BUILD_DIR) $(GRAMMAR_FILE)

	# Move header files into build/include directory
	mv $(BUILD_DIR)/$(GRAMMAR_DIR)/*.h $(BUILD_INCLUDE_DIR)

BUILD_DIRS:
	echo "\nUsing Development Build Flow\n"
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BUILD_INCLUDE_DIR)

clean:
	$(brief) rm -rf $(BUILD_DIR)/* $(TARGET)

test:
	@echo "Running tests..."
	# Add your test runner commands here, e.g., GoogleTest

.PHONY:
	all clean test

.SILENT:
	all clean test $(TARGET) $(OBJ_DIR)/%.o $(LEXER_OBJ) $(PARSER_OBJ) ANTLR_HEADERS BUILD_DIRS
