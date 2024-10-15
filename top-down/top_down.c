#include <stdio.h>
#include <windows.h>

#define res_x 45 // resolução em x (min = 45)
#define res_y 30 // resolução em y
#define map_size 5 

int main_loop = 1;

char player_char = '*';
char void_char = '.';
char wall_char = '%';

int block_width;
int block_height;

int player_x_map;
int player_y_map;

int player_x_buff;
int player_y_buff;

int x_speed_smoother = 0;
int y_speed_smoother = 0;
int speed_smoother = 500;



// 0 = nada; 1 = wall; 2 = player
int map[map_size * map_size] = {
0,0,0,0,0,
0,2,0,1,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0
};

char buff[res_x * res_y];

void init()
{    
    system("cls"); 
    for(int i=0; i<res_x * res_y; i++){
        buff[i] = void_char;
    }

    for(int i=0; i<map_size * map_size; i++){
        if(map[i] == 2){
            player_x_map = i % map_size;
            player_y_map = i / map_size;
        }
    }

    block_width = (int) res_x / map_size;
    block_height = (int) res_y / map_size;

    player_x_buff = block_width * player_x_map;
    player_y_buff = block_height * player_y_map;
        
}

void draw() // função q desenha no buffer, nao mostra na tela apenas coloca a disposição das coisas no buffer
{
    char fillchar;
    for(int i=0; i<map_size; i++){
        for(int j=0; j<map_size; j++){
            int aux = map[i * map_size + j];

            if(aux == 0){
                fillchar = void_char;
            }else if(aux == 1){
                fillchar = wall_char;
            }

            for (int y = i * block_height; y < (i + 1) * block_height; y++) {
                for (int x = j * block_width; x < (j + 1) * block_width; x++) {
                    buff[y * res_x + x] = fillchar;
                }
            }
        }
    }

    buff[ player_y_buff*res_x + player_x_buff ] = player_char;

}

void display() // função q de fato desenha as coisas na tela com cor e tudo mais, usa muito a biblioteca windows.h
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE); // manipulador da janela do console
    DWORD written; // flag
    WriteConsole(hand, buff, res_x * res_y, &written, NULL); // escreve o conteúdo de buff[]
}

void keyboard(){ // controla o teclado e a movimentação

    if (GetKeyState(0x41) & 0x8000) { // A
        x_speed_smoother--;
    }
    if (GetKeyState(0x44) & 0x8000) { // D
        x_speed_smoother++;
    }
    if (GetKeyState(0x57) & 0x8000) { // W
        y_speed_smoother--;
    }
    if (GetKeyState(0x53) & 0x8000) { // S
        y_speed_smoother++;
    }
    if (GetKeyState(VK_ESCAPE) & 0x8000) main_loop = 0;; // sair do jogo


    if(x_speed_smoother > speed_smoother){
        x_speed_smoother = 0;
        player_x_buff++;
    }
    if(x_speed_smoother < speed_smoother*-1){
        x_speed_smoother = 0;
        player_x_buff--;
    }

    if(y_speed_smoother < speed_smoother*-1){
        y_speed_smoother = 0;
        player_y_buff--;
    }
    if(y_speed_smoother > speed_smoother){
        y_speed_smoother = 0;
        player_y_buff++;
    }
}

int main(){
    init();

    while(main_loop){
        keyboard();
        draw();
        display();
        Sleep(0.5);
        if (GetKeyState(VK_ESCAPE) & 0x8000) break;
    }
    
    system("cls");
    printf("map x: %d; map y: %d; buff x: %d; buff y: %d\n", player_x_map, player_y_map, player_x_buff, player_y_buff);
    printf("block x: %d; block y: %d", block_width, block_height);

    return 0;
}