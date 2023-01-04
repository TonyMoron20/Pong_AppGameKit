#include "Ball.h"
#include "agk.h"
#include "Paddle.h"

const float Ball::moveSpeed = 600.0f;

Ball::Ball(Paddle* leftPaddle, Paddle* rightPaddle)
{
	//Se indica la ruta donde esta la imagen que usara la pelota
	sprite = agk::LoadSprite("media/ball.png");

	//Se da valor a las coordenadas iniciales de la pelota, ademas de posicionarla
	x = agk::GetVirtualWidth() / 2.0f;
	y = agk::GetVirtualHeight() / 2.0f;
	agk::SetSpritePositionByOffset(sprite, x, y);

	/*Variables que se usaran para darle dirección al sprite
	Se hace una conversión implicita con "static_cast" ya que las funciones "Random" devuelven valores enteros*/
	velX = static_cast<float>(agk::RandomSign(agk::Random(40, 100))) / 100.0f;
	velY = static_cast<float>(agk::RandomSign(agk::Random(0, 100))) / 100.0f;

	//Variables para calcular el vector final que dara la velocidad y dirección a la pelota
	const float length = agk::Sqrt((velX * velX) + (velY * velY));
	velX = (velX / length) * moveSpeed;
	velY = (velY / length) * moveSpeed;

	//Se guardan las paletas indicadas como parametro en el arreglo
	paddles[0] = leftPaddle;
	paddles[1] = rightPaddle;

	//La collisión al principio sera falsa
	collidingWithPaddle = false;

	//Se indica el sonido que se guardara
	bounceSound = agk::LoadSoundOGG("media/bounce.ogg");
}

void Ball::update()
{
	//Se obtiene el frame time
	const float frameTime = agk::GetFrameTime();

	//Se actualizan las variables para posicionar a la pelota
	x += velX * frameTime;
	y += velY * frameTime;

	//Variables para saber cual es la posición máxima y mínima que puede tener la pelota en el eje Y
	const float minY = agk::GetSpriteHeight(sprite);
	const float maxY = agk::GetVirtualHeight() - minY;

	//Se revisa si la posición en Y no pasa el valor minimo o maximo, en caso de pasarlo se cambia el signo de la velocidad para alterar la dirección
	if (y < minY)
	{
		y = minY;
		velY = -velY;
		agk::PlaySound(bounceSound);
	}
	else if (y > maxY)
	{
		y = maxY;
		velY = -velY;
		agk::PlaySound(bounceSound);
	}

	//Revisa si hay alguna colisión con alguna de las dos paletas, en caso de haber una colisión cambiara la dirección en el eje X
	if (paddles[0]->isCollidingWithSprite(sprite) || paddles[1]->isCollidingWithSprite(sprite))
	{
		if (!collidingWithPaddle)
		{
			velX = -velX;
			collidingWithPaddle = true;
			agk::PlaySound(bounceSound);
		}
	}
	else
	{
		collidingWithPaddle = false;
	}

	//Se actualiza la posición de la pantalla
	agk::SetSpritePositionByOffset(sprite, x, y);
}