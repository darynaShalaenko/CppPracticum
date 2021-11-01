

typedef struct T_Match{
  unsigned char n1, n2; // numbers of teams
  unsigned char b1, b2; // scores
} T_Match;

int inputMatch(T_Match* res);

int setMatch(T_Match* t, unsigned char n1, unsigned char n2, unsigned char b1,unsigned char b2);

void showMatch(const T_Match* res);

int addMatchToFile(const char* fname, const T_Match* res);

int addMatchesToFile(const char* fname, const T_Match* res, size_t n_matches);

void showFileMatches(const char* fname);



