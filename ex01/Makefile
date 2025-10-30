# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 11:52:27 by pgomes            #+#    #+#              #
#    Updated: 2025/10/30 11:40:01 by pgomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rpn
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = RPN.cpp main.cpp
HEADERS = RPN.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
