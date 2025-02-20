#ifndef DRAW_SVG_HPP
#define DRAW_SVG_HPP

#include "object.hpp"
#include <string>
#include <vector>

// Fonction pour convertir un point en code SVG
std::string point_to_svg(const Point& p);

// Fonction pour convertir un cercle en code SVG
std::string circle_to_svg(const Circle& circle);

// Fonction pour convertir un rectangle en code SVG
std::string rectangle_to_svg(const Rectangle& rect);

// Fonction pour convertir un polygone en code SVG
std::string polygon_to_svg(const Polygon& poly);

// Fonction pour convertir une liste de cercles en code SVG
std::string circles_to_svg(const std::vector<Circle>& circles);

// Fonction pour convertir une liste de rectangles en code SVG
std::string rectangles_to_svg(const std::vector<Rectangle>& rects);

// Fonction pour convertir une liste de polygones en code SVG
std::string polygons_to_svg(const std::vector<Polygon>& polys);

// Fonction pour créer un document SVG complet
std::string create_svg_document(const std::string& content, int width = 800, int height = 600);

// Fonction pour créer un document HTML contenant le SVG
std::string create_html_document(const std::string& svgContent, const std::string& title = "SVG Image");

#endif // DRAW_SVG_HPP