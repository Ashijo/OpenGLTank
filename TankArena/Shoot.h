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

class Shoot {
public:
    Shoot();
    Shoot(const Shoot& orig);
    Shoot(Line direction);
    virtual ~Shoot();
    void render();
    int getAngle();
    
private:
    Line direction;
    Game* ctx = NULL;
    int angle;
    
    
};

#endif /* SHOOT_H */
