    #include "memory.h"
    #include "hex.h"
    #include <fstream>
    
/***************************************************************
memory
Use: This function will return a std::string with exactly 2 hex digits representing the 8 bits of
the i argument.
Parameters: uint32_t size
Returns: nothing.. this is a constructor
*************************************************************/ 
    memory::memory ( uint32_t siz ){
        siz = (siz+15)&0xfffffff0; // round the length up, mod-16
        size=siz;
            mem = new uint8_t[siz];
    
    for(uint32_t i = 0; i < siz; i++) {
        mem[i] = 0xa5;

    }
    }

/***************************************************************
destructor
Use: delete the memory allocated in mem
Parameters: none
Returns: none
*************************************************************/ 
    memory::~ memory (){
        delete []mem;
    }

/***************************************************************
check_address
Use: Return true if the given address is in your simulated memory. If the given address is not in
your simulated memory then print a warning message 
Parameters: uint8_t i 
Returns: bool
*************************************************************/ 
    bool memory::check_address ( uint32_t i ) const {
        

        if(i >memory::size){
            cout<<"WARNING: Address out of range: "<<hex0x32(i)<<endl;
            return false;
        }
        else{
            return true;
        }

    }

/***************************************************************
get_size
Use: Return the siz value
Parameters: none
Returns: uint32_t size
*************************************************************/ 
    uint32_t memory::get_size () const {
        return size;
    }

    /***************************************************************
    get8
    Use: Check to see if the given addr is in your mem by calling check_address(). If addr is in the
    valid range, return the value of the byte from your simulated memory at that address. If
    addr is not in the valid range then return zero to the caller.
    Parameters: uint8_t address
    Returns: uint8_t value
    *************************************************************/ 
    uint8_t memory::get8 ( uint32_t addr ) const {
        if(check_address(addr)){
            return mem[addr];
        }
        else
        return 0;
    }
    /***************************************************************
    get16
    Use: This function must call your get8() function twice to get two bytes and then combine them
    in little-endian order to create a 16-bit return value
    Parameters: uint32_t addr
    Returns: uint32_t
    *************************************************************/ 
    uint16_t memory::get16 ( uint32_t addr ) const {
        //get a return on the first 8 bites then shift and get a return from that
        return get8(addr+1) << 8 | get8(addr);
    }
    /***************************************************************
    get32
    Use: This function must call your get16() function twice to get two bytes and then combine them
    in little-endian order to create a 16-bit return value
    Parameters: uint32_t addr
    Returns: uint32_t
    *************************************************************/ 
    uint32_t memory::get32 ( uint32_t addr ) const {
        return get16(addr+2) << 16 | get16(addr);
    }
    /***************************************************************
    set8
    Use: Check to see if the given addr is in your mem by calling check_address(). If addr is in the
    valid range, return the value of the byte from your simulated memory at that address. If
    addr is not in the valid range then return zero to the caller
    Parameters: uint32_t addr and uint32_t val
    Returns: none void
    *************************************************************/ 
    void memory::set8 ( uint32_t addr , uint8_t val ){
        if (check_address(addr)){
            mem[addr] = val;
        }
        else
        return ;
    }
    /***************************************************************
    set16
    Use: Check to see if the given addr is in your mem by calling check_address(). If addr is in the
    valid range, return the value of the byte from your simulated memory at that address. If
    addr is not in the valid range then return zero to the caller
    Parameters: uint32_t addr and uint32_t val
    Returns: none void
    *************************************************************/ 
    void memory::set16 ( uint32_t addr , uint16_t val ){
        set8(addr,val & 0x0ff);
        set8(addr+1,val >> 8);
    }
    /***************************************************************
    set32
    Use: Check to see if the given addr is in your mem by calling check_address(). If addr is in the
    valid range, return the value of the byte from your simulated memory at that address. If
    addr is not in the valid range then return zero to the caller
    Parameters: uint32_t addr and uint32_t val
    Returns: none void
    *************************************************************/ 
    void memory::set32 ( uint32_t addr , uint32_t val ){
        set16(addr,val & 0x0ffff);
        set16(addr+2,val >> 16);
    }
    /***************************************************************
    dump
    Use: Dump the entire contents of your simulated memory in hex with ASCII on the right exactly,
    space-for-space
    Parameters: none
    Returns: none void
    *************************************************************/ 
    void memory::dump () const {
        char ascii[16]={};
        for (uint32_t i = 0; i < size; i++){
            uint8_t ch = get8(i);
            ascii[i%16] = isprint(ch) ? ch : '.';
           // printf("%02x",mem[i]);
            cout<<hex8(get8(i))<<" ";
            if((i%16==0) and (i !=0))
            cout<<" "<<ascii<<endl;
            
        }
    }
    /***************************************************************
    load_file
    Use: Open the file named fname in binary mode and read its contents into your simulated memory
    Parameters: file name
    Returns: bool
    *************************************************************/ 
    bool memory::load_file ( const std :: string & fname ){
        std::ifstream infile(fname, std::ios::in|std::ios::binary);
        if(!infile.is_open()){
            cerr<<"Can not open the file "<<fname<<endl;
            return false;
        }
        int i = 0 ;
        char c;
        while(infile>>noskipws>>c){
            if(check_address(c)){
            mem[i] = c;
            i++;
            }
            else if (!check_address(c)){
                cerr<<"Program too big"<<endl;
                return false;
            }
        }      
        infile.close();
        return true; 
}
