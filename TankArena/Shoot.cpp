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




Shoot::Shoot(Point from, int angle, GLuint idText, Tank* enemy){

    this->angle = angle;
    
    
    int fX, fY, xA, yA;
    
    from.getXY(&xA, &yA);
    
    fX = xA + cos((angle -90) * TO_RAD) * BULLET_SPEED;
    fY = yA + sin((angle -90)* TO_RAD) * BULLET_SPEED;
    
    Point pos(fX ,fY ,30 );
    
    body = new Sphere(idText, pos, 3);
    this-> enemy = enemy;
}

void Shoot::render(){
    if(exist){
        body->render();
    }
}

void Shoot::updatePos(){
    int posX, posY;
    
    body->getPos().getXY(&posX, &posY);
    
    posX += cos((angle -90)* TO_RAD) * BULLET_SPEED;
    posY += sin((angle -90)* TO_RAD) * BULLET_SPEED;
    
    
    body->setPos(posX, posY);
    
}

Point Shoot::getPos(){
    return body->getPos();
}
bool Shoot::checkCol(){
    bool retour = false;
    int myPosX, myPosY, enPosX, enPosY;
    int sizeTank = 10;
    
    body->getPos().getXY(&myPosX, &myPosY);
    enemy->getPos().getXY(&enPosX, &enPosY);
    
     
    if (    
            myPosX > enPosX - sizeTank &&
            myPosX < enPosX + sizeTank &&
            myPosY > enPosY - sizeTank &&
            myPosY < enPosY + sizeTank &&
            exist
            ){
        enemy->isShooted();
        exist = false;
        retour = true;
    }
    
    return retour;
}



