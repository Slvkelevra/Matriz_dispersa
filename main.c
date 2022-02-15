#include <stdio.h>
#include <stdlib.h>

#define NUMC 15
#define NUMR 10

int numUsedIntegerClassic;
int numUsedIntegerSparse;

//Estructura de matriz sparsa
typedef struct {
    
    int riga;
    int colonne;
    int valore;
    
}Linea;


//******************************************************************************
//                      FUNCION fill_classic_matrix
//Formacion de matriz clasica con datos predefinidos

void fill_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    matrix[1][0] = 71;
    matrix[2][14] = 99;
    matrix[3][11] = 53;
    matrix[4][7] = 95;
    matrix[6][14] = 39;
    matrix[8][1] = 27;
    matrix[9][14] = 14;
}




//******************************************************************************
//                      FUNCION print_classic_matrix
//Imprime por pantalla la matriz clasica

void print_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
}



//******************************************************************************
//                      FUNCION search_element_in_classic_matrix
//Busca un elemento en la matriz clasica y devuelve por pantalla la posicion del
//elemento encontrado.En caso de no encontrarlo,devuelve Elemento non trovato

void search_element_in_classic_matrix(int matrix[][NUMC], int numr, 
        int numc, int numric)
{
    int i, j = 0;
    //Recorre filas
    for(i=0; i<numr; i++)
    {
        //Recorre columnas
        for(j=0; j<numc; j++)
        {
            //Si lo encuentra,imprime el numero,i(numero fila)y j(num.fila)
            if(matrix[i][j] == numric)
            {
                printf("Elemento %d trovato in posizione (%d, %d).\n", numric, i, j);
                return;
            }
        }
    }
    printf("Elemento non trovato.\n");
}



//******************************************************************************
//                          FUNCION MATRIX_SPARSE
//Crea una matriz sparsa.Se trata de una columna con esta estructura:
//                 ----------------------------------
//                 | num_fila | num col. | num_elem |
//                 |          |          |          |
//                 |          |          |          |
//                 |          |          |          |
//                 |          |          |          |
//                 |          |          |          |
//                 |          |          |          |
//                 |          |          |          |
//                 ----------------------------------
//Devuelve un puntero a la primera posicion de memoria de la matriz esparsa 
//alocada en memoria

Linea* create_matrix(int riga,int colonna,int num_elem){
    
    //Aloca la matriz en memoria
    Linea *matrix_sparse = (Linea*)malloc(sizeof(Linea)*(num_elem+1));
    
    matrix_sparse[0].riga=riga;
    matrix_sparse[0].colonne=colonna;
    matrix_sparse[0].valore=num_elem;
    
    int i;
    //toma de datos de la matriz esparsa por teclado
    for(i=1;i<=matrix_sparse[0].valore;i++){
        
        scanf("%d",&riga);
        scanf("%d",&colonna);
        scanf("%d",&num_elem);
        
        matrix_sparse[i].riga=riga;
        matrix_sparse[i].colonne=colonna;
        matrix_sparse[i].valore=num_elem;
        printf("los elementos del primer struct son %d %d %d\n",riga,colonna,
                num_elem);
        
    }
    
    return matrix_sparse;
    
}


//******************************************************************************
//                      FUNCION search_element_in_matrix_sparse
//Busca un elemento en la matriz esparsa.Devuelve un puntero de array creado 
//donde se guarda el elemento con sus datos

Linea *search_element_in_matrix_sparse(Linea *mi_matrix,int elem_ric){
    
    //Alocamos el vector en memoria con los datos del elemento encontrado
    Linea *elem_trovato=(Linea*)malloc(sizeof(Linea)*(1));
    int i;
    elem_trovato[0].colonne=elem_trovato[0].riga=elem_trovato[0].valore=0;
    //Recorremos toda la matriz(que en realidad es un vector
    for(i=1;i<mi_matrix[0].valore;i++){
        //SI encontramos el valor,guardamos en elem_trovato la columna donde 
        //lo hemos encontrado,la fila y el elemento
        if(mi_matrix[i].valore==elem_ric){
            elem_trovato[0].riga=mi_matrix[i].riga;
            elem_trovato[0].colonne=mi_matrix[i].colonne;
            elem_trovato[0].valore=mi_matrix[i].valore;
        }
    }
    return elem_trovato;
    
}


//******************************************************************************
//                      FUNCION print_matrix_sparse
//Imprime una patrix esparsa por pantalla

void print_matrix_sparse(Linea *matrix_sparse){
    
    int i,j;
    int cont=1;
    //Recorre la matriz esparsa
    for(i=0;i<=matrix_sparse[0].riga;i++){
        for(j=0;j<matrix_sparse[0].colonne;j++){
            //Si los elementos de la columna y de la fila no son nulos
            if(matrix_sparse[cont].riga==i && matrix_sparse[cont].colonne==j){
                printf("%d\t",matrix_sparse[cont].valore);
                cont++;
            }else{
                printf("0\t");
            }
        }
        printf("\n");
        
    }
}



int main()
{
    int matrix[NUMR][NUMC] = {{0}};
    int numric;     //Numero a buscar
    printf("Insertar el numero de filas,columnas y numero de elementos no"
            "nulos:\n");
    int riga,colonna,num_elem;
    scanf("%d %d %d",&riga,&colonna,&num_elem);
    printf("Insertar numero a encontrar: ");
    scanf("%d",&numric);
    
    Linea *mi_matrix=create_matrix(riga,colonna,num_elem);
    print_matrix_sparse(mi_matrix);
    Linea *elem_trovato=search_element_in_matrix_sparse(mi_matrix,numric);
    
    //Imprime la posicion del numero a encontrar si se ha encontrado
    if(elem_trovato->valore==0){
        printf("No se ha encontrado el numero");
    }else{
        printf("El elemento buscado se ha encontrado "
                "en las posiciones  %d %d",elem_trovato->riga,
                elem_trovato->colonne);
    }
    
    // INICIO TEST MATRIZ CLASICA
    
    fill_classic_matrix(matrix, NUMR, NUMC);
    printf("\n");
    print_classic_matrix(matrix, NUMR, NUMC);
    search_element_in_classic_matrix(matrix, NUMR, NUMC, numric);
    
    // FIN TEST MATRIZ CLASICA

    return 0;
}
