#include<iostream>
#include<sfml\Graphics.hpp>
using namespace sf;
using namespace std;
class Entity {
	int speed;
	int HP;
public:
	virtual void Movement() = 0;
};


int main() {

	RenderWindow window(VideoMode(1280, 720), "TOWER DEFENCE GAME",Style::Default);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			
			//Update




			window.clear();
			//Draw









			window.display();
		}


	}



	return 0;
}