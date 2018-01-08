/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cube.cpp
 * Author: androidlinux
 * 
 * Created on December 19, 2017, 10:27 AM
 */

#include "Cube.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>


Cube::Cube() {
    idGPU = glGenLists(1);
    glNewList(idGPU, GL_COMPILE);
    
    
    
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex3i( -1, -1, 0);
        glVertex3i( -1, 1, 0);
        glVertex3i( 1, 1, 0);
        glVertex3i( 1, -1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(62, 151, 191);
        glVertex3i( 1, -1, 0);
        glVertex3i( 1, -1, 2);
        glVertex3i( 1, 1, 2);
        glVertex3i( 1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(57, 83, 142);
        glVertex3i( 1,-1, 0);
        glVertex3i( 1,-1, 2);
        glVertex3i( -1,-1, 2);
        glVertex3i( -1,-1, 0);
    glEnd();
        
    glBegin(GL_QUADS);
        glColor3ub(57, 83, 142);
        glVertex3i( -1, -1, 0);
        glVertex3i( -1, -1, 2);
        glVertex3i( -1, 1, 2);
        glVertex3i( -1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(57, 83, 142);
        glVertex3i( 1, 1, 0);
        glVertex3i( 1, 1, 2);
        glVertex3i( -1, 1, 2);
        glVertex3i( -1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex3i( -1, -1, 2);
        glVertex3i( -1, 1, 2);
        glVertex3i( 1, 1, 2);
        glVertex3i( 1, -1, 2);
    glEnd();

    glEndList();
}




Cube::~Cube() {
    glDeleteLists(idGPU, 1);    
}

void Cube::render(){
    
    glPushMatrix();
    
    
    glTranslated(position.getX(),position.getY(), position.getZ());
    
    glScaled(size.getX(),size.getY(),size.getZ());
    
    glCallList(idGPU);
   
    
    glPopMatrix();
    
}


void Cube::render(int angle){
    
    glPushMatrix();
    
    
    
    glTranslated(position.getX(),position.getY(), position.getZ());
    
    glScaled(size.getX(),size.getY(),size.getZ());
    
    glRotated(angle,0,0,1);
    
    glCallList(idGPU);
   
    
    glPopMatrix();
    
}



Cube::Cube(GLubyte r,GLubyte g,GLubyte b, Point pos, Point size):Rendable(pos, size) {
    idGPU = glGenLists(1);
    glNewList(idGPU, GL_COMPILE);
    
    
    
    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex3i( -1, -1, 0);
        glVertex3i( -1, 1, 0);
        glVertex3i( 1, 1, 0);
        glVertex3i( 1, -1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex3i( 1, -1, 0);
        glVertex3i( 1, -1, 2);
        glVertex3i( 1, 1, 2);
        glVertex3i( 1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex3i( 1,-1, 0);
        glVertex3i( 1,-1, 2);
        glVertex3i( -1,-1, 2);
        glVertex3i( -1,-1, 0);
    glEnd();
        
    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex3i( -1, -1, 0);
        glVertex3i( -1, -1, 2);
        glVertex3i( -1, 1, 2);
        glVertex3i( -1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex3i( 1, 1, 0);
        glVertex3i( 1, 1, 2);
        glVertex3i( -1, 1, 2);
        glVertex3i( -1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex3i( -1, -1, 2);
        glVertex3i( -1, 1, 2);
        glVertex3i( 1, 1, 2);
        glVertex3i( 1, -1, 2);
    glEnd();

    glEndList();
}

Cube::Cube(GLuint idTexture, Point pos, Point size):Rendable(pos, size){

    idGPU = glGenLists(1);
    glNewList(idGPU, GL_COMPILE);
    glColor3ub(255, 255, 255);
    
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3i( -1, -1, 0);
        glTexCoord2d(0, 1);
        glVertex3i( -1, 1, 0);
        glTexCoord2d(1, 1);
        glVertex3i( 1, 1, 0);
        glTexCoord2d(1, 0);
        glVertex3i( 1, -1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3i( 1, -1, 0);
        glTexCoord2d(0, 1);
        glVertex3i( 1, -1, 2);
        glTexCoord2d(1, 1);
        glVertex3i( 1, 1, 2);
        glTexCoord2d(1, 0);
        glVertex3i( 1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2d(1, 0);
        glVertex3i( 1,-1, 0);
        glTexCoord2d(1, 1);
        glVertex3i( 1,-1, 2);
        glTexCoord2d(0, 1);
        glVertex3i( -1,-1, 2);
        glTexCoord2d(0, 0);
        glVertex3i( -1,-1, 0);
    glEnd();
        
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3i( -1, -1, 0);
        glTexCoord2d(0, 1);
        glVertex3i( -1, -1, 2);
        glTexCoord2d(1, 1);
        glVertex3i( -1, 1, 2);
        glTexCoord2d(1, 0);
        glVertex3i( -1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2d(1, 0);
        glVertex3i( 1, 1, 0);
        glTexCoord2d(1, 1);
        glVertex3i( 1, 1, 2);
        glTexCoord2d(0, 1);
        glVertex3i( -1, 1, 2);
        glTexCoord2d(0, 0);
        glVertex3i( -1, 1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3i( -1, -1, 2);
        glTexCoord2d(0, 1);
        glVertex3i( -1, 1, 2);
        glTexCoord2d(1, 1);
        glVertex3i( 1, 1, 2);
        glTexCoord2d(1, 0);
        glVertex3i( 1, -1, 2);
    glEnd();

    glEndList();

};



Cube::Cube(GLuint idTexture[],int nbText ,Point pos, Point size):Rendable(pos, size){

    //idTexture[0] = down
    //idTexture[1] = left|right|forward|back
    //idTexture[2] = left|right|forward|back
    //idTexture[3] = left|right|forward|back
    //idTexture[4] = left|right|forward|back
    //idTexture[6] = up
    
    
    switch (nbText){
    
        case 2: 
            
            idGPU = glGenLists(1);
            glNewList(idGPU, GL_COMPILE);
            glColor3ub(255, 255, 255);
    
            glBindTexture(GL_TEXTURE_2D, idTexture[0]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( -1, -1, 0);
            glTexCoord2d(0, 100);
            glVertex3i( -1, 1, 0);
            glTexCoord2d(100, 100);
            glVertex3i( 1, 1, 0);
            glTexCoord2d(100, 0);
            glVertex3i( 1, -1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[1]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( 1, -1, 0);
            glTexCoord2d(0, 1);
            glVertex3i( 1, -1, 2);
            glTexCoord2d(50, 1);
            glVertex3i( 1, 1, 2);
            glTexCoord2d(50, 0);
            glVertex3i( 1, 1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[1]);
            glBegin(GL_QUADS);
            glTexCoord2d(50, 0);
            glVertex3i( 1,-1, 0);
            glTexCoord2d(50, 1);
            glVertex3i( 1,-1, 2);
            glTexCoord2d(0, 1);
            glVertex3i( -1,-1, 2);
            glTexCoord2d(0, 0);
            glVertex3i( -1,-1, 0);
            glEnd();
        
            glBindTexture(GL_TEXTURE_2D, idTexture[1]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( -1, -1, 0);
            glTexCoord2d(0, 1);
            glVertex3i( -1, -1, 2);
            glTexCoord2d(50, 1);
            glVertex3i( -1, 1, 2);
            glTexCoord2d(50, 0);
            glVertex3i( -1, 1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[1]);
            glBegin(GL_QUADS);
            glTexCoord2d(50, 0);
            glVertex3i( 1, 1, 0);
            glTexCoord2d(50, 1);
            glVertex3i( 1, 1, 2);
            glTexCoord2d(0, 1);
            glVertex3i( -1, 1, 2);
            glTexCoord2d(0, 0);
            glVertex3i( -1, 1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[0]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( -1, -1, 2);
            glTexCoord2d(0, 100);
            glVertex3i( -1, 1, 2);
            glTexCoord2d(100, 100);
            glVertex3i( 1, 1, 2);
            glTexCoord2d(100, 0);
            glVertex3i( 1, -1, 2);
            glEnd();

            glEndList();
            
            break;
    
        case 6:
            
            idGPU = glGenLists(1);
            glNewList(idGPU, GL_COMPILE);
            glColor3ub(255, 255, 255);
    
            glBindTexture(GL_TEXTURE_2D, idTexture[0]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( -1, -1, 0);
            glTexCoord2d(0, 100);
            glVertex3i( -1, 1, 0);
            glTexCoord2d(100, 100);
            glVertex3i( 1, 1, 0);
            glTexCoord2d(100, 0);
            glVertex3i( 1, -1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[1]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( 1, -1, 0);
            glTexCoord2d(0, 1);
            glVertex3i( 1, -1, 2);  
            glTexCoord2d(1, 1);
            glVertex3i( 1, 1, 2);
            glTexCoord2d(1, 0);
            glVertex3i( 1, 1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[2]);
            glBegin(GL_QUADS);
            glTexCoord2d(1, 0);
            glVertex3i( 1,-1, 0);
            glTexCoord2d(1, 1);
            glVertex3i( 1,-1, 2);
            glTexCoord2d(0, 1);
            glVertex3i( -1,-1, 2);
            glTexCoord2d(0, 0);
            glVertex3i( -1,-1, 0);
            glEnd();
        
            glBindTexture(GL_TEXTURE_2D, idTexture[3]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( -1, -1, 0);
            glTexCoord2d(0, 1);
            glVertex3i( -1, -1, 2);
            glTexCoord2d(1, 1);
            glVertex3i( -1, 1, 2);
            glTexCoord2d(1, 0);
            glVertex3i( -1, 1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[4]);
            glBegin(GL_QUADS);
            glTexCoord2d(1, 0);
            glVertex3i( 1, 1, 0);
            glTexCoord2d(1, 1);
            glVertex3i( 1, 1, 2);
            glTexCoord2d(0, 1);
            glVertex3i( -1, 1, 2);
            glTexCoord2d(0, 0);
            glVertex3i( -1, 1, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, idTexture[5]);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3i( -1, -1, 2);
            glTexCoord2d(0, 1);
            glVertex3i( -1, 1, 2);
            glTexCoord2d(1, 1);
            glVertex3i( 1, 1, 2);
            glTexCoord2d(1, 0);
            glVertex3i( 1, -1, 2);
            glEnd();

            glEndList();
    
            break;
    }
};
