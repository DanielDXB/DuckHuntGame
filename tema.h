#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema : public gfxc::SimpleScene
    {
     public:
         Tema();
        ~Tema();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void RenderScene();

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        glm::mat3 modelMatrix;
        float pozX, pozY;
        float viteza;
        float rot;
        float rot_aripi;
        bool sens_aripi;
        int vieti;
        float timp;
        int puncte;
        bool nimerit;
        int gloante;
        int rate;
    };
}   // namespace m1
