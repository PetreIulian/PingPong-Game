#include <iostream>
#include "raylib.h"

int player_score = 0;
int computer_score = 0;

Color Orange = Color{255,165,0, 254};
Color LightGreen = Color{46, 204, 113, 255};
Color Caledonian = Color{130, 224, 170, 255};
Color AquaMarine = Color{88, 214, 141, 255};

class Ball {
public:
    float x,y;
    int velocity_x,velocity_y;
    int radius;
void DrawBall() {
    DrawCircle(x, y, radius, Orange);
}
void UpdatePosition() {
    x += velocity_x;
    y += velocity_y;
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        velocity_y *= -1;
    }
    if (x + radius >= GetScreenWidth()) {
        computer_score++;
        ResetPosition();
    } else if (x + radius <= 0) {
               player_score++;
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

class Computer: public Player {
public:
void ComputerMove(int ball_y) {
    if (y + height / 2 > ball_y) {
        y -= velocity;
    }
    if (y + height / 2 <= ball_y) {
        y += velocity;
    }
    LimitMovement();
}
};

Ball ball;
Player player;
Computer computer;

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "PingPong");
    SetTargetFPS(60);

    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.velocity_x = 7;
    ball.velocity_y = 7;
    ball.radius = 20;

    player.x = 10;
    player.y = screenHeight / 2  - 60;
    player.width = 25;
    player.height = 120;
    player.velocity = 6;

    computer.x = screenWidth -35;
    computer.y = screenHeight / 2 - 60;
    computer.width = 25;
    computer.height = 120;
    computer.velocity = 6;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ball.UpdatePosition();
        player.Move();
        computer.ComputerMove(ball.y);

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})) {
            ball.velocity_x *=-1;
        }
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{computer.x, computer.y, computer.width, computer.height})) {
            ball.velocity_x *= -1;
        }


        ClearBackground(LightGreen);
        DrawRectangle(0, 0, screenWidth / 2 , screenHeight, AquaMarine);
        DrawCircle(screenWidth / 2, screenHeight / 2, 101, RAYWHITE);
        DrawCircle(screenWidth / 2, screenHeight / 2, 100, Caledonian);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, RAYWHITE);
        ball.DrawBall();
        player.Draw();
        computer.Draw();
        DrawText(TextFormat("%i", player_score), 3 * screenWidth / 4 - 20, 20, 80, RAYWHITE);
        DrawText(TextFormat("%i", computer_score), screenWidth / 4 - 20, 20, 80, RAYWHITE);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}