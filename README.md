# Glybook
Projet étudiant réalisé en C++. Application de gestion de bibliothèque (catalogue de livres, gestion des stocks, des prêts, des utilisateurs)

Il s’agit d’un projet visant à créer un gestionnaire de bibliothèque, il aura pour fonction d’aider à gérer de multiples bibliothèques sous plusieurs aspects (notamment la gestion des prêts et des adhérents ainsi que la mise à jour du catalogue). 
Ce gestionnaire aide à la fois les employés de bibliothèque à gérer leur stock et leurs adhérents mais aussi les emprunteurs qui peuvent voir la liste des livres libres à l’emprunt et réserver des livres pour les emprunter.
Voici un premier aperçu des différentes fonctionnalités que possèdera à terme le programme :
[GLOBAL]
 	Connexion par nom d’utilisateur/mot de passe
 	Gestion des paramètres du compte (modifications des informations propres à l’utilisateur)

[ADMINISTRATEUR]
 	Ajouter une nouvelle bibliothèque (adresse, type (municipale, médiathèque, universitaire), nom)
 	Ajouter des catégories de livres (science-fiction, fantaisie, jeunesse, biographique)
 	Ajouter des livres dans cette bibliothèque (nom, auteur, éditeur, ISBN)
 	Gérer les adhérents (nom, prénom, adresse, numéro de téléphone, code)
 	Exportation de statistiques en tous genre (livres les plus empruntés, classement des emprunteurs, historiques…)

[ADHERENT]
 	Voir le catalogue
 	Emprunter des livres (s’il n’a pas de retard ou pas déjà trop emprunté)
 	Voir les livres qu’il a emprunté, savoir quand il doit les rendre
 	Historique des livres qu’il a emprunté.
