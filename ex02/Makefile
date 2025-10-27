# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2025/10/07 11:52:27 by pgomes            #+#    #+#              #
#    Updated: 2025/10/26 22:12:03 by pgomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = PmergeMe.cpp main.cpp
HEADERS = PeergeMe.hpp
=======
#    Created: 2025/10/07 15:10:00 by pgomes            #+#    #+#              #
#    Updated: 2025/10/07 14:53:25 by pgomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pmerge
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PmergeMe.cpp
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

<<<<<<< HEAD
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
=======
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
