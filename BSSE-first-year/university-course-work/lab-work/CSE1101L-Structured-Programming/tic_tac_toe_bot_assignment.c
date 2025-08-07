#include <stdio.h>
// To play the game just type which grid to place your mark on!
/* tic tac toe grid function takes in  a-i as our grid is
a b c
d e f
g h i
it returns 1 if player wins or 0 if player loses or 2 if its a draw or 3 if game hasnt ended
player is always O and bot is always X */
int tic_tac_toe_grid(char a, char b, char c, char d, char e, char f, char g, char h, char i){
    printf("\n");
    printf("%c  %c  %c  \n", a,b,c);
    printf("%c  %c  %c  \n", d,e,f);
    printf("%c  %c  %c  \n", g,h,i);
    printf("\n");
    if ( (d==e && e==f)  || (b==e && e==h) || (a==e && e==i) || (c==e && e==g) ){
        if (e=='O'){
            return 1;
        }
        else if(e=='X'){
            return 0;
        }
    }
    else if((b==a && a==c) || (d==a && a==g) ){
        if (a=='O'){
            return 1;
        }
        else if(a=='X'){
            return 0;
        }
    }
    else if((g==i && i==h) || (c==i && i==f)){
        if (i=='O'){
            return 1;
        }
        else if(i=='X'){
            return 0;
        }
    }
    else if(a != 'a' && b != 'b' && c != 'c' && d != 'd' && e != 'e' && f != 'f' && g != 'g' && h != 'h' && i != 'i'){
        return 2;
    }
    else { return 3;}
}

int main(){
    char a = 'a';char b = 'b';char c = 'c';char d = 'd';char e = 'e';char f = 'f';char g = 'g';char h = 'h';char i = 'i';
    int p1;
    int game = 3;
    char move;
    int moves = 0;
    printf("Do you want to go first? Type 1 if yes or 0 if no \n");
    scanf("%d", &p1);
    if (p1==0){
            a='X';
            game= tic_tac_toe_grid(a,b,c,d,e,f,g,h,i);
            moves++;
        }
    for (moves;moves<5;moves++){
        
        if (game == 3){            
            printf("Select your grid \n");
            game = tic_tac_toe_grid(a,b,c,d,e,f,g,h,i);

            scanf(" %c", &move);

            if (move == 'a' && a=='a'){
                a='O';
            }
            else if (move == 'b' && b=='b'){
                b='O';
            }
            else if (move == 'c' && c=='c'){
                c='O';
            }
            else if (move == 'd'  && d=='d'){
                d='O';
            }
            else if (move == 'e'  && e=='e'){
                e='O';
            }
            else if (move == 'f'  && f=='f'){
                f='O';
            }
            else if (move == 'g' && g =='g'){
                g='O';
            }
            else if (move == 'h' && h=='h'){
                h='O';
            }
            else if (move == 'i' && i=='i'){
                i='O';
            }
            else{
                printf("please select a proper move.");
                return 0;
            }

            // Algorithm of bot moves 
            if (e=='e'){
                e='X';
            }
            else if ((a==d || h==i || c==e) && g=='g'){
                g='X';
            }
            else if((a==b || i==f || e==g) && c=='c'){
                c='X';
            }
            else if ((g==d || b==c || e==i) && a=='a'){
                a='X';
            }
            else if((c==f || g== h || a==e) && i=='i'){
                i='X';
            }
            else if((e == f || a==g) && d=='d'){
                d='X';
            }
            else if((e==d || c==i) && f=='f'){
                f='X';
            }
            else if((e==b || g==i) && h=='h'){
                h='X';
            }
            else if((e==h || a==c) && b=='b'){
                b='X';
            }
            else if(c=='c'){
                c='X';
            }
            else if(g=='g'){
                g='X';
            }
            else if(i=='i'){
                i='X';
            }
            else if(a=='a'){
                a='X';
            }
            else if(h=='h'){
                h='X';
            }
            else if(b=='b'){
                b='X';
            }
            else if(d=='d'){
                d='X';
            }
            else if(f=='f'){
                f='X';
            }
            game= tic_tac_toe_grid(a,b,c,d,e,f,g,h,i);
        }
    }
    if (game ==0){
    printf("\n BOT Wins \n");
    return 0;
    }
    else if (game == 1){
        printf("\n Player Wins \n");
        return 0;
    }
    else if (game == 2){
        printf("\n Draw! \n");
        return 0;
    }
  return 0;
}
