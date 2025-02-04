#pragma once

struct GLFWwindow;

namespace GameEngine {
    class UIModule {
    public:
        static void onWindowCreate(GLFWwindow *window);
        static void onWindowClose();
        static void onUIDrawBegin();
        static void onUIDrawEnd();
    };
}
