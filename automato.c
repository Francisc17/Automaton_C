#include <stdio.h>

/*
q0-A
q1-B
q2-C
q3-D
q4-E
q5-F
q6-G
q7-H
q8-I
q9-J
q10-K
q11-L
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{

	FILE *filePointer;
	char simb,estado = 'A';
	int erro = 0;


	filePointer = fopen("palavra.txt", "r");

	if (filePointer == NULL)
	{
			printf("File is not available \n");
	}
	else
	{

			while ((simb = fgetc(filePointer)) != EOF && (erro == 0))
			{
					switch (estado)
					{
					case 'A' :
						if ((simb == 'x') || (simb == 'y') || (simb == 'z'))
							estado = 'B';
						else
							if (simb == '!')
								estado = 'G';
						else
								erro = 1;
						break;

					case 'B':
						if (simb == '>')
							estado = 'C';
						else
							erro = 1;
						break;

					case 'C':
						if((simb == '-') || (simb == '+'))
							estado = 'D';
						else
							erro = 1;
						break;

			    case 'D':
			      if((simb >= 48 && simb <= 57)) //valores na tabela de ascii para os algarismos
			        estado = 'E';
			      break;

			    case 'E':
			      if((simb >= 48 && simb <= 57))
			        estado = 'E';
			      else
			        if(simb == ',')
			          estado = 'F';
			      else
			        if(simb == '#')
			          estado = 'A';
			      else
			        erro = 1;
			      break;

			    case 'F':
			      if ((simb >= 48 && simb <= 57))
			        estado = 'F';
			      else
			        if(simb == '#')
			          estado = 'A';
			      else
			        if(simb == '!')
			          estado = 'G';
			      else
			        erro = 1;
			      break;

			    case 'G':
			      if((simb == '-') || (simb == '+'))
			        estado = 'H';
			      else
			        if((simb == 'x') || (simb == 'y') || (simb == 'z'))
			          estado = 'K';
			      else
			        erro = 1;
			      break;

			    case 'H':
			      if((simb >= 48 && simb <= 57))
			        estado = 'I';
			      else
			        erro = 1;
			      break;

			    case 'I':
			      if((simb == '+') || (simb == '-') || (simb == '*'))
			        estado = 'G';
			      else
			        if(simb == ',')
			          estado = 'J';
			      else
			        if(simb == '_')
			          estado = 'G';
			      else
			        if(simb == '.')
			          estado = 'L';
						else
							if((simb >= 48 && simb <= 57))
								estado = 'I';
			      else
			        erro = 1;
			      break;

			    case 'J':
			      if((simb == '+') || (simb == '-') || (simb == '*'))
			        estado = 'G';
			      else
			        if((simb >= 48 && simb <= 57))
			          estado = 'J';
			      else
			        if(simb == '_')
			          estado = 'G';
			      else
			        if(simb == '.')
			          estado = 'L';
			      else
			        erro = 1;
			      break;

			    case 'K':
			      if(simb == '_')
			        estado = 'G';
			      else
			        if((simb == '+') || (simb == '-') || (simb == '*'))
			          estado = 'G';
			      else
			        if(simb == '.')
			          estado = 'L';
			      else
			        erro = 1;
			      break;

			      default:
			        erro = 1;
					}
			}
	}

	fclose(filePointer);


	if ((!erro) && (estado == 'L'))
		printf("\nPalavra da linguagem!!!\n");
	else
		printf("\nA palavra nao pertence a linguagem!!!\n");


	return 0;
}
