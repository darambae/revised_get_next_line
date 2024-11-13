
# get_next_line

## Table des matières

  - [Introduction](#introduction)
  - [Fonctionnalités](#fonctionnalités)
  - [Fonctions standards pour la gestion des fichiers](#fonctions-standards-pour-la-gestion-des-fichiers)
  - [Bonus](#bonus)

## Introduction

**get_next_line** est un projet en C qui vise à fournir une fonction permettant de lire une ligne à partir d'un descripteur de fichier, y compris l'entrée standard. Cette implémentation permet de lire efficacement ligne par ligne à partir de fichiers, tout en gérant simultanément plusieurs descripteurs de fichier. Le projet met l'accent sur la gestion de la mémoire et l'allocation dynamique, garantissant que les ressources sont correctement gérées lors de la lecture de l'entrée. En travaillant sur **get_next_line**, vous approfondirez votre compréhension de la gestion des fichiers en C et améliorerez vos compétences dans la manipulation des tampons et des chaînes.

**For the English and Korean versions of this README, please follow the links:**
- [English Version](./README.md)
- [한국어 Version](./README_kr.md)

## Fonctionnalités

- Lit une ligne à partir d'un descripteur de fichier, y compris le caractère de nouvelle ligne.
- Gère plusieurs descripteurs de fichiers simultanément.
- Utilisation efficace de la mémoire avec allocation dynamique de tampon.

## Fonctions standards pour la gestion des fichiers

- `open()` : Ouvre un fichier et renvoie un descripteur de fichier.
  - Prototype : `int open(const char *pathname, int flags, mode_t mode);`
  - Exemple : `int fd = open("file.txt", O_RDONLY);`

- `read()` : Lit des données depuis un descripteur de fichier.
  - Prototype : `ssize_t read(int fd, void *buf, size_t count);`
  - Exemple : `ssize_t bytesRead = read(fd, buffer, 1024);`

- `close()` : Ferme un descripteur de fichier.
  - Prototype : `int close(int fd);`
  - Exemple : `close(fd);`

## Bonus

- Gère plusieurs descripteurs de fichiers en même temps.
- Renvoie la ligne lue, ou NULL s'il n'y a plus rien à lire ou si une erreur s'est produite.

---
