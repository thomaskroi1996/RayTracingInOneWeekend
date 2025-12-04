#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.hh"

class Camera
{

public:
    void render(const hittable &world);

    double aspect_ratio = 1.0;
    u_int32_t image_width = 100;
    u_int32_t samples_per_pixel = 10;

private:
    color ray_color(const ray &r, const hittable &world);
    void initialize();
    ray get_ray(int i, int j) const;
    vec3 sample_square() const;

    u_int32_t image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
    double pixel_samples_scale;
};

#endif