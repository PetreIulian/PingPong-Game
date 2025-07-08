#include <iostream>
#include "raylib.h"
#include "ball.h"
#include "player.h"
#include "computer.h"

int player_score_val = 0;
int computer_score_val = 0;
int *player_score = &player_score_val;
int *computer_score = &computer_score_val;

Color LightGreen = Color{46, 204, 113, 255};
Color Caledonian = Color{130, 224, 170, 255};
Color AquaMarine = Color{88, 214, 141, 255};


Ball ball;
Player player;
Computer computer;

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "PingPong");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ball.UpdatePosition(computer_score, player_score);
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
        DrawText(TextFormat("%i", *player_score), 3 * screenWidth / 4 - 20, 20, 80, RAYWHITE);
        DrawText(TextFormat("%i", *computer_score), screenWidth / 4 - 20, 20, 80, RAYWHITE);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}