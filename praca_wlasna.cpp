#include <iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;

int *utworz( const unsigned N)
{
	int *T=new int [N];
	for(unsigned i=0; i<N;i++)
	T[i]=0;
	return T; 
}



void wypisz(int *T, const unsigned N)
{
	for(unsigned i=0; i<N; i++)
	{
		cout<<T[i]<<" ";
	}
	cout<<endl;
}

void usun(int *T)
{
	if(T)
	{
		delete [] T;
		T=nullptr;
	}
}

void usun1(char *T)
{
	if(T)
	{
		delete [] T;
		T=nullptr;
	}
}

void kopiuj(char *T, const string zrodlo)
{
	size_t p = zrodlo.copy(T,zrodlo.size()); //funkcja copy oraz size
	T[p]='\0';
	
}

int suma(int *a, int *b)
{
	return *a+*b;	
}

bool zapisywanie(ofstream &fout,string &opis)
{
    if (fout.good())
    {
    fout<<opis<<endl;
    cout<<opis;
    fout.close();
    return true;
    }
    fout.clear();
    return false;
}

int suma1(const int *T, const unsigned int n)
{int suma=0;
for (unsigned int i=0; i<n; i++)
	if(i%2)
    		suma+=T[i];
return suma;
}

int dlugosc_wyrazu(const char *napis)
{
	unsigned licznik=0;
	while(napis[licznik]!='\0')
	{
	
	
		licznik++;
	}
	return licznik;
}

void losowanie (int *&T, const unsigned N, unsigned maximum)
{
	for(unsigned i=0;i<N;i++)
	{
		T[i]=rand()%(maximum+1);
	}
}

int **utworz_dwu(unsigned M, unsigned N)
{
	int **T=new int *[M];
	for (unsigned i=0; i<M;i++)
		T[i]=new int [N];
	for (unsigned i=0; i<M;i++)
		for (unsigned j=0; j<N;j++)
			T[i][j]=0;
	return T;
}

void usun_dwu(int ** T,unsigned M)
{
	if (T)
	{
		for (unsigned i=0; i<M; i++)
			delete [] T[i];
		delete [] T;
		T=nullptr;	
	}
}

void wypisz_dwu( int **T, unsigned M, unsigned N)
{
	for (unsigned i=0; i<M; i++)
		for (unsigned j=0; j<N; j++)
			cout<<"T["<<i<<"]["<<j<<"]="<<T[i][j]<<endl;
}

void losowanie(int **T, unsigned M, unsigned N, unsigned mini, unsigned maxi)
{
	for(unsigned i=0; i<M; i++)
		for(unsigned j=0; j<N ; j++)
		T[i][j]=rand()%(maxi-mini+1)+mini;
}

void zamiana(int &aq, int &bq)
{
	int pom=aq;
	aq=bq;
	bq=pom;
}

int **wykonywanie_dodawania(int **T1, int **T2, unsigned M, unsigned N)
{
	int **T3=new int *[M];
	for (unsigned i=0; i<M; i++)
	T3[i]=new int [N];
	//wyzerowanie
	for (unsigned i=0; i<M; i++)
	for (unsigned j=0; j<N; j++)
		{T3[i][j]=0;
		T3[i][j]=T1[i][j]+T2[i][j];
		}
		
	return T3;
}

bool wczytywanie_z_pliku(ifstream &fin , string &opis)
{
	if(fin.good())
	{
	
	fin>>opis;
	fin.close();
	return true;
	}
	fin.clear();
	return false;
}

int main(int argc, char ** argv)
{
if (argc!=4)
	{
		cerr<<"Zla liczba argumentow";
		cerr<<"./nazwa wyraz_do_skopiowania wczytanie.txt zapisywanie.txt"<<endl;
		return -1;
	}
srand(time(NULL));
unsigned n,maxi;
cout<<"Podaj liczbe elementow tablicy: ";
cin>>n;
cout<<"Podaj maksimum tablicy: ";
cin>>maxi;
//dynamiczny przydzial pamieci dla tablicy jednowymiarowej wraz zwalnianiem na stercie oraz losowaniem losowych wartosci
int *tab=utworz(n);
wypisz(tab,n);
losowanie(tab,n,maxi);
wypisz(tab,n);
//kopiowanie danego wyrazenia czyli korzystanie z funkcji wbudowanych char* /string
string src=argv[1];
char *napis=nullptr;
napis=new char [src.size()+1];
kopiuj(napis, src);
//przekazywanie poprzez wskaznik
int a,b;
cout<<"Podaj pierwsza liczbe do obliczenia jej sumy: ";
cin>>a;
cout<<"Podaj druga liczbe: ";
cin>>b;
cout<<"Suma wynosi: "<<suma(&a,&b);
//wykonywanie roznych operacji na tablicach 
suma1(tab,n);
cout<<endl;
usun(tab);
usun1(napis);

//tworzenie tablicy dwuwymiarowej i usuwanie tablicy na stercie
cout<<"Na ocene dobra. Podaj dwuwymiarowa tablice (czyli liczbe wierszy i kolumn). "<<endl;
cout<<"Podaj liczbe wierszy: ";
unsigned m;
cin>>m;
cout<<"Podaj liczbe kolumn: ";
cin>>n;
int **tab_dwu=utworz_dwu(m,n);
wypisz_dwu(tab_dwu, m, n);
//losowanie liczb pseudowlowych
cout<<"Podaj przedzial <min, max>, z ktorego beda losowne liczby pseudolosowe: ";
unsigned mini;
cin>>mini;
cin>>maxi;
losowanie(tab_dwu, m, n, mini, maxi);
wypisz_dwu(tab_dwu, m, n);
//referencja
cout<<"Referencja. Podaj argumenty aby zamienic je ze soba poprzez referencje. ";
cin>>a;
cin>>b;
zamiana(a,b);
cout<<"Pierwsza liczba ktora zostala podana zostala zamieniona na: "<<a<<" a druga zostala zamieniona na: "<<b;
cout<<endl;

//wykonywanie dzialania na tablicach
int **tab_dwu2=utworz_dwu(m,n);
losowanie(tab_dwu2, m, n, mini, maxi);
cout<<"Wykonane dzialanie na tablicy to dodawanie macierzy. Wynik dodawania randomowych liczb to"<<endl;
int **tab_dwu3=wykonywanie_dodawania(tab_dwu, tab_dwu2, m, n);
wypisz_dwu(tab_dwu3, m, n);
usun_dwu(tab_dwu, m);
usun_dwu(tab_dwu2, m);
usun_dwu(tab_dwu3, m);
//wczytywanie z pliku
cout<<"W pliku znajduje sie taki zestaw znakow"<<endl;
ifstream fin(argv[2]);
string opis="";
if(!wczytywanie_z_pliku(fin, opis))
{	
	cerr<<"Blad otwarcia pliku wejsciowego \n";
	return -10;
}
//zapisywanie do pliku
ofstream fout;
fout.open(argv[3]);
if(!zapisywanie(fout,opis))
{
	cerr<<"Blad zapisu danych do pliku \n";
	return -20;	
}



	return 0;
	
}
