#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

namespace debugfs 
{
	void ViewCheck(sf::View * View, sf::String * Text) 
	{
		string xp;
		stringstream oxp;
		float xpos = View->GetCenter().x;
		oxp << xpos;
		xp = oxp.str();
		
		string yp;
		stringstream oyp;
		float ypos = View->GetCenter().y;
		oyp << ypos;
		yp = oyp.str();
		
		string fstring = "View Center: ";
		fstring += xp;
		fstring += ", "; 
		fstring += yp;
		
		Text->SetText(fstring);
		Text->SetX(xpos - View->GetHalfSize().x);
		Text->SetY(ypos - View->GetHalfSize().y);
	}
}
