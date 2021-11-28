#pragma once

#include "Event.h"
#include "Window.h"

#include <string>

namespace Expine {
    class Layer
    {
    public:
        Layer(const std::string& name = "default");
        Layer(const Layer &l) = delete;
        virtual ~Layer();

        virtual void OnUpdate() {};
        virtual void HandleEvent(Event &e) {};
        virtual void OnMount() {};
        virtual void OnUnmount() {};
    private:
        std::string m_Name;
    };
}