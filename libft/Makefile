# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: agreau <agreau@student.42.fr>              +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/11/21 15:04:15 by agreau            #+#    #+#              #
#    Updated: 2014/03/03 03:44:43 by agreau           ###   ########.fr        #
#    Updated: 2014/03/02 20:42:55 by agreau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
##########CONFIG##########
NAME = libft.a

TERMCAP = no

ADDITIONAL_FILES =

SRC_FOLDER = srcs

H_FOLDER = includes

O_FOLDER = object

COMPIL = gcc

FLAGS = -Wall -Werror -Wextra
##########GENERATION CONTENT##########
SRC := $(shell find $(SRC_FOLDER) -depth -type f)

SRO = $(notdir $(SRC:.c=.o))

SRH = -I H_FOLDER

ifeq ($(TERMCAP), yes)
	COMPIL_LINE = gcc $(FLAGS) -c $(SRC) $(SRH) -ltermcap \
				  && ar rc $(NAME) $(SRO) && ranlib $(NAME)
else
	COMPIL_LINE = gcc $(FLAGS) -c $(SRC) $(SRH) \
				  && ar rc $(NAME) $(SRO) && ranlib $(NAME)
endif

ifdef ADDITIONAL_FILES
	DEL = rm -rf $(ADDITIONAL_FILES)
endif
##########RULES##########
all: $(NAME)

$(NAME):
	@echo "[Recompilation libft start]"
	@$(COMPIL_LINE) && make move_o
	@echo "\033[1;32m[Recompilation libft successful]\033[00m"
	@echo "\033[2;34m===================\033[00m"

clean:
	@echo "[Clean start]"
	@rm -rf $(O_FOLDER)
	@echo "\033[1;32m[Clean completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"

fclean: clean
	@echo "[Full clean start]"
	@rm -f $(NAME)
	@$(DEL)
	@echo "\033[1;32m[Full clean completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"

re: fclean all

clear:
	@clear
	
reclear: clear re launch

move_o:
	@mkdir -p $(O_FOLDER)
	@mv $(SRO) $(O_FOLDER)

clang: COMPIL = cc
clang: all

help:
	@echo "clean 	 =>	supprime les fichiers compilés"
	@echo "fclean	 =>	supprime les fichiers compilés et l'executable"
	@echo "re		 =>	supprime les fichiers compilés et l'exécutable et les regénères"
	@echo "clear	 => vide le termial"
	@echo "reclear	 => vide le terminal recompile le programme et lance l'executable"
	@echo "clang	 => compile le programme avec clang"

.DEFAULT:
	@echo je ne sais pas faire $< tapes make help pour connaitre les commandes valides

.DONE:
	@echo on detruit les .o
	@clean

.PHONY:	all clean fclean re reset launch relaunch gdb clear reclear move_o clang reclang
