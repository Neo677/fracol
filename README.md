Fractol

Fractol est un projet de l’école 42 qui permet de générer et d’explorer des fractales célèbres telles que Julia et Mandelbrot. 
Ce projet met en œuvre des calculs complexes en temps réel pour afficher ces figures mathématiques fascinantes.


Fonctionnalités


Affichage de plusieurs types de fractales (Julia, Mandelbrot, etc.).

Navigation et zoom sur les fractales avec le clavier et la souris.

Modification des paramètres dynamiquement pour explorer différentes formes et couleurs.

Compatible avec macOS et Linux.


Fichiers principaux du projet


fractol.h : Fichier d’en-tête principal contenant les structures et les prototypes.
ft_main.c : Point d’entrée du programme.
ft_init.c : Gestion des initialisations de la fenêtre et des fractales.
ft_render.c : Affichage des fractales et gestion des pixels.
ft_events.c : Gestion des événements clavier et souris.
ft_map.c : Calculs spécifiques aux coordonnées des fractales.
ft_math_utils.c : Fonctions mathématiques pour les calculs complexes.
ft_str_utils.c : Fonctions utilitaires pour la gestion des chaînes.
ft_touch_repeat.c : Gestion des interactions continues.

Utilisation


1. Compilation


Pour compiler le projet, utilisez la commande suivante :

		make
Cela génère l’exécutable fractol.

2. Lancement

Pour lancer le programme, utilisez la commande suivante :

		./fractol <nom_fractale> [paramètres]

Exemple :

		./fractol mandelbrot
  
		./fractol julia 0.285 0.01
  

3. Commandes

Voici les commandes utilisables dans le programme :

Clavier :
 
	Flèche A : Déplace la fractale à gauche.
	Flèche D : Déplace la fractale à droite.
	Flèche W : Déplace la fractale vers le haut.
	Flèche S : Déplace la fractale vers le bas.
	TAB / N : Augmente ou diminue le nombre d’itérations.

  
Souris :
	Scroll vers le haut : Zoom avant.
	Scroll vers le bas : Zoom arrière.

4. Options

Vous pouvez passer différents arguments pour explorer d’autres fractales :


	./fractol mandelbrot  
 
	./fractol julia 0.285 0.01  


Règles du projet
 Le projet respecte la norme de l’école 42.
 Pas de variables globales.
 Gestion propre de la mémoire et des erreurs (aucune fuite).

Règles du Makefile

	make : Compile le projet.
 
	make clean : Supprime les fichiers objets.
 
	make fclean : Supprime les fichiers objets et l’exécutable.
 
	make re : Réexécute un nettoyage complet suivi d’une recompilation.

Crédits

Projet réalisé dans le cadre du cursus de l’école 42.

Merci d’avoir pris le temps de lire ce README !

Amusez-vous bien à explorer les fractales et découvrez la beauté mathématique qu’elles cachent. 🌀

Si vous avez des questions ou des suggestions, n’hésitez pas à me contacter. Bonne exploration ! 😊
