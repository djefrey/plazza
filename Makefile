##
## EPITECH PROJECT, 2022
## B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
## File description:
## Makefile
##

SRC			=	src/com/NamedPipes.cpp				\
				src/com/Pipes.cpp					\
				src/cond/CCondVar.cpp				\
				src/kitchen/pizzas/APizza.cpp		\
				src/kitchen/pizzas/Serializer.cpp	\
				src/kitchen/Kitchen.cpp				\
				src/mutex/CMutex.cpp				\
				src/process/CProcess.cpp			\
				src/thread/CThread.cpp				\
				src/thread/Jobs.cpp					\
				src/thread/ThreadPool.cpp			\
				src/ArgHandler.cpp					\
				src/Logistic.cpp					\
				src/main.cpp						\
				src/Order.cpp						\
				src/Reception.cpp					\

NAME		=	plazza

CPPFLAGS	+=	-std=c++17

OBJ			=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) -lpthread

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:				fclean all

.PHONY:			clean fclean all re
