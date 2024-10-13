#include <stdio.h>
#include <windows.h>

#define res_x 45 // resolução em x (min = 45)
#define res_y 30 // resolução em y
#define map_size 5 

char player_char = '#';
char void_char = '.';
char wall_char = '%';

// 0 = nada; 1 = wall; 2 = player
int map[map_size * map_size] = {
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0
};

char buff[res_x * res_y];

void init()
{    

    for(int i=0; i<res_x * res_y; i++){
        buff[i] = void_char;
    }
}

void draw() // função q desenha no buffer, nao mostra na tela apenas coloca a disposição das coisas no buffer
{
    for(int i=0; i<map_size * map_size; i++){
        
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

    display();
    


    return 0;
}