#include <stdio.h>

int power (int x, int y) {    
	int res = 1;
	for (int z = 0; z < y; z++) {
		res = res * x;
	}
	return res;
} // функция возведения целого числа в целочисленную же степень

int main() {
	int arr[4] = {0}; // инициализируем статический массив из 4 символов, отражающий состояние четырёх регистров
	for (int i = 0; i <= 3; i++) {
                printf("%d ", arr[i]);
        }
	printf("\n");
	char s[25];
	int i, j;
	while (1) { // объявляем вечный цикл: программа не завершается до тех пор, пока не встречена команда "ret"
	for (i = 0; i < 25; i++) {
		scanf("%c", &s[i]);
	        if (s[i]  == '\n') {
			break;
		}
	} // посимвольно считываем отдельно взятую команду
	int a = 0;
	int k = 0;
	if (s[9] == '-') {
		for (int j = i - 1; j >= 10; j--) {
                	a = a + power (10, k) * (s[j] - '0');
                	k++;
        	}
		a = -a;
	}
	else if (s[9] != '-') {
		for (int j = i - 1; j >= 9; j--) {
			a = a + power (10, k) * (s[j] - '0');
			k++;
		}
	} // переводим строку в число, предусматривая случай как отрицательных, так и положительных чисел
	if (s[1] == 'o') { // если введена команда "mov"...
		switch (s[5]) { // идентифицируем первый операнд
			case 'a':
				switch (s[10]) { // идентифицируем второй операнд
					case 'b':
						arr[0] = arr[1];
						break;
					case 'c':
						arr[0] = arr[2];
						break;
					case 'd':
						arr[0] = arr[3];
						break;
					default: // предполагаем, что если вторым операндом оказался не регистр, то им является число
						arr[0] = a;
						break;
				}
				break;
			case 'b':
				switch (s[10]) {
                                        case 'a':
                                                arr[1] = arr[0];
                                                break;
                                        case 'c':
                                                arr[1] = arr[2];
                                                break;
                                        case 'd':
                                                arr[1] = arr[3];
                                                break;
                                        default: // предполагаем, что если вторым операндом оказался не регистр, то им является число
                                                arr[1] = a;
                                                break;
                                }
                                break;
			case 'c':
				switch (s[10]) {
                                        case 'a':
                                                arr[2] = arr[0];
                                                break;
                                        case 'b':
                                                arr[2] = arr[1];
                                                break;
                                        case 'd':
                                                arr[2] = arr[3];
                                                break;
                                        default: // предполагаем, что если вторым операндом оказался не регистр, то им является число
                                                arr[2] = a;
                                                break;
                                }
                                break;
			case 'd':
				switch (s[10]) {
                                        case 'a':
                                                arr[3] = arr[0];
                                                break;
                                        case 'b':
                                                arr[3] = arr[1];
                                                break;
                                        case 'c':
                                                arr[3] = arr[2];
                                                break;
                                        default: // предполагаем, что если вторым операндом оказался не регистр, то им является число
                                                arr[3] = a;
                                                break;
                                }
                                break;
			default:
				break;
		}
	}
	else if (s[1] == 'd') { // если введена команда "add"...
                switch (s[5]) { // идентифицируем первый операнд
                        case 'a':
                                switch (s[10]) { // идентифицируем второй операнд
                                        case 'b':
                                                arr[0] += arr[1];
                                                break;
                                        case 'c':
                                                arr[0] += arr[2];
                                                break;
                                        case 'd':
                                                arr[0] += arr[3];
                                                break;
                                        default:
                                                arr[0] += a;
                                                break;
                                }
                                break;
                        case 'b':
                                switch (s[10]) {
                                        case 'a':
                                                arr[1] += arr[0];
                                                break;
                                        case 'c':
                                                arr[1] += arr[2];
                                                break;
                                        case 'd':
                                                arr[1] += arr[3];
                                                break;
                                        default:
                                                arr[1] += a;
                                                break;
                                }
                                break;
                        case 'c':
                                switch (s[10]) {
                                        case 'a':
                                                arr[2] += arr[0];
                                                break;
                                        case 'b':
                                                arr[2] += arr[1];
                                                break;
                                        case 'd':
                                                arr[2] += arr[3];
                                                break;
                                        default:
                                                arr[2] += a;
                                                break;
                                }
                                break;
                        case 'd':
                                switch (s[10]) {
                                        case 'a':
                                                arr[3] += arr[0];
                                                break;
                                        case 'b':
                                                arr[3] += arr[1];
                                                break;
                                        case 'c':
                                                arr[3] += arr[2];
                                                break;
                                        default:
                                                arr[3] += a;
                                                break;
                                }
         			break;
                        default:
                                break;
                }
        }
	else if (s[1] == 'u') { // если введена команда "sub"...
                switch (s[5]) { // идентифицируем первый операнд
                        case 'a':
                                switch (s[10]) { // идентифицируем второй операнд
                                        case 'b':
                                                arr[0] -= arr[1];
                                                break;
                                        case 'c':
                                                arr[0] -= arr[2];
                                                break;
                                        case 'd':
                                                arr[0] -= arr[3];
                                                break;
                                        default:
                                                arr[0] -= a;
                                                break;
                                }
                                break;
                        case 'b':
                                switch (s[10]) {
                                        case 'a':
                                                arr[1] -= arr[0];
                                                break;
                                        case 'c':
                                                arr[1] -= arr[2];
                                                break;
                                        case 'd':
                                                arr[1] -= arr[3];
                                                break;
                                        default:
                                                arr[1] -= a;
                                                break;
                                }
                                break;
                        case 'c':
                                switch (s[10]) {
                                        case 'a':
                                                arr[2] -= arr[0];
                                                break;
                                        case 'b':
                                                arr[2] -= arr[1];
                                                break;
                                        case 'd':
                                                arr[2] -= arr[3];
                                                break;
                                        default:
                                                arr[2] -= a;
                                                break;
                                }
                                break;
                        case 'd':
                                switch (s[10]) {
                                        case 'a':
                                                arr[3] -= arr[0];
                                                break;
                                        case 'b':
                                                arr[3] -= arr[1];
                                                break;
                                        case 'c':
                                                arr[3] -= arr[2];
                                                break;
                                        default:
                                                arr[3] -= a;
                                                break;
                                }
                                break;
                        default:
                                break;
                }
        }
	else { // если не встретилась ни одна из команд "mov", "sub" или "add", то завершаем работу программы
		printf("Exit from the program\n");
		break;
	}
	for (int i = 0; i <= 3; i++) {
                printf("%d ", arr[i]);
        } // после выполнения каждой команды выведем текущее состояние всех 4 регистров
	printf("\n");
	}
	return 0;
}
