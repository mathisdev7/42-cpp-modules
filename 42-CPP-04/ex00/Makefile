CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = animal
SRCS = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
