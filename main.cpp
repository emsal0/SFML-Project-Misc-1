#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "main_char.hpp"
#include "debugfs.hpp"
using namespace std;
using namespace sf;

int main() 
{
	RenderWindow App;
	App.Create(VideoMode(800,600), "SFML Window");
	
	Image mc_Image;
	if (!mc_Image.LoadFromFile("Images/az.jpg")) {return EXIT_FAILURE;}
	
	Vector2f v1_HalfSize (400,300);
	Vector2f v1_Center (400,300);
	View View1(v1_Center, v1_HalfSize);
	
	game::objects::main_c character (25.f,25.f,&mc_Image,200.f);
	
	sf::String Text;
	
	while (App.IsOpened()) 
	{
		Event Event;
		while (App.GetEvent(Event)) 
		{
			if (Event.Type == Event::Closed) 
				App.Close();
		}
		Clock Clock;
		App.SetView(View1);
		debugfs::ViewCheck(&View1, &Text);
		App.Clear();
		
		character.update(&App, &Clock, &View1);
		
		character.draw(&App);
		App.Draw(Text);
		
		App.Display();
	}
}
