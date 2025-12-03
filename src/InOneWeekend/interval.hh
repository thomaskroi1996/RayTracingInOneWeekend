#ifndef INTERVAL_H
#define INTERVAL_H

#include "rtweekend.hh"


class interval{
    public:
        double min, max;

        interval(double a, double b) : min(a), max(b) {}

        double size() const {
            return max - min;
        }

        bool contains(double x) const {
            return min <= x && x <= max;
        }

        bool surrounds(double x) const {
            return min < x && x < max;
        }

        static const interval empty, universe;

};

inline const interval interval::empty = interval(+infinity, -infinity);
inline const interval interval::universe = interval(-infinity, +infinity);


#endif