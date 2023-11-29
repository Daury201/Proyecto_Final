#include <stdio.h>
#include <stdlib.h>

#define MESES 3
#define MAX_NOMBRE_ART 30
#define MAX_TIPO_ART 50

int sumarVentas(int ventasM[MESES])
{
    int total = 0;
    for (int i = 0; i < MESES; i++)
    {
        total += ventasM[i];
    }
    return total;
}

int main()
{
    printf("BIENVENIDOS AL SISTEMA DE LA TIENDA\n\n");

    int menu = 0;
    int n = 0;
    char (*nombre_art)[MAX_NOMBRE_ART] = NULL;
    int *precio_de_compra = NULL;
    int *precio_de_venta = NULL;
    char (*tipo_art)[MAX_TIPO_ART] = NULL;
    int (*ventasM)[MESES] = NULL;
    int ventas_totales = 0;
    int Mejor_mes = 0;

    do
    {
        printf("1.Agregar articulos al sistema\n");
        printf("2.Actualizar datos del articulo\n");
        printf("3.Eliminar datos del articulo\n");
        printf("4.Ver informacion del articulo\n");
        printf("5.Salir\n\n");

        printf("Seleccione la opcion que desea (1-5): ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
        {
            // Liberar la memoria asignada anteriormente si existe
            if (nombre_art != NULL)
            {
                free(nombre_art);
                free(precio_de_compra);
                free(precio_de_venta);
                free(tipo_art);
                free(ventasM);
            }

            printf("Ingrese la cantidad de articulos a ingresar al sistema (1-10): ");
            scanf("%d", &n);

            // Asignar nueva memoria
            nombre_art = malloc(n * MAX_NOMBRE_ART * sizeof(char));
            precio_de_compra = malloc(n * sizeof(int));
            precio_de_venta = malloc(n * sizeof(int));
            tipo_art = malloc(n * MAX_TIPO_ART * sizeof(char));
            ventasM = malloc(n * MESES * sizeof(int));

            for (int i = 0; i < n; i++)
            {
                printf("\nIngrese los datos para el articulo %d:\n", i + 1);

                printf("Nombre del articulo: ");
                scanf("%s", nombre_art[i]);

                printf("Precio de compra de %s: ", nombre_art[i]);
                scanf("%d", &precio_de_compra[i]);

                printf("Precio de venta de %s: ", nombre_art[i]);
                scanf("%d", &precio_de_venta[i]);

                printf("Ingresar el tipo de producto (Frutas,Carnes,Ropa,Vegetales,Bebidas): ");
                scanf("%s", tipo_art[i]);

                printf("Ingrese las ventas por cantidad en los ultimos 12 meses:\n");
                for (int j = 0; j < MESES; j++)
                {
                    printf("Mes %d: ", j + 1);
                    scanf("%d", &ventasM[i][j]);
                    if (ventasM[i][j] > ventasM[i][Mejor_mes])
                    {
                        Mejor_mes = j;
                    }
                }

                ventas_totales = sumarVentas(ventasM[i]);
                printf("Total de ventas para %s: %d\n\n", nombre_art[i], ventas_totales);
            }
        }
        break;

        case 4:
            for (int i = 0; i < n; i++)
            {
                Mejor_mes = 0;
                printf("\nInformacion del articulo %d:\n", i + 1);
                printf("Nombre: %s\n", nombre_art[i]);
                printf("Precio de compra: %d\n", precio_de_compra[i]);
                printf("Precio de venta: %d\n", precio_de_venta[i]);
                printf("Tipo: %s\n", tipo_art[i]);
                printf("Ventas en los ultimos 12 meses:\n");
                for (int j = 0; j < MESES; j++)
                {
                    printf("Mes %d: %d\n", j + 1, ventasM[i][j]);
                    if (ventasM[i][j] > ventasM[i][Mejor_mes])
                    {
                        Mejor_mes = j;
                    }
                }
                printf("El mes con mas ganancias fue el %d con: %d\n\n", Mejor_mes + 1, ventasM[i][Mejor_mes]);
            }
            break;

        case 5:
            free(nombre_art);
            free(precio_de_compra);
            free(precio_de_venta);
            free(tipo_art);
            free(ventasM);
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Ingrese una opcion valida, intentelo nuevamente (1-5)\n\n");
        }
    } while (menu != 5);

    return 0;
}
/*Miercoles 1:33*/
