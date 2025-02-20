#ifndef FILE_HPP
#define FILE_HPP

#include "object.hpp"
#include <string>

// Fonction pour écrire du contenu dans un fichier
bool write_to_file(const std::string& filename, const std::string& content);

// Fonction pour lire du contenu depuis un fichier
std::string read_from_file(const std::string& filename);

// Fonction pour écrire du contenu SVG dans un fichier
bool svg_to_file(const std::string& filename, const std::string& svgContent);

// Fonction pour écrire du contenu HTML dans un fichier
bool html_to_file(const std::string& filename, const std::string& htmlContent);

// Fonction pour lire un cercle depuis un fichier
Circle read_circle_from_file(const std::string& filename);

// Fonction pour lire un rectangle depuis un fichier
Rectangle read_rectangle_from_file(const std::string& filename);

// Fonction pour lire un polygone depuis un fichier
Polygon read_polygon_from_file(const std::string& filename);

#endif // FILE_HPP