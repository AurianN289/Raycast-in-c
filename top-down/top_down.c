#include <stdio.h>
#include <windows.h>

#define res_x 45 // resolução em x (min = 45)
#define res_y 30 // resolução em y
#define map_size 5 

char player_char = '#';
char void_char = '.';
char wall_char = '%';

int block_width;
int block_height;

// 0 = nada; 1 = wall; 2 = player
int map[map_size * map_size] = {
0,0,0,0,0,
0,0,0,0,0,
0,0,1,0,0,
0,0,0,0,0,
0,0,0,0,0
};

char buff[res_x * res_y];

void init()
{    
    for(int i=0; i<res_x * res_y; i++){
        buff[i] = '-';
    }

    block_width = (int) res_x / map_size;
    block_height = (int) res_y / map_size;
}

void draw() // função q desenha no buffer, nao mostra na tela apenas coloca a disposição das coisas no buffer
{
    char fillchar;
    for(int i=0; i<map_size; i++){
        for(int j=0; j<map_size; j++){
            int aux = map[i * map_size + j];
            if(aux == 0){
                fillchar = void_char;
            }
            if(aux == 1){
                fillchar = wall_char;
            }

            for (int y = i * block_height; y < (i + 1) * block_height; y++) {
                for (int x = j * block_width; x < (j + 1) * block_width; x++) {
                    buff[y * res_x + x] = fillchar;
                }
            }
        }
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
    draw();
    display();
    


    return 0;
}