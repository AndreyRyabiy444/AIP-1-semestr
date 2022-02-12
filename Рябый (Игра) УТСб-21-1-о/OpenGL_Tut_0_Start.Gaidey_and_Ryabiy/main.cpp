#include <GL/glut.h>
#include <cmath>
#include"drawLibFamRyabiy.h"



float pos_x=0, pos_y=0;
bool isRight = true;
float angle = 0.0;

bool isGetFlower[3] ={false, false, false}; //массив сердечек

float heart_x = 0, heart_y = 0;
int countHeart = 0;


bool isGlassColor [2] = {false,false};
float r,g,b;
/*

    @return void;
    Рисует кота
*/


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна здесь жить


/*
    glPushMatrix();

    drawSky();
    drawEarth();
    drawGrass();
    drawRoad(0,0);
    drawRotateRoad();
    drawRoad(0.8,0);

    //for(int i=0;i<360;i+=10)
       //drawSun(1*sin(i*M_PI/180),0.2*cos(i*M_PI/180),0.2,0.2);   //drawSun(0,0.9,0.2,0.2); солнце начальная координата + функция

    drawShrabs(-.5-0.10,-.3,0.7,0.7);
    drawCar(1.5,0.3,0.2-0.1,0.2-0.1);

    //for(int i=0;i<4;i++)
    //drawBonny(0.3*i+0.9,-0.2*i+0.4,0.1,0.1);                 //drawBonny(1,0-0.53,0.3,0.3);начальная координата зайца+ фунцкция



    drawHouse(1-0.04,1.5-0.35,1,1);

   // for(int i=0;i<4;i++)

       // drawCat(-0.5*i/2+0.6,0.45*i/2+0.9,0.3,0.3);             //drawCat(0-0.2,0+0.5,0.5,0.5); начальная координата кота+ функция
        drawCat(0-0.2,0+0.5,0.5,0.5);

    drawHeart(0,0-0.2,0.2,0.2);
    drawHeart(0-0.12,0-0.43,0.2,0.2);
    drawHeart(0+0.2,0-0.5,0.2,0.2);
    drawHeart(0+0.4,0-0.23,0.2,0.2);
    drawHeart(0+0.65,0-0.33,0.2,0.2);
    drawHeart(0+0.75,0-0.2,0.2,0.2);
    drawHeart(0+0.2,0-0.22,0.2,0.2);
    drawHeart(0+0.48,0-0.51,0.2,0.2);

    drawSunLight(1.1,1.6,0.3,0.3);
    drawTree(1.5-0.04,1-0.045,1,1);
    drawBonny(1,0-0.53,0.3,0.3);
    drawCat(0-0.2,0+0.5,0.5,0.5);

    //drawSun(0,0.9,0.2,0.2);

    for(int i=0;i<3;i++)
    drawBonny(i*0.1+1.1,i*0.2-0.8,0.1,0.1);

    glPopMatrix();


    //гарфики

   glPushMatrix();

   drawGraphixs();


   glPopMatrix();
*/
    //game

    glPushMatrix();         //кот ходунок

    drawSky();
    drawEarth();
    drawGrass();

    Figure Road1,Road2,Road3;   //дорога
    Road1.x=0.0;Road1.y=0;
    drawRoad(Road1);
    Road2.x=0.9;Road2.y=-0.4;
    drawRoad(Road2);
    Road3.x=0.9;Road3.y=-0.7;
    drawRoad(Road3);
    drawRotateRoad();           //Горизонтальная дорога

    Figure Shrabs1,Shrabs2;
    Shrabs1.x=-0.6;Shrabs1.y=-0.3;
    Shrabs1.q=0.8;Shrabs1.w=0.8;
    drawShrabs(Shrabs1);        //куст снизу
    Shrabs2.x=-1.4;Shrabs2.y=0.25;
    Shrabs2.q=0.7;Shrabs2.w=0.7;
    drawShrabs(Shrabs2);        //куст сверху


    Figure Tree1;
    Tree1.x=0.35;Tree1.y=0.43;
    Tree1.q=1;Tree1.w=1;
    drawTree(Tree1);            //дерево


    Figure SunLight1;
    SunLight1.x=0.1;SunLight1.y=0.8;
    SunLight1.q=0.3;SunLight1.w=0.3;
    drawSunLight(SunLight1);    //солнце


    Figure House1;
    House1.x=0.07;House1.y=0.51;
    House1.q=0.7;House1.w=0.7;
    drawHouse(House1);          //дом


    Figure Car1;
    Car1.x=0.75;Car1.y=0;
    Car1.q=0.07;Car1.w=0.07;
    drawCar(Car1);              //Машина


    Figure Bonny1,Bonny2,Bonny3,Bonny4,Bonny5,Bonny6,Bonny7;
    Bonny1.x=-0.7;Bonny1.y=-0.53;
    Bonny1.q=0.15;Bonny1.w=0.15;
    drawBonny(Bonny1);          //заяц

    Bonny2.x=-0.18;Bonny2.y=0.18;       //зайчик движение
    Bonny2.q=0.08;Bonny2.w=0.08;

    Bonny3.x=-0.1;Bonny3.y=-0.11;
    Bonny3.q=0.08;Bonny3.w=0.08;

    Bonny4.x=0.3;Bonny4.y=-0.3;
    Bonny4.q=0.08;Bonny4.w=0.08;

    Bonny5.x=0.1;Bonny5.y=-0.5;
    Bonny5.q=0.08;Bonny5.w=0.08;

    Bonny6.x=-0.3;Bonny6.y=-0.55;
    Bonny6.q=0.08;Bonny6.w=0.08;

    Bonny7.x=-0.59;Bonny7.y=-0.56;
    Bonny7.q=0.08;Bonny7.w=0.08;

    drawHeart(heart_x,heart_y,0.2,0.2);
    /*
    Figure Heart4;//drawHeart(heart_x,heart_y,0.2,0.2);
    Heart4.x=heart_x;Heart4.y=heart_y;
    Heart4.q=0.2;Heart4.w=0.2;
    drawHeart(Heart4);          //сердце(random)
*/

    Figure Cat1;
    if(isRight)
        glRotatef(0,0,0,1);
    Cat1.x=-0.3+pos_x;Cat1.y=pos_y;
    Cat1.q=0.3;Cat1.w=0.3;
    Cat1.a=angle;
    Cat1.r=r;Cat1.g=g;Cat1.b=b;
    drawCat(Cat1);              //кот

    if(!isGetFlower[0])
     drawHeart(0.2,-0.6,0.2,0.2);      //sharbs 1 heart floor right

    if(!isGetFlower[1])
     drawHeart(-0.3,-0.6,-0.2,0.2); //sharps 1 heaert floor

    if(!isGetFlower[2])             //sharbs left 2 heart
     drawHeart(-0.78,0,0.2,0.2);


    if ((countHeart >= 3)&&(countHeart <= 6))
        drawBonny(Bonny2);

    if ((countHeart >= 7)&&(countHeart <= 10))
        drawBonny(Bonny3);

    if ((countHeart >= 11)&&(countHeart <= 14))
        drawBonny(Bonny4);

    if ((countHeart >= 15)&&(countHeart <= 18))
        drawBonny(Bonny5);

    if ((countHeart >= 19)&&(countHeart <= 21))
        drawBonny(Bonny6);

    if ((countHeart >= 22))
        drawBonny(Bonny7);
    if ((countHeart >= 23))
         drawHappyEnd();

    glPopMatrix();
    /*
    glPushMatrix();

    drawGraphixs();


    glPopMatrix();
*/
    glutSwapBuffers();


}
void processKeys(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
    srand (7);      //генератор семи
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lesson - 0, Start");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}


void processKeys(unsigned char key, int x, int y){
// вправо В
    /*if(key == 100){
        pos_x = pos_x + 0.1;
    }
    if(key == 97){
        pos_x = pos_x - 0.1;

    }//влево Ф
*/


    if(key == 100 ){            //движение в
        pos_x = pos_x + 0.1;
        isRight = true;
    }
    if(key == 119){             //движение ц
        pos_y += 0.1;
        isRight = false;
    }
    if(key == 115){             //движение ы
        pos_y -= 0.1;
        isRight = false;
    }

    if(key == 97) {
        pos_x = pos_x - 0.1;    //движение ф
        isRight = false;
    }

    if(key == 113){             //наклон у
        angle += 1; // angle = angle +1;

    }

    if(key == 101){             //наклон й
        angle -= 1; // angle = angle -1;

    }

    if(key == 13)               //выход enter
        exit(0); // close app
     //Логика программы

    if ((pos_x >= 0.5) && (pos_x<= 0.65) && (pos_y >=-0.7)&& (pos_y <= -0.6))
    {
        isGetFlower[0] = true; //стирание сердечка 1
         countHeart++;
    }

    if ((pos_x >= 0.0) && (pos_x<= 0.2) && (pos_y >=-0.7)&& (pos_y <= -0.6))
    {
        isGetFlower[1] = true; //стирание сердечка 2
         countHeart++;
    }

    if ((pos_x >= -0.6) && (pos_x<= -0.4)&& (pos_y >=-0.1)&& (pos_y <= 0.1))
    {
        isGetFlower[2] = true; //стирание сердечка 3
         countHeart++;
    }


    if ((pos_x>=heart_x+0.2)&& (pos_x<=heart_x+0.3) && (pos_y >=heart_y-0.1)&& (pos_y <=heart_y+0.1))
    {
        countHeart++;                   //рандомное рисование сердечка
        heart_x=2*(float)rand()/RAND_MAX-1;
        heart_y=2*(float)rand()/RAND_MAX-1;
    }


    if ((pos_x>0.3)&&(pos_y>0)&&(pos_x<8)&&(pos_y<8)) //цвет глаз
    {
        r=0.10196; //тёмно-синий
        g=0.2823;
        b=0.4627;
    }
        if ((pos_x<0.3)&&(pos_y>0)&&(pos_x>-8)&&(pos_y<8))
        {
            r=1; //;желтый
            g=1;
            b=0;
        }


     if ((pos_x>0.3)&&(pos_y<0)&&(pos_x<8)&&(pos_y<0)) //цвет глаз
    {
        r=255; //красный
        g=0;
        b=0;
    }
        if ((pos_x<0.3)&&(pos_y<0)&&(pos_x>-8)&&(pos_y<0))
        {
            r=.255; //;зелёный
            g=.90;
            b=.15;
        }



    glutPostRedisplay(); // отрисовка
}
