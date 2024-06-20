#include<iostream>
#include<map>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<string>
#include<variant>
#include <cmath>
#include <cassert>
#include <cstdint>
#include <cmath>
#include<climits>
int Time=0;
struct cacheBlock
{
    uint32_t tag;
    bool valid;
    // Add data field to store the actual data in the cache block
    uint32_t data;
    unsigned int lri;//least recent index
    unsigned int frequency;
    unsigned int score;
    // if(recency!=0){
    //  score=alpha*frequency+beta/recency;
    // }
};
  class Cache{
    private:
    std::vector<cacheBlock>cache;
    std::vector<cacheBlock>recent;   
    //std::vector<std::vector<cacheBlock>> cache;
    unsigned int cacheSize;
    unsigned int blockSize;
    unsigned int numOfBlocks;
    int *data_mem;
    int *Instruction_mem;
    unsigned int hits;
    unsigned int misses;
    unsigned int alpha;//whenenever a loop will come alpha will become 1 and beta becomes 0
    unsigned int beta;
    // pair<uint32_t, uint32_t> splitAdress(uint32_t address)
    // {
    //     int byteOffset = log2(blockSize);
    //     address = address >> byteOffset;
    //     uint32_t index = address & ((1 << numOfBlocks) - 1);
    //     address = address >> ((1 << numOfBlocks) - 1);
    //     uint32_t tag = address;
    //     pair<uint32_t, uint32_t> y = make_pair(index, tag);
    //     return y;
    // }
    public:
    Cache(unsigned int _cacheSize, unsigned int _blockSize,unsigned int _alpha,unsigned int _beta)
        : cacheSize(_cacheSize), blockSize(_blockSize), hits(0), misses(0)
    {
        assert(cacheSize % blockSize == 0);
        numOfBlocks = cacheSize / blockSize;
        cache.resize(numOfBlocks);
        for (auto &u : cache)
        {
            u.valid = false;
            u.lri=numOfBlocks;
        }
    }


void update(int y,int newData)
{
    cache[y].data=newData;
}
void set_data_Memory(int* new_data_Memory) {
    data_mem = new_data_Memory;
}
void set_Inst_Memory(int* new_Inst_Memory){
    Instruction_mem=new_Inst_Memory;
}

 uint32_t data_access(uint32_t address)
    {
        //auto h = splitAdress(address);
        //uint32_t index = h.first;
        //uint32_t tag = h.second;
        for (int i = 0; i < numOfBlocks; i++)
        {
            if (cache[i].tag == address && cache[i].valid)
            {
                // for cache hit
                hits++;
                cache[i].frequency++;
                cache[i].lri=numOfBlocks;
                cache[i].score=alpha*cache[i].frequency+beta*cache[i].lri;
                for (int j = 0; j < numOfBlocks; j++)
                {
                   if (i!=j)
                   {
                       cache[i].lri--;
                       cache[i].score=alpha*cache[i].frequency+beta*cache[i].lri;
                   }
                }
                Time+=1;
                return cache[i].data;
            }
        }
        // Update statistics for cache miss
        misses++;
        for(int i=0;i<numOfBlocks;i++){
            if(!cache[i].valid){
              cache[i].tag = address;
              cache[i].valid = true;
              cache[i].lri = numOfBlocks;
              cache[i].frequency++;
              cache[i].score=alpha*cache[i].frequency+beta*cache[i].lri;
              // Simulate reading data from memory and storing it in the cache block
              cache[i].data = address; // Read from memory array
              Time+=10;
              return cache[i].data;               
            }
        }
        int min_score=INT_MAX;
        int min_index=0;
        for(int i=0;i<numOfBlocks;i++){
            if(cache[i].score<min_score){
                min_score=cache[i].score;
                min_index=i;
            }
        }
        // Replace the min block with the new block
        cache[min_index].tag = address;
        cache[min_index].valid = true;
        cache[min_index].lri = numOfBlocks;
        cache[min_index].frequency++;
        cache[min_index].score=alpha*cache[min_index].frequency+beta*cache[min_index].lri;
        // Simulate reading data from memory and storing it in the cache block
        cache[min_index].data = address; // Read from memory array
        Time+=10;
        return cache[min_index].data;
    }
    uint32_t  Instruction_access(uint32_t address){
        for (int i = 0; i < numOfBlocks; i++)
        {
            if (cache[i].tag ==Instruction_mem [address] && cache[i].valid)
            {
                // for cache hit
                hits++;
                cache[i].frequency++;
                cache[i].lri=numOfBlocks;
                cache[i].score=alpha*cache[i].frequency+beta*cache[i].lri;
                for (int j = 0; j < numOfBlocks; j++)
                {
                   if (i!=j)
                   {
                       cache[i].lri--;
                       cache[i].score=alpha*cache[i].frequency+beta*cache[i].lri;
                   }
                }
                Time+=1;
                return cache[i].data;
            }
        }
        // Update statistics for cache miss
        misses++;
        for(int i=0;i<numOfBlocks;i++){
            if(!cache[i].valid){
              cache[i].tag = Instruction_mem[address];
              cache[i].valid = true;
              cache[i].lri = numOfBlocks;
              cache[i].frequency++;
              cache[i].score=alpha*cache[i].frequency+beta*cache[i].lri;
              // Simulate reading data from memory and storing it in the cache block
              cache[i].data = Instruction_mem[address]; // Read from memory array
              Time+=10;
              return cache[i].data;               
            }
        }
        int min_score=INT_MAX;
        int min_index=0;
        for(int i=0;i<numOfBlocks;i++){
            if(cache[i].score<min_score){
                min_score=cache[i].score;
                min_index=i;
            }
        }
        // Replace the min block with the new block
        cache[min_index].tag = Instruction_mem[address];
        cache[min_index].valid = true;
        cache[min_index].lri = numOfBlocks;
        cache[min_index].frequency++;
        cache[min_index].score=alpha*cache[min_index].frequency+beta*cache[min_index].lri;
        // Simulate reading data from memory and storing it in the cache block
        cache[min_index].data = Instruction_mem[address]; // Read from memory array
        Time+=10;
        return cache[min_index].data;
    }
    

    double hitRate() const
    {
        return static_cast<double>(hits) / (hits + misses);
    }

    double missRate() const
    {
        return static_cast<double>(misses) / (hits + misses);
    }

    unsigned int getHits() const
    {
        return hits;
    }

    unsigned int getMisses() const
    {
        return misses;
    }  
 };
 class Instructions{
    public:
    uint32_t opcode;
    uint32_t Funct7;
    uint32_t Funct3;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t rd;
    uint32_t imm;// for i-type
    uint32_t imm1;// for s-type
    uint32_t imm2;// for s-type
 };
 class core{
    public:
    int *registers =new int[32] ;
    uint32_t pc;
    uint32_t IF(Cache &Instruction_specific,uint32_t pc){
        uint32_t Instruction=Instruction_specific.Instruction_access(pc);
        return Instruction;
    }
    Instructions IDRF(uint32_t Instruction){
        Instructions I;
        uint32_t x=Instruction;
        uint32_t y=x<<25;
        uint32_t z=y>>25;
        I.opcode=z;
        I.Funct7=x>>25;
        y=x<<17;
        z=y>>29;
        I.Funct3=z;
        y=x<<12;
        z=y>>27;
        I.rs1=z;
        y=x<<7;
        z=y>>27;
        I.rs2=z;
        y=x<<20;
        z=y>>27;
        I.rd=z;
        y=x>>20;
        I.imm=y;
        I.imm1=x>>25;
        y=x<<20;
        z=x>>27;
        I.imm2=z;
        return I;
    }
    uint32_t EX(Instructions I){
        if(I.opcode==51 && I.Funct7==0){//ADD
            return registers[I.rs1] + registers[I.rs2];
        }
        else if(I.opcode==51 && I.Funct7==32){//SUB
            return registers[I.rs1] - registers[I.rs2];
        }
        else if(I.opcode==19){//ADDI
            return registers[I.rs1] + I.imm;
        }
        else if(I.opcode==3){//Lw
            return registers[I.rs1] + I.imm;
        }
        else if(I.opcode==35){//SW
            return 0;
        }
    }
    uint32_t MEM(Instructions I,int*data_memory,uint32_t address,Cache &Data_specific){
        if(I.opcode==51 && I.Funct7==0){//ADD
            return address;
        }
        else if(I.opcode==51 && I.Funct7==32){//SUB
            return address;
        }
        else if(I.opcode==19){//ADDI
            return address;
        }
        else if(I.opcode==3){//Lw
         return Data_specific.data_access(registers[I.rs1] + I.imm);
        }
        else if(I.opcode==35){//SW
           // data_memory[registers[I.rs2] +I.imm1]=registers[I.rs1];
            return 0;
        }
    }
    void WB(uint32_t data,Instructions I){
     registers[I.rd] =data;
    }
    void pipeline(int *Instruction_memory,int* data_memory,Cache &Instruction_specific,Cache &Data_specific){
        int *x=Instruction_memory;
        while(*(x)!=0){
            uint32_t Instruction=IF(Instruction_specific,pc);
            pc++;
            x++;
            Instructions I=IDRF(Instruction);
            uint32_t data = EX(I);
            data=MEM(I,data_memory,data,Data_specific);
            WB(data,I);
        }
        std::cout<<"Time:"<<Time<<std::endl;
    }
};
class Processor{
  public: 
    int *data_memory = new int[1024]();
    int *Instruction_memory =new int[1024]();
 // static vector<int> data_memory(1024,0);
  //static vector<int>Instruction_memory(1024,0);

   core core1;
   std::vector<std::string> Instructions;
   std::vector<std::uint32_t> Binary_Instructions;
   void runprogram(){
        static Cache Data_specific(128,16,0.5,0.5);
        Data_specific.set_data_Memory(data_memory);
        static Cache Instruction_specific(128,16,0.5,0.5);
        Instruction_specific.set_Inst_Memory(Instruction_memory);
        std::string filename;
        std::cout << "enter file name:";
        std::getline(std::cin, filename);
        std::ifstream infile(filename);
        if (!infile.is_open())
        {
            std::cout << "err" << std::endl;
            return;
        }
        std::string o;
        while(getline(infile, o))
        {
            Instructions.push_back(o);
        }
        for(std::string str : Instructions){
           // std::vector<std::uint32_t> Binary_Instructions;
          uint32_t value =strtoul(str.c_str(),NULL,2);
          Binary_Instructions.push_back(value);
        }
       // std::cout<<Binary_Instructions[0]<<std::endl;
        int*x=Instruction_memory;
        for(int i=0;i<Binary_Instructions.size();i++){
            *(x)=Binary_Instructions[i];
            x++;
        }
        infile.close();
        int k = 0;
        core1.pc = 0;
        core1.pipeline(Instruction_memory,data_memory,Instruction_specific,Data_specific);
        std::cout << std::endl;
        int y = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                std::cout << core1.registers[y] << " ";
                y++;
            }
            std::cout << std::endl;
        }
        int u = 0;
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                std::cout << data_memory[u] << " ";
                u++;
            }
            std::cout << std::endl;
        }
        Binary_Instructions.clear();
        std::cout << std::endl;

    }
};
int main(){
 Processor p;
 p.runprogram();
}