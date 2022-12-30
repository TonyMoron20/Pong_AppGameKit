# Pong (1972) creado en AppGameKit
En este repositorio se encuentra una recreación del clasico juego de pong hecho totalmente con el motor de juegos AppGameKit.
Ademas de recrear este juego, igual se incluyen nuevas funciones que ayudaran a comprender mejor las funciones que ofrece este software.

### agk::Print()
Muestra en pantalla el mensaje que se le indique, ademas de que da un salto de línea automaticamente.

### agk::GetRawKeyPressed()
Devolvera un valor igual a 1 si la tecla indicada es presionada, el valor es devuelto cada que se presione la tecla, si esta se mantiene presionada devolvera 0.

### agk::SetClearColor()
Esta función se encarga de cambiar el color de fondo de la pantalla de ejecución, el color mostrado se pasa a traves de valores rgb.

### agk::CreateSprite()
Con esta función se crea un sprite a partir de una image ID que contenga la imagen a usar.

### agk::LoadImage()
Carga una imagen a partir de la ruta que se le pase, y la guarda en una image ID.

### agk::GetImageWidth()
Devuelve el ancho total de la imagen indicada.