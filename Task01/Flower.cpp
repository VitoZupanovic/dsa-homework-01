#include "Flower.h"
#include <SFML/Graphics.hpp>


Flower::Flower(sf::RenderWindow* window)
{
	
	this->window = window;
	this->headRadius = 40.f;
	this->numOfPetals = 25;
	this->petalWidth = 15;
	petals.setFillColor(sf::Color(255, 0, 255));
	leaf.setFillColor(sf::Color(0,255,0));
	stem.setFillColor(sf::Color(0, 255,0));
	head.setFillColor(sf::Color(255, 255, 0));
}

void Flower::setPetalsColor(sf::Color color)
{
	petals.setFillColor(color);
}

void Flower::setStemColor(sf::Color color)
{
	stem.setFillColor(color);
}

void Flower::setHeadColor(sf::Color color)
{
	head.setFillColor(color);
}

void Flower::setLeafColor(sf::Color color)
{
	leaf.setFillColor(color);
}

void Flower::setNumOfPetals(int numOfPetals)
{
	this->numOfPetals = numOfPetals;
}

void Flower::setPetalWidth(int petalWidth)
{
	this->petalWidth = petalWidth;
}

void Flower::setHeadRadius(float headRadius)
{
	this->headRadius = headRadius;
}

void Flower::draw()
{

	
	stem.setSize({ 350.f,5.f });
	stem.setPosition({ window->getSize().x / 2.f, window->getSize().y / 2.f });
	stem.rotate(sf::degrees(90));


	
	leaf.setPointCount(5); 
	leaf.setPoint(0, { 0.f, 0.f });       
	leaf.setPoint(1, { 50.f, -30.f });     
	leaf.setPoint(2, { 150.f, -10.f });   
	leaf.setPoint(3, { 50.f, 40.f });     
	leaf.setPoint(4, { 0.f, 0.f });

	leaf.setPosition({ (window->getSize().x / 2.f) - 3.f, (window->getSize().y / 2.f) + 200.f });


	
	int points = numOfPetals * petalWidth;
	float angle = 360.f / points;
	petals.setPointCount(points);
	for (int i = 0; i < points; i++) {
		if ((i + 1) % petalWidth < 3) petals.setPoint(i, sf::Vector2f(headRadius, sf::degrees(i * angle - 90.f)));
		else petals.setPoint(i, sf::Vector2f(headRadius * 2.f, sf::degrees(i * angle - 90.f)));
	}
	petals.setPosition({ window->getSize().x / 2.f, window->getSize().y / 2.f });

	
	head.setRadius(headRadius);
	head.setOrigin({ headRadius, headRadius });
	head.setPosition({ window->getSize().x / 2.f, window->getSize().y / 2.f });

	
	while (window->isOpen())
	{
		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window->close();
		}

		
		window->clear();
		window->draw(stem);
		window->draw(leaf);
		window->draw(petals);
		window->draw(head);
		window->display();
	}
}