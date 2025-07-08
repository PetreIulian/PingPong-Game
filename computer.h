//
// Created by Petre Ioan Iulian on 7/8/2025.
//

#include "player.h""

#ifndef COMPUTER_H
#define COMPUTER_H

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

#endif //COMPUTER_H
