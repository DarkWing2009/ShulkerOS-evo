
#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;
//global
  bool acceptable;
  int cities;
  int coal, iron, lead, food, crystal, essence;
  int gained[10], used[10];
  int steel, munitions, Oricalcum, mithril;
  int Farms, CMines, IMines, LMines, Crystalizers, Extractors, Smelters,Factories, Synthesizers, Refineries;
  int Cdeposit, Ideposit, Ldeposit;
  int economy, income, upkeep, Pupkeep, Mupkeep,Tupkeep;
  int salary, Tworkers;
  int Btax, Ltax;
  int Soldiers,Mages,Tanks,Airships,Runecanons,Novaspheres,Mecha,Angel;
  int sellValue,BuyValue;
  int Barrack, Academy,Garage,Hangar,Lab,Facility,Altar;
  string line;
  string name;
  string i[5];
  int demand[10],expectation;
  int resourceID, CountryID,TrainID;
  int day, week, month, year;
  bool war[6];
  bool NEP[10],NEM[8],NET[8];
  int t;
  int b;
  int a;
  int c;
  int d;
  int e;
  int territory;
  int pop, popGain;
  int rep;
  double money;
  bool Open;
  int TyranyTurn;
  int total, completed;
  char world[25][25];
  string resource;
  int price;
  string city[50];
//prices for trade
  int pricing(int r) {

    switch (r) {
    case 0:
      price = 200 * cos(day) + 1600;
      break;
    case 1:
      price = 160 * cos(day) + 1000;
      break;
    case 2:
      price = 160 * cos(day) + 1000;
      break;
    case 3:
      price = 10 * cos(day) + 50;
      break;
    case 4:
      price = 875 * cos(day) + 7000;
      break;
    case 5:
      price = 220 * cos(day) + 2000;
      break;
    case 6:
      price = 650 * cos(day) + 4600;
      break;
    case 7:
      price = 100 * cos(day) + 1000;
      break;
    case 8:
      price = 2000 * cos(day) + 15600;
      break;
    case 9:
      price = 600 * cos(day) + 6600;
      break;
    }
    return price;
  }
//trade class
  class trade {
    public:
      string resource;
    string country;
    bool offer;
    int price;
    int qty;
  };
  trade * tab = new trade[62];
//Training
  class training{
    public:
    string type;
    int dayL,interval;
    bool started;
    bool built;
  };
  training * train = new training[20000];
//battlefield class
  class battlefield {
    public:
    string Ecountry;
    bool start,victory,defeat;
    int Isoldier,Image,Itank,Iairship,Imecha,Iangel;
    int field;
    string Starget,Mtarget,Ttarget,Atarget;
    int soldier,mage,tank,airship,mecha,angel,runecanon,novasphere;
    int Esoldier,Emage,Etank,Eairship,Emecha,Eangel,Erunecanon,Enovasphere;
    int Aprogress,Eprogress,duration;
    string reason;
  };
  battlefield * battle = new battlefield[20000];
//country class
  class country {
    public:      int land,trade,eco;
    int qty[10];
    bool sell[10];
    string name;
    int citiesN;
    string City[10];
    void create(int);
    int Popu;
    int prod[10];
    int Imine,Cmine,Lmine;
  };
  void country::create(int x) {
    switch (x) {
    case 0:
    land = 80;
    eco = 500;
    Imine =1;
    Cmine =2;
    Lmine =1;
    citiesN = 5;
      name = "Aldinah";
      Popu = 250000;
      trade = 4;
      sell[0] = true;
      prod[0] = 101;
      sell[1] = true;
      prod[1] = 101;
      sell[2] = true;
      prod[2] = 101;
      sell[3] = true;
      prod[3] = 101;
      sell[4] = false;
      sell[5] = false;
      sell[6] = true;
      prod[6] = 101;
      sell[7] = true;
      prod[7] = 101;
      sell[8] = false;
      sell[9] = false;
      break;
    case 1:
    eco = 120;
    Imine =0;
    Cmine =1;
    Lmine =0;
    Popu = 50000;
    land = 35;
    citiesN = 2;

      name = "Elfelheim";
      trade = 1;
      sell[0] = false;
      sell[1] = false;
      sell[2] = false;
      sell[3] = true;
      prod[3] = 100;
      sell[4] = true;
      prod[4] = 20;
      sell[5] = true;
      prod[5] = 20;
      sell[6] = false;
      sell[7] = false;
      sell[8] = true;
      prod[8] = 20;
      sell[9] = true;
      prod[9] = 20;
      break;
    case 2:
    Imine =2;
    Cmine =2;
    Lmine =2;
    land = 90;
    eco = 250;
    citiesN = 6;
      name = "Knox";
      Popu = 275000;
      trade = 2;
      sell[0] = true;
      prod[0] = 80;
      sell[1] = true;
      prod[1] = 80;
      sell[2] = true;
      prod[2] = 110;
      sell[3] = true;
      prod[3] = 100;
      sell[4] = false;
      sell[5] = false;
      sell[6] = true;
      prod[6] = 100;
      sell[7] = true;
      prod[7] = 110;
      sell[8] = false;
      sell[9] = false;
      break;
    case 3:
    Imine =2;
    Cmine =1;
    Lmine =1;
    eco = 250;
    land = 130;
       citiesN = 8;
      name = "Solus";
      Popu = 320000;
      trade = 2;
      sell[0] = true;
      prod[0] = 100;
      sell[1] = true;
      prod[1] = 100;
      sell[2] = true;
      prod[2] = 100;
      sell[3] = true;
      prod[3] = 105;
      sell[4] = true;
      prod[4] = 10;
      sell[5] = true;
      prod[5] = 10;
      sell[6] = true;
      prod[6] = 80;
      sell[7] = true;
      prod[7] = 50;
      sell[8] = true;
      prod[8] = 10;
      sell[9] = true;
      prod[9] = 10;
      break;
    case 4:
    Imine =3;
    Cmine =2;
    Lmine =2;
    Popu = 25000;
    eco = 20;
      name = "Tartan";
      citiesN = 1;
      trade = 2;
      sell[0] = true;
      prod[0] = 110;
      sell[1] = true;
      prod[1] = 110;
      sell[2] = true;
      prod[2] = 110;
      sell[3] = false;
      prod[3] = 20;
      sell[4] = false;
      sell[5] = false;
      sell[6] = false;
      sell[7] = false;
      sell[8] = false;
      sell[9] = false;
      break;
    case 5:
    land = 100;
    Imine =1;
    Cmine =1;
    Lmine =1;
    eco = 360;
    citiesN = 10;
      name = "Union";
      Popu = 60000;
      trade = 3;
      break;
      sell[0] = true;
      prod[0] = 98;
      sell[1] = true;
      prod[1] = 98;
      sell[2] = true;
      prod[2] = 98;
      sell[3] = true;
      prod[3] = 98;
      sell[4] = true;
      prod[4] = 15;
      sell[5] = true;
      prod[5] = 15;
      sell[6] = true;
      prod[6] = 98;
      sell[7] = true;
      prod[7] = 98;
      sell[8] = true;
      prod[8] = 15;
      sell[9] = true;
      prod[9] = 15;
    }
  }
  country * nation = new country[50];
//message class
    class message {
      public:
        bool complete, show, value;
      int Iday, Eday, dayL;
      string type;
      void create();
      void set(int, int, int, string);
      void completed();
      void shown();
    };
    //Constructor
    void message::create() {
      value = false;
    }
    //complete is true
    void message::completed() {
      complete = true;
    }
    //shown is true
    void message::shown() {
      show = true;
    }
    //message set
    void message::set(int i, int e, int l, string str) {
      value = true;
      complete = false;
      show = false;
      Iday = i;
      Eday = e;
      dayL = l;
      type = str;
    }
  message * msg = new message[25000];
//Overview screen
  void screen() {
    cout << "─────────────────["<<name<<"]─────────────────" << endl;
    cout << "Name:         "<<name<<endl;
    cout << "Population:   " << pop <<" Habitant"<<endl;
    cout << "Economy:      " <<economy<< "   (Salary :" << salary << "$)" <<endl;
    cout << "Money:        " << money << "$" << endl << endl;
    cout << "Notable geographical traits\n";
    cout << " Territory:    " << territory << " km2 " << endl;
    cout << " Deposits:" << endl;
    if (Ideposit > 0) {
      for (int i = 0; i < Ideposit; i++) {
        cout << "  Unused Iron Deposit" << endl;
      }
    }
    if (Cdeposit > 0) {
      for (int i = 0; i < Cdeposit; i++) {
        cout << "  Unused Coal Deposit" << endl;
      }
    }
    if (Ldeposit > 0) {
      for (int i = 0; i < Ldeposit; i++) {
        cout << "  Unused Lead Deposit" << endl;
      }
    }
    cout << " Cities:\n [Capital]\n";
    for (int i = 1; i <= cities; i++) {
      cout << " ["<<city[i]<<"]"<<endl;
    }
    cout << endl<<"<Notifications>" << endl;
    for (int i = 0; i < 10; i++) {
      string str;
      switch (i) {
      case 0: //Iron Mines
        str = "Iron";
        break;
      case 1:
        str = "Coal";
        break;
      case 2:
        str = "Lead";
        break;
      case 3:
        str = "Food";
        break;
      case 4:
        str = "Crystal";
        break;
      case 5:
        str = "Essence";
        break;
      case 6:
        str = "Steel";
        break;
      case 8:
        str = "Oricalcum";
        break;
      case 9:
        str = "Mithril";
        break;
      }
      if (gained[i] < used[i]) {
        cout << str << " production is unsufficient (" << gained[i] - used[i] << " " << str << ")" << endl;
      }
    }
    
      if (upkeep > income) {
        cout << "Treasury is emptying (" << upkeep - income << "$)" << endl;
      }
      if(money+income < upkeep){
        cout<<"Not enought money to maintain country. The following will be ceased:";
        cout<<" -Military Recruitement\n";
        if (money+income>Pupkeep+Mupkeep){
          if(money+income<Pupkeep){
            cout<<" -Military Maintenance\n";
            cout<<" -Production\n";
          }
          else{
            cout<<" -Military Maintenance\n";
          }
        }
        
      }
    for(int i =0;i<2000;i++){
        if(train[i].built){
        if (train[i].started == false){
          cout<<train[i].type<<"- Not enought resources"<<endl;
        }
        }
      }
    for (int i = 0; i < total; i++) {
      if (msg[i].complete && msg[i].show == false) {
        cout << msg[i].type << " constructed today (+1 " << msg[i].type << ")" << endl;
      }
    }
    cout <<endl<< "<Construction>" << endl;
    bool exist =false;
    for (int i = total; i >= 0; i--) {
      if (msg[i].complete == false && msg[i].show == false && msg[i].value == true) {
        exist =true;
        cout << "Day " << to_string(msg[i].Iday) << " - " << msg[i].type << " (" << to_string(msg[i].dayL) << " days left)" << endl;
      }
    }
    if(exist == false){
        cout<<"*No construction at the moment\n";
      }
    cout<<"\n<Neighbor Countries>"<<endl;
    cout<<" Aldinah"<<endl;
    cout<<" Elfelheim"<<endl;
    cout<<" Knox"<<endl;
    cout<<" Solus"<<endl;
    cout<<" Tartan"<<endl;
    cout<<" Union\n"<<endl;
  }
//country overview;
  void xscreen(int x){
    cout << "─────────────────["<<nation[x].name<<"]─────────────────" << endl;
    cout << "Name:         "<<nation[x].name<<endl;
    cout << "Population:   " << nation[x].Popu <<" Habitant"<<endl;
    cout << "Economy:      " <<nation[x].eco<< "   (Trade :" << nation[x].trade << ")" <<endl;
    
    cout << "Notable geographical traits\n";
    cout << " Territory:    " << nation[x].land << " km2 " << endl;
    cout << " Mines:" << endl;
    if (nation[x].Imine > 0) {
      for (int i = 0; i < nation[x].Imine; i++) {
        cout << "  Iron mine" << endl;
      }
    }
    if (nation[x].Cmine > 0) {
      for (int i = 0; i < nation[x].Cmine; i++) {
        cout << "  Coal mine" << endl;
      }
    }
    if (nation[x].Lmine > 0) {
      for (int i = 0; i < nation[x].Lmine; i++) {
        cout << "  Lead mine" << endl;
      }
    }
    cout << " Cities:   "<<nation[x].citiesN<<endl;
  cout<<"\n<Countries>"<<endl;
      cout<<" Aldinah"<<endl;
      cout<<" Elfelheim"<<endl;
      cout<<" Knox"<<endl;
      cout<<" Solus"<<endl;
      cout<<" Tartan"<<endl;
      cout<<" Union\n"<<endl;
  }
//Case Insensitivity code
  inline bool caseInsCharCompareN(char a, char b) {
    return (toupper(a) == toupper(b));
  }
  inline bool caseInsCharCompareW(wchar_t a, wchar_t b) {
    return (towupper(a) == towupper(b));
  }
  bool comp(const string & s1,
    const string & s2) {
    return ((s1.size() == s2.size()) &&
      equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
  }
  bool comp(const wstring & s1,
    const wstring & s2) {
    return ((s1.size() == s2.size()) &&
      equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareW));
  }
//delay code
  void delay(double seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC * 2;
    while (clock() < endwait) {}
  }
//Military asset
  void Masset(){
 cout<<"─────────────[Availlable Troops]───────────────"<<endl;
        cout<<Soldiers<<setw(22-to_string(Soldiers).length())<<"Soldiers        "<<Mages<<setw(11-to_string(Mages).length())<<"Mages"<<endl;
        cout<<Tanks<<setw(22-to_string(Tanks).length())<<"Tanks           "<<Airships<<setw(14-to_string(Airships).length())<<"Airships"<<endl<<Mecha<<setw(22-to_string(Mecha).length())<<"Mechas          "<<Angel<<setw(12-to_string(Angel).length())<<"Angels"<<endl<<Novaspheres<<setw(17-to_string(Novaspheres).length())<<"Novaspheres"<<endl;
        cout<<"\n<Military Facilities>\n";
        int repeat;
        repeat =0;
        bool exist;
        exist = false;
        while(repeat<6){
        for(int i = 0 ; i<2000;i++){
          if (train[i].built){
            exist = true;
            if (train[i].type == "Barrack"&&repeat == 0){
              cout<<"Barrack (";if(train[i].started){cout<<"Training 10 soldiers- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No training)"<<endl;}
            }
            if (train[i].type == "Academy"&&repeat == 1){
              cout<<"Academy (";if(train[i].started){cout<<"Teaching 20 students- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No classes)"<<endl;}
            }
            if (train[i].type == "Garage"&&repeat == 2){
              cout<<"Garage (";if(train[i].started){cout<<"Constructing 1 tank- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No construction)"<<endl;}
            }
            if (train[i].type == "Hangar"&&repeat == 3){
              cout<<"Hangar (";if(train[i].started){cout<<"Constructing 1 airship- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No construction)"<<endl;}
            }
            if (train[i].type == "Lab"&&repeat == 4){
              cout<<"Lab (";if(train[i].started){cout<<"Crafting 1 novasphere- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No research)"<<endl;}
            }
            if (train[i].type == "Facility"&&repeat == 5){
              cout<<"Facility (";if(train[i].started){cout<<"Constructing 1 mecha- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No construction)"<<endl;}
            }
            if (train[i].type == "Altar"&&repeat == 6){
              cout<<"Altar (";if(train[i].started){cout<<"Summoning 1 angel- "<<train[i].dayL<<" days left)"<<endl;}else{cout<<"No summoning)"<<endl;}
            }
          }
        }
        repeat +=1;
        }
        if (exist == false){
            cout<<"*No military facilities have been built."<<endl;
          }
          cout<<endl;
  }
//Battle list
  void Blist(){
         bool Atwar;
         Atwar = false;
         cout<<"──────────────[Battle List]──────────────"<<endl;
         cout<<"[ID][Country][Reason][Progression]"<<endl;
         for(int i = 0; i<2000;i++){
           if(battle[i].start){
             Atwar = true;
             cout<<"[";
             if(i<10){cout<<"0";}
             cout<<i<<"] "<<battle[i].Ecountry<<setw(10-battle[i].Ecountry.length()+battle[i].reason.length())<<battle[i].reason<<setw(5-battle[i].reason.length()+to_string(battle[i].Aprogress).length()+to_string(battle[i].Eprogress).length()+3)<<floor(battle[i].field)<<setw(10-(to_string(battle[i].field).length())+to_string(battle[i].duration).length())<<battle[i].duration<<"days"<<endl<<endl;
           }
  }
  if (Atwar == false){
            cout<<"*There is no ongoing battle currently."<<endl;
          }
  }
//confirmation function
  void conf(int x, int type) {
    int workers;
    string building, d;
    int cost;
    int Btime;
    switch (type) {
    case 0: //Iron Mines
      building = "Iron Mine";
      cost = 25000;
      Btime = 10;
      workers = 8;
      break;
    case 1:
      building = "Coal Mine";
      cost = 25000;
      Btime = 10;
      workers = 5;
      break;
    case 2:
      building = "Lead Mine";
      cost = 25000;
      Btime = 10;
      workers = 5;
      break;
    case 3:
      building = "Farm";
      cost = 10000;
      Btime = 10;
      workers = 5;
      break;
    case 4:
      building = "Crystalizer";
      cost = 125000;
      Btime = 50;
      workers = 25;
      break;
    case 5:
      building = "Extractor";
      cost = 50000;
      Btime = 20;
      workers = 10;
      break;
    case 6:
      building = "Smelter";
      cost = 50000;
      Btime = 20;
      workers = 10;
      break;
    case 7:
      building = "Factory";
      cost = 75000;
      Btime = 30;
      workers = 15;
      break;
    case 8:
      building = "Synthesizer";
      cost = 150000;
      Btime = 60;
      workers = 20;
      break;
    case 9:
      building = "Refinery";
      cost = 112500;
      Btime = 45;
      workers = 15;
      break;
    case 10:
      building = "Barrack";
      cost = 10000;
      Btime = 5;
      workers =1;
      break;
    case 11:
      building = "Academy";
      cost = 250000;
      Btime = 100;
      break;
    case 12:
      building = "Garage";
      cost = 250000;
      Btime = 100;
      break;
    case 13:
      building = "Hangar";
      cost = 375000;
      Btime = 150;
      break;
      case 14:
      building = "Lab";
      cost = 375000;
      Btime = 1500;
      break;
    case 15:
      building = "Facility";
      cost = 500000;
      Btime = 200;
      break;
    case 16:
      building = "Altar";
      cost = 500000;
      Btime = 200;
      break;
      case 17:
      building = "City";
      cost = 100000;
      Btime = 50;
    }
    string str;
    cout << "────────────<Confirmation>───────────" << endl;
    cout << "Constructing " << x << " " << building << "." << endl;
    cout << "Cost:                " << cost * x << "$" << endl;
    if(type!=17){
    cout << "Upkeep:              " << workers * salary << "$ per  mine/day" << endl;
    }
    else{
      cout<<"Effect:              Population: +5000 Habitant   Economy: +50\n";
    }
    cout << "Construction time:  " << Btime << "days" << endl;
    cout << "Confirm? (y/n)" << endl;
    cin >> str;
    if (comp(str, "y")) {
      for (int i = 0; i != x; i++) {
        money -= cost;
        switch (type) {
        case 0:
          Ideposit -= 1;
          break;
        case 1:
          Cdeposit -= 1;
          break;
        case 2:
          Ldeposit -= 1;
          break;
        }
      if(type == 17){
        string str;
        cout<<"Please Choose a name for your new city! (one word)\n";
        cin>> str;
        city[cities] =str;
        msg[total].create();
        msg[total].set(day, Btime + day, Btime, str+"(City)");
        total += 1;
      }
      else{
      msg[total].create();
        msg[total].set(day, Btime + day, Btime, building);
        total += 1;
      }
      }
      cout << "\033[2J\033[1;1H";
      cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
      screen();
    }
  }
//Ressource count
  void ressource() {
    gained[0] = IMines;
    gained[1] = CMines;
    gained[2] = LMines;
    gained[3] = Farms * 20;
    used[3] = pop / 50;
    gained[4] = Crystalizers;
    gained[5] = Extractors;
    //steel gained (Smelters)
    if (iron + IMines >= Smelters || coal + CMines >= Smelters) {
      used[0] = Smelters;
      used[1] = Smelters;
      gained[6] = Smelters;
    } else {
      if (iron + IMines > coal + CMines) {
        used[0] = coal + CMines;
        used[1] = coal + CMines;
        gained[6] = coal + CMines;
      }
      if (iron + IMines < coal + CMines) {
        used[0] = iron + IMines;
        used[1] = iron + IMines;
        gained[6] = iron + IMines;
      }
    }
    //munitions gained (Factories)
        if (lead >= Factories * 5) {
          used[2] = Factories * 5;
          gained[7] = Factories * 5;
        } else {
          used[2] = lead + LMines;
          gained[7] = lead + LMines;
        }
  //crystal gain
    if (crystal + Crystalizers >= Synthesizers || steel + Smelters >= Synthesizers) {
      used[6] = Synthesizers;
      used[4] = Synthesizers;
      gained[8] = Synthesizers;
    } else {
      if (crystal + Crystalizers > steel + Smelters) {
        used[6] = steel + Smelters;
        used[4] = steel + Smelters;
        gained[8] = steel + Smelters;
      }
      if (crystal + Crystalizers < steel + Smelters) {
        used[6] = crystal + Crystalizers;
        used[4] = crystal + Crystalizers;
        gained[8] = crystal + Crystalizers;
      }
    }
    //mithril gain
      if (essence + Extractors >= Synthesizers || steel + Smelters >= Synthesizers) {
        used[6] = Synthesizers;
        used[5] = Synthesizers;
        gained[9] = Synthesizers;
      } else {
        if (essence + Extractors > steel + Smelters) {
          used[6] = steel + Smelters;
          used[5] = steel + Smelters;
          gained[9] = steel + Smelters;
        }
        if (essence + Extractors < steel + Smelters) {
          used[6] = essence + Extractors;
          used[5] = essence + Extractors;
          gained[9] = essence + Extractors;
        }
      }
  }

//ALL COMMAND
  void get(string a1, string a2, string a3, string a4) {
    //often update
      for(int i =0;i<2000;i++){
                  if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                } 
              }
      salary = 10 * (economy / 100);
      Mupkeep = salary*Soldiers*20*Mages*3*Tanks*100*Airships*1000*Mecha*1000*Angel;
      Pupkeep = Tworkers * salary;
      upkeep = Pupkeep + Mupkeep+Tupkeep;
      Btax = pop * salary * 0.1;
      Ltax = pop;
      income = Btax + Ltax + 10 * economy;
      ressource();
    //trade
      if (comp(a1, "trade")) {
        if (a2 == " ") {
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout << "────────────[Trading Board]───────────" << endl;
          cout << "[ID][  Country  ][  Resource  ][Price][quantity]" << endl;
          for (int t = 0; t < 61; t++) {
            if (tab[t].offer) {
              cout << "[";
              if (t < 10) {
                cout << "0" << t;
              } else {
                cout << t;
              }
              cout << "]" << " " << tab[t].country << setw(13 - tab[t].country.length() + tab[t].resource.length()) << tab[t].resource << setw(13 - tab[t].resource.length() + to_string(tab[t].price).length()) << tab[t].price << "$" << setw(10 - to_string(tab[t].price).length()) << "x" << tab[t].qty << endl;
            }
          }
          cout << "\nRelated commands:\ntrade [ID]" << endl << "sell [quantity] [resource] " << endl;
        } else {
          if (tab[stoi(a2)].offer == true) {
            if (money >= tab[stoi(a2)].price * tab[stoi(a2)].qty) {
              cout << "───────[Trade offer #" << a2 << "]─────────" << endl;
              cout << "Buying " << tab[stoi(a2)].resource << " from " << tab[stoi(a2)].country << endl;
              cout << "Cost:" << tab[stoi(a2)].price << "$" << setw(18 - to_string(tab[stoi(a2)].price).length()) << "Quantity:" << tab[stoi(a2)].qty << endl;
              cout << "Total:" << tab[stoi(a2)].price * tab[stoi(a2)].qty << "$" << endl << "Confirm?(y/n)" << endl;
              cin >> line;
              if (comp(line, "y")) {
                money -= tab[stoi(a2)].price * tab[stoi(a2)].qty;
                BuyValue += tab[stoi(a2)].price * tab[stoi(a2)].qty;
                if(BuyValue >= 6000){
                  BuyValue-=6000;
                  economy-=1;
                }
                tab[stoi(a2)].offer = false;
                if (tab[stoi(a2)].resource == "Iron") {
                  iron += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Coal") {
                  coal += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Lead") {
                  lead += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Food") {
                  food += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Crystal") {
                  crystal += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Essence") {
                  essence += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Steel") {
                  steel += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Munitions") {
                  munitions += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Oricalcum") {
                  Oricalcum += tab[stoi(a2)].qty;
                }
                if (tab[stoi(a2)].resource == "Mithril") {
                  mithril += tab[stoi(a2)].qty;
                }
                cout << "*Received " << tab[stoi(a2)].qty << " " << tab[stoi(a2)].resource << " from " << tab[stoi(a2)].country << endl;
                delay(0.5);
                cout << "\033[2J\033[1;1H";
                cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
                cout << "────────────[Trading Board]───────────" << endl;
                cout << "[ID][ Country ][ Resource ][Price][quantity]" << endl;
                for (int t = 0; t < 61; t++) {
                  if (tab[t].offer) {
                    cout << "[";
                    if (t < 10) {
                      cout << "0" << t;
                    } else {
                      cout << t;
                    }
                    cout << "]" << " " << tab[t].country << setw(13 - tab[t].country.length() + tab[t].resource.length()) << tab[t].resource << setw(13 - tab[t].resource.length() + to_string(tab[t].price).length()) << tab[t].price << "$" << setw(10 - to_string(tab[t].price).length()) << "x" << tab[t].qty << endl;
                  }
                }
                cout << "\nRelated commands:\ntrade [ID]" << endl << "sell [quantity] [resource] " << endl;
              }
              if (comp(line, "N")) {
                cout << "\033[2J\033[1;1H";
                cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
                cout << "────────────[Trading Board]───────────" << endl;
                cout << "[ID][ Country ][ Resource ][Price][quantity]" << endl;
                for (int t = 0; t < 61; t++) {
                  if (tab[t].offer) {
                    cout << "[";
                    if (t < 10) {
                      cout << "0" << t;
                    } else {
                      cout << t;
                    }
                    cout << "]" << " " << tab[t].country << setw(13 - tab[t].country.length() + tab[t].resource.length()) << tab[t].resource << setw(13 - tab[t].resource.length() + to_string(tab[t].price).length()) << tab[t].price << "$" << setw(10 - to_string(tab[t].price).length()) << "x" << tab[t].qty << endl;
                  }
                }
                cout << "\nRelated commands:\ntrade [ID]" << endl << "sell [quantity] [resource] " << endl;
              }
            } else {
              cout << "Not enought money!" << endl;
              cout << "Missing (" << money - tab[stoi(a2)].price * tab[stoi(a2)].qty << "$)" << endl;
            }
          } else {
            cout << "That offer ID is not available" << endl;
          }
        }
      }
    //help
      if (comp(a1, "help") || comp(a1, "h")) {
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        cout << "───────────────────[Command List]────────────────────────" << endl;
        cout << "(H)elp                                        -Shows this window." << endl;
        cout << "(V)iew (self) [Country]                       -Shows country information." << endl;
        cout << "(S)tate                                       -Shows balance sheet." << endl;
        cout << "(T)rade (board) [Offer ID]                    -Shows trading board or proceed with trade." << endl;
        cout << "(S)ell [quantity] [resource]                  -Sells resource."<<endl;
        cout << "(C)onstruct (list) [quantity] [Building]      -Constructs buildings." << endl;
        cout << "(B)attle (menu)                               -Targeting adjust(for now)"<<endl;
        cout << "(R)ecruit (menu) [quantity] [soldier or mage] -Recruit soldiers or mages." << endl;
        cout << "(D)eploy (list) [Battle ID]                   -Send troops at defined battle." << endl;
        cout << "(E)nd (1) [Number of days]                    - Ends day or specified number of days." << endl << endl;

        cout << "() Default specification" << endl;
        cout << "[] Optional specifications (must include all optional specifications if using these)" << endl;
        cout << "Note: all command are case insensitive and can be used in all winddows execpt in menu" << endl;

      }

    //Balance sheet
      if (comp(a1, "state")) {
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        cout << "────────────[Revenue]───────────" << endl;
        cout << "<Income>" << endl;
        cout << "Population:    " << pop <<" Habitant" <<endl;
        cout << "Tax            " << endl;
        cout << " Borders:      " << economy * 10 << "$" << endl;
        cout << " Income:       " << Btax << "$" << endl;
        cout << " Land:         " << Ltax << "$" << endl;
        cout << "Gross Income:  " << income << "$" << endl;
        cout << endl;
        cout << "<Upkeep>" << endl;
        cout << "Production:    " << Pupkeep << "$" << endl;
        cout << "Military:      " << Tupkeep << "$" << endl;
        cout << "Total Upkeep:  " << upkeep << "$" << endl;
        cout << "---------------" << endl;
        cout << "Income:        " << income - upkeep << "$" << endl;
          cout << "───────────[Resources]──────────" << endl;
          cout << "Iron:         " << iron << "(" << gained[0] - used[0] << ")" << endl;
          cout << "Coal:         " << coal << "(" << gained[1] - used[1] << ")" << endl;
          cout << "Lead:         " << lead << "(" << gained[2] - used[2] << ")" << endl;
          cout << "Food:         " << food << "(" << gained[3] - used[3] << ")" << endl;
          cout << "Crystal:      " << crystal << "(" << gained[4] - used[4] << ")" << endl;
          cout << "Essence:      " << essence << "(" << gained[5] - used[5] << ")" << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel << "(" << gained[6] - used[6] << ")" << endl;
          cout << "Munitions:    " << munitions << "(" << gained[7] - used[7] << ")" << endl;
          cout << "Oricalcum:    " << Oricalcum << "(" << gained[8] - used[8] << ")" << endl;
          cout << "Mithril:      " << mithril << "(" << gained[9] - used[9] << ")" << endl;
        cout << "───────────[Production]──────────" << endl;
        cout << "                [quantity][  Production  ]"<<endl;
        cout << "Iron Mines:    " << IMines <<"(+"<<IMines<<"Iron)"<<endl;
        cout << "Coal Mines:    " << CMines <<"(+"<<CMines<<"Coal)"<<endl;     
        cout << "Lead Mines:    " << LMines <<"(+"<<LMines<<"Lead)"<<endl;
        cout << "Farms:         " << Farms <<"(+"<<Farms*20<<"Food)"<<endl;
        cout << "Crystalizers:  " << Crystalizers <<"(+"<<Crystalizers<<"Crystal)"<<endl;
        cout << "Smelters:      " << Smelters <<"(+"<<Smelters<<"Steel)"<<endl;
        cout << "Factories:     " << Factories <<"(+"<<Factories<<"Munitions)"<<endl;
        cout << "Synthesizers:  " << Synthesizers <<"(+"<<Synthesizers<<"Oricalcum)"<<endl;
        cout << "Refineries:    " << Refineries <<"(+"<<Refineries<<"Mithril)"<<endl;
      }
    //build command
      if (comp(a1, "construct") || comp(a1, "c")) {
        if (a3 == " ") {
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout << "────────────[Construction]───────────" << endl;
          cout << "Command : (B)uild (menu) [quantity] [Building]" << endl;
          cout << "More buildings: Factory, Synthesizer, Refinery, Barrack, Academy, Garage, Hangar, Lab, Facility, Altar, City." << endl;
          cout << "Building category:" << endl;
          cout << "Imine: An iron mine that produces 1 iron every day.\n Cost: 25 000 $\n Build time : 10 days\n Upkeep: 8 salary\n" << endl;
          cout << "Cmine: A coal mine that produces 1 coal every day.\n Cost: 25 000 $\n Build time : 10 days\n Upkeep: 5 salary\n" << endl;
          cout << "Lmine: A lead mine that produces 1 lead every day.\n Cost: 25 000 $\n Build time : 10 days\n Upkeep: 5 salary\n" << endl;
          cout << "Farm:  A farm mine that produces 20 food every day.\n Cost: 10 000 $\n Build time : 10 days\n Upkeep: 5 salary\n" << endl;
          cout << "Crystalizer: An advanced arcane machine that produces 1 crystal every day.\n Cost: 125 000 $\n Build time : 50 days\n Upkeep: 25 salary\n" << endl;
          cout << "Extractor: An advanced arcane machine that produces 1 essence every day.\n Cost: 50 000 $\n Build time : 20 days\n Upkeep: 10 salary\n" << endl;
          cout << "Smelter:  A smelter that takes 1 coal and 1 iron to make 1 steel.\n Cost: 50 000 $\n Build time : 20 days\n Upkeep: 10 salary\n" << endl;
        }
      //production
        if(comp(a3,"city")){
          if (money >= 100000 * stoi(a2)) {
              conf(stoi(a2), 17);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (100000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "IMine") || comp(a3, "IMines")) {
          if (money >= 25000 * stoi(a2)) {
            if (IMines + stoi(a2) <= Ideposit) {
              conf(stoi(a2), 0);
            } else {
              cout << "NOT ENOUGHT IRON DEPOSITS REMAINING (" << Ideposit - IMines << " remaining)" << endl;
            }
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (25000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "cmine") || comp(a3, "cmines")) {
          if (money >= 25000 * stoi(a2)) {
            if (CMines + stoi(a2) <= Cdeposit) {
              conf(stoi(a2), 1);
            } else {
              cout << "NOT ENOUGHT  COAL DEPOSITS REMAINING (" << Cdeposit - CMines << " remaining)" << endl;
            }
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (25000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "Smelter") || comp(a3, "Smelters")) {
          if (money >= 50000 * stoi(a2)) {
            conf(stoi(a2), 6);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (50000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "Farm") || comp(a3, "Farms")) {
          if (money >= 10000 * stoi(a2)) {
            conf(stoi(a2), 3);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (10000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "lmine") || comp(a3, "lmines")) {
          if (money >= 25000 * stoi(a2)) {
            if (LMines + stoi(a2) <= Ldeposit) {
              conf(stoi(a2), 1);
            } else {
              cout << "NOT ENOUGHT LEAD DEPOSITS REMAINING  (" << Ldeposit - LMines << " remaining)" << endl;
            }
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (25000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "extractor") || comp(a3, "extractors")) {
          if (money >= 50000 * stoi(a2)) {
            conf(stoi(a2), 5);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (50000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "refinery") || comp(a3, "refineries")) {
          if (money >= 112500 * stoi(a2)) {
            conf(stoi(a2), 9);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (112500 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "crystalizer") || comp(a3, "crystalizers")) {
          if (money >= 125000 * stoi(a2)) {
            conf(stoi(a2), 4);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (125000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "factory") || comp(a3, "factories")) {
          if (money >= 75000 * stoi(a2)) {
            conf(stoi(a2), 7);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (75000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "Synthesizer") || comp(a3, "synthesizers")) {
          if (money >= 150000 * stoi(a2)) {
            conf(stoi(a2), 8);
          } else {
            cout << "Not enought money!" << endl;
            cout << "Missing (" << money - (150000 * stoi(a2)) << "$)" << endl;
          }
        }
        if (comp(a3, "mine") || comp(a3, "mines")) {
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout << "───────────────────────────────────────────────────────" << endl;
          cout << line << endl;
          cout << "Please select a ressource:" << endl;
          cout << "-Coal (Cmine)" << endl;
          cout << "-Iron (Imine)" << endl;
          cout << "-Lead (Lmine)" << endl;
          cin >> line;
          if (comp(line, "coal")) {
            if (money >= 5000 * stoi(a2)) {
              conf(stoi(a2), 1);
            } else {
              cout << "Not enought money!" << endl;
            }

          }
          if (comp(line, "iron")) {
            if (money >= 10000 * stoi(a2)) {
              conf(stoi(a2), 0);
            } else {
              cout << "Not enought money!" << endl;
            }

            if (comp(line, "lead")) {
              if (money >= 8000 * stoi(a2)) {
                conf(stoi(a2), 2);
              } else {
                cout << "Not enought money!" << endl;
              }
            }
          }
        }
      
      //military
          if(comp(a3,"barrack")||comp(a3,"barracks")){
          if (money>=10000){
            conf(stoi(a2),10);
          }
          else{
            cout << "Not enought money! (Missing"<<10000-money<<"$)"<< endl;
          }
        }
        if(comp(a3,"academy")){
          if (money>=250000){
            conf(stoi(a2),11);
          }
          else{
            cout << "Not enought money! (Missing"<<250000-money<<"$)"<< endl;
          }
        }
        if(comp(a3,"garage")){
          if (money>=250000){
            conf(stoi(a2),12);
          }
          else{
            cout << "Not enought money! (Missing"<<250000-money<<"$)"<< endl;
          }
        }
        if(comp(a3,"Hangar")){
          if (money>=375000){
            conf(stoi(a2),13);
          }
          else{
            cout << "Not enought money! (Missing"<<375000-money<<"$)"<< endl;
          }
        }
        if(comp(a3,"lab")){
          if (money>=375000){
            conf(stoi(a2),14);
          }
          else{
            cout << "Not enought money! (Missing"<<375000-money<<"$)"<< endl;
          }
        }
        if(comp(a3,"facility")){
          if (money>=500000){
            conf(stoi(a2),15);
          }
          else{
            cout << "Not enought money! (Missing"<<500000-money<<"$)"<< endl;
          }
        }
        if(comp(a3,"altar")){
          if (money>=500000){
            conf(stoi(a2),16);
          }
          else{
            cout << "Not enought money! (Missing"<<500000-money<<"$)"<< endl;
          }
        }
      }
    //end day code
      //single day
        if (comp(a1, "end")) {
        if (a2 == " ") {
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        //initial data
          cout << "──────────────────────[Report]───────────────────────" << endl;
          cout << "----Day " << day << " Outcome----" << endl;
          cout << "Population:   " << pop <<" Habitant" << endl;
          cout << "Money:        " << money<< endl;
          cout << "Iron:         " << iron << endl;
          cout << "Coal:         " << coal<< endl;
          cout << "Lead:         " << lead<< endl;
          cout << "Food:         " << food << endl;
          cout << "Crystal:      " << crystal << endl;
          cout << "Essence:      " << essence << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel<< endl;
          cout << "Munitions:    " << munitions<< endl;
          cout << "Oricalcum:    " << Oricalcum << endl;
          cout << "Mithril:      " << mithril << endl;
        //troop training
          for(int i =0;i<2000;i++){
            if(train[i].built){
              if(train[i].started){
                train[i].dayL-=1;
              }
              else{
               if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                } 
              }
              if (train[i].dayL==0){
                if(train[i].started==true){
                  if(train[i].type =="Barrack"){
                    train[i].started = false;
                    Soldiers+=10;
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    train[i].started = false;
                    Mages+=20;
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    train[i].started = false;
                    Tanks+=1;
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    train[i].started = false;
                    Airships+=1;
                    economy+=5;
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    train[i].started = false;
                    Mecha+=1;
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    train[i].started = false;
                    Angel+=1;
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                }
                }
                else{
                  if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                }
                }
              }
            }
          }
        //resource
          ressource();
          iron += gained[0] - used[0];
          coal += gained[1] - used[1];
          lead += gained[2] - used[2];
          food += gained[3] - used[3];
          crystal += gained[4] - used[4];
          essence += gained[5] - used[5];
          steel += gained[6] - used[6];
          munitions += gained[7];
          Oricalcum += gained[8] - used[8];
          mithril += gained[9] - used[9];
          popGain = 0;
          if (gained[3] - used[3] >= 0) {
            for (int cp = 0; cp < pop; cp++) {
              int r;
              r = rand() % 100 + 1;
              if (r == 1) {
                pop += 1;
                popGain += 1;
              }
            }
          }
        //trade rng
          resourceID = 0;
          CountryID = 0;
          for(int i =0; i< 61;i++){
            tab[i].offer = false;
          }
          for (int i = 0; i < 61; i++) {
            int offers;
            offers =0;
            switch (resourceID) {
            case 0:
              tab[i].resource = "Iron";
              break;
            case 1:
              tab[i].resource = "Coal";
              break;
            case 2:
              tab[i].resource = "Lead";
              break;
            case 3:
              tab[i].resource = "Food";
              break;
            case 4:
              tab[i].resource = "Crystal";
              break;
            case 5:
              tab[i].resource = "Essence";
              break;
            case 6:
              tab[i].resource = "Steel";
              break;
            case 7:
              tab[i].resource = "Munitions";
              break;
            case 8:
              tab[i].resource = "Oricalcum";
              break;
            case 9:
              tab[i].resource = "Mithril";
              break;

            }
            if (nation[CountryID].sell[resourceID]) {
              tab[i].country = nation[CountryID].name;
              tab[i].price = 20 * cos(day) + ((pricing(resourceID) * 100) / nation[CountryID].prod[resourceID]);
              
              int rng;
              rng = rand() % 2 + 1;
              if (rng == 1) {
                if(offers<=nation[CountryID].trade){
                offers+=1;
                tab[i].offer = true;
                int n;
                if (resourceID == 3) {
                  n = rand() % 20 + 100;
                }
                if (resourceID >= 0 && resourceID <= 2) {
                  n = rand() % 2 + 1;
                }
                if (resourceID >= 4) {
                  n = 1;
                }
                tab[i].qty = n;
                tab[i].offer = true;
              }
              }
            }
            //progression
            resourceID += 1;
            if (resourceID == 10) {
              resourceID = 0;
              CountryID += 1;
              offers =0;
            }
          }
        //end construction
          for (int i = 0; i < total; i++) {
            msg[i].dayL -= 1;
            if (msg[i].dayL <= 0) {
              if (msg[i].complete == true) {
                msg[i].shown();
              } else {
                if (msg[i].type == "Iron Mine") {
                  IMines += 1;
                  Tworkers += 8;
                }
                if (msg[i].type == "Coal Mine") {
                  CMines += 1;
                  Tworkers += 5;
                }
                if (msg[i].type == "Lead Mine") {
                  LMines += 1;
                  Tworkers += 5;
                }
                if (msg[i].type == "Farm") {
                  Farms += 1;
                  Tworkers += 2;
                }
                if (msg[i].type == "Crystalizer") {
                  Crystalizers += 1;
                  Tworkers += 25;
                }
                if (msg[i].type == "Extractor") {
                  Extractors += 1;
                  Tworkers += 20;
                }
                if (msg[i].type == "Smelter") {
                  Smelters += 1;
                  Tworkers += 10;
                }
                if (msg[i].type == "Factory") {
                  Factories += 1;
                  Tworkers += 10;
                }
                if (msg[i].type == "Synthesizer") {
                  Synthesizers += 1;
                  Tworkers += 20;
                }
                if (msg[i].type == "Barrack") {
                  Barrack += 1;
                  train[TrainID].type = "Barrack";
                  train[TrainID].built = true;
                  train[TrainID].interval=2;
                  TrainID+=1;
                }
                if (msg[i].type == "Academy") {
                  Academy += 1;
                  train[TrainID].type = "Academy";
                  train[TrainID].built = true;
                  train[TrainID].interval=50;
                  TrainID+=1;
                }
                if (msg[i].type == "Garage") {
                  Garage += 1;
                  train[TrainID].type = "Garage";
                  train[TrainID].built = true;
                  train[TrainID].interval=2;
                  TrainID+=1;
                }
                if (msg[i].type == "Hangar") {
                  Hangar += 1;
                  train[TrainID].type = "Hangar";
                  train[TrainID].built = true;
                  train[TrainID].interval=50;
                  TrainID+=1;
                }
                if (msg[i].type == "Lab") {
                  Lab += 1;
                }
                if (msg[i].type == "Facility") {
                  Facility += 1;
                  train[TrainID].type = "Facility";
                  train[TrainID].built = true;
                  train[TrainID].interval=100;
                  TrainID+=1;
                }
                if (msg[i].type == "Altar") {
                  Altar += 1;
                  train[TrainID].type = "Altar";
                  train[TrainID].built = true;
                  train[TrainID].interval=100;
                  TrainID+=1;
                }
                if (msg[i].type == "Altar") {
                  cities+=1;
                  pop+=5000;
                  economy +=50;
                }
                msg[i].completed();
              }
            }
          }
        //economy
          economy += (gained[0]+gained[1]+gained[2]+(gained[3]/19)+gained[4]+gained[5]+gained[6]+gained[7]+gained[8]+gained[9])-(used[0]+used[1]+used[2]+(used[3]/20)+used[4]+used[5]+used[6]+used[7]+used[8]+used[9]);
          money += income - upkeep;
         
        //updated data
          cout << "Ending day.." << endl;
          delay(1);
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout << "──────────────────────[Report]───────────────────────" << endl;
          cout << "----Day " << day << " Outcome----" << endl;
          cout << "Population:   " << pop <<" Habitant"<< "(" << popGain << " Habitant)" << endl;
          cout << "Money:        " << money << " " << "$(" << income - upkeep << "$" << ")" << endl;
          cout << "Iron:         " << iron << "(" << gained[0] - used[0] << ")" << endl;
          cout << "Coal:         " << coal << "(" << gained[1] - used[1] << ")" << endl;
          cout << "Lead:         " << lead << "(" << gained[2] - used[2] << ")" << endl;
          cout << "Food:         " << food << "(" << gained[3] - used[3] << ")" << endl;
          cout << "Crystal:      " << crystal << "(" << gained[4] - used[4] << ")" << endl;
          cout << "Essence:      " << essence << "(" << gained[5] - used[5] << ")" << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel << "(" << gained[6] - used[6] << ")" << endl;
          cout << "Munitions:    " << munitions << "(" << gained[7] - used[7] << ")" << endl;
          cout << "Oricalcum:    " << Oricalcum << "(" << gained[8] - used[8] << ")" << endl;
          cout << "Mithril:      " << mithril << "(" << gained[9] - used[9] << ")" << endl;
          day += 1;
          if (food <= 0) {
            pop -= (food - used[3]) * -1;
            TyranyTurn += 1;
            food = 0;
          }
          delay(1);
          bool w =false;

          for (int i =0; i<20000;i++){
            if (battle[i].start){
              w =true;
            }
          }
          if(w == false){
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          screen();
          }
        //battles
          for (int i =0; i<20000;i++){
            if (battle[i].start){
              cout << "\033[2J\033[1;1H";
              cout<<"██████╗  █████╗ ████████╗████████╗██╗     ███████╗     \n";
              cout<<"██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝  \n";
              cout<<"██████╔╝███████║   ██║      ██║   ██║     █████╗  \n";
              cout<<"██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝ \n";
              cout<<"██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗\n";
              cout<<"╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝\n";
                cout<<"─────────────────[Battlefield #"<<i<<"]─────────────────"<<endl;
                
            //artillery phase
              //mage
              int Sk,Tk,Ak;
              int ESk,ETk,EAk;
              int rng;
              Sk=0;
              Tk=0;
              Ak=0;
              rng = rand() % 100+1;
              if (battle[i].Mtarget == "Soldiers"){
                for (int m =0;m<battle[i].mage; m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 50+10;battle[i].Esoldier-=c;Sk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}     
                }
              }
              if (battle[i].Mtarget == "Tanks"){
                for (int m =0;m<battle[i].mage;m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 50+1;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              if (battle[i].Mtarget == "Airships"){
                for (int m =0;m<battle[i].mage;m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}
                if (type<25){int c;c =rand() % 50+10;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              for (int m =0;m<battle[i].Emage;m++){
                if (rng>50){int c;c =rand() % 50+10;battle[i].soldier-=c*1.15;pop-=c;ESk+=c;}
                if (rng>=25&&rng<=50){int c;c =rand() % 2+1;if(c == 1){battle[i].tank-=1;pop-=1;ETk+=1;}}
                if (rng<25){int c;c =rand() % 15+1;if(c == 1){battle[i].airship-=1;pop-=100;EAk+=1;}}       
                }
                delay(0.5);
              if(battle[i].mage>0){
              cout<<"<Ally Mage Artillery Fire>"<<endl;
              cout<<" (- "<<Sk<<" Enemy Soldiers)"<<endl;
              cout<<" (- "<<Tk<<" Enemy Tanks)"<<endl;
              cout<<" (- "<<Ak<<" Enemy Airships)"<<endl;
              }

              if(battle[i].Emage>0){
              cout<<"\n<Enemy Mage Artillery Fire>"<<endl;
              cout<<" (- "<<ESk<<" Ally Soldiers)"<<endl;
              cout<<" (- "<<ETk<<" Ally Tanks)"<<endl;
              cout<<" (- "<<EAk<<" Ally Airships)"<<endl;
              }
              //airship
              Sk=0;
              Tk=0;
              Ak=0;
              rng = rand() % 100+1;
              if (battle[i].Atarget == "Soldiers"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type<25){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}       
                }
              }
              if (battle[i].Mtarget == "Tanks"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              if (battle[i].Mtarget == "Airships"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type<25){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              for (int a =0;a<battle[i].Eairship;a++){
                if (rng>50){int c;c =rand() % 1000+100;battle[i].soldier-=c*1.15;pop-=c;ESk+=c;}
                if (rng>=25&&rng<=50){int c;c =rand() % 20+1;battle[i].tank-=c*1.15;pop-=c;ETk+=c;}
                if (rng<25){int c;c =rand() % 4+1;if(c == 1){battle[i].airship-=1;pop-=100;EAk+=1;}}
              }
              delay(0.5);
                 if(battle[i].airship>0){
              cout<<"\n<Ally Airship Bombing>"<<endl;
              cout<<" (- "<<Sk<<" Enemy Soldiers)"<<endl;
              cout<<" (- "<<Tk<<" Enemy Tanks)"<<endl;
              cout<<" (- "<<Ak<<" Enemy Airships)"<<endl;
              }

              if(battle[i].Eairship>0){
              cout<<"\n<Enemy Airship Bombing>"<<endl;
              cout<<" (- "<<ESk<<" Ally Soldiers)"<<endl;
              cout<<" (- "<<ETk<<" Ally Tanks)"<<endl;
              cout<<" (- "<<EAk<<" Ally Airships)"<<endl;
              }
              
              //Ground phase
                  battle[i].field = (battle[i].soldier+battle[i].tank*50)/((battle[i].soldier+battle[i].tank*50)+((battle[i].Esoldier+battle[i].Etank*50)+1000));
                  if (battle[i].field<=0.2){
                    battle[i].start = false;
                  Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  }//shit
                    Tk =0;
                    ETk =0;
                  int k,Ek,ETK,Mk,EMk;
                                      k =0;
                    Ek =0;
                    Mk =0;
                    EMk=0;
                  if (battle[i].field>0.2||battle[i].field<=0.4){
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        k+=1;
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      int type;
                      type = rand() % 20+1;
                      if(type == 1){
                        battle[i].mage-=1;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        Ek+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 3+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      if(type ==2 ){
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                      if(type == 3){
                        int rng;
                      rng = rand() % 50+1;
                      EMk+=rng;
                      }
                    }
                  }
                  if (battle[i].field>0.4||battle[i].field<=0.6){
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Ek+=1;
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        k+=1;
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                    }
              
                  }
                  if (battle[i].field>0.6||battle[i].field<=0.8){
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Ek+=1;
                      }
                    }
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      int type;
                      type = rand() % 20+1;
                      if(type == 1){
                        battle[i].Emage-=1;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        k+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 3+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      if(type ==2 ){
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                      if(type == 3){
                        int rng;
                      rng = rand() % 50+1;
                      Mk+=rng;
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                    }
                  }

                  if (battle[i].field>0.8){
                    battle[i].victory = true;battle[i].start = false;
                  
                  }//dominance]
                  delay(0.5);
                  cout<<"\n<Ground Combat>"<<endl;
                  cout<<" (- "<<k<<" Enemy soldiers)"<<endl;
                  cout<<" (- "<<Tk<<" Enemy tanks)"<<endl;
                  cout<<" (- "<<Mk<<" Enemy mages)"<<endl;
                  cout<<endl;
                  cout<<" (- "<<Ek<<" Ally soldiers)"<<endl;
                  cout<<" (- "<<ETk<<" Ally tanks)"<<endl;
                  cout<<" (- "<<EMk<<" Ally mages)"<<endl;
                  battle[i].soldier+=battle[i].Isoldier;
                  battle[i].Isoldier =0;
                  battle[i].mage+=battle[i].Image;
                  battle[i].Image =0;
                  battle[i].tank+=battle[i].Itank;
                  battle[i].Itank =0;
                  battle[i].airship+=battle[i].Iairship;
                  battle[i].Iairship =0;
                  if(battle[i].start == false){
                    battle[i].start = false;
                  }

                  for (int n =0;n<6;n++){
                  if (nation[n].name == battle[i].Ecountry){
                    if(battle[i].defeat){
                      cout<<"██████╗ ███████╗███████╗███████╗ █████╗ ████████╗"<<endl;
                      cout<<"██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗╚══██╔══╝"<<endl;
                      cout<<"██║  ██║█████╗  █████╗  █████╗  ███████║   ██║  " <<endl;
                      cout<<"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██╔══██║   ██║   "<<endl;
                      cout<<"██████╔╝███████╗██║     ███████╗██║  ██║   ██║   "<<endl;
                      cout<<"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝"<<endl;
                      cout<<"After a long period of fighting,"<<battle[i].Ecountry<<" emerged victorious"<<endl;
                      cout<<"You have failed to seize anything and your troops have been imprisonned"<<endl;
                    }
                  if(battle[i].victory){
                    cout << "\033[2J\033[1;1H";
                    cout<<"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗"<<endl;
                    cout<<"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝"<<endl;
                    cout<<"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ "<<endl;
                    cout<<"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  "<<endl;
                    cout<<" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   "<<endl;
                    cout<<"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝ "<<endl;
                    cout<<"After a long period of fighting,"<<name<<" emerged victorious"<<endl;
                    if(battle[i].reason =="Iron"){
                    economy+=10;IMines+=1;
                    nation[n].Imine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Iron Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="Coal"){
                    economy+=10;CMines+=1;
                    nation[n].Cmine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Coal Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="Lead"){
                    economy+=10;LMines+=1;
                     nation[n].Lmine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Lead Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="City"){
                    economy+=10;pop+=5000;
                     nation[n].citiesN-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 city from "<<battle[i].Ecountry;
                  string str;
                  cout<<"Please Choose a name for your new city! (one word)\n";
                  cin>> str;
                  city[cities] =str;
                  cities+=1;
                    }
                  if(battle[i].reason =="Capital"){
                    
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"Congratulation! You have conquered "<<battle[i].Ecountry<<"!\n";
                  cout<<"Everything that once belonged to "<<battle[i].Ecountry<<" now belong to you country"<<endl;
                    economy+=10;
                        IMines += nation[n].Imine;
                        CMines+= nation[n].Cmine;
                        LMines+= nation[n].Lmine;
                        pop += nation[n].Popu;
                        economy += nation[n].eco/2;
                        money+= 1000000;
                        cout<<"Including the cities, therefore please choose a name for evey city:"<<endl;
                        for(int x =0; x<nation[n].citiesN;x++){
                          cout<<"City name:";
                          string str;
                          cin>> str;
                          city[cities] =str;
                          cities+=1;
                          cout<<endl;
                        }
                      }
                      cout<<"All your troops have succesfully returned to the capital"<<endl;
                    }
                    
                    }
                    }
                  }
          
                  }
                }
            
      //multiple days
        else {
          
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        //initial data
          cout << "──────────────────────[Report]───────────────────────" << endl;
          cout << "----Day " << day << " Outcome----" << endl;
          cout << "Population:   " << pop <<" Habitant" << endl;
          cout << "Money:        " << money<< endl;
          cout << "Iron:         " << iron << endl;
          cout << "Coal:         " << coal<< endl;
          cout << "Lead:         " << lead<< endl;
          cout << "Food:         " << food << endl;
          cout << "Crystal:      " << crystal << endl;
          cout << "Essence:      " << essence << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel<< endl;
          cout << "Munitions:    " << munitions<< endl;
          cout << "Oricalcum:    " << Oricalcum << endl;
          cout << "Mithril:      " << mithril << endl;
        //troop training
          for(int i =0;i<2000;i++){
            if(train[i].built){
              if(train[i].started){
                train[i].dayL-=1;
              }
              else{
               if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                } 
              }
              if (train[i].dayL==0){
                if(train[i].started==true){
                  if(train[i].type =="Barrack"){
                    train[i].started = false;
                    Soldiers+=10;
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    train[i].started = false;
                    Mages+=20;
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    train[i].started = false;
                    Tanks+=1;
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    train[i].started = false;
                    Airships+=1;
                    economy+=5;
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    train[i].started = false;
                    Mecha+=1;
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    train[i].started = false;
                    Angel+=1;
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                }
                }
                else{
                  if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                }
                }
              }
            }
          }
        //resource
          ressource();
          iron += gained[0] - used[0];
          coal += gained[1] - used[1];
          lead += gained[2] - used[2];
          food += gained[3] - used[3];
          crystal += gained[4] - used[4];
          essence += gained[5] - used[5];
          steel += gained[6] - used[6];
          munitions += gained[7];
          Oricalcum += gained[8] - used[8];
          mithril += gained[9] - used[9];
          popGain = 0;
          if (gained[3] - used[3] >= 0) {
            for (int cp = 0; cp < pop; cp++) {
              int r;
              r = rand() % 100 + 1;
              if (r == 1) {
                pop += 1;
                popGain += 1;
              }
            }
          }
        //trade rng
          resourceID = 0;
          CountryID = 0;
          for(int i =0; i< 61;i++){
            tab[i].offer = false;
          }
          for (int i = 0; i < 61; i++) {
            int offers;
            offers =0;
            switch (resourceID) {
            case 0:
              tab[i].resource = "Iron";
              break;
            case 1:
              tab[i].resource = "Coal";
              break;
            case 2:
              tab[i].resource = "Lead";
              break;
            case 3:
              tab[i].resource = "Food";
              break;
            case 4:
              tab[i].resource = "Crystal";
              break;
            case 5:
              tab[i].resource = "Essence";
              break;
            case 6:
              tab[i].resource = "Steel";
              break;
            case 7:
              tab[i].resource = "Munitions";
              break;
            case 8:
              tab[i].resource = "Oricalcum";
              break;
            case 9:
              tab[i].resource = "Mithril";
              break;

            }
            if (nation[CountryID].sell[resourceID]) {
              tab[i].country = nation[CountryID].name;
              tab[i].price = 20 * cos(day) + ((pricing(resourceID) * 100) / nation[CountryID].prod[resourceID]);
              
              int rng;
              rng = rand() % 2 + 1;
              if (rng == 1) {
                if(offers<=nation[CountryID].trade){
                offers+=1;
                tab[i].offer = true;
                int n;
                if (resourceID == 3) {
                  n = rand() % 20 + 100;
                }
                if (resourceID >= 0 && resourceID <= 2) {
                  n = rand() % 2 + 1;
                }
                if (resourceID >= 4) {
                  n = 1;
                }
                tab[i].qty = n;
                tab[i].offer = true;
              }
              }
            }
            //progression
            resourceID += 1;
            if (resourceID == 10) {
              resourceID = 0;
              CountryID += 1;
              offers =0;
            }
          }
        //end construction
          for (int i = 0; i < total; i++) {
            msg[i].dayL -= 1;
            if (msg[i].dayL <= 0) {
              if (msg[i].complete == true) {
                msg[i].shown();
              } else {
                if (msg[i].type == "Iron Mine") {
                  IMines += 1;
                  Tworkers += 8;
                }
                if (msg[i].type == "Coal Mine") {
                  CMines += 1;
                  Tworkers += 5;
                }
                if (msg[i].type == "Lead Mine") {
                  LMines += 1;
                  Tworkers += 5;
                }
                if (msg[i].type == "Farm") {
                  Farms += 1;
                  Tworkers += 2;
                }
                if (msg[i].type == "Crystalizer") {
                  Crystalizers += 1;
                  Tworkers += 25;
                }
                if (msg[i].type == "Extractor") {
                  Extractors += 1;
                  Tworkers += 20;
                }
                if (msg[i].type == "Smelter") {
                  Smelters += 1;
                  Tworkers += 10;
                }
                if (msg[i].type == "Factory") {
                  Factories += 1;
                  Tworkers += 10;
                }
                if (msg[i].type == "Synthesizer") {
                  Synthesizers += 1;
                  Tworkers += 20;
                }
                if (msg[i].type == "Barrack") {
                  Barrack += 1;
                  train[TrainID].type = "Barrack";
                  train[TrainID].built = true;
                  train[TrainID].interval=2;
                  TrainID+=1;
                }
                if (msg[i].type == "Academy") {
                  Academy += 1;
                  train[TrainID].type = "Academy";
                  train[TrainID].built = true;
                  train[TrainID].interval=50;
                  TrainID+=1;
                }
                if (msg[i].type == "Garage") {
                  Garage += 1;
                  train[TrainID].type = "Garage";
                  train[TrainID].built = true;
                  train[TrainID].interval=2;
                  TrainID+=1;
                }
                if (msg[i].type == "Hangar") {
                  Hangar += 1;
                  train[TrainID].type = "Hangar";
                  train[TrainID].built = true;
                  train[TrainID].interval=50;
                  TrainID+=1;
                }
                if (msg[i].type == "Lab") {
                  Lab += 1;
                }
                if (msg[i].type == "Facility") {
                  Facility += 1;
                  train[TrainID].type = "Facility";
                  train[TrainID].built = true;
                  train[TrainID].interval=100;
                  TrainID+=1;
                }
                if (msg[i].type == "Altar") {
                  Altar += 1;
                  train[TrainID].type = "Altar";
                  train[TrainID].built = true;
                  train[TrainID].interval=100;
                  TrainID+=1;
                }
                if (msg[i].type == "Altar") {
                  cities+=1;
                  pop+=5000;
                  economy +=50;
                }
                msg[i].completed();
              }
            }
          }
        //economy
          economy += (gained[0]+gained[1]+gained[2]+(gained[3]/19)+gained[4]+gained[5]+gained[6]+gained[7]+gained[8]+gained[9])-(used[0]+used[1]+used[2]+(used[3]/20)+used[4]+used[5]+used[6]+used[7]+used[8]+used[9]);
          money += income - upkeep;
         
        //updated data
          cout << "Ending day.." << endl;
          delay(1);
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout << "──────────────────────[Report]───────────────────────" << endl;
          cout << "----Day " << day << " Outcome----" << endl;
          cout << "Population:   " << pop <<" Habitant"<< "(" << popGain << " Habitant)" << endl;
          cout << "Money:        " << money << " " << "$(" << income - upkeep << "$" << ")" << endl;
          cout << "Iron:         " << iron << "(" << gained[0] - used[0] << ")" << endl;
          cout << "Coal:         " << coal << "(" << gained[1] - used[1] << ")" << endl;
          cout << "Lead:         " << lead << "(" << gained[2] - used[2] << ")" << endl;
          cout << "Food:         " << food << "(" << gained[3] - used[3] << ")" << endl;
          cout << "Crystal:      " << crystal << "(" << gained[4] - used[4] << ")" << endl;
          cout << "Essence:      " << essence << "(" << gained[5] - used[5] << ")" << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel << "(" << gained[6] - used[6] << ")" << endl;
          cout << "Munitions:    " << munitions << "(" << gained[7] - used[7] << ")" << endl;
          cout << "Oricalcum:    " << Oricalcum << "(" << gained[8] - used[8] << ")" << endl;
          cout << "Mithril:      " << mithril << "(" << gained[9] - used[9] << ")" << endl;
          day += 1;
          if (food <= 0) {
            pop -= (food - used[3]) * -1;
            TyranyTurn += 1;
            food = 0;
          }
          delay(1);
          bool w =false;

          for (int i =0; i<20000;i++){
            if (battle[i].start){
              w =true;
            }
          }
          if(w == false){
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          screen();
          }
        //battles
          for (int i =0; i<20000;i++){
            if (battle[i].start){
              cout << "\033[2J\033[1;1H";
              cout<<"██████╗  █████╗ ████████╗████████╗██╗     ███████╗     \n";
              cout<<"██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝  \n";
              cout<<"██████╔╝███████║   ██║      ██║   ██║     █████╗  \n";
              cout<<"██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝ \n";
              cout<<"██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗\n";
              cout<<"╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝\n";
                cout<<"─────────────────[Battlefield #"<<i<<"]─────────────────"<<endl;
                
            //artillery phase
              //mage
              int Sk,Tk,Ak;
              int ESk,ETk,EAk;
              int rng;
              Sk=0;
              Tk=0;
              Ak=0;
              rng = rand() % 100+1;
              if (battle[i].Mtarget == "Soldiers"){
                for (int m =0;m<battle[i].mage; m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 50+10;battle[i].Esoldier-=c;Sk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}     
                }
              }
              if (battle[i].Mtarget == "Tanks"){
                for (int m =0;m<battle[i].mage;m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 50+1;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              if (battle[i].Mtarget == "Airships"){
                for (int m =0;m<battle[i].mage;m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}
                if (type<25){int c;c =rand() % 50+10;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              for (int m =0;m<battle[i].Emage;m++){
                if (rng>50){int c;c =rand() % 50+10;battle[i].soldier-=c*1.15;pop-=c;ESk+=c;}
                if (rng>=25&&rng<=50){int c;c =rand() % 2+1;if(c == 1){battle[i].tank-=1;pop-=1;ETk+=1;}}
                if (rng<25){int c;c =rand() % 15+1;if(c == 1){battle[i].airship-=1;pop-=100;EAk+=1;}}       
                }
                delay(0.5);
              if(battle[i].mage>0){
              cout<<"<Ally Mage Artillery Fire>"<<endl;
              cout<<" (- "<<Sk<<" Enemy Soldiers)"<<endl;
              cout<<" (- "<<Tk<<" Enemy Tanks)"<<endl;
              cout<<" (- "<<Ak<<" Enemy Airships)"<<endl;
              }

              if(battle[i].Emage>0){
              cout<<"\n<Enemy Mage Artillery Fire>"<<endl;
              cout<<" (- "<<ESk<<" Ally Soldiers)"<<endl;
              cout<<" (- "<<ETk<<" Ally Tanks)"<<endl;
              cout<<" (- "<<EAk<<" Ally Airships)"<<endl;
              }
              //airship
              Sk=0;
              Tk=0;
              Ak=0;
              rng = rand() % 100+1;
              if (battle[i].Atarget == "Soldiers"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type<25){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}       
                }
              }
              if (battle[i].Mtarget == "Tanks"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              if (battle[i].Mtarget == "Airships"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type<25){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              for (int a =0;a<battle[i].Eairship;a++){
                if (rng>50){int c;c =rand() % 1000+100;battle[i].soldier-=c*1.15;pop-=c;ESk+=c;}
                if (rng>=25&&rng<=50){int c;c =rand() % 20+1;battle[i].tank-=c*1.15;pop-=c;ETk+=c;}
                if (rng<25){int c;c =rand() % 4+1;if(c == 1){battle[i].airship-=1;pop-=100;EAk+=1;}}
              }
              delay(0.5);
                 if(battle[i].airship>0){
              cout<<"\n<Ally Airship Bombing>"<<endl;
              cout<<" (- "<<Sk<<" Enemy Soldiers)"<<endl;
              cout<<" (- "<<Tk<<" Enemy Tanks)"<<endl;
              cout<<" (- "<<Ak<<" Enemy Airships)"<<endl;
              }

              if(battle[i].Eairship>0){
              cout<<"\n<Enemy Airship Bombing>"<<endl;
              cout<<" (- "<<ESk<<" Ally Soldiers)"<<endl;
              cout<<" (- "<<ETk<<" Ally Tanks)"<<endl;
              cout<<" (- "<<EAk<<" Ally Airships)"<<endl;
              }
              
              //Ground phase
                  battle[i].field = (battle[i].soldier+battle[i].tank*50)/((battle[i].soldier+battle[i].tank*50)+((battle[i].Esoldier+battle[i].Etank*50)+1000));
                  if (battle[i].field<=0.2){
                    battle[i].start = false;
                  Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  }//shit
                    Tk =0;
                    ETk =0;
                  int k,Ek,ETK,Mk,EMk;
                                      k =0;
                    Ek =0;
                    Mk =0;
                    EMk=0;
                  if (battle[i].field>0.2||battle[i].field<=0.4){
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        k+=1;
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      int type;
                      type = rand() % 20+1;
                      if(type == 1){
                        battle[i].mage-=1;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        Ek+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 3+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      if(type ==2 ){
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                      if(type == 3){
                        int rng;
                      rng = rand() % 50+1;
                      EMk+=rng;
                      }
                    }
                  }
                  if (battle[i].field>0.4||battle[i].field<=0.6){
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Ek+=1;
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        k+=1;
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                    }
              
                  }
                  if (battle[i].field>0.6||battle[i].field<=0.8){
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Ek+=1;
                      }
                    }
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      int type;
                      type = rand() % 20+1;
                      if(type == 1){
                        battle[i].Emage-=1;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        k+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 3+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      if(type ==2 ){
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                      if(type == 3){
                        int rng;
                      rng = rand() % 50+1;
                      Mk+=rng;
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                    }
                  }

                  if (battle[i].field>0.8){
                    battle[i].victory = true;battle[i].start = false;
                  
                  }//dominance]
                  delay(0.5);
                  cout<<"\n<Ground Combat>"<<endl;
                  cout<<" (- "<<k<<" Enemy soldiers)"<<endl;
                  cout<<" (- "<<Tk<<" Enemy tanks)"<<endl;
                  cout<<" (- "<<Mk<<" Enemy mages)"<<endl;
                  cout<<endl;
                  cout<<" (- "<<Ek<<" Ally soldiers)"<<endl;
                  cout<<" (- "<<ETk<<" Ally tanks)"<<endl;
                  cout<<" (- "<<EMk<<" Ally mages)"<<endl;

                  for (int n =0;n<6;n++){
                  if (nation[n].name == battle[i].Ecountry){
                    if(battle[i].defeat){
                      cout<<"██████╗ ███████╗███████╗███████╗ █████╗ ████████╗"<<endl;
                      cout<<"██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗╚══██╔══╝"<<endl;
                      cout<<"██║  ██║█████╗  █████╗  █████╗  ███████║   ██║  " <<endl;
                      cout<<"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██╔══██║   ██║   "<<endl;
                      cout<<"██████╔╝███████╗██║     ███████╗██║  ██║   ██║   "<<endl;
                      cout<<"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝"<<endl;
                      cout<<"After a long period of fighting,"<<battle[i].Ecountry<<" emerged victorious"<<endl;
                      cout<<"You have failed to seize anything and your troops have been imprisonned"<<endl;
                    }
                  if(battle[i].victory){
                    cout << "\033[2J\033[1;1H";
                    cout<<"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗"<<endl;
                    cout<<"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝"<<endl;
                    cout<<"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ "<<endl;
                    cout<<"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  "<<endl;
                    cout<<" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   "<<endl;
                    cout<<"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝ "<<endl;
                    cout<<"After a long period of fighting,"<<name<<" emerged victorious"<<endl;
                    if(battle[i].reason =="Iron"){
                    economy+=10;IMines+=1;
                    nation[n].Imine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Iron Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="Coal"){
                    economy+=10;CMines+=1;
                    nation[n].Cmine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Coal Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="Lead"){
                    economy+=10;LMines+=1;
                     nation[n].Lmine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Lead Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="City"){
                    economy+=10;pop+=5000;
                     nation[n].citiesN-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 city from "<<battle[i].Ecountry;
                  string str;
                  cout<<"Please Choose a name for your new city! (one word)\n";
                  cin>> str;
                  city[cities] =str;
                  cities+=1;
                    }
                  if(battle[i].reason =="Capital"){
                    
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"Congratulation! You have conquered "<<battle[i].Ecountry<<"!\n";
                  cout<<"Everything that once belonged to "<<battle[i].Ecountry<<" now belong to you country"<<endl;
                    economy+=10;
                        IMines += nation[n].Imine;
                        CMines+= nation[n].Cmine;
                        LMines+= nation[n].Lmine;
                        pop += nation[n].Popu;
                        economy += nation[n].eco/2;
                        money+= 1000000;
                        cout<<"Including the cities, therefore please choose a name for evey city:"<<endl;
                        for(int x =0; x<nation[n].citiesN;x++){
                          cout<<"City name:";
                          string str;
                          cin>> str;
                          city[cities] =str;
                          cities+=1;
                          cout<<endl;
                        }
                      }
                    }
                    cout<<"All your troops have succesfully returned to the capital"<<endl;
                    }
                    }
                  }
          
                  }
                
        
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        //initial data
          cout << "──────────────────────[Report]───────────────────────" << endl;
          cout << "----Day " << day << " Outcome----" << endl;
          cout << "Population:   " << pop <<" Habitant" << endl;
          cout << "Money:        " << money<< endl;
          cout << "Iron:         " << iron << endl;
          cout << "Coal:         " << coal<< endl;
          cout << "Lead:         " << lead<< endl;
          cout << "Food:         " << food << endl;
          cout << "Crystal:      " << crystal << endl;
          cout << "Essence:      " << essence << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel<< endl;
          cout << "Munitions:    " << munitions<< endl;
          cout << "Oricalcum:    " << Oricalcum << endl;
          cout << "Mithril:      " << mithril << endl;
        //troop training
          for(int i =0;i<2000;i++){
            if(train[i].built){
              if(train[i].started){
                train[i].dayL-=1;
              }
              else{
               if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                } 
              }
              if (train[i].dayL==0){
                if(train[i].started==true){
                  if(train[i].type =="Barrack"){
                    train[i].started = false;
                    Soldiers+=10;
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    train[i].started = false;
                    Mages+=20;
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    train[i].started = false;
                    Tanks+=1;
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    train[i].started = false;
                    Airships+=1;
                    economy+=5;
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    train[i].started = false;
                    Mecha+=1;
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    train[i].started = false;
                    Angel+=1;
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                }
                }
                else{
                  if(train[i].type =="Barrack"){
                    if(money>=10*salary){
                      money-=10*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Academy"){
                    if(money>=250*salary&&essence>=20){
                      money-=250*salary;
                      essence-=20;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Garage"){
                    if(money>=20*salary&&steel>=1&&munitions>=1){
                      money-=20*salary;
                      munitions-=1;
                      steel-=1;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Hangar"){
                    if(money>=500*salary&&steel>=15){
                      money-=500*salary;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Facility"){
                    if(money>=(2500*salary)&&steel>35&&essence>=10&&Oricalcum>=5&&crystal>=10&&mithril>=10&&munitions>=50){
                      money-=2500*salary;
                      crystal-=10;
                      essence-=10;
                      steel-=35;
                      munitions -=50;
                      Oricalcum-=5;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                    }
                  }
                  if(train[i].type =="Altar"){
                    if(money>=(2100*salary)&&steel>15&&essence>=25&&Oricalcum>=25&&crystal>=15&&mithril>=10){
                      money-=2100*salary;
                      crystal-=15;
                      essence-=25;
                      steel-=15;
                      Oricalcum-=25;
                      mithril-=10;
                      train[i].dayL = train[i].interval;
                      train[i].started = true;
                  }
                }
                }
              }
            }
          }
        //resource
          ressource();
          iron += gained[0] - used[0];
          coal += gained[1] - used[1];
          lead += gained[2] - used[2];
          food += gained[3] - used[3];
          crystal += gained[4] - used[4];
          essence += gained[5] - used[5];
          steel += gained[6] - used[6];
          munitions += gained[7];
          Oricalcum += gained[8] - used[8];
          mithril += gained[9] - used[9];
          popGain = 0;
          if (gained[3] - used[3] >= 0) {
            for (int cp = 0; cp < pop; cp++) {
              int r;
              r = rand() % 100 + 1;
              if (r == 1) {
                pop += 1;
                popGain += 1;
              }
            }
          }
        //trade rng
          resourceID = 0;
          CountryID = 0;
          for(int i =0; i< 61;i++){
            tab[i].offer = false;
          }
          for (int i = 0; i < 61; i++) {
            int offers;
            offers =0;
            switch (resourceID) {
            case 0:
              tab[i].resource = "Iron";
              break;
            case 1:
              tab[i].resource = "Coal";
              break;
            case 2:
              tab[i].resource = "Lead";
              break;
            case 3:
              tab[i].resource = "Food";
              break;
            case 4:
              tab[i].resource = "Crystal";
              break;
            case 5:
              tab[i].resource = "Essence";
              break;
            case 6:
              tab[i].resource = "Steel";
              break;
            case 7:
              tab[i].resource = "Munitions";
              break;
            case 8:
              tab[i].resource = "Oricalcum";
              break;
            case 9:
              tab[i].resource = "Mithril";
              break;

            }
            if (nation[CountryID].sell[resourceID]) {
              tab[i].country = nation[CountryID].name;
              tab[i].price = 20 * cos(day) + ((pricing(resourceID) * 100) / nation[CountryID].prod[resourceID]);
              
              int rng;
              rng = rand() % 2 + 1;
              if (rng == 1) {
                if(offers<=nation[CountryID].trade){
                offers+=1;
                tab[i].offer = true;
                int n;
                if (resourceID == 3) {
                  n = rand() % 20 + 100;
                }
                if (resourceID >= 0 && resourceID <= 2) {
                  n = rand() % 2 + 1;
                }
                if (resourceID >= 4) {
                  n = 1;
                }
                tab[i].qty = n;
                tab[i].offer = true;
              }
              }
            }
            //progression
            resourceID += 1;
            if (resourceID == 10) {
              resourceID = 0;
              CountryID += 1;
              offers =0;
            }
          }
        //end construction
          for (int i = 0; i < total; i++) {
            msg[i].dayL -= 1;
            if (msg[i].dayL <= 0) {
              if (msg[i].complete == true) {
                msg[i].shown();
              } else {
                if (msg[i].type == "Iron Mine") {
                  IMines += 1;
                  Tworkers += 8;
                }
                if (msg[i].type == "Coal Mine") {
                  CMines += 1;
                  Tworkers += 5;
                }
                if (msg[i].type == "Lead Mine") {
                  LMines += 1;
                  Tworkers += 5;
                }
                if (msg[i].type == "Farm") {
                  Farms += 1;
                  Tworkers += 2;
                }
                if (msg[i].type == "Crystalizer") {
                  Crystalizers += 1;
                  Tworkers += 25;
                }
                if (msg[i].type == "Extractor") {
                  Extractors += 1;
                  Tworkers += 20;
                }
                if (msg[i].type == "Smelter") {
                  Smelters += 1;
                  Tworkers += 10;
                }
                if (msg[i].type == "Factory") {
                  Factories += 1;
                  Tworkers += 10;
                }
                if (msg[i].type == "Synthesizer") {
                  Synthesizers += 1;
                  Tworkers += 20;
                }
                if (msg[i].type == "Barrack") {
                  Barrack += 1;
                  train[TrainID].type = "Barrack";
                  train[TrainID].built = true;
                  train[TrainID].interval=2;
                  TrainID+=1;
                }
                if (msg[i].type == "Academy") {
                  Academy += 1;
                  train[TrainID].type = "Academy";
                  train[TrainID].built = true;
                  train[TrainID].interval=50;
                  TrainID+=1;
                }
                if (msg[i].type == "Garage") {
                  Garage += 1;
                  train[TrainID].type = "Garage";
                  train[TrainID].built = true;
                  train[TrainID].interval=2;
                  TrainID+=1;
                }
                if (msg[i].type == "Hangar") {
                  Hangar += 1;
                  train[TrainID].type = "Hangar";
                  train[TrainID].built = true;
                  train[TrainID].interval=50;
                  TrainID+=1;
                }
                if (msg[i].type == "Lab") {
                  Lab += 1;
                }
                if (msg[i].type == "Facility") {
                  Facility += 1;
                  train[TrainID].type = "Facility";
                  train[TrainID].built = true;
                  train[TrainID].interval=100;
                  TrainID+=1;
                }
                if (msg[i].type == "Altar") {
                  Altar += 1;
                  train[TrainID].type = "Altar";
                  train[TrainID].built = true;
                  train[TrainID].interval=100;
                  TrainID+=1;
                }
                if (msg[i].type == "Altar") {
                  cities+=1;
                  pop+=5000;
                  economy +=50;
                }
                msg[i].completed();
              }
            }
          }
        //economy
          economy += (gained[0]+gained[1]+gained[2]+(gained[3]/19)+gained[4]+gained[5]+gained[6]+gained[7]+gained[8]+gained[9])-(used[0]+used[1]+used[2]+(used[3]/20)+used[4]+used[5]+used[6]+used[7]+used[8]+used[9]);
          money += income - upkeep;
         
        //updated data
          cout << "Ending day.." << endl;
          delay(1);
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout << "──────────────────────[Report]───────────────────────" << endl;
          cout << "----Day " << day << " Outcome----" << endl;
          cout << "Population:   " << pop <<" Habitant"<< "(" << popGain << " Habitant)" << endl;
          cout << "Money:        " << money << " " << "$(" << income - upkeep << "$" << ")" << endl;
          cout << "Iron:         " << iron << "(" << gained[0] - used[0] << ")" << endl;
          cout << "Coal:         " << coal << "(" << gained[1] - used[1] << ")" << endl;
          cout << "Lead:         " << lead << "(" << gained[2] - used[2] << ")" << endl;
          cout << "Food:         " << food << "(" << gained[3] - used[3] << ")" << endl;
          cout << "Crystal:      " << crystal << "(" << gained[4] - used[4] << ")" << endl;
          cout << "Essence:      " << essence << "(" << gained[5] - used[5] << ")" << endl;
          cout << "───────────" << endl;
          cout << "Steel:        " << steel << "(" << gained[6] - used[6] << ")" << endl;
          cout << "Munitions:    " << munitions << "(" << gained[7] - used[7] << ")" << endl;
          cout << "Oricalcum:    " << Oricalcum << "(" << gained[8] - used[8] << ")" << endl;
          cout << "Mithril:      " << mithril << "(" << gained[9] - used[9] << ")" << endl;
          day += 1;
          if (food <= 0) {
            pop -= (food - used[3]) * -1;
            TyranyTurn += 1;
            food = 0;
          }
          delay(1);
          w =false;

          for (int i =0; i<20000;i++){
            if (battle[i].start){
              w =true;
            }
          }
          if(w == false){
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          screen();
          }
        //battles
          for (int i =0; i<20000;i++){
            if (battle[i].start){
              cout << "\033[2J\033[1;1H";
              cout<<"██████╗  █████╗ ████████╗████████╗██╗     ███████╗     \n";
              cout<<"██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝  \n";
              cout<<"██████╔╝███████║   ██║      ██║   ██║     █████╗  \n";
              cout<<"██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝ \n";
              cout<<"██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗\n";
              cout<<"╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝\n";
                cout<<"─────────────────[Battlefield #"<<i<<"]─────────────────"<<endl;
                
            //artillery phase
              //mage
              int Sk,Tk,Ak;
              int ESk,ETk,EAk;
              int rng;
              Sk=0;
              Tk=0;
              Ak=0;
              rng = rand() % 100+1;
              if (battle[i].Mtarget == "Soldiers"){
                for (int m =0;m<battle[i].mage; m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 50+10;battle[i].Esoldier-=c;Sk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}     
                }
              }
              if (battle[i].Mtarget == "Tanks"){
                for (int m =0;m<battle[i].mage;m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 50+1;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              if (battle[i].Mtarget == "Airships"){
                for (int m =0;m<battle[i].mage;m++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 20+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 2+1;if(c == 1){battle[i].Etank-=1;Tk+=1;}}
                if (type<25){int c;c =rand() % 50+10;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              for (int m =0;m<battle[i].Emage;m++){
                if (rng>50){int c;c =rand() % 50+10;battle[i].soldier-=c*1.15;pop-=c;ESk+=c;}
                if (rng>=25&&rng<=50){int c;c =rand() % 2+1;if(c == 1){battle[i].tank-=1;pop-=1;ETk+=1;}}
                if (rng<25){int c;c =rand() % 15+1;if(c == 1){battle[i].airship-=1;pop-=100;EAk+=1;}}       
                }
                delay(0.5);
              if(battle[i].mage>0){
              cout<<"<Ally Mage Artillery Fire>"<<endl;
              cout<<" (- "<<Sk<<" Enemy Soldiers)"<<endl;
              cout<<" (- "<<Tk<<" Enemy Tanks)"<<endl;
              cout<<" (- "<<Ak<<" Enemy Airships)"<<endl;
              }

              if(battle[i].Emage>0){
              cout<<"\n<Enemy Mage Artillery Fire>"<<endl;
              cout<<" (- "<<ESk<<" Ally Soldiers)"<<endl;
              cout<<" (- "<<ETk<<" Ally Tanks)"<<endl;
              cout<<" (- "<<EAk<<" Ally Airships)"<<endl;
              }
              //airship
              Sk=0;
              Tk=0;
              Ak=0;
              rng = rand() % 100+1;
              if (battle[i].Atarget == "Soldiers"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type<25){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}       
                }
              }
              if (battle[i].Mtarget == "Tanks"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type>=25&&type<=50){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type<25){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              if (battle[i].Mtarget == "Airships"){
                for (int a =0;a<battle[i].airship;a++){
                  int type;
                  type = rand() % 100+1;
                if (type>50){int c;c =rand() % 5+1;if(c == 1){battle[i].Eairship-=1;Ak+=1;}}
                if (type>=25&&type<=50){int c;c =rand() % 20+1;battle[i].Etank-=c;Tk+=c;}
                if (type<25){int c;c =rand() % 1000+100;battle[i].Esoldier-=c;Sk+=c;}
                }
              }
              for (int a =0;a<battle[i].Eairship;a++){
                if (rng>50){int c;c =rand() % 1000+100;battle[i].soldier-=c*1.15;pop-=c;ESk+=c;}
                if (rng>=25&&rng<=50){int c;c =rand() % 20+1;battle[i].tank-=c*1.15;pop-=c;ETk+=c;}
                if (rng<25){int c;c =rand() % 4+1;if(c == 1){battle[i].airship-=1;pop-=100;EAk+=1;}}
              }
              delay(0.5);
                 if(battle[i].airship>0){
              cout<<"\n<Ally Airship Bombing>"<<endl;
              cout<<" (- "<<Sk<<" Enemy Soldiers)"<<endl;
              cout<<" (- "<<Tk<<" Enemy Tanks)"<<endl;
              cout<<" (- "<<Ak<<" Enemy Airships)"<<endl;
              }

              if(battle[i].Eairship>0){
              cout<<"\n<Enemy Airship Bombing>"<<endl;
              cout<<" (- "<<ESk<<" Ally Soldiers)"<<endl;
              cout<<" (- "<<ETk<<" Ally Tanks)"<<endl;
              cout<<" (- "<<EAk<<" Ally Airships)"<<endl;
              }
              
              //Ground phase
                  battle[i].field = (battle[i].soldier+battle[i].tank*50)/((battle[i].soldier+battle[i].tank*50)+((battle[i].Esoldier+battle[i].Etank*50)+1000));
                  if (battle[i].field<=0.2){
                    battle[i].start = false;
                  Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  }//shit
                    Tk =0;
                    ETk =0;
                  int k,Ek,ETK,Mk,EMk;
                                      k =0;
                    Ek =0;
                    Mk =0;
                    EMk=0;
                  if (battle[i].field>0.2||battle[i].field<=0.4){
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        k+=1;
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      int type;
                      type = rand() % 20+1;
                      if(type == 1){
                        battle[i].mage-=1;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        Ek+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 3+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      if(type ==2 ){
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                      if(type == 3){
                        int rng;
                      rng = rand() % 50+1;
                      EMk+=rng;
                      }
                    }
                  }
                  if (battle[i].field>0.4||battle[i].field<=0.6){
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Ek+=1;
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        k+=1;
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                    }
              
                  }
                  if (battle[i].field>0.6||battle[i].field<=0.8){
                    for(int f =0; f<battle[i].Esoldier;f++){
                      int rng;
                      rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Ek+=1;
                      }
                    }
                    for(int f =0; f<battle[i].soldier;f++){
                      int rng;
                      int type;
                      type = rand() % 20+1;
                      if(type == 1){
                        battle[i].Emage-=1;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        k+=1;
                      }
                      }
                    }
                    for(int f =0; f<battle[i].tank;f++){
                      int type;
                      type = rand() % 3+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      k+=rng;
                      }
                      if(type ==2 ){
                        rng = rand() % 10+1;
                      if (rng <= battle[i].field*10){
                        Tk+=1;
                      }
                      }
                      if(type == 3){
                        int rng;
                      rng = rand() % 50+1;
                      Mk+=rng;
                      }
                    }
                    for(int f =0; f<battle[i].Etank;f++){
                      int type;
                      type = rand() % 2+1;
                      if(type == 1){
                      int rng;
                      rng = rand() % 50+1;
                      Ek+=rng;
                      }
                      else{
                        rng = rand() % 10+1;
                      if (rng > battle[i].field*10){
                        ETk+=1;
                      }
                      }
                    }
                  }

                  if (battle[i].field>0.8){
                    battle[i].victory = true;battle[i].start = false;
                  
                  }//dominance]
                  delay(0.5);
                  cout<<"\n<Ground Combat>"<<endl;
                  cout<<" (- "<<k<<" Enemy soldiers)"<<endl;
                  cout<<" (- "<<Tk<<" Enemy tanks)"<<endl;
                  cout<<" (- "<<Mk<<" Enemy mages)"<<endl;
                  cout<<endl;
                  cout<<" (- "<<Ek<<" Ally soldiers)"<<endl;
                  cout<<" (- "<<ETk<<" Ally tanks)"<<endl;
                  cout<<" (- "<<EMk<<" Ally mages)"<<endl;
                  battle[i].soldier+=battle[i].Isoldier;
                  battle[i].Isoldier =0;
                  battle[i].mage+=battle[i].Image;
                  battle[i].Image =0;
                  battle[i].tank+=battle[i].Itank;
                  battle[i].Itank =0;
                  battle[i].airship+=battle[i].Iairship;
                  battle[i].Iairship =0;
                  if(battle[i].start == false){
                    battle[i].start = false;
                  }

                  for (int n =0;n<6;n++){
                  if (nation[n].name == battle[i].Ecountry){
                    if(battle[i].defeat){
                      cout<<"██████╗ ███████╗███████╗███████╗ █████╗ ████████╗"<<endl;
                      cout<<"██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗╚══██╔══╝"<<endl;
                      cout<<"██║  ██║█████╗  █████╗  █████╗  ███████║   ██║  " <<endl;
                      cout<<"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██╔══██║   ██║   "<<endl;
                      cout<<"██████╔╝███████╗██║     ███████╗██║  ██║   ██║   "<<endl;
                      cout<<"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝"<<endl;
                      cout<<"After a long period of fighting,"<<battle[i].Ecountry<<" emerged victorious"<<endl;
                      cout<<"You have failed to seize anything and your troops have been imprisonned"<<endl;
                    }
                  if(battle[i].victory){
                    cout << "\033[2J\033[1;1H";
                    cout<<"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗"<<endl;
                    cout<<"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝"<<endl;
                    cout<<"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ "<<endl;
                    cout<<"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  "<<endl;
                    cout<<" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   "<<endl;
                    cout<<"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝ "<<endl;
                    cout<<"After a long period of fighting,"<<name<<" emerged victorious"<<endl;
                    if(battle[i].reason =="Iron"){
                    economy+=10;IMines+=1;
                    nation[n].Imine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Iron Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="Coal"){
                    economy+=10;CMines+=1;
                    nation[n].Cmine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Coal Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="Lead"){
                    economy+=10;LMines+=1;
                     nation[n].Lmine-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 Lead Mine from "<<battle[i].Ecountry;
                    }
                  if(battle[i].reason =="City"){
                    economy+=10;pop+=5000;
                     nation[n].citiesN-=1;
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"You have taken 1 city from "<<battle[i].Ecountry;
                  string str;
                  cout<<"Please Choose a name for your new city! (one word)\n";
                  cin>> str;
                  city[cities] =str;
                  cities+=1;
                    }
                  if(battle[i].reason =="Capital"){
                    
                    Soldiers+=battle[i].soldier;
                  Mages+=battle[i].mage;
                  Tanks+=battle[i].tank;
                  Airships+=battle[i].airship;
                  Mecha+=battle[i].mecha;
                  Angel+=battle[i].angel;
                  cout<<"Congratulation! You have conquered "<<battle[i].Ecountry<<"!\n";
                  cout<<"Everything that once belonged to "<<battle[i].Ecountry<<" now belong to you country"<<endl;
                    economy+=10;
                        IMines += nation[n].Imine;
                        CMines+= nation[n].Cmine;
                        LMines+= nation[n].Lmine;
                        pop += nation[n].Popu;
                        economy += nation[n].eco/2;
                        money+= 1000000;
                        cout<<"Including the cities, therefore please choose a name for evey city:"<<endl;
                        for(int x =0; x<nation[n].citiesN;x++){
                          cout<<"City name:";
                          string str;
                          cin>> str;
                          city[cities] =str;
                          cities+=1;
                          cout<<endl;
                        }
                      }
                      cout<<"All your troops have succesfully returned to the capital"<<endl;
                    }
                    
                    }
                    }
                  }
          
                  }
                }
        }
    //view code
      if (comp(a1, "view")||comp(a1,"v")) {
        if(a2 == " "){
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        screen();
        }
        if (comp(a2,"Aldinah")){
          cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          xscreen(0);
        }
        if (comp(a2,"Elfelheim")){
          cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          xscreen(1);
        }
        if (comp(a2,"Knox")){
          cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          xscreen(2);
        }
        if (comp(a2,"Solus")){
          cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          xscreen(3);
        }
        if (comp(a2,"Tartan")){
          cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          xscreen(4);
        }
        if (comp(a2,"Union")){
          cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          xscreen(5);
        }

      }
    //exit code
      if (comp(a1, "exit")) {
        Open = false;
      }
    //battle code
      if(comp(a1,"Battle")||comp(a1,"b")){
       if(a2==" "){
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
       Blist();
          }
       else{
         if (battle[stoi(a2)].start){
           cout << "\033[2J\033[1;1H";
           cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
           bool x = true;
           while(x){
          Masset();
           cout<<"─────────────[Battlefield #"<<a2<<"]─────────────"<<endl;
           cout<<"<"<<name<<">"<<setw(30-name.length())<<"<"<<battle[stoi(a2)].Ecountry<<">"<<endl;
           cout<<"[Friendly Units] [Main Target] [Enemy Units]"<<endl;
           cout<<battle[stoi(a2)].soldier<<setw(21-to_string(battle[stoi(a2)].soldier).length())<<"Soldiers:     "<<battle[stoi(a2)].Starget<<endl;
           cout<<battle[stoi(a2)].mage<<setw(21-to_string(battle[stoi(a2)].mage).length())<<"Mages:        "<<battle[stoi(a2)].Mtarget<<endl;
           cout<<battle[stoi(a2)].tank<<setw(21-to_string(battle[stoi(a2)].tank).length())<<"Tanks:        "<<battle[stoi(a2)].Ttarget<<endl;
           cout<<battle[stoi(a2)].airship<<setw(21-to_string(battle[stoi(a2)].airship).length())<<"Airships:     "<<battle[stoi(a2)].Atarget<<endl;
           cout<<battle[stoi(a2)].mecha<<setw(24-to_string(battle[stoi(a2)].mecha).length())<<"Mechas:       All"<<endl;
           cout<<battle[stoi(a2)].angel<<setw(24-to_string(battle[stoi(a2)].angel).length())<<"Angels:       All"<<endl;
           cout<<Novaspheres<<setw(19-to_string(Novaspheres).length())<<"Novaspheres:"<<endl;
           cout<<endl;
            bool reinforce = false;
           cout<<"<Incoming Reinforcements Tommorow>"<<endl;
           if(battle[stoi(a2)].Isoldier>0){cout<<"Soldiers: "<<battle[stoi(a2)].Isoldier<<endl;reinforce = true;}
           if(battle[stoi(a2)].Image>0){  cout <<"Magess:   "<<battle[stoi(a2)].Image<<endl;reinforce = true;}
           if(battle[stoi(a2)].Itank>0){cout<<"Tanks: "<<battle[stoi(a2)].Itank<<endl;reinforce = true;}
           if(battle[stoi(a2)].Iairship>0){cout<<"Airships: "<<battle[stoi(a2)].Iairship<<endl;reinforce = true;}
           if(battle[stoi(a2)].Imecha>0){cout<<"Mechas: "<<battle[stoi(a2)].Imecha<<endl;reinforce = true;}
           if(battle[stoi(a2)].Iangel>0){cout<<"Angels: "<<battle[stoi(a2)].Iangel<<endl;reinforce = true;}
           if (reinforce ==false){
             cout<<"*No reinforcements"<<endl;
           }
            cout<<endl;  
           if(battle[stoi(a2)].mage>0){
           cout<<"Possible mage unit target: [Soldiers][Tanks][Airships]"<<endl;
           cout<<"Mage Unit target:";
           cin>>line;
           bool exist =false;
           while(exist == false){
           if(comp(line,"soldiers")||comp(line,"soldiers")){battle[stoi(a2)].Mtarget = "Soldiers";exist = true;}
           if(comp(line,"Tanks")||comp(line,"tank")){battle[stoi(a2)].Mtarget = "Tanks";exist = true;}
           if(comp(line,"Airships")||comp(line,"Airship")){battle[stoi(a2)].Mtarget = "Airships";exist = true;}
           if(exist == false){
             cout<<"Not a valid target, try again."<<endl;
             }
           }
           }
           if(battle[stoi(a2)].airship>0){
           cout<<"Possible airship unit target: [Soldiers][Tanks][Airships]"<<endl;
           cout<<"Airship Unit target:";
           cin>>line;
           bool exist =false;
           while(exist == false){
           if(comp(line,"soldiers")||comp(line,"soldiers")){battle[stoi(a2)].Atarget = "Soldiers";exist = true;}
           if(comp(line,"Tanks")||comp(line,"tank")){battle[stoi(a2)].Atarget = "Tanks";exist = true;}
           if(comp(line,"Airships")||comp(line,"Airship")){battle[stoi(a2)].Atarget = "Airships";exist = true;}
              if(exist == false){
             cout<<"Not a valid target, try again."<<endl;
             }
           }
           }
         }
         }
         else{
           cout << "\033[2J\033[1;1H";
           cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          Masset();
          Blist();
          cout<<"Invalid Battle ID. Please Try again.";
         }
       }
      }
    //recruit 
      if(comp(a1,"recruit")||comp(a1,"r")){
        if(a2 == " "){
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"\n──────────[Recruit]───────────"<<endl;
        cout<<"1.Soldiers: 100$ each"<<endl;
        cout<<"2.Mages:    7500$ each"<<endl;
        cout<<"recruit [quantity][soldier or mage]"<<endl;
      }
      else{
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"\n──────────[Recruit]───────────"<<endl;
        bool exist;
        exist = false;
        if(comp(a3,"soldier")||comp(a3,"soldiers")){
          if(money>=stoi(a2)*100){
          exist = true;
          cout<<"Recruiting Soldiers"<<endl;
          cout<<"Number:  "<<a2<<" soldiers"<<endl;
          cout<<"Cost:    "<<stoi(a2)*100<<"$"<<endl;
          cout<<"Confirm?(y/n)"<<endl;
          cin>>line;
          if(comp(line,"y")){
            money-=stoi(a2)*100;
            cout<<"*Recruited "<<a2<<" Soldiers"<<endl;
            Soldiers += stoi(a2);
            pop+=stoi(a2);
            delay(0.5);
            
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"\n──────────[Recruit]───────────"<<endl;
        cout<<"1.Soldiers: 100$ each"<<endl;
        cout<<"2.Mages:    7500$ each"<<endl;
        cout<<"recruit [quantity][soldier or mage]"<<endl;
          }
          if (comp(line,"n")){
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"\n──────────[Recruit]───────────"<<endl;
        cout<<"Soldiers: 100$ each"<<endl;
        cout<<"Mages:    7500$ each"<<endl;
        cout<<"recruit [quantity][soldier or mage]"<<endl;
          }
          
          }
          else{
          cout<<"Soldiers: 100$ each"<<endl;
        cout<<"Mages:      7500$ each"<<endl;
        cout<<"recruit [quantity][soldier or mage]"<<endl;
        cout<<"Not enought money!("<<100*stoi(a2)-money<<endl;
          }
        }
        if(comp(a3,"mage")||comp(a3,"mages")){
          if(money>=stoi(a2)*7500){
          exist = true;
          cout<<"Recruiting Mages"<<endl;
          cout<<"Number:  "<<a2<<" mages"<<endl;
          cout<<"Cost:    "<<stoi(a2)*7500<<"$"<<endl;
          cout<<"Confirm?(y/n)"<<endl;
          cin>>line;
          if(comp(line,"y")){
            money-=stoi(a2)*7500;
            cout<<"*Recruited "<<a2<<" Mages"<<endl;
            Mages += stoi(a2);
            pop+=stoi(a2);
            delay(0.5);
            
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"\n──────────[Recruit]───────────"<<endl;
        cout<<"1.Soldiers: 100$ each"<<endl;
        cout<<"2.Mages:    7500$ each"<<endl;
        cout<<"recruit [quantity][soldier or mage]"<<endl;
          }
          if (comp(line,"n")){
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"\n──────────[Recruit]───────────"<<endl;
        cout<<"1.Soldiers: 100$ each"<<endl;
        cout<<"2.Mages:    7500$ each"<<endl;
        cout<<"recruit [quantity][soldier or mage]"<<endl;
          }
          }
          else{
          cout<<"1.Soldiers: 100$ each"<<endl;
          cout<<"2.Mages:    7500$ each"<<endl;
          cout<<"recruit [quantity][soldier or mage]"<<endl;
          cout<<"Not enought money!("<<7500*stoi(a2)-money<<endl;
          }
        }
      }
      }
      
    //deploy code
      if (comp(a1,"deploy")||comp(a1,"d")){
        string input;
        if(a2 == " "){
        cout << "\033[2J\033[1;1H";
        cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
        Masset();
        cout<<"──────────────[Battle List]──────────────"<<endl;
         cout<<"[ID][Country][Reason][Progression]"<<endl;
         for(int i = 0; i<63;i++){
           if(battle[i].soldier ==0){
             cout<<"[";
             if(i<10){cout<<"0";}
             cout<<i<<"] "<<battle[i].Ecountry<<setw(10-battle[i].Ecountry.length()+battle[i].reason.length())<<battle[i].reason<<setw(5-battle[i].reason.length()+to_string(battle[i].Aprogress).length()+to_string(battle[i].Eprogress).length()+3)<<floor(battle[i].field)<<endl;
           }
  }

        }
        else{
          input = a2;
          cout<<"─────────────[Battlefield #"<<input<<"]─────────────"<<endl;
           cout<<"<"<<name<<">"<<setw(30-name.length())<<"<"<<battle[stoi(input)].Ecountry<<">"<<endl;
           cout<<"[Friendly Units] [Main Target] [Enemy Units]"<<endl;
           cout<<battle[stoi(input)].soldier<<setw(21-to_string(battle[stoi(input)].soldier).length())<<"Soldiers:     "<<battle[stoi(input)].Starget<<endl;
           cout<<battle[stoi(input)].mage<<setw(21-to_string(battle[stoi(input)].mage).length())<<"Mages:        "<<battle[stoi(input)].Mtarget<<endl;
           cout<<battle[stoi(input)].tank<<setw(21-to_string(battle[stoi(input)].tank).length())<<"Tanks:        "<<battle[stoi(input)].Ttarget<<endl;
           cout<<battle[stoi(input)].airship<<setw(21-to_string(battle[stoi(input)].airship).length())<<"Airships:     "<<battle[stoi(input)].Atarget<<endl;
           cout<<battle[stoi(input)].mecha<<setw(24-to_string(battle[stoi(input)].mecha).length())<<"Mechas:       All"<<endl;
           cout<<battle[stoi(input)].angel<<setw(24-to_string(battle[stoi(input)].angel).length())<<"Angels:       All"<<endl;
           cout<<Novaspheres<<setw(19-to_string(Novaspheres).length())<<"Novaspheres"<<endl;
           cout<<endl;
           int ID;
           ID = stoi(input);
           if(Soldiers>0){
           cout<<"Number of Soliders to deploy:";cin>>input;
           if(Soldiers>=stoi(input)){
           battle[ID].Isoldier += stoi(input);
           }
           else{
             cout<<"You do not have "<<input<<" soldiers availlable, sent "<<Soldiers<<" instead."<<endl;
             battle[ID].Isoldier += Soldiers;
           }
           }
           else{
             cout<<"No Soldiers Availlable"<<endl;
           }
           if(Mages>0){
           cout<<"Number of Mages to deploy:";cin>>input;
           if(Mages>=stoi(input)){
           battle[ID].Image += stoi(input);
           }
           else{
             cout<<"You do not have "<<input<<" mages availlable, sent "<<Mages<<" instead."<<endl;
             battle[ID].Image += Mages;
           }
           }
           else{
             cout<<"No Mages Availlable"<<endl;
           }
           if (Tanks>0){
           cout<<"Number of Tanks to deploy:";cin>>input;
           if(Tanks>=stoi(input)){
           battle[ID].Itank += stoi(input);
           }
           else{
             cout<<"You do not have "<<input<<" tanks availlable, sent "<<Tanks<<" instead."<<endl;
             battle[ID].Itank += Tanks;
           }
           }
           else{
             cout<<"No Tanks Availlable"<<endl;
           }
           if(Airships>0){
           cout<<"Number of Airships to deploy:";cin>>input;
           if(Airships>=stoi(input)){
           battle[ID].Iairship += stoi(input);
           }
           else{
             cout<<"You do not have "<<input<<" airships availlable, sent "<<Airships<<" instead."<<endl;
             battle[ID].Iairship += Airships;
           }
           }
           else{
             cout<<"No Airships Availlable"<<endl;
           }
           if(Mecha>0){
           cout<<"Number of Mechas to deploy:";cin>>input;
           if(Mecha>=stoi(input)){
           battle[ID].Imecha += stoi(input);
           }
           else{
             cout<<"You do not have "<<input<<" mechas availlable, sent "<<Mecha<<" instead."<<endl;
             battle[ID].mecha +=Mecha;
           }
          }
          else{
             cout<<"No Mechas Availlable"<<endl;
           }
          if(Angel>0){
           cout<<"Number of Angels to deploy:";cin>>input;
           if(Angel>=stoi(input)){
           battle[ID].Iangel += stoi(input);
           }
           else{
             cout<<"You do not have "<<input<<" angels availlable, sent "<<Angel<<" instead."<<endl;
             battle[ID].Iangel += Angel;
           }
           }
           else{
             cout<<"No Angels Availlable"<<endl;
           } 
        }
      }
    //debug
      if(comp(a1,"debug")){
        cout<<train[stoi(a2)].built<<endl;
        cout<<train[stoi(a2)].dayL<<endl;
        cout<<train[stoi(a2)].interval<<endl;
        cout<<train[stoi(a2)].started<<endl;
      }
    //sell code
      if (comp(a1,"Sell")){
      acceptable = false;
        if(a3 == " "){
          cout<<"Please try again and specify a quantity and a resource\n sell [quantity] [resource]"<<endl;
        }
        if (comp(a3,"Iron")){
          if(iron>=stoi(a2)){
          resource ="iron";
          acceptable = true;
          expectation = 100*cos(day)+pricing(0);
          }
          else{
            cout<<"You do not own "<<a2<<" iron! (You have "<<iron<<").\n";
          }
        }
        if (comp(a3,"Coal")){
          if(coal>=stoi(a2)){
          resource ="coal";
          acceptable = true;
          expectation = 100*cos(day)+pricing(1);
          }
          else{
            cout<<"You do not own "<<a2<<" coal! (You have "<<coal<<").\n";
          }
        }
        if (comp(a3,"LEad")){
          if(lead>=stoi(a2)){
          resource ="lead";
          acceptable = true;
        expectation = 100*cos(day)+pricing(2);
        }
          else{
            cout<<"You do not own "<<a2<<" lead! (You have "<<lead<<").\n";
          }
        }
        if (comp(a3,"Food")){
          if(food>=stoi(a2)){
          resource ="food";
          acceptable = true;
          expectation = 10*cos(day)+pricing(3);
          }
          else{
            cout<<"You do not own "<<a2<<" food! (You have "<<food<<").\n";
          }
        }
        if (comp(a3,"Crystal")){
          if(crystal>=stoi(a2)){
          resource ="crystal";
          acceptable = true;
          expectation = 100*cos(day)+pricing(4);
          }
          else{
            cout<<"You do not own "<<a2<<" crystal! (You have "<<crystal<<").\n";
          }
        }
        if (comp(a3,"Essence")){
          if(essence>=stoi(a2)){
          resource ="esssence";
          acceptable = true;
          expectation = 100*cos(day)+pricing(5);
          }
          else{
            cout<<"You do not own "<<a2<<" essence! (You have "<<essence<<").\n";
          }
        }
        if (comp(a3,"Steel")){
          if(steel>=stoi(a2)){
          resource ="steel";
          acceptable = true;
          expectation = 100*cos(day)+pricing(6);
          }
          else{
            cout<<"You do not own "<<a2<<" steel! (You have "<<steel<<").\n";
          }
        }
        if (comp(a3,"Munitions")){
          if(munitions>=stoi(a2)){
          resource ="munitions";
          acceptable = true;
          expectation = 100*cos(day)+pricing(7);
          }
          else{
            cout<<"You do not own "<<a2<<" munitions! (You have "<<munitions<<").\n";
          }
        }
        if (comp(a3,"Oricalcum")){
          if(Oricalcum>=stoi(a2)){
          resource ="oricalcum";
          acceptable = true;
          expectation = 100*cos(day)+pricing(8);
          }
          else{
            cout<<"You do not own "<<a2<<" oricalcum! (You have "<<Oricalcum<<").\n";
          }
        }
        if (comp(a3,"Mithril")){
          if(mithril>=stoi(a2)){
          resource ="mithril";
          acceptable = true;
          expectation = 100*cos(day)+pricing(9);
          }
          else{
            cout<<"You do not own "<<a2<<" mithril! (You have"<<mithril<<").\n";
          }
        }
        if (acceptable){
          cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
          cout<<"────────────<Sales>───────────"<<endl;
          cout<<"Selling "<<a2<<" "<<resource<<endl;
          cout<<"Expected price per unit: "<<expectation-(100*cos(day))-100<<"$〜"<<expectation-(100*cos(day))+100<<"$"<<endl;
          cout<<"Expected sales:"<<(expectation-(100*cos(day))-100)*stoi(a2)<<"$〜"<<(expectation-(100*cos(day))+100)*stoi(a2)<<"$"<<endl;
          cout<<"Confirm?(y/n)"<<endl;
          cin >> line;
          if (comp(line,"y")){
            cout<<"*Sold "<<a2<<" "<<resource<<" for "<<expectation*stoi(a2)<<"$"<<endl;
            delay(1);
            money+= expectation*stoi(a2); 
            cout << "\033[2J\033[1;1H";
            cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
            screen();
          }
          if (comp(line,"n")){
            cout << "\033[2J\033[1;1H";
          cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
            screen();
          }
          }
      }
  }
//input management
  void xstart() {
    getline(cin, line);
    c = 0;
    d = 0;
    b = 0;
    a = 0;
    while (a != line.length()) {
      if (line[a] == ' ') {
        i[b] = line.substr(d, c);
        c = -1;
        d = a + 1;
        b += 1;
      }
      a += 1;
      c += 1;
    }
    switch (b) {
    case 0:
      i[0] = line;
      i[1] = " ";
      i[2] = " ";
      i[3] = " ";
      i[4] = " ";
      break;

    case 1:
      i[1] = line.substr(d, c);
      i[2] = " ";
      i[3] = " ";
      i[4] = " ";
      break;
    case 2:
      i[2] = line.substr(d, c);
      i[3] = " ";
      i[4] = " ";
      break;
    case 3:
      i[3] = line.substr(d, c);
      i[4] = " ";
      break;
    }
    get(i[0], i[1], i[2], i[3]);
  }
//introduction 
  void intro(bool start) {
    if (start) {cout<<"██╗  ██╗██╗███╗   ██╗ ██████╗ ██████╗  ██████╗ ███╗   ███╗    ███████╗██╗███╗   ███╗"<<endl;
cout<<"██║ ██╔╝██║████╗  ██║██╔════╝ ██╔══██╗██╔═══██╗████╗ ████║    ██╔════╝██║████╗ ████║"<<endl;
cout<<"█████╔╝ ██║██╔██╗ ██║██║  ███╗██║  ██║██║   ██║██╔████╔██║    ███████╗██║██╔████╔██║"<<endl;
cout<<"██╔═██╗ ██║██║╚██╗██║██║   ██║██║  ██║██║   ██║██║╚██╔╝██║    ╚════██║██║██║╚██╔╝██║"<<endl;
cout<<"██║  ██╗██║██║ ╚████║╚██████╔╝██████╔╝╚██████╔╝██║ ╚═╝ ██║    ███████║██║██║ ╚═╝ ██║"<<endl;
cout<<"╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝     ╚═╝    ╚══════╝╚═╝╚═╝     ╚═╝"<<endl;
      cout << "Welcome to Kingdom Simulator" << endl;
      delay(0.5);
      cout << "The game takes place in another world where magic co-exists with machinery."<<endl;
      delay(1.8);
      cout << "After a long period of diplomatic discussions, you are finally able to proclaim your nation as a new country." << endl << endl;
      delay(1.25);
      cout << "The country is brand new and only has 1 city, the capital." << endl;
      delay(0.5);
      cout << "The capital city is the most important one, if it is lost, your nation will be considered destroyed and you will lose tha game." << endl << endl;
      delay(1.5);
      cout << "Anyways, let's get this started!" << endl;
      delay(0.5);
      cout << "So first of all, your country needs a name!" << endl;
      delay(0.5);
      cout << "I suggest putting \"The\" in front of your country's name if its includes a title like kingdom or empire." << endl;
      delay(0.5);
      cout << "Kingdom name : ";
      getline(cin, name);
      cout << "Now then, just to confirm, is your country " << name << "?(y/n)" << endl;
      cin >> line;
      while (comp(line, "y") != true) {
        cin.ignore();
        cout << "Kingdom name : ";
        getline(cin, name);
        cout << "Now then, just to confirm, is your country " << name << "?(y/n)" << endl;
        cin >> line;
      }
      cout << "\033[2J\033[1;1H";
      cout << "Initializing..." << endl;
      delay(2);
      cout << "\033[2J\033[1;1H";
      cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
      screen();
      cout << "*type \"help\" for the command list" << endl;
    } else {
      name = "Default";
      cout << "\033[2J\033[1;1H";
      cout<<name<<" (Day "<<day<<")   "<<money<<"$\n";
      screen();
    }
  }
int main() {
  //variables
  string Ecountry;
    bool start,victory,defeat;
    int Isoldier,Image,Itank,Iairship,Imecha,Iangel;
    int field;
    string Starget,Mtarget,Ttarget,Atarget;
    int soldier,mage,tank,airship,mecha,angel,runecanon,novasphere;
    int Esoldier,Emage,Etank,Eairship,Emecha,Eangel,Erunecanon,Enovasphere;
    string reason;
    //battle initialization
      battle[0].Ecountry = "Aldinah";
      battle[0].Starget = "Soldiers";
      battle[0].Mtarget = "Soldiers";
      battle[0].Ttarget = "Soldiers";
      battle[0].Atarget = "Airships";
      battle[0].soldier = 0;
      battle[0].mage =0;
      battle[0].tank =0;
      battle[0].airship =0;
      battle[0].Emage = 50;
      battle[0].Esoldier = 10000;
      battle[0].Eairship = 50;
      battle[0].Etank =0;
      battle[0].start =false;
      battle[0].victory =false;
      battle[0].defeat = false;
        battle[0].reason = "Iron";

      battle[1].Ecountry = "Aldinah";
      battle[1].Starget = "Soldiers";
      battle[1].Mtarget = "Soldiers";
      battle[1].Ttarget = "Soldiers";
      battle[1].Atarget = "Airships";
      battle[1].soldier = 0;
      battle[1].mage =0;
      battle[1].tank =0;
      battle[1].airship =0;
      battle[1].Emage = 50;
      battle[1].Esoldier = 10000;
      battle[1].Eairship = 50;
      battle[1].Etank =0;
      battle[1].start =false;
      battle[1].victory =false;
      battle[1].defeat = false;
      battle[1].reason = "Coal";

      battle[2].Ecountry = "Aldinah";
      battle[2].Starget = "Soldiers";
      battle[2].Mtarget = "Soldiers";
      battle[2].Ttarget = "Soldiers";
      battle[2].Atarget = "Airships";
      battle[2].soldier = 0;
      battle[2].mage =0;
      battle[2].tank =0;
      battle[2].airship =0;
      battle[2].Emage = 50;
      battle[2].Esoldier = 10000;
      battle[2].Eairship = 50;
      battle[2].Etank =0;
      battle[2].start =false;
      battle[2].victory =false;
      battle[2].defeat = false;
      battle[2].reason = "Coal";

      battle[3].Ecountry = "Aldinah";
      battle[3].Starget = "Soldiers";
      battle[3].Mtarget = "Soldiers";
      battle[3].Ttarget = "Soldiers";
      battle[3].Atarget = "Airships";
      battle[3].soldier = 0;
      battle[3].mage =0;
      battle[3].tank =0;
      battle[3].airship =0;
      battle[3].Emage = 50;
      battle[3].Esoldier = 10000;
      battle[3].Eairship = 50;
      battle[3].Etank =0;
      battle[3].start =false;
      battle[3].victory =false;
      battle[3].defeat = false;
      battle[3].reason = "Lead";

      battle[4].Ecountry = "Aldinah";
      battle[4].Starget = "Soldiers";
      battle[4].Mtarget = "Soldiers";
      battle[4].Ttarget = "Soldiers";
      battle[4].Atarget = "Airships";
      battle[4].soldier = 0;
      battle[4].mage =0;
      battle[4].tank =0;
      battle[4].airship =0;
      battle[4].Emage = 50;
      battle[4].Esoldier = 10000;
      battle[4].Eairship = 50;
      battle[4].Etank =0;
      battle[4].start =false;
      battle[4].victory =false;
      battle[4].defeat = false;
      battle[4].reason = "City";

      battle[5].Ecountry = "Aldinah";
      battle[5].Starget = "Soldiers";
      battle[5].Mtarget = "Soldiers";
      battle[5].Ttarget = "Soldiers";
      battle[5].Atarget = "Airships";
      battle[5].soldier = 0;
      battle[5].mage =0;
      battle[5].tank =0;
      battle[5].airship =0;
      battle[5].Emage = 50;
      battle[5].Esoldier = 10000;
      battle[5].Eairship = 50;
      battle[5].Etank =0;
      battle[5].start =false;
      battle[5].victory =false;
      battle[5].defeat = false;
      battle[5].reason = "City";

      battle[6].Ecountry = "Aldinah";
      battle[6].Starget = "Soldiers";
      battle[6].Mtarget = "Soldiers";
      battle[6].Ttarget = "Soldiers";
      battle[6].Atarget = "Airships";
      battle[6].soldier = 0;
      battle[6].mage =0;
      battle[6].tank =0;
      battle[6].airship =0;
      battle[6].Emage = 50;
      battle[6].Esoldier = 10000;
      battle[6].Eairship = 50;
      battle[6].Etank =0;
      battle[6].start =false;
      battle[6].victory =false;
      battle[6].defeat = false;
      battle[6].reason = "City";

      battle[7].Ecountry = "Aldinah";
      battle[7].Starget = "Soldiers";
      battle[7].Mtarget = "Soldiers";
      battle[7].Ttarget = "Soldiers";
      battle[7].Atarget = "Airships";
      battle[7].soldier = 0;
      battle[7].mage =0;
      battle[7].tank =0;
      battle[7].airship =0;
      battle[7].Emage = 50;
      battle[7].Esoldier = 10000;
      battle[7].Eairship = 50;
      battle[7].Etank =0;
      battle[7].start =false;
      battle[7].victory =false;
      battle[7].defeat = false;
      battle[7].reason = "City";

      battle[8].Ecountry = "Aldinah";
      battle[8].Starget = "Soldiers";
      battle[8].Mtarget = "Soldiers";
      battle[8].Ttarget = "Soldiers";
      battle[8].Atarget = "Airships";
      battle[8].soldier = 0;
      battle[8].mage =0;
      battle[8].tank =0;
      battle[8].airship =0;
      battle[8].Emage = 50;
      battle[8].Esoldier = 10000;
      battle[8].Eairship = 50;
      battle[8].Etank =0;
      battle[8].start =false;
      battle[8].victory =false;
      battle[8].defeat = false;
      battle[8].reason = "City";

      battle[9].Ecountry = "Aldinah";
      battle[9].Starget = "Soldiers";
      battle[9].Mtarget = "Soldiers";
      battle[9].Ttarget = "Soldiers";
      battle[9].Atarget = "Airships";
      battle[9].soldier = 0;
      battle[9].mage =0;
      battle[9].tank =0;
      battle[9].airship =0;
      battle[9].Emage = 10;
      battle[9].Esoldier = 50000;
      battle[9].Eairship = 100;
      battle[9].Etank =0;
      battle[9].start =false;
      battle[9].victory =false;
      battle[9].defeat = false;
      battle[9].reason = "Capital";

      battle[10].Ecountry = "Elfelheim";
      battle[10].Starget = "Soldiers";
      battle[10].Mtarget = "Soldiers";
      battle[10].Ttarget = "Soldiers";
      battle[10].Atarget = "Airships";
      battle[10].soldier = 0;
      battle[10].mage =0;
      battle[10].tank =0;
      battle[10].airship =0;
      battle[10].Emage = 5000;
      battle[10].Esoldier = 100000;
      battle[10].Eairship = 0;
      battle[10].Etank =0;
      battle[10].start =false;
      battle[10].victory =false;
      battle[10].defeat = false;
      battle[10].reason = "Coal";

      battle[11].Ecountry = "Elfelheim";
      battle[11].Starget = "Soldiers";
      battle[11].Mtarget = "Soldiers";
      battle[11].Ttarget = "Soldiers";
      battle[11].Atarget = "Airships";
      battle[11].soldier = 0;
      battle[11].mage =0;
      battle[11].tank =0;
      battle[11].airship =0;
      battle[11].Emage = 5000;
      battle[11].Esoldier = 110000;
      battle[11].Eairship = 0;
      battle[11].Etank =0;
      battle[11].start =false;
      battle[11].victory =false;
      battle[11].defeat = false;
      battle[11].reason = "City";
      
      battle[12].Ecountry = "Elfelheim";
      battle[12].Starget = "Soldiers";
      battle[12].Mtarget = "Soldiers";
      battle[12].Ttarget = "Soldiers";
      battle[12].Atarget = "Airships";
      battle[12].soldier = 0;
      battle[12].mage =0;
      battle[12].tank =0;
      battle[12].airship =0;
      battle[12].Emage = 5000;
      battle[12].Esoldier = 110000;
      battle[12].Eairship = 0;
      battle[12].Etank =0;
      battle[12].start =false;
      battle[12].victory =false;
      battle[12].defeat = false;
      battle[12].reason = "City";

      battle[13].Ecountry = "Elfelheim";
      battle[13].Starget = "Soldiers";
      battle[13].Mtarget = "Soldiers";
      battle[13].Ttarget = "Soldiers";
      battle[13].Atarget = "Airships";
      battle[13].soldier = 0;
      battle[13].mage =0;
      battle[13].tank =0;
      battle[13].airship =0;
      battle[13].Emage = 10000;
      battle[13].Esoldier = 400000;
      battle[13].Eairship = 0;
      battle[13].Etank =0;
      battle[13].start =false;
      battle[13].victory =false;
      battle[13].defeat = false;
      battle[13].reason = "Capital";

      battle[14].Ecountry = "Knox";
      battle[14].Starget = "Soldiers";
      battle[14].Mtarget = "Soldiers";
      battle[14].Ttarget = "Soldiers";
      battle[14].Atarget = "Airships";
      battle[14].soldier = 0;
      battle[14].mage =0;
      battle[14].tank =0;
      battle[14].airship =0;
      battle[14].Emage = 0;
      battle[14].Esoldier = 100000;
      battle[14].Eairship = 50;
      battle[14].Etank =1000;
      battle[14].start =false;
      battle[14].victory =false;
      battle[14].defeat = false;
      battle[14].reason = "Iron";

      battle[15].Ecountry = "Knox";
      battle[15].Starget = "Soldiers";
      battle[15].Mtarget = "Soldiers";
      battle[15].Ttarget = "Soldiers";
      battle[15].Atarget = "Airships";
      battle[15].soldier = 0;
      battle[15].mage =0;
      battle[15].tank =0;
      battle[15].airship =0;
      battle[15].Emage = 0;
      battle[15].Esoldier = 100000;
      battle[15].Eairship = 50;
      battle[15].Etank =1000;
      battle[15].start =false;
      battle[15].victory =false;
      battle[15].defeat = false;
      battle[15].reason = "Iron";

      battle[16].Ecountry = "Knox";
      battle[16].Starget = "Soldiers";
      battle[16].Mtarget = "Soldiers";
      battle[16].Ttarget = "Soldiers";
      battle[16].Atarget = "Airships";
      battle[16].soldier = 0;
      battle[16].mage =0;
      battle[16].tank =0;
      battle[16].airship =0;
      battle[16].Emage = 0;
      battle[16].Esoldier = 100000;
      battle[16].Eairship = 50;
      battle[16].Etank =1000;
      battle[16].start =false;
      battle[16].victory =false;
      battle[16].defeat = false;
      battle[16].reason = "Coal";

      battle[17].Ecountry = "Knox";
      battle[17].Starget = "Soldiers";
      battle[17].Mtarget = "Soldiers";
      battle[17].Ttarget = "Soldiers";
      battle[17].Atarget = "Airships";
      battle[17].soldier = 0;
      battle[17].mage =0;
      battle[17].tank =0;
      battle[17].airship =0;
      battle[17].Emage = 0;
      battle[17].Esoldier = 100000;
      battle[17].Eairship = 50;
      battle[17].Etank =1000;
      battle[17].start =false;
      battle[17].victory =false;
      battle[17].defeat = false;
      battle[17].reason = "Coal";

      battle[18].Ecountry = "Knox";
      battle[18].Starget = "Soldiers";
      battle[18].Mtarget = "Soldiers";
      battle[18].Ttarget = "Soldiers";
      battle[18].Atarget = "Airships";
      battle[18].soldier = 0;
      battle[18].mage =0;
      battle[18].tank =0;
      battle[18].airship =0;
      battle[18].Emage = 0;
      battle[18].Esoldier = 100000;
      battle[18].Eairship = 50;
      battle[18].Etank =1000;
      battle[18].start =false;
      battle[18].victory =false;
      battle[18].defeat = false;
      battle[18].reason = "Lead";

      battle[19].Ecountry = "Knox";
      battle[19].Starget = "Soldiers";
      battle[19].Mtarget = "Soldiers";
      battle[19].Ttarget = "Soldiers";
      battle[19].Atarget = "Airships";
      battle[19].soldier = 0;
      battle[19].mage =0;
      battle[19].tank =0;
      battle[19].airship =0;
      battle[19].Emage = 0;
      battle[19].Esoldier = 100000;
      battle[19].Eairship = 50;
      battle[19].Etank =1000;
      battle[19].start =false;
      battle[19].victory =false;
      battle[19].defeat = false;
      battle[19].reason = "Lead";

      battle[20].Ecountry = "Knox";
      battle[20].Starget = "Soldiers";
      battle[20].Mtarget = "Soldiers";
      battle[20].Ttarget = "Soldiers";
      battle[20].Atarget = "Airships";
      battle[20].soldier = 0;
      battle[20].mage =0;
      battle[20].tank =0;
      battle[20].airship =0;
      battle[20].Emage = 0;
      battle[20].Esoldier = 100000;
      battle[20].Eairship = 50;
      battle[20].Etank =1000;
      battle[20].start =false;
      battle[20].victory =false;
      battle[20].defeat = false;
      battle[20].reason = "City";

      battle[21].Ecountry = "Knox";
      battle[21].Starget = "Soldiers";
      battle[21].Mtarget = "Soldiers";
      battle[21].Ttarget = "Soldiers";
      battle[21].Atarget = "Airships";
      battle[21].soldier = 0;
      battle[21].mage =0;
      battle[21].tank =0;
      battle[21].airship =0;
      battle[21].Emage = 0;
      battle[21].Esoldier = 100000;
      battle[21].Eairship = 50;
      battle[21].Etank =1000;
      battle[21].start =false;
      battle[21].victory =false;
      battle[21].defeat = false;
      battle[21].reason = "City";

      battle[22].Ecountry = "Knox";
      battle[22].Starget = "Soldiers";
      battle[22].Mtarget = "Soldiers";
      battle[22].Ttarget = "Soldiers";
      battle[22].Atarget = "Airships";
      battle[22].soldier = 0;
      battle[22].mage =0;
      battle[22].tank =0;
      battle[22].airship =0;
      battle[22].Emage = 0;
      battle[22].Esoldier = 100000;
      battle[22].Eairship = 50;
      battle[22].Etank =1000;
      battle[22].start =false;
      battle[22].victory =false;
      battle[22].defeat = false;
      battle[22].reason = "City";

      battle[23].Ecountry = "Knox";
      battle[23].Starget = "Soldiers";
      battle[23].Mtarget = "Soldiers";
      battle[23].Ttarget = "Soldiers";
      battle[23].Atarget = "Airships";
      battle[23].soldier = 0;
      battle[23].mage =0;
      battle[23].tank =0;
      battle[23].airship =0;
      battle[23].Emage = 0;
      battle[23].Esoldier = 100000;
      battle[23].Eairship = 50;
      battle[23].Etank =1000;
      battle[23].start =false;
      battle[23].victory =false;
      battle[23].defeat = false;
      battle[23].reason = "City";

      battle[24].Ecountry = "Knox";
      battle[24].Starget = "Soldiers";
      battle[24].Mtarget = "Soldiers";
      battle[24].Ttarget = "Soldiers";
      battle[24].Atarget = "Airships";
      battle[24].soldier = 0;
      battle[24].mage =0;
      battle[24].tank =0;
      battle[24].airship =0;
      battle[24].Emage = 0;
      battle[24].Esoldier = 100000;
      battle[24].Eairship = 50;
      battle[24].Etank =1000;
      battle[24].start =false;
      battle[24].victory =false;
      battle[24].defeat = false;
      battle[24].reason = "City";

      battle[25].Ecountry = "Knox";
      battle[25].Starget = "Soldiers";
      battle[25].Mtarget = "Soldiers";
      battle[25].Ttarget = "Soldiers";
      battle[25].Atarget = "Airships";
      battle[25].soldier = 0;
      battle[25].mage =0;
      battle[25].tank =0;
      battle[25].airship =0;
      battle[25].Emage = 0;
      battle[25].Esoldier = 100000;
      battle[25].Eairship = 50;
      battle[25].Etank =1000;
      battle[25].start =false;
      battle[25].victory =false;
      battle[25].defeat = false;
      battle[25].reason = "City";

      battle[26].Ecountry = "Knox";
      battle[26].Starget = "Soldiers";
      battle[26].Mtarget = "Soldiers";
      battle[26].Ttarget = "Soldiers";
      battle[26].Atarget = "Airships";
      battle[26].soldier = 0;
      battle[26].mage =0;
      battle[26].tank =0;
      battle[26].airship =0;
      battle[26].Emage = 0;
      battle[26].Esoldier = 300000;
      battle[26].Eairship = 100;
      battle[26].Etank =1500;
      battle[26].start =false;
      battle[26].victory =false;
      battle[26].defeat = false;
      battle[26].reason = "Capital";

      battle[27].Ecountry = "Solus";
      battle[27].Starget = "Soldiers";
      battle[27].Mtarget = "Soldiers";
      battle[27].Ttarget = "Soldiers";
      battle[27].Atarget = "Airships";
      battle[27].soldier = 0;
      battle[27].mage =0;
      battle[27].tank =0;
      battle[27].airship =0;
      battle[27].Emage = 150;
      battle[27].Esoldier = 500000;
      battle[27].Eairship = 5;
      battle[27].Etank =10;
      battle[27].start =false;
      battle[27].victory =false;
      battle[27].defeat = false;
      battle[27].reason = "Iron";

      battle[28].Ecountry = "Solus";
      battle[28].Starget = "Soldiers";
      battle[28].Mtarget = "Soldiers";
      battle[28].Ttarget = "Soldiers";
      battle[28].Atarget = "Airships";
      battle[28].soldier = 0;
      battle[28].mage =0;
      battle[28].tank =0;
      battle[28].airship =0;
      battle[28].Emage = 150;
      battle[28].Esoldier = 500000;
      battle[28].Eairship = 5;
      battle[28].Etank =10;
      battle[28].start =false;
      battle[28].victory =false;
      battle[28].defeat = false;
      battle[28].reason = "Iron";
      
      battle[29].Ecountry = "Solus";
      battle[29].Starget = "Soldiers";
      battle[29].Mtarget = "Soldiers";
      battle[29].Ttarget = "Soldiers";
      battle[29].Atarget = "Airships";
      battle[29].soldier = 0;
      battle[29].mage =0;
      battle[29].tank =0;
      battle[29].airship =0;
      battle[29].Emage = 150;
      battle[29].Esoldier = 500000;
      battle[29].Eairship = 5;
      battle[29].Etank =10;
      battle[29].start =false;
      battle[29].victory =false;
      battle[29].defeat = false;
      battle[29].reason = "Coal";

      battle[30].Ecountry = "Solus";
      battle[30].Starget = "Soldiers";
      battle[30].Mtarget = "Soldiers";
      battle[30].Ttarget = "Soldiers";
      battle[30].Atarget = "Airships";
      battle[30].soldier = 0;
      battle[30].mage =0;
      battle[30].tank =0;
      battle[30].airship =0;
      battle[30].Emage = 150;
      battle[30].Esoldier = 500000;
      battle[30].Eairship = 5;
      battle[30].Etank =10;
      battle[30].start =false;
      battle[30].victory =false;
      battle[30].defeat = false;
      battle[30].reason = "Lead";

      battle[31].Ecountry = "Solus";
      battle[31].Starget = "Soldiers";
      battle[31].Mtarget = "Soldiers";
      battle[31].Ttarget = "Soldiers";
      battle[31].Atarget = "Airships";
      battle[31].soldier = 0;
      battle[31].mage =0;
      battle[31].tank =0;
      battle[31].airship =0;
      battle[31].Emage = 150;
      battle[31].Esoldier = 500000;
      battle[31].Eairship = 5;
      battle[31].Etank =10;
      battle[31].start =false;
      battle[31].victory =false;
      battle[31].defeat = false;
      battle[31].reason = "City";

        battle[32].Ecountry = "Solus";
      battle[32].Starget = "Soldiers";
      battle[32].Mtarget = "Soldiers";
      battle[32].Ttarget = "Soldiers";
      battle[32].Atarget = "Airships";
      battle[32].soldier = 0;
      battle[32].mage =0;
      battle[32].tank =0;
      battle[32].airship =0;
      battle[32].Emage = 150;
      battle[32].Esoldier = 500000;
      battle[32].Eairship = 5;
      battle[32].Etank =10;
      battle[32].start =false;
      battle[32].victory =false;
      battle[32].defeat = false;
      battle[32].reason = "City";
      
        battle[33].Ecountry = "Solus";
      battle[33].Starget = "Soldiers";
      battle[33].Mtarget = "Soldiers";
      battle[33].Ttarget = "Soldiers";
      battle[33].Atarget = "Airships";
      battle[33].soldier = 0;
      battle[33].mage =0;
      battle[33].tank =0;
      battle[33].airship =0;
      battle[33].Emage = 150;
      battle[33].Esoldier = 500000;
      battle[33].Eairship = 5;
      battle[33].Etank =10;
      battle[33].start =false;
      battle[33].victory =false;
      battle[33].defeat = false;
      battle[33].reason = "City";

        battle[34].Ecountry = "Solus";
      battle[34].Starget = "Soldiers";
      battle[34].Mtarget = "Soldiers";
      battle[34].Ttarget = "Soldiers";
      battle[34].Atarget = "Airships";
      battle[34].soldier = 0;
      battle[34].mage =0;
      battle[34].tank =0;
      battle[34].airship =0;
      battle[34].Emage = 150;
      battle[34].Esoldier = 500000;
      battle[34].Eairship = 5;
      battle[34].Etank =10;
      battle[34].start =false;
      battle[34].victory =false;
      battle[34].defeat = false;
      battle[34].reason = "City";

        battle[35].Ecountry = "Solus";
      battle[35].Starget = "Soldiers";
      battle[35].Mtarget = "Soldiers";
      battle[35].Ttarget = "Soldiers";
      battle[35].Atarget = "Airships";
      battle[35].soldier = 0;
      battle[35].mage =0;
      battle[35].tank =0;
      battle[35].airship =0;
      battle[35].Emage = 150;
      battle[35].Esoldier = 500000;
      battle[35].Eairship = 5;
      battle[35].Etank =10;
      battle[35].start =false;
      battle[35].victory =false;
      battle[35].defeat = false;
      battle[35].reason = "City";

        battle[36].Ecountry = "Solus";
      battle[36].Starget = "Soldiers";
      battle[36].Mtarget = "Soldiers";
      battle[36].Ttarget = "Soldiers";
      battle[36].Atarget = "Airships";
      battle[36].soldier = 0;
      battle[36].mage =0;
      battle[36].tank =0;
      battle[36].airship =0;
      battle[36].Emage = 150;
      battle[36].Esoldier = 500000;
      battle[36].Eairship = 5;
      battle[36].Etank =10;
      battle[36].start =false;
      battle[36].victory =false;
      battle[36].defeat = false;
      battle[36].reason = "City";

        battle[37].Ecountry = "Solus";
      battle[37].Starget = "Soldiers";
      battle[37].Mtarget = "Soldiers";
      battle[37].Ttarget = "Soldiers";
      battle[37].Atarget = "Airships";
      battle[37].soldier = 0;
      battle[37].mage =0;
      battle[37].tank =0;
      battle[37].airship =0;
      battle[37].Emage = 150;
      battle[37].Esoldier = 500000;
      battle[37].Eairship = 5;
      battle[37].Etank =10;
      battle[37].start =false;
      battle[37].victory =false;
      battle[37].defeat = false;
      battle[37].reason = "City";

        battle[38].Ecountry = "Solus";
      battle[38].Starget = "Soldiers";
      battle[38].Mtarget = "Soldiers";
      battle[38].Ttarget = "Soldiers";
      battle[38].Atarget = "Airships";
      battle[38].soldier = 0;
      battle[38].mage =0;
      battle[38].tank =0;
      battle[38].airship =0;
      battle[38].Emage = 150;
      battle[38].Esoldier = 500000;
      battle[38].Eairship = 5;
      battle[38].Etank =10;
      battle[38].start =false;
      battle[38].victory =false;
      battle[38].defeat = false;
      battle[38].reason = "City";

      battle[39].Ecountry = "Solus";
      battle[39].Starget = "Soldiers";
      battle[39].Mtarget = "Soldiers";
      battle[39].Ttarget = "Soldiers";
      battle[39].Atarget = "Airships";
      battle[39].soldier = 0;
      battle[39].mage =0;
      battle[39].tank =0;
      battle[39].airship =0;
      battle[39].Emage = 300;
      battle[39].Esoldier = 1000000;
      battle[39].Eairship = 5;
      battle[39].Etank =10;
      battle[39].start =false;
      battle[39].victory =false;
      battle[39].defeat = false;
      battle[39].reason = "Capital";

      battle[40].Ecountry = "Tartan";
      battle[40].Starget = "Soldiers";
      battle[40].Mtarget = "Soldiers";
      battle[40].Ttarget = "Soldiers";
      battle[40].Atarget = "Airships";
      battle[40].soldier = 0;
      battle[40].mage =0;
      battle[40].tank =0;
      battle[40].airship =0;
      battle[40].Emage = 0;
      battle[40].Esoldier = 10000;
      battle[40].Eairship = 0;
      battle[40].Etank =0;
      battle[40].start =false;
      battle[40].victory =false;
      battle[40].defeat = false;
      battle[40].reason = "Iron";
      
      battle[41].Ecountry = "Tartan";
      battle[41].Starget = "Soldiers";
      battle[41].Mtarget = "Soldiers";
      battle[41].Ttarget = "Soldiers";
      battle[41].Atarget = "Airships";
      battle[41].soldier = 0;
      battle[41].mage =0;
      battle[41].tank =0;
      battle[41].airship =0;
      battle[41].Emage = 0;
      battle[41].Esoldier = 10000;
      battle[41].Eairship = 0;
      battle[41].Etank =0;
      battle[41].start =false;
      battle[41].victory =false;
      battle[41].defeat = false;
      battle[41].reason = "Iron";

      battle[42].Ecountry = "Tartan";
      battle[42].Starget = "Soldiers";
      battle[42].Mtarget = "Soldiers";
      battle[42].Ttarget = "Soldiers";
      battle[42].Atarget = "Airships";
      battle[42].soldier = 0;
      battle[42].mage =0;
      battle[42].tank =0;
      battle[42].airship =0;
      battle[42].Emage = 0;
      battle[42].Esoldier = 10000;
      battle[42].Eairship = 0;
      battle[42].Etank =0;
      battle[42].start =false;
      battle[42].victory =false;
      battle[42].defeat = false;
      battle[42].reason = "Coal";

      battle[43].Ecountry = "Tartan";
      battle[43].Starget = "Soldiers";
      battle[43].Mtarget = "Soldiers";
      battle[43].Ttarget = "Soldiers";
      battle[43].Atarget = "Airships";
      battle[43].soldier = 0;
      battle[43].mage =0;
      battle[43].tank =0;
      battle[43].airship =0;
      battle[43].Emage = 0;
      battle[43].Esoldier = 10000;
      battle[43].Eairship = 0;
      battle[43].Etank =0;
      battle[43].start =false;
      battle[43].victory =false;
      battle[43].defeat = false;
      battle[43].reason = "Coal";

      battle[44].Ecountry = "Tartan";
      battle[44].Starget = "Soldiers";
      battle[44].Mtarget = "Soldiers";
      battle[44].Ttarget = "Soldiers";
      battle[44].Atarget = "Airships";
      battle[44].soldier = 0;
      battle[44].mage =0;
      battle[44].tank =0;
      battle[44].airship =0;
      battle[44].Emage = 0;
      battle[44].Esoldier = 10000;
      battle[44].Eairship = 0;
      battle[44].Etank =0;
      battle[44].start =false;
      battle[44].victory =false;
      battle[44].defeat = false;
      battle[44].reason = "Lead";

      battle[45].Ecountry = "Tartan";
      battle[45].Starget = "Soldiers";
      battle[45].Mtarget = "Soldiers";
      battle[45].Ttarget = "Soldiers";
      battle[45].Atarget = "Airships";
      battle[45].soldier = 0;
      battle[45].mage =0;
      battle[45].tank =0;
      battle[45].airship =0;
      battle[45].Emage = 0;
      battle[45].Esoldier = 10000;
      battle[45].Eairship = 0;
      battle[45].Etank =0;
      battle[45].start =false;
      battle[45].victory =false;
      battle[45].defeat = false;
      battle[45].reason = "Lead";

        battle[46].Ecountry = "Tartan";
      battle[46].Starget = "Soldiers";
      battle[46].Mtarget = "Soldiers";
      battle[46].Ttarget = "Soldiers";
      battle[46].Atarget = "Airships";
      battle[46].soldier = 0;
      battle[46].mage =0;
      battle[46].tank =0;
      battle[46].airship =0;
      battle[46].Emage = 0;
      battle[46].Esoldier = 10000;
      battle[46].Eairship = 0;
      battle[46].Etank =0;
      battle[46].start =false;
      battle[46].victory =false;
      battle[46].defeat = false;
      battle[46].reason = "City";

        battle[47].Ecountry = "Tartan";
      battle[47].Starget = "Soldiers";
      battle[47].Mtarget = "Soldiers";
      battle[47].Ttarget = "Soldiers";
      battle[47].Atarget = "Airships";
      battle[47].soldier = 0;
      battle[47].mage =0;
      battle[47].tank =0;
      battle[47].airship =0;
      battle[47].Emage = 0;
      battle[47].Esoldier = 10000;
      battle[47].Eairship = 0;
      battle[47].Etank =0;
      battle[47].start =false;
      battle[47].victory =false;
      battle[47].defeat = false;
      battle[47].reason = "City";

        battle[48].Ecountry = "Tartan";
      battle[48].Starget = "Soldiers";
      battle[48].Mtarget = "Soldiers";
      battle[48].Ttarget = "Soldiers";
      battle[48].Atarget = "Airships";
      battle[48].soldier = 0;
      battle[48].mage =0;
      battle[48].tank =0;
      battle[48].airship =0;
      battle[48].Emage = 0;
      battle[48].Esoldier = 25000;
      battle[48].Eairship = 0;
      battle[48].Etank =0;
      battle[48].start =false;
      battle[48].victory =false;
      battle[48].defeat = false;
      battle[48].reason = "Capital";

          battle[49].Ecountry = "Union";
      battle[49].Starget = "Soldiers";
      battle[49].Mtarget = "Soldiers";
      battle[49].Ttarget = "Soldiers";
      battle[49].Atarget = "Airships";
      battle[49].soldier = 0;
      battle[49].mage =0;
      battle[49].tank =0;
      battle[49].airship =0;
      battle[49].Emage = 500;
      battle[49].Esoldier = 10000;
      battle[49].Eairship = 5;
      battle[49].Etank =100;
      battle[49].start =false;
      battle[49].victory =false;
      battle[49].defeat = false;
      battle[49].reason = "Iron";

            battle[50].Ecountry = "Union";
      battle[50].Starget = "Soldiers";
      battle[50].Mtarget = "Soldiers";
      battle[50].Ttarget = "Soldiers";
      battle[50].Atarget = "Airships";
      battle[50].soldier = 0;
      battle[50].mage =0;
      battle[50].tank =0;
      battle[50].airship =0;
      battle[50].Emage = 500;
      battle[50].Esoldier = 10000;
      battle[50].Eairship = 5;
      battle[50].Etank =100;
      battle[50].start =false;
      battle[50].victory =false;
      battle[50].defeat = false;
      battle[50].reason = "Coal";

            battle[51].Ecountry = "Union";
      battle[51].Starget = "Soldiers";
      battle[51].Mtarget = "Soldiers";
      battle[51].Ttarget = "Soldiers";
      battle[51].Atarget = "Airships";
      battle[51].soldier = 0;
      battle[51].mage =0;
      battle[51].tank =0;
      battle[51].airship =0;
      battle[51].Emage = 500;
      battle[51].Esoldier = 10000;
      battle[51].Eairship = 5;
      battle[51].Etank =100;
      battle[51].start =false;
      battle[51].victory =false;
      battle[51].defeat = false;
      battle[51].reason = "Lead";

            battle[52].Ecountry = "Union";
      battle[52].Starget = "Soldiers";
      battle[52].Mtarget = "Soldiers";
      battle[52].Ttarget = "Soldiers";
      battle[52].Atarget = "Airships";
      battle[52].soldier = 0;
      battle[52].mage =0;
      battle[52].tank =0;
      battle[52].airship =0;
      battle[52].Emage = 500;
      battle[52].Esoldier = 10000;
      battle[52].Eairship = 5;
      battle[52].Etank =100;
      battle[52].start =false;
      battle[52].victory =false;
      battle[52].defeat = false;
      battle[52].reason = "City";

            battle[53].Ecountry = "Union";
      battle[53].Starget = "Soldiers";
      battle[53].Mtarget = "Soldiers";
      battle[53].Ttarget = "Soldiers";
      battle[53].Atarget = "Airships";
      battle[53].soldier = 0;
      battle[53].mage =0;
      battle[53].tank =0;
      battle[53].airship =0;
      battle[53].Emage = 500;
      battle[53].Esoldier = 10000;
      battle[53].Eairship = 5;
      battle[53].Etank =100;
      battle[53].start =false;
      battle[53].victory =false;
      battle[53].defeat = false;
      battle[53].reason = "City";

            battle[54].Ecountry = "Union";
      battle[54].Starget = "Soldiers";
      battle[54].Mtarget = "Soldiers";
      battle[54].Ttarget = "Soldiers";
      battle[54].Atarget = "Airships";
      battle[54].soldier = 0;
      battle[54].mage =0;
      battle[54].tank =0;
      battle[54].airship =0;
      battle[54].Emage = 500;
      battle[54].Esoldier = 10000;
      battle[54].Eairship = 5;
      battle[54].Etank =100;
      battle[54].start =false;
      battle[54].victory =false;
      battle[54].defeat = false;
      battle[54].reason = "City";

            battle[56].Ecountry = "Union";
      battle[56].Starget = "Soldiers";
      battle[56].Mtarget = "Soldiers";
      battle[56].Ttarget = "Soldiers";
      battle[56].Atarget = "Airships";
      battle[56].soldier = 0;
      battle[56].mage =0;
      battle[56].tank =0;
      battle[56].airship =0;
      battle[56].Emage = 500;
      battle[56].Esoldier = 10000;
      battle[56].Eairship = 5;
      battle[56].Etank =100;
      battle[56].start =false;
      battle[56].victory =false;
      battle[56].defeat = false;
      battle[56].reason = "City";

            battle[55].Ecountry = "Union";
      battle[55].Starget = "Soldiers";
      battle[55].Mtarget = "Soldiers";
      battle[55].Ttarget = "Soldiers";
      battle[55].Atarget = "Airships";
      battle[55].soldier = 0;
      battle[55].mage =0;
      battle[55].tank =0;
      battle[55].airship =0;
      battle[55].Emage = 500;
      battle[55].Esoldier = 10000;
      battle[55].Eairship = 5;
      battle[55].Etank =100;
      battle[55].start =false;
      battle[55].victory =false;
      battle[55].defeat = false;
      battle[55].reason = "City";

            battle[57].Ecountry = "Union";
      battle[57].Starget = "Soldiers";
      battle[57].Mtarget = "Soldiers";
      battle[57].Ttarget = "Soldiers";
      battle[57].Atarget = "Airships";
      battle[57].soldier = 0;
      battle[57].mage =0;
      battle[57].tank =0;
      battle[57].airship =0;
      battle[57].Emage = 500;
      battle[57].Esoldier = 10000;
      battle[57].Eairship = 5;
      battle[57].Etank =100;
      battle[57].start =false;
      battle[57].victory =false;
      battle[57].defeat = false;
      battle[57].reason = "City";

            battle[58].Ecountry = "Union";
      battle[58].Starget = "Soldiers";
      battle[58].Mtarget = "Soldiers";
      battle[58].Ttarget = "Soldiers";
      battle[58].Atarget = "Airships";
      battle[58].soldier = 0;
      battle[58].mage =0;
      battle[58].tank =0;
      battle[58].airship =0;
      battle[58].Emage = 500;
      battle[58].Esoldier = 10000;
      battle[58].Eairship = 5;
      battle[58].Etank =100;
      battle[58].start =false;
      battle[58].victory =false;
      battle[58].defeat = false;
      battle[58].reason = "City";

            battle[59].Ecountry = "Union";
      battle[59].Starget = "Soldiers";
      battle[59].Mtarget = "Soldiers";
      battle[59].Ttarget = "Soldiers";
      battle[59].Atarget = "Airships";
      battle[59].soldier = 0;
      battle[59].mage =0;
      battle[59].tank =0;
      battle[59].airship =0;
      battle[59].Emage = 500;
      battle[59].Esoldier = 10000;
      battle[59].Eairship = 5;
      battle[59].Etank =100;
      battle[59].start =false;
      battle[59].victory =false;
      battle[59].defeat = false;
      battle[59].reason = "City";

            battle[60].Ecountry = "Union";
      battle[60].Starget = "Soldiers";
      battle[60].Mtarget = "Soldiers";
      battle[60].Ttarget = "Soldiers";
      battle[60].Atarget = "Airships";
      battle[60].soldier = 0;
      battle[60].mage =0;
      battle[60].tank =0;
      battle[60].airship =0;
      battle[60].Emage = 500;
      battle[60].Esoldier = 10000;
      battle[60].Eairship = 5;
      battle[60].Etank =100;
      battle[60].start =false;
      battle[60].victory =false;
      battle[60].defeat = false;
      battle[60].reason = "City";
            battle[61].Ecountry = "Union";
      battle[61].Starget = "Soldiers";
      battle[61].Mtarget = "Soldiers";
      battle[61].Ttarget = "Soldiers";
      battle[61].Atarget = "Airships";
      battle[61].soldier = 0;
      battle[61].mage =0;
      battle[61].tank =0;
      battle[61].airship =0;
      battle[61].Emage = 500;
      battle[61].Esoldier = 10000;
      battle[61].Eairship = 5;
      battle[61].Etank =100;
      battle[61].start =false;
      battle[61].victory =false;
      battle[61].defeat = false;
      battle[61].reason = "City";

            battle[62].Ecountry = "Union";
      battle[62].Starget = "Soldiers";
      battle[62].Mtarget = "Soldiers";
      battle[62].Ttarget = "Soldiers";
      battle[62].Atarget = "Airships";
      battle[62].soldier = 0;
      battle[62].mage =0;
      battle[62].tank =0;
      battle[62].airship =0;
      battle[62].Emage = 1000;
      battle[62].Esoldier = 30000;
      battle[62].Eairship = 10;
      battle[62].Etank =200;
      battle[62].start =false;
      battle[62].victory =false;
      battle[62].defeat = false;
      battle[62].reason = "Capital";

    for (int i = 0; i < 10; i++) {
      nation[i].create(i);
      demand[i] = 100;
    }
    
    srand(time(NULL));
    Cdeposit = 1;
    Ldeposit = 1;
    Ideposit = 1;
    economy = 100;
    salary = 10 * (economy / 100);
    iron = 10;
    coal = 10;
    lead = 10;
    crystal = 10;
    essence = 10;
    food = 1000;
    completed = -1;
    total = 0;
    string a1, a2, a3, a4, a5;
    line = "n";
    economy = 100;
    day = 1;
    week = 1;
    month = 1;
    year = 1;
    territory = 50;
    pop = territory * 100;
    TyranyTurn = 0;
    rep = 100;
    Open = true;
    money = 125000;
    resourceID = 0;
    CountryID = 0;
    gained[0] = IMines;
    gained[1] = CMines;
    gained[2] = LMines;
    gained[3] = Farms * 20;
    used[3] = pop / 50;
    gained[4] = Crystalizers;
    gained[5] = Extractors;
    //steel gained (Smelters)
    if (iron + IMines >= Smelters || coal + CMines >= Smelters) {
      used[0] = Smelters;
      used[1] = Smelters;
      gained[6] = Smelters;
    } else {
      if (iron + IMines > coal + CMines) {
        used[0] = coal + CMines;
        used[1] = coal + CMines;
        gained[6] = coal + CMines;
      }
      if (iron + IMines < coal + CMines) {
        used[0] = iron + IMines;
        used[1] = iron + IMines;
        gained[6] = iron + IMines;
      }
    }
    //munitions gained (Factories)
    if (lead >= Factories * 5) {
      used[2] = Factories * 5;
      gained[7] = Factories * 5;
    } else {
      used[2] = lead + LMines;
      gained[7] = lead + LMines;
    }

    if (crystal + Crystalizers >= Synthesizers || steel + Smelters >= Synthesizers) {
      used[6] = Synthesizers;
      used[4] = Synthesizers;
      gained[8] = Synthesizers;
    } else {
      if (crystal + Crystalizers > steel + Smelters) {
        used[6] = steel + Smelters;
        used[4] = steel + Smelters;
        gained[8] = steel + Smelters;
      }
      if (crystal + Crystalizers < steel + Smelters) {
        used[6] = crystal + Crystalizers;
        used[4] = crystal + Crystalizers;
        gained[8] = crystal + Crystalizers;
      }
    }
    if (essence + Extractors >= Synthesizers || steel + Smelters >= Synthesizers) {
      used[6] = Synthesizers;
      used[5] = Synthesizers;
      gained[9] = Synthesizers;
    } else {
      if (essence + Extractors > steel + Smelters) {
        used[6] = steel + Smelters;
        used[5] = steel + Smelters;
        gained[9] = steel + Smelters;
      }
      if (essence + Extractors < steel + Smelters) {
        used[6] = essence + Extractors;
        used[5] = essence + Extractors;
        gained[9] = essence + Extractors;
      }
    }
    resourceID = 0;
          CountryID = 0;
          for(int i =0; i< 61;i++){
            tab[i].offer = false;
          }
          for (int i = 0; i < 61; i++) {
            int offers;
            offers =0;
            switch (resourceID) {
            case 0:
              tab[i].resource = "Iron";
              break;
            case 1:
              tab[i].resource = "Coal";
              break;
            case 2:
              tab[i].resource = "Lead";
              break;
            case 3:
              tab[i].resource = "Food";
              break;
            case 4:
              tab[i].resource = "Crystal";
              break;
            case 5:
              tab[i].resource = "Essence";
              break;
            case 6:
              tab[i].resource = "Steel";
              break;
            case 7:
              tab[i].resource = "Munitions";
              break;
            case 8:
              tab[i].resource = "Oricalcum";
              break;
            case 9:
              tab[i].resource = "Mithril";
              break;

            }
            if (nation[CountryID].sell[resourceID]) {
              tab[i].country = nation[CountryID].name;
              tab[i].price = 20 * cos(day) + ((pricing(resourceID) * 100) / nation[CountryID].prod[resourceID]);
              if(offers<=nation[CountryID].trade){
              int rng;
              rng = rand() % 2 + 1;
              if (rng == 1) {
                offers+=1;
                tab[i].offer = true;
                int n;
                if (resourceID == 3) {
                  n = rand() % 20 + 100;
                }
                if (resourceID >= 0 && resourceID <= 2) {
                  n = rand() % 2 + 1;
                }
                if (resourceID >= 4) {
                  n = 1;
                }
                tab[i].qty = n;
                tab[i].offer = true;
              }
              if(rng == 2){
                tab[i].offer = false;
              }
            }
            }
            //progression
            resourceID += 1;
            if (resourceID == 10) {
              resourceID = 0;
              CountryID += 1;
              offers =0;
            }
          }

    
  intro(true);
  while (Open) {
    xstart();
  }
}