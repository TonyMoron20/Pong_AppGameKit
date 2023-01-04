#include "Paddle.h"
#include "agk.h"

const float Paddle::moveSpeed = 360.0f;

Paddle::Paddle(unsigned int image, float startX)
{
	//Se inicializa el sprite de la paleta
	sprite = agk::CreateSprite(image);

	//Se inicializan las coordenadas X e Y que tendra la paleta
	x = startX;
	y = agk::GetVirtualHeight()/2.0f;

	//Posición inicial que tendra la paleta
	agk::SetSpritePositionByOffset(sprite, x, y);
}

void Paddle::moveUp()
{
	move(-1.0f);
}

void Paddle::moveDown()
{
	move(1.0f);
}

void Paddle::move(float moveDirection)
{
	const float moveY = agk::GetFrameTime() * moveSpeed * moveDirection;
	const float newY = y + moveY;

	//Variables para restringir movimiento vertical de la paleta
	const float minY = agk::GetSpriteHeight(sprite) / 2.0f;
	const float maxY = agk::GetVirtualHeight() - minY;

	//Condición para la restricción de movimiento de las paletas
	if (newY < minY)
	{
		y = minY;
	}
	else if (newY > maxY)
	{
		y = maxY;
	}
	else
	{
		y = newY;
	}

	//Actualizar posición de la paleta
	agk::SetSpritePositionByOffset(sprite, x, y);
}

void Paddle::reset()
{
	y = agk::GetVirtualHeight() / 2.0f;
	agk::SetSpritePositionByOffset(sprite, x, y);
}

bool Paddle::isCollidingWithSprite(unsigned int otherSprite) const
{
	//Devolvera un valor "true" si el valor devuelto por la función "GetSpriteCollision()" es igual a 1
	return 1 == agk::GetSpriteCollision(sprite, otherSprite);
}