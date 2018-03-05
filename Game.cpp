#include"Game.hpp"
#include"Vector2D.hpp"

const float Game::playerSpeed = 150.f;
const sf::Time Game::SPF = sf::seconds(1.f / 60.f);

Game::Game() :
	mainWindow(sf::VideoMode(640,480), "My Game"),
	mainTexture(),
	mainPlayer(),
	mainMoveUp(false),
	mainMoveDown(false),
	mainMoveLeft(false),
	mainMoveRight(false) {

    if(!mainTexture.loadFromFile("Textures/Ngeng.png")){
        //error
    }

    mainPlayer.setTexture(mainTexture);
	mainPlayer.setPosition(100.f, 100.f);
}

void Game::Run() {
	sf::Clock clock;
	sf::Time lastUpdate = sf::Time::Zero;
	while (mainWindow.isOpen()) {
		ProcessEvents();
		lastUpdate += clock.restart();
		while(lastUpdate > SPF) {
			lastUpdate -= SPF;
			ProcessEvents();
			Update(SPF);
		}
		Render();
	}
}

void Game::ProcessEvents() {
	sf::Event event;
	while(mainWindow.pollEvent(event)) {
		switch(event.type) {
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mainWindow.close();
			break;
		}
	}
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	if(key == sf::Keyboard::W) {
		mainMoveUp = isPressed;
	} else if(key == sf::Keyboard::A) {
		mainMoveLeft = isPressed;
	} else if(key == sf::Keyboard::S) {
		mainMoveDown = isPressed;
	} else if(key == sf::Keyboard::D) {
		mainMoveRight = isPressed;
	}
}

void Game::Update(sf::Time deltaTime) {
	Vector2D movement(0.f, 0.f);
	if(mainMoveUp)
		movement.Y -= playerSpeed;
	if(mainMoveDown)
		movement.Y += playerSpeed;
	if(mainMoveLeft)
		movement.X -= playerSpeed;
	if(mainMoveRight)
		movement.X += playerSpeed;

	mainPlayer.move(SFMLVector2f(movement) * deltaTime.asSeconds());
}

void Game::Render() {
	mainWindow.clear();
	mainWindow.draw(mainPlayer);
	mainWindow.display();
}
