#include <iostream>

const int OCEAN_HEIGHT = 7;
const int OCEAN_WIDTH = 9;

int main()
{
    int ocean[OCEAN_HEIGHT][OCEAN_WIDTH] =
    {
        {0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0}
    };
    int islandCounter = 0;
    int oceanCounter[OCEAN_HEIGHT][OCEAN_WIDTH]{};
    for(int i = 0; i < OCEAN_HEIGHT; i++)
    {
        for(int j = 0; j < OCEAN_WIDTH; j++)
        {
            if(ocean[i][j] == 1 && oceanCounter[i][j] != 1)
            {
                islandCounter++;
                if (j + 1 < OCEAN_WIDTH)
                {
                    if(ocean[i][j + 1] == 1)
                    {
                        islandCounter--;
                    }
                }
                if(ocean[i + 1][j] == 1 && oceanCounter[i + 1][j] != 1)
                {
                    if (i + 1 >= OCEAN_HEIGHT) break;
                    oceanCounter[i + 1][j] = 1;
                    if (j > 0)
                    {
                        if(ocean[i + 1][j - 1] == 1 && oceanCounter[i + 1][j - 1] != 1)
                        {
                            oceanCounter[i + 1][j - 1] = 1;
                        }
                    }
                    if (j + 1 < OCEAN_WIDTH)
                    {
                        if(ocean[i + 1][j + 1] == 1 && oceanCounter[i + 1][j + 1] != 1)
                        {
                            oceanCounter[i + 1][j + 1] = 1;
                        }
                    }
                }
            }
        }
    }
    std::cout << "island counter = " << islandCounter << "\n";
}