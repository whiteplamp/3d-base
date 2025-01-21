//
// Created by yanne on 17.01.2025.
//

#ifndef MENU_VIEWPORT_H
#define MENU_VIEWPORT_H

#include <string>

#include "base_viewport.h"
#include "../button.h"
#include "../figures/cube.h"

class  MenuViewport : public BaseViewport {
private:
    Button button;

public:
    MenuViewport(Vector2 position, Vector2 size, Camera camera, Color viewPortBackGroundColor, std::string type, Button button)
        : BaseViewport(position, size, camera, viewPortBackGroundColor, type), button(button) {}

    void draw() override {
        button.draw();
    }

};

#endif //MENU_VIEWPORT_H
