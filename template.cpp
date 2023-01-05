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
	screen = gamescreen::startScreen;

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

	//Se crea el texto que mostrara el mensaje de resultado
	resultText = agk::CreateText("");
	agk::SetTextAlignment(resultText, 1);
	agk::SetTextFont(resultText, font);
	agk::SetTextSize(resultText, 30.0f);
	agk::SetTextPosition(resultText, agk::GetVirtualWidth() / 2.0f, agk::GetVirtualHeight() * 0.3f);
	agk::SetTextVisible(resultText, 0);

	//Se crea el texto que mostrara las instrucciones para cambiar de pantalla
	nextScreenText = agk::CreateText("Presiona espacio para iniciar");
	agk::SetTextAlignment(nextScreenText, 1);
	agk::SetTextFont(nextScreenText, font);
	agk::SetTextSize(nextScreenText, 20.0f);
	agk::SetTextPosition(nextScreenText, agk::GetVirtualWidth() / 2.0f, agk::GetVirtualHeight() * 0.5f);

	//Se cargan los sonidos de victoria y derrota
	winSound = agk::LoadSoundOGG("media/win.ogg");
	gameOverSound = agk::LoadSoundOGG("media/gameOver.ogg");
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
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::gameScreen;
		agk::SetTextVisible(nextScreenText, 0);
	}
}

//Función para la pantalla de juego
void app::updateGameScreen()
{
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

	//Sistema de puntos
	bool gameOver = false;
	if (ball->getX() < 0.0f)
	{
		aiScore->addPoint();
		ball->reset();
		if (aiScore->hasWinningScore())
		{
			agk::SetTextString(resultText, "¡La IA gano!");
			agk::PlaySound(gameOverSound);
			gameOver = true;
		}
	}
	if (ball->getX() > agk::GetVirtualWidth())
	{
		playerScore->addPoint();
		ball->reset();
		if (playerScore->hasWinningScore())
		{
			agk::SetTextString(resultText, "¡El jugador gano!");
			agk::PlaySound(winSound);
			gameOver = true;
		}
	}

	//En caso de que alguno de los jugadores llegue al marcador ganador el juego cambiara a la pantalla de resultados
	if (gameOver)
	{
		agk::SetTextString(nextScreenText, "Presiona espacio para continuar");
		agk::SetTextVisible(resultText, 1);
		agk::SetTextVisible(nextScreenText, 1);
		screen = gamescreen::resultScreen;
	}

	//Movimiento de la pelota
	ball->update();
}

//Función para la pantalla de resultados
void app::updateResultScreen()
{
	if (agk::GetRawKeyPressed(AGK_KEY_SPACE))
	{
		screen = gamescreen::startScreen;
		playerScore->resetScore();
		aiScore->resetScore();
		playerPaddle->reset();
		aiPaddle->reset();
		agk::SetTextString(nextScreenText, "Presiona espacio para iniciar");
		agk::SetTextVisible(resultText, 0);
	}
}

void app::End (void)
{

}
