#include"drawLibFamRyabiy.h"



float fun(float x){
    float y = 0.0;
    if(x>2)
        y = 2*x-15;
    else if (x<2)
        y = 3* fabs(x-1)-8;   //fabs - вещественный модуль
    else y = 5;

    return y;
}


/*
float fun(float x){             //пример
    float y = 0.0;
    if(x>0)
        y = 2*x-10;
    else if (x<0)
        y = 2* fabs(x)-1;   //fabs - вещественный модуль
    else y = 0;

    return y;
}
    */
void drawGraphixs(){
    glPushMatrix();

    glScaled(0.02,0.02,0);

    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2d(-500,0);   //сетка
    glVertex2d(500,0);

    glVertex2d(0,-500);
    glVertex2d(0,500);

    glEnd();

    glBegin(GL_LINE_STRIP);
    for(int i=1;i<=40;i++){                     //дз 1
        glColor3f(1,0.0117,0.24313);
        float y =-0.1*i*i+2*i+1 ;
            glVertex2d(i,fun(i));
    }
    glEnd();


    /*
    glBegin(GL_LINE_STRIP);
    for(int i=-40;i<=40;i++){
        glColor3f(1,0.0117,0.24313);            //дз 2
        float y =(2+i)*(2+i)+3*i ;
            glVertex2f(i,y);
    }



    glBegin(GL_LINE_STRIP);
    for(int i=1;i<=40;i++){
        glColor3f(1,0.0117,0.24313);            //дз 3
        float y =sqrt(15+4/i)+13*i+sin(3*i+13);
            glVertex2f(i,y);
    }


    */
        /*
    glBegin(GL_LINE_STRIP);
    for(float i=0;i<4*M_PI;i+=0.1){         //круг
        glColor3d(i/2,i/25,i/55);
        glVertex2d(cos(.9*i),sin(.9*i));

        }

        */

    /*
    glBegin(GL_LINE_STRIP);                 //график(1)(кардиограмма)
    for(float i=-100;i<=100;i+=0.1){
        glColor3f(1,0.0117,0.24313);
        float y =(exp(i+1))/sin(i*i) ;
            glVertex2f(i,y);
    }




    glBegin(GL_LINE_STRIP);                 //график(2)(парабола)
    for(float i=-100;i<=100;i+=0.1){
        glColor3f(1,0.0117,0.24313);
        float y =i*i+(i+1)*(i+1) ;
            glVertex2f(i,y);
    }



    glBegin(GL_LINE_STRIP);                 //график(3)(петля)
    for(float i=-100;i<=100;i+=0.1){
        glColor3f(1,0.0117,0.24313);
        float y =i-i*i*i ;
            glVertex2f(i*i,y);
    }

    glBegin(GL_LINE_STRIP);                 //график(4)(солнце)
    for(float i=-100;i<=100;i+=0.1){
        glColor3f(1,0.0117,0.24313);
        float x =cos(i)+(cos(20*i)*cos(i)*0.4) ;
        float y =sin(i)+(cos(20*i)*sin(i)*0.4) ;
            glVertex2f(x,y);
    }

    */



    glPopMatrix();
}
void drawSunLight(Figure fig){
    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glScalef(fig.q,fig.w,1);

    glBegin(GL_LINES);

    for(int i=0;i<360;i+=15){
        glColor3d(0.8,0.7803,0.133333);
        glVertex2d(sin(i),cos(i));
        glVertex2d(-sin(i),-cos(i));
        }

    glEnd();

    glPopMatrix();

}
void drawCar(Figure fig){

    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glScalef(fig.q,fig.w,1);
    glBegin(GL_QUADS);              //машина

    glColor3f(1,0.0117,0.24313);
    glVertex2d(2-0.2,2);            //корпус
    glVertex2d(2-0.2,-2);
    glVertex2d(-6+0.2,-2);
    glVertex2d(-6+0.2,2);

    glVertex2d(-6+0.2,2-1.8);            //капот
    glVertex2d(-6+0.2,-2);
    glVertex2d(-6-2.6,-2);
    glVertex2d(-6-2.6,2-1.8);

    glVertex2d(2-0.2,2-1.5);            //корпус(зад)
    glVertex2d(2-0.2,-2);
    glVertex2d(4+0.2,-2);
    glVertex2d(4+0.2,2-1.5);

    glColor3f(0.6862,0.8549,0.98823);
    glVertex2d(-5.77+0.2,2);            //ОКНО (переднее)
    glVertex2d(-5.77+0.2,2-1.8);
    glVertex2d(-5.77-2.3,2-1.8);
    glVertex2d(-5.77,2);

    glVertex2d(-1+0.2,2);            //ОКНО (заднее)
    glVertex2d(-1+0.2,2-1.8);
    glVertex2d(-4-0.4,2-1.8);
    glVertex2d(-4-0.4,2);


    glColor3f(0,0,0);
    glVertex2d(2-0.2,2);            //крыша
    glVertex2d(2-0.2,2+0.2);
    glVertex2d(-6+0.2,2+0.2);
    glVertex2d(-6+0.2,2);

    glEnd();

    glTranslated(-5.7,-1.6,0);
    glBegin(GL_LINES);              //Колесо - диск-перед (цикл)

    for(int i=-360;i<360;i+=1){
        glColor3d(0,0,0);
        glVertex2d(sin(i)*1.3,cos(i)*1.3);
        glVertex2d(-sin(i)*1.3,-cos(i)*1.3);

        glColor3d(1,1,1);
        glVertex2d(sin(i),cos(i));
        glVertex2d(-sin(i),-cos(i));


        }

    glEnd();


    glTranslated(6.7,0,0);
    glBegin(GL_LINES);              //Колесо - диск-зад (цикл)

    for(int i=-360;i<360;i+=1){
        glColor3d(0,0,0);
        glVertex2d(sin(i)*1.3,cos(i)*1.3);
        glVertex2d(-sin(i)*1.3,-cos(i)*1.3);

        glColor3d(1,1,1);
        glVertex2d(sin(i),cos(i));
        glVertex2d(-sin(i),-cos(i));


        }

    glEnd();

    glPopMatrix();

}



void drawTree(Figure fig){
    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glScalef(fig.q,fig.w,1);

    glBegin(GL_QUADS);      //ствол дерева
    glVertex2f(.2,.6);
    glColor3f(0.72156,0.3647,0.26274);
    glVertex2f(.4,.6);
    glVertex2f(.4,-.2);
    glColor3f(0.45098,0.258823,0.133333);
    glVertex2f(.2,-.2);

    glEnd();

    glTranslated(0.3,0.45,0);            //травка верх (цикл)
    glScaled(0.4,0.4,1);
    glBegin(GL_LINES);

    for(int i=-360;i<360;i+=1){
       glColor3f(0.11764,0.75294,0.23529);
        glVertex2d(sin(i),cos(i));
        glVertex2d(-sin(i),-cos(i));
        }

    glEnd();


    glPopMatrix();
}

void drawShrabs(Figure fig){

    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glScalef(fig.q,fig.w,1);



    glBegin(GL_QUADS);
    glColor3f(0.188,0.517,0.274);
    glVertex2f(-.3+0.13,-.4+0.25);
    glVertex2f(-.3+0.13,-.4-0.1);            //куст верхушка
    glVertex2f(1.1-0.13,-.4-0.1);
    glVertex2f(1.1-0.13,-.4+0.25);

    glColor3f(0.188,0.517,0.274);
    glVertex2f(-.3+0.02,-.4+0.1);
    glVertex2f(-.3+0.02,-.4-0.2);            //куст
    glVertex2f(1.1-0.02,-.4-0.2);
    glVertex2f(1.1-0.02,-.4+0.1);

    glEnd();
    glPopMatrix();
}

void drawRotateRoad(){

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.40,0.42,0.40);
    glVertex2f(-.3+0.03,-.4+0.1);
    glVertex2f(-.3+0.03,-.4+0.27);            //дорога горизонтальная
    glVertex2f(1.1,-.4+0.27);
    glVertex2f(1.1,-.4+0.1);

    glPopMatrix();

    glEnd();

}



void drawRoad(Figure fig){

    glPushMatrix();

    glTranslated(fig.x,fig.y,0);

    glBegin(GL_QUADS);
    glColor3f(0.40,0.42,0.40);
    glVertex2f(-.3-0.2,.6-0.9);
    glVertex2f(-.3-0.2,.4-0.17);            //дорога вертикальная
    glVertex2f(-.3+0.03,.4-0.17);
    glVertex2f(-.3+0.03,.6-0.9);

    glEnd();

    glPopMatrix();
}

void drawGrass(){
    glPushMatrix();


    glBegin(GL_QUADS);                //трава
    glColor3f(0.60,0.80,0.20);
    glVertex2f(.12+0.9,.4+0.06);
    glColor3f(0.60,0.80,0.20);
    glVertex2f(-.5-0.9,.4+0.06);
    glColor3f(0.188,0.517,0.274);
    glVertex2f(-.5-0.9,-.6+0.83);
    glColor3f(0.188,0.517,0.274);
    glVertex2f(.12+0.9,-.6+0.83);


    glEnd();
    glPopMatrix();

}

void drawEarth(){
    glPushMatrix();


    glBegin(GL_QUADS);
    glColor3f(0.4,0.22,0.14);           //земля
    glVertex2f(.12+0.9,-.4+0.64);
    glVertex2f(-.5-0.9,-.4+0.64);
    glVertex2f(-.5-0.9,-.6-0.9);
    glVertex2f(.12+0.9,-.6-0.9);

    glEnd();
    glPopMatrix();

}


void drawSky(){
    glPushMatrix();


    glBegin(GL_QUADS);
    glColor3f(0,150,255);
    glVertex2f(-.5-0.9,.6+0.9);
    glColor3f(0.03137,0.14509,0.4039);
    glVertex2f(.12+0.9,.6+0.9);
    glColor3f(0.733333,0.4235,0.5411);
    glVertex2f(.12+0.9,-.4+0.64);
    glVertex2f(-.5-0.9,-.4+0.64);


    glEnd();
    glPopMatrix();

}
void drawCat(Figure fig){
    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glRotatef(0+fig.a,0,0,1);
    glScalef(fig.q,fig.w,1);

       glBegin(GL_TRIANGLES);          //тело
       glColor3f(0.145098, 0.156862, 0.31372);
       glVertex2f(-.2, -.4);
       glVertex2f(.2, -0.4);
       glColor3f(1, 1, 1);
       glVertex2f(0, .2);


       glColor3f(0.145098, 0.156862, 0.31372);           //голова
       glVertex2f(-.2, .3 + 0.2);
       glVertex2f(.2, 0.3 + 0.2);
       glColor3f(1, 1, 1);
       glVertex2f(0, .2);

       glColor3f(1, 1, 1);          //хвост
       glVertex2f(.2, -.4);
       glVertex2f(.2 + 0.2, .0);
       glColor3f(0.145098, 0.156862, 0.31372);
       glVertex2f(.2 + 0.15, 0.015 + 0.2);

       glColor3f(0.145098, 0.156862, 0.31372);          // ушко left
       glVertex2f(-.2, .3 + 0.2);
       glColor3f(1, 1, 1);
       glVertex2f(.0 - 0.1, .3 + 0.4);
       glColor3f(0.145098, 0.156862, 0.31372);
       glVertex2f(.0, .3 + 0.2);

       glColor3f(0.145098, 0.156862, 0.31372);          // ушко right
       glVertex2f(.2, .3 + 0.2);
       glColor3f(1, 1, 1);
       glVertex2f(.0 + 0.1, .3 + 0.4);
       glColor3f(0.145098, 0.156862, 0.31372);
       glVertex2f(.0, .3 + 0.2);

        /*
       glColor3f(.255, .90, .15);    //глаз левый
       glVertex2f(-.2, .5-0.05);
       glVertex2f(-.1, .4-0.05);
       glVertex2f(.0, .5-0.05);

       glColor3f(.255, .90, .15);    //глаз  правый
       glVertex2f(.2, .5-0.05);
       glVertex2f(.1, .4-0.05);
       glVertex2f(.0, .5-0.05);
        */
       glColor3f(fig.r, fig.g,fig.b);    //глаз левый
       glVertex2f(-.2, .5-0.05);
       glVertex2f(-.1, .4-0.05);
       glVertex2f(.0, .5-0.05);

       glColor3f(fig.r, fig.g,fig.b);    //глаз  правый
       glVertex2f(.2, .5-0.05);
       glVertex2f(.1, .4-0.05);
       glVertex2f(.0, .5-0.05);
glEnd();


    glPopMatrix();

}

void drawHeart(float x, float y, float q, float w){

    glPushMatrix();

    glTranslated(x,y,0);
    glScalef(q,w,1);

    glBegin(GL_QUADS);
    glColor3f(255 , 0, 0);
    glVertex2f(-.2,.0);
    glVertex2f(.0,.2);
    glVertex2f(.2,.0);
    glVertex2f(.0,-.2);

    glVertex2f(-.2,.0);
    glVertex2f(-.4,.2);
    glVertex2f(-.6,.0);
    glVertex2f(-.4,-.2);

    glVertex2f(-.2,.0);
    glVertex2f(-.4,-.2);
    glVertex2f(-.2,-.4);
    glVertex2f(.0,-.2);

    glColor3f(1 , 1, 1);
    glVertex2f(-.2+0.2,0.2-0.15);
    glVertex2f(-.2+0.2,-0.2+0.15);
    glVertex2f(-.1+0.2,-0.2+0.15);
    glVertex2f(-.1+0.2,0.2-0.15);

    glColor3f(1 , 1, 1);
    glVertex2f(-.2+0.2,0.2-0.17);
    glVertex2f(-.2+0.2,-0.2+0.17);
    glVertex2f(-.1+0.2,-0.2+0.17);
    glVertex2f(-.1+0.2,0.2-0.17);

    glEnd();

    glPopMatrix();
}

void drawBonny(Figure fig){

    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glScalef(fig.q,fig.w,1);

    glBegin(GL_QUADS);
    glColor3f(1 , 1, 1);
    glVertex2f(-.2,.6);         // шея+грудь
    glVertex2f(-.2,-.2);
    glVertex2f(.1,-.2);
    glVertex2f(.1,.6);

    glVertex2f(-.2,-.2);        //передняя лапка
    glVertex2f(.1+0.05,-.2);
    glVertex2f(.1+0.05,-.2-0.05);
    glVertex2f(-.2,-.2-0.05);

    glVertex2f(-.2-0.1,.6-0.08);    //живот
    glVertex2f(-.2-0.1,-.2+0.08);
    glVertex2f(.1,-.2+0.08);
    glVertex2f(.1,.6-0.08);

    glVertex2f(-.2-0.1,.6);         //живот+туловище
    glVertex2f(-.2-0.1,-.2-0.05);
    glVertex2f(-.2-0.4,-.2-0.05);
    glVertex2f(-.2-0.4,.6);

    glVertex2f(-.2-0.1,.4);         //зад
    glVertex2f(-.2-0.1,-.2-0.05);
    glVertex2f(-.2-0.65,-.2-0.05);
    glVertex2f(-.2-0.65,.4);

    glVertex2f(-.2-0.65,.3);         //хвост
    glVertex2f(-.2-0.65,-.2+0.15);
    glVertex2f(-.2-0.75,-.2+0.15);
    glVertex2f(-.2-0.75,.3);


    glVertex2f(.1,.3);         // голова
    glVertex2f(.6,.3);
    glVertex2f(.6,.7);
    glVertex2f(.1,.7);

    glColor3f(0 , 0, 0);
    glVertex2f(.1+0.2,.5);         // глаз
    glVertex2f(.1+0.3,.5);
    glVertex2f(.1+0.3,.5+0.1);
    glVertex2f(.1+0.2,.5+0.1);

    glColor3f(255 , 0, 255);
    glVertex2f(.1+0.5,.4);         // нос
    glVertex2f(.1+0.6,.4);
    glVertex2f(.1+0.6,.4+0.1);
    glVertex2f(.1+0.5,.4+0.1);

    glColor3f(1 , 1, 1);
    glVertex2f(.1,.7);         // уши
    glVertex2f(.1+0.3,.7);
    glVertex2f(.1+0.3,.7+0.4);
    glVertex2f(.1,.7+0.4);

    glVertex2f(.1,.7+0.3);         // уши(задняя часть)
    glVertex2f(.1-0.3,.7+0.3);
    glVertex2f(.1-0.3,.7+0.1);
    glVertex2f(.1,.7+0.1);

glEnd();

glPopMatrix();

}
/*
    @return void;
    Рендер дома
    args: float r float g float b - цвета дома
*/



void drawHouse(Figure fig){

    glPushMatrix();

    glTranslated(fig.x,fig.y,0);
    glScalef(fig.q,fig.w,1);

    glBegin(GL_QUADS);               //коробка
    glColor3f(0.6313, 0.1372, 0.07058);
    glVertex2f(-.8-0.5,.4);
    glVertex2f(-.8-0.5,-.4);
    glVertex2f(-.4,-.4);
    glVertex2f(-.4,.4);


    glColor3f(0.69411 , 0.31764,0.14117);
    glVertex2f(-.7-0.09,.3-0.3);           //дверь
    glVertex2f(-.7-0.09,-.4);
    glVertex2f(-.5,-.4);
    glVertex2f(-.5,.3-0.3);

    glColor3f(1,1,1);         //труба
    glVertex2f(-.7,.6);
    glVertex2f(-.7,-.1+0.24);
    glVertex2f(-.5,-.1+0.24);
    glVertex2f(-.5,.6);

    glColor3f(0.9294,0.28235,0.18823);          //крыша
    glVertex2f(-.8-0.6,.4);
    glVertex2f(-.8-0.6,-.1+0.24);
    glVertex2f(-.4+0.1,-.1+0.24);
    glVertex2f(-.4+0.1,.4);

    glColor3f(1,0.803921, 0.09803);          //окно
    glVertex2f(-.8-0.4,.5-0.45);
    glVertex2f(-.8-0.4,-.1-0.1);
    glVertex2f(-.5-0.4,-.1-0.1);
    glVertex2f(-.5-0.4,.5-0.45);

    glEnd();

    glPopMatrix();

}

void drawSun(Figure fig){

    glPushMatrix();

    glTranslated(fig.x,fig.y,0);

    glScalef(fig.q,fig.w,1);

        glBegin(GL_QUADS);          //солнце
        glColor3f(1,0.6901,0.02352);
        glVertex2f(-.6,.4);
        glColor3f(1,0.6901,0.02352);
        glVertex2f(-.6,-.4);
        glVertex2f(.4,-.4);
        glColor3f(0.97,0.95,0.168);
        glVertex2f(.4,.4);


    glEnd();


    glPopMatrix();
}

void drawHappyEnd(){
    glPushMatrix();

    glTranslated(-0.3,0,0);
    glScalef(0.5,0.5,1);
    glBegin(GL_QUADS);
    //W
    glVertex2f(-.6,.6);
    glVertex2f(-.4,.6);
    glVertex2f(-.4,-.4);
    glVertex2f(-.6,-.4);

    glVertex2f(-.4,-.4);
    glVertex2f(0.4,-.4);
    glVertex2f(0.4,-.2);
    glVertex2f(-.4,-.2);

    glVertex2f(0.2,.6);
    glVertex2f(0.4,.6);
    glVertex2f(0.4,-.4);
    glVertex2f(0.2,-.4);

    glVertex2f(-0.2,.6);
    glVertex2f(0,.6);
    glVertex2f(0,-.4);
    glVertex2f(-0.2,-.4);
    //I
    glVertex2f(0.8,.6);
    glVertex2f(0.6,.6);
    glVertex2f(0.6,-.4);
    glVertex2f(0.8,-.4);
    //N
    glVertex2f(0.8+0.4,.6);
    glVertex2f(0.6+0.4,.6);
    glVertex2f(0.6+0.4,-.4);
    glVertex2f(0.8+0.4,-.4);

    glVertex2f(0.8+0.9,.6);
    glVertex2f(0.6+0.9,.6);
    glVertex2f(0.6+0.9,-.4);
    glVertex2f(0.8+0.9,-.4);

    glVertex2f(0.8+0.4,.6);
    glVertex2f(0.6+0.4,.6);
    glVertex2f(0.6+0.9,-.4);
    glVertex2f(0.8+0.9,-.4);

glEnd();

    glPopMatrix();
}
