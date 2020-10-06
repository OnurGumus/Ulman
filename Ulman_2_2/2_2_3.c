#include "cell.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

DefCell(char, CELL, LIST);

LIST createFromString(const char* s)
{
    size_t len = strlen(s);
    LIST list = malloc(sizeof(struct CELL) * len);
    if (!list)
    {
        return 0;
    }
    LIST current = list;
    for (int i = 0; i < len - 1; i++)
    {
        current->element = s[i];
        LIST const next = current + 1;
        current->next = next;
        current = next;
    }
    current->element = s[len - 1];
    current->next = 0;
    return list;
}

bool compare(LIST l1, LIST l2) {
    if (l1 == l2)
    {
        return true;
    }
    if (l1 == 0 || l2 == 0 || l1->element != l2->element)
    {
        return false;
    }
    else {
        return compare(l1->next, l2->next);
    }

}
int main(void)
{
    char hello[] = "hello world";
    char hello2[] = "hello world!";
    LIST list1 = createFromString(hello);
    LIST list2 = createFromString(hello);
    LIST list3 = createFromString(hello2);
    printf("%d\n", compare(list1, list2));
    printf("%d\n", compare(list1, list3));
    return EXIT_SUCCESS;
}
