#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<map>
#include<string>
class core
{
    public:
    int *registers{ new int[32]{} };
    int pc;
    std::string l;
    int base;
    std::string h;
    int mp_index=0;
    std::string f;
    std::vector<int> word;
    std::map<int,std::pair<std::string,std::string>> mp;
    std::map<int,std::string> m;

    void execute(std::string b,int *mem)
    {
        std::vector<std::string> parts;
        
        std::stringstream str(b);
        while(getline(str,h,' '))
        {
            parts.push_back(h);
        }
        std::string::iterator it =parts[0].end();
        if(parts[0]=="base:")
        {
            base=stoi(parts[2]);
            for(int i=0;i<word.size();i++)
            {
                mem[base+i]=word[i];
            }
            pc=pc+1;
        }
        else if(*(it-1)==':' && parts[1]==".string"){

            std::pair<std::string,std::string> p={parts[0],parts[2].substr(1,parts[2].length()-2)};
            mp[mp_index]=p;
            mp_index++;
            pc+=1;
        }
        else if(parts[0]=="add")
        {
            int rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                rs1=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                rs1=stoi(f);
            }
            if(parts[3].size()>2)
            {
                f=std::string(1,parts[3][1])+std::string(1,parts[3][2]);
                rs2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[3][1]);
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
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                rs1=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                rs1=stoi(f);
            }
            if(parts[3].size()>2)
            {
                f=std::string(1,parts[3][1])+std::string(1,parts[3][2]);
                rs2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[3][1]);
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
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                rs=stoi(f);
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
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
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[2][1]);
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
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[2][1]);
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
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[2][1]);
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
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=stoi(f);
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[2][1]);
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
            std::string w;
            int offset;
            int r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=stoi(f);
            }
            if(parts[2][2]=='x'||parts[2][3]=='x')
            {
                if(parts[2][2]=='x')
                {
                    f=std::string(1,parts[2][0]);
                    offset=stoi(f);
                    if(parts[2].size()==5)
                    {
                        w=std::string(1,parts[2][3]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=std::string(1,parts[2][3])+std::string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=std::string(1,parts[2][0])+std::string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=std::string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=std::string(1,parts[2][4])+std::string(1,parts[2][5]);
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
            std::string w;
            int offset;
            int r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=stoi(f);
            }
                if(parts[2][2]=='x')
                {
                    f=std::string(1,parts[2][0]);
                    offset=stoi(f);
                    if(parts[2].size()==5)
                    {
                        w=std::string(1,parts[2][3]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=std::string(1,parts[2][3])+std::string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=std::string(1,parts[2][0])+std::string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=std::string(1,parts[2][4]);
                        r2=stoi(w);                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=std::string(1,parts[2][4])+std::string(1,parts[2][5]);
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
                else if(parts[0]=="li"){
            int rd,k;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=stoi(f);
            }
            k=stoi(parts[2]);
            registers[rd]=k;
            pc+=1;
        }
        else if(parts[0]=="la"){
            int rd;
            std::string w;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=stoi(f);
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=stoi(f);
            }
            for(auto it=mp.begin();it!=mp.end();++it){
                if(it->second.first==parts[2]){
                    registers[rd]=it->first;
                }
            }
            pc+=1;
        }
        else if(parts[0]=="ecall"){
            switch(registers[17]){
                case 1:
               // cout<<this->registers[10]<<" ";
                  printf("%d",registers[10]);
                   break;
                case 2:
                    printf("%f",registers[10]);
                    break;
                case 4:
                   std:: cout<<mp[registers[10]].second;
                    break;
                case 10:
                  std::cout<<"Program exited with code: 0";
                  return;
                  break;
                case 11:
                  printf("%c",registers[10]);
                  break;
                case 34:
                case 35:
                case 36:
                case 93:
                    std::cout<<"Program exited with code: ";
                    std::cout<<registers[10];
                    return; 
                    break;
            }
            pc+=1;              
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
    std::map<int,std::string> m;
    std::vector<std::string> v;
    int pc=1;
    void runprogramCore1()
    {
        std::string filename;
        std::cout<<"enter file name:";
        std::getline(std::cin,filename);
        std::ifstream infile(filename);
        if(!infile.is_open())
        {
            std::cout<<"err"<<std::endl;
        }
        std::string o;
        while(getline(infile,o))
        {
            v.push_back(o);
        }
        checkingcore1();
        infile.close();
        int k=0;
        core1.pc=0;
        while(k!=v.size())
        {
            core1.execute(v.at(k),&(*memory1));
            k=core1.pc;
        }
        std::cout<<std::endl;
        int y=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<16;j++)
            {
                std::cout<<core1.registers[y]<<" ";
                y++;
            }
            std::cout<<std::endl;
        }
        int u=0;
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                std::cout<<memory1[u]<<" ";
                u++;
            }
            std::cout<<std::endl;
        }
        v.clear();
        std::cout<<std::endl;
    }
    void runprogramCore2()
    {
        std::string filename;
        std:: cout<<"enter file name:";
        std::getline(std::cin,filename);
        std::ifstream infile(filename);
        if(!infile.is_open())
        {
            std::cout<<"err"<<std::endl;
        }
        std::string o;
        while(getline(infile,o))
        {
            v.push_back(o);
        }
        checkingcore2();
        infile.close();
        int k=0;
        core2.pc=0;
        while(k!=v.size())
        {
            core2.execute(v.at(k),&(*memory2));
            k=core2.pc;
        }
        std::cout<<std::endl;
        int y=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<16;j++)
            {
                std::cout<<core2.registers[y]<<" ";
                y++;
            }
           std:: cout<<std::endl;
        }
        int u=0;
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                std::cout<<memory2[u]<<" ";
                u++;
            }
            std::cout<<std::endl;
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
                std::string h;
                h=v[t];
                std::string sd;
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
                std::string h;
                h=v[t];
                std::string sd;
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