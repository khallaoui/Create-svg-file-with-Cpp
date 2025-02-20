#include "draw_svg.hpp"
#include "file.hpp"
#include "object.hpp"
#include <iostream>
#include <vector>

int main() {


    // Test de lecture d'un cercle depuis un fichier
    try {
        Circle circleFromFile = read_circle_from_file("../data/Circle1.txt");
        std::string circleSvgFromFile = circle_to_svg(circleFromFile);
        std::string svgDocFromFile = create_svg_document(circleSvgFromFile, 1000, 1000); // Increased size
        std::string htmlDocFromFile = create_html_document(svgDocFromFile, "Cercle depuis fichier");
        html_to_file("circle_from_file.html", htmlDocFromFile);
        std::cout << "Fichier circle_from_file.html créé." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la lecture du cercle depuis fichier: " << e.what() << std::endl;
    }

    // Test de lecture d'un rectangle depuis un fichier
    try {
        Rectangle rectFromFile = read_rectangle_from_file("../data/Rectangle1.txt");
        std::string rectSvgFromFile = rectangle_to_svg(rectFromFile);
        std::string svgDocFromFile = create_svg_document(rectSvgFromFile, 1000, 1000); // Increased size
        std::string htmlDocFromFile = create_html_document(svgDocFromFile, "Rectangle depuis fichier");
        html_to_file("rectangle_from_file.html", htmlDocFromFile);
        std::cout << "Fichier rectangle_from_file.html créé." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la lecture du rectangle depuis fichier: " << e.what() << std::endl;
    }

    // Test de lecture d'un polygone depuis un fichier
    try {
        Polygon polyFromFile = read_polygon_from_file("../data/Polygon1.txt");
        std::string polySvgFromFile = polygon_to_svg(polyFromFile);
        std::string svgDocFromFile = create_svg_document(polySvgFromFile, 1000, 1000); // Increased size
        std::string htmlDocFromFile = create_html_document(svgDocFromFile, "Polygone depuis fichier");
        html_to_file("polygon_from_file.html", htmlDocFromFile);
        std::cout << "Fichier polygon_from_file.html créé." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la lecture du polygone depuis fichier: " << e.what() << std::endl;
    }

    return 0;
}