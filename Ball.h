#pragma once
class Ball
{
	private:
		//Variable para la velocidad con la que se movera la pelota
		const static float moveSpeed;

		//Variable para guardar el sprite de la pelota
		unsigned int sprite;

		//Variables para el movimiento de la pelota
		float x, y, velX, velY;

	public:
		//Constructor de la clase
		Ball();

		//Función para actualizar el movimiento de la pelota
		void update();
};

