#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void crear_llenar(char** matriz);
void mover1(char** matriz);
void mover2(char** matriz);
void imprimir(char** matriz);

int main(int argc, char*argv[]){
	int size = 7;
	int revisar_tablero = 0;
	char** matriz = new char*[size];

	crear_llenar(matriz);
	imprimir(matriz);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] == '.'){
				revisar_tablero++;
			}
		}
	}
////////////////////////////////////////
	while(revisar_tablero != 0){
		revisar_tablero = 0;

	mover1(matriz);
	imprimir(matriz);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] == '.'){
				revisar_tablero++;
			}
		}
	}

	mover2(matriz);
	imprimir(matriz);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] == '.'){
				revisar_tablero++;
			}
		}
	}
	
	}
	

	return 0;
}//fin del main

void imprimir(char** matriz){
	int size = 7;

	for (int i = 0; i < size; i++){
		cout << i << "  ";	
	}
	cout << endl;

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << matriz[i][j] << "  ";
		}
		cout << i;
		cout << endl;
	}
}

void crear_llenar(char** matriz){
	int size = 7;

	//creacion de matriz
	for (int i = 0; i < size; i++){
		matriz[i] = new char[size];	
	}

	//llenado prueba
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if(i == 0 && j == 3){
				matriz[i][j] = '#';
			}else if (i == 3 && j == 0){
				matriz[i][j] = '+';
			}else if (i == 3 && j == 6){
				matriz[i][j] = '+';
			}else if (i == 6 && j == 3){
				matriz[i][j] = '#';
			}else{
				matriz[i][j] = '.';
			}
		}
	}
}

void mover1(char** matriz){
	int size = 7;
	int x1, y1, x2, y2;

	cout << "Ingrese las coordenadas de la pieza a mover (turno de +)" << endl << endl;
	cout << "Ingrese la coordenada en x: ";
	cin >> x1;
	cout << endl;

	cout << "Ingrese la coordenada en y: ";
	cin >> y1;
	cout << endl;

	if (x1 > 6 || x1 < 0 || y1 > 6 || y1 < 0 || matriz[x1][y1] != '+'){
		cout << "No encontramos tu pieza....perdiste el turno" << endl;
	}else{
		cout << "Ingresa las coordenadas a la que quieres mover tu pieza" << endl << endl;
		cout << "Ingrese la coordenada en x: ";
		cin >> x2;
		cout << endl;

		cout << "Ingrese la coordenada en y: ";
		cin >> y2;
		cout << endl;

		if ((x2 > 6 || x2 < 0 || y2 > 6 || y2 < 0) || ((x2 >= x1 + 3) || (x2 <= x1 - 3) || 
			(y2 >= y1 +3) || (y2 <= y1 - 3) || matriz[x1][y1] != '+')){
			cout << "Hiciste un movimiento invalido....perdiste turno" << endl;
		}else{
			if ((x2 == x1 + 2) || (x2 == x1 - 2) || (y2 == y1 + 2) || (y2 == y1 - 2)){//if para mover 2 espacios
				matriz[x1][y1] = '.';
				matriz[x2][y2] = '+';

			if (matriz[x2 + 1][y2] == '#'){//para comer
				matriz[x2 + 1][y2] = '+';
			}
			if (matriz[x2 - 1][y2] == '#'){
				matriz[x2 - 1][y2] = '+';
			}
			if(matriz[x2][y2 + 1] == '#'){
				matriz[x2][y2 + 1] = '+';
			}
			if(matriz[x2][y2 - 1] == '#'){
				matriz[x2][y2 - 1] = '+';
			} 
			if(matriz[x2 + 1][y2 + 1] == '#'){//inicio de diagonales
				matriz[x2 + 1][y2 + 1] = '+';
			}
			if(matriz[x2 + 1][y2 - 1] == '#'){
				matriz[x2 + 1][y2 - 1] = '+';
			}
			if(matriz[x2 - 1][y2 - 1] == '#'){
				matriz[x2 - 1][y2 - 1] = '+';
			}
			if(matriz[x2 - 1][y2 + 1] == '#'){
				matriz[x2 - 1][y2 + 1] = '+';
			}	

			}else if((x2 == x1 + 1) || (x2 == x1 - 1) || (y2 == y1 + 1) || (y2 == y1 - 1)){//if para clonar
				matriz[x2][y2] = '+';

			if (matriz[x2 + 1][y2] == '#'){//para comer
				matriz[x2 + 1][y2] = '+';
			}
			if (matriz[x2 - 1][y2] == '#'){
				matriz[x2 - 1][y2] = '+';
			}
			if(matriz[x2][y2 + 1] == '#'){
				matriz[x2][y2 + 1] = '+';
			}
			if(matriz[x2][y2 - 1] == '#'){
				matriz[x2][y2 - 1] = '+';
			} 
			if(matriz[x2 + 1][y2 + 1] == '#'){//inicio de diagonales
				matriz[x2 + 1][y2 + 1] = '+';
			}
			if(matriz[x2 + 1][y2 - 1] == '#'){
				matriz[x2 + 1][y2 - 1] = '+';
			}
			if(matriz[x2 - 1][y2 - 1] == '#'){
				matriz[x2 - 1][y2 - 1] = '+';
			}
			if(matriz[x2 - 1][y2 + 1] == '#'){
				matriz[x2 - 1][y2 + 1] = '+';
			}

			}
		}
	}
}//fin de void mover y comer

void mover2(char** matriz){
	int size = 7;
	int x1, y1, x2, y2;

	cout << "Ingrese las coordenadas de la pieza a mover (turno de #)" << endl << endl;
	cout << "Ingrese la coordenada en x: ";
	cin >> x1;
	cout << endl;

	cout << "Ingrese la coordenada en y: ";
	cin >> y1;
	cout << endl;

	if (x1 > 6 || x1 < 0 || y1 > 6 || y1 < 0 || matriz[x1][y1] != '#'){
		cout << "No encontramos tu pieza....perdiste el turno" << endl;
	}else{
		cout << "Ingresa las coordenadas a la que quieres mover tu pieza" << endl << endl;
		cout << "Ingrese la coordenada en x: ";
		cin >> x2;
		cout << endl;

		cout << "Ingrese la coordenada en y: ";
		cin >> y2;
		cout << endl;

		if ((x2 > 6 || x2 < 0 || y2 > 6 || y2 < 0) || ((x2 >= x1 + 3) || (x2 <= x1 - 3) || 
			(y2 >= y1 +3) || (y2 <= y1 - 3) || matriz[x1][y1] != '#')){
			cout << "Hiciste un movimiento invalido....perdiste turno" << endl;
		}else{
			if ((x2 == x1 + 2) || (x2 == x1 - 2) || (y2 == y1 + 2) || (y2 == y1 - 2)){//if para mover 2 espacios
				matriz[x1][y1] = '.';
				matriz[x2][y2] = '#';

			if (matriz[x2 + 1][y2] == '+'){//para comer
				matriz[x2 + 1][y2] = '#';
			}
			if (matriz[x2 - 1][y2] == '+'){
				matriz[x2 - 1][y2] = '#';
			}
			if(matriz[x2][y2 + 1] == '+'){
				matriz[x2][y2 + 1] = '#';
			}
			if(matriz[x2][y2 - 1] == '+'){
				matriz[x2][y2 - 1] = '#';
			} 
			if(matriz[x2 + 1][y2 + 1] == '+'){//inicio de diagonales
				matriz[x2 + 1][y2 + 1] = '#';
			}
			if(matriz[x2 + 1][y2 - 1] == '+'){
				matriz[x2 + 1][y2 - 1] = '#';
			}
			if(matriz[x2 - 1][y2 - 1] == '+'){
				matriz[x2 - 1][y2 - 1] = '#';
			}
			if(matriz[x2 - 1][y2 + 1] == '+'){
				matriz[x2 - 1][y2 + 1] = '#';
			}	

			}else if((x2 == x1 + 1) || (x2 == x1 - 1) || (y2 == y1 + 1) || (y2 == y1 - 1)){//if para clonar
				matriz[x2][y2] = '#';

			if (matriz[x2 + 1][y2] == '+'){//para comer
				matriz[x2 + 1][y2] = '#';
			}
			if (matriz[x2 - 1][y2] == '+'){
				matriz[x2 - 1][y2] = '#';
			}
			if(matriz[x2][y2 + 1] == '+'){
				matriz[x2][y2 + 1] = '#';
			}
			if(matriz[x2][y2 - 1] == '+'){
				matriz[x2][y2 - 1] = '#';
			} 
			if(matriz[x2 + 1][y2 + 1] == '+'){//inicio de diagonales
				matriz[x2 + 1][y2 + 1] = '#';
			}
			if(matriz[x2 + 1][y2 - 1] == '+'){
				matriz[x2 + 1][y2 - 1] = '#';
			}
			if(matriz[x2 - 1][y2 - 1] == '+'){
				matriz[x2 - 1][y2 - 1] = '#';
			}
			if(matriz[x2 - 1][y2 + 1] == '+'){
				matriz[x2 - 1][y2 + 1] = '#';
			}

			}
		}
	}
}//fin de void mover y comer
