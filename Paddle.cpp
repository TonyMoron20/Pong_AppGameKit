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

	//Posici�n inicial que tendra la paleta
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

	//Condici�n para la restricci�n de movimiento de las paletas
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

	//Actualizar posici�n de la paleta
	agk::SetSpritePositionByOffset(sprite, x, y);
}

void Paddle::reset()
{
	y = agk::GetVirtualHeight() / 2.0f;
	agk::SetSpritePositionByOffset(sprite, x, y);
}