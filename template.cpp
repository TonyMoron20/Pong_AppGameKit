// Includes
#include "template.h"

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);
	agk::SetWindowAllowResize(0);
	agk::SetWindowTitle("Pong");

	//Inicialización de variable screen
	screen = gamescreen::gameScreen;
}

int app::Loop (void)
{
	//Switch que ejecutara las pantallas
	switch (screen)
	{
		case gamescreen::startScreen:
			updateStartScreen();
			break;
		case gamescreen::gameScreen:
			updateGameScreen();
			break;
		case gamescreen::resultScreen:
			updateResultScreen();
			break;
	}

	agk::Sync();

	return 0; // return 1 to close app
}

//Función para la pantalla de inicio
void app::updateStartScreen()
{
	agk::Print("Pantalla de inicio");
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::gameScreen;
	}
}

//Función para la pantalla de juego
void app::updateGameScreen()
{
	agk::Print("Pantalla de juego");
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::resultScreen;
	}
}

//Función para la pantalla de resultados
void app::updateResultScreen()
{
	agk::Print("Pantalla de resultados");
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::startScreen;
	}
}

void app::End (void)
{

}
