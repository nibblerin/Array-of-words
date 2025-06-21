#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void splitStringIntoWords(char* str, char words[][MAX_WORD_LENGTH], int* wordCount, int* maxSize) {
    char* delimiter = " ,.!?;:\n\t"; //����� �������� �������-����������� ����
    char* word = strtok(str, delimiter);//���������� ������� ����� �� ������ str <=> ������ ����� strtok ���������� ��������� �� ������ ����� � ������ str
    //���������, ������� ����� �������������� ��� �������� �������� �����
 
    while (word != NULL) {  //�����������, �� �������� �� �� ����� ������
        strncpy(words[*wordCount], word, *maxSize - 1); //����������� �������� ����� � ������ words. *maxSize - 1 ������������ ��� ����, ����� ��������������� 
                                                        //������ �������� ��� ����������� ���-�� �������� ������� ����� �����������
        words[*wordCount][*maxSize - 1] = '\0'; //����� ��� ������� ��������� ������ '\0'
        (*wordCount)++;    
        word = strtok(NULL, delimiter); 
        //������������� NULL � �������� ������� ��������� ��������� ������� strtok, ��� ��� ������ ���������� ��������� �� �� ������ � ��� �������, 
        //�� ������� ������������ ����� ����������� ������.
        //������� strtok ���������� ���������� ����������� ��������� ��� ������������ ������� ������� � ������.
    }
}
int main() {
    char input_str[256];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    int word_size = MAX_WORD_LENGTH;

    // ���� ������ �� ������������
    printf("Enter the string: ");
    fgets(input_str, sizeof(input_str), stdin);

    // ��������� ������ �� ����� � ���������� �� � ������
    splitStringIntoWords(input_str, words, &word_count, &word_size);

    // ������� ������ ����
    printf("The array of the words:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}