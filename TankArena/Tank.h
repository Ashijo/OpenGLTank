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

class Game;
class Tank {
public:
    Tank();
    Tank(const Tank& orig);
    virtual ~Tank();
    Tank(Game *ctx ,GLuint idText, Point pos);
    
    void render();
    void checkCol();
    
    void shoot();
    void isShooted();
    
    
private:
    GLuint idText;
    GLuint idGPU;
    int hp = 10;
    
    Point pos;
    Point posCanon;
    
    
    Game* ctx = NULL;
    Cube* body = NULL;
    Cylinder* canon = NULL;
    
    
    
    
};

#endif /* TANK_H */

