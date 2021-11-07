#pragma once

namespace Expine
{
    class Event
    {
    public:
        virtual const char* GetName() const = 0;
    };

    class KeyPressedEvent: public Event
    {
    protected:
        int m_KeyCode;
    public:
        KeyPressedEvent(int keyCode) : m_KeyCode(keyCode) {}
        virtual const char* GetName() const override { return "KeyPressedEvent";}
    };

    class KeyReleasedEvent: public Event
    {
    protected:
        int m_KeyCode;
    public:
        KeyReleasedEvent(int keyCode) : m_KeyCode(keyCode) {}
        virtual const char* GetName() const override { return "KeyReleasedEvent";}
    };

    class MouseButtonPressedEvent: public Event
    {
    protected:
        int m_Button;
    public:
        MouseButtonPressedEvent(int button) : m_Button(button) {}
        virtual const char* GetName() const override { return "MouseButtonPressedEvent";}
    };

    class MouseButtonReleasedEvent: public Event
    {
    protected:
        int m_Button;
    public:
        MouseButtonReleasedEvent(int button) : m_Button(button) {}
        virtual const char* GetName() const override { return "MouseButtonReleasedEvent";}
    };

    class MouseMovedEvent: public Event
    {
    private:
        double m_X,m_Y;
    public:
        MouseMovedEvent(double x, double y) : m_X(x), m_Y(y) {}
        virtual const char* GetName() const override { return "MouseMovedEvent";}
    };
}