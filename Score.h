#pragma once
class Score
{
	private:
		//variable global para guardar el score para ganar
		static const int winningScore;

		//Variable para guardar el texto que se mostrara
		unsigned int text;

		//Variable para guardar el score
		int score;

		//Actualizara el texto que se muestra en pantalla
		void updateText();

	public:
		//Constructor
		Score(unsigned int font, float x);

		//Funci�n que a�adira puntos al score
		void addPoint();

		//Funci�n que reiniciara el score a 0
		void resetScore();

		//Funci�n que valida si algun jugador gano
		bool hasWinningScore() const;
};