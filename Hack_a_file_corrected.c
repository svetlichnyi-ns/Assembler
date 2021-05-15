#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    const char initial_phrase[] = "Hello, world!";
    const char final_phrase[] = "Sapere aude!!";
    int length = strlen(initial_phrase);

    if (argc == 1) {
        printf("You haven't entered any arguments!n");
        return -1;
    }
    
    else if (argc > 2) {
        printf("You have entered too many arguments!\n");
        return -1;
    }

    FILE* changed_file = fopen(argv[1], "r+b");
    if (changed_file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    printf("You have opened the file!\n");

    char symbol; // будем посимвольно считывать содержимое файла, храня результат в переменной symbol типа char
    int indicator = 0; // создадим индикатор того, что нужная строка была изменена программой
    int number = 0; // будем хранить количество совпавших символов
    fseek(changed_file, 0, SEEK_END); // переместим внутренний указатель файла в его конец
    unsigned long long int file_length = ftell(changed_file); // в переменную file_length положим т.н. длину файла
    fseek(changed_file, 0, SEEK_SET); // установим внутренний указатель файла в его начало
    printf("The length of the file: %llu\n", file_length);
    int j = 0; // создадим переменную, отвечающую количеству итераций будущего цикла
    while (j < file_length) { // на каждой итерации будем инкрементировать j; поскольку после каждого вхождения в цикл внутренний указатель файла смещается на единицу вправо, то по достижении переменной j значения file_length будет достигнут конец файла
        fread(&symbol, sizeof(char), 1, changed_file);
        if (symbol == initial_phrase[number]) { // ожидаем того, что считанный символ совпадёт с текущей буквой искомой фразы
            number++; // если это произошло, проверяем на предмет совпадения следующую букву искомой фразы
        }
        else {
            number = 0; // если нашлось несоответствие, то сбрасываем number до нуля и мнова ищем совпадений букв, начиная с нулевой
        }
        if (number == length + 1) { // если совпали идущие подряд length + 1 символов (включая нуль-терминированный байт), то искомая фраза найдена
            fseek(changed_file, -(length + 1), SEEK_CUR);
            for (int i = 0; i < length + 1; i++) {
                fwrite(&final_phrase[i], sizeof(char), 1, changed_file);
            }
            printf("The text has been changed!\n");
            indicator = 1; // срабатывание индикатора
            break;
        }
        j++;
    }
 
    if (indicator == 0) {
        printf("Unluckily, a necessary string has not been found...\n");
    }
    
    fclose(changed_file);
    return 0;
}
