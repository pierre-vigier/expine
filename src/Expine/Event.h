#pragma once

namespace Expine
{
    enum class EventType {
        KeyPressedEvent, KeyReleasedEvent, MouseButtonPressedEvent, MouseButtonReleasedEvent,
        MouseMovedEvent, WindowsClosedEvent
    };

    class Event
    {
    public:
        virtual const char* GetName() const = 0;
        virtual const bool OfType(const EventType &t) const = 0;
    };

    class KeyPressedEvent: public Event
    {
    protected:
        int m_KeyCode;
    public:
        KeyPressedEvent(int keyCode) : m_KeyCode(keyCode) {}
        virtual const char* GetName() const override { return "KeyPressedEvent";}
        virtual const bool OfType(const EventType &t) const override { return t == EventType::KeyPressedEvent;}
    };

    class KeyReleasedEvent: public Event
    {
    protected:
        int m_KeyCode;
    public:
        KeyReleasedEvent(int keyCode) : m_KeyCode(keyCode) {}
        virtual const char* GetName() const override { return "KeyReleasedEvent";}
        virtual const bool OfType(const EventType &t) const override { return t == EventType::KeyReleasedEvent;}
    };

    class MouseButtonPressedEvent: public Event
    {
    protected:
        int m_Button;
    public:
        MouseButtonPressedEvent(int button) : m_Button(button) {}
        virtual const char* GetName() const override { return "MouseButtonPressedEvent";}
        virtual const bool OfType(const EventType &t) const override { return t == EventType::MouseButtonPressedEvent;}
    };

    class MouseButtonReleasedEvent: public Event
    {
    protected:
        int m_Button;
    public:
        MouseButtonReleasedEvent(int button) : m_Button(button) {}
        virtual const char* GetName() const override { return "MouseButtonReleasedEvent";}
        virtual const bool OfType(const EventType &t) const override { return t == EventType::MouseButtonReleasedEvent;}
    };

    class MouseMovedEvent: public Event
    {
    private:
        double m_X,m_Y;
    public:
        MouseMovedEvent(double x, double y) : m_X(x), m_Y(y) {}
        virtual const char* GetName() const override { return "MouseMovedEvent";}
        virtual const bool OfType(const EventType &t) const override { return t == EventType::MouseMovedEvent;}
    };

    class WindowsClosedEvent: public Event
    {
    public:
        virtual const char* GetName() const override { return "WindowsClosedEvent";}
        virtual const bool OfType(const EventType &t) const override { return t == EventType::WindowsClosedEvent;}
    };
}