// Includes
#include "template.h"
#include "Paddle.h"

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);

	//Cambia el color de fondo de la pantalla de ejecuci�n a negro
	agk::SetClearColor( 26, 26, 26 );

	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);
	agk::SetWindowAllowResize(0);
	agk::SetWindowTitle("Pong");

	//Inicializaci�n de variable screen
	screen = gamescreen::gameScreen;

	//Se carga y se posiciona la imagen de la red
	const unsigned int net = agk::LoadSprite("media/net.png");
	agk::SetSpritePositionByOffset(net, agk::GetVirtualWidth()/2.0f, agk::GetVirtualHeight()/2.0f );

	//Se carga la imagen que tendran las paletas
	unsigned int paddleImage = agk::LoadImage("media/paddle.png");

	//Variable que contiene la distancia que habra entre el borde de la pantalla y la paleta
	const static float distanceFromEdge = 20.0f + (agk::GetImageWidth(paddleImage)/2.0f);

	//Se crean las variables para las coordenadas en X de cada paleta
	const float playerX = distanceFromEdge;
	const float aiX = agk::GetVirtualWidth() - distanceFromEdge;

	//Se crean los objetos de tipo Paddle
	playerPaddle = new Paddle(paddleImage, playerX);
	aiPaddle = new Paddle(paddleImage, aiX);

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

//Funci�n para la pantalla de inicio
void app::updateStartScreen()
{
	agk::Print("Pantalla de inicio");
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::gameScreen;
	}
}

//Funci�n para la pantalla de juego
void app::updateGameScreen()
{
	agk::Print("Pantalla de juego");
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::resultScreen;
	}

	//Control del jugador
	if (agk::GetRawKeyState(AGK_KEY_UP) || agk::GetRawKeyState(AGK_KEY_W))
	{
		playerPaddle->moveUp();
	}
	if (agk::GetRawKeyState(AGK_KEY_DOWN) || agk::GetRawKeyState(AGK_KEY_S))
	{
		playerPaddle->moveDown();
	}
}

//Funci�n para la pantalla de resultados
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
