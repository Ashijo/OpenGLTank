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



Cube::Cube(int largeur,int  profondeur,int  hauteur) {
    this->largeur = largeur;
    this->profondeur = profondeur;
    this->hauteur = hauteur;
    
    idGPU = glGenLists(1);
    glNewList(idGPU, GL_COMPILE);
    
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex3i(largeur/2*-1, profondeur/2*-1, 0);
        glVertex3i(largeur/2*-1, profondeur/2, 0);
        glVertex3i(largeur/2, profondeur/2, 0);
        glVertex3i(largeur/2, profondeur/2*-1, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(62, 101, 191);
        glVertex3i( largeur/2, profondeur/2*-1, 0);
        glVertex3i( largeur/2, profondeur/2*-1, hauteur);
        glVertex3i( largeur/2, profondeur/2, hauteur);
        glVertex3i( largeur/2, profondeur/2, 0);
    glEnd();

        glBegin(GL_QUADS);
        glColor3ub(57, 83, 142);
        glVertex3i(largeur/2,profondeur/2*-1, 0);
        glVertex3i(largeur/2,profondeur/2*-1, hauteur);
        glVertex3i(largeur/2*-1,profondeur/2*-1, hauteur);
        glVertex3i(largeur/2*-1,profondeur/2*-1, 0);
        glEnd();

    
        glBegin(GL_QUADS);
        glColor3ub(57, 83, 142);
        glVertex3i( largeur/2*-1,  profondeur/2*-1, 0);
        glVertex3i( largeur/2*-1, profondeur/2*-1, hauteur);
        glVertex3i( largeur/2*-1, profondeur/2, hauteur);
        glVertex3i( largeur/2*-1, profondeur/2, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(57, 83, 142);
        glVertex3i( largeur/2, profondeur/2, 0);
        glVertex3i( largeur/2, profondeur/2, hauteur);
        glVertex3i( largeur/2*-1, profondeur/2, hauteur);
        glVertex3i( largeur/2*-1, profondeur/2, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex3i( largeur/2*-1, profondeur/2*-1, hauteur);
        glVertex3i( largeur/2*-1, profondeur/2, hauteur);
        glVertex3i( largeur/2, profondeur/2, hauteur);
        glVertex3i( largeur/2, profondeur/2*-1, hauteur);
        glEnd();

        
        glEndList();
    
    
}


Cube::~Cube() {
    glDeleteLists(idGPU, 1);
    
}

void Cube::render(){
     glCallList(idGPU);
}

