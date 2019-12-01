#include <iostream>
#include <random>
#include<iomanip>
#define SIZE 10
#define ROUND 100


typedef struct{
    int x;
    int y;
}pos;

class Bug
{
private:
    pos BugPos;
    int size;
    std::default_random_engine e;
public:
    Bug();

    void walk();
    bool OutOfRange() const;
    pos GetPostion() const;
};

Bug::Bug()
{ 
    size = SIZE;
    (*this).BugPos.x = 0;
    (*this).BugPos.y = 0;
}

void Bug::walk()
{
    int temp = e()%4;
    switch(temp){
        case 0:
            (*this).BugPos.x++;
            break;
        case 1:
            (*this).BugPos.y++;
            break;
        case 2:
            (*this).BugPos.x--;
            break;
        case 3:
            (*this).BugPos.y--;
            break;
    }

    if(OutOfRange()){//undo walk
        switch(temp){
            case 0:
                (*this).BugPos.x--;
                break;
            case 1:
                (*this).BugPos.y--;
                break;
            case 2:
                (*this).BugPos.x++;
                break;
            case 3:
                (*this).BugPos.y++;
                break;
        }
        walk();
    }
}

bool Bug::OutOfRange() const
{
    if( BugPos.x > SIZE || BugPos.x < -SIZE || BugPos.y > SIZE || BugPos.y < -SIZE){
        return true;
    }
    return false;
}

pos Bug::GetPostion() const
{
    return BugPos;
}

using namespace std;
int main()
{
    int counter[2*SIZE+1][2*SIZE+1];
    for(int i = 0; i <= 2*SIZE; i++){
        for(int j = 0; j <= 2*SIZE; j++){
            counter[i][j] = 0;
        }
    }

    Bug b0;
    for(int i = 0; i < ROUND; i++){
        b0.walk();
        pos temp = b0.GetPostion();
        cout<< temp.x << "," << temp.y << endl;
        counter[temp.x + SIZE][temp.y + SIZE]++;
    }


    for(int i = 0; i < 2*SIZE; i++){
        for(int j = 0; j< 2*SIZE; j++){
            cout << setw(3) << counter[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
