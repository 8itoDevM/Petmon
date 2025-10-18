#pragma once
#include <string>
#include "raylib.h"

class Button{
public:
    Button();
    Button(std::string text, int font_size, Font font, Vector2 position, Vector2 magrin, Color btn_color, Color text_color);
    std::string _text;
    int _font_size;
    Font _font;
    Vector2 _position;
    Vector2 _magrin;
    Color _btn_color;
    Color _original_color;
    Color _text_color;

    bool selected = false;

    void Draw();
    void Update();
    bool Click();
private:
    Vector2 size;
    Vector2 CalculateSize(std::string text, int font_size, Font font, Vector2 magrin);
    Color IncreaseBrightness(Color originalColor, int brightnessAmount);

};