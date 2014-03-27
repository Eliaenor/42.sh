TODO

	- suush
		- exec

	- martin
		- config

changelog

	23/02/3014
		- chrysa/suush
			+ parser OK

	21/03/2014
    	- Vin's
        	+ Termcaps operatinnels a 100% normalement, me concater en cas de bug.
        	+ Signaux activés pour le moment afin de pouvoir ctrl+c en cas de besoin.

	15/03/2014
		- suush
			+ amelioration du lexer

	14/03/2014
		- chrysa
			= fin du debug du lexer
		- Vin's
			+ Implementation des Termcaps, mise en attente de la gestion de l'historique. Encore un bug si la commande fait plus de deux ligne de long.
			+ Correction de ft_prompt
			+ Legere mise a la norme

	12/03/2014
		- chrysa
			= lexer OK

	05/03/2014
		- chrysa => changements mineurs et réorganisation du code
			+ ajout de commentaires sur toute la partie lexer/parser
			+ ajout de fonction dans la libft
				* ft_putcolorendl => renvoi un chaine de caractère en couleur avec un retour a la ligne
				* ft_printincolor => affiche une ligne avec de la couleur a l'écran
				* ft_printincolorendl => affiche une ligne avec de la couleur a l'écran avec un retour a la ligne
			= modification de structure du code
			= modification dans la fonction ft_b_exit du fichier srcs/exit/ft_exit.c pour rendre le code plus "lisible" et gagner des lignes
			= modification dans la fonction ft_prompt du fichier srcs/init/prompt.c pour rendre le code plus "lisible" et gagner des lignes
			- suppresion de la gestion des inihbiteurs dans le dossier lexer_parser car mal foutu
