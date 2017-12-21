/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: androidlinux
 * 
 * Created on December 19, 2017, 10:49 AM
 */

#include "Game.h"

void Game::Init() {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    IMG_Init(IMG_INIT_JPG);


    win = SDL_CreateWindow("Christmass", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    ctx = SDL_GL_CreateContext(win);
    SDL_ShowCursor(SDL_DISABLE);

    dirX = 10;
    dirY = 10;
    dirZ = 25;
    
    eyeX = 40;
    eyeY = 40;
    eyeZ = 20;
    
    std::string skyDown = "textures/skybox/down.jpg";
    std::string skyLeft = "textures/skybox/left.jpg";
    std::string skyFront = "textures/skybox/back.jpg";
    std::string skyRight = "textures/skybox/right.jpg";
    std::string skyBack = "textures/skybox/front.jpg";
    std::string skyUp = "textures/skybox/up.jpg";
    
    idTest[0] = loadTexture(skyDown.c_str());
    idTest[1] = loadTexture(skyLeft.c_str());
    idTest[2] = loadTexture(skyFront.c_str());
    idTest[3] = loadTexture(skyRight.c_str());
    idTest[4] = loadTexture(skyBack.c_str());
    idTest[5] = loadTexture(skyUp.c_str());
    
    c = new Cube(idTest);
    cone = new Cone();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) WIN_WIDTH / WIN_HEIGHT, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 1);

    isRunning = true;


}

void Game::Start() {
    int start, end;

    while (isRunning) {
        start = SDL_GetTicks();

        event();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        
//        glTranslated(eyeX, eyeY, eyeZ);
//        gluLookAt(0.0, 0.0, 0.0, dirX, dirY, dirZ, 0, 0, 1);
//        glLoadIdentity();
        
        gluLookAt(eyeX, eyeY, eyeZ, dirX, dirY, dirZ, 0, 0, 1);

        

        glScaled(200,200,200);
        c->render();
        
        glLoadIdentity();
        
        //glColor3ub(255,0,255);
        //cone->render();

        //mettre a jour l ecran
        SDL_GL_SwapWindow(win);
                
                end = SDL_GetTicks();
                
                if (end-start < 1000/FPS){
                    SDL_Delay((1000/FPS)-(end-start));
                }

    }



}

void Game::Free() {

    glDeleteTextures(6, idTest);
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    IMG_Quit();

    SDL_Quit();

}


void Game::event(){
    // innitialisationd des variables
    float i = 0.0;
    int alphaLateral = 0;
    double dirXLateral = 0.0;
    double dirYLateral = 0.0;
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
        if(states[SDL_SCANCODE_A]){
            //lateral gauche
            alphaLateral = alphaDir + 90;
            dirXLateral = eyeX + toDeg(sin(toRad(alphaLateral)))*2;
            dirYLateral = eyeY + toDeg(cos(toRad(alphaLateral)))*2;
            
//            std::cout << "alpha dir : " << alphaDir << std::endl;
//            std::cout << "alphaLateral : " << alphaLateral << std::endl;
//            std::cout << "cos(toRad(alphaB)) : " << cos(toRad(alphaLateral)) << std::endl;
//            std::cout << "sin(toRad(alphaB)) : " << sin(toRad(alphaLateral)) << std::endl;
//            std::cout << " dirX - eyeX : " << dirXLateral - eyeX << std::endl;
//            std::cout << " dirY - eyeY : " << dirYLateral - eyeY << std::endl;
//            std::cout << "dirX : " << dirXLateral << ".  dirY :" << dirYLateral<< ".  dirZ :" << dirZ << std::endl;
            
            i = dirXLateral - eyeX;
            eyeX -= (i/50);
            i = dirYLateral - eyeY;
            eyeY -= (i/50);
        }
        if(states[SDL_SCANCODE_D]){
            alphaLateral = alphaDir - 90 ;
            dirXLateral = eyeX + toDeg(sin(toRad(alphaLateral)))*2;
            dirYLateral = eyeY + toDeg(cos(toRad(alphaLateral)))*2;
            
            i = dirXLateral - eyeX;
            eyeX -= (i/50);
            i = dirYLateral - eyeY;
            eyeY -= (i/50);
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

float Game::toRad(int deg){
    
    float r = (float)deg/180/3.14159265358979323846;
    return  r;
}

 double Game::toDeg(float rad){
     
    double r = rad*180/3.14159265358979323846;
    return r;
 };
