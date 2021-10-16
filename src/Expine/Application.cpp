#include "Application.h"
#include <iostream>

namespace Expine
{
    Application::Application() 
    {
        std::cout << "Application created" << std::endl;
    }
    
    Application::~Application() 
    {
        std::cout << "Application destroyed" << std::endl;
    }
}