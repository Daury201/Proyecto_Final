int main()
{
    printf("BIENVENIDOS AL SISTEMA DE LA TIENDA\n\n");

    /*Declaración variables n para determinar longitud y menu*/

    int menu=0;
    int n=0;

    /*Estructura del menu*/
    do
    {
        printf("1.Agregar articulos al sistema\n");
        printf("2.Actualizar datos del articulo\n");
        printf("3.Eliminar datos del articulo\n");
        printf("4.Ver informacion del articulo\n");
        printf("5.Salir\n\n");

        printf("Seleccione la opcion que desea(1-5):\n");
        scanf("%d", &menu);

        switch(menu)
        {

        case 1:
        {
            printf("Ingrese la cantidad de articulos a ingresar al sistema:\n");
            scanf("%d", &n);

            /*Declaración de principales variables a utilizar*/

            char nombre_art [n][30];
            int precio_de_compra[n];
            int precio_de_venta[n];
            char tipo_art[5][50];
            int ventasM[12];

            for(int i=0; i<n; i++)
            {
                printf("Nombre del articulo %d\n",i+1);
                scanf("%s", &nombre_art[i]);
                printf("Precio de compra de %s:\n", nombre_art[i]);
                scanf("%d", &precio_de_compra[i]);
                printf("Precio de venta de %s:\n", nombre_art[i]);
                scanf("%d", &precio_de_venta[i]);
                printf("Ingresar el tipo de producto (Frutas,Carnes,Ropa,Vegetales,Bebidas)\n");
                scanf("%s", &tipo_art[i]);
                printf("Ingrese las ventas por cantidad en los ultimos 12 meses\n");

                for(int j=0; j<3; j++)
                {
                    printf("Mes %d: ", j+1);
                    scanf("%d", &ventasM[j]);
                }
                printf("\n");

            }

        }

        break;

        case 2:
        {
            printf("Funcion disponible proximamente...\n");
        }
        break;

        case 3:
        {
            printf("Funcion disponible proximamente...\n");
        }
        break;

        case 4:
        {
            printf("Funcion disponible proximamente...\n");
        }
        break;

        case 5:
        {
            printf("Saliendo del programa...\n");
        }
        break;

        default:
        {
            printf("Ingrese una opcion valida, intentelo nuevamente(1-5)\n\n");
        }
        }
    }
    while(menu!=5);

    return 0;
}






    /*Solicitud de informacion*/

   /* for(int i=0; i<n; i++)
    {
        printf("El articulo %s tiene un precio de compra de: %d un precio de venta de: %d y es de tipo: %s\n\n",
               nombre_art[i], precio_de_compra[i], precio_de_venta[i], tipo_art[i]);

    }*/

