#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>
#include <string>

// Structure pour représenter un point
struct Point {
    double x;
    double y;
    
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

// Structure pour représenter un cercle
struct Circle {
    Point center;
    double radius;
    std::string fill;
    std::string stroke;
    double strokeWidth;
    
    Circle(Point center = Point(), double radius = 1.0, 
           std::string fill = "none", std::string stroke = "black", double strokeWidth = 1.0)
        : center(center), radius(radius), fill(fill), stroke(stroke), strokeWidth(strokeWidth) {}
};

// Structure pour représenter un rectangle
struct Rectangle {
    Point topLeft;
    double width;
    double height;
    std::string fill;
    std::string stroke;
    double strokeWidth;
    
    Rectangle(Point topLeft = Point(), double width = 1.0, double height = 1.0,
              std::string fill = "none", std::string stroke = "black", double strokeWidth = 1.0)
        : topLeft(topLeft), width(width), height(height), fill(fill), stroke(stroke), strokeWidth(strokeWidth) {}
};

// Structure pour représenter un polygone
struct Polygon {
    std::vector<Point> points;
    std::string fill;
    std::string stroke;
    double strokeWidth;
    
    Polygon(std::vector<Point> points = {},
            std::string fill = "none", std::string stroke = "black", double strokeWidth = 1.0)
        : points(points), fill(fill), stroke(stroke), strokeWidth(strokeWidth) {}
};

// Fonction pour créer un cercle
Circle createCircle(const Point& center, double radius, 
                   const std::string& fill = "none", const std::string& stroke = "black", double strokeWidth = 1.0);

// Fonction pour créer un rectangle
Rectangle createRectangle(const Point& topLeft, double width, double height,
                         const std::string& fill = "none", const std::string& stroke = "black", double strokeWidth = 1.0);

// Fonction pour créer un polygone
Polygon createPolygon(const std::vector<Point>& points,
                     const std::string& fill = "none", const std::string& stroke = "black", double strokeWidth = 1.0);

// Fonction pour créer un tableau "à la Véra Molnár" avec répétition d'objets
std::vector<Circle> createMolnarCircleGrid(const Circle& baseCircle, int rows, int cols, double spacingX, double spacingY);
std::vector<Rectangle> createMolnarRectangleGrid(const Rectangle& baseRect, int rows, int cols, double spacingX, double spacingY);
std::vector<Polygon> createMolnarPolygonGrid(const Polygon& basePoly, int rows, int cols, double spacingX, double spacingY);

#endif // OBJECT_HPP