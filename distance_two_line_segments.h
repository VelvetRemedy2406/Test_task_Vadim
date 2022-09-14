//
// Created by daniil on 13.09.22.
//
#include "math.h"

#ifndef TEST_TASK_VADIM_DISTANCE_TWO_LINE_SEGMENTS_H
#define TEST_TASK_VADIM_DISTANCE_TWO_LINE_SEGMENTS_H
struct point {
    double x, y, z;
};

struct line {
    double x1, y1, z1, x2, y2, z2;
};

double dot(point p1, point p2) {
    return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

double norm(point c1) {
    return sqrt(dot(c1, c1));
}

double get_shortest_distance(line line1, line line2) {
    double EPS = 0.00000001;

    point d21{line1.x2 - line1.x1, line1.y2 - line1.y1, line1.z2 - line1.z1};
    point d41{line2.x2 - line2.x1, line2.y2 - line2.y1, line2.z2 - line2.z1};
    point d13{line1.x1 - line2.x1, line1.y1 - line2.y1, line1.z1 - line2.z1};

    double a = dot(d21, d21);
    double b = dot(d21, d41);
    double c = dot(d41, d41);
    double d = dot(d21, d13);
    double e = dot(d41, d13);
    double D = a * c - b * b;

    double sc, sN, sD = D;
    double tc, tN, tD = D;

    if (D < EPS) {
        sN = 0.0;
        sD = 1.0;
        tN = e;
        tD = c;
    } else {
        sN = (b * e - c * d);
        tN = (a * e - b * d);
        if (sN < 0.0) {
            sN = 0.0;
            tN = e;
            tD = c;
        } else if (sN > sD) {
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }

    if (tN < 0.0) {
        tN = 0.0;

        if (-d < 0.0)
            sN = 0.0;
        else if (-d > a)
            sN = sD;
        else {
            sN = -d;
            sD = a;
        }
    } else if (tN > tD) {
        tN = tD;
        if ((-d + b) < 0.0)
            sN = 0;
        else if ((-d + b) > a)
            sN = sD;
        else {
            sN = (-d + b);
            sD = a;
        }
    }

    if (abs(sN) < EPS) sc = 0.0;
    else sc = sN / sD;
    if (abs(tN) < EPS) tc = 0.0;
    else tc = tN / tD;

    point dP{d13.x + (sc * d21.x) - (tc * d41.x), d13.y + (sc * d21.y) - (tc * d41.y),
             d13.z + (sc * d21.z) - (tc * d41.z)};

    return sqrt(dot(dP, dP));
}

#endif //TEST_TASK_VADIM_DISTANCE_TWO_LINE_SEGMENTS_H
