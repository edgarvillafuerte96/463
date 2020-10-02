#include "hex.h"
#include "memory.h"
using namespace std;

void usage(){
    cout<<"error in the program"<<endl;
}
int main ( int argc , char ** argv )
{
    if ( argc != 3)
    usage ();

    memory mem ( std :: stoul ( argv [1] , 0 , 16));
    mem.dump ();
    if (! mem.load_file(argv[2]))
    usage();
    mem.dump ();

    std::cout << mem.get_size () << std :: endl ;
    std::cout << hex32 ( mem.get8 (0)) << std :: endl ;
    std::cout << hex32 ( mem.get16 (0)) << std :: endl ;
    std::cout << hex32 ( mem.get32 (0)) << std :: endl ;
    std::cout << hex0x32 ( mem.get8 (0)) << std :: endl ;
    std::cout << hex0x32 ( mem.get16 (0)) << std :: endl ;
    std::cout << hex0x32 ( mem.get32 (0)) << std :: endl ;
    std::cout << hex8 ( mem.get8 (0)) << std :: endl ;
    std::cout << hex8 ( mem.get16 (0)) << std :: endl ;
    std::cout << hex8 ( mem.get32 (0)) << std :: endl ;
    std::cout << hex0x32 ( mem.get32 (0x1000 )) << std :: endl ;

    mem.set8 (0x10 , 0x12 );
    mem.set16 (0x14 , 0x1234 );
    mem.set32 (0x18 , 0x87654321 );
    mem.dump ();

    return 0;
 }
