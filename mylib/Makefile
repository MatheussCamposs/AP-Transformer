CXX := g++
CXXFLAGS := -Wall -Wextra -O2 -Iinclude

SRCS := src/matrix/matrix.cpp src/random/random.cpp src/ReLU/ReLU.cpp
OBJS := $(SRCS:.cpp=.o)

LIB := mylib.a

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
