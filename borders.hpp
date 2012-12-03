#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <typeinfo>
//#include "objects.hpp" 
#include <cmath>
#include "main_char.hpp"
#include "basefs.hpp"
using namespace std;

namespace game 
{
	namespace objects
	{
		class border: public object
		{
			public:
				void update(sf::RenderWindow *, sf::Clock *, sf::View *, game::objects::main_c *, float);
				void set_dims (float, float);
				void mc_interact (sf::View *, game::objects::main_c *, float);
				void draw(sf::RenderWindow *);
				border (float x, float y, float s, sf::Image * Image) : object ( x, y,  s, Image) {};
		};
		
		void border::set_dims (float w, float h)
		{
			Sprite.Resize (w, h);
//			cout << Sprite.GetSize().x << ", " << Sprite.GetSize().y << endl;
		}
		
		void border::mc_interact(sf::View * View, game::objects::main_c * main_char, float dd)
		{
			
			
			float cx = Sprite.GetPosition().x;
			float cy = Sprite.GetPosition().y;
			float cw = Sprite.GetSize().x;
			float ch = Sprite.GetSize().y;

			
			
			float vx = View->GetCenter().x - View->GetHalfSize().x;
			float vy = View->GetCenter().y - View->GetHalfSize().y;
		
			float vhx = View->GetHalfSize().x;
			float vhy = View->GetHalfSize().y;
		
			float cx2 = main_char->Sprite.GetPosition().x;
			float cy2 = main_char->Sprite.GetPosition().y;
			float cw2 = main_char->Sprite.GetSize().x;
			float ch2 = main_char->Sprite.GetSize().y;
		
			
			
			if (CheckCollision(cx, cy, cw, ch, cx2, cy2, cw2, ch2))
			{
				if (Sprite.GetSize().x > Sprite.GetSize().y)
				{
					main_char->Sprite.SetX(vx + cx + main_char->Sprite.GetPosition().x );
					main_char->Sprite.SetY(vy + cy + ch - main_char->Sprite.GetPosition().y );
				}
				else 
				{
					main_char->Sprite.SetX(vx + cx + cw - main_char->Sprite.GetPosition().x );
					main_char->Sprite.SetY(View->GetCenter().y - View->GetHalfSize().y + cy + main_char->Sprite.GetPosition().y );
				}
			}
				
			
		}			
		
		void border::update(sf::RenderWindow * App, sf::Clock * Clock, sf::View * View, game::objects::main_c * main_char, float vs)
		{
			
			//Clock->Reset();
			
			float ElapsedTime = Clock->GetElapsedTime();
			
			float dd = vs * ElapsedTime;
			
			float yp = Sprite.GetPosition().y;
		
			
			Sprite.SetY(yp - dd);
			
	
		
	//		View->Move( 0, -dd / 4);
			
			this->mc_interact(View, main_char, dd);
		}
		
		void border::draw(sf::RenderWindow * App) 
		{
			App->Draw(Sprite);
		}
	}
}