/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: ashijo
 *
 * Created on January 4, 2018, 9:28 AM
 */

#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Constantes.h"
#include "Cube.h"
#include <math.h>
#include "sdlglutils.h"
#include "Cylinder.h"
#include "Tank.h"
#include "Sphere.h" 
#include "vector"
#include "Shoot.h"


class Shoot;
class Tank;
class Cube;
class Game {
public:
    Game();
    ~Game();
    
    void init();
    void start();
    void free();
    
    Tank* getEnemyPtr(int ref);
    int getTick();
    void endGame();
private:
    
    // contextes
    SDL_Window* win = NULL;
    SDL_GLContext ctx;
    
    //attributs
    bool isRunning  = true;
    Cube* skybox    = NULL;
    Cube* arene     = NULL;
    Tank* tank1      = NULL;
    Tank* tank2      = NULL;
    std::vector <Shoot*> shoots;
    
    
    double eyeX, eyeY, eyeZ, dirX, dirY, dirZ;
    int alphaDir = 0;
    int tick = 0;
    
    const Uint8* states;
    GLuint imgSkybox[6];
    GLuint imgArn[2];
    GLuint imgTnk[3];
    
    
    //methodes de rangement 
        //initialisation
    void initSDL();
    void initTextures();
    void initModels();
    void initMatrix();
        //en jeu
    void cleaner();
    void event();
    void updateModels();
    void drawModels();
    
    
};

#endif /* GAME_H */

