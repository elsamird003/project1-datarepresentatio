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

Data convert_to_base_n(Data src, unsigned char n)
{
  Data new_data;
  new_data.data = NULL;
  src.sign = 0;

  if (src.base == n)
  {
    return src;
  }

  // get the value
  // times the base to the power of the index

  // first finidn what rthe base is and from ant base  you multiply the digit the base bt the base of digit position n^0 then n^1 and so on!!!!!
  // values * base to the power of the position. convert any base to decimal
  // to convert to any base i need to grab the lenghts of the linked list, invert the or lenght of the linked list. After that i need to grab value and then multuply it by the base to the power of the lenght.

  // first try to convert data to base 10 because it is easier to convert to any

  // We start from right to left.

  // convert the data to base 10
  int decimalValue = 0;
  DataNode *curData = src.data;
  int counter = 0;
  // curData->number = convertNumberToChar(decimalValue);

  int length = src.len;

  while (curData != NULL)
  {
    decimalValue += convertCharToNumber(curData->number) * pow(src.base, length - counter - 1);
    curData = curData->next;
    counter++;
  }
  while (decimalValue > 0)
  {
    DataNode *new_node = (DataNode *)malloc(sizeof(DataNode));
    new_node->number = convertCharToNumber(decimalValue % n);
    new_node->next = new_data.data;
    new_data.data = new_node;
    new_data.len++;
    decimalValue /= n;
   
  }
 printf("decimalValue HERER!@@@@@@@@@@@@@@@@ %c\n", decimalValue);
  // DataNode *new_node = (DataNode *)malloc(sizeof(DataNode));
  // new_node->number = convertNumberToChar(n * src.base * p_power);
  // new_node->next = new_data.data;
  // new_data.data = new_node;
  // src.data = src.data->next;
  // p_power = p_power / src.base;

  // // new_node->number = convertNumberToChar(n % src.base);
  // new_node->next = new_data.data;
  // new_data.data = new_node;
  // new_data.data = new_node;
 printf("decimalValue HERER!@@@@@@@@@@@@@@@@ %c\n", convertchartonum(new_data.data->number));
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
