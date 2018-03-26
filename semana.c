#include <stdio.h>
#include <stdlib.h>
#define MsjError "Se ha producido un error"
#define MsjNumeroInvalido "El caracter ingresado no es un numero entero"
#define MsjNumeroIlogico "El numero ingresado es menor que 0 o mayor que 366 por lo que no corresponde al numero de dia de un año"
#define MsjExplicacion "Rayos Cosmicos"

int main (void)
{
int numero,dia,x;
char c;

printf ("Escriba que dia del 1 al 366 es hoy para saber que dia de la semana es\n");

x = scanf ("%d",&numero);
if (x != 1)
{
fprintf (stderr, "%s: %s", MsjError, MsjNumeroInvalido); /* indica que no se ingreso un numero entero */
return EXIT_FAILURE;
}

while ((c = getchar ()) != '\n' && c != EOF) /* vacia buffer */
;

if (numero <= 0 || numero > 366)
{fprintf (stderr, "%s: %s", MsjError, MsjNumeroIlogico); /* no acepta que se ingresen numeros que no correspondan a un dia de un año */
return EXIT_FAILURE;
}

dia = (numero+7)%7; /* convierte cada numero ingresado a un numero del 0 al 7 */

switch (dia) /* asigna un dia de la semana a cada numero del 0 al 6 */
{
case 1 :
printf ("Hoy es domingo\n");
break;

case 2 :
printf ("Hoy es lunes\n");
break;

case 3 :
printf ("Hoy es martes\n");
break;

case 4:
printf ("Hoy es miercoles\n");
break;

case 5 :
printf ("Hoy es jueves\n");
break;

case 6 :
printf ("Hoy es viernes\n");
break;

case 0 :
printf ("Hoy es sabado\n");
break;

default : fprintf (stderr, "%s: %s", MsjError, MsjExplicacion);
}

return EXIT_SUCCESS;
}
