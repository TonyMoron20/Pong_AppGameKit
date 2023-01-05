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

### agk::RandomSing()
Le da un signo positivo o negativo de manera aleatoria al valor indicado.

### agk::Random()
Devuelve un número de forma aleatoria que se encuentre entre los dos números que se indiquen en el parentesis.

### agk::GetSpriteCollision()
Devuelve el valor de 1 si los dos sprites que se indiquen dentro del parentesis tienen una colisión, en caso contrario devuelve 0.

### agk::LoadSoundOGG()
Carga un archivo de sonido de tipo ".ogg" oara poder usarlo dentro de la aplicación.

### agk::PlaySound()
Reproduce el sonido que se indique en los parentesis.

### agk::GetSpriteYByOffset()
Obtiene la posición en Y del sprite indicado, el punto de origen se toma desde el centro del sprite.

### agk::CreateText()
Crea un objeto de tipo texto, y este mostrara en pantalla el texto que se le pase como cadena en el parentesis.

### agk::SetTextAlignment()
Alinea el texto segun se le indique, siendo 0 = izquierda, 1 = centrado, 2 = derecha.

### agk::SetTextFont()
Hace que la fuente que use el texto sea cambiada por la que se indique.

### agk::SetTextSize()
Establece el tamaño con el que se mostrara el texto.

### agk::SetTextPosition()
Establece la posición en la que se mostrara el texto.

### agk::Str()
Convierte datos de tipo numerico a tipo string.

### agk::SetTextString()
Actualiza el texto del objeto de tipo texto.

### agk::DeleteString()
Elimina de la memoria la cadena que se le indique.

### agk::LoadFont()
Carga desde una ruta una fuente para texto y la guarda como un font ID.

### agk::SetTextVisible()
Con esta función se indica si el texto sera visible o no en la pantalla, 0 = invisible, 1 = visible.