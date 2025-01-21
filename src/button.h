//
// Created by yanne on 15.01.2025.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <string>

#include "raylib.h"

class Button {
private:
    Vector2 position, size;
    std::string text;
    Color color, hoverColor;
    Font font;
    float fontSize;
public:
    Button(Vector2 position, Vector2 size, std::string text, Color color, Color hoverColor, Font font, float fontSize): position(position), size(size), text(text), color(color), hoverColor(hoverColor), font(font), fontSize(fontSize) {};

    void draw() {
        Vector2 textCenter = (Vector2) {position.x + 10, position.y + size.y / 2 - fontSize / 2, };
        auto mousePos = GetMousePosition();
        if ((mousePos.x > position.x && mousePos.x < position.x + size.x) && (mousePos.y > position.y && mousePos.y < position.y + size.y) ) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawRectangleV(position, size, hoverColor);
        }
        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            DrawRectangleV(position, size, color);
        }
        DrawTextEx(font, text.c_str(), textCenter, fontSize, 4, WHITE);
    }

};

#endif //BUTTON_H
