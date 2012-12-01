#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "objects.hpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

namespace game
{
	namespace objects 
	{
		class main_c: public object
		{
			public:
				void update (sf::RenderWindow *, sf::Clock *, sf::View *);
				void draw(sf::RenderWindow *);
				void KeyInput(sf::RenderWindow *, float, sf::View *);
				main_c(float x, float y, sf::Image * Image, float s) : object (x,y,Image, s) {};
				
		};
		
		void main_c::KeyInput(sf::RenderWindow * App, float ElapsedTime, sf::View * View) 
		{
			
			float xx = Sprite.GetPosition().x;
			float yy = Sprite.GetPosition().y;
			
			
			if (App->GetInput().IsKeyDown(sf::Key::Up)) yy -= Speed * ElapsedTime;
			if (App->GetInput().IsKeyDown(sf::Key::Down)) yy += Speed * ElapsedTime;
			if (App->GetInput().IsKeyDown(sf::Key::Left)) xx -= Speed * ElapsedTime;
			if (App->GetInput().IsKeyDown(sf::Key::Right)) xx += Speed * ElapsedTime;
			
			Sprite.SetX(xx);
			Sprite.SetY(yy);
			
		}
		
		
		void main_c::update (sf::RenderWindow * App, sf::Clock * Clock, sf::View * View)
		{
			float ElapsedTime = Clock->GetElapsedTime();
			Clock->Reset();
			
			this->KeyInput(App, ElapsedTime, View);
			
			float hsx = View->GetHalfSize().x;
			float hsy = View->GetHalfSize().y;
			
			sf::Vector2f cent = View->GetCenter();
			
			float xp = Sprite.GetPosition().x;
			float yp = Sprite.GetPosition().y;
			
			float Offset = Speed * ElapsedTime;
			float Bound = 20.f;
			
			if (xp < cent.x - hsx + Bound) View->Move( -Offset, 0 );
			if ( (xp + Sprite.GetSize().x ) > cent.x + hsx - Bound) View->Move( Offset, 0 );
			if (yp < cent.y - hsy + Bound) View->Move( 0, -Offset );
			if ( (yp + Sprite.GetSize().y ) > cent.y + hsy - Bound) View->Move( 0, Offset );

		}
			
		void main_c::draw(sf::RenderWindow * App)
		{
			App->Draw(Sprite);
		}
	}
}
