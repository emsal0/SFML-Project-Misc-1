#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "objects.hpp"
#include <iostream>
#include <vector>
using namespace std;


class main_c: public object
{
	public:
		void update (sf::RenderWindow *, sf::View *, float);
		void draw(sf::RenderWindow *);
		void KeyInput(sf::RenderWindow *, float, sf::View *);
		main_c(float x, float y, float s, sf::Image * Image) : object (x,y,s, Image) {};
		
};

void main_c::KeyInput(sf::RenderWindow * App, float ElapsedTime, sf::View * View) 
{
	
	float vx = View->GetCenter().x - View->GetHalfSize().x;
	float vy = View->GetCenter().y - View->GetHalfSize().y;
	
	float xx =  Sprite.GetPosition().x - vx;
	float yy = Sprite.GetPosition().y - vy;
	
	
	if (App->GetInput().IsKeyDown(sf::Key::Up)) yy -= Speed * ElapsedTime;
	if (App->GetInput().IsKeyDown(sf::Key::Down)) yy += Speed * ElapsedTime;
	if (App->GetInput().IsKeyDown(sf::Key::Left)) xx -= Speed * ElapsedTime;
	if (App->GetInput().IsKeyDown(sf::Key::Right)) xx += Speed * ElapsedTime;
	
	vx = View->GetCenter().x - View->GetHalfSize().x;
	vy = View->GetCenter().y - View->GetHalfSize().y;
	
	Sprite.SetX(vx + xx);
	Sprite.SetY(vy + yy);
	
}


void main_c::update (sf::RenderWindow * App, sf::View * View, float vs)
{
	float ElapsedTime = App->GetFrameTime();
	
	float dd = vs * ElapsedTime;
		
	this->KeyInput(App, ElapsedTime, View);
	
	
	
	float yp = Sprite.GetPosition().y;
	
	Sprite.SetY(yp - dd );
	
	/*float hsx = View->GetHalfSize().x;
	float hsy = View->GetHalfSize().y;
	
	sf::Vector2f cent = View->GetCenter();
	
	float xp = Sprite.GetPosition().x;
	float yp = Sprite.GetPosition().y;
	
	float Offset = Speed * ElapsedTime;
	float Bound = 20.f;
	
	if (xp < cent.x - hsx + Bound) View->Move( -Offset, 0 );
	if ( (xp + Sprite.GetSize().x ) > cent.x + hsx - Bound) View->Move( Offset, 0 );
	if (yp < cent.y - hsy + Bound) View->Move( 0, -Offset );
	if ( (yp + Sprite.GetSize().y ) > cent.y + hsy - Bound) View->Move( 0, Offset );*/

}
	
void main_c::draw(sf::RenderWindow * App)
{
	App->Draw(Sprite);
}

