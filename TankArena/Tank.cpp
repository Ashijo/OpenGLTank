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
#include "Constantes.h"

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
    
    int enX, enY, sizeX, sizeY;
    ctx->getEnemyPtr(ref)->getPos().getXY(&enX, &enY);
    size.getXY(&sizeX, &sizeY);
    
    if(
        x-sizeX >= enX+sizeX ||
        x+sizeX <= enX-sizeX ||
        y-sizeY >= enY+sizeY ||
        y+sizeY <= enY-sizeY
        ){
        respons = true;
    }
    
    return respons;
};
    
Point Tank::getPos(){
    return pos;
}

void Tank::right(){
    int x,y, mX, mY;
    pos.getXY(&x,&y);
    
    mY = SPEED* sin(TO_RAD * (dirAngle-180));
    mX = SPEED* cos(TO_RAD * (dirAngle-180));
    
    if(checkCol(mX + x, mY + y)){
        pos.setXY(x + mX, y + mY);
        updatePos();
    }

}

void Tank::left(){
    int x,y, mX, mY;
    pos.getXY(&x,&y);
    
    mY = SPEED* sin(TO_RAD * dirAngle);
    mX = SPEED* cos(TO_RAD * dirAngle);
    
    if(checkCol(mX + x, mY + y)){
        pos.setXY(x + mX,y + mY);
        updatePos();
    }
}

void Tank::avancer(){
    int x,y, mX, mY;
    pos.getXY(&x,&y);
    
    mY = SPEED* sin(TO_RAD * (dirAngle-90));
    mX = SPEED* cos(TO_RAD * (dirAngle-90));
    
    if(checkCol(mX + x, mY + y)){
        pos.setXY(x + mX,y + mY);
        updatePos();
    }
}
    
 void Tank::reculer(){
 int x,y, mX, mY;
    
    pos.getXY(&mX,&mY);
 
    y = SPEED* sin(TO_RAD * (dirAngle-90));
    x = SPEED* cos(TO_RAD * (dirAngle-90));
    
    if (checkCol(mX - x, mY - y)){
        pos.setXY(mX-x,mY-y);
        updatePos();
    }
 }   

void Tank::updatePos(){
    int x,y,z;
    
    pos.getXYZ(&x,&y,&z);
    body->setPos(x,y,z);
    canon->setPos(x,y,z + size.getZ());
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
    checkPos();
}

void Tank::checkPos(){
    int posX, posY, posZ;
    pos.getXYZ(&posX, &posY, &posZ);
      
    if (
            posX + 10 < ARN_SIZE * -1 ||
            posX - 10 > ARN_SIZE      ||
            posY + 10 < ARN_SIZE * -1 ||
            posY - 10 > ARN_SIZE
            ){
        pos.setZ(posZ -1);
        updatePos();
    }
    
    if (posZ < -1){
        isShooted();
    }
}