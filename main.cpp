#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>

#include "debugfs.hpp"
using namespace std;
using namespace sf;

int main() 
{
	RenderWindow App;
	App.Create(VideoMode(800,600), "Azventure 2012");
	
	Image mc_Image;
	if (!mc_Image.LoadFromFile("Images/az.jpg")) {return EXIT_FAILURE;}
	
	Vector2f v1_HalfSize (400,300);
	Vector2f v1_Center (400,1300);
	View View1(v1_Center, v1_HalfSize);
	
	main_c character (400.f,1300.f,200.f,&mc_Image);
	
	border border1 (0,1000, 20.f, &mc_Image);
	border1.set_dims(800,1);
	border border2 (0 - character.Sprite.GetSize().x + 10,1000, 20.f, &mc_Image);
	border2.set_dims(1,600);
	border border3 (800 + character.Sprite.GetSize().y - 10, 1000, 20.f, &mc_Image);
	border3.set_dims(1,600);
	border border4 (0,1600, 20.f, &mc_Image);
	border4.set_dims(800,1);

	
	vector<border> borders;
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
		App.SetView(View1);
		debugfs::ViewCheck(&App, &View1, &character, &Text);
		App.Clear();
				
		int sz = borders.size();
		
		Move_View_y(&View1, &App, 20.f);

		character.update(&App, &View1, 20.f);
		for (signed i = 0; i<sz; i++) 
		{
			
			borders[i].update(&App, &View1, &character, 20.f);
	//		borders[i].draw(&App);
		}
		
		character.draw(&App);
		App.Draw(Text);
		
		App.Display();
	}
}
