##
## EPITECH PROJECT, 2021
## assembly
## File description:
## makefile
##

NAME	=	libasm.so

SRC	=	src/my_strlen.asm		\
		src/my_strcmp.asm		\
		src/my_strncmp.asm		\
		src/my_strcasecmp.asm	\
		src/my_strchr.asm		\
		src/my_strcspn.asm		\
		src/my_rindex.asm		\
		src/my_strstr.asm		\
		src/my_strpbrk.asm		\
		src/my_memset.asm		\
		src/my_memcpy.asm		\
		src/my_memmove.asm

TEST_SRC=	tests/test_memcpy.c		\
			tests/test_memset.c		\
			tests/test_rindex.c		\
			tests/test_strcasecmp.c	\
			tests/test_strchr.c		\
			tests/test_strcmp.c		\
			tests/test_strcspn.c	\
			tests/test_strlen.c		\
			tests/test_strncmp.c	\
			tests/test_strpbrk.c	\
			tests/test_strstr.c		\
			tests/test_memmove.c

OBJ	=	$(SRC:.asm=.o)

TEST_OBJ=	$(TEST_SRC:.c=.o)

ASFLAGS	=	-f elf64

CFLAGS	=	-Wall -Wextra -fPIC -g

CPPFLAGS=	-I./include/ -m64 -fno-builtin -no-pie

CRITERION=	-lcriterion --coverage

all	:	$(OBJ)
		ld -fPIC -shared -nostdlib -o $(NAME) $(OBJ)

tests_run:	re $(TEST_OBJ)
		gcc -o unit_tests $(CPPFLAGS) $(CRITERION) $(TEST_OBJ) -ldl
		./unit_tests
			
coverage:
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

%.o 	:	%.asm
		nasm $(ASFLAGS) -o $@ $<

clean	:
		rm -f $(OBJ)
		rm -f $(TEST_OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f unit_tests

re	:	fclean all

.PHONY	:	all clean fclean re
