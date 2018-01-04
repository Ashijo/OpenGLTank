/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cone.cpp
 * Author: androidlinux
 * 
 * Created on December 20, 2017, 11:41 AM
 */

#include "Cone.h"

Cone::Cone() {
    this->params = gluNewQuadric();
    //gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
}

Cone::Cone(const Cone& orig) {
}

Cone::~Cone() {
    gluDeleteQuadric(params);
}

void Cone::render(){
    gluCylinder(params,10,1,15,25,25);
}