#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_complete_overlaps(int a, int b, int c, int d);
int find_partial_overlaps(int a, int b, int c, int d);

int main (int argc, char *argv[])
{
    FILE* file;
    char* filename = "input.txt";

    if (argc > 1 && !strcmp(argv[1], "-t"))
    {
        filename = "test_input.txt";
    }

    if(fopen_s(&file, filename, "r"))
    {
        perror("Error reading file");
        return -1;
    }

    unsigned int a, b, c, d;
    unsigned int num_complete_overlaps = 0;
    unsigned int num_partial_overlaps = 0;
    while (fscanf_s(file, "%u-%u,%u-%u", &a, &b, &c, &d) == 4)
    {
        num_complete_overlaps += find_complete_overlaps(a, b, c, d);
        num_partial_overlaps += find_partial_overlaps(a, b, c, d);
    }
    printf("Num of complete overlaps: %d\n", num_complete_overlaps);
    printf("Num of partial overlaps: %d\n", num_partial_overlaps);

    return 0;
}

int find_complete_overlaps(int a, int b, int c, int d)
{
    if (c >= a && c <= b)
    {
        if (d >= a && d <= b)
        {
            return 1;
        }
    }

    if (a >= c && a <= d)
    {
        if (b >= c && b <= d)
        {
            return 1;
        }
    }

    return 0;
}

int find_partial_overlaps(int a, int b, int c, int d)
{
    if (a >= c && a <= d)
    {
        return 1;
    }
    else if (b >= c && b <= d) {
        return 1;
    }
    else if (c >= a && c <= b) {
        return 1;
    }
    else if (d >= a && d <= b) {
        return 1;
    }

    return 0;
}