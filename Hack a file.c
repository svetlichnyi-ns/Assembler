#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
    const char initial_phrase[] = "Hello, world!"; 
    const char final_phrase[] = "Sapere aude!!";
    int length = strlen(initial_phrase);
    char comparison[] = {};

    if (argc == 1) {
        printf("You haven't entered any arguments!\n");
        return;
    }

    else if (argc > 2) {
        printf("You have entered too many arguments!\n");
        return;
    }

    FILE* changed_file = fopen(argv[1], "r+b");
    if (changed_file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("You have opened the file!\n");
    do {
        fread(comparison, sizeof(char), length, changed_file); // в массив символов "comparison" считаем первые length символов из файла
        comparison[length] = '\0'; // в конце считанного массива сиволов установим нуль-терминированный байт
        if (strcmp(comparison, initial_phrase) == 0) { // сравним считанную строку с искомой строкой "Hello, world!"
            printf("The string 'Hello, world!' has been found!\n");
            fseek(changed_file, -length, SEEK_CUR); // передвинем внутренний указатель файла на length символов назад, т.е. в самое начало считанной до этого строки
            fwrite(final_phrase, sizeof(char), length, changed_file); // перезапишем length символов в изменяемом файле
            printf("The text has been changed!\n");
            break;
        }
        else {
            fseek(changed_file, -(length - 1), SEEK_CUR); // если нужная строка пока ещё не найдена, передвинем внутренний указатель файла на length - 1 сиволов назад и продолжим поиски
            if (feof(changed_file) != 0) { // если нужную строку найти не удалось, а конец файла достигнут...
                printf("Unluckily, a necessary string has not been found\n");
                break;
            }
        }
    } while (feof(changed_file) == 0); // цикл продолжается до тех пор, пока не будет найдена нужная строка
    fclose(changed_file);
    return;
}
