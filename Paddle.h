#pragma once
class Paddle
{
	private:
		//Variable para indicar la velocidad con la que se movera la paleta
		const static float moveSpeed;

		//Variable para guardar la imagen del sprite
		unsigned int sprite;

		//Coordenadas para posicionar a las paletas dentro de la ventana de juego
		float x, y;

		//Funcion para el movimiento de las paletas
		void move(float moveDirection);

	public:
		//Constructor de la clase
		Paddle(unsigned int image, float startX);

		//Funciones para los distintos comportamientos que tendra la paleta
		void moveUp();
		void moveDown();
		void reset();
};

