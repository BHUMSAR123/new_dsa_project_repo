#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//creating a class clock for sleep time 
class Clock {
public:
    int hours;
    int minutes;
};
//blue print of records
class Record {
public:
    string name;
    int airpod_id;
    Clock sleep_time;
    int time_taken;
    string song_name;
    //this overloading is required while sort algorithm was used 
    bool operator<(Record& mate){
        if (sleep_time.hours != mate.sleep_time.hours) {
            return sleep_time.hours < mate.sleep_time.hours;
        }
        return sleep_time.minutes < mate.sleep_time.minutes;
    }
};

class music_channel {
public:
    int channel_id = 0;
    int airpods_assigned[2];
    
};
//blueprint of dorm
class Dorm: public music_channel {
public:
    string dorm_name = "";
    Record* inmate1 = nullptr;
    Record* inmate2 = nullptr;
};

//this function inserts the details from the txt file
void insert_details(vector<Record>& records) {
    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        Record new_record;
        iss >> new_record.name >> new_record.airpod_id >> new_record.sleep_time.hours >> new_record.sleep_time.minutes >> new_record.time_taken >> new_record.song_name;
        records.push_back(new_record);
    }

    infile.close();
}
//this function assigns the dorm to the inamtes 
void assign_to_dorms(vector<Record>& records, vector<Dorm>& dorms) {
    sort(records.begin(), records.end());  //sorting the sleep time of each individual in ascending order
    int count = 1000, channel_id_count = 202301;

    unordered_set<string> assigned_names;   // this data structure is used to store the names those are already assigned so that same person dosent get assigned in multiple dorms

    for (auto& record : records) {
        bool assigned = false;

        for (auto& d : dorms) {
            if (d.inmate1 != nullptr && abs(d.inmate1->sleep_time.hours - record.sleep_time.hours) <= 1) {
                continue; // Skip this dorm if inmate 1 has a sleep time gap less than 1 hour and if is not pointing to null pointer
            }
            if (d.inmate2 != nullptr && abs(d.inmate2->sleep_time.hours - record.sleep_time.hours) <= 1) {
                continue; // Skip this dorm if inmate 2 has a sleep time gap less than 1 hour and if is not pointing to null pointer
            }
            if (d.inmate1 == nullptr) {          //assigning the dorms 
                d.inmate1 = new Record(record); 
                assigned_names.insert(record.name);
                assigned = true;
                d.airpods_assigned[0] = record.airpod_id; 
                break;
            }
            if (d.inmate2 == nullptr) {
                d.inmate2 = new Record(record); 
                assigned_names.insert(record.name);
                assigned = true;
                d.airpods_assigned[1] = record.airpod_id; 
                break;
            }
        }
        if (!assigned) {    //if someone dosen't get assigned then this part will run
            Dorm new_dorm;
            new_dorm.dorm_name = to_string(count);
            new_dorm.channel_id = channel_id_count++;
            new_dorm.inmate1 = new Record(record); 
            dorms.push_back(new_dorm);
            assigned_names.insert(record.name);
            new_dorm.airpods_assigned[0] = record.airpod_id; 
            count++;
            assigned = true;
        }
    } 
}

//this function plays the sleep inducing movie from 20: 00 to 2:59 keeping the time constraint between this hour that person must sleep between this hours
void sleep_inducer(vector<Dorm>& dorms) {
    cout << "Playing sleep-inducing music in all dorms:" << endl<<endl;
    //here we have made two loops one running between 20: 00 hrs to 23:59 and other between 00:00 to 2:59 hrs due to terminal issue two.both loops are marked with "this-->"
  /*this-->*/  for (int hour = 20; hour < 24; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            cout << "At " << hour << ":" << minute << ":" << endl;
            for (int i = 0; i < dorms.size(); i++) {
                if (dorms[i].inmate1 != nullptr && dorms[i].inmate1->sleep_time.hours == hour && dorms[i].inmate1->sleep_time.minutes == minute) {
                    cout << "Dorm " << dorms[i].dorm_name << " has:" << endl;
                    cout << "Inmate 1: " << dorms[i].inmate1->name << " at: " << hour << ":" << minute << endl;
                    cout << "Playing Music " << dorms[i].inmate1->song_name << " for " << dorms[i].inmate1->time_taken << " minutes." << endl;
                     cout<<"through channel id: "<<dorms[i].channel_id<<" at airpod id: "<<dorms[i].airpods_assigned[0]<<endl;

                }
                if (dorms[i].inmate2 != nullptr && dorms[i].inmate2->sleep_time.hours == hour && dorms[i].inmate2->sleep_time.minutes == minute) {
                    cout << "Dorm " << dorms[i].dorm_name << " has:" << endl;
                    cout << "Inmate 2: " << dorms[i].inmate2->name << " at: " << hour << ":" << minute << endl;
                    cout << "Playing Music " << dorms[i].inmate2->song_name << " for " << dorms[i].inmate2->time_taken << " minutes." << endl;
                     cout<<"through channel id: "<<dorms[i].channel_id<<" at airpod id: "<<dorms[i].airpods_assigned[1]<<endl;
                }
            }
            cout << endl;
        }
    }
   /*this-->*/  for (int hour = 0; hour < 3; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            cout << "At " << hour << ":" << minute << ":" << endl;
            for (int i = 0; i < dorms.size(); i++) {
                if (dorms[i].inmate1 != nullptr && dorms[i].inmate1->sleep_time.hours == hour && dorms[i].inmate1->sleep_time.minutes == minute) {
                    cout << "Dorm " << dorms[i].dorm_name << " has:" << endl;
                    cout << "Inmate 1: " << dorms[i].inmate1->name << " at: " << hour << ":" << minute << endl;
                    cout << "Playing Music " << dorms[i].inmate1->song_name << " for " << dorms[i].inmate1->time_taken << " minutes." << endl;
                    cout<<"through channel id: "<<dorms[i].channel_id<<" at airpod id: "<<dorms[i].airpods_assigned[0]<<endl;
                   }
                if (dorms[i].inmate2 != nullptr && dorms[i].inmate2->sleep_time.hours == hour && dorms[i].inmate2->sleep_time.minutes == minute) {
                    cout << "Dorm " << dorms[i].dorm_name << " has:" << endl;
                    cout << "Inmate 2: " << dorms[i].inmate2->name << " at: " << hour << ":" << minute << endl;
                    cout << "Playing Music " << dorms[i].inmate2->song_name << " for " << dorms[i].inmate2->time_taken << " minutes." << endl;
                    cout<<"through channel id: "<<dorms[i].channel_id<<" at airpod id: "<<dorms[i].airpods_assigned[1]<<endl;
                }
            }
            cout << endl;
        }
    }
}
//this function is for printing the details of persons residing in that particular dorms
void print_dorm_details(vector<Dorm>& dorms) {
    for (int i = 0; i < dorms.size(); i++) {
        cout << "Dorm " << dorms[i].dorm_name << " has: " << endl;
        if (dorms[i].inmate1 != nullptr) {
            cout << "Inmate 1: " << dorms[i].inmate1->name << endl;
        }
        if (dorms[i].inmate2 != nullptr) {
            cout << "Inmate 2: " << dorms[i].inmate2->name << endl;
        }
        cout<<"music channel assigned: "<<dorms[i].channel_id<<endl;
        cout<<endl;
       
    }
    
}


int main() {
    vector<Record> records;
    insert_details(records);

    vector<Dorm> dorms;
    assign_to_dorms(records, dorms);
    cout<< "HELLO SIR" << endl ; 
    cout<<"Enter 1 :- TO SEE THE NO. OF INMATES IN DORMS" << endl ; 
    cout<<"Enter 2 :- TO EXECUTE THE SLEEP INDUCER " << endl ; 
    int choice ; 
    cin>>choice ; 
    if(choice == 1) 
    print_dorm_details(dorms); 
    else 
        sleep_inducer(dorms) ; 
    
    //de allocation of memory
      for (auto& dorm : dorms) {
        delete dorm.inmate1;
        delete dorm.inmate2;
    }
    
    return 0;
}


