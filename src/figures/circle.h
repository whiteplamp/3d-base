//
// Created by yanne on 09.01.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "raylib.h"


class Circle {
public:
    Circle(const int x, const int y, const float radius, const Color color): x(x), y(y), radius(radius), color(color) {};

    void draw_circle() const {
        DrawCircleLines(x, y, radius, color);
    }
private:
    int x, y;
    float radius;
    Color color;

};



#endif //CIRCLE_H
