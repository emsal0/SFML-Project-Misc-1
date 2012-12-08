#include "objects.hpp"
#include <vector> 

class bullet : public object
{
	public:
		void update(sf::RenderWindow *, sf::View * View, float);
		void draw(sf::RenderWindow *);
		bullet (float x, float y, float s, sf::Image * Image) : object (x,y,s,Image);
};

void bullet::update(sf::RenderWindow * App, sf::View * View, float vs)
{
	float ElapsedTime = App->GetFrameTime();
	
	yp = Sprite.GetPosition().y;
	
	dd = vs * ElapsedTime;
	
	yp -= Speed * ElapsedTime;
	
	Sprite.SetY(yp - dd);
	
	
	
}

void bullet::draw(sf::RenderWindow * App)
{
	App->Draw(Sprite);
}

