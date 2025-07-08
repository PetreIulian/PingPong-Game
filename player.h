//
// Created by Petre Ioan Iulian on 7/8/2025.
//

#include "raylib.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
protected:
    void LimitMovement() {
        if (y <= 0) {
            y = 5;
        }
        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height - 5;
        }
    }
public:
    float x,y;
    float width,height;
    int velocity;
    void Draw() {
        DrawRectangle(x, y, width, height, RAYWHITE);
    }
    void Move() {
        if (IsKeyDown(KEY_UP)) {
            y = y - velocity;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y = y + velocity;
        }
        if (y <= 0) {
            y = 5;
        }
        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height - 5;
        }
        LimitMovement();
    }
};

#endif //PLAYER_H
