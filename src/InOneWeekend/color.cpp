#include "rtweekend.hh"

void write_color(std::ostream &out, const color &pixel_color)
{

    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    static const interval intensity(0.00000, 0.99999);

    int rbyte = int(256 * intensity.clamp(r));
    int bbyte = int(256 * intensity.clamp(g));
    int gbyte = int(256 * intensity.clamp(b));

    // std::clog << r << " " << " " << g << " " << b << std::endl;

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
