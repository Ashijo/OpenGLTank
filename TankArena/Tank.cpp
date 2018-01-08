/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tank.cpp
 * Author: ashijo
 * 
 * Created on January 6, 2018, 7:41 PM
 */

#include "Tank.h"

Tank::Tank() {
}

Tank::Tank(const Tank& orig) {
}

Tank::~Tank() {
}

Tank::Tank(Game* ctx, GLuint idText, Point pos){

    this->ctx = ctx;
    this->idText = idText;
    this->pos = pos;
    
    Point size(10,10,10);
    
    body = new Cube(idText, pos, size);
    
    size.setXYZ(3,3,25);
    posCanon.setXYZ(pos.getX(), pos.getY(), pos.getZ() + size.getZ() / 2);
    
    canon = new Cylinder(idText, posCanon, size);
    
}

void Tank::render(){

    body->render();
    canon->render(90,0,0);
    
};
void Tank::checkCol(){};
    
void Tank::shoot(){};
void Tank::isShooted(){};