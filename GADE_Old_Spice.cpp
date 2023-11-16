#include <GL/glew.h>
#include <iostream>
#include "gl/freeglut.h"
#include "ChessBoard.h"
#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
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

#include "Model.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include <tinyobjloader/tiny_obj_loader.h> 
#include "Camera.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Model* table;
Model* boat;
Model* water;
Model* sky;
Model* brassscale;
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

Camera camera(1600, 800);


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


void fpsCounter(float x, float y, const string& text);

void MovePeice();
void cleanUp();


int frameCount = 0; // Variable to store the frame count
int currentTime, previousTime; // Variables to calculate frame rate


void mouse_callback(int xpos, int ypos) {
    

    camera.ProcessMouseMovement(xpos,ypos);
}

void keyboard_callback(unsigned char key, int x, int y) {
    camera.ProcessInput(key, x, y);
    glutPostRedisplay();
    
}
// Function to update the frame counter and calculate frame rate
void updateFrameCounter() {
    currentTime = glutGet(GLUT_ELAPSED_TIME);

    float deltaTime = (currentTime - previousTime) / 1000.0f;

    frameCount++;

    float fps = frameCount / deltaTime;

    // Convert FPS to string
    ostringstream oss;
    oss << "FPS: " << fps;

    // Set color and render text in screen space
    glColor3f(1, 1, 1);
    fpsCounter(10, 10, oss.str());

    previousTime = currentTime;
    frameCount = 0;
}


void Timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, Timer,0 );

}

void Display() {

    
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(camera.GetViewMatrix()));
    // Update the frame counter
    updateFrameCounter();


    chessboard->step(texturemanager);
    
    terrain->draw();
   // texturemanager->useTexture("Table");
    table->draw();

    texturemanager->useTexture("Boat");
    boat->draw();

    texturemanager->useTexture("water");
    water->draw();

    texturemanager->useTexture("sky");
    sky->draw();

    texturemanager->useTexture("scale");
    brassscale->draw();
    
    //__White--Peices__//
    glColor3f(1,1,1); {
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
    
    glColor3f(0,0,0); {
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
    updateFrameCounter();
    glutSwapBuffers();
    
}



// Idle function - continuously called when the system is idle
void idle() {
    // Trigger a redraw to update the frame counter
    glutPostRedisplay();
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
    wrook01->SetPosition(0, 0.5f, 1);

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
    


   // glutKeyboardFunc(CameraSwitch); //__Gets--KeyBoard--InPut__//

    table = new Model("Model/Table", "Table");                  
    table->generateDisplayList();
    table->setPosition(vec3(4,-16.5f,4));
    table->SetScale(vec3(10,10,10));

    boat = new Model("Model/Boat", "boat");
    boat->generateDisplayList();
    boat->setPosition(vec3(4, -45, 4));
    boat->SetScale(vec3(10,10,10));

    water = new Model("Model/water", "water");
    water->generateDisplayList();
    water->setPosition(vec3(4, -50, 4));
    water->SetScale(vec3(20, 20, 20));

    sky = new Model("Model/sky", "sky");
    sky->generateDisplayList();
    sky->setPosition(vec3(4, -50, 4));
    sky->SetScale(vec3(500,500,500));


    brassscale = new Model("Model/scale", "scale");
    brassscale->generateDisplayList();
    brassscale->setPosition(vec3(4, 0, 11));
    brassscale->SetScale(vec3(0.1f,0.1f,0.1f));

    chessboard = new ChessBoard(8,8);
    texturemanager = new TextureManager();

    terrain = new Terrain(texturemanager->getTexture("heightMap"), 50, 5);
    terrain->setPosition(vec3(0,-20,-20));
}

void fpsCounter(float x, float y , const string& text) 
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2f(x, y);

    for (char chartext : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, chartext);
    }

    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);

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
    glutIdleFunc(idle);

    glutPassiveMotionFunc(mouse_callback);
    glutKeyboardFunc(keyboard_callback);

    // Set the initial time for frame rate calculation
    previousTime = glutGet(GLUT_ELAPSED_TIME);

    glutMainLoop();
    return 0;
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

    delete table;
    delete boat;
    delete water;
    delete sky;
    delete brassscale;
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

            wrook01->SetPosition(wrook01->GetPosition().x + movement, 0.5f, 1);

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

            wrook01->SetPosition(wrook01->GetPosition().x - movement, 0.5f, 1);

            wrook02->SetPosition(wrook02->GetPosition().x - movement, 0.5f, 8);
        }
       

      
    }
}
