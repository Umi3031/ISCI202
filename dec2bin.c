#include "linked_list.h"
#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

// аравтын тооллын системээс хоёртын тооллын системд хөрвүүлэх
char *dec2bin(int dec) {
    Stack stack;
    initStack(&stack);

    // Хэрвээ тоо 0 бол шууд буцаана
    if (dec == 0) {
        char *result = (char *)malloc(2 * sizeof(char));  // 1 тэмдэгт + NULL-терминатор
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Тоог 2-оор хувааж, үлдэгдлийг Stack-д нэмэх
    while (dec > 0) {
        push(&stack, (dec % 2) + '0');  // үлдэгдлийг '0' эсвэл '1' болгон хадгална
        dec /= 2;
    }

    // Stack-аас 2-ийн тэмдэгтүүдийг авна
    int len = length(stack.top);  // Stack-ийн урт
    char *bin = (char *)malloc((len + 1) * sizeof(char));  // Одоо хөрвүүлсэн 2-ны тоо, NULL-терминатор орно
    int i = 0;

    // Stack-аас утгуудыг авч, bin массивд хадгалах
    while (!isEmpty(&stack)) {
        bin[i++] = pop(&stack);
    }

    bin[i] = '\0';  // NULL-терминатор
    return bin;
}

int main() {
    int dec;
    scanf("%d", &dec);

    char *bin = dec2bin(dec);
    printf("%s\n", bin);

    free(bin);
    return 0;
}
