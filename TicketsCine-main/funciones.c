#include <stdio.h>
#include "funciones.h"
#include <string.h>

void ingresarCliente(char clientes[5][2][40]){


for (int i = 0; i < 5; i++) 
{
    if(strcmp(clientes[i][0], "") == 0) {
        printf("Ingrese nombre del nuevo cliente: ");
        scanf("%s", clientes[i][0]);
        printf("Ingrese cedula del nuevo cliente: ");
        scanf("%s", clientes[i][1]);
        break;
    }
} 
imprimirClientes(clientes);
}

void imprimirClientes(char clientes[5][2][40]) {
for (int i = 0; i < 5; i++) {
printf("%s\t\t%s\n", clientes[i][0], clientes[i][1]);
}
}

void listarPeliculas(char peliculas[10][4][40]) {
for (int i = 0; i < 10; i++) {
printf("ID: %s, Nombre: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
}
}

void buscarporNombre(char peliculas[10][4][40]) {
char nombre[40];
printf("Ingrese el nombre de la pelicula: ");
scanf("%s", nombre);
for (int i = 0; i < 10; i++) {
if (strcmp(peliculas[i][1], nombre) == 0) {
printf("ID: %s, Nombre: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
return;
}
}
printf("Pelicula no encontrada.\n");
}

void buscarporGenero(char peliculas[10][4][40]) {
char genero[40];
printf("Ingrese el genero de la pelicula: ");
scanf("%s", genero);
for (int i = 0; i < 10; i++) {
if (strcmp(peliculas[i][3], genero) == 0) {
printf("ID: %s, Nombre: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
}
}
}

void comprarTicket(char peliculas[10][4][40], double precio[3], char clientes[5][2][40], int reserva[10][4]) {
int peliculaId, clienteId, ticketCantidad;
printf("Ingrese el ID de la pelicula: ");
scanf("%d", &peliculaId);
printf("Ingrese el ID del cliente: ");
scanf("%d", &clienteId);
printf("Ingrese la cantidad de tickets: ");
scanf("%d", &ticketCantidad);


if (peliculaId > 0 && peliculaId <= 10 && clienteId > 0 && clienteId <= 5 && ticketCantidad > 0) {
    for (int i = 0; i < 4; i++) {
        if (reserva[peliculaId - 1][i] == -1) {
            reserva[peliculaId - 1][i] = clienteId;
            printf("Ticket comprado exitosamente para %s.\n", peliculas[peliculaId - 1][1]);
            return;
        }
    }
    printf("No hay mas espacio para reservas en esta pelicula.\n");
} else {
    printf("Datos invalidos.\n");
}
}

void verCompras(char peliculas[10][4][40], double precio[3], char clientes[5][2][40], int reserva[10][4]) {
int compras = 0;


for (int i = 0; i < 10; i++) {
    int comprasPorPelicula = 0;
    for (int j = 0; j < 4; j++) {
        if (reserva[i][j] != -1) {
            if (comprasPorPelicula == 0) {
                printf("Pelicula: %s\n", peliculas[i][1]);
            }
            int clienteId = reserva[i][j];
            printf("Cliente: %s, Cedula: %s\n", clientes[clienteId][0], clientes[clienteId][1]);
            compras++;
            comprasPorPelicula++;
        }
    }
}

if (compras == 0) {
    printf("No hay compras realizadas.\n");
}
}