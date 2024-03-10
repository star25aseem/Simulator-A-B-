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
    std::vector<std::string> parts;
    std::queue<std::string> infe;
    std::queue<std::string> ide;
    std::vector<std::string> ex;
    std::queue<std::string> me;
    std::string ife;
    std::vector<std::string> idrf;
    std::map<int,std::string> pl;
    void IF(std::string e)
    {
        infe.push(e);
        pc+=1;
    }
    void IDRF()
    {   
        std::string c=infe.front();
        infe.pop();
        std::stringstream str(c);
        while(getline(str,h,' '))
        {
            parts.push_back(h);
        }
        if(parts[0]=="add")
        {
            std::string rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=f;
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                rs1=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                rs1=f;
            }
            if(parts[3].size()>2)
            {
                f=std::string(1,parts[3][1])+std::string(1,parts[3][2]);
                rs2=f;
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[3][1]);
                rs2=f;
            }
            ide.push(parts[0]);
            ide.push(rd);
            ide.push(rs1);
            ide.push(rs2);
            ide.push("3");
        }
        else if(parts[0]=="sub")
        {
            std::string rd,rs1,rs2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=f;
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                rs1=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                rs1=f;
            }
            if(parts[3].size()>2)
            {
                f=std::string(1,parts[3][1])+std::string(1,parts[3][2]);
                rs2=f;
            }
            if(parts[3].size()==2)
            {
                f=std::string(1,parts[3][1]);
                rs2=f;
            }
            ide.push(parts[0]);
            ide.push(rd);
            ide.push(rs1);
            ide.push(rs2);
            ide.push("3");
        }
        else if(parts[0]=="addi")
        {
            std::string rd,rs,k;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                rd=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                rd=f;
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                rs=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                rs=f;
            }
            k=parts[3];
            ide.push(parts[0]);
            ide.push(rd);
            ide.push(rs);
            ide.push(k);
            ide.push("3");
        }
        else if(parts[0]=="bne")
        {
            std::string r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=f;
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                r2=f;
            }
            ide.push(parts[0]);
            ide.push(r1);
            ide.push(r2);
            ide.push(parts[3]);  
            ide.push("3");   
       }
        else if(parts[0]=="beq")
        {
            std::string r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=f;
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                r2=f;
            }
            ide.push(parts[0]);
            ide.push(r1);
            ide.push(r2);
            ide.push(parts[3]);
            ide.push("3");
        }
            else if(parts[0]=="blt")
            {
            std::string r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=f;
            }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                r2=f;
            }
            ide.push(parts[0]);
            ide.push(r1);
            ide.push(r2);
            ide.push(parts[3]);
            ide.push("3");
        }
        else if(parts[0]=="bgt")
        {
            std::string r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=f;
             }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=f;
            }
            if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                r2=f;
            }
            ide.push(parts[0]);
            ide.push(r1);
            ide.push(r2);
            ide.push(parts[3]);
            ide.push("3");
        }
        else if(parts[0]=="j")
        {
            ide.push(parts[0]);
            ide.push(parts[1]);
            ide.push("3");
        }
        else if(parts[0]=="lw")
        {
            int x,y;
            std::string w;
            std::string offset;
            std::string r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=f;
            }
            if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=f;
            }
            if(parts[2][2]=='x'||parts[2][3]=='x')
            {
                if(parts[2][2]=='x')
                {
                    f=std::string(1,parts[2][0]);
                    offset=f;
                    if(parts[2].size()==5)
                    {
                        w=std::string(1,parts[2][3]);
                        r2=w;                       
                    }
                    if(parts[2].size()==6)
                    {
                        w=std::string(1,parts[2][3])+std::string(1,parts[2][4]);
                        r2=w;                       
                    }
                }
                if(parts[2][3]=='x')
                {
                    f=std::string(1,parts[2][0])+std::string(1,parts[2][1]);
                    offset=stoi(f);
                    if(parts[2].size()==6)
                    {
                        w=std::string(1,parts[2][4]);
                        r2=w;                       
                    }
                    if(parts[2].size()==7)
                    {
                        w=std::string(1,parts[2][4])+std::string(1,parts[2][5]);
                        r2=w;                       
                    }
                }
                ide.push(parts[0]);
                ide.push(r1);
                ide.push(r2);
                ide.push(offset);

            }
            if(parts[2]=="base")
            {
                ide.push(parts[0]);
                ide.push(r1);
                ide.push("base");
            } 
            pc=pc+1;
        }
    }
    void EX()
    {
        if(ide.front()=="add")
        {
            int RD,RS1,RS2,w; 
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS1=stoi(ide.front());
            ide.pop();
            RS2=stoi(ide.front());
            ide.pop();
            w=registers[RS1]+registers[RS2];
            std::string q=std::to_string(w);
            ex.push_back("1");
            ex.push_back(std::to_string(RD));
            ex.push_back(q); 
        }
        if(ide.front()=="sub")
        {
            int RD,RS1,RS2,w; 
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS1=stoi(ide.front());
            ide.pop();
            RS2=stoi(ide.front());
            ide.pop();
            w=registers[RS1]-registers[RS2];
            std::string q=std::to_string(w);
            ex.push_back("2");
            ex.push_back(std::to_string(RD));
            ex.push_back(q);
        }
        if(ide.front()=="addi")
        {
            int RD,RS1,k,w; 
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS1=stoi(ide.front());
            ide.pop();
            k=stoi(ide.front());
            ide.pop();
            w=registers[RS1]+k;
            std::string q=std::to_string(w);
            ex.push_back("3");
            ex.push_back(std::to_string(RD));
            ex.push_back(q);
        }
        if(ide.front()=="bne")
        {
            int RD,RS;
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS=stoi(ide.front());
            ide.pop();
            int y=0;
            if(registers[RD]!=registers[RS])
            {
                while(m[y]!=ide.front())
                {
                    y++;
                }
                if(m[y]==ide.front())
                {
                    pc=y+1;
                }
            }
        }
        if(ide.front()=="beq")
        {
            int RD,RS;
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS=stoi(ide.front());
            ide.pop();
            int y=0;
            if(registers[RD]==registers[RS])
            {
                while(m[y]!=ide.front())
                {
                    y++;
                }
                if(m[y]==ide.front())
                {
                    pc=y+1;
                }
            }
        }
        if(ide.front()=="blt")
        {
            int RD,RS;
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS=stoi(ide.front());
            ide.pop();
            int y=0;
            if(registers[RD]<registers[RS])
            {
                while(m[y]!=ide.front())
                {
                    y++;
                }
                if(m[y]==ide.front())
                {
                    pc=y+1;
                }
            }
        }
        if(ide.front()=="bgt")
        {
            int RD,RS;
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            RS=stoi(ide.front());
            ide.pop();
            int y=0;
            if(registers[RD]>=registers[RS])
            {
                while(m[y]!=ide.front())
                {
                    y++;
                }
                if(m[y]==ide.front())
                {
                    pc=y+1;
                }
            }

        }
        else if(ide.front()=="j")
        {
            int y=0;
                while(m[y]!=ide.front())
                {
                    y++;
                }
                if(m[y]==ide.front())
                {
                    pc=y+1;
                }
                ide.pop();
        }
        else if(ide.front()=="lw")
        {
            ex.push_back("4");
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
        }
        else if(ide.front()=="sw")
        {
            ex.push_back("5");
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
        }
    }
    void MEM(int *memory)
    {
        int i=0;
        while(i<ex.size())
        {
            if(ex[i]=="4"&&ex[i+1]=="1")
            {
                int r1,r2,os;
                r1=stoi(ex[i+2]);
                r2=stoi(ex[i+3]);
                os=stoi(ex[i+4]);
                registers[r1]=memory[registers[r2]+os];
                for(int j=i;j<=i+4;i++)
                {
                    ex.erase(ex.begin()+j);
                }
            }
            if(ex[i]=="4"&&ex[i+1]=="2")
            {
                int r1,base;
                r1=stoi(ex[i+2]);
                base=stoi(ex[i+3]);
                registers[r1]=base;
                for(int j=i;j<=i+3;i++)
                {
                    ex.erase(ex.begin()+j);
                }
            }
            if(ex[i]=="5")
            {
                int r1,r2,os;
                r1=stoi(ex[i+2]);
                r2=stoi(ex[i+3]);
                os=stoi(ex[i+4]);
                memory[registers[r2]+os]=registers[r1];
                for(int j=i;j<=i+3;i++)
                {
                    ex.erase(ex.begin()+j);
                }
            }
            i++;
        }
        for(int i=0;i<ex.size();i++)
        {
            me.push(ex[i]);
        }
    }
    void WB()
    {
        if(me.front()=="1")
        {
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
        if(me.front()=="2")
        {
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
        if(me.front()=="3")
        {
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
    } 
    std::vector<std::string> remove(std::vector<std::string>fd,int *memory)
    {
        std::vector<int> word;
        std::vector<int> removing;
        bool adf;
        for(int i=0;i<fd.size();i++)
        {
            std::string b=fd[i];
            if(fd[i][1]=='.')
            {
                std::stringstream str(b);
                while(getline(str,h,' '))
                {
                    parts.push_back(h);
                }
                if(parts[0]==".word")
                {
                    for(int k=1;k<=parts.size();k++)
                    {
                        word.push_back(stoi(parts[k]));
                    }
                }
                for(int a=0;a<parts.size();a++)
                {
                    parts.pop_back();
                }
                removing.push_back(i);
            }
            if(fd[i][0]!='.'&&fd[i][1]=='b'&&fd[i][2]=='a'&&fd[i][3]=='s'&&fd[i][4]=='e')
            {
                std::string asdf;
                std::string r=fd[i];
                std::stringstream str(r);
                while(getline(str,asdf,' '))
                {
                    parts.push_back(h);
                }
                            base=stoi(parts[2]);
                for(int i=0;i<word.size();i++)
                {
                    memory[base+i]=word[i];
                }
                removing.push_back(i);
            }
            for(int er=0;er<removing.size();er++)
            {
                fd.erase(fd.begin()+er);
            }
        }
        return fd;
    }
    void pipeline(std::vector<std::string> fg,int latif,int latid,int latex,int latmem,int latwb,int *memory)
    {
        int cycle=0;
        std::map<int,std::pair<int,std::string>> ij;
        std::map<int,std::queue<std::pair<int,std::string>>> ins;
        int nh;
        std::vector<std::string> bh;
        bool stall=false; 
        for(int i=0;i<=fg.size()-1;i++)
        {   ij[i].first=i;
            ij[i].second=fg[i];
        }
        while(pc<=fg.size())
        {
            if(pc<fg.size())
            {  
                ins[1].push(ij[pc]);
            }
            nh=1;
            for(int i=0;i<nh;i++)
            {
                if(true)
                {   if(!ins[5].empty())
                    {   int t=pc;
                        pc=ins[5].front().first;
                        WB();
                        pc=t;
                        ins[5].pop();
                        for(int j=0;j<latwb-1;j++)
                        {
                            
                        }
                       // bh.pop_back();
                        //cycle++;
                        if(ins[4].empty()&&ins[3].empty()&&ins[2].empty()&&ins[1].empty()){
                            pc++;
                        }
                    }
                    if(!ins[4].empty())
                    {
                        int t=pc;
                        pc=ins[4].front().first;
                        int x=pc;
                        MEM(memory);
                        pc=t;
                       ins[4].pop();
                        if(pc<=fg.size())
                        {
                            ins[5].push(ij[x]);
                        }
                        for(int j=0;j<latmem-1;j++)
                        {
                            
                        }
                    }
                    if(!ins[3].empty())
                    {
                        int t=pc;
                        pc=ins[3].front().first;
                        int x=pc;
                        ins[3].pop();
                        if(ide.front()=="bne"||ide.front()=="beq"||ide.front()=="blt"||ide.front()=="bgt"||ide.front()=="j")
                        {
                            EX();
                            pc=t;
                            if(pc<=fg.size())
                            {
                                ins[1].push(ij[x]);
                            }
                        }
                        else
                        {
                            EX();
                            pc=t;
                            if(pc<=fg.size())
                            {
                                ins[4].push(ij[x]);
                            }
                        }
                        for(int j=0;j<latex-1;j++)
                        {
                            
                        }
                    }
                    if(!ins[2].empty()&&stall==false)
                    {   
                        int t=pc;
                        pc=ins[2].front().first;
                        int x=pc;                                        
                        IDRF();
                        pc=t;
                        ins[2].pop();
                        if(pc<=fg.size()){
                          ins[3].push(ij[x]);
                        }
                        for(int j=0;j<latid-1;j++)
                        {
                            
                        }
                        // if(bh.empty()||stall==false)
                        // {
                        //     bh.push_back(ij[pc].second);
                        // }
                        // if(ij[pc].second[2]==bh.front()[1]||ij[pc].second[3]==bh.front()[1])
                        // {
                        //     stall=true;
                        // }
                    }  
                    if(!ins[1].empty()&&stall==false)
                    {    
                        int x=ins[1].front().first;
                        IF(ins[1].front().second);
                        ins[1].pop();
                        if(pc<=fg.size()){
                          ins[2].push(ij[x]);
                        }
                        for(int j=0;j<latif-1;j++)
                        {

                        }
                        cycle++;
                    }
                    else{
                        cycle++;
                    }
                }
                else
                {
                    //ins.pop();
                }
            }
        }
        float a=fg.size();
        float b=cycle;
        float c=a/b;
        printf("IPC:%.3f\n",c);
    }

};
class processor
{
    public:
    core core1;
    int *memory1=new int[1024]();
    std::vector<std::string> v;
    void runprogramCore1()
    {
        std::string filename;
        std::cout<<"enter file name:";
        std::getline(std::cin,filename);
        std::ifstream infile(filename);
        if(!infile.is_open())
        {
            std::cout<<"err"<<std::endl;
            return;
        }
        std::string o;
        while(getline(infile,o))
        {
            v.push_back(o);
        }
        infile.close();
        int k=0;
        core1.pc=0;
        int lateif,lateid,lateex,latemem,latewb;
        std::cout<<"IF Latency:";
        std::cin>>lateif;
        std::cout<<"ID Latency:";
        std::cin>>lateid;
        std::cout<<"EX Latency:";
        std::cin>>lateex;
        std::cout<<"MEM Latency:";
        std::cin>>latemem;
        std::cout<<"WB Latency:";
        std::cin>>latewb;
        std::vector<std::string> jkl=core1.remove(v,&(*memory1));
        core1.pipeline(jkl,lateif,lateid,lateex,latemem,latewb,&(*memory1));
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
};
int main()
{
    processor p;
    p.runprogramCore1();
}