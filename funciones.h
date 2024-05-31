#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

struct Producto {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
};

void ingresarProducto(struct Producto inventario[], int *numProductos);
void editarProducto(struct Producto inventario[], int numProductos);
void eliminarProducto(struct Producto inventario[], int *numProductos);
void listarProductos(struct Producto inventario[], int numProductos);

#endif // FUNCIONES_H