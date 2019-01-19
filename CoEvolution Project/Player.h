#pragma once
#include "Game.h"
#include "Level.h"
#include "IEntity.h"
#include "AnimationController.h"

class Player : virtual public IEntity {

public:

	Player(GameDataRef data, std::vector<Level>* levels, sf::Vector2f wh);
	~Player();

	virtual void init() override;
	virtual void update(float dt) override;
	virtual void draw(float dt) override;

	float percentageOfLevelCompleted();
	bool isAlive();
	void jump();
	void stopJumping();
	void left();
	void right();
	void stop();
	virtual void die();
	void respawn();
	void restart();
	virtual void finish();
	void nextLevel();
	const int& getCurrentLevel();
	bool isFinished();

	void setProgress(float progress);
	void setColor(sf::Color color);
	const float& getProgress() const;
	const sf::Vector2f& getPosition() const;

protected:
	GameDataRef _data;

	AnimationController* _animController;
	sf::Sprite _sprite;
	std::vector<Level>* _levels;
	sf::Clock _timer;
	int _currentLevel;

	float _speed, _jumpVelocity;
	const int _startingLives = 3;
	int _direction = 0, _lives = _startingLives, _currentCheckpoint = 0;
	bool _falling, _jumping, _holdingJump, _jump, _grounded, _finished, _exit;
	float _progress = 0.0f;
};