#include<reg51.h>

void delay(){
	unsigned int i,j;
	for(i=0;i<=200;i++){
		for(j=0;j<=200;j++){
		}
	}
}

int main(){
	
	unsigned char pattern = 0xFE;
	
	while(1){
		
		
		P1 = pattern;
		delay();
		
		pattern = (pattern << 1) | 0x01;
		
		if (pattern == 0xFF){
			
			  pattern = 0xFE;
		}
	}
}
