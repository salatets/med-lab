#pragma once
#include "PathGenerator.hpp"
#include <iostream>

class Screenshot : private PathGenerator
{
public:
    void save() { std::cout << datePath("png").toStdString() << std::endl; }
};

class WindowCapture : private PathGenerator
{
public:
    void save() { std::cout << datePath("mp4").toStdString() << std::endl; }
};
