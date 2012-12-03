/* objects.hpp
 * 
 * Defines game::objects::object, the base class for every entity in the game.
 *
 * Also defined is game::objects::lobjects, the universal list of all objects.
 * */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

namespace game 
{
	namespace objects 
	{

		class object
		{
			public:
				object(float, float,float,  sf::Image * );
				//~object();
				float Speed;
				sf::Sprite Sprite;
				void update();
				void draw();
				void Die();				
		};
		
		vector<object *> lobjects;
		
		object::object (float x, float y, float s = 50.f, sf::Image * Image=NULL) 
		{
			Speed = s; 
			Sprite.SetX(x);
			Sprite.SetY(y);
			if (!(Image==NULL))
			{
				Sprite.SetImage(*Image);
			}
			lobjects.push_back(this);
		}
		
		
	}
}
