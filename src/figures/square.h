//
// Created by yanne on 10.01.2025.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "raylib.h"

class Square {
public:
    Square(Vector2 center, Vector2 size, Vector2 direction, Color color): center(center), size(size), direction(direction), color(color), position((Vector2) {center.x - size.x / 2, center.y - size.y / 2}) {};

    void update() {
        updateCenter();
        position = (Vector2) {center.x - size.x / 2, center.y - size.y / 2};
    }

    void draw() {
        DrawRectangleV(position, size, color);
    }

    void updateCenter() {
        center.x += direction.x;
        center.y += direction.y;
    }

    Vector2 getPosition() {
        return position;
    }

    Vector2 getCenter() {
        return center;
    }

    Vector2 getSize() {
        return size;
    }

    Rectangle getRectangle() {
        return (Rectangle){position.x, position.y, size.x, size.y};
    }

    Vector2 getDirection() {
        return direction;
    }

    void updateDirection(Vector2 newDir) {
        direction.x = newDir.x;
        direction.y = newDir.y;
    }
private:
    Vector2 center, position, size, direction;
    Color color;
};

#endif //SQUARE_H
