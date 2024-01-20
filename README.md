# C - Sorting algorithms & Big O

## Contexte

Ce projet est conçu pour être réalisé par des groupes de deux étudiants. Chaque paire d'étudiants devrait faire de la programmation en binôme, en particulier pour la partie obligatoire.

## Ressources

Lisez ou regardez les ressources suivantes pour améliorer votre compréhension :

- Algorithme de tri
- Notation Big O
- Animations d'algorithmes de tri
- [15 algorithmes de tri en 6 minutes (AVERTISSEMENT : La vidéo suivante peut déclencher des crises d'épilepsie. Elle n'est pas nécessaire pour le projet, car il s'agit simplement d'une visualisation amusante de différents algorithmes de tri)](lien-de-la-video)

## Objectifs d'Apprentissage

À la fin de ce projet, vous devriez être en mesure d'expliquer les concepts suivants à n'importe qui, sans l'aide de Google :

### Général

- Implémentation d'au moins quatre algorithmes de tri différents.
- Compréhension de la notation Big O et capacité à évaluer la complexité temporelle d'un algorithme.
- Sélection du meilleur algorithme de tri pour une entrée donnée.
- Définition d'un algorithme de tri stable.

## Exigences

### Général

- Éditeurs autorisés : vi, vim, emacs
- Compilation de tous les fichiers sur Ubuntu 20.04 LTS en utilisant gcc, avec les options : `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Tous les fichiers doivent se terminer par une nouvelle ligne.
- Un fichier `README.md` à la racine du dossier du projet est obligatoire.
- Le code doit suivre le style Betty, et sera vérifié en utilisant `betty-style.pl` et `betty-doc.pl`.
- Interdiction des variables globales.
- Limite de cinq fonctions par fichier.
- Sauf indication contraire, l'utilisation de fonctions de bibliothèque standard (par exemple, printf, puts) est interdite.
- Des fichiers main.c sont fournis en exemple pour tester les fonctions, mais ils ne doivent pas être poussés dans votre référentiel (si vous le faites, nous ne les prendrons pas en compte). Nous utiliserons nos propres fichiers main.c lors de la compilation. Nos fichiers main.c peuvent être différents de ceux montrés dans les exemples.
- Les prototypes de toutes vos fonctions doivent être inclus dans votre fichier d'en-tête appelé `sort.h`.
- N'oubliez pas de pousser votre fichier d'en-tête.
- Tous vos fichiers d'en-tête doivent être protégés contre les inclusions multiples.
- Une liste/tableau n'a pas besoin d'être trié si sa taille est inférieure à 2.

### GitHub

- Il devrait y avoir un dépôt de projet par groupe. Si vous clonez/fourchez/quoi que ce soit d'autre un dépôt de projet avec le même nom avant la deuxième date limite, vous risquez un score de 0%.

## Informations Supplémentaires

### Structure de Données et Fonctions

Pour ce projet, vous avez accès aux fonctions suivantes :

#### `print_array`

```c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Affiche un tableau d'entiers
 *
 * @array: Le tableau à afficher
 * @size: Nombre d'éléments dans @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}



#### Fonction `print_list`

```c
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Affiche une liste d'entiers
 *
 * @list: La liste à afficher
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
Les fichiers print_array.c et print_list.c (contenant les fonctions print_array et print_list) seront compilés avec vos fonctions lors de la correction. Assurez-vous de déclarer les prototypes de ces fonctions dans votre fichier d'en-tête sort.h

Structure de Liste Doublement Chaînée

/**
 * struct listint_s - Nœud de liste doublement chaînée
 *
 * @n: Entier stocké dans le nœud
 * @prev: Pointeur vers l'élément précédent de la liste
 * @next: Pointeur vers l'élément suivant de la liste
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


Notation Big O
O(1)
O(n)
O(n!)
O(n^2) (n au carré)
O(log(n))
O(n log(n))
O(n + k)
...

Veuillez utiliser la notation "courte" (évitez d'utiliser des constantes). Par exemple, O(nk) ou O(wn) doit être écrit comme O(n). Si une réponse est requise dans un fichier, assurez-vous que tous vos fichiers de réponse ont une nouvelle ligne à la fin.

Tests

Pour tester les algorithmes de tri avec de grands ensembles d'entiers aléatoires, vous pouvez utiliser Random.org.
