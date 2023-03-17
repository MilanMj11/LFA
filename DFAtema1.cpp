#include <bits/stdc++.h>

using namespace std;

ifstream fin("automat.txt");
ifstream fin_aux("automat.txt");
ifstream f_input("input.txt");
ofstream fout("output.txt");

const int NMAX = 10005;
vector< pair<int,char> > graf[NMAX]; /// v[i] = { vecin , muchie }
map<string,int> conversie; /// conversie[node] = indicele
string conv[NMAX]; /// conv[indice] = node;
string stari_finale[NMAX];
string stare_initiala = "";
int cnt_stari_finale = 0;
int cnt_nodes = 0;
int dim_sol = 0, dim_drum = 0;
string sol[NMAX],drum[NMAX];

void procesare_linie(string s){
    string node1 = "",node2 = "";
    char muchie;
    int ind = 0;
    while(s[ind]!=' '){
        node1 = node1 + s[ind];
        ind++;
    }
    ind++;
    while(s[ind]!=' '){
        muchie = s[ind];
        ind++;
    }
    ind++;
    int dim = s.size();
    while(ind!=dim){
        node2 = node2 + s[ind];
        ind++;
    }
//    fout << node1 << '\n' << muchie << '\n' << node2 << '\n';
    if(conversie.find(node1) == conversie.end()){
        conversie.insert(make_pair(node1,++cnt_nodes));
        conv[cnt_nodes] = node1;
    }
    if(conversie.find(node2) == conversie.end()){
        conversie.insert(make_pair(node2,++cnt_nodes));
        conv[cnt_nodes] = node2;
    }
    graf[conversie[node1]].push_back(make_pair(conversie[node2],muchie));
}

void procesare_stari_finale(string s){
    string nod = "";
    int ind = 0;
    int dim = s.size();
    while(ind!=dim){
        if(s[ind]==' '){
            stari_finale[++cnt_stari_finale] = nod;
            nod = "";
            ind++;
        }
        nod = nod + s[ind];
        ind++;
    }
    stari_finale[++cnt_stari_finale] = nod;
//    fout << cnt_stari_finale << '\n';
//    for(int i=1;i<=cnt_stari_finale;i++){
//        fout << stari_finale[i] << '\n';
//    }
}

void citire(){
    getline(fin_aux,stare_initiala);
    getline(fin,stare_initiala);
    //fout << stare_initiala << '\n';
    string s;
    int nr_linii = 0;
    while(!fin_aux.eof()){
        getline(fin_aux,s);
        nr_linii++;
        //fout << s << '\n';
    }
    int aux = 0;
    while(!fin.eof()){
        getline(fin,s);
        aux++;
        if(aux == nr_linii){
            procesare_stari_finale(s);
        } else
            procesare_linie(s);
    }
}

bool acceptat = false;

void dfs(int node,string cuvant){
    drum[++dim_drum] = conv[node];
    if(cuvant.size()==0) {
        for(int i=1;i<=cnt_stari_finale;i++)
            if(conv[node] == stari_finale[i]){
                //fout << "acceptat";
                acceptat = true;
                return;
            }
        //fout << "neacceptat";
        acceptat = false;
        return;
    }
    /// fout << cuvant << '\n';
    sol[++dim_sol] = cuvant;
    for(int i=0;i<graf[node].size();i++){
        pair<int,char> aux = graf[node][i];
        int vecin = aux.first;
        char litera = aux.second;
        if(litera == cuvant[0]){
            string cuvant_nou = cuvant.erase(0,1);
            dfs(vecin,cuvant_nou);
            return;
        }
    }
    acceptat = false;
    //fout << "neacceptat";
    return;
}

void solve(){
    /// citesc un cuvant pe care vreau sa-l verific
    string cuvant;
    f_input >> cuvant;
    dfs(conversie[stare_initiala],cuvant);
    if(acceptat == true){
        fout << "acceptat" << '\n';
        /*for(int i=1;i<=dim_sol;i++){
            fout << sol[i] << '\n';
        }*/
        for(int i=1;i<=dim_drum;i++){
            fout <<  "->" << drum[i];
        }
    } else {
        fout << "neacceptat";
    }
}

int main() {

    citire();
    /// acum am datele procesate si salvate in structuri
    solve();
    return 0;
}
