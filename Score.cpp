#include "Score.h"
#include "agk.h"

//Se inicializa el score para ganar
const int Score::winningScore = 4;

Score::Score(unsigned int font, float x)
{
	//Crea e inicializa el texto que se mostrara en pantalla
	text = agk::CreateText("0");

	//Se establece la alineación que tendra el texto
	agk::SetTextAlignment(text, 1);

	//Se indica la fuente que usara el texto
	agk::SetTextFont(text, font);

	//Se establece el tamaño del texto
	agk::SetTextSize(text, 72.0f);

	//Se establece la posición en la que se mostrara el texto en la pantalla
	agk::SetTextPosition(text, x, agk::GetVirtualHeight() * 0.1f);

	//Se inicializa la variable que llevara el conteo de puntos
	score = 0;
}

void Score::addPoint()
{
	score += 1;
	updateText();
}

void Score::resetScore()
{
	score = 0;
	updateText();
}

void Score::updateText()
{
	char* scoreStr = agk::Str(score);
	agk::SetTextString(text, scoreStr);
	agk::DeleteString(scoreStr);
}

bool Score::hasWinningScore() const
{
	return winningScore == score;
}