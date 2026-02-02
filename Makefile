CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -Imylib/include

TARGET := main
SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

LIB := mylib/mylib.a

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LIB) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
