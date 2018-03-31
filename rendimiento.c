#include <stdio.h>
#include <stdlib.h>
#define MsjError "Se ha producido un error"
#define MsjNumeroInvalido "El caracter ingresado no es un numero"
#define MsjNegativo "la magnitud no puede ser negativa"

int main (void) {

	float km,precio,totalpesos,rendimiento, rendimientomin, rendimientomax, rendimientotot = 0, kmtot = 0, combustibletot = 0, costotot = 0, promedio, datos = 0;
	int x,y,z, ingresos = 0;
	char c; /* declaracion de variables */

	do {
		puts ("Ingrese los kilometros recorridos (-1 para terminar):");
		x = scanf ("%f",&km);

		if (x != 1){ /*validacion*/
			fprintf (stderr,"%s: %s", MsjError, MsjNumeroInvalido);
			return EXIT_FAILURE;
		}
		while ((c=getchar ()) != '\n' && c != EOF)
		;

		if (km == -1) /*sale del ciclo si se ingresa -1*/
		break;
	
		if (km < 0) { /*validacion*/
	
			fprintf (stderr, "%s: %s", MsjError, MsjNegativo);
			return EXIT_FAILURE;
		}

		puts ("Ingrese el precio del combustible por litro:");
		y = scanf ("%f",&precio);

		if (y != 1) {
			fprintf (stderr,"%s: %s", MsjError, MsjNumeroInvalido);
			return EXIT_FAILURE;
		}
		while ((c=getchar ()) != '\n' && c != EOF)
		;
		if (precio < 0) {
			fprintf (stderr, "%s: %s", MsjError, MsjNegativo);
			return EXIT_FAILURE;
		}

		puts ("Ingrese el monto total en pesos utilizado en esta compra:");
		z = scanf ("%f",&totalpesos);

		if (z != 1) {
			fprintf (stderr,"%s: %s", MsjError, MsjNumeroInvalido);
			return EXIT_FAILURE;
		}
		while ((c=getchar ()) != '\n' && c != EOF)
		;
		if (totalpesos < 0) {
			fprintf (stderr, "%s: %s", MsjError, MsjNegativo);
			return EXIT_FAILURE;
		}

		rendimiento = ((totalpesos/precio)*100)/km; /*calculo e impresion del rendimiento para cada ingreso*/

		printf ("Rendimiento (1/100 km) de este tanque : %.2f\n", rendimiento);
	
		if (datos == 0) {
			rendimientomax = rendimiento;
			rendimientomin = rendimiento;
			datos = 1;
		}
		if (datos == 1) {
			if (rendimientomax < rendimiento)
				rendimientomax = rendimiento;
			if (rendimientomin > rendimiento)
				rendimientomin = rendimiento;
		}

		rendimientotot = rendimientotot + rendimiento; /*total de rendimientos para luego hacer promedio*/
		kmtot = kmtot + km; /*total de km recorridos*/
		combustibletot = combustibletot + (totalpesos/precio); /*total combustible gastado*/
		costotot = costotot + totalpesos; /*total dinero gastado*/
		ingresos ++; /*lleva la cuenta de las veces que se ingresan datos*/

	}
	while (km != -1);

	promedio = rendimientotot/ingresos; /*calculo promedio*/

	printf ("Rendimiento promedio (1/100km): %.4f\nMejor rendimiento (1/100km): %.2f\nPeor rendimiento (1/100km): %.2f\nDistancia total recorrida (km): %.2f\nCombustible total consumidos (l): %.2f\nCosto total de su vehiculo: %.2f\n", promedio, rendimientomin, rendimientomax, kmtot, combustibletot, costotot); /*impresion final*/

	return EXIT_SUCCESS;
}



