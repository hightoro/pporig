CXX		= g++
CXXFLAGS	= -Wall -Wextra -O2 -std=c++11
LDFLAGS		=

TARGET		= test.exe

SRCS		= test.cpp
OBJS    	= $(SRCS:%.cpp=%.o)

.PHONY: all clean
.SUFFIXES:.cpp .hpp .o

#[作りたいもの]: [材料]
#(-----TAB-----) [作り方]

all:		$(TARGET)

$(TARGET):	$(OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $^
.cpp.o:
		$(CXX) $(CXXFLAGS) -c $<
clean:
		$(RM) *.o *~ $(TARGET)

test.o:		dict.hpp coord.hpp tags.hpp file.hpp

