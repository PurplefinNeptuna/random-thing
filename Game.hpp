#include<SFML/Graphics.hpp>

class Game {
  public:
	Game();
	void Run();

  private:
	void ProcessEvents();
	void Update(sf::Time deltaTime);
	void Render();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    static const float playerSpeed;
    static const sf::Time SPF; //opposite of FPS

	sf::RenderWindow mainWindow;
	sf::Texture mainTexture;
	sf::Sprite mainPlayer;

	bool mainMoveUp;
	bool mainMoveDown;
	bool mainMoveLeft;
	bool mainMoveRight;
};
