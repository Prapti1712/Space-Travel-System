#include<iostream>
#include<cmath>
using namespace std;
class Planet{
public:
float Position_X, Position_Y, Position_Z;
char Name;
float get_X(void){
return Position_X;}
void update_X(float X){
Position_X=X;}
float get_Y(void){
return Position_Y;}
void update_Y(float Y){
Position_Y=Y;}
float get_Z(void){
return Position_Z;}
void update_Z(float Z){
Position_Z=Z;}
char get_name(void){
return Name;}
void update_name(char name){
Name=name;}
};
class Ticket{
private:
int Price;
public:
Planet Source_Station, Destination_Station;
char Traveller_Name;
int B_Date, T_Date;
void bookTicket(void);
void cancelTicket(void);
void updateTicket(int price, Planet destination, char name, int date){
Price=price;
Destination_Station.Name=destination.Name;
Traveller_Name=name;
T_Date=date;}
int getPrice(void){
Price=((int)sqrt((Source_Station.Position_X-Destination_Station.Position_X)*(Source_Station.Position_X-Destination_Station.Position_X)+(Source_Station.Position_Y-Destination_Station.Position_Y)*(Source_Station.Position_Y-Destination_Station.Position_Y)+(Source_Station.Position_Z-Destination_Station.Position_Z)*(Source_Station.Position_Z-Destination_Station.Position_Z)))/(T_Date-B_Date+1);
return Price;}
void updatePrice(Planet destination, int t_date){
update_destination_station(destination);
update_t_date(t_date);
Price=getPrice();}
Planet get_source_station(void){
return Source_Station;}
void update_source_station(Planet source){
Source_Station.Name=source.Name;}
Planet get_destination_station(void){
return Destination_Station;}
void update_destination_station(Planet destination){
Destination_Station.Name=destination.Name;}
char get_traveller_name(void){
return Traveller_Name;}
void update_traveller_name(char traveller){
Traveller_Name=traveller;}
int get_b_date(void){
return B_Date;}
void update_b_date(int b_date){
B_Date=b_date;}
int get_t_date(void){
return T_Date;}
void update_t_date(int t_date){
T_Date=t_date;}
};
class Traveller{
public:
char Name;
Ticket list_of_ticket;
int ID;
private:
int Traveller_id;
public:
char getName(void){
return Name;}
void updateName(char name){
Name=name;}
void update_ticket(int price, Planet destination_station, char traveller_name, int date){
list_of_ticket.updatePrice(destination_station,date);
list_of_ticket.Destination_Station.Name=destination_station.Name;
list_of_ticket.Traveller_Name=traveller_name;
list_of_ticket.T_Date=date;}
int getId(void){
return Traveller_id;}
int verifyId(void){
int count=0;
while(ID!=0){
ID=ID/10;
count++;}
if(count==10) return 1;
return 0;}
Ticket get_ticket(void){
return list_of_ticket;}
void updateId(int id){
ID=id;}
};
class Astronaut: public Traveller{
private:
int Experience; Ticket A;
public:
void update_experience(int years){
Experience=years;}
int get_experience(void){
return Experience;}
void update_ticket(int price, Planet destination_station, char traveller_name, int date){
A.updatePrice(destination_station,date);
A.Destination_Station.Name=destination_station.Name;
A.Traveller_Name=traveller_name;
A.T_Date=date;}
Ticket get_ticket(void){
return A;}
};
class Passenger: public Traveller{
private:
int Validity; Ticket P;
public:
void update_validity(int validity){
if(validity<=10)
Validity=validity;}
int get_validity(void){
return Validity;}
void update_ticket(int price, Planet destination_station, char traveller_name, int date){
P.updatePrice(destination_station,date);
P.Destination_Station.Name=destination_station.Name;
P.Traveller_Name=traveller_name;
P.T_Date=date;}
Ticket get_ticket(void){
return P;}
};
class Commander: public Traveller{
private:
int Authority; Ticket C;
public:
int Experience, LicenseId;
char List_of_commander;
void update_authority(void){
Authority=LicenseId;}
int get_authority(void){
return Authority;}
void update_experience(int years){
Experience=years;}
int get_experience(void){
return Experience;}
void update_LicenseId(int license_id){
LicenseId=license_id;}
int get_LicenseId(void){
return LicenseId;}
void update_list_of_commander(int commander){
List_of_commander=commander;}
char get_list_of_commander(void){
return List_of_commander;}
void update_ticket(int price, Planet destination_station, char traveller_name, int date){
C.updatePrice(destination_station,date);
C.Destination_Station.Name=destination_station.Name;
C.Traveller_Name=traveller_name;
C.T_Date=date;}
Ticket get_ticket(void){
return C;}
};
class Space_Travel{
private:
Traveller traveller[10];
Astronaut A; Commander C;
public:
Traveller* add_travellers(int n, Traveller travel[]){
int i;
for(i=0; i<n; i++){
traveller[i]=travel[i];}
return traveller;}
void list_travellers(int n){
int i;
for(i=0; i<n; i++)
cout<<"Price: %d "<<traveller[i].list_of_ticket.getPrice()<<"Source Station: %c "<<traveller[i].list_of_ticket.Source_Station.Name<<"Destination Station: %c "<<traveller[i].list_of_ticket.Destination_Station.Name<<"Traveller Name: %c "<<traveller[i].list_of_ticket.Traveller_Name<<"Booking Date: %d "<<traveller[i].list_of_ticket.B_Date<<"Travel Date: %d"<<traveller[i].list_of_ticket.T_Date<<endl;}
void set_astronaut_id(int astro_id){
A.ID=astro_id;}
void set_commander_id(int commander_id){
C.ID=commander_id;}
void update_astronaut_id(int astro_id){
A.ID=astro_id;}
void change_commander_id(int commander_id){
C.ID=commander_id;}
};

int main(){
Planet P1, P2, P3, P4, P5, P6, P7;
Astronaut A1, A2;
Commander C1, C2;
Passenger P[11];
Ticket T1, T2;
char name1, name2;
int i, count=0, j;
for(i=0; i<11; i++){
count=0; int index[7]={0};
T1=P[i].get_ticket();
P3=T1.Source_Station;
P4=T1.Destination_Station;
for(j=i+1; j<11; j++){
T2=P[j].get_ticket();
P5=T2.Source_Station;
P6=T2.Destination_Station;
if(P3.Name==P5.Name&&P4.Name==P6.Name&&T1.T_Date==T2.T_Date) {count++; index[count-1]=j;}}
if(count>1&&count<8){
Space_Travel S;
Traveller travel[count+3], *Travel;
for(j=0; j<count+3; j++){
if(j==0) travel[j]=P[i];
else if(j<=count) travel[j]=P[index[j-1]];
else if(j==count+1) travel[j]=A1;
else travel[j]=C1;}
Travel=S.add_travellers(count+3, travel);
S.list_travellers(count+3);}}
}