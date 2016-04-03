#pragma once
#include "runnable_drawable.h"
#include "button.h"
#include "texture_data.h"
#include "debug.h"

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <vector>
#include <memory>

// The gui class instantiated by all classes that want to use any sort of gui element, excluding their own sprite, texture and the likes.
// The class acts as a container and will update and render all stack created with a instance of this class.
class GUI : public aoc::RunnableDrawable
{

public:
	GUI() 
    {
        if (!m_font.loadFromFile("Resources/Font/arial.ttf"))
        {
            Debug::Print(Debug::warning, "Failed to load default font", "gui.h", "GUI");
        }
    };

	~GUI() {};

	// Update all gui stack.
	virtual void Update(sf::Vector2f windowsize)
	{
		for (auto& button : m_button_stack)
		{
            button->Update(windowsize);
		}
	}

	// Handle user input events for all gui stack.
	virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos)
	{
		for (auto& button : m_button_stack)
		{
			button->HandleEvents(event, mousepos);
		}
	}

	// Render all gui elements.
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        // Draw outer frame.
        target.draw(m_frame_sprite);

        // Draw buttons
		for (auto& button : m_button_stack)
		{
            button->Draw(target, states);
		}

        // Draw sprites
        for (auto& sprite : m_sprite_ref_stack)
        {
            target.draw(sprite);
        }

        for (auto& sprite : m_sprite_stack)
        {
            target.draw(sprite);
        }

        // Draw text
        for (auto& text : m_text_ref_stack)
        {
            target.draw(text.get());
        }

        for (auto& text : m_text_stack)
        {
            target.draw(text);
        }

	}

    // Create the frame of this gui. Nothing should be drawn outside the bounds of the frame.
    // This is most likely a background and will be rendered first.
    void CreateFrame(TextureData texture_data, sf::Vector2f position)
    {
        if (m_frame_texture.loadFromFile(texture_data.path))
        {
            m_frame_sprite.setTexture(m_frame_texture);
            m_frame_sprite.setScale(texture_data.scale);
            m_frame_sprite.setPosition(position);
        }
    }

    // Create a dynamic sprite that can change texture during runtime. 
    // The gui class has no control over what the sprites texture is.
    void CreateSprite(sf::Sprite& sprite, sf::Vector2f position)
    {
        sprite.setPosition(position);
        m_sprite_ref_stack.push_back(sprite);
    }

    // Static sprite that can't change texture during runtime.
    void CreateSprite(TextureData texture_data, sf::Vector2f position, sf::Color = sf::Color::Transparent)
    {
        m_texture_storage.push_back(sf::Texture());
        sf::Texture& temp_texture = m_texture_storage.back();

        if (temp_texture.loadFromFile(texture_data.path))
        {
            m_sprite_stack.push_back(sf::Sprite());
            sf::Sprite& temp_sprite = m_sprite_stack.back();

            temp_sprite.setTexture(temp_texture);
            temp_sprite.setPosition(position);

        }
    }

    // Create dynamic text that can change during runtime. The gui class has no control over what text is drawn, only its position.
    void CreateText(sf::Text& text, unsigned int char_size, sf::Vector2f position, sf::Color color = sf::Color::Black, sf::Uint32 style = sf::Text::Regular)
    {
        text.setFont(m_font);
        text.setCharacterSize(char_size);
        text.setPosition(position);
        text.setColor(color);
        text.setStyle(style);
        m_text_ref_stack.push_back(text);

    }

    // Create static text that can't change during runtime.
    void CreateText(std::string text, unsigned int char_size, sf::Vector2f position, sf::Color color = sf::Color::Black, sf::Uint32 style = sf::Text::Regular)
    {
        m_text_stack.push_back(sf::Text());
        sf::Text& temp_text = m_text_stack.back();

        temp_text.setString(text);
        temp_text.setFont(m_font);
        temp_text.setCharacterSize(char_size);
        temp_text.setPosition(position);
        temp_text.setColor(color);
        temp_text.setStyle(style);

    }

	// Create a new button. The supplied method will be bound to the button, and when clicked the button will call the method.
	template<class ReturnType, class Class, typename... Params>
	void CreateButton(std::string texture_path, std::string hoover_texture_path, sf::Vector2f scale, sf::Vector2f position, 
		ReturnType(Class::*method_ref)(Params...), Class& class_ref, Params&... params)
	{
		m_button_stack.push_back(
			std::make_unique<Button<ReturnType, Class, Params...> >(
				class_ref, method_ref, params...,					  // Class, method, and params called with OnClick event
				texture_path, hoover_texture_path,                    // Normal and hoover texture
				scale, position));                                    // Scale and position			
	}

    // Set a new font for the text rendered by the gui object. 
    // It already has a default font loaded in the constructor.
    void SetFont(std::string font_path)
    {
        if (!m_font.loadFromFile(font_path))
        {
            Debug::Print(Debug::warning, "Failed to load font", "gui.h", "SetFont");
        }
    }


private:
    sf::Font m_font;

    sf::Texture m_frame_texture;
    sf::Sprite m_frame_sprite;


    // Stack storing the gui stack inheriting RunnableDrawable.
    std::vector<std::unique_ptr<aoc::RunnableDrawable> > m_button_stack;

    // Stack storing static text elements.
    std::vector<sf::Text> m_text_stack;

    // Stack storing text elements that can change during runtime.
    std::vector<std::reference_wrapper<sf::Text> > m_text_ref_stack;

    // Stack storing all static sprites.
    std::vector<sf::Sprite> m_sprite_stack;

    // Stack storing all dynamic sprites.
    std::vector<std::reference_wrapper<sf::Sprite> > m_sprite_ref_stack;

    // Storage container for most textures.
    std::vector<sf::Texture> m_texture_storage;





};

