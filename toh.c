    /*

     * C program for Tower of Hanoi using Recursion

     */

    #include <stdio.h>
    #include<conio.h>

     

    void towers(int, char, char, char);

     

    int main()

    {

        int num;

     

        printf("Enter the number of disks : ");
        fflush(stdin);

        scanf("%d", &num);

        printf("The sequence of moves involved in the Tower of Hanoi are :\n");

        towers(num, 'A', 'C', 'B');
        getch();

        return 0;

    }

    void towers(int num, char frompeg, char topeg, char auxpeg)

    {
	//static 	int count=0;
        if (num==1)

        {

            printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);

        
}
else {

        towers(num - 1, frompeg, auxpeg, topeg);

        printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
    

        towers(num - 1, auxpeg, topeg, frompeg);
      //  count++;
		}
		//printf("count=%d",count);

    }
