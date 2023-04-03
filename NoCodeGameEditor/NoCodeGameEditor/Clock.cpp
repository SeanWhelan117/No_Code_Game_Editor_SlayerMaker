#include "Clock.h"

Clock::Clock()
{
	loadFiles();
	startClock();
	setupClockDisplay();
}

void Clock::loadFiles()
{
	if (!clockFont.loadFromFile("./ASSETS/FONTS/casio-fx-702p.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}
}

void Clock::update(sf::Time t_deltaTime)
{
	addToClock();
	clockString = std::to_string(minuteTens) + std::to_string(minuteSingles) + colon + std::to_string(secondTens) + std::to_string(secondSingles);
	clockText.setString(clockString);
}

void Clock::render(sf::RenderWindow& t_window)
{
	t_window.draw(clockText);

}

void Clock::startClock()
{
	myClock.restart();
}

void Clock::setupClockDisplay()
{
	clockText.setFont(clockFont);
	clockText.setCharacterSize(100u);
	clockText.setFillColor(sf::Color::Black);
	clockString = std::to_string(minuteTens) + std::to_string(minuteSingles) + colon + std::to_string(secondTens) + std::to_string(secondSingles);
	clockText.setString(clockString);
	clockText.setPosition(sf::Vector2f(100, 100));
}

void Clock::addToClock()
{
	secondSingles = myClock.getElapsedTime().asSeconds();

	if (secondSingles == 9)
	{
		myClock.restart();
		secondSingles = 0;
		secondTens += 1;
	}

	if (secondTens == 6)
	{
		myClock.restart();
		secondSingles = 0;
		secondTens = 0;
		minuteSingles += 1;
	}

	if (minuteSingles > 9)
	{
		myClock.restart();
		secondSingles = 0;
		secondTens = 0;
		minuteSingles = 0;
		minuteTens += 1;
	}

	if (minuteTens > 5)
	{
		myClock.restart();
		secondSingles = 0;
		secondTens = 0;
		minuteSingles = 0;
		minuteTens = 0;
	}
}
