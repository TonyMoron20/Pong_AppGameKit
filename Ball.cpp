#include "Ball.h"
#include "agk.h"

const float Ball::moveSpeed = 600.0f;

Ball::Ball()
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
}

void Ball::update()
{
	//Se obtiene el frame time
	const float frameTime = agk::GetFrameTime();

	//Se actualizan las variables para posicionar a la pelota
	x += velX * frameTime;
	y += velY * frameTime;

	//Se actualiza la posición de la pantalla
	agk::SetSpritePositionByOffset(sprite, x, y);
}