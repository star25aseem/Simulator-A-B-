#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
class core
{
    public:
    memory m;
    int *registers{ new int[32]{} };
    int pc=1;
    string *program=new string[1000];
    vector<string> parts;

    void execute(int pc)
    {
        int base;
        string h;
        string f;
        stringstream str(program[pc]);
        while(getline(str,h,' '))
        {
            parts.push_back(h);
        }
        if(parts[0]=="base:")
        {
            base=stoi(parts[1]);
        }
        if(parts[0]=="add")
        {
            int rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                rd=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                rs1=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=string(1,parts[2][1]);
                rs1=stoi(f);
            }
            if(parts[3].size()>2)
            {
                f=string(1,parts[3][1])+string(1,parts[3][2]);
                rs2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=string(1,parts[3][1]);
                rs2=stoi(f);
            }
            registers[rd]=registers[rs1]+registers[rs2];
            pc=pc+1;
        }
        if(parts[0]=="sub")
        {
            int rd,rs1,rs2;
            int rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                rd=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                rs1=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=string(1,parts[2][1]);
                rs1=stoi(f);
            }
            if(parts[3].size()>2)
            {
                f=string(1,parts[3][1])+string(1,parts[3][2]);
                rs2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=string(1,parts[3][1]);
                rs2=stoi(f);
            }
            registers[rd]=registers[rs1]-registers[rs2];
            pc=pc+1;
        }
        if(parts[0]=="bne")
        {
            int r1,r2;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=string(1,parts[2][1]);
                r2=stoi(f);
            }
            int y=0;
            if(r1!=r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                        return;
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
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=string(1,parts[2][1]);
                r2=stoi(f);
            }
            int y=0;
            if(r1==r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                        return;
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
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=string(1,parts[2][1]);
                r2=stoi(f);
            }
            int y=0;
            if(r1<r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                        return;
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
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=string(1,parts[2][1]);
                r2=stoi(f);
            }
            int y=0;
            if(r1>=r2)
            {
                while(program[y]==parts[3])
                {
                    y++;
                    if(program[y]==parts[3])
                        pc=y;
                        return;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        if(parts[0]=="lw")
        {
            int x,y;
            string w;
            int offset;
            int r1,r2;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2][2]=='x'||parts[2][3]=='x')
            {
                if(parts[2][2]=='x')
                {
                    f=string(1,parts[2][0]);
                    offset=stoi(f);
                    if(parts[2].size()==5)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(f);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(f);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=string(1,parts[2][0])+string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(f);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(f);                       
                    }
                }
                registers[r1]=m.mem[registers[r2]+offset];
            }
            if(parts[2]=="base")
            {
                registers[r1]=m.mem[base];
            } 
            pc=pc+1;
        }
        if(parts[0]=="sw")
        {
            int x,y;
            string w;
            int offset;
            int r1,r2;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2][2]=='x'||parts[2][3]=='x')
            {
                if(parts[2][2]=='x')
                {
                    f=string(1,parts[2][0]);
                    offset=stoi(f);
                    if(parts[2].size()==5)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(f);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(f);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=string(1,parts[2][0])+string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(f);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(f);                       
                    }
                }   
            }
            m.mem[registers[r2]+offset]=registers[r1];
            pc=pc+1;
        }
        if(parts[0]=="la")
        {
            int x,y;
            string w;
            int offset;
            int r1,r2;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2][2]=='x'||parts[2][3]=='x')
            {
                if(parts[2][2]=='x')
                {
                    f=string(1,parts[2][0]);
                    offset=stoi(f);
                    if(parts[2].size()==5)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(f);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(f);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=string(1,parts[2][0])+string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(f);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(f);                       
                    }
                }
                registers[r1]=registers[r2]+offset;   
            }
            if(parts[2]=="base")
            {
                registers[r1]=base;
            } 
            pc=pc+1;
        }
        if(parts[0]=="addi")
        {
            int rd,rs,int k;
            if(parts[1].size()>2)
            {
                f=string(1,parts[1][1])+string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=string(1,parts[1][1]);
                rd=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=string(1,parts[2][1])+string(1,parts[2][2]);
                rs=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=string(1,parts[2][1]);
                rs=stoi(f);
            }
            k=stoi(parts[3]);
            registers[rd]=registers[rs]+k;
            pc=pc+1;
        }
    }
};
class memory
{
    public:
    int *mem=new int[1024];
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
    }
    infile.close();
}