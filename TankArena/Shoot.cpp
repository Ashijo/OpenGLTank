/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shoot.cpp
 * Author: ashijo
 * 
 * Created on January 7, 2018, 4:25 PM
 */

#include "Shoot.h"

Shoot::Shoot() {
}

Shoot::Shoot(const Shoot& orig) {
}

Shoot::~Shoot() {
}

Shoot::Shoot(Line direction){

    int xA, yA, xB, yB, xAB, yAB;
    
    direction.getA().getXY(&xA, &yA);
    direction.getB().getXY(&xB, &yB);
    
    xAB = xB-xA;
    yAB = yB-yA;
    
    this->direction = direction;
    
    
};

