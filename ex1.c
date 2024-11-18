/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>

// REMIDER : YOU CANT USE ANY CONTROL FLOW OPERATIONS OR FUNCTIONS, ONLY BITWISE.

int main() {
  
  // What bit
  printf("What bit:\n");
  /*Scan two integers (representing number and a position)
  Print the bit in this position. */

  int num, position;
  printf("Please enter a number:\n");
  scanf("%d", &num);
  printf("Please enter a position:\n");
  scanf("%d", &position);

  int posRepresentative = 1;
  posRepresentative = posRepresentative << position; // moving the bit 1 to the indx matching the 'position'
  int bitInPosition = num & posRepresentative; 
  /* comparing the two numbers, so if the bit in num[position] is 1 - we'll get "1" in the bitInPosition[position],
  and if it's 0 - we'll get "0" in the bitInPosition[position] instead. */
  bitInPosition = bitInPosition >> position; // moving the bit back so the value will be 0/1
  printf("The bit in position %d of number %d is: %d", num, position, bitInPosition);



  // Set bit
  printf("\nSet bit:\n");
  /*Scan two integers (representing number and a position)
  Make sure the bit in this position is "on" (equal to 1)
  Print the output
  Now make sure it's "off" (equal to 0)
  Print the output */

  printf("Please enter a number:\n");
  scanf("%d", &num);
  printf("Please enter a position:\n");
  scanf("%d", &position);

  posRepresentative = 1 << position;
  int numWithBitOn = num | posRepresentative; // The posRepresentative[position] is 1, so no matter what 
  // num[position] bit is, we'll get numWithBitOn[position] = "1".
  printf("Number with bit %d set to 1: %d\n", position, numWithBitOn);

  int reversedPosRep = ~posRepresentative;
  int numWithBitOff = num & reversedPosRep; 
  // Since all bits in reversedPosRep are now valued to 1 - except reversedPosRep[position] -
  // the numWithBitOff[i] (i!=position) will be the same as num[i].
  // And since reversedPosRep[position]=0, no matter what num[position] is - the numWithBitOff[position]=0.
  printf("Number with bit %d set to 0: %d", position, numWithBitOff);



  // Toggle bit
  printf("\nToggle bit:\n");
  /*Scan two integers (representing number and a position)
  Toggle the bit in this position
  Print the new number */
  
  printf("Please enter a number:\n");
  scanf("%d", &num);
  printf("Please enter a position:\n");
  scanf("%d", &position);

  posRepresentative = 1 << position;
  int toggledNum = num ^ posRepresentative; // For i!=position, all the bits in "num" remain for toggledNum
  // since posRepresentative[i]=0. posRepresentative[position]=1, therefore If num[position]=0 ==> toggledNum[position]=1
  // and if num[position]=1 ==> toggledNum[position]=0.
  printf("Number with bit %d toggled: %d\n", position, toggledNum);



  // Even - Odd
  printf("\nEven - Odd:\n");
  /* Scan an integer
  If the number is even - print 1, else - print 0. */
  
  // 3, 5, 7, 11
  printf("\n3, 5, 7, 11:\n");
  /* Scan two integers in octal base
  sum them up and print the result in hexadecimal base
  Print only 4 bits, in positions: 3,5,7,11 in the result. */

  printf("Bye!\n");
  
  return 0;
}
