#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MostrarPersonas(char *v[],int cant);
int BusarNombrePorPalabra(char *v[],int cant, char *paClave);
void BuscarNombrePorId(int ID,char *v[],int cant);
int main(){
    char buff[50]; //arreglo donde reside temporalmente el nombre
    char *V[5]; // arreglos de 5 elementos

    //pido al usuario los 5 nombres a ingresar
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre:");
        scanf("%s",buff);//temporalmente se almacena en buff
        int tama= strlen(buff); //calculo el tamanio del nombre
        
        //reservo memoria para el tamanio del nombre
        V[i]=(char *)malloc(sizeof(char)* (tama +1));
        strcpy(V[i], buff); //copia lo que esta en el buff al arreglo V
    }
    MostrarPersonas(V,5);
//interfaz para el usuario
    int opcion=0;
    int idBuscar;
    char palabra[50];

    printf("---Menu de Busqueda----\n");
    printf("1.Buscar por ID\n2.Buscar por palabra clave\n Seleccione: ");
    scanf("%d",&opcion);
    switch (opcion)
    {
    case 1:
        printf("Ingrese el ID a buscar: ");
        scanf("%d",&idBuscar);
        BuscarNombrePorId(idBuscar,V,5);
        break;
    case 2:
        getchar();
        printf("Ingrese la palabra clave: ");
        gets(palabra);
        int indice=BusarNombrePorPalabra(V,5,palabra);
        if (indice != -1)
        {
            printf("Coincidencia encontrada: %s (ID:%d)\n",V[indice],indice+1);
        }else
        {
            printf("No hubo coincidencias para %s\n",palabra);
        }
    break;
    default:
        break;
    }
    //liberar memoria
    for (int i = 0; i < 5; i++)
    {
        free(V[i]);
    }
    
    return 0;
}
void MostrarPersonas(char *v[],int cant){
    printf("\n--Lista de Personas---\n");
    for (int i = 0; i < cant; i++)
    {
        printf("%d: %s\n",i+1,v[i]);
    }
    
}
int BusarNombrePorPalabra(char *v[],int cant, char *paClave){
    //recorro el arreglo
    for (int i = 0; i < cant; i++)
    {
        //strstr busca una cadena dentro de otra cadena, devuelve un puntero a la primera posicion donde aparece dentro del texto
        if (strstr(v[i],paClave) != NULL)
        {
            return i;
        }
        
    }
    return -1;
}
void BuscarNombrePorId(int ID,char *v[],int cant){
    int encontrado=0;
    
        if (ID>=0 && ID < cant)
        {
            printf("Id %d: %s\n",ID,v[ID]);

        }else{
            printf("no se encontro el valor buscado\n");
        }
    
}