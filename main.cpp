#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>
//#include "g_game.hpp"
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
	Vector2f v1_Center (400,1300);
	View View1(v1_Center, v1_HalfSize);
	
	game::objects::main_c character (400.f,1300.f,200.f,&mc_Image);
	
	game::objects::border border1 (0,1000, 20.f, &mc_Image);
	border1.set_dims(800,2);
	game::objects::border border2 (0,1000, 20.f, &mc_Image);
	border2.set_dims(2,600);
	game::objects::border border3 (800, 1000, 20.f, &mc_Image);
	border3.set_dims(2,600);
	game::objects::border border4 (0,1600, 20.f, &mc_Image);
	border1.set_dims(800,2);

	int los = game::objects::lobjects.size();
	
	vector<game::objects::border> borders;
	borders.push_back(border1);
	borders.push_back(border2);
	borders.push_back(border3);
	borders.push_back(border4);
	
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
		debugfs::ViewCheck(&View1, &character, &Text);
		App.Clear();
				
		int sz = borders.size();
		
		game::Move_View_y(&View1, &Clock, 20.f);

		character.update(&App, &Clock, &View1, 20.f);
		for (signed i = 0; i<sz; i++) 
		{
			
			borders[i].update(&App, &Clock, &View1, &character, 20.f);
			borders[i].draw(&App);
		}
		
		character.draw(&App);
		App.Draw(Text);
		
		App.Display();
		Clock.Reset();
	}
}
