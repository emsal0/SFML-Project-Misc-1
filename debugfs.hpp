#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "borders.hpp"

namespace debugfs 
{
	void ViewCheck(sf::View * View, game::objects::main_c * main_char, sf::String * Text) 
	{
		string xp;
		stringstream oxp;
		float xpos = main_char->Sprite.GetPosition().x;
		oxp << xpos;
		xp = oxp.str();
		
		string yp;
		stringstream oyp;
		float ypos = main_char->Sprite.GetPosition().y;
		oyp << ypos;
		yp = oyp.str();
		
		string fstring = "Character Position: ";
		fstring += xp;
		fstring += ", "; 
		fstring += yp;
		
		Text->SetText(fstring);
		Text->SetX(View->GetCenter().x - View->GetHalfSize().x);
		Text->SetY(View->GetCenter().y - View->GetHalfSize().y);
	}
}
