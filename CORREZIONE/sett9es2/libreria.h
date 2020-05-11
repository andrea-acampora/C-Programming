#ifndef Gestione_Liste_Varie
#define Gestione_Liste_Varie

//Liste
	struct libro
    {
        int anno_pubb;
        int lunghezza;
        int codice;
		int valutazione;
		char *titolo;
		char *autore;
		char *casa_ed;
		char *genere;
		//
        struct libro *next;
    };

    int aggiungiLibro(struct libro **t, char *titolo, char *autore, int anno_pubb, char *casa_ed, int lunghezza, char *genere, int codice, int valutazione);
    void stampaTuttiLibri(struct libro *t);
	void stampaLibriValutazione(struct libro *t, int valutazione2);
    int cercaLibro(struct libro *t, int numero);
    int eliminaLibro(struct libro **t, int codice2);
    void resetLista(struct libro **t);
#endif
