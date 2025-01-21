//
// Created by yanne on 17.01.2025.
//

#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "raylib.h"

class BaseViewport {
protected:
    Vector2 position{}, size{};
    Camera camera{};
    RenderTexture texture{};
    Color viewPortBackGroundColor{};
    Rectangle screenRect{};
    std::string type;

public:
    BaseViewport(Vector2 position, Vector2 size, Camera camera, Color viewPortBackGroundColor, std::string type) {
        this->position = position;
        this->size = size;
        this->camera = camera;
        this->texture = LoadRenderTexture((int)size.x, (int)size.y);
        this->viewPortBackGroundColor = viewPortBackGroundColor;
        this->screenRect = (Rectangle){position.x, position.y, (float) texture.texture.width, (float) -texture.texture.height};
        this->type = type;
    };

    virtual ~BaseViewport() {
        UnloadRenderTexture(this->texture);
    }

    virtual void update() {

    }

    virtual void draw() {

    }

    void render() {
        if (type == "2D") {
            BeginTextureMode(this->texture);

                ClearBackground(RAYWHITE);

                update();
                draw();

            EndTextureMode();

        }
        else if (type == "3D") {
            BeginTextureMode(this->texture);

                ClearBackground(RAYWHITE);
                BeginMode3D(this->camera);

                    update();
                    draw();

                EndMode3D();

            EndTextureMode();
        }

    }

    void drawTexture() {
        DrawTextureRec(this->texture.texture, this->screenRect, this->position, this->viewPortBackGroundColor);
    }
};

#endif //VIEWPORT_H
