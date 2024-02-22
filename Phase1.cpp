#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
void BLU(int rs1,int rs2)
{
    
}
class core
{
    int *registers{ new int[32]{} };
    int pc=0;
    string *program=new string[1000];
    vector<string> parts;
    string h;
    void execute()
    {
        stringstream string(program[pc]);
        while(getline(string,h,' '))
        {
            parts.push_back(h);
        }
        if(parts[0]=="ADD")
        {
            int rd=int((parts[1])[1]);
            int rs1=int((parts[2])[1]);
            int rs2=int((parts[3])[1]);
            registers[rd]=registers[rs1]+registers[rs2];
        }
        if(parts[0]=="SUB")
        {
            int rd=int((parts[1])[1]);
            int rs1=int((parts[2])[1]);
            int rs2=int((parts[3])[1]);
            registers[rd]=registers[rs1]-registers[rs2];
        }
    }
};
class memory
{
    int *memory=new int[1024];
};
class processor
{

};