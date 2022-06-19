#include <stdio.h>
#include <assert.h>

const char *majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char *minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct colorMap
{
    int pairNumber;
    char *majorColor;
    char *minorColor;
};

const int numberOfValues = 25;
struct colorMap colorMapCollection[25];

void getColorMap()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            colorMapCollection[i * 5 + j].pairNumber = i * 5 + j;
            colorMapCollection[i * 5 + j].majorColor = (char *)majorColor[i];
            colorMapCollection[i * 5 + j].minorColor = (char *)minorColor[j];
        }
    }
}

void printColorMap()
{

    for (int i = 0; i < numberOfValues; i++)
    {
        printf("%d | %s | %s\n", colorMapCollection[i].pairNumber, colorMapCollection[i].majorColor, colorMapCollection[i].minorColor);
    }
}

void Testfunction()
{
    for (int i = 0; i < 26; i++)
    {
        assert(colorMapCollection[i].pairNumber == i + 1);
        assert(colorMapCollection[i].majorColor == majorColor[i]);
        assert(colorMapCollection[i].minorColor == minorColor[i]);
    }
}

int main()
{
    getColorMap();
    printColorMap();
    Testfunction();
    printf("All is well (maybe!)\n");
    return 0;
}