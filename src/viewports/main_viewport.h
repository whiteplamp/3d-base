//
// Created by yanne on 17.01.2025.
//

#ifndef MAIN_VIEWPORT_H
#define MAIN_VIEWPORT_H
#include "base_viewport.h"
#include "../figures/cube.h"

class MainViewport : public BaseViewport {
private:
    Cube *cube;

public:
    MainViewport(Vector2 position, Vector2 size, Camera camera, Color viewPortBackGroundColor, std::string type, Cube cube)
    : BaseViewport(position, size, camera, viewPortBackGroundColor, type) {
        this->cube = new Cube(cube.getPosition(), cube.getSize());
    }

    void update() override {
        Vector2 mouseDelta;
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            mouseDelta = GetMouseDelta();
            this->camera.position.x += mouseDelta.x;
        }
    }

    void draw() override {
        cube->draw();
        DrawGrid(16, 10);
    }

};

#endif //MAIN_VIEWPORT_H
