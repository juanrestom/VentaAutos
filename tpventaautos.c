#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct VentaAuto {
   char cliente[50];
   char modelo[50];
   float precio;
};

void agregarVenta(struct VentaAuto ventas[], int *contador) {
    struct VentaAuto nuevaVenta;
    printf("Ingrese el nombre del cliente: ");
    fgets(nuevaVenta.cliente, sizeof(nuevaVenta.cliente), stdin);
    printf("Ingrese el modelo del auto: ");
    fgets(nuevaVenta.modelo, sizeof(nuevaVenta.modelo), stdin);
    printf("Ingrese el precio de venta: ");
    scanf("%f", &nuevaVenta.precio);
    getchar();  // Limpiar el búfer de entrada

    ventas[*contador] = nuevaVenta;
    (*contador)++;
    printf("Venta agregada correctamente.\n");
};
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
};
void modificarVenta(struct VentaAuto ventas[], int contador, int indice) {
    if (indice >= 0 && indice < contador) {
        struct VentaAuto ventaModificada;
        printf("Ingrese el nombre del cliente: ");
        fgets(ventaModificada.cliente, sizeof(ventaModificada.cliente), stdin);
        printf("Ingrese el modelo del auto: ");
        fgets(ventaModificada.modelo, sizeof(ventaModificada.modelo), stdin);
        printf("Ingrese el precio de venta: ");
        scanf("%f", &ventaModificada.precio);
        getchar();  // Limpiar el búfer de entrada

        ventas[indice] = ventaModificada;
        printf("Venta modificada correctamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
};
void mostrarVentas(struct VentaAuto ventas[], int contador) {
    printf("=== Listado de Ventas ===\n");
    if (contador > 0) {
        for (int i = 0; i < contador; i++) {
            printf("Venta %d:\n", i + 1);
            printf("Cliente: %s", ventas[i].cliente);
            printf("Modelo: %s", ventas[i].modelo);
            printf("Precio: %.2f\n", ventas[i].precio);
            printf("---------------------------\n");
        }
    } else {
        printf("No hay ventas registradas.\n");
    }
};
int main() {
    struct VentaAuto ventas[100];
    int contador = 0;
    char opcion_str[3];
    char indice_str[3];
    int opcion;  // Variable opcion declarada fuera del do-while

    do {
        printf("\n=== Mini Sistema ABM - Ventas de Autos ===\n");
        printf("1. Agregar venta\n");
        printf("2. Eliminar venta\n");
        printf("3. Modificar venta\n");
        printf("4. Mostrar listado de ventas\n");
        printf("5. Salir\n");
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
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}




