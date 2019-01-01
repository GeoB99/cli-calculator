/* Simple Calculator
 *
 * Module: main.c
 * 
 * Purpose: Main C file of the program
 * 
 * Created by: Bișoc George (Fraizeraust)
 * 
 * Remarks: For further documentation and notes regard fgets(), strtol(), strtod()
 *          and sleep() check one of the links below.
 * 
 *          fgets()  -- https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
 *          strtol() -- https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
 *          strtod() -- https://www.tutorialspoint.com/c_standard_library/c_function_strtod.htm
 *          sleep()  -- https://linux.die.net/man/3/sleep
 * 
*/

/* INCLUDES */

#include "precomp.h"

/* SETUP */

int PrintString(const char *Message, ...)
{
    /* List the arguments */
    va_list Arg;
    int Ret;

    /* Iterate the arguments */
    va_start(Arg, Message);
    Ret = vprintf(Message, Arg);

    if (!Ret)
    {
        /* If vprintf() fails for some weird reason, then return the appropriate value and bail out */
        return 1;
    }

    /* If we're here, then free the list of arguments invoked by va_list() */
    va_end(Arg);

    return Ret;
}

int CalcInit(void)
{
    /* Declaration and initialization */
    int TimeOut;
    TimeOut = 3;

    /* Print the string into the terminal */
    PrintString("The calculator is initializing...\n");

    while (TimeOut > 0)
    {
        /* Decrease the countdown */
        --TimeOut;

        /* Sleep for one second, this will delay the loop */
        sleep(1);

        if (TimeOut == 0)
        {
            /* Stop the loop and invoke CalcEngine() which is the main calculator's routine */
            CalcEngine();
            break;
        }
    }

    return 0;
}

int CalcEngine(void)
{
    /* Declarations */
    char Operator[MAX_NUM];
    char FirstOperand[MAX_NUM];
    char SecondOperand[MAX_NUM];
    char Buffer[MAX_BUFF];
    char RootOperand[MAX_NUM];
    long RetFirstOperand;
    long RetSecondOperand;
    long RetOperator;
    double RetRootOperand;

    /* Output the welcome string */
    PrintString("Welcome to cli-calculator!\n");
    
    /* 
     * Get into the loop, the execution of the do...while loop
     * ceases only if the user wrote to STDIN "no" if the user
     * doesn't want to do another operation with the calculator.
     * If the written answer is "yes" then the body code inside
     * the loop will repeat.
    */
    do
    {
        PrintString("Please enter one of the following operator (in number)\n");
        PrintString("\n1 - Addition\n");
        PrintString("\n2 - Subtraction\n");
        PrintString("\n3 - Multiplication\n");
        PrintString("\n4 - Division\n");
        PrintString("\n5 - Square Root\n");
        PrintString("\n");
        PrintString("> ");

        /*
         * Retrieve the operator from STDIN stream (in character type).
         * This will be converted later into an integer long for switch().
        */
        fgets(Operator, 10, stdin);
        RetOperator = strtol(Operator, NULL, 0);

        /*
         * Do a condition check, if the input is equal to an integer of 5.
         * If that's the case then the user chose to do a square root operation
         * and such operation requires only one operand unlike other operations.
         * This will be converted later into a floating point of double type.
         * If the condition is false (STDIN is not 5) then go to the other conditional
         * body code depending on the chosen operator.
        */
        if (RetOperator == 5)
        {
            PrintString("Enter the operand for the root\n");
            PrintString("> ");
            fgets(RootOperand, MAX_NUM, stdin);
            RetRootOperand = strtod(RootOperand, NULL);
        }
        else
        {
            /*
             * Retrieve the first operand from STDIN (in character type).
             * This will be converted later into an integer long for specific
             * cases within the switch body of code.
            */
            PrintString("Enter the first operand\n");
            PrintString("> ");
            fgets(FirstOperand, MAX_NUM, stdin);
            RetFirstOperand = strtol(FirstOperand, NULL, 0);

            /*
             * Retrieve the second operand from STDIN (in character type).
             * This will be converted later into an integer long for specific
             * cases within the switch body of code.
            */
            PrintString("Enter the second operand\n");
            PrintString("> ");
            fgets(SecondOperand, MAX_NUM, stdin);
            RetSecondOperand = strtol(SecondOperand, NULL, 0);
        }

        /*
         * Execute the body code of switch(). The cases within the code block are based upon
         * the chosen operator which is stored by RetOperator variable.
        */
        switch (RetOperator)
        {
            /* Addition */
            case 1:
            {
                PrintString("%d + %d = %d\n", RetFirstOperand, RetSecondOperand, RetFirstOperand + RetSecondOperand);
                break;
            }

            /* Subtraction */
            case 2:
            {
                PrintString("%d - %d = %d\n", RetFirstOperand, RetSecondOperand, RetFirstOperand - RetSecondOperand);
                break;
            }

            /* Multiplication */
            case 3:
            {
                PrintString("%d * %d = %d\n", RetFirstOperand, RetSecondOperand, RetFirstOperand * RetSecondOperand);
                break;
            }

            /* Division */
            case 4:
            {
                /*
                 * To avoid unexpected occurrences we shall do a condition check if the second operand is equal to 0.
                 * If that's the case, this is an invalid operation and we must handle it appropriately.
                */
                if (RetSecondOperand == 0)
                {
                    PrintString("It's impossible to divide by zero! The application will exit...\n");
                    exit(0);
                    break;
                }

                PrintString("%d / %d = %d\n", RetFirstOperand, RetSecondOperand, RetFirstOperand / RetSecondOperand);
                break;
            }

            /* Square root */
            case 5:
            {
                /* If the root operand is negative then this is an invalid operation which we must handle it */
                if (RetRootOperand < 0)
                {
                    PrintString("It's impossible to do the square root by having a negative operand! The application will exit...\n");
                    exit(0);
                    break;
                }

                PrintString("The square root of %lf is %lf\n", RetRootOperand, sqrt(RetRootOperand));
                break;
            }

            /* If none of the operators match with the expected condition then the program will exit */
            default:
            {
                PrintString("Please enter a valid number which represents the operator! The application will exit...\n");
                exit(0);
                break;
            }
        }

        /*
         * If we're here then everything went good. Ask the user if he/she
         * wants to continue using the calculator. The actual check is done
         * by the strcmp() function in while loop below (the program will exit
         * if the answer is "no", otherwise the process will continue).
        */
        PrintString("Would you like to do another operation? (yes/no)\n");
        PrintString("\n");
        PrintString("> ");
        fgets(Buffer, MAX_BUFF, stdin);
    } while (strcmp(Buffer, "yes\n") == 0);

    return 0;
}

int main(void)
{
    /*
     * Declare and initialize Ret by invoking the CalcInit() routine
     * which will initialize the calculator program.
    */
    int Ret;
    Ret = CalcInit();

    /* Do a sanity check if the routine fails to perform the initialization procedure */
    if (!Ret)
    {
        /* Fail and bail out */
        return 1;
    }

    return 0;
}

/* EOF */
