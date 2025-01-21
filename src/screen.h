//
// Created by yanne on 17.01.2025.
//

#ifndef SCREEN_H
#define SCREEN_H
#include <vector>
#include <typeinfo>

#include "viewports/base_viewport.h"


class Screen {
private:
    std::vector<std::unique_ptr<BaseViewport>> viewports;
public:
    Screen(std::vector<std::unique_ptr<BaseViewport>> &viewports) {
        this->viewports = std::move(viewports);
    };

    void draw() {
        for (auto &viewport : viewports) {
            viewport->render();
        }
        BeginDrawing();
            ClearBackground(BLACK);

            for (auto &viewport : viewports) {
                viewport->drawTexture();
            }

            DrawFPS(10, 10);
        EndDrawing();
    }
};

#endif //SCREEN_H
