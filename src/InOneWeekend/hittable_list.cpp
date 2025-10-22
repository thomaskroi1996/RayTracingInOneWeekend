#include "hittable_list.hh"


void hittable_list::add(shared_ptr<hittable> object){
    objects.push_back(object);
}

bool hittable_list::hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;

    auto closest_so_far = ray_tmax;

    int index = 0;
    for (const auto& object : objects){
        if(object->hit(r, ray_tmin, closest_so_far, temp_rec)){
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
        index++;
    }

    return hit_anything;
}