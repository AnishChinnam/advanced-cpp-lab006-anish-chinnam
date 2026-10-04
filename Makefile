CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -Iinclude -Itests
BUILD_DIR := build
TEST_TARGET := $(BUILD_DIR)/test_linked_lists
MAIN_TARGET := $(BUILD_DIR)/main
HEADERS := include/singly_linked_list.h include/doubly_linked_list.h

.PHONY: all test clean

all: $(MAIN_TARGET) $(TEST_TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(MAIN_TARGET): src/main.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) src/main.cpp -o $@

$(TEST_TARGET): tests/test_linked_lists.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) tests/test_linked_lists.cpp -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
