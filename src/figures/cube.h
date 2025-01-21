//
// Created by yanne on 15.01.2025.
//

#ifndef CUBE_H
#define CUBE_H
#include "raylib.h"

class Cube {
private:
    Vector3 position;
    float size;
public:
    Cube(Vector3 position, float size): position(position), size(size) {};

    void update() {

    }

    void draw() {
        DrawCubeWiresV(position, (Vector3){size, size, size}, BLACK);
    }

    Vector3 getPosition() const {
        return position;
    }

    float getSize() const {
        return size;
    }
};



#endif //CUBE_H
