//
// Created by Petre Ioan Iulian on 7/8/2025.
//

#include "player.h""

#ifndef COMPUTER_H
#define COMPUTER_H

class Computer: public Player {
public:

    Computer() {
        x = screenWidth -35;
        y = screenHeight / 2 - 60;
        width = 25;
        height = 120;
        velocity = 6;
    }

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

#endif //COMPUTER_H
