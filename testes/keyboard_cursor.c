#include <stdio.h>
#include <windows.h>
  

int main(){
    int x=0, y=0;
  
    while(1){
        if (GetKeyState(0x41) & 0x8000) { // A
            x--;
        }
        if (GetKeyState(0x44) & 0x8000) { // D
            x++;
        }
        if (GetKeyState(0x57) & 0x8000) { // W
            y++;
        }
        if (GetKeyState(0x53) & 0x8000) { // S
            y--;
        }
        if (GetKeyState(VK_ESCAPE) & 0x8000) break; // sair do jogo
        printf("player: ( %d , %d )", x,y);
  
  
        POINT point;
        GetCursorPos(&point);
        printf("posicao mouse: ( %d , %d )", point.x, point.y);
  
  
        system("cls");  
    }

  return 0;
}