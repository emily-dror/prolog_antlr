CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCDIR = src
INCDIR = include
LIBDIR = lib
BUILDDIR = build
TESTSDIR = tests

SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

TARGET = project_name

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)

test:
	@echo "Running tests..."
	# Add your test runner commands here, e.g., GoogleTest

.PHONY: all clean test

