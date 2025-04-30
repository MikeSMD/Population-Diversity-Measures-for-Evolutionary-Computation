CXX = g++
CXXFLAGS = -fopenmp -std=c++17 -w

SRCPP := $(shell find . -name '*.cpp')
DIVERSITY_MRS := $(shell find ../Diversity_measures/GA -name '*.cpp')

ALL := $(SRCPP) $(DIVERSITY_MRS)

TARGET = GeneticAlgorithm

all: $(TARGET)

$(TARGET): $(ALL)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

