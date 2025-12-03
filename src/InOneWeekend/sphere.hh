#ifndef SPHERE_H
#define SPHERE_H

#include "rtweekend.hh"
#include "hittable.hh"

class sphere : public hittable
{
public:
    sphere(const point3 &center, double radius) : center(center), radius(std::fmax(0, radius)) {}

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override;

private:
    point3 center;
    double radius;
};

#endif
