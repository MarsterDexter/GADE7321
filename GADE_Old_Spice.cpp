#include <GL/glew.h>
#include <iostream>
#include "gl/freeglut.h"
#include "ChessBoard.h"
#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "glm/glm.hpp"
#include "Terrain.h"
#include <math.h>
//__Chess--Peices__//
#include "PrimativeGameObject.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"


//__White--Peices__//
King* wking;
Queen* wqueen;
Bishop* wbishop01;
Bishop* wbishop02;
Rook* wrook01;
Rook* wrook02;
Kinght* wkinght01;
Kinght* wkinght02;

//__WPawn__//
Pawn* wpawn00;
Pawn* wpawn01;
Pawn* wpawn02;
Pawn* wpawn03;
Pawn* wpawn04;
Pawn* wpawn05;
Pawn* wpawn06;
Pawn* wpawn07;
//__WPawn__//
//__White--Peices__//

//__Black--Peices__//
King* bking;
Queen* bqueen;
Bishop* bbishop01;
Bishop* bbishop02;
Rook* brook01;
Rook* brook02;
Kinght* bkinght01;
Kinght* bkinght02;

//__BPawn__//
Pawn* bpawn00;
Pawn* bpawn01;
Pawn* bpawn02;
Pawn* bpawn03;
Pawn* bpawn04;
Pawn* bpawn05;
Pawn* bpawn06;
Pawn* bpawn07;
//__BPawn__//
//__Black--Peices__//

Terrain* terrain;
ChessBoard* chessboard;
TextureManager* texturemanager;
vec3 camArray[3]
{
    vec3(-10, 10, -10),
    vec3(20, 10, 1),
    vec3(-10, 5, -10),
};

int currentCam;

const int   WIDTH = 800; //__Screen--Size__//
const int   HEIGHT = 800; //__Screen--Size__//
int screenWidth;
int screenHeight;

float movement = 0.01f;

bool startMoving = false;

void MovePeice();
void cleanUp();

void Timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, Timer,0 );

}

void Display() {

    
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    chessboard->step(texturemanager);
    terrain->draw();

    //glDisable(GL_TEXTURE_2D);

    //__White--Peices__//
    glColor3f(0.5f,0,1); {
        wking->Draw();
        wqueen->Draw();
        wbishop01->Draw();
        wbishop02->Draw();
        wrook01->Draw();
        wrook02->Draw();
        wkinght01->Draw();
        wkinght02->Draw();
        //__WPawn__//
        wpawn00->Draw();
        wpawn01->Draw();
        wpawn02->Draw();
        wpawn03->Draw();
        wpawn04->Draw();
        wpawn05->Draw();
        wpawn06->Draw();
        wpawn07->Draw();
    }
    //__White--Peices__//
    
    glColor3f(1,0,0); {
        //__Black--Peices__//
        bking->Draw();
        bqueen->Draw();
        bbishop01->Draw();
        bbishop02->Draw();
        brook01->Draw();
        brook02->Draw();
        bkinght01->Draw();
        bkinght02->Draw();

        //__BPawn__//
        bpawn00->Draw();
        bpawn01->Draw();
        bpawn02->Draw();
        bpawn03->Draw();
        bpawn04->Draw();
        bpawn05->Draw();
        bpawn06->Draw();
        bpawn07->Draw();
        //__BPawn__//
        //__Black--Peices__//
    }

    MovePeice();

    glutSwapBuffers();
    
}

void CameraSwitch(unsigned char key, int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (WIDTH / HEIGHT), 0.1, 1000);
    //__Camera--Switch__//
    switch (key)
    {
    case GLUT_KEY_LEFT:
        currentCam--;
        break;
    case GLUT_KEY_RIGHT:
        currentCam++;
        break;
    default:
        currentCam = 0;
    }

    if (key == ' ') 
    {
        startMoving = !startMoving;
    }
   
     cout << currentCam << endl;

     if (currentCam < 0)
         currentCam = 2;

     if (currentCam > 2)
         currentCam = 0;

     gluLookAt
     (
         camArray[currentCam].x, camArray[currentCam].y, camArray[currentCam].z,
         0, 0, 0,
         0, 1, 0
     );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //__Camera__// 
    
        
}

void Init() {//__Initalisation__//

    //__Camera__//
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (WIDTH / HEIGHT), 0.1, 1000);
    glClearColor(207.0f / 255, 52.0f/ 255, 52.0f/ 255, 1);
    gluLookAt
    (
        -10, 10, -10,
        0, 0, 0,
        0, 1, 0
    );
    //__Camera__//
    


    //__White--Peices__//
    wking = new King;
    wking->SetPosition(0, 0.5f, 4);

    wqueen = new Queen;
    wqueen->SetPosition(0, 0.5f, 3);

    wkinght01 = new Kinght;
    wkinght01->SetPosition(0, 0.5f, 1);

    wkinght02 = new Kinght;
    wkinght02->SetPosition(0, 0.5f, 6);

    wbishop01 = new Bishop;
    wbishop01->SetPosition(0, 0.5f, 2);

    wbishop02 = new Bishop;
    wbishop02->SetPosition(0, 0.5f, 5);

    wrook01 = new Rook;
    wrook01->SetPosition(0, 0.5f, 1);/////////////

    wrook02 = new Rook;
    wrook02->SetPosition(0, 0.5f, 8);

    //__WPawn__//
    wpawn00 = new Pawn;
    wpawn00->SetPosition(1,0.5f,0);

    wpawn01 = new Pawn;
    wpawn01->SetPosition(1, 0.5f, 1);

    wpawn02 = new Pawn;
    wpawn02->SetPosition(1, 0.5f, 2);

    wpawn03 = new Pawn;
    wpawn03->SetPosition(1, 0.5f, 3);

    wpawn04 = new Pawn;
    wpawn04->SetPosition(1, 0.5f, 4);

    wpawn05 = new Pawn;
    wpawn05->SetPosition(1, 0.5f, 5);

    wpawn06 = new Pawn;
    wpawn06->SetPosition(1, 0.5f, 6);

    wpawn07 = new Pawn;
    wpawn07->SetPosition(1, 0.5f, 7);
    //__WPawn__//
    //__White--Peices__//

    //__Black--Peices__//
    bking = new King;
    bking->SetPosition(7, 0.5f, 4);

    bqueen = new Queen;
    bqueen->SetPosition(7, 0.5f, 3);

    bbishop01 = new Bishop;
    bbishop01->SetPosition(7,0.5f,2);

    bbishop02 = new Bishop;
    bbishop02->SetPosition(7, 0.5f, 5);

    brook01 = new Rook;
    brook01->SetPosition(7,0.5f,1);
    
    brook02 = new Rook;
    brook02->SetPosition(7,0.5f,8);

    bkinght01 = new Kinght;
    bkinght01->SetPosition(7, 0.5f, 1);

    bkinght02 = new Kinght;
    bkinght02->SetPosition(7,0.5f, 6);

    //__BPawn__//
    bpawn00 = new Pawn;
    bpawn00->SetPosition(6, 0.5f, 0);

    bpawn01 = new Pawn;
    bpawn01->SetPosition(6, 0.5f, 1);

    bpawn02 = new Pawn;
    bpawn02->SetPosition(6, 0.5f, 2);

    bpawn03 = new Pawn;
    bpawn03->SetPosition(6, 0.5f, 3);

    bpawn04 = new Pawn;
    bpawn04->SetPosition(6, 0.5f, 4);

    bpawn05 = new Pawn;
    bpawn05->SetPosition(6, 0.5f, 5);

    bpawn06 = new Pawn;
    bpawn06->SetPosition(6, 0.5f, 6);

    bpawn07 = new Pawn;
    bpawn07->SetPosition(6, 0.5f, 7);
    //__BPawn__//
    //__Black--Peices__//
    


    glutKeyboardFunc(CameraSwitch); //__Gets--KeyBoard--InPut__//

    chessboard = new ChessBoard(8,8);
    texturemanager = new TextureManager();

    terrain = new Terrain(texturemanager->getTexture("heightMap"), 50, 5);
    terrain->setPosition(vec3(0,-5,-20));
}

int main(int argc, char * argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition((screenWidth- WIDTH)/2, (screenHeight-HEIGHT)/2);
    glutCreateWindow("OldSpice_Game_Engine_Chess");
    Init();                                                     //__Initalizing--gameObjects(Awake method)__//
    glutDisplayFunc(Display);
    glutTimerFunc(0,Timer,0);
    glutMainLoop();
}

void cleanUp() {
    delete texturemanager;
    delete chessboard;
    delete terrain;

    //__White--Peices__//
    delete wking;
    delete wqueen;
    delete wbishop01;
    delete wbishop02;
    delete wrook01;
    delete wrook02;
    delete wkinght01;
    delete wkinght02;
    //__WPawn__//
    delete wpawn00;
    delete wpawn01;
    delete wpawn02;
    delete wpawn03;
    delete wpawn04;
    delete wpawn05;
    delete wpawn06;
    delete wpawn07;
    //__WPawn__//
    //__White--Peices__//


    //__Black--Peices__//
    delete bqueen;
    delete bking;
    delete bbishop01;
    delete bbishop02;
    delete brook01;
    delete brook02;
    delete bkinght01;
    delete bkinght02;
    //__BPawn__//
    delete bpawn00;
    delete bpawn01;
    delete bpawn02;
    delete bpawn03;
    delete bpawn04;
    delete bpawn05;
    delete bpawn06;
    delete bpawn07;
    //__BPawn__//
    //__Black--Peices__//
}

void MovePeice() 
{
    if (startMoving == true)
    {
        if (wking->GetPosition().x <= 2) 
        {
            wking->SetPosition(wking->GetPosition().x + movement, 0.5f, 4);

            wqueen->SetPosition(wqueen->GetPosition().x + movement, 0.5f, 3);

            wkinght01->SetPosition(wkinght01->GetPosition().x + movement, 0.5f, 1);

            wkinght02->SetPosition(wkinght02->GetPosition().x + movement, 0.5f, 6);

            wbishop01->SetPosition(wbishop01->GetPosition().x + movement, 0.5f, 2);

            wbishop02->SetPosition(wbishop02->GetPosition().x + movement, 0.5f, 5);

            wrook01->SetPosition(wrook01->GetPosition().x + movement, 0.5f, 1);/////////////

            wrook02->SetPosition(wrook02->GetPosition().x + movement, 0.5f, 8);
        }
          
    }
    else if(startMoving == false)
    {
        if (wking->GetPosition().x >= 0) 
        {
            //__White--Peices__//
            wking->SetPosition(wking->GetPosition().x - movement, 0.5f, 4);

            wqueen->SetPosition(wqueen->GetPosition().x - movement, 0.5f, 3);

            wkinght01->SetPosition(wkinght01->GetPosition().x - movement, 0.5f, 1);

            wkinght02->SetPosition(wkinght02->GetPosition().x - movement, 0.5f, 6);

            wbishop01->SetPosition(wbishop01->GetPosition().x - movement, 0.5f, 2);

            wbishop02->SetPosition(wbishop02->GetPosition().x - movement, 0.5f, 5);

            wrook01->SetPosition(wrook01->GetPosition().x - movement, 0.5f, 1);/////////////

            wrook02->SetPosition(wrook02->GetPosition().x - movement, 0.5f, 8);
        }
       

      
    }
}
