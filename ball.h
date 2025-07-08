//
// Created by Petre Ioan Iulian on 7/8/2025.
//

#include "raylib.h"

#ifndef BALL_H
#define BALL_H

const int screenWidth = 1280;
const int screenHeight = 800;

Color Orange = Color{255,165,0, 254};

class Ball {
public:
    float x,y;
    int velocity_x,velocity_y;
    int radius;

    Ball() {
        x = screenWidth / 2;
        y = screenHeight / 2;
        velocity_x = 7;
        velocity_y = 7;
        radius = 20;
    }

    void DrawBall() {
        DrawCircle(x, y, radius, Orange);
    }
    void UpdatePosition(int *computer_score, int *player_score) {
        x += velocity_x;
        y += velocity_y;
        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            velocity_y *= -1;
        }
        if (x + radius >= GetScreenWidth()) {
            (*computer_score)++;
            ResetPosition();
        } else if (x + radius <= 0) {
            (*player_score)++;
            ResetPosition();
        }
    }
    void ResetPosition() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;
        int direction[2]={-1,1};
        velocity_x *= direction[GetRandomValue(0, 1)];
        velocity_y *= direction[GetRandomValue(0, 1)];
    }
};

#endif //BALL_H
