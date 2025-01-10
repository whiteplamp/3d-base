//
// Created by yanne on 10.01.2025.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "raylib.h"

class Square {
public:
    Square(Vector2 position, Vector2 size, Color color): position(position), size(size), color(color) {};

    void draw() {
        DrawRectangleV(position, size, color);
    }
private:
    Vector2 position, size;
    Color color;
};

#endif //SQUARE_H
