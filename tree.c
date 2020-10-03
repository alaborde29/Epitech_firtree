/*
** EPITECH PROJECT, 2020
** B-CPE-100-NAN-1-1-firtree-alexandre.laborde
** File description:
** tree
*/

#include <unistd.h>

void my_putchar(char c);

void print_spaces(int size, int line_size)
{
    int i = 0;
    int j = 0;
    int n_ligne = 4;
    int n_char = 1;

    while (i != size) {
        while (j != n_ligne) {
            n_char = n_char + 2;
            j++;
        }
        n_ligne++;
        j = 0;
        n_char = n_char - 4;
        i++;
    }
    n_char = n_char + 2;
    for (int n = 0; n != ((n_char / 2) + 1) - (line_size / 2 + 1); n++)
        my_putchar(' ');
}

void print_n_char(char c, int n)
{
    int i = 0;

    while (i != n) {
        my_putchar(c);
        i++;
    }
    return;
}

void build_floor(int size)
{
    int n_ligne = 4;
    int n_char = 1;
    int rem = 4;

    for (int i = 0; i != size; i++) {
        for (int j = 0; j != n_ligne; j++) {
            print_spaces(size, n_char);
            print_n_char('*', n_char);
            my_putchar('\n');
            n_char = n_char + 2;
        }
        n_ligne++;
        n_char = n_char - rem;
        if ( i % 2 == 1)
            rem = rem + 2;
    }
}

void build_trunk(int size)
{
    int size_l = size;
    int i = 0;

    if (size % 2 == 0)
        size_l = size_l + 1;
    while (i != size) {
        print_spaces(size, size_l);
        print_n_char('|', size_l);
        my_putchar('\n');
        i++;
    }
}

void tree(int size)
{
    if (size <= 0)
        return;
    build_floor(size);
    build_trunk(size);
    return;
}