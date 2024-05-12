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
using namespace std;

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
    std::map<std::string,std::pair<int*,std::vector<int>>>arrays;
    std::map<std::string,std::string>strings;
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
        pc=pc+1;
    }
    void IDRF(bool &stall,bool &dataforward,int &data_after_execution)
    {   
        parts.clear();
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
            if(!dataforward){
            for(int i=0;i<ex.size();i++){
                if(ex[i]==rs1||ex[i]==rs2){
                    stall=true;
                    break;
                }
            }
            }
            else{
               for(int i=0;i<ex.size();i++){
                 if(ex[i]==rs1){
                     rs1=to_string(data_after_execution);
                    }
                  if(ex[i]==rs2){
                    rs2=to_string(data_after_execution);
                  }
                }
            }
            ide.push(parts[0]);
            ide.push(rd);
            ide.push(rs1);
            ide.push(rs2);
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
            if(!dataforward){
              for(int i=0;i<ex.size();i++){
                   if(ex[i]==rs1||ex[i]==rs2){
                     stall=true;
                      break;
                    }
                }
            }
            else{
               for(int i=0;i<ex.size();i++){
                 if(ex[i]==rs1){
                     rs1=to_string(data_after_execution);
                    }
                  if(ex[i]==rs2){
                    rs2=to_string(data_after_execution);
                  }
                }
            }
            ide.push(parts[0]);
            ide.push(rd);
            ide.push(rs1);
            ide.push(rs2);
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
            if(dataforward && registers[stoi(r1)]!=registers[stoi(r2)]){
                ide.push(parts[3]); 
            }
            if(!dataforward){
                if(predict(pc)){
                    ide.push(parts[3]);
                }
            }
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
        }
        else if(parts[0]=="bgt")
        {
            std::string r1,r2;
            if(parts[1].size()>2)
            {
                f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                r1=f;
            }
            else if(parts[1].size()==2)
            {
                f=std::string(1,parts[1][1]);
                r1=f;
             }
            if(parts[2].size()>2)
            {
                f=std::string(1,parts[2][1])+std::string(1,parts[2][2]);
                r2=f;
            }
            else if(parts[2].size()==2)
            {
                f=std::string(1,parts[2][1]);
                r2=f;
            }
            ide.push(parts[0]);
            ide.push(r1);
            ide.push(r2);
            ide.push(parts[3]);
        }
        else if(parts[0]=="j")
        {
            ide.push(parts[0]);
            ide.push(parts[1]);
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
                    else if(parts[2].size()==7)
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
            else if(parts[0]=="la"){
                std::string rd,k;
                if(parts[1].size()>2)
                {
                   f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                   rd=f;
                }
                else if(parts[1].size()==2)
                {
                   f=std::string(1,parts[1][1]);
                   rd=f;
                }
                k=parts[2];
                ide.push(parts[0]);
                ide.push(rd);
                ide.push(k);
            }
            else if(parts[0]=="li"){
                std::string rd,k;
                if(parts[1].size()>2)
                {
                   f=std::string(1,parts[1][1])+std::string(1,parts[1][2]);
                   rd=f;
                }
                else if(parts[1].size()==2)
                {
                   f=std::string(1,parts[1][1]);
                   rd=f;
                }
                k=parts[2];
                ide.push(parts[0]);
                ide.push(rd);
                ide.push(parts[2]);
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
    void EX(bool &data_forwarding,int &final_data)
    {
        ex.clear();
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
            final_data=w;
        }
        else if(ide.front()=="sub")
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
            final_data=w;
        }
        else if(ide.front()=="addi")
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
            final_data=w;
        }
        else if(ide.front()=="bne")
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
        else if(ide.front()=="beq")
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
        else if(ide.front()=="blt")
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
        else if(ide.front()=="bgt")
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
                    pc=y;
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
        else if(ide.front()=="li"){
            int RD,w;
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            int k=stoi(ide.front());
            ide.pop();
            w=registers[RD]+k;
            std::string q=std::to_string(w);
            ex.push_back("6");
            ex.push_back(std::to_string(RD));
            ex.push_back(q); 
            final_data=w;
        }
        else if(ide.front()=="la"){
            int RD,w;
            ide.pop();
            RD=stoi(ide.front());
            ide.pop();
            std::string k=ide.front();
            ide.pop();
            for(auto it=arrays.begin();it!=arrays.end();it++){
                if(it->first==k){
                   w=&*(it->second.first);
                }
            }
            std::string q=std::to_string(w);
            ex.push_back("7");
            ex.push_back(std::to_string(RD));
            ex.push_back(q);
            final_data=w;
        }
        else if(ide.front()=="sw")
        {
            ex.push_back("5");
            ide.pop();
            ex.push_back(ide.front());
            ide.pop();
            if(ide.front()!="base")
            {
                ex.push_back(ide.front());
                ide.pop();
                ex.push_back(ide.front());
                ide.pop();
            }
            else if(ide.front()=="base")
            {
                ex.push_back(ide.front());
                ide.pop();
            }
        }
    }
    void MEM(int *memory,CacheSimulation &cv)
    {
        int i=0;
        while(i<ex.size())
        {
            if(ex[i]=="4"&&ex[i+2]!="base")
            {
                int r1,r2,os,o;
                r1=stoi(ex[i+1]);
                r2=stoi(ex[i+3]);
                os=stoi(ex[i+4]);
                uint32_t address=registers[r2]+os;
                if(!cv.access(address))
                {
                    o=cv.write(address,memory[address]);
                }
                registers[r1]=o;
                for(int j=i;j<=i+4;j++)
                {
                    ex.erase(ex.begin()+j);
                }
            }
            if(ex[i]=="4"&&ex[i+2]=="base")
            {
                int r1,base;
                r1=stoi(ex[i+1]);
                base=stoi(ex[i+3]);
                registers[r1]=base;
                for(int j=i;j<=i+3;i++)
                {
                    ex.erase(ex.begin()+j);
                }
            }
            if(ex[i]=="5")
            {
                int r1,r2,os,o;
                r1=stoi(ex[i+2]);
                r2=stoi(ex[i+3]);
                os=stoi(ex[i+4]);
                uint32_t address=registers[r2]+os;
                if(!cv.access(address))
                {
                    o=cv.write(address,registers[r1]);
                }
                else if(cv.access(address))
                {
                    cv.update(address,registers[r2]);
                }
                memory[registers[r2]+os]=registers[r1];
                for(int j=i;j<=i+3;j++)
                {
                    ex.erase(ex.begin()+j);
                }
            }
            i++;
        }
        for(int j=0;j<ex.size();j++)
        {
            me.push(ex[j]);
        }
    }
    void WB()
    {
        if(me.empty()){
            return;
        }
        else if(me.front()=="1")
        {
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            l=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
        else if(me.front()=="2")
        {
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            l=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
        else if(me.front()=="3")
        {
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            l=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
        else if(me.front()=="6"){
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            l=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
        else if(me.front()=="7"){
            int DR,l;
            me.pop();
            DR=stoi(me.front());
            me.pop();
            l=stoi(me.front());
            me.pop();
            registers[DR]=l;
        }
    } 
    std::vector<std::string> remove(std::vector<std::string>fd,int *memory)
    {
        std::vector<int> word;
        std::vector<int> removing;
        bool adf;
        parts.clear();
        for(int i=0;i<fd.size();i++)
        {
            int rw=removing.size();
            std::string b=fd[i];
            if(fd[i][0]=='.')
            {
                std::string e;
                std::cout<<"r";
                std::stringstream str(b);
                while(getline(str,e,' '))
                {
                    parts.push_back(e);
                }
                if(parts[0]==".word")
                {
                    std::cout<<"d";
                    for(int k=1;k<parts.size();k++)
                    {
                        word.push_back(stoi(parts[k]));
                    }
                    removing.push_back(i);
                }
                    parts.clear();
            }
            if(fd[i][0]=='b')
            {
                std::cout<<"nm";
                parts.clear();
                std::string asdf;
                std::stringstream str(b);
                while(getline(str,asdf,' '))
                {
                    parts.push_back(asdf);
                }
                if(parts[0]=="base:")
                {
                    base=stoi(parts[2]);
                    for(int fgd=0;fgd<word.size();fgd++)
                    {
                        memory[base+fgd]=word[fgd];
                    }
                    removing.push_back(i);
                }
            }
            if(fd[i]==".data")
            {
                removing.push_back(i);
            }
            if(fd[i]==".text")
            {
                removing.push_back(i);
            }
            int yo=removing.size();
        }
        int fds=removing.size();
        std::map<int,string> mer;
        std::vector<string> hes;
        for(int i=0;i<fd.size();i++)
        {
            mer[i]=fd[i];
        }
        for(int i=0;i<removing.size();i++)
        {
            mer[removing[i]]="zzzz";
        }
        for(int i=0;i<fd.size();i++)
        {
            if(mer[i]!="zzzz")
            {
                hes.push_back(mer[i]);
            }
        }
        for(int i=0;i<hes.size();i++) 
        {
            std::cout<<hes[i];
        }
        return hes;
    }
    bool predict(int pc){

        return true;
    }
    void pipeline(std::vector<std::string> fg,int latif,int latid,int latex,int latmem,int latwb,int *memory,CacheSimulation cv)
    {
        int instructions =0;
        int cycle=0;
        std::map<int,std::pair<int,std::string>> ij;
        std::map<int,std::queue<std::pair<int,std::string>>> ins;
        int nh,ht;
        std::vector<std::string> slit1;
        std::vector<std::string> slit2;
        std::queue<std::string> bh;
        bool stall=false; 
        for(int i=0;i<=fg.size()-1;i++)
        {   ij[i].first=i;
            ij[i].second=fg[i];
        }
        std::cout<<"type yes if you want to enable data forwarding else type no"<<std::endl;
        std::string x;
        bool data_forwarding=false;
        std::cin>>x;
        if(x=="yes"){
            data_forwarding=true;
        }
        else if(x=="no"){
            data_forwarding=false;
        }
        ht=1;
        ins[1].push(ij[pc]);
        while(!ins[1].empty() || !ins[2].empty() || !ins[3].empty() || !ins[4].empty() || !ins[5].empty())
        {       
                    if(!ins[5].empty())
                    {   
                        int t=pc;
                        pc=ins[5].front().first;
                        WB();
                        ins[5].pop();
                        for(int j=0;j<latwb-1;j++)
                        {
                            
                        }
                        if(stall==true)
                        {
                            stall=false;
                        }
                        pc=t;
                        std::cout<<"W";
                    }
                    if(!ins[4].empty())
                    {
                        int t=pc;
                        pc=ins[4].front().first;
                        int x=pc;
                        MEM(memory,cv);
                       ins[4].pop();
                        ins[5].push(ij[x]);
                        for(int j=0;j<latmem-1;j++)
                        {
                            
                        }
                        std::cout<<"M";
                        pc=t;
                    }
                    int data_after_execution;
                    if(!ins[3].empty())
                    {
                        int t=pc;
                        pc=ins[3].front().first;
                        int x=pc;
                        ins[3].pop();
                        if(ide.front()=="bne"||ide.front()=="beq"||ide.front()=="blt"||ide.front()=="bgt"||ide.front()=="j")
                        {
                            EX(data_forwarding,data_after_execution);
                            if(pc!=x){
                              ins[1].push(ij[pc]);
                            }
                        }
                        else
                        {
                            EX(data_forwarding,data_after_execution);
                            std::cout<<"k";
                            ins[4].push(ij[x]);
                        }
                        if(x!=fg.size()-1 && pc!=x)
                        {    
                            std::string ef=ij[x].second;
                            std::string sd=ij[x+1].second;
                            std::string jkl;
                            std::stringstream dfg(ef);
                            std::stringstream fgh(sd);
                            while(getline(dfg,jkl,' '))
                            {
                                slit1.push_back(jkl);
                            }
                            while(getline(fgh,jkl,' '))
                            {
                                slit2.push_back(jkl);
                            }
                            if(slit2[0]=="add"||slit2[0]=="sub"||slit2[0]=="addi")
                            {
                                if(slit1[1]==slit2[2]||slit1[1]==slit2[3])
                                {   
                                    stall=true; 
                                }
                            }
                        }
                        for(int j=0;j<latex-1;j++)
                        {
                            
                        }
                       std::cout<<"E";
                        pc=t;
                    }
                    if(!ins[2].empty()&&stall==false)
                    {   
                        int t=pc;
                        pc=ins[2].front().first;
                        int x=pc;                                        
                        IDRF(stall,data_forwarding,data_after_execution);
                        ins[2].pop();
                        ins[3].push(ij[x]);
                        for(int j=0;j<latid-1;j++)
                        {
                            
                        }
                       std::cout<<"R";
                        pc=t;
                    }  
                    if(!ins[1].empty()&&stall==false)
                    {   
                        instructions++;
                        int x=ins[1].front().first;
                        IF(ins[1].front().second);
                        ins[1].pop();
                        ins[2].push(ij[x]);
                        for(int j=0;j<latif-1;j++)
                        {

                        }
                       if(pc<fg.size() && stall==false){
                           while(m.find(ij[pc].first)!=m.end()){
                               pc++;
                            }
                            ins[1].push(ij[pc]);
                        }
                        else
                        {
                            pc=pc-1;
                        }
                       std::cout<<"I";                   
                        //cycle++;
                    }
                    cycle++;
                    std::cout<<std::endl;
        }
        float a=instructions;
        float b=cycle;
        float c=a/b;
        printf("IPC:%.3f\n",c);
    }

};
struct cacheBlock
{
    uint32_t tag;
    bool valid;
    // Add data field to store the actual data in the cache block
    uint32_t data;
    unsigned int recency;
    unsigned int frequency;
    unsigned int score;
    // if(recency!=0){
    //  score=alpha*frequency+beta/recency;
    // }
};

class processor
{
public:
    core core1;
    int *data_memory = new int[1024]();
    int *Instruction_memory =new int[1024]();
   // std::vector<std::string> v;
    std::vector<cacheBlock>cache;
    std::vector<cacheBlock>recent;   
    std::vector<std::vector<cacheBlock>> cache;
    unsigned int cacheSize;
    unsigned int blockSize;
    unsigned int numOfBlocks;
    unsigned int hits;
    unsigned int misses;
    unsigned int alpha;
    unsigned int beta;
    pair<uint32_t, uint32_t> splitAdress(uint32_t address)
    {
        int byteOffset = log2(blockSize);
        address = address >> byteOffset;
        uint32_t index = address & ((1 << numOfBlocks) - 1);
        address = address >> ((1 << numOfBlocks) - 1);
        uint32_t tag = address;
        pair<uint32_t, uint32_t> y = make_pair(index, tag);
        return y;
    }
    CacheSimulation(unsigned int _cacheSize, unsigned int _blockSize)
        : cacheSize(_cacheSize), blockSize(_blockSize), hits(0), misses(0)
    {
        assert(cacheSize % blockSize == 0);
        numOfBlocks = cacheSize / blockSize;
        cache.resize(numOfBlocks);
        for (auto &u : cache)
        {
            u.valid = false;
            u.recency=0;
        }
    }


void update(int y,int newData)
{
    cache[y].data=newData;
}

 bool access(uint32_t address)
    {
        auto h = splitAdress(address);
        uint32_t index = h.first;
        uint32_t tag = h.second;
        for (int i = 0; i < numOfBlocks; i++)
        {
            if (cache[i].tag == tag && cache[i].valid)
            {
                // for cache hit
                hits++;
                cache[i].frequency++;
                cache[i].recency=1;
                cache[i].score=alpha*cache[i].frequency+beta/cache[i].recency;
                for (int i = 0; i < numOfBlocks; i++)
                {
                   if (cache[i].recency!=1 || cache[i].recency!=0)
                   {
                       cache[i].recency++;
                       cache[i].score=alpha*cache[i].frequency+beta/cache[i].recency;
                   }
                }
                return true;
            }
        }
        // Update statistics for cache miss
        misses++;
        int min_score=INT_MAX;
        int min_index=0;
        for(int i=0;i<numOfBlocks;i++){
            if(cache[i].score<min_score){
                min_score=cache[i].score;
                min_index=i;
            }
        }
        // Replace the min block with the new block
        cache[min_index].tag = tag;
        cache[min_index].valid = true;
        cache[min_index].recency = 1;
        cache[min_index].frequency++;
        cache[min_index].score=alpha*cache[min_index].frequency+beta/cache[min_index].recency;
        // Simulate reading data from memory and storing it in the cache block
        cache[min_index].data = memory[address]; // Read from memory array
        return false;
    }

    // Method to read data from cache
    uint32_t read(uint32_t address)
    {
        auto h = splitAdress(address);
        uint32_t index = h.first;
        if (cache[index].valid && cache[index].tag == h.second)
        {
            //for cache hit
            hits++;
            return cache[index].data;
        }
        //for cache miss
        misses++;
        cache[index].tag = h.second;
        cache[index].valid = true;
        // Simulate reading data from memory and storing it in the cache block
        cache[index].data = memory[address]; // Read from memory array
        return cache[index].data;
    }

    // Method to write data to cache
    uint32_t write(uint32_t address, uint32_t data)
    {
        auto h = splitAdress(address);
        uint32_t index = h.first;
        cache[index].tag = h.second;
        cache[index].valid = true;
        // Update data in the cache block
        cache[index].data = data;
        // Write data back to memory array
        memory[address] = data;
        return data;
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
    void runprogramCore1()
    {
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
            v.push_back(o);
        }
        checkingcore1();
        infile.close();
        int k = 0;
        core1.pc = 0;
        int lateif, lateid, lateex, latemem, latewb;
        std::cout << "IF Latency:";
        std::cin >> lateif;
        std::cout << "ID Latency:";
        std::cin >> lateid;
        std::cout << "EX Latency:";
        std::cin >> lateex;
        std::cout << "MEM Latency:";
        std::cin >> latemem;
        std::cout << "WB Latency:";
        std::cin >> latewb;
        std::vector<std::string> jkl = core1.remove(v, &(*data_memory));
        //if()
        core1.pipeline(jkl, lateif, lateid, lateex, latemem, latewb, &(*data_memory), cv);
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
        v.clear();
        std::cout << std::endl;
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
            if(v[t][y]==':' && v[t][y+1]=='.' && v[t][y+2]=='w'){
                std::string h;
                h=v[t];
                std::string sd;
                sd=h.substr(0,y);
                std::string p;
                std::stringstream str(v[t]);
                while(getline(str,p,' ')){
                    if(h[0]>='0' && h[0]<='9'){
                      core1.arrays[sd].second.push_back(stoi(p));
                    }
                }
                int *x=data_memory;
                while(*(x)==NULL){
                    x++;
                }
                core1.arrays[sd].first=x;
                for(int i=0;i<core1.arrays[sd].size();i++){
                    *(x)=core1.arrays[sd].second[i];
                    x++;
                }
            }
            else if(v[t][y]==':' && v[t][y+1]=='.' && v[t][y+2]=='s'){
                std::string h;
                h=v[t];
                std::string sd;
                sd=h.substr(0,y);
                int x=y;
                while(v[t][x]!='"'){
                    x++;
                }
                x++;
                int z=x;
                while(v[t][z]!='"'){
                    z++;
                }
                std::string p;
                p=h.substr(x,z);
                core1.strings[sd]=p;
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
};
int main()
{
    processor p;
    p.runprogramCore1();
}