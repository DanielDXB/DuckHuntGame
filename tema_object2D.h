#pragma once

#include <string>
#include <iostream>
#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace tema_object2D
{
    Mesh* CapRata(const std::string& nume, glm::vec3 centru, float lungime, glm::vec3 culori);
    Mesh* CorpRata(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori);
    Mesh* AripaStanga(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori);
    Mesh* AripaDreapta(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori);
    Mesh* Cioc(const std::string& nume, glm::vec3 varf, float lungime, glm::vec3 culori);
    Mesh* Cadru(const std::string& nume, glm::vec3 stangaJos, float lungime, glm::vec3 culori);
    Mesh* Scor(const std::string& nume, glm::vec3 stangaJos, float lungime, glm::vec3 culori);
    Mesh* Cartuse(const std::string& nume, glm::vec3 stangaJos, float lungime, glm::vec3 culori);
    Mesh* Viata(const std::string& nume, glm::vec3 centru, float lungime, glm::vec3 culori);

    bool Coliziune(glm::mat3 transformMatrix, int pozX, int pozY);
}
