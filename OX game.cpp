#include<iostream>
#include<ctime>

void board(char *spaces);
void playermove(char *spaces, char player);
void compmove(char *spaces, char comp);
bool checkwinner(char*spaces, char comp, char player);
bool checktie(char*spaces);

int main(){
char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char player = 'X';
char comp = 'O';
bool running = true;

 board(spaces);

 while(running){
    playermove(spaces, player);
    board(spaces);
    if(checkwinner(spaces, comp, player)){
        std::cout<<"Thank you for Playing!"<<'\n';
        running = false;
        break;
    }else if(checktie(spaces)){
        std::cout<<"Thank you for Playing!"<<'\n';
        running = false;
        break;
    }
    
    compmove(spaces, comp);
    board(spaces);
    if(checkwinner(spaces, comp, player)){
        running = false;
        std::cout<<"Thank you for Playing!"<<'\n';
        break;
    }else if(checktie(spaces)){
        running = false;
        std::cout<<"Thank you for Playing!"<<'\n';
        break;
    }
 }

return 0;
}

void board(char *spaces){

    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<'\n';
    std::cout<<"     |     |     "<<'\n'<<'\n'<<'\n';
}

void playermove(char *spaces, char player){
    int number;
    do{
        std::cout<<"Choose a box (1-9): ";
        std::cin>>number;
        number--;   
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    }while(number>0 || number<8);

}

void compmove(char *spaces, char comp){ 
    srand(time(0));
    int number = 0;
    do{
        number = rand() % 9;
    }while(spaces[number] != ' ');

    spaces[number] = comp;
}

bool checkwinner(char*spaces, char comp, char player){
    if(spaces[0] != ' ' && spaces[0]==spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[3] != ' ' && spaces[3]==spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[6] != ' ' && spaces[6]==spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[0] != ' ' && spaces[0]==spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[1] != ' ' && spaces[1]==spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[2] != ' ' && spaces[2]==spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[0] != ' ' && spaces[0]==spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else if(spaces[2] != ' ' && spaces[2]==spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? std::cout<<"You Win!\n" : std::cout<<"You lose!\n";
    }else{
        return false;
    }

    return true;
}

bool checktie(char*spaces){
    for(int i = 0; i<9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    
    std::cout << "IT'S A TIE!\n";
    return true;
}

