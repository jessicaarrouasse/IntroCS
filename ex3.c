/****************************************** 
*Student name: Arrouasse Jessica
*Student ID: 328786348
*Exercise name: ex3
******************************************/


#include <stdio.h>

//mission 1
#define MAX_BASE 10
#define MIN_BASE 2

//mission 2
#define T_MAX 10000000
#define T_MIN 1

//mission 3
#define P 1
#define Q 10000


/******************************************************************************* 
* function name: main
*
* The Input: user choose an mission :mission 1 the user choose2 numbers in base 
*									 between 1 and 10;
*									 mission 2 the user choose time t of the 
*									 counter;
*									 mission 3 the user choose  lower and the 
*									 umpper limit of the range1 and 10000;
* 									 mission 4 the user choose the beguinning 
*									 value for the game.
* 
* The mission operation: :mission 1 print: the sum of the 2 numbers in the base 
*                         that the user choose; 
*                         mission2  print: the value that correspond to the time
*                         that the user choose. 
*                         mission 3 print: the modified Kaprekar numbers in the
*						  range that the user choose.
*						  mission 4 print: the winner (the person that reache 1)
*                          
* output : if everything good return 0 .             
*
*******************************************************************************/


int main()
{
	//mission 1
	int num1, num2;
    int factor = 0, remainder = 0, total = 0;
    int base;
    int unchangedNum1;
    int unchangedNum2;
    int lastDigit;

    //mission 2
	int value1 = 3;
	int value2 = 6;
	int time1 = 1;
	int time2 = 4;
	int t;
	int counter;

	//mission 3
	int n;
	int nSquare;
	int sum;
	int left;
	int right;
	int p;
	int q;
	int i;
	int splitNumber;
	int currentNumber;

	//mission 4
	int result = 1;
	int turn = 1;
	int number;
	int nUnchanged;
	int noNumber;

	int mission = 1;

	//loop until the mission is bigger than 4 or smaller than 1
	while (mission >= 1 && mission <=4)
	{
		//the user choose the mission numer
		printf("Please enter the mission number:\n");
		scanf("%d",&mission);

		//do the mission that correspond to the number that choose the user 
		switch (mission)
		{
			//user choose the base
			case 1: printf("Please enter the base of the problem:\n");
				    scanf("%d", &base);

				    //if the number is not in the range print the error
				    if (base < MIN_BASE || base > MAX_BASE)
				    {
				        printf("ERROR - The base %d is not between 2 and 10 \n",
				        	    base);
				    }
 
 					//otherwise the user choose the 2 numbers
				    else
				    {
					    printf("Please enter the first number in base %d:\n",
					    	    base);

					    scanf("%d", &num1);
					    printf("Please enter the second number in base %d:\n",
					            base);

					    scanf("%d", &num2);

					    //keep the number befor change
					    unchangedNum1 = num1;
					    unchangedNum2 = num2;
					    total = 0;

					    //the initial factor
					    factor = 1;

					    //loop until the finish operation
					    while (num1 != 0 || num2 != 0 || remainder != 0)
					    {   
					    	//sum of the last digit and the remainder 
					        lastDigit = num1 % 10 + num2 % 10 + remainder;

					        //the lastdigit become the first number in the total  
					        total = total + (lastDigit % base) * factor;

					        //the reamainder that correspond to the base
					        remainder = lastDigit / base;

					        //pass to the next numbers
					        num1 = num1 / 10;
					        num2 = num2 / 10;

					        //multiply:for the numbers will be in the good order  
					        factor = factor  *10;
					    }

					    //print the sum    
					    printf("The result of %d + %d in base %d is %d\n",
					    		unchangedNum1, 
					            unchangedNum2, 
					            base, total);
					    break;

			case 2: value1 = 3;
					value2 = 6;
					time1 = 1;
					time2 = 4;

					//the user choose the time
					printf("Please enter the time:\n");
					scanf("%d",&t);

					//print the error if the t is not in the range 
					if (t < T_MIN || t > T_MAX)
					{
						printf("ERROR - The time %d is invalid\n",t );
					}

					//otherwise found the correspond value
					else
					{	
						//loop until we found the correspond cycle to the time
						while (t < time1 || t > time2)
						{
							//found the range of times and values the cycle
							value1 = value1 * 2;
							time1 = value1 - 2;
							value2 = value1 * 2;
							time2 = value2 - 2;

						}

						//loop until we found the time  that the user chose
						for (counter = time1 ; counter < t && time2 != t ; 
							++counter)
						{
							--value1; 	
						}
 						
 						/* assignement of value2 in value1 if the t in the last 
 						   time in the cycle */

						if (time2 == t)
						{
							value1 = value2;
						}

						//print the value
						printf("The time in the timer after %d seconds is %d\n",
						 		t, value1);
					} 

					break;

			//the user choose the lower and upper limit
			case 3: printf("Please enter the lower limit of the range (p):\n");
					scanf("%d", &p);
					printf("Please enter the upper limit of the range (q):\n");
					scanf("%d", &q);

					
					/* if the lower and the upper limit is not in the range print
					   the error */
					if (p < P || q > Q || p >= q)
					{
						printf("ERROR - The range %d to %d isn't valid\n", p, q);
					}

					//otherwise found the the modified Kaprekar numbers
					else
					{

						noNumber = 1;
						//loop until we found all the kaprekar numbers
						for (i = p; i <= q && i < Q; i++)
						{
							//for save the i
							currentNumber = i;

							//reset split number
							splitNumber = 1;


							while (currentNumber > 0)
							{
								currentNumber = currentNumber / 10;
								splitNumber = splitNumber * 10;
							}
							//found the square of the number
							nSquare = i * i;

							//found the left number 
							left = nSquare % splitNumber;
							
							//found the right number
							right = nSquare / splitNumber;
							sum = left + right;

							//print the kaprekar numbers 
							if (sum == i)
							{
								if (noNumber)
								{
									printf("The numbers between %d and %d are:\n", p, q);
									noNumber = 0;
								}
								printf("%d\n", i );
							}

						}

						if (noNumber)
							{
								printf("NO NUMBERS BETWEEN %d AND %d\n",p,q);
							}
					}

					break;

			case 4: printf("Please enter the initial value for the game:\n");
					scanf("%d",&number);

					//print the initial value
					printf("Louise: %d\n",number);

					//louise begin
					turn = 1;

					//loop until we found the winner
					while (number > 1)
					{
						nUnchanged = number;

						//loop until result bigger than number
						while (result < number)
						{
							//multiply by 2 result
							result = result << 1;
						}

							// divide by 2 the number
							number = result >> 1;

						// if its not power of 2
						if (result != number)
						{
							//substraction of nUnchanged number with the number
							number = nUnchanged ^ number;
						}

						//restoraton of the result
						result = 1;

						//if its the turn of louise print the number
						if (turn)
						{
							printf("Louise: %d\n",number);

						}

						//if its the turn of Richard print the number
						else
						{
							printf("Richard: %d\n",number);
						}

						turn = !turn;

				    }

				    //print the winner corresponding to the turn
					if (turn)
					{
					    printf("The winner is: Richard\n");
					}
				    
				    else
				    {	
				    	printf("The winner is: Louise\n");
				    }
				}

				break;
				
				default: 
						break;

		}
	}	

	return 0;
}
