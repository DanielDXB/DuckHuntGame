#include "tema_object2D.h"

#include <vector>
#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>
#define PI 3.15


Mesh* tema_object2D::CorpRata(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori)
{
    Mesh* corp = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(varf, culori),
        VertexFormat(glm::vec3(varf.x - lungime/2, varf.y - lungime, 0), culori),
        VertexFormat(glm::vec3(varf.x + lungime/2, varf.y - lungime, 0), culori)
    };
    std::vector<unsigned int> indices = {0, 1, 2};

    corp->InitFromData(vertices, indices);
    return corp;
}
Mesh* tema_object2D::CapRata(const std::string& nume, glm::vec3 centru, float lungime, glm::vec3 culori)
{
    Mesh* cap = new Mesh(nume);
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(centru, culori)
    };
    std::vector<unsigned int> indices = {0};
   
    int poz = 0;
    for (float i = 0; i < 2*PI+1; i += 0.2) {
        vertices.push_back(VertexFormat(glm::vec3(centru.x + lungime*sin(i), centru.y + lungime*cos(i), 0), culori));
        poz++;
        indices.push_back(poz);
    }
    cap->SetDrawMode(GL_TRIANGLE_FAN);
    cap->InitFromData(vertices, indices);
    return cap;
}
Mesh* tema_object2D::AripaStanga(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori)
{
    Mesh* aripa = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(varf, culori),
        VertexFormat(glm::vec3(varf.x - lungime, varf.y - lungime/2, 0), culori),
        VertexFormat(glm::vec3(varf.x - lungime, varf.y + lungime/2, 0), culori)
    };
    std::vector<unsigned int> indices = { 0, 1, 2 };

    aripa->InitFromData(vertices, indices);
    return aripa;
}
Mesh* tema_object2D::AripaDreapta(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori)
{
    Mesh* aripa = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(varf, culori),
        VertexFormat(glm::vec3(varf.x + lungime, varf.y - lungime / 2, 0), culori),
        VertexFormat(glm::vec3(varf.x + lungime, varf.y + lungime / 2, 0), culori)
    };
    std::vector<unsigned int> indices = { 0, 1, 2 };

    aripa->InitFromData(vertices, indices);
    return aripa;
}
Mesh* tema_object2D::Cioc(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori)
{
    Mesh* cioc = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(varf, culori),
        VertexFormat(glm::vec3(varf.x - lungime / 2, varf.y - lungime, 0), culori),
        VertexFormat(glm::vec3(varf.x + lungime / 2, varf.y - lungime, 0), culori)
    };
    std::vector<unsigned int> indices = { 0, 1, 2 };

    cioc->InitFromData(vertices, indices);
    return cioc;
}
Mesh* tema_object2D::Cadru(const std::string& nume, glm::vec3 stangaJos, float lungime, glm::vec3 culori)
{
    Mesh* cadru = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(stangaJos, culori),
        VertexFormat(glm::vec3(stangaJos.x, stangaJos.y + lungime/4, 0), culori),
        VertexFormat(glm::vec3(stangaJos.x + lungime, stangaJos.y + lungime/4, 0), culori),
        VertexFormat(glm::vec3(stangaJos.x + lungime, stangaJos.y, 0), culori)
    };
    std::vector<unsigned int> indices = { 0, 1, 2, 3};

    cadru->SetDrawMode(GL_LINE_LOOP);
    cadru->InitFromData(vertices, indices);
    return cadru;
}
Mesh* tema_object2D::Scor(const std::string& nume, glm::vec3 stangaJos, float lungime, glm::vec3 culori)
{
    Mesh* scor = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(stangaJos, culori),
        VertexFormat(glm::vec3(stangaJos.x, stangaJos.y + lungime, 0), culori),
        VertexFormat(glm::vec3(stangaJos.x + lungime/4, stangaJos.y + lungime, 0), culori),
        VertexFormat(glm::vec3(stangaJos.x + lungime/4, stangaJos.y, 0), culori)
    };
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 2, 0 };

    scor->InitFromData(vertices, indices);
    return scor;
}
Mesh* tema_object2D::Cartuse(const std::string& nume, glm::vec3 stangaJos, float lungime, glm::vec3 culori)
{
    Mesh* cadru = new Mesh(nume);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(stangaJos, culori),
        VertexFormat(glm::vec3(stangaJos.x, stangaJos.y + lungime, 0), culori),
        VertexFormat(glm::vec3(stangaJos.x + lungime/2, stangaJos.y+lungime, 0), culori),
        VertexFormat(glm::vec3(stangaJos.x + lungime/2, stangaJos.y, 0), culori)
    };
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    cadru->SetDrawMode(GL_LINE_LOOP);
    cadru->InitFromData(vertices, indices);
    return cadru;
}
Mesh* tema_object2D::Viata(const std::string& nume, glm::vec3 centru, float lungime, glm::vec3 culori)
{
    Mesh* viata = new Mesh(nume);
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(centru, culori)
    };
    std::vector<unsigned int> indices = { 0 };

    int poz = 0;
    for (float i = 0; i < 2 * PI + 1; i += 0.2) {
        vertices.push_back(VertexFormat(glm::vec3(centru.x + lungime * sin(i), centru.y + lungime * cos(i), 0), culori));
        poz++;
        indices.push_back(poz);
    }
    viata->SetDrawMode(GL_TRIANGLE_FAN);
    viata->InitFromData(vertices, indices);
    return viata;
}
bool tema_object2D::Coliziune(glm::mat3 modelMatrix, int pozX, int pozY)
{
    glm::vec3 centru = glm::vec3(0, -100, 1);
    centru = modelMatrix * centru;
    float xs = centru.x - 100;
    float xd = centru.x + 100;
    float ys = centru.y + 100;
    float yj = centru.y - 100;
    return (pozX < xd && pozX > xs && pozY < ys && pozY > yj);
}
