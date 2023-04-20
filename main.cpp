#include <iostream>

class No final {
  public:
    ~No() {
      delete esquerda;
      delete direita;
    }
    int fb; // fator de balanceamento
    int chave;
    No* esquerda = NULL;
    No* direita = NULL;
};

class ArvoreAVL final {
  public:
    ArvoreAVL(No* r) : raiz(r) {}
    ~ArvoreAVL() {
      delete raiz;
    }

    No* getRaiz() { return raiz; }
    void setRaiz(No* r) { raiz = r; }

    void imprimir() {
      if (raiz) {
        ArvoreAVL esquerda(raiz->esquerda);
        esquerda.imprimir();
        ArvoreAVL direita(raiz->direita);
        direita.imprimir();
        std::cout << raiz->chave << ' ';
      }
    }

  private:
    No* raiz = NULL;     
};

void rotacao_esquerda_simples(No* p) {
  No* q = p->direita;
  p->direita = q->esquerda;
  q->esquerda = p;
}

void rotacao_direita_simples(No* p) 
{
  No* q = p->esquerda;
  p->esquerda = q->direita;
  q->direita = p;
}

void rotacao_esquerda_dupla(No* p) {
  No* q = p->direita;
  No* r = q->esquerda;
  p->direita = r->esquerda;
  q->esquerda = r->direita;
  r->esquerda = p;
  r->direita = q;
}

void rotacao_direita_dupla(No* p) {
  No* q = p->esquerda;
  No* r = q->direita;
  p->esquerda = r->direita;
  q->direita = r->esquerda;
  r->direita = p;
  r->esquerda = q;
}