//
// Created by yanne on 09.01.2025.
//

#ifndef LINE_H
#define LINE_H
#include "raylib.h"

class Line {
public:
    Line(const Vector2 start, const Vector2 end, const float thick, const Color color): start(start), end(end), thick(thick), color(color) {};

    void draw_line() const {
        DrawLineEx(start, end, thick, color);
    }
private:
    Vector2 start, end;
    float thick;
    Color color;
};

#endif //LINE_H
