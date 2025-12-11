#include <iostream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

unordered_map<char,pair<string,string>>protein_map = {
    {'A', {"Ala", "Alanine"}},
    {'C', {"Cys", "Cysteine"}},
    {'D', {"Asp", "Aspartic Acid"}},
    {'E', {"Glu", "Glutamic Acid"}},
    {'F', {"Phe", "Phenylalanine"}},
    {'G', {"Gly", "Glycine"}},
    {'H', {"His", "Histidine"}},
    {'I', {"Ile", "Isoleucine"}},
    {'K', {"Lys", "Lysine"}},
    {'L', {"Leu", "Leucine"}},
    {'M', {"Met", "Methionine"}},
    {'N', {"Asn", "Asparagine"}},
    {'P', {"Pro", "Proline"}},
    {'Q', {"Gln", "Glutamine"}},
    {'R', {"Arg", "Arginine"}},
    {'S', {"Ser", "Serine"}},
    {'T', {"Thr", "Threonine"}},
    {'V', {"Val", "Valine"}},
    {'W', {"Trp", "Tryptophan"}},
    {'Y', {"Tyr", "Tyrosine"}}
};
 bool isvalidresidue(char residue){
     residue = toupper(residue);
     return protein_map.find(residue) != protein_map.end();
 }
 bool isvalidsequence(const string& sequence){
 if (sequence.empty()) return false;
 for (char residue : sequence) {
     if (!isvalidresidue(residue)) {
         return false;
    }
  }
  return true;
}

string tothreelettercode(char residue){
    residue = toupper(residue);
    auto it = protein_map.find(residue);
    if (it != protein_map.end()) {
        return it->second.first;
    }
    return "???";
}

string tofullnamcode(char residue){
    auto it = protein_map.find(residue);
    if (it != protein_map.end()) {
        return it->second.second;
    }
    return "UNK";
}

string outputsequence(const string& sequence, bool fullname){
    string result;
    for (char residue : sequence) {
        if (fullname) {
            result += tofullnamcode(residue) + " ";
        } else {
            result += tothreelettercode(residue) + " ";
        } 
    }
    return result;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << "the file " << endl;
        return 1;
    }

    bool Fullname = false;
    if (argc == 3 && string(argv[2]) == "--fullnames") {
    Fullname = true;
    }
   // string seq1 = "ACDEFGHIKLMNPQRSTVWY";
   // string seq2 = "ACDXYZ";

   // cout << "Sequence 1 is " << (isvalidsequence(seq1) ? output3lettersequence(seq1) : "invalid") << endl;
   // cout << "Sequence 2 is " << (isvalidsequence(seq2) ? output3lettersequence(seq2) : "invalid") << endl;
   string filename = argv[1];
   ifstream file(filename);
    if (!file.is_open()) {cout << "Error opening file: " << filename << endl;
        return 1;
    }
    string line;
    int line_number = 0;
    while (getline(file,line)){
    cout << "Line " << ++line_number << endl;
        if (isvalidsequence(line)) {
            cout << outputsequence(line,Fullname) << endl;
        } else {
            cout << "invalid sequence" << endl;
        }
    }
    
    return 0;
}