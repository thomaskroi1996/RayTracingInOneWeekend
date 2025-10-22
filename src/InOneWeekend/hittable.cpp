#include "hittable.hh"

void hit_record::set_face_normal(const ray &ray, const vec3 &outward_normal)
{
    // outward_normal has to be a unit vector

    front_face = dot(ray.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}