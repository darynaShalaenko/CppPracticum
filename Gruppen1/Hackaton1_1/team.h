
typedef struct Team{
   char* team_name;
   unsigned number;
} Team;

int createTeam(Team* t);

int setTeam(Team* t, const char* name, unsigned m);

int inputTeam(Team* t);

void deleteTeam(Team* t);

int addTeamToFile(const char* fname, const Team* t);

int addTeamsToFile(const char* fname, const Teams* res, size_t n_teams);

void showFileMatches(const char* fname);


