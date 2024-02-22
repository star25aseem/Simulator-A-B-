#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class core
{
    public:
    memory m;
    int *registers{ new int[32]{} };
    int pc=1;
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
        if(parts[0]=="add")
        {
                        int rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                rd=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                rd=int((parts[1])[1]);
            }
            if(parts[2].size()>2)
            {
                rs1=int((parts[2])[1]+parts[2][2]);
            }
            if(parts[2].size()==2)
            {
                rs1=int((parts[2])[1]);
            }
            if(parts[3].size()>2)
            {
                rs2=int((parts[3])[1]+parts[3][2]);
            }
            if(parts[3].size()==2)
            {
                rs2=int((parts[3])[1]);
            }
            registers[rd]=registers[rs1]+registers[rs2];
            pc=pc+1;
        }
        if(parts[0]=="sub")
        {
            int rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                rd=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                rd=int((parts[1])[1]);
            }
            if(parts[2].size()>2)
            {
                rs1=int((parts[2])[1]+parts[2][2]);
            }
            if(parts[2].size()==2)
            {
                rs1=int((parts[2])[1]);
            }
            if(parts[3].size()>2)
            {
                rs2=int((parts[3])[1]+parts[3][2]);
            }
            if(parts[3].size()==2)
            {
                rs2=int((parts[3])[1]);
            }
            registers[rd]=registers[rs1]-registers[rs2];
            pc=pc+1;
        }
        if(parts[0]=="bne")
        {
            int r1,r2;
            if(parts[1].size()>2)
            {
                r1=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                r1=int((parts[1])[1]);
            }
            if(parts[2].size()>2)
            {
                r2=int((parts[2])[1]+parts[2][2]);
            }
            if(parts[2].size()==2)
            {
                r2=int((parts[2])[1]);
            }
            int y=0;
            if(r1!=r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        if(parts[0]=="beq")
        {
            int r1,r2;
            if(parts[1].size()>2)
            {
                r1=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                r1=int((parts[1])[1]);
            }
            if(parts[2].size()>2)
            {
                r2=int((parts[2])[1]+parts[2][2]);
            }
            if(parts[2].size()==2)
            {
                r2=int((parts[2])[1]);
            }
            int y=0;
            if(r1==r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        if(parts[0]=="blt")
        {
            int r1,r2;
            if(parts[1].size()>2)
            {
                r1=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                r1=int((parts[1])[1]);
            }
            if(parts[2].size()>2)
            {
                r2=int((parts[2])[1]+parts[2][2]);
            }
            if(parts[2].size()==2)
            {
                r2=int((parts[2])[1]);
            }
            int y=0;
            if(r1<r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        if(parts[0]=="bgt")
        {
            int r1,r2;
            if(parts[1].size()>2)
            {
                r1=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                r1=int((parts[1])[1]);
            }
            if(parts[2].size()>2)
            {
                r2=int((parts[2])[1]+parts[2][2]);
            }
            if(parts[2].size()==2)
            {
                r2=int((parts[2])[1]);
            }
            int y=0;
            if(r1>=r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        if(parts[0]=="lw")
        {
            if(parts[1].size()>2)
            {
                int r1=int((parts[1])[1]+parts[1][2]);
            }
            if(parts[1].size()==2)
            {
                int r1=int((parts[1])[1]);
            }

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
int main()
{
    int pc=0;
    core c1,c2;
    string filename;
    cout<<"enter file name";
    getline(cin,filename);
    ifstream infile(filename);
    if(!infile.is_open())
    {
        cout<<"err"<<endl;
    }
    string l;
    while(getline(infile,l))
    {
        c1.program[pc]=l;
        pc=pc+1;
    }
}