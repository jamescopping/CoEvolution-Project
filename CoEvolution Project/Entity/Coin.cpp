#include "Coin.h"

Coin::Coin(GameDataRef data): _data(data)
{
	AssetManager::rescale(this->_sprite, ZOOM_FACTOR);
	this->_position = sf::Vector2f(0.0f, 0.0f);
	this->_animController = new AnimationController(this->_sprite);
	std::vector<unsigned int> animIds = std::vector<unsigned int>();
	animIds.push_back(COIN_IDLE);
	this->_animController->mapAnimations(&this->_data->assetManager, animIds);
	this->_animController->nextAnimation(COIN_IDLE, true, false);
}

Coin::~Coin()
{
	delete this->_animController;
}

void Coin::init()
{
	//this->_velocity = sf::Vector2f(10.0f, 10.0f);
	//this->activate();
}

void Coin::update(float dt)
{
	this->_sprite.setPosition(this->_position);
}

void Coin::draw(float dt)
{
	this->_animController->update();
	this->_data->window.draw(this->_sprite);
}

void Coin::collect()
{
	
	// play sound
	// have destroy time out
	// destroy the entity
	//change to animation state collected and start anim timer
	//in the update function call destroy after the the anim is done
	destory();
}
