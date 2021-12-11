#include <iostream>
using namespace std;
class Fgr {
    public:
        virtual float get_s() = 0;
};

class rct: public Fgr {
    public:
        float w;
        float h;
        void set_w(float wn) {
            w = wn;
        }
        void set_h(float hn) {
            h = hn;
        }
        float get_s() {
            return (w * h);
    }
};

class crcl: public Fgr {
    public:
        float r;
        void set_r(float rn) {
            r = rn;
        }
        float get_s() {
            return (r * r * 3.14);
    }
};

int main() {
    rct rect;
    crcl crcls[4];
    int i;
    float s_cur, s_total = 0, n, m;
    printf("rct: \n");
    printf("n = ");
    scanf("%f", &n);     
    printf("m = ");
    scanf("%f", &m);
    rect.set_w(n);
    rect.set_h(m);
    s_total += rect.get_s();
    for(i = 0; i < 4; i++){
        printf("circle %d: \n", i+1);
        printf("r = ");
        scanf("%f", &n);
        crcls[i].set_r(n);
        s_total += crcls[i].get_s();
    }
    printf("\nS_total = %f", s_total);
}