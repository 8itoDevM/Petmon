#pragma once
#include <functional>

struct Scenes
{
    std::function<void()> Init;
    std::function<void()> Update;
    std::function<void()> Draw;
};
