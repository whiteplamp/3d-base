#ifndef FIELD_H
#define FIELD_H
#include <iostream>
#include <vector>

#include "raylib.h"
#include "../figures/square.h"


struct Collision {
    bool isCollided;
};

class Field {
private:
    Vector2 point1, point2, point3, point4;
    std::vector<Square> squares;
    float speed;
    bool moving = false;
public:
    Field(
        Vector2 point1,
        Vector2 point2,
        Vector2 point3,
        Vector2 point4,
        std::vector<Square> &squares,
        float speed
    ): point1(point1), point2(point2), point3(point3), point4(point4),  squares(squares), speed(speed)  {};



    void update() {
        for (int i = 0; i < squares.size(); i++) {
            auto squareCenter = squares[i].getCenter();
            auto squareSize = squares[i].getSize();

            if ((squareCenter.x - squareSize.x / 2 <= point1.x) || (squareCenter.x + squareSize.x / 2 >= point2.x)) {
                auto direction = squares[i].getDirection();
                squares[i].updateDirection(
                    (Vector2){-direction.x, direction.y}
                );
            }
            if ((squareCenter.y - squareSize.y / 2 <= point2.y) || (squareCenter.y + squareSize.y / 2 >= point3.y)) {
                auto direction = squares[i].getDirection();
                squares[i].updateDirection(
                    (Vector2){direction.x, -direction.y}
                );
            }
            squares[i].update();

        }

        std::cout << CheckCollisionRecs(squares[0].getRectangle(), squares[1].getRectangle()) << std::endl;

        if (CheckCollisionRecs(squares[0].getRectangle(), squares[1].getRectangle())) {
            auto centerF = squares[0].getCenter();
            auto centerS = squares[1].getCenter();
            auto sizeX = squares[0].getSize().x / 2  + squares[1].getSize().x / 2;
            auto sizeY = squares[0].getSize().y / 2 + squares[1].getSize().y / 2;
            auto directionF = squares[0].getDirection();
            auto directionS = squares[1].getDirection();

            std::cout << "X" << abs(centerF.x - centerS.x) << std::endl;
            std::cout << "Y" << abs(centerF.y - centerS.y) << std::endl;

            if (abs(centerF.x - centerS.x) <= sizeX) {
                squares[0].updateDirection(
                    (Vector2){directionF.x, -directionF.y}
                );
                squares[1].updateDirection(
                    (Vector2){directionS.x, -directionS.y}
                );
            }
            else if (abs(centerF.y - centerS.y) <= sizeY) {
                squares[0].updateDirection(
                    (Vector2){-directionF.x, directionF.y}
                );
                squares[1].updateDirection(
                    (Vector2){-directionS.x, directionS.y}
                );
            }
            else {
            }
        }
    }
    void draw() {
        DrawLineV(point1, point2, BLACK);
        DrawLineV(point2, point3, BLACK);
        DrawLineV(point3, point4, BLACK);
        DrawLineV(point4, point1, BLACK);

        for (auto square : squares) {
            square.draw();
        }
    }

    void turnMoving() {
        moving = !moving;
    }
};

#endif //FIELD_H
