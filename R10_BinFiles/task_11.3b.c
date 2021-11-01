#include <stdio.h>
#include <iostream>

using namespace std;

bool check(unsigned n)
{
    unsigned t = 1;
    while (t < n) t *= 3;
    return t == n;
}

void print_file(char* filename)
{
    FILE* fin = fopen(filename, "rb");
    unsigned tmp;
    while (!feof(fin))
    {
        if (!fread(&tmp, sizeof(tmp), 1, fin)) break;
        cout << tmp << endl;
    }
    fclose(fin);
}

void input_file(char* filename)
{
    FILE* f = fopen(filename, "wb");
    unsigned tmp;
    while (1)
    {
        cin >> tmp;
        if (tmp == 0) break;
        fwrite(&tmp, sizeof(tmp), 1, f);

    }
    fclose(f);
}

void create_file(char* inp_name, char* out_name)
{
    FILE* fin = fopen(inp_name, "rb");
    FILE* fout = fopen(out_name, "wb");
    unsigned tmp;
    while (!feof(fin))
    {
        if (!fread(&tmp, sizeof(tmp), 1, fin)) break;
        if (check(tmp)) fwrite(&tmp, sizeof(tmp), 1, fout);
    }
    fclose(fin);
    fclose(fout);
}

int main()
{
    char fin[20] = "F";
    char fout[20] = "G";
    input_file(fin);
    create_file(fin, fout);
    print_file(fin);
    cout << endl;
    print_file(fout);
}
