#include <iostream>
using namespace std;

class my_array{
    public:
        int total_size;
        int used_size;
        int *ptr;   // Pointer that points to the first element of the array
        my_array(){}
        my_array(int ts, int us){
            total_size = ts;
            used_size = us;
            ptr = new int[ts];
        }
};

// void create_array(arr *a, int ts, int us){      // creating pointer (*a) that stores the address of the instance object
//     a -> total_size = ts;
//     (*a).used_size = us;
//     int *ptr = new int[us];
// }

int main(){
    my_array marks(20, 8);
    // create_array(&marks, 20, 12);   // passing address of the "marks"
    printf("The total_size of the marks is %d", marks.total_size);
    return 0;
}