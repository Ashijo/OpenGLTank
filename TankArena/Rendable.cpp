/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rendable.cpp
 * Author: ashijo
 * 
 * Created on January 4, 2018, 9:50 AM
 */

#include "Rendable.h"

Rendable::Rendable() {
    this->size.setXYZ(1,1,1);
}
Rendable::Rendable(Point position){
    this->position = position;
    this->size.setXYZ(1,1,1);
};
Rendable::Rendable(Point position, int sizeX, int sizeY, int sizeZ){
    this->position = position;
    this->size.setXYZ(sizeX, sizeY, sizeZ);
};
Rendable::Rendable(Point position, Point size){
    this->position = position;
    this->size = size;
};
    
Point Rendable::getPos(){
    return this->position;
};
void Rendable::getPos(Point* pos){
    pos->setXYZ(position);
};
void Rendable::getPos(Point* pos, int* sizeX, int* sizeY, int* sizeZ){
    pos->setXYZ(position);
    *sizeX = size.getX();
    *sizeY = size.getY();
    *sizeZ = size.getZ();
};
void Rendable::getPos(Point* pos, Point* size){
    pos->setXYZ(position);
    size->setXYZ(this->size);
};
    
void Rendable::setPos(Point newPos){
    this->position.setXYZ(newPos);
};
void Rendable::setPos(int x, int y){
    this->position.setXY(x,y);
};
void Rendable::setPos(int x, int y, int z){
    this->position.setXYZ(x,y,z);
};

void Rendable::render(){};