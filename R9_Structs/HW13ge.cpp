#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Human
{
    string firstname;
    string surname;
    string sex;
    int date_of_birth[3];

};

Human hum_input(Human hum)
{
    printf("Enter the firstname and surname  ");
    cin >> hum.firstname >> hum.surname;
    printf("Enter the sex ");
    cin >> hum.sex;

    printf("Enter the date of birth ");
    for(int i = 0; i < 3; i++)
    {
        cin >> hum.date_of_birth[i];
    }

    return hum;
}

void print_hum(Human hum)
{
    cout << hum.firstname << " " << hum.surname <<
    " " << hum.sex << " " << hum.date_of_birth[0] <<
    " " << hum.date_of_birth[1] << " " <<
    hum.date_of_birth[2];
}


int main()
{
    int n;
    int k = 0;
    int k1 = 0;
    printf("Enter the count of people ");
    scanf("%d",&n);

    Human count_of_hum[n];
    Human count_of_man[n];
    Human count_of_woman[n];
    Human hum;
    Human the_oldest;

    int m = 60; //пенсійний вік для чоловіків
    int w = 55; //пенсійний вік для жінок



    for(int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " human " << endl;
        count_of_hum[i] = hum_input(hum);
    }


    for (int i = 0; true; i++)
    {
        if( i > n)
            break;
        else
            if(count_of_hum[i].sex == "man");
                {
                    the_oldest = count_of_hum[i];
                    break;
                }
    }


    for(int i = 0; i < n; i++)
    {
        if(count_of_hum[i + 1].sex == "man")    
            if(the_oldest.date_of_birth[2] > count_of_hum[i + 1].date_of_birth[2])
                the_oldest = count_of_hum[i + 1];
            else
                if(the_oldest.date_of_birth[2] == count_of_hum[i + 1].date_of_birth[2])
                    if(the_oldest.date_of_birth[1] > count_of_hum[i + 1].date_of_birth[1])
                        the_oldest = count_of_hum[i + 1];
                    else
                        if(the_oldest.date_of_birth[1] == count_of_hum[i + 1].date_of_birth[1])
                            if(the_oldest.date_of_birth[0] > count_of_hum[i + 1].date_of_birth[0])
                                the_oldest = count_of_hum[i + 1];  
    }

int j = 0;
int b = 0;
    for(int i = 0; i < n; i++)
    {
        if(count_of_hum[i].sex == "man" )
            if((2021 - count_of_hum[i].date_of_birth[2]) >= m)
                {
                count_of_man[j] = count_of_hum[i];
                k += 1;
                j += 1;
                }

        if(count_of_hum[i].sex == "woman")
            if((2021 - count_of_hum[i].date_of_birth[2]) >= w)
                {
                    count_of_woman[b] = count_of_hum[i];
                    k1 += 1; 
                    b += 1;
                }
    }        


    for(int i = 0; i < n; i++)
    {
        print_hum(count_of_hum[i]);
        printf("\n");
    }

    cout << endl;

    printf("Retired men - > ");
    printf("\n");
    for(int j = 0; j < k; j++)
    {
        print_hum(count_of_man[j]);
        printf("\n");
    }
    cout << endl;

    printf("Retired women - > ");
    printf("\n");
    for(int b = 0; b < k1; b++)
    {
        print_hum(count_of_woman[b]);
        printf("\n");
    }
   cout << endl;

    printf("The oldest man - > ");
    print_hum(the_oldest);



