#include "draw_svg.hpp"
#include <sstream>

// Implémentation de point_to_svg
std::string point_to_svg(const Point& p) {
    std::stringstream ss;
    ss << p.x << "," << p.y;
    return ss.str();
}

// Implémentation de circle_to_svg
std::string circle_to_svg(const Circle& circle) {
    std::stringstream ss;
    ss << "<circle cx=\"" << circle.center.x 
       << "\" cy=\"" << circle.center.y 
       << "\" r=\"" << circle.radius 
       << "\" fill=\"" << circle.fill 
       << "\" stroke=\"" << circle.stroke 
       << "\" stroke-width=\"" << circle.strokeWidth 
       << "\" />";
    return ss.str();
}

// Implémentation de rectangle_to_svg
std::string rectangle_to_svg(const Rectangle& rect) {
    std::stringstream ss;
    ss << "<rect x=\"" << rect.topLeft.x 
       << "\" y=\"" << rect.topLeft.y 
       << "\" width=\"" << rect.width 
       << "\" height=\"" << rect.height 
       << "\" fill=\"" << rect.fill 
       << "\" stroke=\"" << rect.stroke 
       << "\" stroke-width=\"" << rect.strokeWidth 
       << "\" />";
    return ss.str();
}

// Implémentation de polygon_to_svg
std::string polygon_to_svg(const Polygon& poly) {
    if (poly.points.empty()) {
        return ""; // Retourner une chaîne vide si le polygone n'a pas de points
    }
    
    std::stringstream ss;
    ss << "<polygon points=\"";
    
    for (size_t i = 0; i < poly.points.size(); ++i) {
        ss << point_to_svg(poly.points[i]);
        if (i < poly.points.size() - 1) {
            ss << " ";
        }
    }
    
    ss << "\" fill=\"" << poly.fill 
       << "\" stroke=\"" << poly.stroke 
       << "\" stroke-width=\"" << poly.strokeWidth 
       << "\" />";
    
    return ss.str();
}

// Implémentation de circles_to_svg
std::string circles_to_svg(const std::vector<Circle>& circles) {
    std::stringstream ss;
    for (const auto& circle : circles) {
        ss << circle_to_svg(circle) << "\n";
    }
    return ss.str();
}

// Implémentation de rectangles_to_svg
std::string rectangles_to_svg(const std::vector<Rectangle>& rects) {
    std::stringstream ss;
    for (const auto& rect : rects) {
        ss << rectangle_to_svg(rect) << "\n";
    }
    return ss.str();
}

// Implémentation de polygons_to_svg
std::string polygons_to_svg(const std::vector<Polygon>& polys) {
    std::stringstream ss;
    for (const auto& poly : polys) {
        ss << polygon_to_svg(poly) << "\n";
    }
    return ss.str();
}

// Implémentation de create_svg_document
std::string create_svg_document(const std::string& content, int width, int height) {
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
       << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "
       << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
       << "<svg width=\"" << width << "\" height=\"" << height 
       << "\" xmlns=\"http://www.w3.org/2000/svg\">\n"
       << content
       << "</svg>";
    return ss.str();
}

// Implémentation de create_html_document
std::string create_html_document(const std::string& svgContent, const std::string& title) {
    std::stringstream ss;
    ss << "<!DOCTYPE html>\n"
       << "<html>\n"
       << "<head>\n"
       << "    <title>" << title << "</title>\n"
       << "</head>\n"
       << "<body>\n"
       << svgContent << "\n"
       << "</body>\n"
       << "</html>";
    return ss.str();
}