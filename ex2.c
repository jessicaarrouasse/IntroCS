/***************************************** 
*Student name: Arrouasse Jessica
*Exercise name: ex2
*****************************************/ 


#include <stdio.h>

//for option 3
#define PRINT_HOT "This year the weather was hot \n"
#define PRINT_COLD "This year the weather was cold \n"
#define PRINT_NORMAL "This year the weather was normal \n"

//for option 2
enum weather {NORMAL, HOT, COLD};

//for option 3
enum type {VALID, BAD_STRUCTURE, INVALID};


/******************************************************************************* 
* function name: main
*
* The Input: user choose an option :option 1 Parentheses Order;
*									option 2 Calculating numbers with
*                                   operator +,-,*,/,% ;
*									option 3 average of 4 temparature(one for 
*                                   each season) of the year;
* 
* The Function operation: :option 1 print: Ok for correct order; Invalid input 
*              for chars different that(,),[,],a; bad sturcture for incorect 
*              order of parhentheses.
*              option 2 print the result when the input is with correct operator
*              otherwise print Invalid input.
*              option 3 print the average when the temparature is between 10 and
*              37 include.
* 
* output : if everything good return 0 .             
*
*******************************************************************************/

int main(int argc, char const *argv[])
{
	int option;

	//for option 1
	enum type error = VALID;
	enum weather year;
	//correspond to the parhentheses ()
	char firstParhenteses = '0';
	//correspond to the parhentheses []
	char secondParhenteses = '0';
	char input1, input2, input3, input4;
	char dummy;

	//for option 2
	int num1;
	int num2;
	char operator;
	float result;

	//for option 3
	const float maxTemp = 37;
	const float minTemp = 10;
	float temp1, temp2, temp3, temp4;
	float sum;
	float average;

				

	//print the sentence in the parhenteses
	printf("Please choose an option:\n");
	//take the choice of the user
	scanf("%d",&option);

	//do the case that the user choose

	switch (option)
	{
		//print the sentense in the parhenteses
		case 1: printf("Please enter four chars:\n");
				//take the 4 chars that the user choice
				scanf("%c%c %c %c %c", &dummy, &input1, &input2, &input3, 
					                   &input4);
				//check which input1 the user choose
				switch (input1)
				{
					//user choose a pass the switch
					case 'a':
							  break;

					//user choose [:assignement [ in secondParhentheses
			  	   	case '[': secondParhenteses = '[';
				              break;
					
					//user choose (: assignement ( in firstParhentheses 
				   	case '(': firstParhenteses = '(';
				      	      break;
				    
				    //user choose )or ]assignement of BAD_STRUCTURE in error  	
			       	case ')':
			       	case ']': error = BAD_STRUCTURE;
				    	      break;

				    //user chose a wrong chars :assignement of INVALID in error
				   	default: error = INVALID;
				}

				/*

				if error is INVALID print the sentence between the parentheses 
                and finish the program

                */

				if (error == INVALID)
				{
					printf("Invalid input\n");
					return 0;
				}

				//check which input2 the user choose
				switch (input2) 
				{

					//user choose a pass the switch
				   	case 'a':
				      	      break;
					
					/*

					user choose (: check if there was before ( :assignement 
					BAD_STRUCTURE in error , if there was not ( 
					befor :assignement of ( in firstParhentheses.

					*/

				   	case '(': if (firstParhenteses == '(')
				      		  {
				      		      error = BAD_STRUCTURE;
				      	      }
				      		  else if (firstParhenteses == '0')
				      	      {
				      		      firstParhenteses = '(';
				      		  }
				      	      break;

				    //user choose ]or[ :assignement of BAD_STRUCTURE in error  
				   	case ']':
				   	case '[': error = BAD_STRUCTURE;
				      	      break;

				    /*

					user choose ):check if there was not before ( :assignement 
					BAD_STRUCTURE in error , if there was ( 
					befor :assignement of 0 in firstParhentheses.

					*/

				   	case ')': if (firstParhenteses == '0')
							  {
							       error = BAD_STRUCTURE;
							  }
							  else if (firstParhenteses == '(')
							  {
							      firstParhenteses = '0';
							  }
							  break;

				    //user chose a wrong chars :assignement of INVALID in error
				    default : error = INVALID;
				}

				/*

				if error is INVALID print the sentence between the parentheses 
                and finish the program

                */

				if (error == INVALID)
				{
					printf("Invalid input\n");
					return 0;
				}

                //check which input3 the user choose
				switch (input3) 
				{
					//user choose a pass the switch
				   	case 'a':
				      	     break;

				    /*

					user choose (:ckeck if there was before ( :assignement 
					BAD_STRUCTURE in error , if there was not ( 
					befor :assignement of 0 in firstParhentheses.

					*/
					
				   	case '(': if(firstParhenteses == '(')
						      {
						          error = BAD_STRUCTURE;
						      }
						      else if(firstParhenteses == '0')
						      {
						          firstParhenteses = '(';
						      }
						      break;
				    //user choose [or] :assignement of BAD_STRUCTURE in error				      
					case '[':
					case ']': error = BAD_STRUCTURE;
				    break;

                    /*

					user choose ):check if there was not before ( :assignement 
					BAD_STRUCTURE in error , if there not ( 
					befor :assignement of 0 in firstParhentheses.

					*/

				     case ')': if(firstParhenteses == '0')
				      	       {
				      		       error = BAD_STRUCTURE;
				      	       }
				               if(firstParhenteses == '(')
				      	       {
				      		       firstParhenteses = '0';
				      	       }
				    	       break;

				    //user chose a wrong chars :assignement of INVALID in error
				   	default: error = INVALID;
				}

				/*

				if error is INVALID print the sentence between the parentheses 
                and finish the program

                */

				if (error == INVALID)
				{
					printf("Invalid input\n");
					return 0;
				}

				//check which input4 the user choose
			   	switch (input4) 
			   	{
			   		case 'a': if (secondParhenteses == '[')
			   		          {
			   		               error = BAD_STRUCTURE;
			   		          }
			      	         break;

					//user choose( or[ :assignement of BAD_STRUCTURE in error
				   	case '(':
				   	case '[': error = BAD_STRUCTURE;
				      	      break;

				    /*

					user choose ]:check if the input 1 [ or ( :assignement 
					BAD_STRUCTURE in error 

					*/

				    case  ']': if (input1 != '[' || input2 != '(')
				               {
			                       error = BAD_STRUCTURE;
				               }
				      		   break;

                    /*

					user choose ):check if there was not before ( :assignement 
					BAD_STRUCTURE in error , if there was not ( 
					befor :assignement of 0 in firstParhentheses. if 
					secondParhentheses is [ assignement BAD_STRUCTURE in error.

					*/

				    case ')':  if (firstParhenteses == '0')
				      	       {
				      		       error = BAD_STRUCTURE;     
				      	       }
				      	       else if (firstParhenteses == '(')
				      	       {
				      	       	    firstParhenteses = '0';
				      	       }
				      	       if (secondParhenteses == '[')
				   		       {
				   		            error = BAD_STRUCTURE;
				   		       }
				      	       break;

				    //user chose a wrong chars :assignement of INVALID in error				 
				    default: error = INVALID;
					}

                /*

				check which error is: if error is BAD_STRUCTURE or 
				firstParhentheses is ( print the Bad structure and finish the 
				program . If error is INVALID print Invalid input and finish 
				the program otherwise the parhenthese is in correct order print 
				0k and finish the program.

                */

				if (error == BAD_STRUCTURE || firstParhenteses == '(')
				{
					printf("Bad structure\n");
					return 0;
				}
				else if (error == INVALID)
				{
				    printf("Invalid input\n");
					return 0;
				}
				else
				{
					printf("Ok\n");
				}
		break;
		
		case 2: //print the sentence between the parhentheses
		        printf("Please enter first number: \n");
		        //take the input num1
			    scanf("%d",&num1);
			    //print the sentence between the parhentheses
			    printf("Please enter second number: \n");
			    //take the input num2
			    scanf("%d",&num2);
			    //print the sentence between the parhentheses
			    printf("Please enter operator: \n");
			    //take the input operator
			    scanf("%c%c",&dummy,&operator);

			    /*

			    check which operator the user choose and do the calculating 
			    for the case that the user choose

			    */
			    switch (operator)
			    {
			    	case '-': result = num1 - num2;
			    	          break;

			    	case '+': result = num1 + num2;
			    	          break;

			    	case '*': result = num1 * num2;
			    	          break;

                    /*

                    fot / :if the num 2 is 0 its an error :print Invalid input 
                    otherwise do the calculating with casting for correct answer
                    in float

                    */
			    	case '/': if (num2 == 0)
			    			  {
			    		          printf("Invalid input\n");
			    		          return 0;
			    	          }
			    	          else
			    	          {
			    		          result = (float)num1/num2;
			    	          }	
			    	          break;

			    	/*

                    for %: if the num 2 is 0 its an error :print Invalid input 
                    otherwise do the calculating.

                    */

			    	case '%': if (num2 == 0)
			    	          {
			    		          printf("Invalid input\n");
			    		          return 0;
			    	          }
			    	          else
			    	          {
			    		          result = num1 % num2;
			    	          }
			    	          break;
			    	//if the user choose another chars print Invalid input
			    	default: printf("Invalid input\n");
			    		     return 0;
			    }
			    //print the result
			    printf("The result is: %7.2f\n",result);


		break;

		case 3: //print the sentence between the parhentheses
		        printf("Please enter the average temperature per season: \n");
		        //take the 4 input as the 4 temperatures for each season
			    scanf("%f %f %f %f",&temp1, &temp2, &temp3, &temp4);

			    /*

			    if there is at least one temperature bigger than 37 or smaller
			    than 10 :print Invalid input

			    */ 
			    if ((temp1 < minTemp || temp1 > maxTemp) 
			       || (temp2 < minTemp || temp2 > maxTemp) 
			       || (temp3 < minTemp || temp3 > maxTemp) 
			       || (temp4 < minTemp || temp4 > maxTemp))
			    {
			    	printf("Invalid input\n");
			    	return 0;
			    }
			    
			    //sum of the 4 temperature 
				sum = temp1 + temp2 + temp3 + temp4;

				//average of the year
				average = sum / 4;
 				
 				/*

 				check which type: smaller than 20 :COLD, bigger or equal to 20
 				and smaller than 30: NORMAL, bigger or equal to 30 and smaller
 				or equal to 37 :HOT.

 				*/ 

				if (average < 20)
				{
					year = COLD; 		
				}

				else if (average < 30)
				{
					year = NORMAL; 		
				}

				else
				{
					year = HOT;
				}

			    	
				/*

				do the case that correspond for the average of the year and
				print the sentence correspond to the define 

				*/

				switch (year)
				{
				    case COLD: printf(PRINT_COLD); 
			            break;

				    case NORMAL: printf(PRINT_NORMAL);
					     break;

				    default: printf(PRINT_HOT);
				      
			  	}

			  	//print the average
			  	printf("Estimated average: %.2f\n",average );
		break;
		default: return 0;
	}
    return 0;

}
