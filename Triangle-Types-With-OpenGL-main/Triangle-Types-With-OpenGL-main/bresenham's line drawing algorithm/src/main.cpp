#include <vector>
#include <cmath>
#include <algorithm>

std::vector<float> Bresenham(float x0, float y0, float x1, float y1)
{
    std::vector<float> points;

    // Convert all coordinates to integers (since Bresenham works with integer pixels)
    int xi = static_cast<int>(std::round(x0));
    int yi = static_cast<int>(std::round(y0));
    int xf = static_cast<int>(std::round(x1));
    int yf = static_cast<int>(std::round(y1));

    int dx = std::abs(xf - xi);
    int dy = std::abs(yf - yi);

    int sx = (xi < xf) ? 1 : -1;
    int sy = (yi < yf) ? 1 : -1;

    int err = dx - dy; // error term

    while (true)
    {
        // Store the pixel coordinates (x, y, z)
        points.push_back(static_cast<float>(xi));
        points.push_back(static_cast<float>(yi));
        points.push_back(0.0f); // z coordinate

        if (xi == xf && yi == yf)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            xi += sx;
        }
        if (e2 < dx) {
            err += dx;
            yi += sy;
        }
    }

    return points;
}
