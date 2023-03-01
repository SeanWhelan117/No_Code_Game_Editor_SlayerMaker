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
	viewsCreation();
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
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			processMouseClicks(newEvent);
		}
		if (sf::Event::TextEntered == newEvent.type)
		{
			processTextEntered(newEvent);
		}
		if (sf::Event::MouseWheelScrolled == newEvent.type)
		{
			//std::cout << newEvent.mouseWheelScroll.delta << std::endl;
			processMouseWheel(newEvent);
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

	if (sf::Keyboard::Tab == t_event.key.code)
	{
		if (myState == GameState::gameOptions)
		{
			myState = GameState::mainmenu;
		}
		else if (myState == GameState::createGame)
		{
			myState = GameState::gameOptions;
		}
		else if (myState == GameState::chooseGame)
		{
			myState = GameState::mainmenu;
		}
		else if (myState == GameState::options)
		{
			myState = GameState::mainmenu;
		}
		else if (myState == GameState::testGame)
		{
			myState = GameState::createGame;
		}
	}

	if (gameOptions.canType == true)
	{
		if (sf::Keyboard::BackSpace == t_event.key.code)
		{
			if (!gameOptions.gameName.empty())
			{
				gameOptions.gameName.pop_back();
			}

		}
	}

	
}

void Game::processMouseClicks(sf::Event t_event)
{
	if (sf::Mouse::Left == t_event.mouseButton.button)
	{
		changeGridSize = true;
	}


}

void Game::processTextEntered(sf::Event t_event)
{
	if (gameOptions.canType == true)
	{
		if (t_event.text.unicode != 8)
		{
			if (gameOptions.gameName.size() < 12)
			{
				gameOptions.gameName += t_event.text.unicode;
			}
		}
	}
}

void Game::processMouseWheel(sf::Event t_event)
{
	
	if (mainViewActive == true)
	{
		if (scrolling == false)
		{
			if (t_event.mouseWheelScroll.delta == 1)
			{
				//Zooming In
				zoomAmount -= 0.1;
				mainView.zoom(zoomAmount);
			}
			else if (t_event.mouseWheelScroll.delta == -1)
			{
				zoomAmount += 0.1;
				mainView.zoom(zoomAmount);
			}
			//std::cout << zoomAmount << std::endl;
			zoomAmount = 1;
		}
		else if (scrolling)
		{
			sf::Vector2f viewPos = mainView.getCenter();
			if (t_event.mouseWheelScroll.delta == 1)
			{
				viewPos.y -= 15;
				mainView.setCenter(viewPos);
			}
			else if (t_event.mouseWheelScroll.delta == -1)
			{
				viewPos.y += 15;
				mainView.setCenter(viewPos);
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));

	if (m_exitGame || myState == GameState::exitGame)
	{
		m_window.close();
	}

	if (myState != GameState::testGame)
	{
		m_window.setView(mainView);
		if (myState != GameState::createGame)
		{
			mainView.reset(sf::FloatRect(0, 0, gameWidth, gameHeight));
		}
		m_window.setMouseCursorVisible(true);
	}

	if (myState == GameState::createGame)
	{
		
		mainViewActive = true;
		testViewActive = false;
		if (gridCreated == false)
		{
			gridSize = gameOptions.getGridSize();
			if (myGrid.theGrid.size() > 0)
			{
				myGrid.theGrid.clear();
			}
			myGrid.setupGrid(gridSize);
			gridCreated = true;
		}
		myGrid.update(t_deltaTime);

		if (myTools.wallsPlaced == true)
		{

			for (int i = 0; i < gridSize; i++)
			{
				for (int m = 0; m < gridSize; m++)
				{
					if (myGrid.theGrid.at(m).at(i).getCellShape().getFillColor() == sf::Color::Red)
					{
						createWallVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0);
						numOfWalls++;
					}
					else if (myGrid.theGrid.at(m).at(i).getCellShape().getFillColor() == sf::Color::Green)
					{
						createWallVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1);
						numOfWalls++;
					}
					else if (myGrid.theGrid.at(m).at(i).getCellShape().getFillColor() == sf::Color::Blue)
					{
						createWallVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2);
						numOfWalls++;
					}
				}
			}
			for (int i = 0; i < wallVector.size(); i++)
			{
				wallVector.at(i).loadFiles();
			}
			myTools.wallsPlaced = false;
			wallVectorCreated = true;
		}
		myTools.update(t_deltaTime, m_window, myGrid.theGrid, gridSize, myChoice.choiceMade, myChoice.currentChoice);
		myChoice.update(t_deltaTime, m_window, myTools.currentMode);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			scrolling = true;
		}
		else
		{
			scrolling = false;
		}
	}

	if (myState == GameState::mainmenu)
	{
		gridCreated = false;
		myMenu.update(myState, m_window);

	}
	
	if (myState == GameState::gameOptions)
	{
		gridCreated = false;
		gameOptions.update(t_deltaTime, m_window, myState);
		checkMousePos();

		if (wallVectorCreated == true)
		{
			
			wallVector.clear();
		}
	}

	if (myState == GameState::testGame)
	{
		myPlayer.update(m_window);
		myCrosshair.update(m_window);
		m_window.setMouseCursorVisible(false);
		myBackground.update(gameOptions.chosenBG);
		testView.setCenter(myPlayer.getPlayer().getPosition());
		m_window.setView(testView);
	}
	
	if (myTools.testingGame == true)
	{
		myState = GameState::testGame;
		myTools.testingGame = false;
		
	}

	removeWallVector();

}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	if (myState == GameState::createGame)
	{
		if (gridCreated == true)
		{
			gridSize = gameOptions.getGridSize();
			myGrid.render(m_window, gridSize);
			
			if (wallVectorCreated == true)
			{
				for (int i = 0; i < wallVector.size(); i++)
				{
					wallVector.at(i).render(m_window);
				}
			}
			
			myTools.render(m_window);
			myChoice.render(m_window);
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
	else
	{
		changeGridSize = false;
	}

	if (myState == GameState::testGame)
	{
		myBackground.render(m_window);
		myPlayer.render(m_window);

		for (int i = 0; i < wallVector.size(); i++)
		{
			wallVector.at(i).render(m_window);
		}
		myCrosshair.render(m_window);
	}
	m_window.display();
}


void Game::checkMousePos()
{
	for (int i = 0; i < gameOptions.NUM_OF_TRIANGLES; i++)
	{
		if (gameOptions.triangles[i].getGlobalBounds().contains(mousePos))
		{
			if (changeGridSize == true)
			{
				changeGridSize = false;
				gameOptions.changeGridSize(i);
			}
		}

	}
}

void Game::createWallVector(sf::Vector2f t_wallPos, int t_wallTextNum)
{
	Wall tempWall{t_wallTextNum};

	tempWall.setupWall(t_wallPos);

	wallVector.push_back(tempWall);
}

void Game::removeWallVector()
{
	if (wallVectorCreated == true)
	{
		if (!wallVector.empty())
		{
			for (int i = 0; i < wallVector.size(); i++)
			{
				if (wallVector.at(i).getWall().getGlobalBounds().contains(mousePos))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left()))
					{
						if (myTools.rubberToolSelected)
						{
							vector<Wall>::iterator begin = wallVector.begin();
							begin += i;
							vector<Wall>::iterator remove = wallVector.erase(begin);
						}
					}
					
				}
			}
		}
	}
}

void Game::viewsCreation()
{
	mainView.reset(sf::FloatRect(0,0, gameWidth, gameHeight ));
	testView.reset(sf::FloatRect(100,100, gameWidth * 0.3, gameHeight * 0.3));
}