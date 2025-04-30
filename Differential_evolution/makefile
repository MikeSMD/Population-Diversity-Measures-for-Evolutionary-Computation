CXX = g++
CXXFLAGS = -fopenmp -std=c++17 -w

SRCPP := $(shell find . -name '*.cpp')
DIVERSITY_MRS := $(shell find ../Diversity_measures/DE -name '*.cpp')

ALL := $(SRCPP) $(DIVERSITY_MRS)

TARGET = DifferentialEvolution

all: $(TARGET)

$(TARGET): $(ALL)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

