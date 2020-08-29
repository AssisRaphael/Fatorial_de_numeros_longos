#include <stdio.h>
#include <stdlib.h> // apenas para usar alocação dinamica

//Programa que calcula fatorial de números enormes


short int *num;//vetor de caracteres que irá armazenar os algarísmos do número

void Fatorial(int n){

	int nDigitos, VaiUm, novoDigito;

	num[0] = 1; //o número começa com 1

	//Faz a multiplicação do resultado por todos os termos de n	
	for(int i=1;i<=n;i++){//percorre os n termos para calcular o fatorial

		for(int j=0;j<nDigitos;j++){
			novoDigito = num[j] * i + VaiUm;//calcula o valor numérico na posição j
			num[j] = novoDigito % 10;//escreve a unidade do número
			VaiUm = novoDigito / 10;//calcula o quanto sobra pra proxima casa decimal
		}

		while(VaiUm>0){
			num[nDigitos] = VaiUm % 10;//O próximo digito é a dezena anterior, que pode ser maior que 10
			VaiUm = VaiUm / 10;//refatora o número e repete o processo até não surgir mais dezenas
			nDigitos++;//Aumenta mais um algarismono número
		}
	}
}

void Imprime(){
	
	int inicioNumero = 0;//representa se o numero ja começou
						 //Ex: 00542 começa no 3 digito

	for(int i=39999; i>=0; i--){//percorre a string do numero
		if(num[i]!=0)
			inicioNumero=1;
		if(inicioNumero){
			printf("%d",num[i]);
		}
	}
}


int main(){
	 
	int n;
	num = malloc(sizeof(int)*40000);//armazena um número com até 40 mil algarísmos

	printf("Digite um numero inteiro: ");
	scanf("%d",&n);

	for(int i=0; i<40000; i++)//zera o vetor de números
		num[i]=0;

	Fatorial(n);

	printf("Resultado: ");
	Imprime();
	printf("\n");

	free(num);
}








