#include <conio.h>
#include <iostream>
#include <string.h>
#include<fstream>
#include <cstdlib> 
#include <ctime>
using namespace std; 
  int p = 0,age,sum=0,check=0,m=0,o=0,f=0,a[11]; char gender; void array(){
  	for(int i=0;i<11;i++) a[i]=0;
  }
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void install();
  void allotment(int a[]);
  void empty();
  void show();
  void avail();
  void position(int i);
  void name(); void imp(); void analy(int a[]); void cancel();
}
bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
  cout<<"\n" ;
} 
void a::install()
{fstream fout; 
  
    // opens an existing csv file or creates a new file. 
    fout.open("bus name.csv", ios::out | ios::app); 
  
  cout<<"Enter bus no: ";
  cin>>(bus[p].busn);
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nArrival time: "; 
  cin>>bus[p].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  bus[p].empty(); fout<<bus[p].busn<<","<<bus[p].driver<<","<<bus[p].arrival<<","<<bus[p].depart<<","<<bus[p].from<<","<<bus[p].to<<","<<endl;
  p++;
}
void a::allotment(int a[])
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number; 
  int n;
  for(n=0;n<=p;n++)

  {
 
		 int e=0;for(int i=strlen(number);i>=1;i--) { 	
		 if(bus[n].busn[strlen(bus[n].busn)-i]==number[strlen(number)-i])
		 e++;}
		 if(e==strlen(number)){ 
		 break; } }
  while(n<=p)
  { 
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    { 
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: \n";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        cout<<"enter passenger age \n"; cin>>age; check++; cout<<"enter passenger gender(F/M/O)\n"; cin>>gender; 
		if(gender=='F') f++; else if(gender=='M') m++; else if(gender=='O') o++;
		sum=sum+age; a[n+1]=a[n+1]+1;
		cout<<"YOUR TICKET IS SUCCESSFULLY BOOKED\n";
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }

void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    { 
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<p;n++)

  {  
 
		 int e=0;for(int i=strlen(number);i>=1;i--) { 	
		 if(bus[n].busn[strlen(bus[n].busn)-i]==number[strlen(number)-i])
		 e++;}
		 if(e==strlen(number)){ 
		 break; }}
  
while(n<=p)
{ 
  vline('*');
  cout<<"Bus no: \t"<<bus[n].busn
  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from <<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no ";
}
void a::position(int l)
{
  int s=0;int q=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          q++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<q<<" seats empty in Bus No: "<<bus[l].busn;
  }
void a::avail()
{
  for(int n=0;n<p;n++)
  { cout<<n<<endl;
    vline('*');
    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}
void a::name()
{ for(int n=0;n<p;n++)
{ 
	  int a=1;
  for (int i=0; i<8; i++)
  {
   for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<"  in   "<<bus[n].busn;
    }
  }
}
}
void a::imp()
{ int k=0,x=0;
	ifstream myfile;
	myfile.open("bus name.csv");
	while(myfile.good()){ string line;
	
	getline(myfile,line,',');
	if(x==0) { for(int i=0;i<sizeof(line);i++) bus[k].busn[i]=line[i]; x++;}
else	if(x==1) { for(int i=0;i<sizeof(line);i++) bus[k].driver[i]=line[i];x++;
	} 
else	if(x==2){  for (int i=0;i<sizeof(line);i++) bus[k].arrival[i]=line[i];x++; 
	}
else	if(x==3){ for (int i=0;i<sizeof(line);i++) bus[k].depart[i]=line[i];x++;
	}
else	if(x==4){ for (int i=0;i<sizeof(line);i++) bus[k].from[i]=line[i];x++;
	}
else	if(x==5){ for (int i=0;i<sizeof(line);i++) bus[k].to[i]=line[i]; x=0;	bus[p].empty();	k++;   p=k;
	}
	
} cout<<"buses are successfully imported\n";;}
void a ::analy(int a[])
{ age=sum/check;
cout<<"1)Average Age of Passengers is "<<age<<endl;
if(f>m && f >o)
        cout << "2)Female passengers are higher\n" ;

  else  if(m> f && m >o)
        cout << "2)Male passengers are higher\n";
    
 else   if(o >m && o>f)
        cout << "2)Other passengers are higher\n" ;
        else cout<< "2) NO PROPER CONCLUSION ABOUT THE GENDER CATEGORY\n";
   int max;         max = a[0];
int j=0; int count=0;
    for (j = 0; j < 11; j++)

    {

        if (max < a[j])

            max = a[j];

    } int i=0;
while (i < 10)
    {
        if (a[i] == max) {
            break;
        }
        i++;
    } int k=i;int v=i+1;
    while (k<=check) {
	if (a[k]==a[v])
	count++; v++; k++;
}
 if(a[0]==max||count>0) {
        cout << "3)NO PROPER CONCLUSION ABOUT THE DEMAND OF BUSES TODAY";
    }
   else if (i>0 &&i< 11) { 
        cout<<"3)BUS in highest demand is bus number:"<<bus[i-1].busn<<endl;
    }
 
}
void fb()
{ int fb;
cout<<"Press 1 for Registering a Complaint \nPress 2 for giving Feedback\n";
cin>>fb;
if(fb==1)
{string comp; int cn;
	ofstream outfile;
   outfile.open("complaint.txt", ios::out | ios::app);
	cout<<"describe your complaint, press enter and -1 to exit\n";
	   while (outfile) { 
  
        // Read a Line from standard input 
        getline(cin, comp); 
  
        // Press -1 to exit 
        if (comp == "-1") 
            break; 
  
        // Write line in file 
        outfile << comp<< endl; 
    } 
 cout<<"Your Complaint number is:\t";
   int max;
   max = 100; //set the upper bound to generate the random number
   srand(time(0));
  cn=rand()%max; 
   cout <<cn<<endl;
        outfile<<"complaint number:"<<cn<<endl;

cout<<"Thank You for Writing To us,we will solve your complaint ASAP";
outfile.close();	}	
else	if (fb==2)
	{ int rate;string feedbac;
	ofstream infile;
   infile.open("feedback.txt", ios::out | ios::app);
	cout<<"Please rate us on the rate of 5\n";
	cin>>rate; infile<<"Rating:"<<rate<<endl;
	cout<<"describe your experience, press enter and -1 to exit\n";
	   while (infile) { 
  
        // Read a Line from standard input 
        getline(cin, feedbac); 
  
        // Press -1 to exit 
        if (feedbac == "-1") 
            break; 
  
        // Write line in file 
        infile << feedbac<< endl; 
    } 
	 cout<<"thanks for your valuable feedback\n";
	}
	else cout<<"incorrect input,try again!!\n";
}
void a::cancel()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number; 
  int n;
  for(n=0;n<=p;n++)

  {
 
		 int e=0;for(int i=strlen(number);i>=1;i--) { 	
		 if(bus[n].busn[strlen(bus[n].busn)-i]==number[strlen(number)-i])
		 e++;}
		 if(e==strlen(number)){ 
		 break; } }
  while(n<=p)
  { 
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    { 
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")!=0)
      {
        cout<<"TICKET SUCCESSFULLY CANCELED\n";
        break;
      }
    else
      cout<<"The seat no. is not reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }

int main()
{ array();
int w;
while(1)
{
  cout<<"\n\t\t\t1.Add a Bus\n\t\t\t"
  <<"2.Reserve Seats\n\t\t\t"
  <<"3.Print Seat Info\n\t\t\t"
  <<"4.Show Buses Available\n\t\t\t"
  <<"5.Print Reserved Passengers name\n\t\t\t"<< "6.Import buses of previous day\n\t\t\t"<<"7.Show analysis of the day and shut down\n\t\t\t"
  <<"8.Give Feedback or File a Complaint\n\t\t\t"<<"9.Cancel the reservation\n\t\t\t"
  <<"0.Close The Day";
cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].install();
      break;
    case 2:  bus[p].allotment(a);
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  bus[0].name();
		break;
		case 6:bus[0].imp();
			break;
			case 7: bus[0]. analy(a); exit(0); break;
			case 8: fb(); break;
			case 9: bus[0].cancel(); break;
		case 0: exit(0);
	} }
return 0;
}
