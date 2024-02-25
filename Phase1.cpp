#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
class core
{
    public:
    int *registers{ new int[32]{} };
    int pc;
    string l;
    int base;
    string h;
    string f;
    vector<int> word;
    map<int,string> m;

    void execute(string b,int *mem)
    {
        vector<string> parts;
        
        stringstream str(b);
        while(getline(str,h,' '))
        {
            parts.push_back(h);
        }
        if(parts[0]=="base:")
        {
            base=stoi(parts[1]);
            for(int i=0;i<word.size();i++)
            {
                mem[base+i]=word[i];
            }
            pc=pc+1;
        }
        else if(parts[0]=="add")
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
        else if(parts[0]=="sub")
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
            registers[rd]=registers[rs1]-registers[rs2];
            pc=pc+1;
        }
        else if(parts[0]=="addi")
        {
            int rd,rs,k;
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
        else if(parts[0]=="bne")
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
            if(registers[r1]!=registers[r2])
            {
                while(m[y]!=parts[3])
                {
                    y++;
                }
                if(m[y]==parts[3])
                {
                    pc=y+1;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        else if(parts[0]=="beq")
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
            if(registers[r1]==registers[r2])
            {
                while(m[y]!=parts[3])
                {
                    y++;
                }
                if(m[y]==parts[3])
                {
                    pc=y+1;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        else if(parts[0]=="blt")
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
            if(registers[r1]<=registers[r2])
            {
                while(m[y]!=parts[3])
                {
                    y++;
                }
                if(m[y]==parts[3])
                {
                    pc=y+1;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        else if(parts[0]=="bgt")
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
            if(registers[r1]!=registers[r2])
            {
                while(m[y]!=parts[3])
                {
                    y++;
                }
                if(m[y]==parts[3])
                {
                    pc=y+1;
                }
            }
            else
            {
                pc=pc+1;
            }
        }
        else if(parts[0]=="j")
        {
            int y=0;
                while(m[y]!=parts[1])
                {
                    y++;
                }
                if(m[y]==parts[1])
                {
                    pc=y+1;
                }
        }
        else if(parts[0]=="lw")
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
                        w=string(1,parts[2][3]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][3])+string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=string(1,parts[2][0])+string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(w);                       
                    }
                }
                registers[r1]=mem[registers[r2]+offset];
            }
            if(parts[2]=="base")
            {
                registers[r1]= base;
            } 
            pc=pc+1;
        }
        else if(parts[0]=="sw")
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
                if(parts[2][2]=='x')
                {
                    f=string(1,parts[2][0]);
                    offset=stoi(f);
                    if(parts[2].size()==5)
                    {
                        w=string(1,parts[2][3]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][3])+string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=string(1,parts[2][0])+string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=string(1,parts[2][4])+string(1,parts[2][5]);
                        r2=stoi(w);                       
                    }
                }   
            mem[registers[r2]+offset]=registers[r1];
            pc=pc+1;
        }
        else if(parts[0]==".word")
        {
            for(int i=1;i<=parts.size()-1;i++)
            {
                word.push_back(stoi(parts[i]));
            }
            pc=pc+1;
        }
        else if(parts[0]==".data")
        {
            pc=pc+1;
        }
        else if(parts[0]==".text")
        {
            pc=pc+1;
        }
        else
        {
            pc++;
        }
    }
};
class processor
{
public:
    core core1;
    core core2;
    int *memory1=new int[1024]();
    int *memory2=new int[1024]();
    map<int,string> m;
    vector<string> v;
    int pc=1;
    void runprogramCore1()
    {
        string filename;
        cout<<"enter file name:";
        getline(cin,filename);
        ifstream infile(filename);
        if(!infile.is_open())
        {
            cout<<"err"<<endl;
        }
        string o;
        while(getline(infile,o))
        {
            v.push_back(o);
        }
        checkingcore1();
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
        infile.close();
        int k=0;
        core1.pc=0;
        while(k!=v.size())
        {
            core1.execute(v.at(k),&(*memory1));
            k=core1.pc;
        }
        int y=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<16;j++)
            {
                cout<<core1.registers[y]<<" ";
                y++;
            }
            cout<<endl;
        }
        int u=0;
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                cout<<memory1[u]<<" ";
                u++;
            }
            cout<<endl;
        }
        v.clear();
        cout<<endl<<endl;
    }
    void runprogramCore2()
    {
        string filename;
        cout<<"enter file name:";
        getline(cin,filename);
        ifstream infile(filename);
        if(!infile.is_open())
        {
            cout<<"err"<<endl;
        }
        string o;
        while(getline(infile,o))
        {
            v.push_back(o);
        }
        checkingcore2();
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
        infile.close();
        int k=0;
        core2.pc=0;
        while(k!=v.size())
        {
            core2.execute(v.at(k),&(*memory2));
            k=core2.pc;
        }
        int y=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<16;j++)
            {
                cout<<core2.registers[y]<<" ";
                y++;
            }
            cout<<endl;
        }
        int u=0;
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                cout<<memory2[u]<<" ";
                u++;
            }
            cout<<endl;
        }
    }
    void checkingcore1()
    {
        int t=0;
        while(t < v.size())
        {
            int y=0;
            while(v[t][y] !=':' && y < v.at(t).size())
            {
                y++;
            }
            if(v[t][y]==':')
            {
                string h;
                h=v[t];
                string sd;
                sd=h.substr(0,y);
                core1.m[t]=sd;
            }
            t++;
        }
    }
    void checkingcore2()
    {
        int t=0;
        while(t < v.size())
        {
            int y=0;
            while(v[t][y] !=':' && y < v.at(t).size())
            {
                y++;
            }
            if(v[t][y]==':')
            {
                string h;
                h=v[t];
                string sd;
                sd=h.substr(0,y);
                core2.m[t]=sd;
            }
            t++;
        }
    }
};
int main()
{
    processor p;
    p.runprogramCore1();
    p.runprogramCore2();
}