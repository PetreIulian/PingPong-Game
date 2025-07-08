//
// Created by Petre Ioan Iulian on 7/8/2025.
//

#include "raylib.h"

#ifndef BALL_H
#define BALL_H

Color Orange = Color{255,165,0, 254};

class Ball {
public:
    float x,y;
    int velocity_x,velocity_y;
    int radius;
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
