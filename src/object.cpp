#include "object.hpp"

// Implémentation de createCircle
Circle createCircle(const Point& center, double radius,
                   const std::string& fill, const std::string& stroke, double strokeWidth) {
    return Circle(center, radius, fill, stroke, strokeWidth);
}

// Implémentation de createRectangle
Rectangle createRectangle(const Point& topLeft, double width, double height,
                         const std::string& fill, const std::string& stroke, double strokeWidth) {
    return Rectangle(topLeft, width, height, fill, stroke, strokeWidth);
}

// Implémentation de createPolygon
Polygon createPolygon(const std::vector<Point>& points,
                     const std::string& fill, const std::string& stroke, double strokeWidth) {
    return Polygon(points, fill, stroke, strokeWidth);
}

// Implémentation de createMolnarCircleGrid
std::vector<Circle> createMolnarCircleGrid(const Circle& baseCircle, int rows, int cols, double spacingX, double spacingY) {
    std::vector<Circle> gridCircles;
    
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Circle newCircle = baseCircle;
            newCircle.center.x = baseCircle.center.x + col * spacingX;
            newCircle.center.y = baseCircle.center.y + row * spacingY;
            gridCircles.push_back(newCircle);
        }
    }
    
    return gridCircles;
}

// Implémentation de createMolnarRectangleGrid
std::vector<Rectangle> createMolnarRectangleGrid(const Rectangle& baseRect, int rows, int cols, double spacingX, double spacingY) {
    std::vector<Rectangle> gridRectangles;
    
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Rectangle newRect = baseRect;
            newRect.topLeft.x = baseRect.topLeft.x + col * spacingX;
            newRect.topLeft.y = baseRect.topLeft.y + row * spacingY;
            gridRectangles.push_back(newRect);
        }
    }
    
    return gridRectangles;
}

// Implémentation de createMolnarPolygonGrid
std::vector<Polygon> createMolnarPolygonGrid(const Polygon& basePoly, int rows, int cols, double spacingX, double spacingY) {
    std::vector<Polygon> gridPolygons;
    
    if (basePoly.points.empty()) {
        return gridPolygons;
    }
    
    // Trouver le point de référence (coin supérieur gauche du polygone)
    Point referencePoint = basePoly.points[0];
    for (const auto& point : basePoly.points) {
        if (point.x < referencePoint.x) referencePoint.x = point.x;
        if (point.y < referencePoint.y) referencePoint.y = point.y;
    }
    
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Polygon newPoly = basePoly;
            double offsetX = col * spacingX;
            double offsetY = row * spacingY;
            
            // Déplacer chaque point du polygone
            for (size_t i = 0; i < newPoly.points.size(); ++i) {
                newPoly.points[i].x = basePoly.points[i].x - referencePoint.x + offsetX;
                newPoly.points[i].y = basePoly.points[i].y - referencePoint.y + offsetY;
            }
            
            gridPolygons.push_back(newPoly);
        }
    }
    
    return gridPolygons;
}