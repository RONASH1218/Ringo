#include <stdio.h>
#include <conio.h>
#include<math.h>

void dectobinary(int nbit,int num,int arry[])
{
	while(nbit>=0){
		if(num>0){
			arry[nbit-1]=num%2;
			num=num/2;
			nbit--;
		}
		else{
			arry[nbit-1]=0;
			nbit--;
		}
	}
}

int num(int arry[], int nbit){
	int i,a=0;
	for(i=0;i<nbit;i++){
		a=a*10+arry[i];
	}
	return a;
}
int binaryAddition(int a, int b) {
    int carry = 0, result = 0, bit = 1;
    while (a != 0 || b != 0) {
        int bit_a = a % 10;
        int bit_b = b % 10;

       
        int sum = bit_a + bit_b + carry;

        
        result += (sum % 2) * bit;

        
        carry = sum / 2;

        
        a /= 10;
        b /= 10;
        bit *= 10;
    }

    
    result += carry * bit;
    return result;
}


int logicalShiftLeft(int num) {
    return num * 10; 
}


int logicalShiftRight(int num) {
    return num / 10; 
}


int boothMultiply(int multiplicand, int multiplier) {
    int accumulator = 0;
    int bitMask = 1;

    
    while (multiplier != 0) {
        
        if (multiplier % 10 == 1) {
            accumulator = binaryAddition(accumulator, multiplicand);
        }

        
        multiplicand = logicalShiftLeft(multiplicand);
        multiplier = logicalShiftRight(multiplier);

        
        bitMask *= 10;
    }

    return accumulator;
}


int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary != 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main() {
    int num1,num2,arry1[10],arry2[10],sum[10],nbit, multiplicand, multiplier;
    printf("enter the number of bits:");
    scanf("%d", &nbit);
    printf("Enter the multiplicand: ");
    scanf("%d", &num1);
    
    printf("Enter the multiplier: ");
    scanf("%d", &num2);
    
    	if(num1<0){
		dectobinary(nbit,abs(num1),arry1);
	}
	else{
		dectobinary(nbit,num1,arry1);
	}
	
	if(num2<0){
		dectobinary(nbit,abs(num2),arry2);
	}
	else{
		dectobinary(nbit,num2,arry2);
	}

  	multiplicand= num(arry1,nbit);
  	multiplier = num(arry2,nbit);
    int product = boothMultiply(multiplicand, multiplier);

    printf("Product of the two binary numbers: %d (binary)\n", product);
    printf("Product in decimal: %d\n", binaryToDecimal(product));

    getch();
    return 0;
}
