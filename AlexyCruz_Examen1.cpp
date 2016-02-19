#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void crear_llenar(char** matriz);

int main(int argc, char*argv[]){
	int size = 7;
	char** matriz = new char*[size];

	crear_llenar(matriz);

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << matriz[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
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
