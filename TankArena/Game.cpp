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
        updateModels();
        //viewport manager
        if (first_person){
            
        
            glViewport(1, 1, WIN_WIDTH / 2 -2, WIN_HEIGHT -2);
            glLoadIdentity();
            gluLookAt(tank1eyeX, tank1eyeY, tank1eyeZ, tank1dirX, tank1dirY, tank1dirZ, 0, 0, 1);
            
            drawModels();
            
            glViewport(WIN_WIDTH / 2 +1, 1, WIN_WIDTH / 2 -2, WIN_HEIGHT-2);
            glLoadIdentity();
            gluLookAt(tank2eyeX, tank2eyeY, tank2eyeZ, tank2dirX, tank2dirY, tank2dirZ, 0, 0, 1);

            drawModels();
            
        } else {   
            glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
            glLoadIdentity();
            gluLookAt(eyeX, eyeY, eyeZ, dirX, dirY, dirZ, 0, 0, 1);
        
            drawModels();
            
        }
        

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
    
    
    for (int i = 0; i < shoots.size(); i++){
        shoots[i]->~Shoot();
    }
    
    tank1->~Tank();
    tank2->~Tank();
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

Tank* Game::getEnemyPtr(int ref){
    Tank* respons;
    
    if (ref == 1){
    
        respons = tank1;
        
    }
    if (ref == 0){
    
        respons = tank2;
    
    }
    
    return respons;
}

int Game::getTick(){

    return tick;

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
    size.setXYZ(SKYBOX_SIZE,SKYBOX_SIZE,SKYBOX_SIZE);
    skybox = new Cube(imgSkybox, 6,pos, size);
    pos.setXYZ(2,2,1);
    size.setXYZ(ARN_SIZE,ARN_SIZE,ARN_UP);
    arene = new Cube(imgArn, 2, pos, size);
    
    pos.setXYZ(ARN_SIZE * -1 / 10 ,2,20);
    tank1 = new Tank(this, imgTnk[0], pos);
    pos.setXYZ(ARN_SIZE / 10 ,2,20);
    tank2 = new Tank(this, imgTnk[1], pos);
    
    
    //init TPS viewPort 
    dirX = 1;
    dirY = 0;
    dirZ = 10;
    
    eyeX = 40;
    eyeY = 0;
    eyeZ = 950;
    
    
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
    //gestion des evenements clavier
    int only_one;
    SDL_Event event;
    only_one = SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT || states[SDL_SCANCODE_ESCAPE])
            isRunning = false;
        if(states[SDL_SCANCODE_W]){
            tank2->avancer();
        }
        if(states[SDL_SCANCODE_S]){
            tank2->reculer();
        }
        if(states[SDL_SCANCODE_A]){
            tank2->mooveLeft();
        }
        if(states[SDL_SCANCODE_D]){
            tank2->mooveRight();
        }
        if(states[SDL_SCANCODE_E]){
            tank2->right();
        }
        if(states[SDL_SCANCODE_Q]){
            tank2->left();
        }
        if(states[SDL_SCANCODE_SPACE]){
            
            if (tank2->shoot()){
                Shoot* s = new Shoot(tank2->getPos(), tank2->getDirection(), imgTnk[2], tank1);
                shoots.push_back(s);
            }
            
        }
        
        if(states[SDL_SCANCODE_UP]){
            tank1->avancer();
        }
        if(states[SDL_SCANCODE_DOWN]){
            tank1->reculer();
        }
        if(states[SDL_SCANCODE_LEFT]){
            tank1->mooveLeft();
        }
        if(states[SDL_SCANCODE_RIGHT]){
            tank1->mooveRight();
        }
        if(states[SDL_SCANCODE_PAGEUP]){
            tank1->left();
        }
        if(states[SDL_SCANCODE_PAGEDOWN]){
            tank1->right();
        }
        if(states[SDL_SCANCODE_RCTRL]){
            if (tank1->shoot()){
                Shoot* s = new Shoot(tank1->getPos(), tank1->getDirection(), imgTnk[2], tank2);
                shoots.push_back(s);
            }
        
        }
    
        
        if(states[SDL_SCANCODE_F1] && only_one == 1){
            first_person = !first_person;
        }
        
    SDL_WarpMouseInWindow(win, WIN_WIDTH/2 , WIN_HEIGHT/2);
    tick++;
    
}

void Game::updateModels(){
    
    for (int i = 0; i < shoots.size(); i++){
        shoots[i]->updatePos();
        if(shoots[i]->checkCol()){
        
            shoots[i]->~Shoot();
        
        };
    }
    
    tank1->update();
    tank2->update();
    
    
    tank1->getPos().getXYZ(&tank1dirX, &tank1dirY, &tank1dirZ);
    tank1->getPos().getXYZ(&tank1eyeX, &tank1eyeY, &tank1eyeZ);
    tank1dirZ += 5;
    tank1eyeZ += 25;
    tank1dirX += cos((tank1->getDirection()-90) * TO_RAD) * 50;
    tank1dirY += sin((tank1->getDirection()-90) * TO_RAD) * 50;

    tank1eyeX += cos((tank1->getDirection()-90) * TO_RAD) * 10;
    tank1eyeY += sin((tank1->getDirection()-90) * TO_RAD) * 10;
    
    
    
    tank2->getPos().getXYZ(&tank2dirX, &tank2dirY, &tank2dirZ);
    tank2->getPos().getXYZ(&tank2eyeX, &tank2eyeY, &tank2eyeZ);
    tank2dirZ += 5;
    tank2eyeZ += 25;
    tank2dirX += cos((tank2->getDirection()-90) * TO_RAD) * 50;
    tank2dirY += sin((tank2->getDirection()-90) * TO_RAD) * 50;

    tank2eyeX += cos((tank2->getDirection()-90) * TO_RAD) * 10;
    tank2eyeY += sin((tank2->getDirection()-90) * TO_RAD) * 10;
    
   
}


void Game::drawModels(){

    
    arene->render();
    
    skybox->render();
    
    tank1->render();
    tank2->render();
    
    for (int i = 0; i < shoots.size(); i++){
        shoots[i]->render();
    }
    
}


void Game::endGame(){
    isRunning = false;
}
