# SVG Project

## Structure du projet

- `src/` : Contient tous les fichiers source (.cpp et .hpp).
- `data/` : Contient les fichiers texte décrivant les formes géométriques.
- `CMakeLists.txt` : Fichier de configuration pour CMake.

## Compilation

Pour compiler le projet, utilisez CMake :

```sh
mkdir build
cd build
cmake ..
make
```

## Exécution

Pour exécuter le programme principal :

```sh
./svg_project
```

## Fonctionnalités

Le programme permet de :
1. Créer différentes formes géométriques (cercles, rectangles, polygones)
2. Convertir ces formes en code SVG
3. Générer des documents HTML contenant les images SVG
4. Lire les paramètres des formes depuis des fichiers texte
5. Créer des grilles de formes géométriques "à la Véra Molnár"

## Format des fichiers de données

Les fichiers de données utilisent un format simple avec une ligne par forme :

### Cercle (Circle1.txt)
```
Circle 2.5 4.6 1.2 red black 2.0
```
Format : Nom cx cy rayon [fill stroke strokeWidth]

### Rectangle (Rectangle1.txt)
```
Rectangle 1.0 2.0 5.0 3.0 blue black 1.5
```
Format : Nom x y largeur hauteur [fill stroke strokeWidth]

### Polygone (Polygon1.txt)
```
Polygon 4 0.0 0.0 1.0 0.0 1.0 1.0 0.0 1.0 green black 1.0
```
Format : Nom nombre_points x1 y1 x2 y2 ... [fill stroke strokeWidth]