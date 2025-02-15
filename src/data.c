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

  // got to check from right to left numbers.

  int length = src.len;
  // //  while(curr != NULL) {

  //     value += pow(base, i) * convertCharToNumber(curr->number);

  //     curr = curr->next;

  //     i++;

  //  }
  while (curData != NULL)
  {
    decimalValue += convertCharToNumber(curData->number) * pow(src.base, counter);
    counter++;
    curData = curData->next;
  }

  char charNum = convertNumberToChar(decimalValue);
  int temp_val = decimalValue;


   while (decimalValue > 0)
{
    DataNode *new_node = malloc(sizeof(DataNode));
    new_node->number = convertNumberToChar(decimalValue % n);
     
     if (curData == NULL){
      new_data.data = new_node;
      new_data.data->next = NULL;
     }
     else{
       curData->next = new_node;
       new_node->next = NULL;
     }

     curData = new_node;
      decimalValue = decimalValue / n;
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
