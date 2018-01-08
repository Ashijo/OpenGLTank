/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cylinder.cpp
 * Author: ashijo
 * 
 * Created on January 6, 2018, 3:13 PM
 */

#include <GL/gl.h>

#include "Cylinder.h"

Cylinder::Cylinder() {
    
    this->params = gluNewQuadric();
    //gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
    
    
}

Cylinder::Cylinder(GLuint idTexture ,Point pos, Point size):Rendable(pos, size) {

    idGPU = glGenLists(1);
    
    glNewList(idGPU, GL_COMPILE);
    
    
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, idTexture);
    this->params = gluNewQuadric();
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
    
    gluCylinder(params,1,1,1,size.getX()*size.getY(),size.getZ());
    
    gluDeleteQuadric(params);
    
    glEndList();
    
    
    
}

Cylinder::Cylinder(const Cylinder& orig) {
}

Cylinder::~Cylinder() {
     gluDeleteQuadric(params);
}

void Cylinder::render(double anglX,double anglY,double anglZ){

    
    glPushMatrix();
    
    
    glTranslated(position.getX(),position.getY(), position.getZ());
    
    glRotated(anglZ,0,0,1);
    glRotated(anglY,0,1,0);
    glRotated(anglX,1,0,0);
    
    glScaled(size.getX(), size.getY(), size.getZ());

    
    glCallList(idGPU);
    glPopMatrix();

}