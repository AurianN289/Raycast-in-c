#include <stdio.h>
#include <windows.h>
#include <string.h>


#define res_x 45 // resolução em x
#define res_y 30 // resolução em y
#define map_size 5

  
char player_char = '#';
char void_char = '.';
char wall_char = '%';


// 0 = nada; 1 = wall; 2 = player
int map[map_size * map_size] = {
0,0,0,0,0,
0,0,0,0,0,
0,0,0,1,0,
0,2,0,0,0,
0,0,0,0,0
};

char buff[res_x * res_y];
int tam_x_bloco, tam_y_bloco;

int t = 0;

void init()
{
    tam_x_bloco = res_x/map_size;
    tam_y_bloco = res_y/map_size;
  
    // preenche tudo de vazio
    for(int i=0; i<res_x * res_y; i++){
        buff[i] = void_char;
    }
  
    //desenha as bordas
    for(int i=0; i<res_x * res_y; i++){
        if(i<res_x){
            buff[i] = wall_char;
        }

        if( i%res_x == 0 || i%res_x == res_x-1 ){
            buff[i] = wall_char;
        }

        if(i/res_x >= res_y-1){
            buff[i] = wall_char;
        } 
    }
}

  

void draw() // função q desenha no buffer, nao mostra na tela apenas coloca a disposição das coisas no buffer
{
    if(t >= 100){
        buff[ t%100 + 5 ] = player_char;
        buff[ (t-1)%100 + 5 ] = void_char;
    }
}

  
void display() // função q de fato desenha as coisas na tela com cor e tudo mais, usa muito a biblioteca windows.h
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE); // manipulador da janela do console
    DWORD written; // flag
    WriteConsole(hand, buff, res_x * res_y, &written, NULL); // escreve o conteúdo de buff[]
}
  

int main(){ 
    init();

    while(1){
        display();
        Sleep(1); // 1 milissegundo
        t++;
    }

    return 0;
}