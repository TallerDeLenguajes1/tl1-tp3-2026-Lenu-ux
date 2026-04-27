#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct 
{
    int ProductoID;
    int cant;
    char *TipoProducto;
    float PrecioUnitario; //valor aleatorio entre 10 y 100
}typedef Producto;

struct 
{
    int ClienteID;
    char *NombreCliente;
    int CantProductosAPedir;
    Producto *Productos;
} typedef Cliente;
//-------FUNCIONES--------
void cargarDatos(Cliente *c, int cant);
void cargarProductos(Cliente *c);
float calcularCostoTotal(Producto p);
void mostrarTodo(Cliente *c,int cant);
int main(){
    srand(time(NULL));
    int cantClientes;
    do
    {
        printf("Ingrese la cantidad de clientes a cargar: ");
        scanf("%d",&cantClientes);
        
    } while (cantClientes<5);
    
    
    Cliente *clientes;
    clientes=(Cliente *)malloc(sizeof(Cliente)*cantClientes);
    //cargar datos
    cargarDatos(clientes,cantClientes);
    mostrarTodo(clientes,cantClientes);

    //liberar memoria
    for (int i = 0; i < cantClientes; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}
void cargarDatos(Cliente *c, int cant){
    char buff[50];
    //int long;
    for (int i = 0; i < cant; i++)
    {
        //completo el ID del cliente
        c[i].ClienteID=i+1;
        //pido el ingreso del nombre el cliente
        printf("Ingrese el nombre del cliente %d: ",i+1);
        gets(buff);
        fflush(stdin);
       
        c[i].NombreCliente=malloc(strlen(buff)+1);
        strcpy(c[i].NombreCliente,buff);
         //cantidad de productos que pedira el cliente
        printf("\nCantidad de productos a pedir: ");
        scanf("%d",&c[i].CantProductosAPedir);
        fflush(stdin);
        cargarProductos(&c[i]);
    }
    
}

void cargarProductos(Cliente *c){
    c->Productos=(Producto *)malloc(sizeof(Producto)*c->CantProductosAPedir);
    for (int i = 0; i < c->CantProductosAPedir; i++)
    {
        c->Productos[i].ProductoID=i+1;
        c->Productos[i].cant=rand() %10 +1;

        int indiceAleatorio= rand() % 5;
        c->Productos[i].TipoProducto= TiposProductos[indiceAleatorio];

        c->Productos[i].PrecioUnitario= (float)(rand() % 91 +10);
    }
    
}

float calcularCostoTotal(Producto p){
    return p.cant * p.PrecioUnitario;
}

void mostrarTodo(Cliente *c,int cant){
    for (int i = 0; i < cant; i++)
    {
        float totalPagar=0;
        printf("\n------------\n");
        printf("Cliente ID: %d\nNombre:%s\n",c[i].ClienteID,c[i].NombreCliente);
        printf("Productos pedidos:\n");

        for (int j = 0; j < c[i].CantProductosAPedir; j++)
        {
            float subtotal=calcularCostoTotal(c[i].Productos[j]);
            totalPagar +=subtotal;

            printf("ID: %d\tTipo:%s\t Cantidad:%d\t Precio:$%.2f/t Subtotal:$%.2f\n",c[i].Productos[j].ProductoID,c[i].Productos[j].TipoProducto,c[i].Productos[j].cant,c[i].Productos[j].PrecioUnitario,subtotal);

        }
        printf("\nTotal a pagar por cliente: $%.2f",totalPagar);
    }
    
}