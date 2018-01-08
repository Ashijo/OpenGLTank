/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: ashijo
 * 
 * Created on January 4, 2018, 9:28 AM
 */

#include "Game.h"

Game::Game() {
}
Game::~Game(){};


void Game::init(){

    initSDL();
   
    //pos de base (temporaire, pour debug)
    dirX = 10;
    dirY = 10;
    dirZ = 25;
    
    eyeX = 40;
    eyeY = 40;
    eyeZ = 50;
    
    initMatrix();
    initTextures(); 
    initModels();
   

}

void Game::start(){

    int start, end;

    while (isRunning) {
        start = SDL_GetTicks();

        cleaner();
        event();        
        
        gluLookAt(eyeX, eyeY, eyeZ, dirX, dirY, dirZ, 0, 0, 1);
       
        drawModels();

        //mettre a jour l ecran
        SDL_GL_SwapWindow(win);
                
        //gerrer les FPS
        end = SDL_GetTicks(); 
        if (end-start < 1000/FPS){
            SDL_Delay((1000/FPS)-(end-start));
        }

    }


}

void Game::free(){
    
    skybox->~Cube();
    arene->~Cube();

    glDeleteTextures(3, imgTnk);
    glDeleteTextures(2, imgArn);
    glDeleteTextures(6, imgSkybox);
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}


void Game::initSDL(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);


    win = SDL_CreateWindow("TPTankArena", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    if(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2) < 0) { printf("opengl error: %s\n", SDL_GetError()); }
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    if(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1) < 0) { printf("opengl error: %s\n", SDL_GetError()); }
 
    
    ctx = SDL_GL_CreateContext(win);
    SDL_ShowCursor(SDL_DISABLE);
}

void Game::initTextures(){

    std::string skyDown     = "textures/skybox/down.jpg";
    std::string skyLeft     = "textures/skybox/left.jpg";
    std::string skyFront    = "textures/skybox/back.jpg";
    std::string skyRight    = "textures/skybox/right.jpg";
    std::string skyBack     = "textures/skybox/front.jpg";
    std::string skyUp       = "textures/skybox/up.jpg";
    
    std::string arnGround   = "textures/sand.jpg";
    std::string arnSide     = "textures/brick.jpg";
    
    std::string tank1       = "textures/tnk1.jpg";
    std::string tank2       = "textures/tnk2.jpg";
    
    std::string steel       = "textures/steel.jpg";
    
    
    imgSkybox[0]            = loadTexture(skyDown.c_str());
    imgSkybox[1]            = loadTexture(skyBack.c_str());
    imgSkybox[2]            = loadTexture(skyRight.c_str());
    imgSkybox[3]            = loadTexture(skyFront.c_str());
    imgSkybox[4]            = loadTexture(skyLeft.c_str());
    imgSkybox[5]            = loadTexture(skyUp.c_str());
    
    imgArn[0]               = loadTexture(arnGround.c_str());
    imgArn[1]               = loadTexture(arnSide.c_str());

    imgTnk[0]               = loadTexture(tank1.c_str());
    imgTnk[1]               = loadTexture(tank2.c_str());
    imgTnk[3]               = loadTexture(steel.c_str());
    
}

void Game::initModels(){
    Point pos, size;
    
    pos.setXYZ(1,1,1);
    size.setXYZ(400,400,400);
    skybox = new Cube(imgSkybox, 6,pos, size);
    pos.setXYZ(2,2,1);
    size.setXYZ(300,300,10);
    arene = new Cube(imgArn, 2, pos, size);
    
    pos.setXYZ(2,2,20);
    size.setXYZ(30,30,100);
    test = new Tank(this, imgTnk[0], pos);
    
    //pos.setXYZ(100,100,20);
    //sphere = new Sphere(imgTnk[2], pos, 5);
    
}

void Game::initMatrix(){
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) WIN_WIDTH / WIN_HEIGHT, 1, 10000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 1);

}

void Game::cleaner(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Game::event(){
    // innitialisationd des variables
    float i = 0.0;
    int x = 0;
    int y = 0;
    Uint32 result;
    
    //prise des coordonnées de la sourie
    result = SDL_GetMouseState(&x,&y);
    
    //coordonées sourie au centre de l'écran
    x -= WIN_WIDTH/2;
    y -= WIN_HEIGHT/2;
    
    
    //on applique les changement de direction
    if (y < -1){
        dirZ++;
    }
    if (y > 1){
        dirZ--;
    }
    if (x < -1){
        alphaDir-=20;
    }
    if (x > 1){
        alphaDir+=20;
    }
    
    //calcul de la direction du regard
    dirX = eyeX + toDeg(sin(toRad(alphaDir)));
    dirY = eyeY + toDeg(cos(toRad(alphaDir)));
    
    //gestion des evenements clavier
    SDL_Event event;
    SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT || states[SDL_SCANCODE_ESCAPE])
            isRunning = false;
        if(states[SDL_SCANCODE_W]){
            //vers l'avant
            i = dirX - eyeX;
            eyeX += (i/50);
            i = dirY - eyeY;
            eyeY += (i/50);
        }
        if(states[SDL_SCANCODE_S]){
            //vers l'arriere
            i = dirX - eyeX;
            eyeX -= (i/50);
            i = dirY - eyeY;
            eyeY -= (i/50);
        }
        
        if(states[SDL_SCANCODE_UP]){
            //vers l'avant
            i = dirX - eyeX;
            eyeX += (i/50);
            i = dirY - eyeY;
            eyeY += (i/50);
        }
        if(states[SDL_SCANCODE_DOWN]){
            //vers l'arriere
            i = dirX - eyeX;
            eyeX -= (i/50);
            i = dirY - eyeY;
            eyeY -= (i/50);
        }
        
       
        if (states[SDL_SCANCODE_SPACE]){
            eyeZ += 10;
        }
        
        if (eyeZ > 30){
            eyeZ-= 5;
        }
        
        
    if(result == 1){
        i = dirX - eyeX;
        eyeX += (i/50);
        i = dirY - eyeY;
        eyeY += (i/50);
    }
    if(result == 4){
        i = dirX - eyeX;
        eyeX -= (i/50);
        i = dirY - eyeY;
        eyeY -= (i/50);
    }
        
    SDL_WarpMouseInWindow(win, WIN_WIDTH/2 , WIN_HEIGHT/2);
    
}

void Game::drawModels(){

    
    arene->render();
    
    skybox->render();
    
    test->render();
    
    //sphere->render();
    
    
}

float Game::toRad(int deg){
    
    float r = (float)deg/180/PI;
    return r;
}

 double Game::toDeg(float rad){
     
    double r = (double)rad*180/PI;
    return r;
 };