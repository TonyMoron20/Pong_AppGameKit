// Includes
#include "template.h"
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);

	//Cambia el color de fondo de la pantalla de ejecución a negro
	agk::SetClearColor( 26, 26, 26 );

	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);
	agk::SetWindowAllowResize(0);
	agk::SetWindowTitle("Pong");

	//Inicialización de variable screen
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

	//Se crea el objeto de tipo Ball
	ball = new Ball(playerPaddle, aiPaddle);

	//Se carga la fuente que usaran los scores
	unsigned int font = agk::LoadFont("media/kongtext.ttf");

	//Se crean los objetos de tipo Score
	playerScore = new Score(font, agk::GetVirtualWidth() * 0.2f);
	aiScore = new Score(font, agk::GetVirtualWidth() * 0.8f);
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

	//Control del jugador
	if (agk::GetRawKeyState(AGK_KEY_UP) || agk::GetRawKeyState(AGK_KEY_W))
	{
		playerPaddle->moveUp();
	}
	if (agk::GetRawKeyState(AGK_KEY_DOWN) || agk::GetRawKeyState(AGK_KEY_S))
	{
		playerPaddle->moveDown();
	}

	//Control de la IA
	if (ball->getY() < aiPaddle->getY())
	{
		aiPaddle->moveUp();
	}
	if (ball->getY() > aiPaddle->getY())
	{
		aiPaddle->moveDown();
	}

	//Movimiento de la pelota
	ball->update();
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
