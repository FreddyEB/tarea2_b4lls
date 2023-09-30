# Pasos de Compilación
- **Integrantes Tarea 2:** [Freddy Bacigalupo y Vicente Giaconi]

1. En esta ocasión, para compilar los archivos de la tarea 2 se utilizó un makefile hecho manualmente para satisfacer nuestras necesidades. Compilar Utilizando la *"Terminal", "Command Prompt"  o la "Integrated Terminal"* si se está utilizando Visual Studio Code, se ingresa el comando *"make"* y empieza el proceso de compilación de archivos, donde se creará un ejecutable llamado "_tarea2_".

2. Luego, se debe ejecutar el programa escribiendo *"./tarea2 (filas)(columnas)(coordenada_x de de entrada)(coordenada_y de entrada) (coordenada_x de de salida)(coordenada_y de salida) ("pila" o "cola")"* lo anterior va sin paretesis, solo están ahí por un tema de orden y mejor compresión del README. Esto imprimirá en consola la solución generada(*solve_pila* y *solve_cola*) con el laberinto normal y el laberinto solucionado.

3. Para evitar que que salten errores del tipo "[-Wc++11-extensions]", se agregaron las flags "FLAGS" en el makefile, que tienen la siguiente instrucción de compilación: *g++ -std=c++11*.

4. Finalmente, para poder eliminar los ejecutables, solo se debe correr el siguiente comando en consola: *"make clean"*.

