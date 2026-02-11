NAME = account

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp \
	  tests.cpp \
 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(NAME)
	@./$(NAME) >  $(NAME).log

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
