include <iostream>
using namespace std;

int point_in_sq(double x, double y, double x1, double y1, double x2, double y2){
    return ((((x<=x1) and (x>=x2)) or ((x<=x2) and (x>=x1))) and (((y<=y1) and (y>=y2)) or ((y<=y2) and (y>=y1)))); 
}

int find_last(double a1, double a2, double lim1, double lim2){
    if (((a1<=lim1) and (a1>=lim2)) or ((a1<=lim2) and (a1>=lim1))) return a1;
    if (((a2<=lim1) and (a2>=lim2)) or ((a2<=lim2) and (a2>=lim1))) return a2;
}
int check_points(double ax1, double ay1, double ax2, double ay2, double bx1, double by1, double bx2, double by2){
    double x[2]={0,0},y[2]={0,0};
    bool flagb=false, flaga=false, flagx1=false, flagx2=false, flagy1=false, flagy2=false;
    if (point_in_sq(ax1,ay1,bx1,by1,bx2,by2)==1){
        flaga=true;
        flagx1=true;
        flagy1=true;
        x[0]=ax1;
        y[0]=ay1;
    }
    if (point_in_sq(ax1,ay2,bx1,by1,bx2,by2)==1){
        x[0]=ax1;
        y[1]=ay2;
        flaga=true;
        flagx1=true;
        flagy2=true;
    }
    if (point_in_sq(ax2,ay1,bx1,by1,bx2,by2)==1){
        x[1]=ax2;
        y[0]=ay1;
        flaga=true;
        flagx2=true;
        flagy1=true;
    }
    if (point_in_sq(ax2,ay2,bx1,by1,bx2,by2)==1){
        x[1]=ax2;
        y[1]=ay2;
        flaga=true;
        flagy1=true;
        flagy2=true;
    }

    if (point_in_sq(bx1,by1,ax1,ay1,ax2,ay2)==1){
        x[0]=bx1;
        y[0]=by1;
        flagb=true;
        flagx1=true;
        flagy1=true;
    }
    if (point_in_sq(bx1,by2,ax1,ay1,ax2,ay2)==1){
        x[0]=bx1;
        y[1]=by2;
        flagb=true;
        flagx1=true;
        flagy2=true;
    }
    if (point_in_sq(bx2,by1,ax1,ay1,ax2,ay2)==1){
        x[1]=bx2;
        y[0]=by1;
        flagb=true;
        flagx2=true;
        flagy1=true;
    }
    if (point_in_sq(bx2,by2,ax1,ay1,ax2,ay2)==1){
        x[1]=bx2;
        y[1]=by2;
        flagb=true;
        flagx2=true;
        flagy2=true;
    }
    if (flagb or flaga){
        if (flagx1 and flagx2 and flagy1 and flagy2 == false){
            if (flaga){
                if (!flagx1) x[0]=find_last(bx1,bx2,ax1,ax2);
                if (!flagx2) x[1]=find_last(bx1,bx2,ax1,ax2);
                if (!flagy1) y[0]=find_last(by1,by2,ay1,ay2);
                if (!flagy2) y[1]=find_last(by1,by2,ay1,ay2);
            }
            if (flagb){
                if (!flagx1) x[0]=find_last(ax1,ax2,bx1,bx2);
                if (!flagx2) x[1]=find_last(ax1,ax2,bx1,bx2);
                if (!flagy1) y[0]=find_last(ay1,ay2,by1,by2);
                if (!flagy2) y[1]=find_last(ay1,ay2,by1,by2);
            }
        }
        cout<<"Перетинаються"<<endl<<x[0]<<" "<<y[0]<<" "<<x[1]<<" "<<y[1];
    }
    else{
        cout<<"He перетинаються";
    }
    return -1;
}

int main() {
    cout << " ax1=? ay1=? ax2=? ay2=?";
    double ax1,ay1,ax2,ay2; 
    cin >> ax1>>ay1>> ax2>>ay2;

    cout << endl<<" bx1=? by1=? bx2=? by2=?";
    double bx1,by1,bx2,by2; 
    cin >> bx1>>by1>> bx2>>by2;
    check_points(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);

} 
