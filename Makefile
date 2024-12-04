# CHAPITRE 1 : BUT FINAL

but : game

# CHAPITRE 2 : VARIABLES

OFILES = taille.o \
         menu.o \
	 nbjoueur.o \
	 comportementJCJ.o \
	 comportementJCIA.o \
	 definirMaxXY.o \
	 initialisation.o \
	 coordoner.o \
         main.o


CC = gcc

CFLAGS = -Wall -ansi -pedantic

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

menu.o : taille.h menu.h nbjoueur.h

taille.o : taille.h

coordoner.o : coordoner.h initialisation.h

initialisation.o : initialisation.h

nbjoueur.o : nbjoueur.h

comportementJCJ.o : comportementJCJ.h definirMaxXY.h initialisation.h coordoner.h

comportementJCIA.o : comportementJCIA.h definirMaxXY.h initialisation.h coordoner.h 

main.o : menu.h comportementJCJ.h comportementJCIA.h


# CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

game : $(OFILES)
	$(CC) $(CFLAGS) -o game $(OFILES) -lgraph

# CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) game

# CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean

run :
	./game

