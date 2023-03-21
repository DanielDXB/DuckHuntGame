#include "lab_m1/Tema/tema.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema/tema_transform2D.h"
#include "lab_m1/Tema/tema_object2D.h"
#include <random>
#include <time.h>
#define PI 3.15

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema::Tema()
{
}


Tema::~Tema()
{
}


void Tema::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    srand(time(NULL));
    pozX = rand() % 1280;
    pozY = rand() % 720;
    rot = ((float)(rand() % 630)) / 100;
    nimerit = false;
    vieti = 3;
    gloante = 3;
    rate = 1;
    puncte = 0;
    rot_aripi = 0;
    sens_aripi = true;
    timp = 8;

    Mesh* cioc = tema_object2D::Cioc("cioc", glm::vec3(0, 0, 0), 35, glm::vec3(1, 0, 0));
    AddMeshToList(cioc);

    Mesh* corp = tema_object2D::CorpRata("corp", glm::vec3(0, -60, 0), 130, glm::vec3(1, 0, 0));
    AddMeshToList(corp);

    Mesh* cap = tema_object2D::CapRata("cap", glm::vec3(0, -60, 0), 35, glm::vec3(0, 0, 1));
    AddMeshToList(cap);

    Mesh* stanga = tema_object2D::AripaStanga("stanga", glm::vec3(0, -130, 0), 100, glm::vec3(0, 1, 0));
    AddMeshToList(stanga);

    Mesh* dreapta = tema_object2D::AripaDreapta("dreapta", glm::vec3(0, -130, 0), 100, glm::vec3(0, 1, 0));
    AddMeshToList(dreapta);

    Mesh* cadru = tema_object2D::Cadru("cadru", glm::vec3(1050, 650, 0), 200, glm::vec3(1, 1, 1));
    AddMeshToList(cadru);

    Mesh* scor = tema_object2D::Scor("scor", glm::vec3(1035, 650, 0), 50, glm::vec3(0, 0, 1));
    AddMeshToList(scor);

    Mesh* cartuse = tema_object2D::Cartuse("cartuse", glm::vec3(1200, 580, 0), 50, glm::vec3(0, 1, 0));
    AddMeshToList(cartuse);

    Mesh* viata = tema_object2D::Viata("viata", glm::vec3(1210, 550, 0), 20, glm::vec3(1, 0, 0));
    AddMeshToList(viata);
}


void Tema::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema::RenderScene() {
    modelMatrix = glm::mat3(1);
    modelMatrix *= tema_transform2D::Translate(pozX, pozY);
    modelMatrix *= tema_transform2D::Rotate(rot - PI/2);

    RenderMesh2D(meshes["cap"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["corp"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["stanga"], shaders["VertexColor"], modelMatrix * tema_transform2D::Rotate(rot_aripi));
    RenderMesh2D(meshes["dreapta"], shaders["VertexColor"], modelMatrix * tema_transform2D::Rotate(-rot_aripi));
    RenderMesh2D(meshes["cioc"], shaders["VertexColor"], modelMatrix);


    RenderMesh2D(meshes["cadru"], shaders["VertexColor"], glm::mat3(1));
    for (int i = 1; i <= puncte; i++) {
        RenderMesh2D(meshes["scor"], shaders["VertexColor"], tema_transform2D::Translate(i * 15, 0));
    }

    for (int i = 0; i < gloante; i++) {
        RenderMesh2D(meshes["cartuse"], shaders["VertexColor"], tema_transform2D::Translate(-i*50, 0));
    }

    for (int i = 0; i < vieti; i++) {
        RenderMesh2D(meshes["viata"], shaders["VertexColor"], tema_transform2D::Translate(-i * 50, 0));
    }
}
void Tema::Update(float deltaTimeSeconds)
{
    viteza = 100 + rate * 20;
    pozX += cos(rot) * viteza * deltaTimeSeconds;
    pozY += sin(rot) * viteza * deltaTimeSeconds;

    if (sens_aripi == true) {
        rot_aripi += viteza * deltaTimeSeconds / 500;
        if (rot_aripi > 0.15)
            sens_aripi = false;
    }
    else if (sens_aripi == false) {
        rot_aripi -= viteza * deltaTimeSeconds / 500;
        if (rot_aripi < -0.15) 
            sens_aripi = true;
    }

    timp -= deltaTimeSeconds;
    if (timp < 0)
        rot = PI/2;

    if (pozX > 1280 || pozX < 0) {
        rot = PI - rot;
        if (pozX > 1280)
            pozX = 1279;
        else
            pozX = 1;
    }
    if (pozY > 720 || pozY < 0) {
        rot = 2*PI - rot;
        if (pozY > 720)
        {
            pozY = 719;
            if (timp < 0) {
                pozX = rand() % 1280;
                pozY = rand() % 720;
                rot = ((float)(rand() % 630)) / 100;
                vieti--;
                rate++;
                gloante = 3;
                timp = 8;
            }
        }
        else
        {
            pozY = 1;
            if (nimerit) {
                pozX = rand() % 1280;
                pozY = rand() % 720;
                rot = ((float)(rand() % 630)) / 100;
                nimerit = false;
                puncte++;
                rate++;
                gloante = 3;
                timp = 8;
            }
        }
    }
    if (vieti > 0 && rate < 15)
        RenderScene();
}


void Tema::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema::OnKeyPress(int key, int mods)
{
}


void Tema::OnKeyRelease(int key, int mods)
{
}


void Tema::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}


void Tema::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}


void Tema::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT)) {
        gloante--;
       if (!nimerit && timp>0 && tema_object2D::Coliziune(modelMatrix, mouseX, 720-mouseY)) {
            rot = -PI/2;
            timp = 100;
            nimerit = true;
        }
    }
}


void Tema::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema::OnWindowResize(int width, int height)
{
}
