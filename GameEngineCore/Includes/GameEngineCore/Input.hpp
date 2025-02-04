#ifndef INPUT_HPP
#define INPUT_HPP

#include "GameEngineCore/Keys.hpp"

#include <iostream>

namespace GameEngine {
    class Input {
    public:
        static bool isKeyPressed(const KeyCode keyCode);
        static void pressKey(const KeyCode keyCode);
        static void releaseKey(const KeyCode keyCode);

        static bool isMouseButtonPressed(const MouseButton mouseButton);
        static void pressMouseButton(const MouseButton mouseButton);
        static void releaseMouseButton(const MouseButton mouseButton);

    private:
        static bool m_keysPressed[];
        static bool m_mouseButtonsPressed[];
    };
}

#endif
