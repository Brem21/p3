#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProducto(struct Producto inventario[], int *numProductos) {
    if (*numProductos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", inventario[*numProductos].nombre);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &inventario[*numProductos].precio);
        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &inventario[*numProductos].cantidad);
        
        (*numProductos)++;
        printf("Producto ingresado correctamente.\n");
    } else {
        printf("El inventario está lleno, no se pueden agregar más productos.\n");
    }
}

void editarProducto(struct Producto inventario[], int numProductos) {
    char nombreEditar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreEditar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombreEditar) == 0) {
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &inventario[i].precio);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &inventario[i].cantidad);
            printf("Producto editado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado en el inventario.\n");
    }
}

void eliminarProducto(struct Producto inventario[], int *numProductos) {
    char nombreEliminar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreEliminar);

    int encontrado = 0;
    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombreEliminar) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*numProductos)--;
            printf("Producto eliminado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado en el inventario.\n");
    }
}

void listarProductos(struct Producto inventario[], int numProductos) {
    printf("Productos en el inventario:\n");
    printf("Nombre\t\tPrecio\tCantidad\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s\t\t%.2f\t%d\n", inventario[i].nombre, inventario[i].precio, inventario[i].cantidad);
    }
}
