
#include <stdio.h>

#define NUMBER_OF_SIDES 12
#define NUMBER_OF_TILESIDES 5
#define NUMBER_OF_EDGES 30
#define FOUR_ON_THE_POWER_OF_FIVE 1024

int tiles[NUMBER_OF_SIDES][NUMBER_OF_TILESIDES];
int used[NUMBER_OF_SIDES];

char table[FOUR_ON_THE_POWER_OF_FIVE][NUMBER_OF_SIDES][NUMBER_OF_TILESIDES];

int configuration[NUMBER_OF_SIDES][NUMBER_OF_TILESIDES] = { { 0,1,2,3,4 },
                                                            { 0,9,10,11,5 },
                                                            { 1,5,12,13,6 },
                                                            { 2,6,14,15,7 },
                                                            { 3,7,16,17,8 },
                                                            { 9,4,8,18,19 },
                                                            { 10,19,20,25,24 },
                                                            { 20,18,17,21,26 },
                                                            { 21,16,15,22,27 },
                                                            { 22,14,13,23,28 },
                                                            { 23,12,11,24,29 },
                                                            { 25,26,27,28,29 } };

int important[NUMBER_OF_SIDES] = { 0,1,2,2,2,3,2,3,3,3,4,5 };

int edges[NUMBER_OF_EDGES];

int found;

struct {
         int tile_number,position;
       } solution[NUMBER_OF_SIDES];

FILE *fp;

int hash_func(int *temp)
{
  int i;
  int value;

  value = 0;

  for (i = 0;i < NUMBER_OF_TILESIDES;++i)
  {
    if (temp[i] == -1)
      break;

    value = 4 * value + (temp[i] + 1);
  }

  return value;
}

void read_input(void)
{
  int i,j,k,l;
  int temp[NUMBER_OF_TILESIDES];

  // reading from "BALL.IN"

  fp = fopen("BALL.IN","rt");

  for (i = 0;i < NUMBER_OF_SIDES;++i)
    for (j = 0;j < NUMBER_OF_TILESIDES;++j)
      fscanf(fp,"%d",&tiles[i][j]);

  fclose(fp);

  // initialization of "table"

  for (i = 0;i < FOUR_ON_THE_POWER_OF_FIVE;++i)
    for (j = 0;j < NUMBER_OF_SIDES;++j)
      for (k = 0;k < NUMBER_OF_TILESIDES;++k)
        table[i][j][k] = 0;

  // generating of "table"

  for (i = 0;i < NUMBER_OF_SIDES;++i)
    for (j = 0;j < NUMBER_OF_TILESIDES;++j)
      for (k = 1;k <= NUMBER_OF_TILESIDES;++k)
      {
        for (l = 0;l < k;++l)
          temp[l] = tiles[i][(j + l) % NUMBER_OF_TILESIDES];
        for (l = k;l < NUMBER_OF_TILESIDES;++l)
          temp[l] = -1;

        table[hash_func(temp)][i][j] = 1;
      }

}

void recursion(int side_number)
{
  int i,j,k;
  int number;
  int temp[NUMBER_OF_TILESIDES];

  if (found)
    return;

  if (side_number == NUMBER_OF_SIDES)
  {
    found = 1;
    return;
  }

  for (i = 0;i < important[side_number];++i)
    temp[i] = edges[configuration[side_number][i]];

  for (i = important[side_number];i < NUMBER_OF_TILESIDES;++i)
    temp[i] = -1;

  number = hash_func(temp);

  // trying to set next tile

  for (i = 0;i < NUMBER_OF_SIDES;++i)
    if (!used[i])
    {
      for (j = 0;j < NUMBER_OF_TILESIDES;++j)
        if (table[number][i][j])
        {
          for (k = important[side_number];k < NUMBER_OF_TILESIDES;++k)
            edges[configuration[side_number][k]] =
              tiles[i][(j + k) % NUMBER_OF_TILESIDES];

          used[i] = 1;

          solution[side_number].tile_number = i;
          solution[side_number].position = j;

          recursion(side_number + 1);

          used[i] = 0;

          if (found)
            break;
        }

      if (found)
        break;
    }

}

void solve(void)
{
  int i;

  // initialization of "used"

  for (i = 0;i < NUMBER_OF_SIDES;++i)
    used[i] = 0;

  // first tile is fixed on the first side in position 0

  for (i = 0;i < NUMBER_OF_TILESIDES;++i)
    edges[configuration[0][i]] = tiles[0][i];

  used[0] = 1;

  solution[0].tile_number = 0;
  solution[0].position = 0;

  // going into recursion

  found = 0;

  recursion(1);
}

void write_output(void)
{
  int i,j,k;
  int temp,ref_edge;

  // writing to "BALL.OUT"

  fp = fopen("BALL.OUT","wt");

  if (!found)
    fprintf(fp,"-1\n");
  else
    for (i = 0;i < NUMBER_OF_SIDES;++i)
    {
      temp = configuration[i][(NUMBER_OF_TILESIDES - solution[i].position) %
                              NUMBER_OF_TILESIDES];

      ref_edge = -1;

      for (j = 0;j < NUMBER_OF_SIDES;++j)
        if (j != i)
        {
          for (k = 0;k < NUMBER_OF_TILESIDES;++k)
            if (configuration[j][k] == temp)
            {
              ref_edge = j;
              break;
            }

          if (ref_edge != -1)
            break;
        }

      fprintf(fp,"%d %d\n",solution[i].tile_number + 1,ref_edge + 1);
    }

  fclose(fp);
}

int main(void)
{
  read_input();

  solve();

  write_output();

  return 0;
}
