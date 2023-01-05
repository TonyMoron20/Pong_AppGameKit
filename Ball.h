#pragma once

class Paddle;

class Ball
{
	private:
		//Variable para la velocidad con la que se movera la pelota
		const static float moveSpeed;

		//Variable para guardar el sprite de la pelota
		unsigned int sprite;

		//Variables para el movimiento de la pelota
		float x, y, velX, velY;

		//Arreglo de tipo Paddle para guardar la referencia a las dos paletas
		Paddle* paddles[2];

		//Variable bool para guardar el estado de colisión entre pelota y paletas
		bool collidingWithPaddle;

		//Variable para guardar el sonido de rebote
		unsigned int bounceSound;

	public:
		//Constructor de la clase
		Ball(Paddle* leftPaddle, Paddle* rightPaddle);

		//Función para actualizar el movimiento de la pelota
		void update();

		//Función para obtener la posición en Y actual
		float getY() const;

		//Función para obtener la posición en X actual
		float getX() const;

		//Función para reiniciar los atributos de la pelota
		void reset();
};

