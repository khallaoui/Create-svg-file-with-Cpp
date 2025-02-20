#include "file.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Implémentation de write_to_file
bool write_to_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << " pour écriture." << std::endl;
        return false;
    }
    
    file << content;
    file.close();
    return true;
}

// Implémentation de read_from_file
std::string read_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << " pour lecture." << std::endl;
        return "";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

// Implémentation de svg_to_file
bool svg_to_file(const std::string& filename, const std::string& svgContent) {
    return write_to_file(filename, svgContent);
}

// Implémentation de html_to_file
bool html_to_file(const std::string& filename, const std::string& htmlContent) {
    return write_to_file(filename, htmlContent);
}

// Implémentation de read_circle_from_file
Circle read_circle_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << " pour lecture." << std::endl;
        return Circle();
    }
    
    std::string line;
    std::getline(file, line);
    file.close();
    
    std::istringstream iss(line);
    std::string shapeType;
    double cx, cy, radius;
    std::string fill = "none", stroke = "black";
    double strokeWidth = 1.0;
    
    iss >> shapeType >> cx >> cy >> radius;
    
    // Si nous avons d'autres paramètres, les lire
    if (!iss.eof()) {
        iss >> fill;
    }
    if (!iss.eof()) {
        iss >> stroke;
    }
    if (!iss.eof()) {
        iss >> strokeWidth;
    }
    
    if (shapeType != "Circle") {
        std::cerr << "Erreur: Le type de forme dans le fichier n'est pas 'Circle'." << std::endl;
        return Circle();
    }
    
    return Circle(Point(cx, cy), radius, fill, stroke, strokeWidth);
}

// Implémentation de read_rectangle_from_file
Rectangle read_rectangle_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << " pour lecture." << std::endl;
        return Rectangle();
    }
    
    std::string line;
    std::getline(file, line);
    file.close();
    
    std::istringstream iss(line);
    std::string shapeType;
    double x, y, width, height;
    std::string fill = "none", stroke = "black";
    double strokeWidth = 1.0;
    
    iss >> shapeType >> x >> y >> width >> height;
    
    // Si nous avons d'autres paramètres, les lire
    if (!iss.eof()) {
        iss >> fill;
    }
    if (!iss.eof()) {
        iss >> stroke;
    }
    if (!iss.eof()) {
        iss >> strokeWidth;
    }
    
    if (shapeType != "Rectangle") {
        std::cerr << "Erreur: Le type de forme dans le fichier n'est pas 'Rectangle'." << std::endl;
        return Rectangle();
    }
    
    return Rectangle(Point(x, y), width, height, fill, stroke, strokeWidth);
}

// Implémentation de read_polygon_from_file
Polygon read_polygon_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << " pour lecture." << std::endl;
        return Polygon();
    }
    
    std::string line;
    std::getline(file, line);
    file.close();
    
    std::istringstream iss(line);
    std::string shapeType;
    int numPoints;
    std::string fill = "none", stroke = "black";
    double strokeWidth = 1.0;
    
    iss >> shapeType >> numPoints;
    
    if (shapeType != "Polygon") {
        std::cerr << "Erreur: Le type de forme dans le fichier n'est pas 'Polygon'." << std::endl;
        return Polygon();
    }
    
    std::vector<Point> points;
    for (int i = 0; i < numPoints; ++i) {
        double x, y;
        iss >> x >> y;
        points.push_back(Point(x, y));
    }
    
    // Si nous avons d'autres paramètres, les lire
    if (!iss.eof()) {
        iss >> fill;
    }
    if (!iss.eof()) {
        iss >> stroke;
    }
    if (!iss.eof()) {
        iss >> strokeWidth;
    }
    
    return Polygon(points, fill, stroke, strokeWidth);
}