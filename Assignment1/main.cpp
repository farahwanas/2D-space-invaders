//    Includes
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <OpenGL/gl3.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl3ext.h>
#include <math.h>
#include <vector>
#include <random>
#include<iostream>
#endif

#define SPACE 32

//Player Movements
int playerFactorUpDown=0;
int playerFactorLeftRight=0;
int boundsLeft=100;
int boundsRight=180;
int boundsUp=160;
int boundsDown=120;

//Enemy Movemenets
int moveYaEnemyLeftBounds=0;
int moveYaEnemyRightBounds=50;
int moveYaEnemy=0;
int direction =0;

//Enemy Bullets Movemenets
int moveYaEnemyBulletFelY=0;
int moveYaEnemyBulletFelX=0;


//Player Bullets Movemenets
int moveYaPlayerBulletFelY=1000;
int moveYaPlayerBulletFelX=-1100;
bool hassalSpace=false;


//PowerUps Movement
int randomPUP=-1000;
bool flag=false;
bool flagGebto=false;
bool flagColor=false;

//(rand() % (max- min)) + min


//Player Lives
int myLives=3;

//Enemy Lives
int enemyLifeSpan=0;



void drawPlayer(){
    if(flagColor==true){
        glColor4f(0.0f,1.0f,0.0f,0.0f);
    }
    else{
        glColor4f(1.0f,0.8f,0.9f,1.0f);
    }
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(100+playerFactorLeftRight, 150+playerFactorUpDown);
    glVertex2f(180+playerFactorLeftRight, 150+playerFactorUpDown);
    glVertex2f(180+playerFactorLeftRight, 160+playerFactorUpDown);
    glVertex2f(100+playerFactorLeftRight, 160+playerFactorUpDown);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(100+playerFactorLeftRight, 140+playerFactorUpDown);
    glVertex2f(180+playerFactorLeftRight, 140+playerFactorUpDown);
    glVertex2f(180+playerFactorLeftRight, 146+playerFactorUpDown);
    glVertex2f(100+playerFactorLeftRight,146+playerFactorUpDown);
    glEnd();
    
    
    glBegin(GL_POLYGON);
    glVertex2f(130+playerFactorLeftRight, 140+playerFactorUpDown);
    glVertex2f(130 + 50+playerFactorLeftRight, 140+playerFactorUpDown);
    glVertex2f(130 + 50+playerFactorLeftRight, 140 + 20+playerFactorUpDown);
    glVertex2f(130+playerFactorLeftRight, 140 + 20+playerFactorUpDown);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(140+playerFactorLeftRight, 140+playerFactorUpDown);
    glVertex2f(150+playerFactorLeftRight, 140+playerFactorUpDown);
    glVertex2f(145 +playerFactorLeftRight, 120+playerFactorUpDown);
    glEnd();
    
    glTranslatef(150+playerFactorLeftRight, 152+playerFactorUpDown, 0);
    glColor4f(0.0f,1.0f,1.0f,1.0f);
    GLUquadric *window = gluNewQuadric();
    gluDisk(window, 0, 5, 10, 10);
    
    glTranslatef(20, 0, 0);
    GLUquadric *window2 = gluNewQuadric();
    gluDisk(window2, 0, 5, 10, 10);
    
    glPopMatrix();
    
}

void drawEnemy(){
    glPushMatrix();
    glColor4f(0.9f,0.2f,0.3f,1.0f);

    glBegin(GL_POLYGON);
    glVertex2f(0+moveYaEnemy, 280);
    glVertex2f(50+moveYaEnemy, 280);
    glVertex2f(50+moveYaEnemy, 250);
    glVertex2f(0+moveYaEnemy, 250);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(20+moveYaEnemy, 300);
    glVertex2f(30+moveYaEnemy, 300);
    glVertex2f(25+moveYaEnemy, 280);
    glEnd();
    
    glTranslatef(25+moveYaEnemy, 250, 0);
    GLUquadric *pistol = gluNewQuadric();
    gluDisk(pistol, 0, 5, 10, 10);
  
    glEnd();
    glPopMatrix();
}



void drawEnemyBulletsGdeeda(){
    glBegin(GL_POLYGON);
    glColor4f(0.9f,0.2f,0.3f,1.0f);
    glVertex2f(20+moveYaEnemyBulletFelX, 255+moveYaEnemyBulletFelY);
    glVertex2f(30+moveYaEnemyBulletFelX, 255+moveYaEnemyBulletFelY);
    glVertex2f(30+moveYaEnemyBulletFelX, 260+moveYaEnemyBulletFelY);
    glVertex2f(20+moveYaEnemyBulletFelX, 260+moveYaEnemyBulletFelY);

    glEnd();
    
    
}


void drawPlayerBulletsGdeeda(){
    
    glBegin(GL_POLYGON);
    glColor4f(1.0f,0.8f,0.9f,1.0f);

    glVertex2f(130+moveYaPlayerBulletFelX, 140+moveYaPlayerBulletFelY);
    glVertex2f(140+moveYaPlayerBulletFelX, 140+moveYaPlayerBulletFelY);
    glVertex2f(140+moveYaPlayerBulletFelX, 145+moveYaPlayerBulletFelY);
    glVertex2f(130+moveYaPlayerBulletFelX, 145+moveYaPlayerBulletFelY);

    
    glEnd();
    
    glPopMatrix();

}




void drawPowerUp(){
    glPushMatrix();
    
    glBegin(GL_POLYGON);
    glColor4f(0.0f,1.0f,0.0f,1.0f);
    glVertex2f(0+randomPUP, 0+randomPUP);
    glVertex2f(5+randomPUP, 0+randomPUP);
    glVertex2f(5+randomPUP, 5+randomPUP);
    glVertex2f(0+randomPUP, 5+randomPUP);
    glEnd();
    
    glPopMatrix();

}





void drawPlayerLives(){
    
    if(myLives>0){
        glColor3f (0.0, 0.0, 1.0);
        glRasterPos2f(0, 280); //define position on the screen
        char *string = "Player Lives:";
        
        while(*string){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
        }
        
        
        glPushMatrix();
        glRasterPos2f(25, 280);
        glColor3f(0.0,0.0,1.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, myLives+48);
        glPopMatrix();
    }
    else if(enemyLifeSpan>=300 && myLives<=0){
        glColor3f (1.0, 0.0, 1.0);
                glRasterPos2f(150, 150); //define position on the screen
                char *string = "IT IS A TIE";
              
              while(*string){
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
              }
        
        playerFactorLeftRight=10000;
        moveYaEnemy=10000;
        moveYaPlayerBulletFelX=10000;
        moveYaEnemyBulletFelX=10000;
        randomPUP=10000;

        
    }
    else{
        glColor3f (1.0, 0.0, 1.0);
                glRasterPos2f(150, 150); //define position on the screen
                char *string = "YOU LOST";
              
              while(*string){
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
              }
        
        playerFactorLeftRight=10000;
        moveYaEnemy=10000;
        moveYaPlayerBulletFelX=10000;
        moveYaEnemyBulletFelX=10000;
        randomPUP=10000;

    }
}


void drawEnemyLives(){
   
    if(enemyLifeSpan<300){
        glColor3f (0.0, 0.0, 1.0);
        glRasterPos2f(0, 10); //define position on the screen
        char *string = "Enemy Lives:";
        
        while(*string){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
        }
        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(25, 12.5);
        glVertex2f(300, 12.5);
        
        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(25, 12.5);
        glVertex2f(25+enemyLifeSpan, 12.5);
        glEnd();
        
    }
    
    else if(enemyLifeSpan>=300 && myLives<=0){
        glColor3f (1.0, 0.0, 1.0);
                glRasterPos2f(150, 150); //define position on the screen
                char *string = "IT IS A TIE";
              
              while(*string){
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
              }
        
        
        playerFactorLeftRight=10000;
        moveYaEnemy=10000;
        moveYaPlayerBulletFelX=10000;
        moveYaEnemyBulletFelX=10000;
        randomPUP=10000;
        
    }
    else {
        glColor3f (1.0, 0.0, 1.0);
                glRasterPos2f(150, 150); //define position on the screen
                char *string = "YOU WON";
              
              while(*string){
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
              }
        
        
        playerFactorLeftRight=10000;
        moveYaEnemy=10000;
        moveYaPlayerBulletFelX=10000;
        moveYaEnemyBulletFelX=10000;
        randomPUP=10000;

        
    }
}
 


void enemyMove(int x){
    
        if (direction==0 && moveYaEnemyRightBounds<300) {
            moveYaEnemy+=10;
            moveYaEnemyRightBounds+=10;
            moveYaEnemyLeftBounds+=10;

        }
      
    
        else if (direction==1 && moveYaEnemyLeftBounds>0) {
            moveYaEnemy-=10;
            moveYaEnemyRightBounds-=10;
            moveYaEnemyLeftBounds-=10;
        }
    
        else if (direction==0 && moveYaEnemyRightBounds==300) {
            direction=1;
            moveYaEnemy-=10;
            moveYaEnemyRightBounds-=10;
            moveYaEnemyLeftBounds-=10;
        }
        
        else if (direction==1 && moveYaEnemyLeftBounds==0) {
            direction=0;
            moveYaEnemy+=10;
            moveYaEnemyRightBounds+=10;
            moveYaEnemyLeftBounds+=10;
        }
    glutPostRedisplay();
    glutTimerFunc(1000, enemyMove,0);
        
    
}



void enemyGeneratesBullets(int x){
    if (moveYaEnemyBulletFelY>=-300) {
        moveYaEnemyBulletFelY-=15;
    }
    else{
        moveYaEnemyBulletFelX=moveYaEnemy;
        moveYaEnemyBulletFelY=0;
    }
        glutPostRedisplay();
        glutTimerFunc(90, enemyGeneratesBullets,0);
    
}


void playerGeneratesBullets(int x){

        moveYaPlayerBulletFelY+=10;

    
        glutPostRedisplay();
        glutTimerFunc(40, playerGeneratesBullets,0);

}


void powerUpGenerated(int x){
    if (flag) {
       
            randomPUP=(rand() % (200 - 20)) + 20;
            flag=false;
            
    }
    
    else{
        
        randomPUP=(rand() % (200 - 2000)) + 2000;
        flag=true;
    }
    
    glutPostRedisplay();
    glutTimerFunc(10000, powerUpGenerated,0);

}

void powerDeActivated(int x){
        
            flagColor=false;
            flagGebto=false;
        
    
    glutPostRedisplay();

}

void powerUpAcquire(int x){
        if(flagGebto){
            randomPUP=2000;
            flagColor=true;
            glutTimerFunc(5000, powerDeActivated,0);
        }
        
    
    glutPostRedisplay();
    glutTimerFunc(10, powerUpAcquire,0);

}










void key(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_DOWN:
            
            if(boundsDown>0){
                boundsUp-=20;
                boundsDown-=20;
                playerFactorUpDown-=20;
            }glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
           
            if(boundsUp<220){
                boundsUp+=20;
                boundsDown+=20;
                playerFactorUpDown+=20;
            }glutPostRedisplay();
        break;
   case GLUT_KEY_RIGHT:
          

            if(boundsRight<300){
                boundsRight+=20;
                boundsLeft+=20;
                playerFactorLeftRight+=20;
            }glutPostRedisplay();
       break;
            
   case GLUT_KEY_LEFT:
            

            if(boundsLeft>0){
                boundsLeft-=20;
                boundsRight-=20;
                playerFactorLeftRight-=20;
            }glutPostRedisplay();
       break;
            
        case SPACE:
            if(moveYaPlayerBulletFelY>=300-moveYaPlayerBulletFelY ){
                
                moveYaPlayerBulletFelX=playerFactorLeftRight;
                moveYaPlayerBulletFelY=playerFactorUpDown;
                
            }
            glutPostRedisplay();
            break;
            
        
    }
    
    

    };

 

void ImpactOnEnemyLives(int x){
    int bulletCenterX=((140+130)/2)+moveYaPlayerBulletFelX;
    int EnemyCenterX=((0+50)/2)+moveYaEnemy;
    int bulletRadiusX=(140-130)/2;
    int EnemyRadiusX=(50-0)/2;
    
    
    int bulletCenterY=((140+145)/2)+moveYaPlayerBulletFelY;
    int EnemyCenterY=((280+250)/2);
    int bulletRadiusY=(145-140)/2;
    int EnemyRadiusY=(280-250)/2;
    

    if(bulletCenterX<EnemyCenterX+EnemyRadiusX && bulletCenterX>EnemyCenterX-EnemyRadiusX &&
       bulletCenterY<EnemyCenterY+EnemyRadiusY && bulletCenterY>EnemyCenterY-EnemyRadiusY ){
        enemyLifeSpan+=50;
        moveYaPlayerBulletFelY=300;
    }
    
    
        glutPostRedisplay();
        glutTimerFunc(100, ImpactOnEnemyLives,0);
    
}




void ImpactOnPlayerLives(int x){
    int bulletCenterX=((20+30)/2)+moveYaEnemyBulletFelX;
    int playerCenterX=((180+100)/2)+playerFactorLeftRight;
    int bulletRadiusX=(30-20)/2;
    int playerRadiusX=(180-100)/2;
    
    
    int bulletCenterY=((255+260)/2)+moveYaEnemyBulletFelY;
    int playerCenterY=((160+140)/2)+playerFactorUpDown;
    int playerRadiusY=(160-140)/2;
    int bulletRadiusY=(260-255)/2;
    

    if(bulletCenterX<playerCenterX+playerRadiusX && bulletCenterX>playerCenterX-playerRadiusX &&
       bulletCenterY<playerCenterY+playerRadiusY && bulletCenterY>playerCenterY-playerRadiusY && myLives>0 &&flagGebto==false){
        myLives--;
        moveYaEnemyBulletFelY=0;

    }
    else if(myLives<=0){
        glColor3f (1.0, 0.0, 1.0);
                glRasterPos2f(150, 150); //define position on the screen
                char *string = "YOU LOST";
              
              while(*string){
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
              }
        
    }
    
        glutPostRedisplay();
        glutTimerFunc(100, ImpactOnPlayerLives,0);
    
}
    



void ImpactOffPowerUps(int x){
    
    int powerUpCenterX=((0+5)/2)+randomPUP;
    int powerUpRadiusX=(5-0)/2;
    int powerUpCenterY=((5+0)/2)+randomPUP;
    int powerUpRadiusY=(5-0)/2;

    int playerCenterRectangleX=((180+100)/2)+playerFactorLeftRight;
    int playerRadiusRectangleX=(180-100)/2;
    int playerCenterRectangleY=((160+140)/2)+playerFactorUpDown;
    int playerRadiusRectangleY=(160-140)/2;
    
    int playerCenterTriangleX=((140+150)/2)+playerFactorLeftRight;
    int playerRadiusTriangleX=(150-140)/2;
    int playerCenterTriangleY=((120+140)/2)+playerFactorUpDown;
    int playerRadiusTriangleY=(140-120)/2;
    
    
    

    if((powerUpCenterX<playerCenterRectangleX+playerRadiusRectangleX && powerUpCenterX>playerCenterRectangleX-playerRadiusRectangleX &&
        powerUpCenterY<playerCenterRectangleY+playerRadiusRectangleY && powerUpCenterY>playerCenterRectangleY-playerRadiusRectangleY) ||
       (powerUpCenterX<playerCenterTriangleX+playerRadiusTriangleX && powerUpCenterX>playerCenterTriangleX-playerRadiusTriangleX &&
        powerUpCenterY<playerCenterTriangleY+playerRadiusTriangleY && powerUpCenterY>playerCenterTriangleY-playerRadiusTriangleY)){
        flagGebto=true;
        flagColor=true;
        
    }
    
    
    
    
        glutPostRedisplay();
        glutTimerFunc(1, ImpactOffPowerUps,0);
    
}


void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawPlayer();
    drawEnemy();
    drawEnemyBulletsGdeeda();
    drawPlayerBulletsGdeeda();
    drawPowerUp();
    drawPlayerLives();
    drawEnemyLives();
    
    glFlush();
}



int main(int argc, char** argr) {
  glutInit(&argc, argr);

  glutInitWindowSize(2000, 300);
  glutInitWindowPosition(300, 300);

  glutCreateWindow("2D space invaders");
  glutDisplayFunc(Display);

    
    glutSpecialFunc(key);

    glutTimerFunc(0, enemyMove, 0); // sets the Timer handler function; which runs every `Threshold` milliseconds (1st argument)
    glutTimerFunc(0, enemyGeneratesBullets, 0); // sets the Timer handler function; which runs every `Threshold` milliseconds (1st argument)

    glutTimerFunc(0, powerUpGenerated, 0);
    glutTimerFunc(0, powerUpAcquire, 0);

    
    glutTimerFunc(0, playerGeneratesBullets, 0);


    glutTimerFunc(0, ImpactOnPlayerLives, 0);
    glutTimerFunc(0, ImpactOnEnemyLives, 0);
    glutTimerFunc(0, ImpactOffPowerUps, 0);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glClearColor(0, 0, 0, 0);
  gluOrtho2D(0, 300, 0, 300);
    
    
  glutMainLoop();
    
    
}
