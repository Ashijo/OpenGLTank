/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sphere.cpp
 * Author: ashijo
 * 
 * Created on January 7, 2018, 5:10 PM
 */

#include "Sphere.h"

Sphere::Sphere() {
}

Sphere::Sphere(const Sphere& orig) {
}

Sphere::~Sphere() {
}

Sphere::Sphere(GLuint idTexture, Point center, int r){
    this->idTexture = idTexture;
    this->center = center;
    this->r = r;
    
    idList = glGenLists(1);
        glNewList(idList, GL_COMPILE);
        

        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, this->idTexture);
        quadric = gluNewQuadric();
        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluQuadricTexture(quadric, GL_TRUE);

    gluSphere(quadric, 1, 20, 20);



}

void Sphere::render(){
    int x, y, z;
    center.getXYZ(&x,&y,&z);
    
    
     glPushMatrix();
     glTranslated(x, y, z);
     glScaled(r,r,r);
     glCallList(idList);
     glPopMatrix();
}