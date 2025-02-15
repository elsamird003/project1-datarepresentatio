#include <data.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int convertCharToNumber(char ch)
{
  if (ch >= '0' && ch <= '9')
  {
    return ch - '0';
  }
  else if (ch >= 'A' && ch <= 'F')
  {
    return ch - 'A' + 10;
  }
  else
  {
    return -1;
  }
}

char convertNumberToChar(int n)
{
  if (n >= 0 && n <= 9)
  {
    return n + '0';
  }
  else if (n >= 10 && n <= 15)
  {
    return n - 10 + 'A';
  }
  else
  {
    return 0;
  }
}

// converting up words method. =
// division notes, for going down.
// and multiplication is from going up
Data convert_to_base_n(Data src, unsigned char n) // n is the base.
{
  int decimal = 0;
  int value = 0;
  int base = src.base;
  int counter = 0;
  Data new_data;
  new_data.data = NULL;

  src.sign = 0;
  DataNode *curData = src.data;
  
  // convert to base 10
  while (curData != NULL)
  {

    value += pow(base, counter) * convertCharToNumber(curData->number);

    curData= curData->next;

    counter++;
  }
  
 DataNode *tail = NULL;
  while (value > 0) {
    DataNode *new_node = malloc(sizeof(DataNode));    
    new_node->number = convertNumberToChar(value % n);

    if (curData == NULL) {
        new_data.data = new_node;
         new_data.data->next = NULL;
    } else {
        curData->next = new_node;
        new_node->next = NULL;
    }
    curData = new_node;
    value /= n;
    
     new_data.len++;
}

  return new_data;
}

Data convert_int_to_data(int number, unsigned char base,
                         unsigned char number_bits)
{
  Data new_data;
  new_data.data = NULL;
  // TODO
  return new_data;
}

Data left_shift(Data src, int n)
{
  Data new_data;
  // TODO
  return new_data;
}

Data right_shift(Data src, int n)
{
  Data new_data;
  // TODO
  return new_data;
}
