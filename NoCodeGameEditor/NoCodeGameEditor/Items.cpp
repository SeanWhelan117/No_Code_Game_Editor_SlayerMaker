#include "Items.h"

Items::Items(TextureManager& textureManager) : m_textureManager(textureManager)
{

}

void Items::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect)
{
	playerCollision(t_playerRect);

	for (int i = 0; i < explosiveVector.size(); i++)
	{
		explosiveVector.at(i).get()->update(t_deltaTime);

		if (explosiveVector.at(i).get()->exploded == true)
		{
			spawnExplosion(explosiveVector.at(i).get()->getExplosive().getPosition());
			removeExplosive(i);
		}
	}

	for (int i = 0; i < particleSystemsVector.size(); i++)
	{
		particleSystemsVector.at(i).update(t_deltaTime);
	}

	for (int i = 0; i < collisionCircleVector.size(); i++)
	{
		float scale = collisionCircleVector.at(i).getScale().x;
		collisionCircleVector.at(i).setScale(scale+= 0.3, scale+= 0.3);
	}

}

void Items::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < medkitVector.size(); i++)
	{
		medkitVector.at(i).get()->render(t_window);
	}

	for (int i = 0; i < explosiveVector.size(); i++)
	{
		explosiveVector.at(i).get()->render(t_window);
	}

	for (int i = 0; i < particleSystemsVector.size(); i++)
	{
		particleSystemsVector.at(i).draw(t_window);
	}


	//for (int i = 0; i < collisionCircleVector.size(); i++)
	//{
	//	t_window.draw(collisionCircleVector.at(i));
	//}

}

void Items::addToVector(sf::Vector2f t_itemPosition, int t_itemType)
{

	if (t_itemType == 0)
	{
		Medkit tempMedkit(t_itemPosition, m_textureManager);
		medkitVector.emplace_back(new Medkit(tempMedkit));
	}
	else if (t_itemType == 1)
	{
		Explosive tempExplosive(t_itemPosition, m_textureManager, false);
		explosiveVector.emplace_back(new Explosive(tempExplosive));
	}
	
}

bool Items::isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2)
{
	return t_obj1.intersects(t_obj2);
}

void Items::playerCollision(sf::FloatRect t_playerRect)
{
	
	for (int i = 0; i < medkitVector.size(); i++)
	{
		if (isColliding(medkitVector.at(i).get()->getMedkit().getGlobalBounds(), t_playerRect))
		{
			std::vector<std::unique_ptr<Medkit>>::iterator begin = medkitVector.begin();
			begin += i;
			medkitVector.erase(begin);
			addHealth = true;
		}
	}

	for (int i = 0; i < explosiveVector.size(); i++)
	{
		if (isColliding(explosiveVector.at(i).get()->getExplosive().getGlobalBounds(), t_playerRect) && explosiveVector.at(i).get()->primed == false)
		{
			removeExplosive(i);
			explosivesCollected++;
		}
	}
}

void Items::dropBomb(sf::Vector2f t_playerPos)
{
	Explosive tempExplosive(t_playerPos, m_textureManager, true);
	explosiveVector.emplace_back(new Explosive(tempExplosive));
	std::cout << "exlposiveAdded" << std::endl;
}

void Items::removeExplosive(int t_remove)
{
	std::vector<std::unique_ptr<Explosive>>::iterator begin = explosiveVector.begin();
	begin += t_remove;
	explosiveVector.erase(begin);
}

void Items::spawnExplosion(sf::Vector2f t_explosionPosition)
{
	ParticleSystem tempParticleSystem;
	tempParticleSystem.addExplosion(t_explosionPosition.x, t_explosionPosition.y, 250);
	particleSystemsVector.push_back(tempParticleSystem);

	sf::CircleShape tempCircle;
	tempCircle.setOutlineThickness(1);
	tempCircle.setOutlineColor(sf::Color::White);
	tempCircle.setFillColor(sf::Color(0, 0, 0, 0));
	tempCircle.setRadius(10);
	tempCircle.setPosition(t_explosionPosition.x, t_explosionPosition.y);
	tempCircle.setOrigin(tempCircle.getLocalBounds().width / 2, tempCircle.getGlobalBounds().height / 2);
	collisionCircleVector.push_back(tempCircle);
}