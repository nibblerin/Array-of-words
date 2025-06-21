#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void splitStringIntoWords(char* str, char words[][MAX_WORD_LENGTH], int* wordCount, int* maxSize) {
    char* delimiter = " ,.!?;:\n\t"; //здесь задаются символы-разделители слов
    char* word = strtok(str, delimiter);//извлечение первого слова из строки str <=> Первый вызов strtok возвращает указатель на первый токен в строке str
    //указатель, который будет использоваться для хранения текущего слова
 
    while (word != NULL) {  //проверяется, не достигли ли мы конца строки
        strncpy(words[*wordCount], word, *maxSize - 1); //копирование текущего слова в массив words. *maxSize - 1 используется для того, чтобы зарезервировать 
                                                        //третий параметр для определения кол-ва символов которые будут скопированы
        words[*wordCount][*maxSize - 1] = '\0'; //место для символа окончания строки '\0'
        (*wordCount)++;    
        word = strtok(NULL, delimiter); 
        //Использование NULL в качестве первого аргумента указывает функции strtok, что она должна продолжить разбирать ту же строку с той позиции, 
        //на которой остановилась после предыдущего вызова.
        //Функция strtok использует внутренний статический указатель для отслеживания текущей позиции в строке.
    }
}
int main() {
    char input_str[256];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    int word_size = MAX_WORD_LENGTH;

    // Ввод строки от пользователя
    printf("Enter the string: ");
    fgets(input_str, sizeof(input_str), stdin);

    // Разбиваем строку на слова и записываем их в массив
    splitStringIntoWords(input_str, words, &word_count, &word_size);

    // Выводим массив слов
    printf("The array of the words:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}