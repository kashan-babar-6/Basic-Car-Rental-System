#include<iostream>
#include<fstream>
using namespace std;
void display(){
	    cout<<"\n     RENT A CAR  ";
		cout<<"\n\t Press 1 for Honda car"<<endl;
		cout<<"\t Press 2 for Corolla car"<<endl;
		cout<<"\t Press 3 for Wagon-R car"<<endl;
		cout<<"\t Press 4 for Kia car"<<endl;
		cout<<"\t Press 0 for Exit"<<endl;
}
	int rent(int a){
		int b,time,hours,days,months;
			cout<<"\t Press 1 for time in hours: "<<endl;
			cout<<"\t Press 2 for time in days: "<<endl;
			cout<<"\t Press 3 for time in months: "<<endl;
			cin>>time;
			if(time==1) {
				cout<<"\t How much Hour do you need: "<<endl;
				cin>>hours;
				b=a*hours;
			}
			if(time==2) {
				cout<<"\t How much Days do you need: "<<endl;
				cin>>days;
				b=a*(days*24);
			}
			if(time==3) {
				cout<<"\t How much Months do you need: ";
				cin>>months;
				b=a*(months*30*24);
				
			}
			return b;
	}
	void read(){
		int tim,fine,early,late,bill;
		string check,names;
            int d,b;
            cout<<"ENTER THE NAME : "<<endl;
            cin>>names;
		ifstream file("customer_records.txt");
	while(!file.eof()){
	file>>check;
	if(check==names){
		cout<<" NAME : " << check;
		file>>d;
		cout<<"   DATE : "<<d;
		file>>b;
		cout<<"  BILL  : "<<b<<endl;
	}}
		cout<<"\nuser is on time press 1"<<endl;	
		cout<<"\nif user is late press 2"<<endl;
    	cin>>tim;
    	if(tim==1){	
    		cout<<names<<" your bill is "<<bill;
			}
		else if(tim==2){
			cout<<"HOURS YOU LATE : ";
			cin>>fine;
			fine=fine*100;
			cout<<"YOUR FINE IS "<<fine<<endl;
			cout<<"YOUR final BILL IS "<<b+fine<<endl;
			}
		

	file.close();
}
int main(){
	
	int choose,n,bill=0,date;
	string name,time;
	int a;
	do{
			cout<<"ENTER 1 TO CHECK THE COUSTOMER DETAIL AND 2 FOR RENT a car  : ";
	cin>>a;
	if(a==1){
			read();
	}
	else{
	    cout<<"\nENTER YOUR NAME : " ;
	    cin>>name;
	    cout<<"Enter the date in which user rent the car : ";
		cin>>date;
	     display();	
       	cin>>choose;
		if(choose==1){
				bill=rent(500);
		}
		else if(choose==2)	{
			bill=rent(200);
		}
		else if (choose==3){
			bill=rent(300);		
		}
		else if (choose==4){
			bill=rent(400);		
		}
		    cout<<name<<" your bill is "<<bill<<endl;
		    ofstream fil("customer_records.txt",ios::app);
		    fil<<name<<" ";
		    fil<<date<<" ";
		    fil<<bill<<"\n";
		    fil.close();
			cout<<"\n\nPress 1 to again calculate and 0 for exit  : ";
			cin>>n;
			system("CLS");
	}}while(n!=0);
	return 0;	
}
