#include <iostream>
#include<math.h>
#include<locale.h>
#include<vector>
#include<string>

using namespace std;

//FUNKCJA NAJWIEKSZEGO WSPOLNEGO DZIELNIKA
int NWD(int a,  int b)
{
    if (b == 0)
    {
      return abs(a);
    }
    
    else 
    {
        while (a != b)
        {
            if (a > b)
                a=a- b;

            else
                b = b - a;
        }
         return a;
    }
}



//RÓWNANIE DIOFANTYCZNE LINIOWE 
//FUNCKJA WYŚWIETLA X0, Y0, X, Y
void row_diofantyczne(int a, int b,int c)
{
        int nwd = NWD(abs(a), abs(b));
        int g = c / nwd;
        int ax = a, bx = b;
        int r, q;
        int x0 = 1, y0 = 1;

        // szczególny przypadek
        
        if (a + b == c)
        {
            cout << "x0= " << x0 << endl;
            cout << "y0= " << y0 << endl;

            cout << "ogół rozwiązań" << endl;
            cout << "x= " << x0 << "+" << bx / nwd << "t" << endl;
            cout << "y= " << y0 << "-" << ax / nwd << "t" << endl;
        }

    else
        {
            vector<int>l_dzielniki;

            
            if (abs(c) % nwd == 0)
            {
                //kiedy a lub =0
                if (b == 0)
                {
                    y0 = 0;
                    x0 = c / a;
                    cout << "x0= " << x0 << endl;
                    cout << "y0= " << y0 << endl;
                    cout << "ogół rozwiązań" << endl;

                    
                    cout << "x= " << x0 << "+" << bx / nwd << "t" << endl;

                    cout << "y= " << y0 << "-" << ax / nwd << "t" << endl;
                }
                


                else {
                    //utworzenie tablicy z q (dzielniki)

                    if (a > b)
                    {
                        for (r = a % b; r != 0; r = a % b)
                        {
                            q = a / b;
                            l_dzielniki.push_back(q);
                            a = b;
                            b = r;
                        }
                    }
                    else
                    {
                        for (r = b % a; r != 0; r = b % a)
                        {
                            q = b / a;
                            l_dzielniki.push_back(q);
                            b = a;
                            a = r;
                        }
                    }

                    vector<int>x0;
                    int u;
                    vector<int>y0;
                    int w;
                    int x_0, y_0;

                    // liczenie x0 i y0 jezeli a>b
                    if (abs(a) > abs(b))
                    {
                        x0.push_back(1);
                        x0.push_back(0);

                        for (int i = 0; i < l_dzielniki.size(); i++)
                        {
                            u = x0[i] - (l_dzielniki[i] * x0[i + 1]);
                            x0.push_back(u);
                        }

                        y0.push_back(0);
                        y0.push_back(1);

                        for (int i = 0; i < l_dzielniki.size(); i++)
                        {
                            w = y0[i] - (l_dzielniki[i] * y0[i + 1]);
                            y0.push_back(w);
                        }

                        reverse(x0.begin(), x0.end());
                        reverse(y0.begin(), y0.end());
                        for (int j = 0; j < 1; j++)
                        {
                            x_0 = x0[j] * g;
                            y_0 = y0[j] * g;
                        }
                    }


                    //liczenie x0 i y0 jezeli b>a
                    else
                    {
                        x0.push_back(0);
                        x0.push_back(1);

                        for (int i = 0; i < l_dzielniki.size(); i++)
                        {
                            u = x0[i] - (l_dzielniki[i] * x0[i + 1]);
                            x0.push_back(u);
                        }


                        y0.push_back(1);
                        y0.push_back(0);

                        for (int i = 0; i < l_dzielniki.size(); i++)
                        {
                            w = y0[i] - (l_dzielniki[i] * y0[i + 1]);
                            y0.push_back(w);
                        }


                        reverse(x0.begin(), x0.end());
                        reverse(y0.begin(), y0.end());
                        for (int j = 0; j < 1; j++)
                        {
                            x_0 = x0[j] * g;
                            y_0 = y0[j] * g;

                        }
                    }
                    //wyswietlenie x0 i y0
                    if (ax < 0 && bx < 0)
                    {
                        x_0 *= -1;
                        y_0 *= -1;
                        cout << "x0= " << x_0 << endl;
                        cout << "y0= " << y_0 << endl;
                        cout << endl;
                    }
                    else
                    {
                    cout << "x0= " << x_0 << endl;
                    cout << "y0= " << y_0 << endl;
                    cout << endl;
                    }
                    

                  
                    
                   
                    //ogół rozwiązań
                    int x, y;
                    x = bx / nwd; 
                    y = ax / nwd;
                    cout << "ogół rozwiązań" << endl;

                    if (x >= 0 && y>=0)
                    {
                        cout << "x= " << x_0 << "+" << x << "t" << endl;
                       
                        cout << "y= " << y_0 << "-" << y << "t" << endl;
                    }

                    else if (x <0 && y>= 0)
                    {
                        cout << "x= " << x_0 << x << "t" << endl;
                        
                        cout << "y= " << y_0 << "-" << y << "t" << endl;
                    }

                    else if (x >= 0 && y < 0)
                    {
                        cout << "x= " << x_0 << "+" << x << "t" << endl;

                        cout << "y= " << y_0 << "+" << y * (-1) << "t" << endl;
                    }

                    else if (x < 0 && y < 0)
                    {
                        cout << "x= " << x_0 << x << "t" << endl;

                        cout << "y= " << y_0 << "+" << y*(-1) << "t" << endl;
                    }
                    
                   


                }
            }

            else
                cout << "równanie nie ma rozwiązania" << endl;
            

    }
     
}



int main()
{
    setlocale(LC_CTYPE, "Polish");
  
    int a, b,c;
    do {
        cout << "a= "; cin >> a;
        cout << "b= "; cin >> b;
        cout << "c= "; cin >> c;

        // sprawdzenie czy sa =0
        if (a == 0 && b!=0)
        {
            cout << "równanie nie ma rozwiązania" << endl;
            cout << "__________________________________________________________________" << endl;
            cout << endl;

        }

        else if (a == 0 && b == 0)
        {
            if (c == 0)
            {
                cout << "równanie ma nieskończenie wiele rozwiązań" << endl;
                cout << "__________________________________________________________________" << endl;
                cout << endl;
            }
            else
            {
                cout << "równanie nie ma rozwiązania" << endl;
                cout << "__________________________________________________________________" << endl;
                cout << endl;
            }
        }
        else
        {

            cout << a << "x+" << b << "y=" << c << endl;
            cout << endl;
            cout << "NWD(" <<a << "," << b<< ")=" << NWD(abs(a), abs(b)) << endl;
            cout << endl;
            row_diofantyczne(a, b, c);
           
            cout << "__________________________________________________________________"<<endl;
            cout << endl;
        }

    } while (true);
   

    return 0;


}

