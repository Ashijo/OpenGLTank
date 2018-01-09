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

int Tank::nbTank = 0;

Tank::Tank(Game* ctx, GLuint idText, Point pos){

    this->ctx = ctx;
    this->idText = idText;
    this->pos = pos;
    
    size.setXYZ(3,3,20);
    posCanon.setXYZ(pos.getX(), pos.getY(), pos.getZ() + size.getZ() / 2);
    canon = new Cylinder(idText, posCanon, size);
    
    size.setXYZ(10,10,10);
    body = new Cube(idText, pos, size);
    
    ref = nbTank;
    nbTank++;
    
    if (ref == 0){
        dirAngle = 0;
    }else{
        dirAngle = 180;
    }
    
}

void Tank::render(){
    glPushMatrix();
    
    
    body->render(dirAngle);
    canon->render(90,0,dirAngle);
    
    glPopMatrix();
    
    
};

Tank* Tank::getTankPtr(){
    return this;
}

bool Tank::checkCol(int x, int y){
    bool respons = false;
    
    int enX, enY, myX, myY, sizeX, sizeY;
    ctx->getEnemyPtr(ref)->getPos().getXY(&enX, &enY);
    pos.getXY(&myX, &myY);
    size.getXY(&sizeX, &sizeY);
    myX += x;
    myY += y;
    
    if(
            myX-sizeX >= enX+sizeX ||
            myX+sizeX <= enX-sizeX ||
            myY-sizeY >= enY+sizeY ||
            myY+sizeY <= enY-sizeY 
            
        ){
        respons = true;
    }
    
    return respons;

};
    
Point Tank::getPos(){
    return pos;
}

void Tank::avancer(){
    int x,y, mX, mY;
    pos.getXY(&x,&y);
    
    mY = SPEED* sin(TO_RAD * (dirAngle-90));
    mX = SPEED* cos(TO_RAD * (dirAngle-90));
    
    if(checkCol(mX, mY)){
    pos.setXY(x + mX,y + mY);
    updatePos();
    }
}
    
 void Tank::reculer(){
 int x,y;
    
    pos.getXY(&x,&y);
 
    y -= SPEED* sin(TO_RAD * (dirAngle-90));
    x -= SPEED* cos(TO_RAD * (dirAngle-90));
    
    pos.setXY(x,y);
    updatePos();
 
 }   

void Tank::updatePos(){
    int x,y;
    
    pos.getXY(&x,&y);
    body->setPos(x,y);
    canon->setPos(x,y);
}

bool Tank::shoot(){

    bool retour = false;
    if (delay <= 0){
        retour = true;
        delay = 15;
    } 

    return retour;

};
void Tank::isShooted(){
    std::cout<< "Tank " << ref << " is shooted" << std::endl;
    
    hp--;
    std::cout << "hp left : " << hp << std::endl;
    
    if (hp <= 0 ){
        ctx->endGame();
    }
    
};

void Tank::mooveRight(){
    dirAngle -=3;
}
void Tank::mooveLeft(){
    dirAngle +=3;
}

int Tank::getDirection(){
    return dirAngle;
}

void Tank::update(){
    delay--;
}

