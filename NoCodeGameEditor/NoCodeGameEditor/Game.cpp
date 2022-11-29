/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#include "Game.h"
#include <iostream>


/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{  gameWidth, gameHeight, 32U }, "SlayerMaker" },
	m_exitGame{false} //when true game will exit
{

}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame || myState == GameState::exitGame)
	{
		m_window.close();
	}

	if (myState == GameState::createGame)
	{
		myGrid.update(t_deltaTime);
		myGrid.selectStartEndPositions(m_window);
		for (int i = 0; i < 100; i++)
		{
			myWalls.update(t_deltaTime, m_window, myGrid.gridVector);
		}
	}

	if (myState == GameState::mainmenu)
	{
		myMenu.update(myState, m_window);
	}
	
	if (myState == GameState::gameOptions)
	{
		gameOptions.update(t_deltaTime, m_window);
	}
	

}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	if (myState == GameState::createGame)
	{
		myGrid.render(m_window);
		for (int i = 0; i < 100; i++)
		{
			myWalls.render(m_window);
		}
	}

	if (myState == GameState::mainmenu)
	{
		myMenu.render(m_window);
	}

	if (myState == GameState::gameOptions)
	{
		gameOptions.render(m_window);
	}
	m_window.display();
}