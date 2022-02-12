#ifndef DRAWLIBFAMRYABIY_H
#define DRAWLIBFAMRYABIY_H

#include <GL/glut.h>
#include <cmath>

struct Figure{
    float x,y;
    float q,w;
    float a;
    bool isRight = true;
    float color [3];
    bool  isGetFlower[3] ={false, false, false};
    float r,g,b;
};

void drawHappyEnd();
void drawSunLight(Figure fig);
void drawGraphixs();
void drawCar(Figure fig);
void drawTree(Figure fig);
void drawShrabs(Figure fig);
void drawRotateRoad();
void drawRoad(Figure fig);
void drawGrass();
void drawEarth();
void drawSky();
void drawCat(Figure fig);
void drawHeart(float x,float y, float q, float w);
void drawHouse(Figure fig);
void drawSun(Figure fig);
void drawBonny(Figure fig);


#endif // DRAWLIBFAMRYABIY_H
