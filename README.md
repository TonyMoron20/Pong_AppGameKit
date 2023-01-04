# Pong (1972) creado en AppGameKit
En este repositorio se encuentra una recreaci�n del clasico juego de pong hecho totalmente con el motor de juegos AppGameKit.
Ademas de recrear este juego, igual se incluyen nuevas funciones que ayudaran a comprender mejor las funciones que ofrece este software.

### agk::Print()
Muestra en pantalla el mensaje que se le indique, ademas de que da un salto de l�nea automaticamente.

### agk::GetRawKeyPressed()
Devolvera un valor igual a 1 si la tecla indicada es presionada, el valor es devuelto cada que se presione la tecla, si esta se mantiene presionada devolvera 0.

### agk::SetClearColor()
Esta funci�n se encarga de cambiar el color de fondo de la pantalla de ejecuci�n, el color mostrado se pasa a traves de valores rgb.

### agk::CreateSprite()
Con esta funci�n se crea un sprite a partir de una image ID que contenga la imagen a usar.

### agk::LoadImage()
Carga una imagen a partir de la ruta que se le pase, y la guarda en una image ID.

### agk::GetImageWidth()
Devuelve el ancho total de la imagen indicada.

### agk::RandomSing()
Le da un signo positivo o negativo de manera aleatoria al valor indicado.

### agk::Random()
Devuelve un n�mero de forma aleatoria que se encuentre entre los dos n�meros que se indiquen en el parentesis.

### agk::GetSpriteCollision()
Devuelve el valor de 1 si los dos sprites que se indiquen dentro del parentesis tienen una colisi�n, en caso contrario devuelve 0.