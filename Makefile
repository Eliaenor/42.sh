# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agreau <agreau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 21:25:57 by agreau            #+#    #+#              #
#    Updated: 2014/03/27 01:38:04 by vcourtin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
##########CONFIG##########
NAME = 42sh

TERMCAP = yes

ADDITIONAL_FILES =

SRC_FOLDER = srcs

H_FOLDER = includes

LIB_FOLDER = libft

LIB_NAME = libft.a

COMPIL = gcc

FLAGS = -Wall -Werror -Wextra
##########GENERATION CONTENT##########
SRC := $(shell find $(SRC_FOLDER) -depth -type f)

SRO = $(SRC:.c=.o)

SRH = -I $(H_FOLDER)

FULL_LIB_PATH = $(addprefix $(LIB_FOLDER)/, $(LIB_NAME))

ifeq ($(TERMCAP), yes)
	COMPIL_LINE = $(COMPIL) $(FLAGS) $(SRC) $(ADD_F) $(SRH) $(FULL_LIB_PATH) \
				  -o $(NAME) -ltermcap
else
	COMPIL_LINE = $(COMPIL) $(FLAGS) $(SRC) $(ADD_F) $(SRH) $(FULL_LIB_PATH) \
				  -o $(NAME)
endif

ifdef LIB_FOLDER
	M_LIB = make -C $(LIB_FOLDER)
	RE_LIB = make re -C $(LIB_FOLDER)
	C_LIB = make clean -C $(LIB_FOLDER)
	FCLEN_LIB = make fclean -C $(LIB_FOLDER)
endif

ifdef ADDITIONAL_FILES
	DEL = rm -rf $(ADDITIONAL_FILES)
endif
##########RULES##########
.DEFAULT:
	@echo je ne sais pas faire $< tapes make help pour connaitre les commandes valides

.DONE:
	@echo on detruit les .o
	@clean && clib

.PHONY:	all clean fclean re reset launch relaunch gdb clear reclear clang fclall fcallre fcallrelaunch makelib relib clib fclib

all: $(NAME)

$(NAME):
	@echo "\033[2;34m===================\033[00m"
	@echo "[Compilation start]"
	@make fclib
	@make makelib
	@$(COMPIL_LINE)
	@echo "\033[1;32m[Compilation successful]\033[00m"
	@echo "\033[2;34m===================\033[00m"
	@echo "\033[1;32m[Linking C executable $(NAME) $(COMPIL)]\033[00m"

clean:
	@echo "\033[2;34m===================\033[00m"
	@echo "[Clean start]"
	@rm -f $(SRO)
	@echo "\033[1;32m[Clean completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"

fclean: clean
	@echo "\033[2;34m===================\033[00m"
	@echo "[Full clean start]"
	@rm -f $(NAME)
	@$(DEL)
	@echo "\033[1;32m[Full clean completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"

re: fclean all

reset: fclean fclib
	@echo "\033[2;34m===================\033[00m"
	@echo "[Reset application start]"
	@reset
	@make re
	@$(DEL)
	@echo "\033[1;32m[Reset application completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"

reslaunch: fclean
	@echo "\033[2;34m===================\033[00m"
	@echo "[Reset application start]"
	@reset
	@make re
	@$(DEL)
	@echo "\033[1;32m[Reset application completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"
	@make launch

launch:
	@./$(NAME)

relaunch: re launch

gdb: re
	@gdb ./$(NAME)

clear:
	@clear

makelib:
	@$(M_LIB)

relib:
	@$(RE_LIB)

clib:
	@$(C_LIB)

fclib:
	@$(FCLEN_LIB)

reclear: clear re launch

fclall: fclean fclib

fcallre: fcall re

fcallrelaunch: fcall re launch

fcallregdb: fcall re gdb

clang: COMPIL = cc
clang: all

install:
	@echo "\033[2;34m===================\033[00m"
	@echo "[Install start]"
	@mkdir srcs	includes libft libft/srcs libft/includes
	@mv Makefile_libft libft/Makefile
	@echo "\033[1;32m[Install completed]\033[00m"
	@echo "\033[2;34m===================\033[00m"

help:
	@echo "clean 			=>	Cleaning all object of application except libft"
	@echo "fclean 			=>	Cleaning all object and executable of application except libft
	@echo "clean 	 		=> supprime les fichiers compilés"
	@echo "fclean	 		=> supprime les fichiers compilés et l'executable"
	@echo "re	 	 		=> supprime les fichiers compilés et l'exécutable et les regénères"
	@echo "reset	 		=> reset le terminal effectue un make re et supprime les fichiers les fichiers générés par l'executable"
	@echo "reslaunch 		=> reset l'application et la lance"
	@echo "launch	 		=> lance l'application"
	@echo "relaunch	 		=> effectue un make re et un make launch"
	@echo "gdb	 	 		=> recompile le prograble et le lance dans GDB"
	@echo "makelib	 		=> make des libs"
	@echo "relib	 		=> make re des libs"
	@echo "clib 	 		=> make clean des libs"
	@echo "fclib 	 		=> make fclean des libs"
	@echo "clear	 		=> vide le termial"
	@echo "reclear	 		=> vide le terminal recompile le programme et lance l'executable"
	@echo "clang	 		=> compile le programme avec clang"
	@echo "fclall			=> fclean de la lib et de l'app"
	@echo "fcallre 			=> fclall et make re global"
	@echo "fcallrelaunch 	=> fcallre et lancement de l'application"
	@echo "fcallregdb 		=> fcallre et lancement de l'application dans gdb"
	@echo "debug 			=> rajoute des flags spécifiquement pour le débuguage"
	@echo "install	 		=> configure l'architecture du projet"
