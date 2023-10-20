#include <GL/glew.h>
#include <iostream>
#include "gl/freeglut.h"
#include "ChessBoard.h"
#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "glm/glm.hpp"
#include "Terrain.h"


Terrain* terrain;
ChessBoard* chessboard;
TextureManager* texturemanager;
vec3 camArray[3]
{
    vec3(-10, 10, -10),
    vec3(30, -90, 1),
    vec3(-10, 5, -10),
};

int currentCam;

const int   WIDTH = 800; //__Screen--Size__//
const int   HEIGHT = 800; //__Screen--Size__//
int screenWidth;
int screenHeight;


void cleanUp();

void Timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, Timer,0 );

}

void Display() {

    
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    chessboard->step(texturemanager);
    terrain->draw();

    glutSwapBuffers();
    
}

void CameraSwitch(unsigned char key, int x, int y ) 
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
    
    
    glutKeyboardFunc(CameraSwitch); //__Gets--KeyBoard--InPut__//
    chessboard = new ChessBoard(8,8);
    texturemanager = new TextureManager();

    terrain = new Terrain(texturemanager->getTexture("heightMap"), 50, 5);
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
}
