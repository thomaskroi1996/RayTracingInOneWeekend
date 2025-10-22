#include <cmath>
#include "sphere.hh"

bool sphere::hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const
{
    auto oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = h * h - a * c;

    if (discriminant < 0)
        return false;

    auto sqrt_discriminant = std::sqrt(discriminant);

    // find nearest root in the acceptable range of ray_tmin to ray_tmax
    auto root = (h - sqrt_discriminant) / a;
    if (root <= ray_tmin || ray_tmax <= root)
    {
        root = (h + sqrt_discriminant) / a;
        if (root <= ray_tmin || ray_tmax <= root)
        {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
}