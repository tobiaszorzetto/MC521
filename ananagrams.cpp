#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool my_compare(string a, string b) {
  // If any string is a substring then
  // return the size with greater length
  if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0)
    return a.size() > b.size();

  // Else return lexicographically
  // smallest string
  else
    return a < b;
}

bool isValid(string palavra, vector<string> palavras) {
  bool printar = true;
  bool igual = false;
  for (string item : palavras) {
    bool igual = true;
    if (item != palavra && palavra.size() == item.size()) {
      for (char caracter : item) {
        if (count(item.begin(), item.end(), tolower(caracter)) +
                count(item.begin(), item.end(), toupper(caracter)) !=
            count(palavra.begin(), palavra.end(), tolower(caracter)) +
                count(palavra.begin(), palavra.end(), toupper(caracter))) {
          igual = false;
          break;
        }
      }
      if (igual) {
        return false;
      }
    }
  }

  return true;
}

void solution(vector<string> frases) {
  string palavra = "";
  vector<string> palavras;
  for (int j = 0; j < frases.size(); j++) {
    for (int i = 0; i < frases[j].size(); i++) {
      if (frases[j][i] == ' ') {
        if (palavra != "") {
          palavras.push_back(palavra);
        }
        palavra = "";
      } else {
        palavra += frases[j][i];
      }
    }
    if (palavra != "") {
      palavras.push_back(palavra);
    }
    palavra = "";
  }
  vector<string> palavrasPrint;
  for (int i = 0; i < palavras.size(); i++) {
    if (isValid(palavras[i], palavras)) {
      palavrasPrint.push_back(palavras[i]);
    }
  }
  sort(palavrasPrint.begin(), palavrasPrint.end(), my_compare);
  for (int i = 0; i < palavrasPrint.size(); i++) {
    cout << palavrasPrint[i] << endl;
  }
}

int main() {
  vector<string> frases;
  while (true) {
    string frase;
    getline(cin, frase);
    if (frase == "#")
      break;
    frases.push_back(frase);
  }

  solution(frases);
}