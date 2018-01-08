/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tank.h
 * Author: ashijo
 *
 * Created on January 6, 2018, 7:41 PM
 */

#ifndef TANK_H
#define TANK_H

#include "Game.h"
#include "Cylinder.h"
#include "Constantes.h"
#include <math.h>
#include <iostream>

class Game;
class Tank {
public:
    Tank();
    Tank(const Tank& orig);
    virtual ~Tank();
    Tank(Game *ctx ,GLuint idText, Point pos);
    
    void render();
    bool checkCol(int x, int y);
    
    void avancer();
    void reculer();
    
    void shoot();
    void isShooted();
    
    void mooveRight();
    void mooveLeft();
    
    Tank* getTankPtr();
    Point getPos();
    
private:
    GLuint idText;
    GLuint idGPU;
    int hp = 10;
    
    Point pos, size;
    Point posCanon;
    
    int ref;
    
    Game*       ctx       = NULL;
    Cube*       body      = NULL;
    Cylinder*   canon     = NULL;
    
    int dirAngle;
    static int nbTank;
    
    void updatePos();
    
};

#endif /* TANK_H */

