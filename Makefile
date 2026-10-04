CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -Iinclude -Itests
BUILD_DIR := build
TEST_TARGET := $(BUILD_DIR)/test_linked_lists

.PHONY: all test clean

all: $(TEST_TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TEST_TARGET): $(BUILD_DIR) tests/test_linked_lists.cpp
	$(CXX) $(CXXFLAGS) tests/test_linked_lists.cpp -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
