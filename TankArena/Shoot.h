/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shoot.h
 * Author: ashijo
 *
 * Created on January 7, 2018, 4:25 PM
 */

#ifndef SHOOT_H
#define SHOOT_H

#include "Line.h"
#include "Game.h"
#include "Sphere.h"

class Tank;
class Shoot {
public:
    Shoot();
    Shoot(const Shoot& orig);
    Shoot(Point from, int angle ,GLuint idText, Tank* enemy);
    
    virtual ~Shoot();
    void render();
    void updatePos();
    int getAngle();
    Point getPos();
    bool checkCol();
    
private:
    int angle;
    Sphere* body = NULL;
    Tank* enemy;
    bool exist = true;
    
};

#endif /* SHOOT_H */

