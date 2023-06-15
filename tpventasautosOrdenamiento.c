#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct VentaAuto {
   char lugar[50];
   char vendedor[50];
   char cliente[50];
   char direccion[50];
   char modelo[50];
   float precio;
};

void agregarVenta(struct VentaAuto ventas[], int *contador) {
    struct VentaAuto nuevaVenta;
    
   printf("Ingrese el lugar: ");
    fgets(nuevaVenta.lugar, sizeof(nuevaVenta.lugar), stdin);
    
    printf("Ingrese el vendedor: ");
    fgets(nuevaVenta.vendedor, sizeof(nuevaVenta.vendedor), stdin);
    
    printf("Ingrese el cliente: ");
    fgets(nuevaVenta.cliente, sizeof(nuevaVenta.cliente), stdin);
    
    printf("Ingrese la dirección: ");
    fgets(nuevaVenta.direccion, sizeof(nuevaVenta.direccion), stdin);
    
    printf("Ingrese el modelo del auto: ");
    fgets(nuevaVenta.modelo, sizeof(nuevaVenta.modelo), stdin);
    
    printf("Ingrese el precio de venta: ");
    scanf("%f", &nuevaVenta.precio);
    getchar();  
    
    ventas[*contador] = nuevaVenta;
    (*contador)++;
    
    printf("Venta agregada correctamente.\n");
}

void eliminarVenta(struct VentaAuto ventas[], int *contador, int indice) {
    if (indice >= 0 && indice < *contador) {
        for (int i = indice; i < *contador - 1; i++) {
            ventas[i] = ventas[i + 1];
        }
        (*contador)--;
        printf("Venta eliminada correctamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

void modificarVenta(struct VentaAuto ventas[], int contador, int indice) {
    if (indice >= 0 && indice < contador) {
        struct VentaAuto ventaModificada;
        
        printf("Ingrese el lugar: ");
        fgets(ventaModificada.lugar, sizeof(ventaModificada.lugar), stdin);
        
        printf("Ingrese el vendedor: ");
        fgets(ventaModificada.vendedor, sizeof(ventaModificada.vendedor), stdin);
        
        printf("Ingrese el cliente: ");
        fgets(ventaModificada.cliente, sizeof(ventaModificada.cliente), stdin);
        
        printf("Ingrese la dirección: ");
        fgets(ventaModificada.direccion, sizeof(ventaModificada.direccion), stdin);
        
        printf("Ingrese el modelo del auto: ");
        fgets(ventaModificada.modelo, sizeof(ventaModificada.modelo), stdin);
        
        printf("Ingrese el precio de venta: ");
        scanf("%f", &ventaModificada.precio);
        getchar();
        
        ventas[indice] = ventaModificada;
        
        printf("Venta modificada correctamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

void mostrarVentas(struct VentaAuto ventas[], int contador) {
    printf(" Listado de Ventas\n");
    if (contador > 0) {
        for (int i = 0; i < contador; i++) {
            printf("Venta %d:\n", i + 1);
            printf("Lugar: %s", ventas[i].lugar);
            printf("Vendedor: %s", ventas[i].vendedor);
            printf("Cliente: %s", ventas[i].cliente);
            printf("Dirección: %s", ventas[i].direccion);
            printf("Modelo: %s", ventas[i].modelo);
            printf("Precio: %.2f\n", ventas[i].precio);
            printf("---------------------------\n");
        }
    } else {
        printf("No hay ventas registradas.\n");
    }
}

void merge(struct VentaAuto ventas[], int izquierda, int medio, int derecha) {
    int i, j, k;
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    struct VentaAuto izquierdaArray[n1], derechaArray[n2];

    for (i = 0; i < n1; i++)
        izquierdaArray[i] = ventas[izquierda + i];
    for (j = 0; j < n2; j++)
        derechaArray[j] = ventas[medio + 1 + j];

    i = 0;
    j = 0;
    k = izquierda;

    while (i < n1 && j < n2) {
        if (izquierdaArray[i].precio <= derechaArray[j].precio) {
            ventas[k] = izquierdaArray[i];
            i++;
        } else {
            ventas[k] = derechaArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ventas[k] = izquierdaArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        ventas[k] = derechaArray[j];
        j++;
        k++;
    }
}

void mergeSort(struct VentaAuto ventas[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(ventas, izquierda, medio);
        mergeSort(ventas, medio + 1, derecha);

        merge(ventas, izquierda, medio, derecha);
    }
}
void quickSort(struct VentaAuto ventas[], int izquierda, int derecha) {
    int i = izquierda;
    int j = derecha;
    char pivote[50];
    strcpy(pivote, ventas[(izquierda + derecha) / 2].cliente);

    while (i <= j) {
        while (strcmp(ventas[i].cliente, pivote) < 0)
            i++;
        while (strcmp(ventas[j].cliente, pivote) > 0)
            j--;

        if (i <= j) {
            struct VentaAuto temp = ventas[i];
            ventas[i] = ventas[j];
            ventas[j] = temp;

            i++;
            j--;
        }
    }

    if (izquierda < j)
        quickSort(ventas, izquierda, j);
    if (i < derecha)
        quickSort(ventas, i, derecha);
}
int main() {
    struct VentaAuto ventas[100];
    int contador = 0;
    char opcion_str[3];
    char indice_str[3];
    int opcion;

    do {
        printf("\nSistema ABM - Ventas de Autos\n");
        printf("1. Agregar venta\n");
        printf("2. Eliminar venta\n");
        printf("3. Modificar venta\n");
        printf("4. Listar ventas\n");
        printf("5. Ordenar ventas (Merge Sort)\n");
        printf("6. Ordenar ventas (Quick Sort)\n");
        printf("7. Salir\n");
        printf("Ingrese una opción: ");
        fgets(opcion_str, sizeof(opcion_str), stdin);
        sscanf(opcion_str, "%d", &opcion);

        switch (opcion) {
            case 1:
                agregarVenta(ventas, &contador);
                break;
            case 2:
                printf("Ingrese el índice de la venta a eliminar: ");
                fgets(indice_str, sizeof(indice_str), stdin);
                int indice;
                sscanf(indice_str, "%d", &indice);
                eliminarVenta(ventas, &contador, indice);
                break;
            case 3:
                printf("Ingrese el índice de la venta a modificar: ");
                fgets(indice_str, sizeof(indice_str), stdin);
                sscanf(indice_str, "%d", &indice);
                modificarVenta(ventas, contador, indice);
                break;
            case 4:
                mostrarVentas(ventas, contador);
                break;
            case 5:
                mergeSort(ventas, 0, contador - 1);
                printf("Ventas ordenadas por Merge Sort.\n");
                break;
            case 6:
                quickSort(ventas, 0, contador - 1);
                printf("Ventas ordenadas por Quick Sort.\n");
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
