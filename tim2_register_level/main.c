#define RCC_BASE   0x40021000
#define GPIOC_BASE 0x40011000
#define TIM2_BASE  0x40000000

#define RCC_APB1ENR  (*(volatile unsigned long *)(RCC_BASE + 0x1C))
#define RCC_APB2ENR  (*(volatile unsigned long *)(RCC_BASE + 0x18))
#define GPIOC_CRH    (*(volatile unsigned long *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR    (*(volatile unsigned long *)(GPIOC_BASE + 0x0C))
#define TIM2_CR1     (*(volatile unsigned long *)(TIM2_BASE + 0x00))
#define	TIM2_SR      (*(volatile unsigned long *)(TIM2_BASE + 0x10))
#define	TIM2_PSC		 (*(volatile unsigned long *)(TIM2_BASE + 0x28))
#define TIM2_ARR		 (*(volatile unsigned long *)(TIM2_BASE + 0x2C))

void delay(volatile unsigned int ms){
		TIM2_PSC = 7999;
		TIM2_ARR = ms;
		TIM2_SR &= ~(1);
		TIM2_CR1 |= 1;
	
		while(!(TIM2_SR & 1));
			
		TIM2_CR1 &= ~(1);

}

int main(){
		RCC_APB2ENR |= 0x10;
		RCC_APB1ENR |= 1;
		GPIOC_CRH &= 0x0FFFFF;
		GPIOC_CRH |= 0x100000;

		while(1){
				GPIOC_ODR ^= (1<<13);
				delay(5000);
		}


		return 0;
}