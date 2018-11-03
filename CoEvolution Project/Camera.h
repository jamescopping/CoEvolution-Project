#pragma once
#include "SFML/Graphics.hpp"
#define ASPECT_RATIO_WIDTH 4
#define ASPECT_RATIO_HEIGHT 3

class Camera {
public:
	Camera() {}
	Camera(sf::RenderWindow* window, sf::Vector2u wh, sf::Vector2f offset);
	~Camera() {}

	void Restore();
	void Update(sf::Vector2f point);

	const sf::FloatRect GetCameraBox();

	void Resize(sf::Event event);
private:
	sf::RenderWindow* _window;
	sf::View _view;
	sf::Vector2f _offset;
};
