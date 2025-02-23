/******************
Name: Shira Cababia
ID: 326153590
Assignment: ex1
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
  printf("The bit in position %d of number %d is: %d\n", position, num, bitInPosition);



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
  int numWithBitOn = num | posRepresentative; /* The posRepresentative[position] is 1, so no matter what 
  num[position] bit is, we'll get numWithBitOn[position] = "1". */
  printf("Number with bit %d set to 1: %d\n", position, numWithBitOn);
  int reversedPosRep = ~posRepresentative;
  int numWithBitOff = num & reversedPosRep; 
  /* Since all bits in reversedPosRep are now valued to 1 - except reversedPosRep[position] -
  the numWithBitOff[i] (i!=position) will be the same as num[i].
  And since reversedPosRep[position]=0, no matter what num[position] is - the numWithBitOff[position]=0. */
  printf("Number with bit %d set to 0: %d\n", position, numWithBitOff);



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
  int toggledNum = num ^ posRepresentative; /* For i!=position, all the bits in "num" remain for toggledNum
  since posRepresentative[i]=0. posRepresentative[position]=1, therefore If num[position]=0 ==> toggledNum[position]=1
  and if num[position]=1 ==> toggledNum[position]=0. */
  printf("Number with bit %d toggled: %d\n", position, toggledNum);



  // Even - Odd
  printf("\nEven - Odd:\n");
  /* Scan an integer
  If the number is even - print 1, else - print 0. */

  printf("Please enter a number:\n");
  scanf("%d", &num);
  posRepresentative = ~1;
  int outputNum = ~ (num | posRepresentative);
  printf("%d\n", outputNum);
  /*The ~1 contains LSB=0 and "1" for the rest of the bits. The LSB affects on whether the number is even 
  (0==>even, 1==>odd). With the "NOR" we'll get 1 if the num is even and its LSB=0 (0nor0=1),
  and when the LSB of num is "1" we'll get 0 (0nor1=0)*/



  // 3, 5, 7, 11
  printf("\n3, 5, 7, 11:\n");
  /* Scan two integers in octal base
  sum them up and print the result in hexadecimal base
  Print only 4 bits, in positions: 3,5,7,11 in the result. */
  int num1, num2, sum;
  printf("Please enter the first number (octal):\n");
  scanf("%o", &num1);
  printf("Please enter the second number (octal):\n");
  scanf("%o", &num2);
  sum = num1 + num2;
  printf("The sum in hexadecimal: %X\n", sum);
  int bitInPosition3 = sum & (1 << 3);
  bitInPosition3 = bitInPosition3 >> 3; // Represent the bit in sum[3], by doing the "&" between that and 1<<3.
  int bitInPosition5 = sum & (1 << 5);
  bitInPosition5 = bitInPosition5 >> 5;
  int bitInPosition7 = sum & (1 << 7);
  bitInPosition7 = bitInPosition7 >> 7;
  int bitInPosition11 = sum & (1 << 11);
  bitInPosition11 = bitInPosition11 >> 11;
  printf("The 3,5,7,11 bits are: %d%d%d%d\n", bitInPosition3, bitInPosition5, bitInPosition7, bitInPosition11);

  printf("Bye!\n");
  return 0;
}
