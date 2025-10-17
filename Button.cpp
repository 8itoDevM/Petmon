#include "Button.h"
#include "raymath.h"

static bool wasSelected = false; 

Button::Button()
{
    _text = "";
    _font_size = 0;
    _font = GetFontDefault();
    _position = {0, 0};
    _magrin = {0, 0};
    size = {0, 0};
}

Button::Button(std::string text, int font_size, Font font, Vector2 position, Vector2 magrin, Color btn_color, Color text_color)
{
    size = CalculateSize(text, font_size, font, magrin);
    _text = text;
    _font_size = font_size;
    _font = font;
    _position = position;
    _magrin = magrin;
    _btn_color = btn_color;
    _text_color = text_color;

    _original_color = _btn_color;
}

void Button::Draw()
{
    DrawRectangle(_position.x, _position.y, size.x, size.y, _btn_color);
    DrawTextEx(_font, _text.c_str(), {_position.x + (_magrin.x/2), _position.y + (_magrin.y/2)}, _font_size, 2, _text_color);
}

void Button::Update()
{
    if (selected && !wasSelected) {
        _btn_color = IncreaseBrightness(_btn_color, 80);
    } 
    else if (!selected && wasSelected) {
        
        _btn_color = _original_color;
    }

    wasSelected = selected; 
}

Vector2 Button::CalculateSize(std::string text, int font_size, Font font, Vector2 magrin)
{
    return Vector2Add(MeasureTextEx(font, text.c_str(), font_size, 2), magrin);
}


Color Button::IncreaseBrightness(Color originalColor, int brightnessAmount)
{
    Color brightenedColor = originalColor;

    // Increase R, G, B components and clamp them between 0 and 255
    brightenedColor.r = (unsigned char)fminf(255.0f, fmaxf(0.0f, (float)originalColor.r + brightnessAmount));
    brightenedColor.g = (unsigned char)fminf(255.0f, fmaxf(0.0f, (float)originalColor.g + brightnessAmount));
    brightenedColor.b = (unsigned char)fminf(255.0f, fmaxf(0.0f, (float)originalColor.b + brightnessAmount));

    return brightenedColor;
}
